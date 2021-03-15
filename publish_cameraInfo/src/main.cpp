#include "ros/ros.h"
#include "sensor_msgs/CameraInfo.h"
#include "std_msgs/String.h"

#include <sstream>

/**
 * This tutorial demonstrates publish camera Info message
 */
int main(int argc, char** argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;

    ros::Publisher pub_head = n.advertise<std_msgs::Header>("head", 100);
    ros::Publisher pub_camera_info = n.advertise<sensor_msgs::CameraInfo>("cameraInfo", 1000);

    ros::Rate loop_rate(10);

    sensor_msgs::CameraInfoPtr cameraInfo(new sensor_msgs::CameraInfo);
    std_msgs::HeaderPtr header(new std_msgs::Header());

    // cameraInfo->
    float fx = 525.0;
    float fy = 525.0;
    float cx = 319.5;
    float cy = 239.5;

    while (ros::ok()) {

        header->stamp = ros::Time::now();
        header->frame_id = "camera";

        cameraInfo->header = *header;
        cameraInfo->height = 480;
        cameraInfo->width = 640;

        cameraInfo->K = { fx, 0, cx,
            0, fy, cy,
            0, 0, 1 };

        pub_head.publish(*header);
        pub_camera_info.publish(*cameraInfo);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}
