from typing import Mapping
from flask import Flask, jsonify, request
from flask_cors import CORS, cross_origin
import numpy as np
import pymysql

mydb = pymysql.connect(host="[Hostname]", user="[Username]", 
		passwd="[Password]", db="[DatabaseName]", charset="utf8")
cur = mydb.cursor()

app = Flask(__name__)
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'

@app.route('/')
@cross_origin()
def main():
    return jsonify(main={"temp":24,"feels_like":23.53,"temp_min":24,"temp_max":24,"pressure":1020,"humidity":41})

@app.route('/hello')
@cross_origin()
def index():
    return jsonify(hello="World")


@app.route('/datas/<int:id>')
@cross_origin()
def datas(id):
    user_info = ['id','name','cost']
    cur.execute(f"select * from `restaurant`.`users` where id={id};")
    data_list = list(cur.fetchone())
    response_json = dict(zip(user_info, data_list))
    return jsonify(user=response_json)


@app.route('/post-test', methods=['POST', 'GET'])
def test_post():
    if request.method == 'POST':
        id = request.json["id"]
        return jsonify(id=id)
    return jsonify(hello="World")
