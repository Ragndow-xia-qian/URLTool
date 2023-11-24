//
// Created by 37237 on 2023/11/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Mainwindow.h" resolved

#include <QUrl>
#include <QDesktopServices>
#include <QCloseEvent>

#include "Headers/mainwindow.h"
#include "../Forms/ui_Mainwindow.h"

namespace UI {
    Mainwindow::Mainwindow(QWidget *parent) :
            QWidget(parent), ui(new Ui::Mainwindow) {
        UI::Ui::Mainwindow::setupUi(this);
    }

    template<typename T>
    T Mainwindow::popup(Message::PopupTemplate<T> &tool, std::string_view s) {
        return tool.popup(s);
    }

    template<>
    void Mainwindow::popup(Message::PopupTemplate<void> &tool, std::string_view s) {
        tool.popup(s);
    }

    void Mainwindow::closeEvent(QCloseEvent *event) {
        Message::AskPopup ask;
        if (this->popup(ask, "确定要退出吗")) {
            event->accept();
            return;
        }
        event->ignore();
    }

    void Mainwindow::exportURLList(const QStringList &urlList, const QString &filename) {
        QFile file(filename);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Could not open file for writing:" << file.errorString();
            return;
        }

        QTextStream out(&file);

        for (auto &&url: urlList) {
            out << url << "\n";
        }

        file.close();
    }

    void Mainwindow::openURL(const QString &url) {
        QDesktopServices::openUrl(QUrl(url));
    }

    Mainwindow::~Mainwindow() {
        delete ui;
    }
} // UI
