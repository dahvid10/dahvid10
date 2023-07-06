from flask import Flask, render_template, jsonify

position_salary = {
    'Legal Developer': 250000,
    'Medical Developer': 500000,
    'Energy Technologist': 250000,
    'Financial Technologist': 250000,
    'Synergist': 150000    
}

position_scale = {
    1: .65,
    2: .75,
    3: .85,
    4: .95,
    5: 1
}

location_scale = {
    'Houston, TX, USA': .95,
    'Nairobi, Kenya': 0.8,
    'Remote': 0.8
}

JOBS = []
id = 0
for position in position_salary:
    for rank in position_scale:
        for location in location_scale:
            role = {
                'id': id,
                'position': position + ' ' + str(rank),
                'location': location,
                'salary': '$' + str(int(position_salary[position] * position_scale[rank] * location_scale[location]))
            }
            JOBS.append(role)
            id += 1

app = Flask(__name__)
@app.route('/')
def home():
    return render_template('home.html',
                           jobs = JOBS,
                           num_jobs = len(JOBS))

@app.route('/api/jobs')
def list_jobs():
    return jsonify(JOBS)

if __name__ == '__main__':
    app.debug = True
    app.run()
    app.run(debug = True)
