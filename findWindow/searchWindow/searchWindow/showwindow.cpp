#include "showwindow.h"
#include "ui_showwindow.h"
#include <QDebug>

showWindow::showWindow(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::showWindow)
{
    ui->setupUi(this);
    //widget
    setWindowTitle("显示界面");
    setFixedSize(800,600);

    //backBtn
    connect(ui->backBtn,&QPushButton::clicked,[=](){
        emit this->windowBack();
    });

}

//updateLabel
void showWindow::posUpdate(QString text){
    ui->posLabel->setText(text);
}


showWindow::~showWindow()
{
    delete ui;
}
