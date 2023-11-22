/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

namespace UI {

class Ui_Mainwindow
{
public:

    static void setupUi(QWidget *UI_Mainwindow)
    {
        if (UI_Mainwindow->objectName().isEmpty())
            UI_Mainwindow->setObjectName(QString::fromUtf8("UI__Mainwindow"));
        UI_Mainwindow->resize(400, 300);

        retranslateUi(UI_Mainwindow);

        QMetaObject::connectSlotsByName(UI_Mainwindow);
    } // setupUi

    static void retranslateUi(QWidget *UI_Mainwindow)
    {
        UI_Mainwindow->setWindowTitle(QCoreApplication::translate("UI::Mainwindow", "Mainwindow", nullptr));
    } // retranslateUi

};

} // namespace UI


namespace UI::Ui {
    class Mainwindow: public Ui_Mainwindow {};
} // namespace UI::Ui


#endif // UI_MAINWINDOW_H
