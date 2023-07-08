from flask import Flask, render_template, jsonify
from positions import positions


app = Flask(__name__)
@app.route('/')
def home():
    return render_template('home.html',
                           jobs = positions,
                           num_jobs = len(positions))

@app.route('/api/jobs')
def list_jobs():
    return jsonify(positions)

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
