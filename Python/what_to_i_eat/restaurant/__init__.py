from typing import Mapping
from flask import Flask, json, jsonify, request
from flask_cors import CORS, cross_origin
import numpy as np
import pymysql

mydb = pymysql.connect(host="[Hostname]", user="[Username]", 
		passwd="[Password]", db="[dbname]", charset="utf8")

app = Flask(__name__)
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'

def map_lists(key, value) -> dict:
    response_value = dict(zip(key, value))
    return response_value

@app.route('/')
@cross_origin()
def main():
    return jsonify(main={"temp":24,"feels_like":23.53,"temp_min":24,"temp_max":24,"pressure":1020,"humidity":41})

@app.route('/hello')
@cross_origin()
def index():
    return jsonify(hello="World")


@app.route('/datas/<int:id>', methods=('GET','PUT'))
@cross_origin()
def datas(id):
    cur = mydb.cursor()
    if request.method == 'PUT':
        name = request.json["name"]
        cost = request.json["cost"]
        try:
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


@app.route('/post-test', methods=('POST', 'GET'))
def test_post():
    if request.method == 'POST':
        id = request.json["id"]
        return jsonify(id=id)
    return jsonify(hello="World")