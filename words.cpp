#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <string>
#include "words.h"

void upload_words(string dictionary_words[]) {
    ifstream dictionary_file(words::dictionary_file_name);

    for (int i = 0; i != words::words_count; ++i)
        getline(dictionary_file, dictionary_words[i]);
}

void random_generator_init() {
    srand(time(nullptr));
}

string generate_secret_word(const string dictionary_words[]) {
    random_generator_init();

    return dictionary_words[rand() % words::words_count + words::min_word_number];
}

string generate_output_word(const string secret_word, const string user_input_word) {
    int secret_word_len { static_cast<int>(secret_word.length()) };
    string output_word;
    
    output_word.assign(secret_word_len, words::default_insert_char);

    if (secret_word != user_input_word) {
        for (int i = 0, user_input_len = user_input_word.length(); i != user_input_len; ++i) {
            for (int j = 0; j != secret_word_len; ++j) {
                if (user_input_word[i] == secret_word[j])
                    output_word[j] = user_input_word[i];
            }
        }
    }

    return output_word;
}