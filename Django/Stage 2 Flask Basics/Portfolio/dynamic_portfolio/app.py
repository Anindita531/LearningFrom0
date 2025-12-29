from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    name = "Anindita Ghosh"
    bio = "Aspiring Data Scientist | Python & Flask Learner"

    skills = ["Python", "Machine Learning", "Flask", "Data Visualization", "SQL"]

    projects = [
        {"title": "User Info Form", "desc": "Flask app to collect user data using POST method"},
        {"title": "Bio Card App", "desc": "Dynamic profile display using route parameters"},
        {"title": "Portfolio Website", "desc": "Personal site with Flask static files"}
    ]

    return render_template("index.html", name=name, bio=bio, skills=skills, projects=projects)

if __name__ == '__main__':
    app.run(debug=True)
