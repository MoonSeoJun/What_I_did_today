from flask import Flask, Blueprint, jsonify, request
from sqlalchemy import create_engine, text


def create_app():
    app = Flask(__name__)
    app.config.from_pyfile('config.py')

    database = create_engine(app.config['DB_URL'], encoding='utf-8')
    app.database = database

    @app.route('/sign-up', methods=['POST'])
    def sign_up():
        user = request.json
        user_id = app.database.execute(text("""
                                                INSERT INTO user (
                                                email,
                                                password
                                               ) VALUES (
                                                :email,
                                                :password
                                               )
                                                """), user).lastrowid

        return "", 200

    from .views import main_views
    app.register_blueprint(main_views.bp)

    return app

