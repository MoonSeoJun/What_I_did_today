from typing import Mapping
from flask import Flask, json, jsonify, request
from flask_cors import CORS, cross_origin



def create_app():
    app = Flask(__name__)
    cors = CORS(app)
    app.config['CORS_HEADERS'] = 'Content-Type'

    from .views import user_views
    app.register_blueprint(user_views.users)

    @app.route('/')
    def main():
        return jsonify(message="Here is Main Page")


    @app.route('/hello')
    def index():
        return jsonify(hello="World")


    @app.route('/post-test', methods=('POST', 'GET'))
    def test_post():
        if request.method == 'POST':
            id = request.json["id"]
            return jsonify(Id=id)
        return jsonify(hello="World")

    
    return app