from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def show_quotes():
    users = []
    # Read file
    with open("quotes.txt", "r") as f:
        for line in f:
            name, quote = line.strip().split(",")
            users.append({"name": name, "quote": quote})
    return render_template("quotes.html", users=users)

if __name__ == '__main__':
    app.run(debug=True)
