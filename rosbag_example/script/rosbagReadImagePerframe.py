#!/usr/bin/python
from __future__ import print_function
import os
import sys
import roslib
import rosbag
import rospy
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

class ImageCreator():
    def __init__(self):
        self.bridge = CvBridge()
        # Get topics
        self.image_topic = rospy.get_param('~image_topic',
                                           '/camera/rgb/image_color')
        self.bagfile_name = rospy.get_param('~bagfile_name', 'bagfile')

        print('image topic: ', self.image_topic)
        print('bagfile name: ', self.bagfile_name)

        with rosbag.Bag(self.bagfile_name, 'r') as bag:
            for topic, msg, t in bag.read_messages():
                if topic == "/camera/rgb/image_color":
                    try:
                        cv_image = self.bridge.imgmsg_to_cv2(
                            msg, desired_encoding="bgr8")
                    except CvBridgeError as e:
                        print(e)
                    timestr = "%.6f" % msg.header.stamp.to_sec()
                    # image_name = timestr + ".jpg"
                    # cv2.imwrite(image_name, cv_image)


if __name__ == '__main__':
    rospy.init_node('rosbagreader', anonymous=True)
    rate = rospy.Rate(10)  # 10hz
    try:
        image_creator = ImageCreator()
    except rospy.ROSInterruptException:
        pass
