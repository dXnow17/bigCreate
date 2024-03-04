#include "DataBase.h"

#include <QSqlQuery>//数据库处理
DataBase::DataBase(QWidget *parent)
    : QMainWindow{parent}
{
    // ;创建一个数据库连接，指定数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // 数据库连接需要设置的信息
    db.setHostName("127.0.0.1"); // 数据库服务器IP，我用的是本地电脑
    db.setDatabaseName("bigcreate");// 数据库名
    db.setUserName("root");// 用户名
    db.setPassword("dongxue");// 密码
    db.setPort(3306);// 端口号
    // 连接数据库
    ok = db.open();
}

//DataBase建立
void DataBase::dbBuild(){
    // 实例化QSqlQuery，用于执行sql语句
    QSqlQuery query("bigcreate");
    // 创建一个表
    query.exec("create table bookInfo (rfid varchar(50),title varchar(50),author varchar(50),x int,y int,z int,condition int)");
    query.exec("INSERT INTO bookIngo (rfid,title,author,x,y,z,condition) VALUES ('2023003960','Qt快速入门','HuoYafei',3,2,3,0)");
    query.exec("INSERT INTO bookIngo (rfid,title,author,x,y,z,condition) VALUES ('2022023782','PythonGUI','LeiTonghui',3,1,2,0)");
    query.exec("INSERT INTO bookIngo (rfid,title,author,x,y,z,condition) VALUES ('2023021617','Python从入门到精通','LiYanping',1,3,1,0)");
    query.exec("INSERT INTO bookIngo (rfid,title,author,x,y,z,condition) VALUES ('2020030325','OpenGL','YanSongbai',2,1,1,0)");
    query.exec("INSERT INTO bookIngo (rfid,title,author,x,y,z,condition) VALUES ('2008070630','计算机图形学基础','LuFeng',2,3,3,1)");
}
