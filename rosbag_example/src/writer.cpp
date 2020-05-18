#include <ros/ros.h>
#include <rosbag/bag.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "bag_writer");
    ros::NodeHandle nh;

    rosbag::Bag bag;
    bag.open("test.bag", rosbag::bagmode::Write);

    std_msgs::String str;
    str.data = std::string("foo");

    std_msgs::Int32 i;
    i.data = 42;

    bag.write("chatter", ros::Time::now(), str);
    bag.write("numbers", ros::Time::now(), i);

    bag.close();

    ros::spinOnce();

    return 0;
}
