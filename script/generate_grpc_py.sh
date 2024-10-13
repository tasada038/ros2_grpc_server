#!/bin/bash

# Directory where proto files are located
PROTO_DIR="../proto"

# Directory where generated Python files will be placed (same directory as proto by default)
OUT_DIR="."

# Check if grpc_tools is installed
if ! python3 -c "import grpc_tools.protoc" &> /dev/null; then
    echo "grpc_tools.protoc not found. Please install it with:"
    echo "  pip3 install grpcio grpcio-tools"
    exit 1
fi

# Compile all proto files in the proto directory
for proto_file in "$PROTO_DIR"/*.proto; do
    echo "Compiling $proto_file..."
    python3 -m grpc_tools.protoc -I="$PROTO_DIR" --python_out="$OUT_DIR" --grpc_python_out="$OUT_DIR" "$proto_file"
    if [ $? -ne 0 ]; then
        echo "Error compiling $proto_file"
        exit 1
    fi
done

echo "All proto files compiled successfully."
