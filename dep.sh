#!/bin/bash

# This script is used to install mysql server and set the root password to "root"

# Install mysql server
sudo apt-get install mysql-server

# Set the root password to "root"
sudo mysql -uroot -e "update mysql.user set authentication_string=password('root') where user='root';
flush privileges;"
sudo mysql -uroot -e "update mysql.user set plugin='mysql_native_password' where user = 'root';"
sudo mysql -uroot -e "flush privileges;"
sudo service mysql restart



# Create a database named "test"
mysql -uroot -proot -e "create database test"

