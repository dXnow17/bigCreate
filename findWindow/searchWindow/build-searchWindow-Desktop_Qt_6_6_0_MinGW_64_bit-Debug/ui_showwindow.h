/********************************************************************************
** Form generated from reading UI file 'showwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWWINDOW_H
#define UI_SHOWWINDOW_H

#include <QtCore/QVariant>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showWindow
{
public:
    QOpenGLWidget *openGLWidget2;
    QOpenGLWidget *openGLWidget3;
    QPushButton *backBtn;
    QLabel *positionLabel;

    void setupUi(QWidget *showWindow)
    {
        if (showWindow->objectName().isEmpty())
            showWindow->setObjectName("showWindow");
        showWindow->resize(1000, 600);
        openGLWidget2 = new QOpenGLWidget(showWindow);
        openGLWidget2->setObjectName("openGLWidget2");
        openGLWidget2->setGeometry(QRect(60, 90, 300, 500));
        openGLWidget3 = new QOpenGLWidget(showWindow);
        openGLWidget3->setObjectName("openGLWidget3");
        openGLWidget3->setGeometry(QRect(390, 90, 600, 500));
        backBtn = new QPushButton(showWindow);
        backBtn->setObjectName("backBtn");
        backBtn->setGeometry(QRect(810, 20, 141, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(16);
        backBtn->setFont(font);
        positionLabel = new QLabel(showWindow);
        positionLabel->setObjectName("positionLabel");
        positionLabel->setGeometry(QRect(100, 20, 311, 41));
        positionLabel->setFont(font);

        retranslateUi(showWindow);

        QMetaObject::connectSlotsByName(showWindow);
    } // setupUi

    void retranslateUi(QWidget *showWindow)
    {
        showWindow->setWindowTitle(QCoreApplication::translate("showWindow", "Form", nullptr));
        backBtn->setText(QCoreApplication::translate("showWindow", "\350\277\224\345\233\236", nullptr));
        positionLabel->setText(QCoreApplication::translate("showWindow", "position", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showWindow: public Ui_showWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWWINDOW_H
