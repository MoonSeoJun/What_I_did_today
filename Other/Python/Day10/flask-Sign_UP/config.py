import os

BASE_DIR = os.path.dirname(__file__)

SECRET_KEY = "dev"

SQLALCHEMY_DATABASE_URI = 'sqlite:///{}'.format(os.path.join(BASE_DIR, '__init__.db'))
SQLALCHEMY_TRACK_MODIFICATIONS = False
