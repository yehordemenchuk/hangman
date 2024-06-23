#include "dialog.h"
#include "game.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, Game *game)
    : QDialog { parent }
    , ui { new Ui::Dialog }
    , m_game { game }
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::show_game_results() {
    switch(m_game->get_state_of_game()) {
        case game::GAME_WON:
            ui->game_result->setText("You won the game!!!");

            break;

        case game::GAME_OVER:
            ui->game_result->setText("You loose. The word was: " + QString(m_game->get_secret().c_str()));

            break;
    }
}

void Dialog::on_restart_button_clicked()
{
    close();

    m_game->init();

    m_game->render();
}


void Dialog::on_exit_button_clicked()
{
    m_game->close();

    close();
}

