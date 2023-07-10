from flask import Flask, render_template, jsonify
from database import fetched_positions
# from database import conn_user, conn_pwd, conn_host, conn_db, TABLES as tables
# import mysql.connector

app = Flask(__name__)



# load_positions()

@app.route('/')
def home():
    return render_template('home.html',
                           jobs = fetched_positions,
                           num_jobs = len(fetched_positions))

@app.route('/api/jobs')
def list_jobs():
    return jsonify(fetched_positions)

@app.route('/products')
def showcase():
    return 'Incoming'

@app.route('/faqs')
def faqs():
    return 'Incoming'

if __name__ == '__main__':
    app.debug = True
    app.run()
    app.run(debug = True)
