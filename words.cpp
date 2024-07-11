#include <fstream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <string>
#include <QMessageBox>
#include "words.h"
#include "game.h"

string str_to_lower(string str)
{
    for (int i = 0, len = str.length(); i != len; ++i)
        str[i] = tolower(str[i]);

    return str;
}

void upload_words(string dictionary_words[], Game* game) 
{
    ifstream dictionary_file(words::dictionary_file_name);

    if (!dictionary_file) 
    {
        QMessageBox::critical(game, "Error", "Error of loading. Game files were corrupted or loss.");

        exit(EXIT_FAILURE);
    }

    for (int i = 0; i != words::words_count; ++i)
        getline(dictionary_file, dictionary_words[i]);
}

void random_generator_init() 
{
    srand(time(nullptr));
}

string generate_secret_word(const string dictionary_words[]) 
{
    random_generator_init();

    return dictionary_words[rand() % words::words_count + words::min_word_number];
}

string generate_output_word(const string secret_word, const string user_input_word, const string previous_output_word) 
{
    int secret_word_len { static_cast<int>(secret_word.length()) };
    string output_word (secret_word_len, words::default_insert_char);
    
    if (!previous_output_word.empty()) 
    {
        output_word = previous_output_word;

        for (int i = 0, user_input_len = user_input_word.length(); i != user_input_len; ++i) 
        {
            for (int j = 0; j != secret_word_len; ++j) 
            {
                if (user_input_word[i] == secret_word[j])
                    output_word[j] = user_input_word[i];
            }
        }
    }

    return output_word;
}
