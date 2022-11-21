#!/bin/bash
currentdate=$(date +%F-%H-%M-%S)
maximum=5
logfile="/<chemin>/classiclog_$currentdate"
mysqldump -u username --password -C <nom database> > $logfile
bzip2 $logfile
number_of_files=$(ls -F /chemin/ | wc -l)
if [ "$number_of_files" -gt "$limite" ];
then 
    rm /<chemin>/"$(ls -t /<chemin> | tail -1)";
fi
