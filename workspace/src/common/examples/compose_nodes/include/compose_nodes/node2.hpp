#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class Node2 : public rclcpp::Node {
  public:
    explicit Node2(const rclcpp::NodeOptions& options);

  private:
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t value;

    void listener_callback(const std_msgs::msg::Int32& msg);
    void timer_callback();
};
