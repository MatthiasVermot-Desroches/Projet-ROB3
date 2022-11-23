#!/bin/bash
currentdate=$(date +%F-%H-%M-%S)
maximum=5
file_name="/<chemin>/classiclog_$currentdate"
logfile="/var/log/dump-mysql.log"
mysqldump -u username --password -C <nom database> > $file_name
bzip2 $file_name
echo "$currentdate : The database backup has been successfully created">> $logfile
number_of_files=$(ls -F /<chemin> | wc -l)
if [ "$number_of_files" -gt "$limite" ];
then 
    echo "$currentdate : The oldest backup will be removed" >> $logfile
    rm /<chemin>/"$(ls -t /<chemin> | tail -1)"; #peut-être faire rm -f pour être sûr de pouvoir remove le fichier
    echo "$currentdate : The oldest backup has been successfully removed" >> $logfile
fi
