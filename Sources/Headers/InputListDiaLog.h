/**
  ******************************************************************************
  * @file           : InputListDiaLog.h
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/17
  ******************************************************************************
  */
#ifndef OPENURLTOOL_INPUTLISTDIALOG_H
#define OPENURLTOOL_INPUTLISTDIALOG_H

#include <QObject>
#include <QDialog>
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QFileDialog> // 添加头文件用于文件对话框

namespace URL {

    class InputListDialog : public QDialog {
    Q_OBJECT

    public:
        explicit InputListDialog(QWidget *parent = nullptr);

        // 返回所有输入框的内容
        [[nodiscard]] QStringList getInputList() const;

        [[nodiscard]] QString getInputPosition() const;

        ~InputListDialog() override;

    public slots:

        // 添加新的输入框项
        void addItem();

        // 删除选中的输入框项
        void removeItem();

        // 选择电脑上的一个地址
        void selectFilePos();

    private:
        QListWidget *listWidget;
        QString position;
    };

} // Input

#endif //OPENURLTOOL_INPUTLISTDIALOG_H
