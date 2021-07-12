#include "ros/ros.h"
#include "roscpp_app_template/hello.h"

#include <iostream>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "helloworld");
  ros::NodeHandle n;

  ros::Publisher hello_pub =
      n.advertise<roscpp_app_template::hello>("hello", 1000);

  ros::Rate loop_rate(10);

  int count = 0;

  while (ros::ok()) {
    roscpp_app_template::hello hello;
    hello.msg = "hello world!";
    ROS_INFO("send");
    hello_pub.publish(hello);

    ros::spinOnce();

    loop_rate.sleep();
  }
}
