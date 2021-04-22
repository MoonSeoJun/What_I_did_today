import datetime
from pytz import timezone

from flask import Blueprint, request, jsonify
from models import my_user_model as my_user

user_route = Blueprint('user_route', __name__)

@user_route.route('/', methods=['GET'])
def select_user(name):
    select_user = my_user.MyUser.query.filter_by(user_name=name).all()