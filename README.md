Open Gazebo:

```bash
roslaunch vehicle_description gazebo.launch 
```

Open link/joint velocity controller:

```bash
roslaunch vehicle_description controller.launch 
```

Open (load) chassis_controller node:

```
roslaunch vehicle_motion_control motion_controller.launch 
```

Publish velocity message:

```bash
rostopic pub /cmd_vel geometry_msgs/Twist "linear:
  x: 2.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 1.0"
```



#### Main Idea

/cmd_vel发布控制小车linear.x和angular.z的信息，subscriber接收到后在callback函数内publish控制每一个轮的线速度



#### Problems

1, publish运动指令后subscriber能接收到，但是打开rqt_graph后显示/chassis_controller节点没能发布 /vehicle/Rev1_velocity_controller/command话题

2, 在Gazebo上显示的Wheel_3和Wheel_4 joint坐标有点奇怪，在轮子之外
