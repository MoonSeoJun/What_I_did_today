from flask import Blueprint, json, request, jsonify
from ..models import mydb
import uuid

users = Blueprint('users', __name__, url_prefix='/datas')

@users.route('/')
def data():
    number = 0
    cur = mydb.cursor()
    json_list = []
    cur.execute(f"select * from `restaurant`.`users`;")
    result = cur.fetchall()
    for row in result:
        json_list.append({f"user{number}": {"id" : row[0], "name" : row[1], "cost" : row[2]}})
        number += 1

    cur.close()
    return jsonify(users=json_list)


@users.route('/create', methods=('GET', 'POST'))
def create_user():
    if request.method == 'POST':
        try:
            cur = mydb.cursor()
            name = request.json["name"]
            cost = request.json["cost"]
            cur.execute(f"insert  into `restaurant`.`users` (name, cost) values ('{name}',{cost})")
            mydb.commit()
            cur.close()
            del(name, cost)
            return jsonify(True)
        except:
            return jsonify(False)
    return jsonify(message="Status Ok")


@users.route('/<int:id>', methods=('GET','PUT'))
def datas(id):
    cur = mydb.cursor()
    if request.method == 'PUT':
        try:
            name = request.json["name"]
            cost = request.json["cost"]
            cur.execute(f"update `restaurant`.`users` set name='{name}', cost={cost} where id={id};")
            mydb.commit()
            cur.close()
            return jsonify(True)
        except:
            return jsonify(False)

    json_list = []
    cur.execute(f"select * from `restaurant`.`users` where id={id};")
    result = cur.fetchall()
    for row in result:
        json_list.append({"id" : row[0], "name" : row[1], "cost" : row[2]})
        
    cur.close()
    return jsonify(user=json_list)

