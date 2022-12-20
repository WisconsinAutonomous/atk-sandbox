# Components and Composing Nodes in ROS2
In C++ ROS2, we can either create nodes as executables or as components. Executables are your classic node with a main function to spin up the node. On the other hand, components are compiled into libraries which can be loaded at runtime by other "container" processes. Components allow much more flexibility than standard nodes -- we can decide to run multiple nodes within one container node (aka composing nodes), or stick with the traditional one node per process (by loading just one node into a container process). The former reduces overhead and improves performance, while the latter is likely easier to debug. More detailed information can be found in [this article](https://docs.ros.org/en/humble/Concepts/About-Composition.html). The key steps to creating components and composing them are documented below.

Note: This example is only meant to demonstrate the basics of components and composing nodes. More examples for other types of nodes (and other ways besides the launch file to use components) can be found [here](https://github.com/ros2/demos/tree/humble/composition).
## Our Example
In our example we created two very simple nodes and compose them together. Node1 will listen for an int value on "topic1", add 5 to that value, and publish it to "topic2". Node2 will listen for an int value on "topic2", add 10 to that value, and publish it to "topic3". The key differences in building these components compared to normal nodes is summarized below.
### Creating the Nodes
The process of creating a component is almost identical to the typical version of creating a node. The only difference is that we don't write a main function to spin up the node. Instead, we "register" the component to rclcpp_components using a macro, for example in [src/node1.cpp](https://github.com/WisconsinAutonomous/WAutoDrive/blob/3c4a1984d1db274130e105b99f13e2d1483813bf/workspace/src/common/examples/compose_nodes/src/node1.cpp#L36).
```
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(Node1)
```
### Launch file
The [launch file](https://github.com/WisconsinAutonomous/WAutoDrive/blob/compose_nodes/workspace/src/common/examples/compose_nodes/launch/compose_nodes.launch.py) is how we actually compose and run these components in one process. A few things to note here:
- ComposableNodeContainer, as the name implies, is the container process that will load/run the components we give it. This should always have the parameters `package='rclcpp_components'` and `executable='component_container'`, which is just a [general container process](https://github.com/ros2/rclcpp/blob/humble/rclcpp_components/src/component_container.cpp). Parameters such as `name` and `namespace` are up to the user. I'm not sure if we can make custom containers or if there is any point in doing so.
- ComposableNode describes the component we want to be run in the container. Package should be the package of the component. Plugin should be the component's class name. Name is up to the user.
### package.xml
The package.xml is also very similar to your normal package.xml -- you only need to add `<depend>rclcpp_components</depend>`.

Note: I use ament_cmake_auto instead of ament_cmake to make my CMakeLists.txt file cleaner/simpler, but this isn't necessary. There isn't any good documentation on ament_cmake_auto but if you are interested, here is a very basic [example](https://gist.github.com/dirk-thomas/a76f952d05e7b21b0128) and the [source code](https://github.com/ament/ament_cmake/tree/humble/ament_cmake_auto).
### CMakeLists.txt
There are a couple differences here:
- Our compnents should be shared libraries instead of executables. 
- We need to add the line `rclcpp_components_register_nodes(component_library "ComponentClassName")` for each component we build. 

The CMakeLists.txt has a couple examples of [this](https://github.com/WisconsinAutonomous/WAutoDrive/blob/3c4a1984d1db274130e105b99f13e2d1483813bf/workspace/src/common/examples/compose_nodes/CMakeLists.txt#L15).

### Running the composed nodes
Once you have completed the above steps, you should be able to run the composed nodes:
```
colcon build --packages-select your_package
ros2 launch your_package your_launch_file.launch.py
```
