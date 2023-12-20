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
rostopic pub -r 10 /cmd_vel geometry_msgs/Twist "linear:
  x: 2.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 1.0"
```



#### Main Idea

'/cmd_vel' publish command to control the 'linear.x' and 'linear.y' of the vehicle.
The linear speed of each wheel would be controlled by the 'callback' function in 'subscriber'.


#### Problems

1. The Wheel_3 and Wheel_4 joint coordinates displayed on Gazebo are a bit strange, outside of the wheel.
