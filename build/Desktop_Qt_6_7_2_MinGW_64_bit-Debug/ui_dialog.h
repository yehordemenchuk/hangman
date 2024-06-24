/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *restart_button;
    QPushButton *exit_button;
    QLabel *game_result;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/game_icon.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Dialog->setWindowIcon(icon);
        restart_button = new QPushButton(Dialog);
        restart_button->setObjectName("restart_button");
        restart_button->setGeometry(QRect(70, 240, 83, 29));
        exit_button = new QPushButton(Dialog);
        exit_button->setObjectName("exit_button");
        exit_button->setGeometry(QRect(240, 240, 83, 29));
        game_result = new QLabel(Dialog);
        game_result->setObjectName("game_result");
        game_result->setGeometry(QRect(100, 90, 221, 20));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Hangman", nullptr));
        restart_button->setText(QCoreApplication::translate("Dialog", "Restart", nullptr));
        exit_button->setText(QCoreApplication::translate("Dialog", "Exit", nullptr));
        game_result->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
