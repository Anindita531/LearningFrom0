from flask import Flask, render_template, redirect, url_for, request

app = Flask(__name__)

@app.route('/')
def home():
    return render_template("home.html")

@app.route('/about')
def about():
    return render_template("about.html")

@app.route('/contact', methods=['GET', 'POST'])
def contact():
    if request.method == 'POST':
        name = request.form['name']
        message = request.form['message']
        print(f"📩 Message from {name}: {message}")  # শুধু console-এ দেখাবে
        return redirect(url_for('thank_you', username=name))
    return render_template("contact.html")

@app.route('/thank/<username>')
def thank_you(username):
    return f"<h2>Thank you, {username}! Your message has been received 💌</h2>"

if __name__ == '__main__':
    app.run(debug=True)
