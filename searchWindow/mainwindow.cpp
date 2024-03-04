#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDialog>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>


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
    //table设置 可简化为文件操作 或 魔术操作
    //database连接
    dBptr = new DataBase;
    if (dBptr->ok)
        ui->statusBar->showMessage("连接MySQL成功: bigcreate ");
    else
        ui->statusBar->showMessage("连接MySQL失败......");

    //button设置
    connect(ui->findBtn,&QPushButton::clicked,[=](){this->serBook();});//查找书籍
    connect(ui->showBtn,&QPushButton::clicked,[=](){this->showBook();});//显示书籍



    //持续监听是否返回，若返回 则清空数据，重新查询(不如直接return 0)
    //connect(showWin,&showWindow::backBtn,this,[=]{showWin->hide();this->show();});

}

//时间设置 实时更新
void MainWindow::timerUpdata(){
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd  hh:mm:ss  dddd");
    this->ui->timeLabel->setText(str);
    this->ui->timeLabel->show();
}

//serBtn设置 查找书籍
void MainWindow::serBook(){
    //ui->comboBox->currentText();
    //ui->lineEdit->text();
    //两个参数上传数据库 得到信息展示在table里 更改状态


}
//showBtn设置 显示书籍
void MainWindow::showBook(){
    // if(info->isFind==0){
    //模态、非模态对话框
    // QDialog warning(this);
    // warning.resize(200,100);
    // warning.exec();
    // //warning.show();
    // warning.setAttribute(Qt::WA_DeleteOnClose);
    //消息对话框
    QMessageBox::information(this,"注意","请选定一个需要显示的书籍！");
    // }
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
