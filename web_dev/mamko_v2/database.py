import mysql.connector
from mysql.connector import errorcode
import os
from positions import positions_list
# from dotenv import load_dotenv
# load_dotenv()

# get database credentials
conn_user = os.environ.get('DB_USERNAME')
conn_pwd = os.environ.get('DB_PASSWORD')
conn_host = os.environ.get('DB_HOST')
conn_db = os.environ.get('DB_NAME')

# ADD TABLES TO DATABASE
def add_tables_to_db():
    # connect to database
    conn = mysql.connector.connect(
    user=conn_user,
    password=conn_pwd,
    host=conn_host,
    database=conn_db,
    )

    # use handle structure to execute SQL statements
    cursor = conn.cursor()
    TABLES = {}
    TABLES['positions'] = (
    "CREATE TABLE `positions` ("
    "  `id` int(11) NOT NULL AUTO_INCREMENT,"
    "  `position` VARCHAR(250) NOT NULL,"
    "  `location` VARCHAR(250) NOT NULL,"
    "  `salary` INT,"  
    "  `description` VARCHAR(2000),"  
    "  PRIMARY KEY (`id`)"
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

    # close cursor and connection
    cursor.close()
    conn.close()

    # insert positions from database
    def ins_positions(pos_list):
        conn = mysql.connector.connect(
                user=conn_user,
                password=conn_pwd,
                host=conn_host,
                database=conn_db,
            )
        cursor = conn.cursor()        
        add_pos = ("INSERT INTO positions "
                "(position, location, salary, description) "
                "VALUES (%(position)s, %(location)s, %(salary)s, %(description)s)")
        
        for pos in pos_list:
            cursor.execute(add_pos, pos)
        conn.commit() # commit changes after INSERT statement
        cursor.close()
        conn.close()

    ins_positions(positions_list)
    return

# load positions from database
def load_positions():
    conn = mysql.connector.connect(
        user=conn_user,
        password=conn_pwd,
        host=conn_host,
        database=conn_db,
    )
    cursor = conn.cursor()
    query = "SELECT id, position, location, salary, description FROM positions"
    cursor.execute(query)
    fetched_positions = []
    for (id, position, location, salary, description) in cursor:
        # print('{}, is in {} with a salary of ${}.'.format(position, location, salary))
        role = {
            'id': id,
            'position': position,
            'location': location,
            'salary': salary,
            'description': description
        }
        fetched_positions.append(role)
    cursor.close()
    conn.close()
    return fetched_positions

fetched_positions = load_positions()
