/**
  ******************************************************************************
  * @file           : CustomDialog.h
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/12/3
  ******************************************************************************
  */
#ifndef OPENURLTOOL_CUSTOMDIALOG_H
#define OPENURLTOOL_CUSTOMDIALOG_H

#include <QDiaLog>
#include <QListWidget>

namespace URL {

    class CustomDialog : public QDialog {
    Q_OBJECT

    public:
        explicit CustomDialog(QWidget *parent = nullptr);

        [[nodiscard]] QStringList getInputList() const;

        [[nodiscard]] QString getInputPosition() const;

        ~CustomDialog() override;

    private slots:

        void selectFile();

        void addItem();

        void deleteItem();

        void modifyItem();

    private:
        void displayFileContent(const QString &filePath);

    private:
        QListWidget *listWidget;
        QString selectedFilePath;
    };

} // URL

#endif //OPENURLTOOL_CUSTOMDIALOG_H
