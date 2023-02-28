-Installer MySQL (mariadb > mysql):
sudo apt install mysql-server

-Importer la base de données
sudo apt install unzip
unzip mysqlsampledatabase.zip
mysql -u username -p < mysqlsampledatabase.sql

ou username et password utilisateur mysql
pour ajouter un utilisateur mysql :
sudo mysql
CREATE USER 'username'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON *.* TO 'username'@'localhost';
FLUSH PRIVILEGES;