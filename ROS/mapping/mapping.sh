#Ce script permet de lancer la cartographie, si le robot est branché à une interface graphique, vous pourrez la voir se créer et modifier les paramètres et l'angle de vue en direct.
#!/bin/bash
source /home/<user>/catkin_ws/devel/setup.bash #cette ligne est là pour éviter les problèmes liés à l'initialisation du robot
cd /home/<user>/catkin_ws/
roslaunch hector_slam_launch tutorial.launch #l'algorithme slam et une carte vide est lancée dans l'interface du robot, la carte est mise à jours avec les points créer par le Lidar.
