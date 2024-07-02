#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/set_bool.hpp"

#include <memory>

void callback(const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
          std::shared_ptr<std_srvs::srv::SetBool::Response>      response)
{
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\n");

  if (request->data) {
      response->message = "ON";
  }
  else {
      response->message = "OFF";
  }
  
  response->success = true;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%s]", response->message);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("my_service2_node");

  rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr service =
    node->create_service<std_srvs::srv::SetBool>("my_service2", &callback);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service ready.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}