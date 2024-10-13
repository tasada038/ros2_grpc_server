#-----------------------------------------------------------------------------------
# MIT License

# Copyright (c) 2024 Takumi Asada

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#-----------------------------------------------------------------------------------

from flask import Flask, render_template, request, jsonify
import grpc
import robot_service_pb2
import robot_service_pb2_grpc

app = Flask(__name__)

class GrpcClient:
    def __init__(self, server_address='localhost:50051'):
        self.channel = grpc.insecure_channel(server_address)
        self.stub = robot_service_pb2_grpc.RobotServiceStub(self.channel)  # Use the correct reference

    def get_float32(self):
        request = robot_service_pb2.Float32Request()
        response = self.stub.GetFloat32(request)
        return response.float_data.data

    def set_float32(self, value):
        request = robot_service_pb2.Float32Request()
        request.float_data.data = value
        response = self.stub.SetFloat32(request)
        return response.float_data.data

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/get_float32', methods=['GET'])
def get_float32():
    grpc_client = GrpcClient()
    try:
        value = grpc_client.get_float32()
        return jsonify({'success': True, 'value': value})
    except Exception as e:
        return jsonify({'success': False, 'error': str(e)})

@app.route('/set_float32', methods=['POST'])
def set_float32():
    grpc_client = GrpcClient()
    try:
        value = float(request.json.get('value', 0))
        updated_value = grpc_client.set_float32(value)
        return jsonify({'success': True, 'updated_value': updated_value})
    except Exception as e:
        return jsonify({'success': False, 'error': str(e)})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080, debug=True)
