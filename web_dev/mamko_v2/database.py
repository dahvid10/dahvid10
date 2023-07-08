import mysql.connector
from mysql.connector import errorcode
import os
from dotenv import load_dotenv
load_dotenv()

conn = mysql.connector.connect(
  user=os.environ.get('DB_USERNAME'),
  password=os.environ.get('DB_PASSWORD'),
  host=os.environ.get('DB_HOST'),
  database=os.environ.get('DB_NAME'),
)

cursor = conn.cursor()
TABLES = {}
TABLES['positions'] = (
  "CREATE TABLE `positions` ("
  "  `pos_id` int(11) NOT NULL AUTO_INCREMENT,"
  "  `title` VARCHAR(250) NOT NULL,"
  "  `location` VARCHAR(250) NOT NULL,"
  "  `salary` INT,"
  "  `currency` VARCHAR(10),"
  "  `responsibilities` VARCHAR(2000),"
  "  `requirements` VARCHAR(2000),"
  "  PRIMARY KEY (`pos_id`)"
  ") ENGINE=InnoDB")

TABLES['applications'] = (
    "CREATE TABLE `applications`("
    "   `app_id` int(11) NOT NULL AUTO_INCREMENT,"
    "   `pos_id` int(11) NOT NULL,"
    "   `first_name` VARCHAR(25),"
    "   `last_name` VARCHAR(25),"
    "   `resume_link` VARCHAR(250),"
    "   `comments` VARCHAR(250),"
    "  PRIMARY KEY (`app_id`)"
    ") ENGINE=InnoDB")

for table_name in TABLES:
    query = TABLES[table_name]
    try:
        print("Creating table {}: ".format(table_name), end='\n')
        cursor.execute(query)
    except mysql.connector.Error as err:
        if err.errno == errorcode.ER_TABLE_EXISTS_ERROR:
            print("already exists.\n")
        else:
            print(err.msg)
    else:
        print("OK\n")

cursor.close()
conn.close()