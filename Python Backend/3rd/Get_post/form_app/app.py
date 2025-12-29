from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def home():
    return render_template("form.html")

@app.route('/submit', methods=['POST'])
def submit():
    # form data নাও
    name = request.form['username']
    age = request.form['age']
    
    # result template এ পাঠাও
    return render_template("result.html", name=name, age=age)

if __name__ == '__main__':
    app.run(debug=True)
