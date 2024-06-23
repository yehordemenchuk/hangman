#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QString>
#include <string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
    class Game;
}
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace game {
    enum game_state {
        GAME_OVER,
        GAME_WON,
        PLAYING
    };

    const short attempts_count = 5;
    const short finish_game_attempts_count = 0;
    const short min_input_len = 1;
    const string basic_output_word = "";
    const bool modal = true;
    const char delimiter = ' ';
    const QString invalid_input = "";
}
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();
    void init();
    void render();
    void update();
    game::game_state get_state_of_game();
    string get_secret();

private slots:
    void on_enterButton_clicked();

private:
    Ui::Game *ui;
    game::game_state m_state_of_game;
    string m_secret_word;
    string m_user_iput;
    string m_user_input;
    string m_game_output;
    short m_attempts_count;
};

void second_window_init(Game* game_ptr);

void hangman_game(int argc, char* argv[]);

#endif // GAME_H
