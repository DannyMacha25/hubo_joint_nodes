## Setup
To start with this repo you need to 
1. Clone [this repo](https://github.com/benedictquartey/hubo_ros/tree/main) and literally this repo into your catkin workspace.
2. Source your environment.
3. Rosrun hubo_ros hubotalker to send msgs to Hubo. (publisher_node requires this) 
4. Rosrun hubo_ros hubolistener to read joint states from Hubo (subscriber_node requires this)
5. Rosrun hubo_joint_subscriber subscriber_node or publisher_node

## Publisher_Node
This node publishes to the "/joint_refs" topic and is an example of how to use the hubotalker node with ros. All that is required to move Hubo's joints is to publish to "/joint_refs"

## Subscriber_Node
This node listens to "/joint_states" and will get the current position of all of the joints on Hubo.
