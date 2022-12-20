from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    container = ComposableNodeContainer(
        name='compose_nodes',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        composable_node_descriptions=[
            ComposableNode(
                package='compose_nodes',
                plugin='Node1',
                name='node1'),
            ComposableNode(
                package='compose_nodes',
                plugin='Node2',
                name='node2'),
        ],
        output='screen',
    )

    return LaunchDescription([container])
