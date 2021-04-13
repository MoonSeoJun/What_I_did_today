from flask_wtf import FlaskForm
from wtforms import StringField, TextAreaField, PasswordField
from wtforms.validators import DataRequired, Length, EqualTo, Email
from wtforms.fields.html5 import EmailField

class QuestionForm(FlaskForm):
    subject = StringField('제목', validators=[DataRequired()])
    content = TextAreaField('내용', validators=[DataRequired()])

class UserCreateForm(FlaskForm):
    username = StringField('UserName', validators=[DataRequired(), Length(min=3, max=25)])
    password1 = PasswordField('Password', validators=[DataRequired(), EqualTo('password2', 'password is not matched')])
    password2 = PasswordField('CheckPassword', validators=[DataRequired()])
    email = EmailField('Email', validators=[DataRequired(), Email()])

class UserLoginForm(FlaskForm):
    username = StringField('UserName', validators=[DataRequired(), Length(min=3, max=25)])
    password = PasswordField('Password', validators=[DataRequired()])

class AnswerForm(FlaskForm):
    content = TextAreaField('내용', validators=[DataRequired('내용은 필수입력 항목입니다.')])

class CommentForm(FlaskForm):
    content = TextAreaField('내용', validators=[DataRequired()])