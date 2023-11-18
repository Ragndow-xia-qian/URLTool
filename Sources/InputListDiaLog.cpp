/**
  ******************************************************************************
  * @file           : InputListDiaLog.cpp
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/17
  ******************************************************************************
  */
#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QStringList>
#include <QPushButton>
#include <QFileDialog>

#include "Headers/InputListDiaLog.h"

namespace Input {
    InputListDialog::InputListDialog(QWidget *parent) : QDialog(parent) {

        // 布局管理器
        auto *layout = new QVBoxLayout(this);

        // 列表框
        listWidget = new QListWidget(this);
        layout->addWidget(listWidget);

        // 按钮布局
        auto *buttonLayout = new QHBoxLayout;

        // 添加按钮
        auto *addButton = new QPushButton("Add", this);
        connect(addButton, &QPushButton::clicked, this, &InputListDialog::addItem);
        buttonLayout->addWidget(addButton);

        // 删除按钮
        auto *removeButton = new QPushButton("Remove", this);
        connect(removeButton, &QPushButton::clicked, this, &InputListDialog::removeItem);
        buttonLayout->addWidget(removeButton);

        layout->addLayout(buttonLayout);

        // 确定按钮
        auto *okButton = new QPushButton("OK", this);
        connect(okButton, &QPushButton::clicked, this, &InputListDialog::accept);
        layout->addWidget(okButton);

        // 选择文件按钮
        auto *selectFileButton = new QPushButton("Select File", this);
        connect(selectFileButton, &QPushButton::clicked, this, &InputListDialog::selectFilePos);
        layout->addWidget(selectFileButton);

        setLayout(layout);
    }

    QStringList InputListDialog::getInputList() const {
        QStringList inputList;
        for (int i = 0; i < listWidget->count(); ++i) {
            QListWidgetItem *item = listWidget->item(i);
            auto *lineEdit = qobject_cast<QLineEdit *>(listWidget->itemWidget(item));
            if (lineEdit) {
                inputList << lineEdit->text();
            }
        }
        return inputList;
    }

    QString InputListDialog::getInputPosition() const {
        return position;
    }

    void InputListDialog::addItem() {
        auto *item = new QListWidgetItem(listWidget);
        auto *lineEdit = new QLineEdit(this);
        listWidget->setItemWidget(item, lineEdit);
    }

    void InputListDialog::removeItem() {
        QListWidgetItem *item = listWidget->currentItem();

        delete item;
    }

    void InputListDialog::selectFilePos() {
        position = QFileDialog::getOpenFileName(
                this,
                tr("选择一个txt文件"),
                QDir::homePath(), // 初始目录
                tr("Text Files (*.txt);;All Files (*)")
        );
    }

    InputListDialog::~InputListDialog() {
        for (int i = 0; i < listWidget->count(); ++i) {
            QListWidgetItem *item = listWidget->item(i);
            delete listWidget->itemWidget(item);
            delete item;
        }
    }
} // Input