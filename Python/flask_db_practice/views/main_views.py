from flask import Blueprint, render_template
bp = Blueprint('main', __name__, url_prefix='/')


@bp.route('/')
def index():
    return render_template('main.html', hello="Hello")


@bp.route('/index')
def hello_world():
    return 'Hello World!'

