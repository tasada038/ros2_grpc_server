cmake_minimum_required(VERSION 3.5)
project(ros2_grpc_server)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gRPC CONFIG REQUIRED)

# ------------------------------ Set Parameter ------------------------------
# Set the directory where .proto files are located
set(PROTO_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/proto")
file(GLOB PROTO_SRC "${PROTO_SRC_DIR}/*.proto")

# gRPC C++ plugin
set(GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)

# Specify output directory for header, source, and script files
set(GENERATED_PROTO_HDR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(GENERATED_PROTO_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(GENERATED_PROTO_PY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/script")

# Generated header and source files directory
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC})

# Generated C++ and Python code from .proto files
foreach(proto_file ${PROTO_SRC})
    get_filename_component(proto_name ${proto_file} NAME_WE)

    # Add custom command to generate C++ code for each .proto file
    add_custom_command(
      OUTPUT ${GENERATED_PROTO_HDR_DIR}/${proto_name}.grpc.pb.cc ${GENERATED_PROTO_HDR_DIR}/${proto_name}.grpc.pb.h
      COMMAND ${Protobuf_PROTOC_EXECUTABLE}
      ARGS --grpc_out=${GENERATED_PROTO_HDR_DIR}
            --cpp_out=${GENERATED_PROTO_HDR_DIR}
            --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN_EXECUTABLE}
            --proto_path=${PROTO_SRC_DIR}
            ${proto_file}
      DEPENDS ${proto_file} ${GRPC_CPP_PLUGIN_EXECUTABLE}
    )
    list(APPEND GENERATED_FILES ${GENERATED_PROTO_HDR_DIR}/${proto_name}.grpc.pb.cc)
    list(APPEND GENERATED_FILES ${GENERATED_PROTO_HDR_DIR}/${proto_name}.grpc.pb.h)
    # Add custom command to generate Python code for each .proto file
    add_custom_command(
        OUTPUT ${GENERATED_PROTO_PY_DIR}/${proto_name}_pb2.py ${GENERATED_PROTO_PY_DIR}/${proto_name}_pb2_grpc.py
        COMMAND python3 -m grpc_tools.protoc
        ARGS -I=${PROTO_SRC_DIR}  # Set the proto path correctly
              --python_out=${GENERATED_PROTO_PY_DIR}  # Protobuf Python output
              --grpc_python_out=${GENERATED_PROTO_PY_DIR}  # gRPC Python output
              ${proto_file}
        DEPENDS ${proto_file}
        COMMENT "Compiling ${proto_file} to Python"
    )
    # Collect all the generated files to be used as dependencies for the custom target
    list(APPEND GENERATED_FILES ${GENERATED_PROTO_PY_DIR}/${proto_name}_pb2.py)
    list(APPEND GENERATED_FILES ${GENERATED_PROTO_PY_DIR}/${proto_name}_pb2_grpc.py)
endforeach()

# Loop through each .proto file
foreach(proto_file ${PROTO_SRC})
    get_filename_component(proto_name ${proto_file} NAME_WE)
endforeach()

# Create a custom target to trigger Python code generation for all proto files
add_custom_target(generate_protos ALL
    DEPENDS ${GENERATED_FILES}
)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

# ------------------------------ add executable ------------------------------
# ----- Build C++ test Code ----- #
option(BUILD_CPP_SOURCE "Build cpp source" ON)
if(BUILD_CPP_SOURCE)
add_executable(pose_server src/pose_server.cpp)
target_sources(pose_server PRIVATE
    ${GENERATED_PROTO_HDR_DIR}/pose_messages.grpc.pb.cc
    ${GENERATED_PROTO_HDR_DIR}/pose_messages.pb.cc
)
target_link_libraries(pose_server gRPC::grpc++ protobuf::libprotobuf)

add_executable(pose_client src/pose_client.cpp)
target_sources(pose_client PRIVATE
    ${GENERATED_PROTO_HDR_DIR}/pose_messages.grpc.pb.cc
    ${GENERATED_PROTO_HDR_DIR}/pose_messages.pb.cc
)
target_link_libraries(pose_client gRPC::grpc++ protobuf::libprotobuf)
endif()

# ------------------------------ add ROS 2 executable ------------------------------
add_executable(float32_server src/float32_server.cpp)
target_sources(float32_server PRIVATE
    ${GENERATED_PROTO_HDR_DIR}/robot_service.grpc.pb.cc
    ${PROTO_SRCS}
)
target_link_libraries(float32_server gRPC::grpc++ protobuf::libprotobuf)

# Linking required packages
ament_target_dependencies(float32_server
    rclcpp
    std_msgs
    gRPC
)

# Installation Settings
install(TARGETS
    float32_server
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
