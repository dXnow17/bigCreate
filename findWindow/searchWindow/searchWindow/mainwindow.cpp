#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QSqlQuery>//执行SQL指令
#include <QTableWidget>
#include <QTableView>
#include <QModelIndex>

#define ROWSUM 10

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("查询界面");
    setFixedSize(800,600);

    showWin = new showWindow;

    //time设置
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){this->timerUpdata();});
    timer->start(1000);

    //comboBox设置
    QStringList strList;
    strList<<"title"<<"author"<<"rfid";
    ui->comboBox->addItems(strList);

    //输入框设置
    ui->lineEdit->setPlaceholderText("请输入要查找的书籍信息...");

    //table设置
    this->dbSet("bigcreate");//database连接
    //this->dbAdd();
    this->tableViewSet();
    listLen=-1;


    //button设置
    connect(ui->findBtn,&QPushButton::clicked,[=](){this->serBook();});//查找书籍
    connect(ui->showBtn,&QPushButton::clicked,[=](){this->showBook();});//显示书籍
    connect(showWin,&showWindow::windowBack,this,[=](){
        showWin->hide();
        this->show();
    });
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

//tableView建立
void MainWindow::tableViewSet(){
    //设置行数:ROWSUM=10 列数固定表头数5 不可更改
    model = new QStandardItemModel(ROWSUM,5,this);
    //设置表头 不可更改
    QStringList headerText;
    headerText<<"RFID号码"<<"标题"<<"作者"<<"位置"<<"借还状态";
    model->setHorizontalHeaderLabels(headerText);
    ui->tableView->setModel(model);
    //设置列宽：自适应
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // ui->tableView->setColumnWidth(0,30);
    //行背景色交替改变，隔行颜色变化 行选定：ui 不可编辑：ui 只能选单行：ui
    ui->tableView->setAlternatingRowColors(true);
}

//serBtn设置 查找书籍：精确查找 可提升！！！！
void MainWindow::serBook(){
    QString type=ui->comboBox->currentText();
    QString inPut=ui->lineEdit->text();
    if(!ui->lineEdit->isModified())
        QMessageBox::information(this,"注意","请输入查询关键字！");
    else{
        //两个参数上传数据库 得到信息展示在table里 更改状态
        QString sql = QString("SELECT * FROM bookInfo WHERE %1 like '%%2%'").arg(type).arg(inPut) ; // 组装sql语句
        // qDebug() << sql <<"\n";

        QSqlQuery query(db);                               // [1] 传入数据库连接
        query.exec(sql);                                   // [2] 执行sql语句
        listLen=-1;
        while(query.next()&&listLen<ROWSUM){
            listLen++;
            model->setItem(listLen,0,new QStandardItem(query.value("rfid").toString()));
            model->setItem(listLen,1,new QStandardItem(query.value("title").toString()));
            model->setItem(listLen,2,new QStandardItem(query.value("author").toString()));
            QString positon = QString("%1列%2架%3层")
                                  .arg(query.value("x").toInt())
                                  .arg(query.value("y").toInt())
                                  .arg(query.value("z").toInt());
            model->setItem(listLen,3,new QStandardItem(positon));
            QString con;
            if(query.value("con").toInt()==0)
                con = "可借";
            else if(query.value("con").toInt()==1)
                con = "已被借出";
            else if(query.value("con").toInt()==2)
                con = "不在架上";
            model->setItem(listLen,4,new QStandardItem(con));
        }
    }
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
    // qDebug() << listLen <<"\n";
    // qDebug() << ui->tableView->currentIndex().row() <<"\n";
    int rowCur = ui->tableView->currentIndex().row();
    if(rowCur > listLen)
        QMessageBox::information(this,"注意","请选定一个需要显示的书籍！");
    else{//转换另一个界面
        QModelIndex index1 =model->index(rowCur,3);
        showWin->posUpdate(model->data(index1).toString());

        QTimer::singleShot(500,this,[=](){//延时0.5s
            this->hide();
            showWin->show();
        });
    }
}

//析构函数
MainWindow::~MainWindow()
{
    delete ui;
}
