import pymysql

db = pymysql.connect(host="localhost", user="root", passwd="m-s-j-0-1-3-0", db="restaurant", charset="utf8")
cur = db.cursor()

id = 1

user_info = ['id','name','cost']
cur.execute(f"select * from `restaurant`.`users` where id={id};")
data_list = list(cur.fetchone())
print(data_list)
response_json = dict(zip(user_info, data_list))

print(response_json)
