# Examples
- rosbag: 
    read bag file frame by frame
- action example
- cv_bridge example
    Convert ROS image msg and OpenCV image format

# Preparation

turtlebot
---------

``` {.example}
sudo apt install ros-kinetic-turtlebot*
```

# Service

```sh
from [package].srv import [service]
```

Do not use `_` in service file name.

-   ServiceExample.srv \[OK\]
-   Service~Example~.srv \[Wrong\]

# Tutorial (Turtlebot Robot)

gazebo simulator
----------------

``` {.example}
roslaunch turtlebot_gazebo turtlebot_world.launch
```

Rviz
----

``` {.example}
roslaunch turtlebot_rviz_launchers view_navigation.launch
```

joy stick
---------

``` {.example}
roslaunch turtlebot_teleop logitech.launch
```

save map
--------

``` {.example}
rosrun map_server map_saver  -f playground
```

simple~controller~
------------------

How to move robot to a specific point

``` {.example}
roslaunch turtlebot_rviz_launchers view_robot.launch
rosrun  simple_controller controller.py
```

gmapping~launcher~
------------------

``` {.example}
roslaunch gmapping_launcher kinect_gmapping.launch
```

amcl~launch~
------------

``` {.example}
roslaunch  amcl_launcher change_map.launch map_file:=/home/yubao/data/catkin_ws/src/ROSFromScratch/gmapping_launcher/map/playground.yaml
```

service:

``` {.example}
rosservice call /global_localization "{}"
```

movebase~demo~
--------------

``` {.example}
roslaunch movebase_launcher movebase_demo.launch map_file:=/home/yubao/data/catkin_ws/src/ROSFromScratch/gmapping_launcher/map/playground.yaml
```

References
==========

-   mastering~ros~: <https://github.com/qboticslabs/mastering_ros>

