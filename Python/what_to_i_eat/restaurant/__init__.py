from typing import Mapping
from flask import Flask, json, jsonify, request
from flask_cors import CORS, cross_origin
import pymysql

mydb = pymysql.connect(host="[HOSTNAME]", user="[USERNAME]", 
		passwd="[PASSWORD]", db="[DBNAME]", charset="utf8")

app = Flask(__name__)
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'

def map_lists(key, value) -> dict:
    response_value = dict(zip(key, value))
    return response_value


@app.route('/')
@cross_origin()
def main():
    return jsonify(message="Here is Main Page")


@app.route('/hello')
@cross_origin()
def index():
    return jsonify(hello="World")


@app.route('/datas/<int:id>', methods=('GET','PUT'))
@cross_origin()
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

    cur.execute(f"select * from `restaurant`.`users` where id={id};")
    user_info = ['id','name','cost']
    data_list = list(cur.fetchone())
    response_json = map_lists(user_info, data_list)
    cur.close()
    return jsonify(user=response_json)


@app.route('/datas', methods=('GET', 'POST'))
@cross_origin()
def data():
    cur = mydb.cursor()
    if request.method == 'POST':
        try:
            name = request.json["name"]
            cost = request.json["cost"]
            cur.execute(f"insert  into `restaurant`.`users` (name, cost) values ('{name}',{cost})")
            mydb.commit()
            cur.close()
            return jsonify(True)
        except:
            return jsonify(False)


@app.route('/post-test', methods=('POST', 'GET'))
@cross_origin()
def test_post():
    if request.method == 'POST':
        id = request.json["id"]
        return jsonify(Id=id)
    return jsonify(hello="World")

