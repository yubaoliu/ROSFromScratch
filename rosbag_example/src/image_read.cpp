// http://docs.ros.org/diamondback/api/rosbag/html/c++/classrosbag_1_1MessageInstance.html
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>

int main(int argc, char** argv)
{
    std::cout << "Read image from bag file" << std::endl;
    std::cout << "Please set image_topic_name and bagfile_name" << std::endl;

    std::string image_topic_name = "/camera/rgb/image_color";
    std::string bagfile_name = "/home/yubao/data/Dataset/TUM/freiburg3/rgbd_dataset_freiburg3_walking_xyz.bag";
    std::cout << "topic name: " << image_topic_name << std::endl;

    cv::Mat image;

    rosbag::Bag bag;
    bag.open(bagfile_name);
    for (rosbag::MessageInstance const m : rosbag::View(bag)) {
        // fetch image topic name
        std::string imgTopic = m.getTopic();
        if (image_topic_name == imgTopic) {
            try {
                sensor_msgs::ImageConstPtr imgMsgPtr = m.instantiate<sensor_msgs::Image>();
                image = cv_bridge::toCvCopy(imgMsgPtr)->image;
            } catch (cv_bridge::Exception& e) {
                ROS_ERROR("Image convert error");
            }
            cv::circle(image, cv::Point(image.cols/ 2, image.rows/ 2), 10, cv::Scalar(255, 0, 255), 3);
            cv::imshow("image", image);
            cv::waitKey(1);
        }
    }

    bag.close();
    return 0;
}
