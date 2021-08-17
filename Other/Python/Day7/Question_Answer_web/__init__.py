from flask import Flask

from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy

import flask_project.config

db = SQLAlchemy()
migrate = Migrate()


def create_app():
    app = Flask(__name__)

    app.config.from_object(config)

    db.init_app(app)
    migrate.init_app(app, db)

    """테이블 생성"""
    from . import models

    from .views import main_view, question_view, answer_views
    app.register_blueprint(main_view.bp)
    app.register_blueprint(question_view.bp)
    app.register_blueprint(answer_views.bp)

    return app
