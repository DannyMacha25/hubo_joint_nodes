#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

int main(int argc, char** argv) {
    // Initialize Ros
    ros::init(argc, argv, "publisher_node");

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<sensor_msgs::JointState>("/joint_refs",1000);

    ros::Rate loop(1000);

    // Initialize Message
    sensor_msgs::JointState state;
    state.name = {"RHY", "RHR", "RHP", "RKN", "RAP", "RAR",
        "LHY", "LHR", "LHP", "LKN", "LAP", "LAR",
        "RSP", "RSR", "RSY", "REB", "RWY", "RWP",
        "LSP", "LSR", "LSY", "LEB", "LWY", "LWP",
        "WST",
        "RWY2", "RHAND", "LWY2", "LHAND",
        "RWH", "LWH"};
    
    std::vector<double> p(31, 0);
    std::vector<double> v(31, 3);

    state.position = p;
    state.velocity = v;

    while(ros::ok()) {

        pub.publish(state);
        ros::spinOnce();
    }
}