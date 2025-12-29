from flask import Flask, render_template

app = Flask(__name__)

@app.route('/bio/<username>')
def show_bio(username):
    fake_data = {
        "Anindita": 21,
        "Ayaan": 22,
        "Riya": 23
    }
    age = fake_data.get(username, "Unknown")
    return render_template("bio.html", name=username, age=age)

if __name__ == '__main__':
    app.run(debug=True)
