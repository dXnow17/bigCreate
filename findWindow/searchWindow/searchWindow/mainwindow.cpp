#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDialog>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QSqlQuery>//执行SQL指令
#include <QTableView>// 显示数据表



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //time设置
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){this->timerUpdata();});
    timer->start(1000);

    //comboBox设置
    QStringList strList;
    strList<<"标题"<<"作者"<<"rfid号码";
    ui->comboBox->addItems(strList);

    //输入框设置
    ui->lineEdit->setPlaceholderText("请输入要查找的书籍信息...");

    //table设置
    this->dbSet("bigcreate");//database连接
    //this->dbAdd();

    model_=new QSqlTableModel(this);
    model_->setTable("bookinfo");
    // model_->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // model_->setSort(0,Qt::AscendingOrder);//设置数据更新模式(行/列某值更新时hi立即更新到数据库
    model_->setHeaderData(0,Qt::Horizontal,"RFID");
    model_->setHeaderData(1,Qt::Horizontal,"标题");
    model_->setHeaderData(2,Qt::Horizontal,"作者");
    model_->setHeaderData(3,Qt::Horizontal,"位置");
    model_->setHeaderData(4,Qt::Horizontal,"状态");
    ui->dbTable->setModel(model_);

    //button设置
    connect(ui->findBtn,&QPushButton::clicked,[=](){this->serBook();});//查找书籍
    connect(ui->showBtn,&QPushButton::clicked,[=](){this->showBook();});//显示书籍

    //持续监听是否返回，若返回 则清空数据，重新查询(不如直接return 0)
    //connect(showWin,&showWindow::backBtn,this,[=]{showWin->hide();this->show();});

}

//timer设置 实时更新
void MainWindow::timerUpdata(){
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd  hh:mm:ss  dddd");
    this->ui->timeLabel->setText(str);
    this->ui->timeLabel->show();
}

//database连接
void MainWindow::dbSet(const QString &name){
    //创建一个数据库连接，指定数据库驱动
    db = QSqlDatabase::addDatabase("QMYSQL",name);
    // 数据库连接需要设置的信息
    db.setHostName("127.0.0.1"); // 数据库服务器IP，我用的是本地电脑
    db.setDatabaseName("bigcreate");// 数据库名
    db.setUserName("root");// 用户名
    db.setPassword("dongxue");// 密码
    db.setPort(3306);// 端口号
    // 连接数据库
    bool ok = db.open();
    if(ok)
        ui->statusBar->showMessage("连接MySQL成功: bigcreate ");
    else
        ui->statusBar->showMessage("连接MySQL失败......");
}

//database建立
void MainWindow::dbAdd(){
    // 实例化QSqlQuery，用于执行sql语句
    QSqlQuery query(db);
    // 创建一个表
    // query.exec("create table bookInfo (rfid varchar(50),title varchar(50),author varchar(50),x int,y int,z int,con int)");
    query.exec("INSERT INTO bookIngo (rfid,title,author,x,y,z,con) VALUES ('2023003960','Qt快速入门','HuoYafei',3,2,3,0)");
    query.exec("INSERT INTO bookIngo (rfid,title,author,x,y,z,con) VALUES ('2022023782','PythonGUI','LeiTonghui',3,1,2,0)");
    query.exec("INSERT INTO bookIngo (rfid,title,author,x,y,z,con) VALUES ('2023021617','Python从入门到精通','LiYanping',1,3,1,0)");
    query.exec("INSERT INTO bookIngo (rfid,title,author,x,y,z,con) VALUES ('2020030325','OpenGL','YanSongbai',2,1,1,0)");
    query.exec("INSERT INTO bookIngo (rfid,title,author,x,y,z,con) VALUES ('2008070630','计算机图形学基础','LuFeng',2,3,3,1)");

}

//serBtn设置 查找书籍
void MainWindow::serBook(){
    QString type=ui->comboBox->currentText();
    QString inPut=ui->lineEdit->text();
    //两个参数上传数据库 得到信息展示在table里 更改状态
    // QString sql =  "SELECT * FROM bookInfo WHERE "+ type + "= "+ inPut +""; // 组装sql语句
    // QSqlQuery query(db);                               // [1] 传入数据库连接
    // query.exec(sql);                                   // [2] 执行sql语句
    // while (query.next()) {                             // [3] 遍历查询结果
    //     // qDebug() << QString("Id: %1, Username: %2")
    //     //                 .arg(query.value("id").toInt())
    //     //                 .arg(query.value("username").toString());
    // }
    model_->setFilter("");


}
//showBtn设置 显示书籍
void MainWindow::showBook(){
    //模态、非模态对话框
    // QDialog warning(this);
    // warning.resize(200,100);
    // warning.exec();
    // //warning.show();
    // warning.setAttribute(Qt::WA_DeleteOnClose);
    //消息对话框
    //if()
        QMessageBox::information(this,"注意","请选定一个需要显示的书籍！");
    // else{
    //转换另一个界面
        QTimer::singleShot(500,this,[=](){//延时0.5s
            showWin = new showWindow;
            this->hide();
            showWin->show();
        });
}

MainWindow::~MainWindow()
{
    delete ui;
}
