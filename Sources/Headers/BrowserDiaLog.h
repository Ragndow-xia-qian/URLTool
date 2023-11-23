/**
  ******************************************************************************
  * @file           : BrowserDiaLog.h
  * @author         : 夏浅
  * @brief          : None
  * @attention      : None
  * @date           : 2023/11/19
  ******************************************************************************
  */
#ifndef OPENURLTOOL_BROWSERDIALOG_H
#define OPENURLTOOL_BROWSERDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QDesktopServices>

namespace URL {

    class BrowserDialog : public QDialog
    {
    Q_OBJECT

    public:
        explicit BrowserDialog(QWidget *parent = nullptr);

        [[nodiscard]] QString getURL() const;

        ~BrowserDialog() override;

    private slots:
        void onOKButtonClicked();

    private:
        void setupUI();
        void connectSignalsAndSlots();

    private:
        QLineEdit *urlLineEdit{};
        QPushButton *okButton{};
    };

} // URL

#endif //OPENURLTOOL_BROWSERDIALOG_H
