#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

#include "compose_nodes/node2.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

Node2::Node2(const rclcpp::NodeOptions& options) : Node("node2", options), value(0) {
    subscription_ =
        this->create_subscription<std_msgs::msg::Int32>("topic_2", 10, std::bind(&Node2::listener_callback, this, _1));
    publisher_ = this->create_publisher<std_msgs::msg::Int32>("topic_3", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&Node2::timer_callback, this));
}

void Node2::listener_callback(const std_msgs::msg::Int32& msg) {
    RCLCPP_INFO(this->get_logger(), "I heard: '%i'", msg.data);
    value = msg.data;
}

void Node2::timer_callback() {
    auto message = std_msgs::msg::Int32();
    message.data = value + 10;
    RCLCPP_INFO(this->get_logger(), "Publishing: '%i'", message.data);
    publisher_->publish(message);
}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(Node2)
