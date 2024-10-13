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

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using pose_messages::Pose;
using pose_messages::Vector3;
using pose_messages::Quaternion;
using pose_messages::PoseService;

// Implementation of the PoseService gRPC service.
class PoseServiceImpl final : public PoseService::Service {
public:
    Status SendPose(ServerContext* context, const Pose* request, Pose* reply) override {
        std::cout << "Received Pose: (" << request->x() << ", " << request->y() << ", " << request->theta() << ")" << std::endl;
        *reply = *request;
        return Status::OK;
    }

    Status SendVector(ServerContext* context, const Vector3* request, Vector3* reply) override {
        std::cout << "Received Vector: (" << request->x() << ", " << request->y() << ", " << request->z() << ")" << std::endl;
        *reply = *request;
        return Status::OK;
    }

    Status SendQuaternion(ServerContext* context, const Quaternion* request, Quaternion* reply) override {
        std::cout << "Received Quaternion: (" << request->x() << ", " << request->y() << ", " << request->z() << ", " << request->w() << ")" << std::endl;
        *reply = *request;
        return Status::OK;
    }
};

// Function to start the gRPC server.
void RunServer() {
    std::string server_address("0.0.0.0:50051");
    PoseServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();
    return 0;
}
