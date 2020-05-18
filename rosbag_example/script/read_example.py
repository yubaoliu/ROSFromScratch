#!/usr/bin/python
# http://wiki.ros.org/rosbag/Code%20API
import rosbag
bag = rosbag.Bag('test.bag')
for topic, msg, t in bag.read_messages(topics=['chatter', 'numbers']):
    print(topic)
    print(msg)
bag.close()
