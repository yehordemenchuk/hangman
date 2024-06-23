#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <game.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, Game *game = nullptr);
    ~Dialog();
    void show_game_results();

private slots:
    void on_restart_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::Dialog *ui;
    Game *m_game;
};

#endif // DIALOG_H
