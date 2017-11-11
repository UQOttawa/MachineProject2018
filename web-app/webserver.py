from flask import Flask
from flask import render_template
NUMBER = 0
app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")

@app.route("/increment", methods=["POST"])
def move():
    global NUMBER
    NUMBER = NUMBER+1
    return str(NUMBER)