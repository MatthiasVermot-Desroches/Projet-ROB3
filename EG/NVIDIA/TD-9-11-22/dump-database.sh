#!/bin/bash

DB_BACKUP_PATH='/home/user/'
TODAY=`date +"%Y-%m-%d-%H-%M-%S"`
LOG_PATH='/var/log/dump-mysql.log'

MYSQL_USER='username'
MYSQL_PASSWORD='password'
DATABASE_NAME='classicmodels'
BACKUP_RETAIN_MINUTES=50


echo "${TODAY} - Backup started for database - ${DATABASE_NAME}" >> ${LOG_PATH}

mysqldump -u ${MYSQL_USER} -p=${MYSQL_PASSWORD} ${DATABASE_NAME} | gzip > ${DB_BACKUP_PATH}/${DATABASE_NAME}-${TODAY}.sql.bz2

if [ $? -eq 0 ]; then
  echo "Database backup successfully completed" >> ${LOG_PATH}
else
  echo "Error found during backup" >> ${LOG_PATH}
  exit 1
fi

DBDELDATE=`date +"%Y-%m-%d-%H-%M-%S" --date="${BACKUP_RETAIN_MINUTES} minutes ago"`

find  ${DB_BACKUP_PATH}/* -mmin +${BACKUP_RETAIN_MINUTES} -exec rm {} \;