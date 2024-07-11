#include <QApplication>
#include <QDialog>
#include <Qstring>
#include "game.h"
#include "dialog.h"
#include "ui_game.h"
#include "words.h"

Game::Game(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
}

void Game::init() 
{
    string dictionary_words[words::words_count];

    upload_words(dictionary_words, this);

    m_state_of_game = game::PLAYING;

    m_secret_word = generate_secret_word(dictionary_words);

    m_user_input = m_secret_word;

    m_game_output = generate_output_word(m_secret_word, m_user_input, game::basic_output_word);

    m_attempts_count = game::attempts_count;
}

void dialog_window_init(Game* game_ptr) 
{
    Dialog dialog_window(nullptr, game_ptr);

    dialog_window.setModal(game::modal);

    dialog_window.show_game_results();

    dialog_window.show();

    dialog_window.exec();
}

void Game::render() 
{
    switch(m_state_of_game) 
    {
        case game::PLAYING:
            ui->current_attempts_count->setText(QString::number(m_attempts_count));

            ui->game_output->clear();

            for (auto output_char : m_game_output)
                ui->game_output->setText(ui->game_output->text() + QString(output_char) + QString(game::delimiter));

            show();

            break;

        default:
            dialog_window_init(this);
    }
}

void Game::update() 
{
    m_user_input = str_to_lower(ui->userGuess->text().toStdString());

    ui->userGuess->clear();

    m_attempts_count--;

    m_game_output = generate_output_word(m_secret_word, m_user_input, m_game_output);

    if (m_attempts_count == game::finish_game_attempts_count && m_secret_word != m_game_output && m_secret_word != m_user_input)
        m_state_of_game = game::GAME_OVER;

    else if (m_user_input.length() > game::min_input_len && m_secret_word == m_user_input)
        m_state_of_game = game::GAME_WON;

    else if (m_secret_word == m_game_output)
        m_state_of_game = game::GAME_WON;
}

string Game::get_secret() 
{
    return m_secret_word;
}

game::game_state Game::get_state_of_game() 
{
    return m_state_of_game;
}

void hangman_game() 
{
    Game hangman;

    hangman.init();

    hangman.render();

    hangman.exec();
}

void Game::on_enterButton_clicked()
{
    if (ui->userGuess->text() != game::invalid_input && ui->userGuess->text() != game::cheat_input)
    {
        update();
        render();
    }
}
