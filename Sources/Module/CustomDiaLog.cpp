/**
  ******************************************************************************
  * @file           : CustomDialog.cpp
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/12/3
  ******************************************************************************
  */
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>

#include "Headers/CustomDiaLog.h"

namespace URL {
    CustomDialog::CustomDialog(QWidget *parent)
            : QDialog(parent), listWidget(new QListWidget(this)) {
        auto *mainLayout = new QVBoxLayout(this);

        // "Select File" button
        auto *selectFileButton = new QPushButton("Select File", this);
        connect(selectFileButton, &QPushButton::clicked, this, &CustomDialog::selectFile);
        mainLayout->addWidget(selectFileButton);

        // List widget to display file content
        mainLayout->addWidget(listWidget);

        // Buttons for add, delete, modify
        auto *buttonLayout = new QHBoxLayout;
        auto *addButton = new QPushButton("Add", this);
        auto *deleteButton = new QPushButton("Delete", this);
        auto *modifyButton = new QPushButton("Modify", this);
        connect(addButton, &QPushButton::clicked, this, &CustomDialog::addItem);
        connect(deleteButton, &QPushButton::clicked, this, &CustomDialog::deleteItem);
        connect(modifyButton, &QPushButton::clicked, this, &CustomDialog::modifyItem);
        buttonLayout->addWidget(addButton);
        buttonLayout->addWidget(deleteButton);
        buttonLayout->addWidget(modifyButton);
        mainLayout->addLayout(buttonLayout);

        // "OK" button
        auto *okButton = new QPushButton("OK", this);
        connect(okButton, &QPushButton::clicked, this, &CustomDialog::accept);
        mainLayout->addWidget(okButton);
    }

    QStringList CustomDialog::getInputList() const {
        QStringList inputList;
        for (int i = 0; i < listWidget->count(); ++i) {
            inputList << listWidget->item(i)->text();
        }
        return inputList;
    }

    QString CustomDialog::getInputPosition() const {
        return selectedFilePath;
    }

    CustomDialog::~CustomDialog() {
        delete listWidget;
    }

    void CustomDialog::selectFile() {
        QString filePath = QFileDialog::getOpenFileName(this, "Select a Text File", "",
                                                        "Text Files (*.txt);;All Files (*)");

        if (!filePath.isEmpty()) {
            selectedFilePath = filePath;
            displayFileContent(filePath);
        }
    }

    void CustomDialog::addItem() {
        QString newItem = QInputDialog::getText(this, "Add Item", "Enter a new item:");
        if (!newItem.isEmpty()) {
            listWidget->addItem(newItem);
        }
    }

    void CustomDialog::deleteItem() {
        QListWidgetItem *selectedItem = listWidget->currentItem();
        delete selectedItem;
    }

    void CustomDialog::modifyItem() {
        QListWidgetItem *selectedItem = listWidget->currentItem();
        if (selectedItem) {
            QString modifiedItem = QInputDialog::getText(this, "Modify Item", "Modify the item:", QLineEdit::Normal,
                                                         selectedItem->text());
            if (!modifiedItem.isEmpty()) {
                selectedItem->setText(modifiedItem);
            }
        }
    }

    void CustomDialog::displayFileContent(const QString &filePath) {
        listWidget->clear();
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            // Read and display the content of the file
            while (!in.atEnd()) {
                QString line = in.readLine();
                listWidget->addItem(line);
            }
            file.close();
        }
    }
} // URL