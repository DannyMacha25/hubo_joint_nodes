#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

using namespace std;

void jointCB(const sensor_msgs::JointState::ConstPtr &msg) {
    ROS_INFO("[Subscriber]: Msg received");
    int joint_count = msg->name.size();

    for (int i = 0; i < joint_count; i++) {
        string output = "Joint: " + msg->name[i] + " Position: " + to_string(msg->position[i]);
        ROS_INFO("%s", output.c_str());
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "subscriber_node");

    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/joint_states", 1000, jointCB);
    ROS_INFO("[Subscriber]: Node Started");

    ros::spin();
}