#Ce script permet de sauvegarder une carte en format png
#!/bin/bash
source /home/<user>/catkin_ws/devel/setup.bash
cd /home/<user>/catkin_ws/maps
currentdate=$(date +%F-%H-%M-%S)
maximum_number_of_png_files=10
maximum_number_of_yaml_and_pgm_files=10
rosrun map_server map_saver map_$currentdate #la carte générée sur l'interface est sauvegardée dans le répertoire actuel
logfile="var/log/mapsaved.log"
echo "$currentdate : The map was successfully saved">> $logfile
convert map_$currentdate.pgm /home/<user>/catkin_ws/map_in_png/map_$currentdate.png
echo "$currentdate : The map was successfully converted into a png file">> $logfile
number_of_png_files=$(ls -F /home/<user>/catkin_ws/map_in_png | wc -l)
number_of_yaml_and_pgm_files=$(ls -F /home/<user>/catkin_ws/maps | wc -l)
if [ "$number_of_png_files" -gt "$maximum_number_of_png_files" ];
then 
    echo "$currentdate : The oldest map will be removed" >> $logfile
    rm -f /home/<user>/catkin_ws/map_in_png/"$(ls -t /home/<user>/catkin_ws/map_in_png | tail -1)";
    echo "$currentdate : The oldest map has been successfully removed" >> $logfile
fi
if [ "$number_of_yaml_and_pgm_files" -gt "$maximum_number_of_yaml_and_pgm_files" ];
then 
    echo "$currentdate : The oldest  .yaml and .pgm will be removed" >> $logfile
    for i in {0..1}
    do
      rm -f /home/<user>/catkin_ws/maps/"$(ls -t /home/<user>/catkin_ws/maps | tail -1)";
    done
    echo "$currentdate : The oldest .yaml and .pgm have been successfully removed" >> $logfile
fi
