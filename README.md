### ros2_service_servers

#### Service servers
1. [my_service.cpp](src/my_service.cpp) accepts `std_srvs/srv/Trigger` requests and publishes `geometry_msgs/msg/Twist` to the `/cmd_vel` topic.
2. [my_service2.cpp](src/my_service2.cpp) accepts `std_srvs/srv/SetBool` requests and toggles.

#### Clone repo
`git clone https://github.com/ivogeorg/ros2_service_servers.git my_service_server`

