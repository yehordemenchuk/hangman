/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QDialog>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QWidget *centralwidget;
    QPushButton *enterButton;
    QLineEdit *userGuess;
    QLabel *game_output;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *current_attempts_count;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QDialog *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName("Game");
        Game->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/game_icon.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Game->setWindowIcon(icon);
        centralwidget = new QWidget(Game);
        centralwidget->setObjectName("centralwidget");
        enterButton = new QPushButton(centralwidget);
        enterButton->setObjectName("enterButton");
        enterButton->setGeometry(QRect(280, 430, 231, 29));
        userGuess = new QLineEdit(centralwidget);
        userGuess->setObjectName("userGuess");
        userGuess->setGeometry(QRect(260, 240, 251, 28));
        game_output = new QLabel(centralwidget);
        game_output->setObjectName("game_output");
        game_output->setGeometry(QRect(260, 100, 201, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 71, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 20, 63, 20));
        current_attempts_count = new QLabel(centralwidget);
        current_attempts_count->setObjectName("current_attempts_count");
        current_attempts_count->setGeometry(QRect(90, 20, 63, 20));

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QDialog *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Hangman", nullptr));
        enterButton->setText(QCoreApplication::translate("Game", "Enter a guess", nullptr));
        game_output->setText(QString());
        label_2->setText(QCoreApplication::translate("Game", "Attempts:", nullptr));
        label_3->setText(QString());
        current_attempts_count->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
