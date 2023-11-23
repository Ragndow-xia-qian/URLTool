#include <QApplication>
#include <QGuiApplication>
#include <QScreen>
#include <QRect>
#include <QObject>
#include <QPushButton>

#include "Headers/mainwindow.h"
#include "Headers/Popup.h"
#include "Headers/InputListDiaLog.h"
#include "Headers/BrowserDiaLog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    const QRect screenRect = QGuiApplication::primaryScreen()->geometry();

    Message::AskPopup ask;
    Message::ErrorPopup error;
    Message::InfoPopup info;
    Message::WarningPopup warning;

    Q_UNUSED(ask)
    Q_UNUSED(error)
    Q_UNUSED(info)
    Q_UNUSED(warning)

    QIcon icon{R"(images\icon.ico)"};

    UI::Mainwindow window;

    window.setWindowIcon(icon);

    QRect windowRect = screenRect;

    windowRect.setLeft(screenRect.width() / 4);
    windowRect.setRight(screenRect.width() / 4 * 3);
    windowRect.setTop(screenRect.height() / 4);
    windowRect.setBottom(screenRect.height() / 4 * 3);

    window.setGeometry(windowRect);

//    window.popup(info, "我是提示内容");

    window.show();

    auto showInputList = [&]() {
        URL::InputListDialog inputList(&window);
        inputList.show();

        if (inputList.exec() == QDialog::Accepted) {
            UI::Mainwindow::exportURLList(inputList.getInputList(), inputList.getInputPosition());
        }
    };
    auto showBrowser = [&]() {
        URL::BrowserDialog browser(&window);
        browser.show();

        if (browser.exec() == QDialog::Accepted) {
            UI::Mainwindow::openURL(browser.getURL());
        }
    };

    auto btn1 = QPushButton("Create URL List", &window);
    QObject::connect(&btn1, &QPushButton::clicked, showInputList);

    btn1.move(windowRect.width() / 2 - btn1.width() / 2, windowRect.height() / 2 - btn1.height() / 2);

    btn1.show();

    auto btn2 = QPushButton("Open URL", &window);
    QObject::connect(&btn2, &QPushButton::clicked, showBrowser);

    btn2.move(windowRect.width() / 2 - btn2.width() / 2, windowRect.height() / 2 - btn2.height() / 2 + btn1.height());

    btn2.show();

    return QApplication::exec();
}
