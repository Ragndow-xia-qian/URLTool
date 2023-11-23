/**
  ******************************************************************************
  * @file           : BrowserDiaLog.cpp
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/19
  ******************************************************************************
  */
#include <QDebug>

#include "Headers/BrowserDiaLog.h"

namespace URL {
    BrowserDialog::BrowserDialog(QWidget *parent) : QDialog(parent) {
        setupUI();
        connectSignalsAndSlots();
    }

    QString BrowserDialog::getURL() const {
        return urlLineEdit->text();
    }

    void BrowserDialog::onOKButtonClicked() {
        accept(); // 直接使用 QDialog 的 accept() 函数来结束对话框的执行
    }

    void BrowserDialog::setupUI() {
        urlLineEdit = new QLineEdit(this);
        okButton = new QPushButton(tr("OK"), this);

        auto *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(urlLineEdit);
        mainLayout->addWidget(okButton);
    }

    void BrowserDialog::connectSignalsAndSlots() {
        connect(okButton, &QPushButton::clicked, this, &BrowserDialog::onOKButtonClicked);
    }

    BrowserDialog::~BrowserDialog() {
        // 删除所有被new出来的对象
        if (urlLineEdit) {
            delete urlLineEdit;
            urlLineEdit = nullptr; // 将指针设置为 nullptr，避免悬挂指针
        }
    }
} // URL