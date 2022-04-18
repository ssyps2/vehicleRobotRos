#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>

/*---- Prototypes of Function ----*/
void cmdVelCallback(const geometry_msgs::Twist &cmdVel);

const float chassisRadius = 0.166;

ros::Subscriber subCmdVel;
ros::Publisher pubWheelVel[4];

std_msgs::Float64 wheelVel[4];

int main(int argc, char *argv[]){
    ros::init(argc, argv, "chassis_controller");

    ros::NodeHandle handle;

    pubWheelVel[0] = handle.advertise<std_msgs::Float64>("vehicle/Rev1_velocity_controller/command", 1);
    pubWheelVel[1] = handle.advertise<std_msgs::Float64>("vehicle/Rev2_velocity_controller/command", 1);
    pubWheelVel[2] = handle.advertise<std_msgs::Float64>("vehicle/Rev3_velocity_controller/command", 1);
    pubWheelVel[3] = handle.advertise<std_msgs::Float64>("vehicle/Rev4_velocity_controller/command", 1);
    subCmdVel = handle.subscribe("/cmd_vel", 1, &cmdVelCallback);

    ros::spin();

    return 0;
}

void cmdVelCallback(const geometry_msgs::Twist &cmdVel){
    wheelVel[0].data = cmdVel.linear.x - chassisRadius * cmdVel.angular.z;
    wheelVel[1].data = cmdVel.linear.x - chassisRadius * cmdVel.angular.z;
    wheelVel[2].data = cmdVel.linear.x + chassisRadius * cmdVel.angular.z;
    wheelVel[3].data = cmdVel.linear.x + chassisRadius * cmdVel.angular.z;

    for (int i = 0; i < 4; i++){
        pubWheelVel[i].publish(wheelVel[i]);
        ROS_INFO("published NO.%d: %f", i, wheelVel[i].data);
    }

    ROS_INFO("command of x: %lf, z: %lf", cmdVel.linear.x, cmdVel.angular.z);
}