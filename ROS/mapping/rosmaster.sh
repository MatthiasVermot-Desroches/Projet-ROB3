#Ce script vous permet de lancer le rosmaster
#!/bin/bash
source /home/<user>/catkin_ws/devel/setup.bash
sudo chmod /dev/ttyUSB0 # les lignes 1 et 2 sont là pour éviter les problèmes en cas d'initialisation du robot
cd /home/<user>/catkin_ws/
roslaunch rplidar_ros rplidar.launch #le rosmaster est lancé et il enregistre des points à l'aide du lidar.
