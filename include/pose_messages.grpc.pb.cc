// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: pose_messages.proto

#include "pose_messages.pb.h"
#include "pose_messages.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace pose_messages {

static const char* PoseService_method_names[] = {
  "/pose_messages.PoseService/SendPose",
  "/pose_messages.PoseService/SendVector",
  "/pose_messages.PoseService/SendQuaternion",
};

std::unique_ptr< PoseService::Stub> PoseService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< PoseService::Stub> stub(new PoseService::Stub(channel, options));
  return stub;
}

PoseService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_SendPose_(PoseService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SendVector_(PoseService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SendQuaternion_(PoseService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status PoseService::Stub::SendPose(::grpc::ClientContext* context, const ::pose_messages::Pose& request, ::pose_messages::Pose* response) {
  return ::grpc::internal::BlockingUnaryCall< ::pose_messages::Pose, ::pose_messages::Pose, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SendPose_, context, request, response);
}

void PoseService::Stub::async::SendPose(::grpc::ClientContext* context, const ::pose_messages::Pose* request, ::pose_messages::Pose* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::pose_messages::Pose, ::pose_messages::Pose, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendPose_, context, request, response, std::move(f));
}

void PoseService::Stub::async::SendPose(::grpc::ClientContext* context, const ::pose_messages::Pose* request, ::pose_messages::Pose* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendPose_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::pose_messages::Pose>* PoseService::Stub::PrepareAsyncSendPoseRaw(::grpc::ClientContext* context, const ::pose_messages::Pose& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::pose_messages::Pose, ::pose_messages::Pose, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SendPose_, context, request);
}

::grpc::ClientAsyncResponseReader< ::pose_messages::Pose>* PoseService::Stub::AsyncSendPoseRaw(::grpc::ClientContext* context, const ::pose_messages::Pose& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSendPoseRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status PoseService::Stub::SendVector(::grpc::ClientContext* context, const ::pose_messages::Vector3& request, ::pose_messages::Vector3* response) {
  return ::grpc::internal::BlockingUnaryCall< ::pose_messages::Vector3, ::pose_messages::Vector3, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SendVector_, context, request, response);
}

void PoseService::Stub::async::SendVector(::grpc::ClientContext* context, const ::pose_messages::Vector3* request, ::pose_messages::Vector3* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::pose_messages::Vector3, ::pose_messages::Vector3, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendVector_, context, request, response, std::move(f));
}

void PoseService::Stub::async::SendVector(::grpc::ClientContext* context, const ::pose_messages::Vector3* request, ::pose_messages::Vector3* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendVector_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::pose_messages::Vector3>* PoseService::Stub::PrepareAsyncSendVectorRaw(::grpc::ClientContext* context, const ::pose_messages::Vector3& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::pose_messages::Vector3, ::pose_messages::Vector3, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SendVector_, context, request);
}

::grpc::ClientAsyncResponseReader< ::pose_messages::Vector3>* PoseService::Stub::AsyncSendVectorRaw(::grpc::ClientContext* context, const ::pose_messages::Vector3& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSendVectorRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status PoseService::Stub::SendQuaternion(::grpc::ClientContext* context, const ::pose_messages::Quaternion& request, ::pose_messages::Quaternion* response) {
  return ::grpc::internal::BlockingUnaryCall< ::pose_messages::Quaternion, ::pose_messages::Quaternion, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SendQuaternion_, context, request, response);
}

void PoseService::Stub::async::SendQuaternion(::grpc::ClientContext* context, const ::pose_messages::Quaternion* request, ::pose_messages::Quaternion* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::pose_messages::Quaternion, ::pose_messages::Quaternion, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendQuaternion_, context, request, response, std::move(f));
}

void PoseService::Stub::async::SendQuaternion(::grpc::ClientContext* context, const ::pose_messages::Quaternion* request, ::pose_messages::Quaternion* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendQuaternion_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::pose_messages::Quaternion>* PoseService::Stub::PrepareAsyncSendQuaternionRaw(::grpc::ClientContext* context, const ::pose_messages::Quaternion& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::pose_messages::Quaternion, ::pose_messages::Quaternion, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SendQuaternion_, context, request);
}

::grpc::ClientAsyncResponseReader< ::pose_messages::Quaternion>* PoseService::Stub::AsyncSendQuaternionRaw(::grpc::ClientContext* context, const ::pose_messages::Quaternion& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSendQuaternionRaw(context, request, cq);
  result->StartCall();
  return result;
}

PoseService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PoseService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PoseService::Service, ::pose_messages::Pose, ::pose_messages::Pose, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](PoseService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::pose_messages::Pose* req,
             ::pose_messages::Pose* resp) {
               return service->SendPose(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PoseService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PoseService::Service, ::pose_messages::Vector3, ::pose_messages::Vector3, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](PoseService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::pose_messages::Vector3* req,
             ::pose_messages::Vector3* resp) {
               return service->SendVector(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PoseService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PoseService::Service, ::pose_messages::Quaternion, ::pose_messages::Quaternion, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](PoseService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::pose_messages::Quaternion* req,
             ::pose_messages::Quaternion* resp) {
               return service->SendQuaternion(ctx, req, resp);
             }, this)));
}

PoseService::Service::~Service() {
}

::grpc::Status PoseService::Service::SendPose(::grpc::ServerContext* context, const ::pose_messages::Pose* request, ::pose_messages::Pose* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PoseService::Service::SendVector(::grpc::ServerContext* context, const ::pose_messages::Vector3* request, ::pose_messages::Vector3* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PoseService::Service::SendQuaternion(::grpc::ServerContext* context, const ::pose_messages::Quaternion* request, ::pose_messages::Quaternion* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace pose_messages

