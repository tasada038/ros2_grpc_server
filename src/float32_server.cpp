//-----------------------------------------------------------------------------------
// MIT License

// Copyright (c) 2024 Takumi Asada

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//-----------------------------------------------------------------------------------

#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <chrono>

#include <grpcpp/grpcpp.h>
#include "robot_service.grpc.pb.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

/******************************************************************************
 * @class   Float32ServiceImpl
 * @brief   Implements the gRPC Float32Service and integrates with ROS 2 to get/set float32 data
 ******************************************************************************/
class Float32ServiceImpl final : public robot_service::RobotService::Service {
public:
    /******************************************************************************
     * @fn      Float32ServiceImpl
     * @brief   Constructor that initializes ROS 2 publisher and subscriber
     * @param   node : A shared pointer to the ROS 2 node
     ******************************************************************************/
    explicit Float32ServiceImpl(std::shared_ptr<rclcpp::Node> node)
        : node_(node), get_float32_data(0.0) {
        // ROS 2 Publisher
        publisher_ = node_->create_publisher<std_msgs::msg::Float32>("/float32_topic", 10);
        publish_thread_ = std::thread(&Float32ServiceImpl::publishLoop, this);
        // ROS 2 Subscriber
        subscriber_ = node_->create_subscription<std_msgs::msg::Float32>(
            "/data", 10, std::bind(&Float32ServiceImpl::float32Callback, this, std::placeholders::_1));
    }

    /******************************************************************************
     * @fn      GetFloat32
     * @brief   Handles incoming gRPC requests to get the Float32 data from ROS 2 topic
     * @param   context : The gRPC server context
     * @param   request : The request object
     * @param   response: The response object containing the float32 data
     * @return  grpc::Status : The status of the gRPC request
     ******************************************************************************/
    grpc::Status GetFloat32(
      grpc::ServerContext* context,
      const robot_service::Float32Request* request,
      robot_service::Float32Response* response
    ) override {
        // Set the response with the current float32 data
        response->mutable_float_data()->set_data(get_float32_data);

        return grpc::Status::OK;
    }

    /******************************************************************************
     * @fn      SetFloat32
     * @brief   Handles incoming gRPC requests to set the Float32 data to a ROS 2 topic
     * @param   context : The gRPC server context
     * @param   request : The request object containing float32 data
     * @param   response: The response object confirming the set data
     * @return  grpc::Status : The status of the gRPC request
     ******************************************************************************/
    grpc::Status SetFloat32(
      grpc::ServerContext* context,
      const robot_service::Float32Request* request,
      robot_service::Float32Response* response) override {

        // Extract the float32 data from request
        float new_data = request->float_data().data();

        // Set the response with the updated new_data
        response->mutable_float_data()->set_data(new_data);

        // Update float 32 data
        set_float32_data = new_data;

        return grpc::Status::OK;
    }

private:
    /******************************************************************************
     * @fn      publishLoop
     * @brief   Publishes the internal pose data to a ROS 2 topic at a fixed rate (1Hz)
     * @detail  This method runs in a separate thread and periodically publishes
     *          the current pose as a formatted string to the "pose_topic".
     ******************************************************************************/
    void publishLoop() {
      rclcpp::Rate rate(1); // Publish at 1Hz
      while (rclcpp::ok()) {
          // Create and publish a ROS 2 message
          std_msgs::msg::Float32 ros_message;
          ros_message.data = set_float32_data;
          publisher_->publish(ros_message);

          // Log the published pose
          RCLCPP_INFO(node_->get_logger(), "Published data: %f", ros_message.data);
          rate.sleep(); // Wait 1 second
      }
    }

    /******************************************************************************
     * @fn      float32Callback
     * @brief   ROS 2 subscription callback to update internal float32 state
     * @param   msg : The incoming ROS 2 message with float32 data
     ******************************************************************************/
    void float32Callback(const std_msgs::msg::Float32::SharedPtr msg) {
        // Update internal state from ROS 2 message
        get_float32_data = msg->data;
        RCLCPP_INFO(node_->get_logger(), "Received float32 data: %f", get_float32_data);
    }

    std::shared_ptr<rclcpp::Node> node_;  ///< ROS 2 Node
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;  ///< ROS 2 Publisher
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscriber_;  ///< ROS 2 Subscriber
    float get_float32_data;  ///< Internal state to store the latest float32 data
    float set_float32_data;
    std::thread publish_thread_; ///< Thread for publishing pose data at regular intervals

};

/******************************************************************************
 * @fn      runServer
 * @brief   Starts the gRPC server and listens for incoming float32 requests
 ******************************************************************************/
void runServer(Float32ServiceImpl &service) {
    std::string server_address("0.0.0.0:50051");
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}


/******************************************************************************
 * @fn      main
 * @brief   Entry point of the application
 ******************************************************************************/
int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto component = rclcpp::Node::make_shared("grpc_server");
    Float32ServiceImpl service(component);

    std::thread server_thread(runServer, std::ref(service));

    // Spin the ROS 2 node in the main thread
    rclcpp::spin(component);

    // Shutdown and join server thread
    rclcpp::shutdown();
    server_thread.join();
    return 0;
}