from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    return "Welcome to Mini Projects!"

@app.route('/profile/<name>')
def profile(name):   # ❌ তুমি এখানে parameter-এ username লিখেছিলে কিন্তু route-এ <name> দিয়েছিলে
    fake_data = {"Anindita": 21}
    age = fake_data.get(name, "Unknown")
    return render_template("index.html", name=name, age=age)

@app.route('/calc/<int:a>/<int:b>')
def cal(a, b):
    s = a + b
    return f"<h1>The total: {s}</h1>"  # ❌ এখানে ${s} নয়, f-string ব্যবহার করতে হবে

if __name__ == '__main__':
    app.run(debug=True)
