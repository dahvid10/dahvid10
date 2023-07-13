import os
from datetime import datetime
from flask import Flask, render_template, jsonify, request
from database import fetched_positions, load_position_by_id, ins_app
from send_email import send_email

app = Flask(__name__)

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

@app.route('/job/<id>', methods=('GET', 'POST'))
def show_job(id):
    # get position from positions table in db
    position = load_position_by_id(id)
    if not position:
        return "Not Found", 404
    
    if (request.method == 'POST'):
        # get submitted app data
        app_data = request.form
        app_data = app_data.to_dict() # make submitted data modifiable
        # add position id
        app_data['pos_id'] = id 
        # add time stamp        
        timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        app_data['timestamp'] = timestamp
        # store app data in 'applications' table in db
        ins_app(app_data)
        try:
            # send an acknowledgement email
            send_email(app_data['email'], position['position'])
        except:
            pass
        # display an acknowledgement
        return render_template('app_ack.html',
                               app_data=app_data,
                               position=load_position_by_id(id))

    return render_template('application_form.html',
                            position=position)
    
if __name__ == '__main__':
    app.debug = True
    app.run()
    app.run(debug = True)
