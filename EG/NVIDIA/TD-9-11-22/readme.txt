-Installer MySQL (mariadb > mysql):
sudo apt install mysql-server

-Importer la base de données
sudo apt install unzip
unzip mysqlsampledatabase.zip
mysql -u username -p password < mysqlsampledatabase.sql