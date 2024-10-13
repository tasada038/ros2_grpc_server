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
#include <grpcpp/grpcpp.h>
#include "pose_messages.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using pose_messages::Pose;
using pose_messages::Vector3;
using pose_messages::Quaternion;
using pose_messages::PoseService;

// Class representing a gRPC client for sending Pose messages.
class PoseClient {
public:
    PoseClient(std::shared_ptr<Channel> channel) : stub_(PoseService::NewStub(channel)) {}

    void SendPose(double x, double y, double theta) {
        Pose request;
        request.set_x(x);
        request.set_y(y);
        request.set_theta(theta);

        Pose reply;
        ClientContext context;

        Status status = stub_->SendPose(&context, request, &reply);

        if (status.ok()) {
            std::cout << "Pose sent: (" << reply.x() << ", " << reply.y() << ", " << reply.theta() << ")" << std::endl;
        } else {
            std::cout << "Error sending Pose: " << status.error_message() << std::endl;
        }
    }

private:
    std::unique_ptr<PoseService::Stub> stub_;
};


int main(int argc, char** argv) {
    /* arguments x, y, and theta */
    if (argc != 4) {
        std::cerr << "Usage: pose_client <x> <y> <theta>" << std::endl;
        return 1;
    }
    double x = std::stod(argv[1]);
    double y = std::stod(argv[2]);
    double theta = std::stod(argv[3]);
    /* end arguments version */
    // ./pose_client 1.0 3.0 3.14

    PoseClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    client.SendPose(x, y, theta);
    // client.SendPose(1.0, 3.0, 3.14);
    return 0;
}