#! /usr/bin/env python

from action_example.msg import DoDishesAction, DoDishesGoal
import actionlib
import rospy
import roslib
roslib.load_manifest('my_pkg_name')


if __name__ == '__main__':
    rospy.init_node('do_dishes_client')
    client = actionlib.SimpleActionClient('do_dishes', DoDishesAction)
    client.wait_for_server()

    goal = DoDishesGoal()
    # Fill in the goal here
    client.send_goal(goal)
    client.wait_for_result(rospy.Duration.from_sec(5.0))
