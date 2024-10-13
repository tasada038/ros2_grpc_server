# Software Architecture Diagram

```mermaid
graph TD
    A[アプリケーション層] <-->|gRPC| B[ミドルウェア層]
    B <-->|ROS 2| C[ハードウェア層]
```

## gRPC Diagram

```mermaid
graph TD
subgraph gRPC Clinet: App Layer
  C[Get Client]
  A[Set Client]
end

subgraph gRPC Server: MW Layer
  B[Server]
  D[ROS 2 Puslisher]
  E[ROS 2 Subscriber]
end

  A[Set Client] -->|Set Request| B[Server]
  C[Get Client] -->|Get Request| B[Server]

  B[Server] -->|Set Response| A[Set Client]
  B[Server] -->|Get Response| C[Get Client]

  B[Server] -->|raw data| D[ROS 2 Puslisher]
  B[Server] -->|raw data| E[ROS 2 Subscriber]
```

## gRPC Sequence
* Set Client Sequence
```mermaid
sequenceDiagram
    participant SetClient as Set Client
    participant Server as Server
    participant Publisher as ROS 2 Publisher

    SetClient->>Server: Set Request
    Server->>Publisher: raw data
    Publisher->>Server: Publish data
    Server->>SetClient: Set Response
```

* Get Client Sequence
```mermaid
sequenceDiagram
    participant GetClient as Get Client
    participant Server as Server
    participant Subscriber as ROS 2 Subscriber

    GetClient->>Server: Get Request
    Server->>Subscriber: Subscribe data
    Subscriber->>Server: raw data
    Server->>GetClient: Get Response
```

# Reference

https://github.com/Sollimann/CleanIt

https://github.com/pf-robotics/kachaka-api

https://github.com/bufbuild/protobuf-es