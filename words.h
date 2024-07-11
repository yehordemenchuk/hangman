#ifndef WORDS_H
#define WORDS_H

#include <string>
#include <QCoreApplication>
#include "game.h"

using namespace std;

namespace words 
{
    const string dictionary_file_name = "dictionary.txt";

    const int words_count = 200;

    const int min_word_number = 1;

    const short inserted_chars_count = 1;

    const char default_insert_char = '_';
}

string str_to_lower(string str);

void upload_words(string dictionary_words[], Game* game);

void random_generator_init();

string generate_secret_word(const string dictionary_words[]);

string generate_output_word(const string secret_word, const string user_input_word, const string previous_output_word);

#endif
