#include <iostream>
#include <ctime>
#include "Work_file.h"
#include "Work_with_words.h"
#include "Other_1.h"
#include <vector>
using namespace std;
int main()  {
    wstring c ;
    srand(time(0)); // автоматическая рандомизация
    vector<int> probability_words, status_word; // п
    vector<string> ru_words,ru_save_words, en_words,part_of_the_word,subject_word, definition_word, transcription_word;
    int count_words, random_word;
   read_file("ZNO.txt", en_words, ru_words, part_of_the_word, probability_words, count_words, subject_word, definition_word, status_word, transcription_word, ru_save_words);
   write_file("ZNO.txt", en_words, ru_save_words, part_of_the_word, probability_words, count_words, subject_word, definition_word, transcription_word);
    int count_zero_word = 1;
    bool while_ad = true;
    int long secundomer = time(NULL);
   while (while_ad == true){
       SetConsoleOutputCP(1251);
       SetConsoleCP(1251);
       secundomer_1(secundomer);
       cout << "Всего слов - " << count_words << endl;
       cout <<"Слов на проверке - " <<count_new_words (probability_words,3) << endl;
       cout << "Слов не на проверке - " << count_new_words(probability_words, 0) << endl;
       cout << "Слов с некоторым шансом на проверку - " << count_new_words(probability_words, -1) << endl;
        while (while_ad == true){
            
            random_word = rand() % count_words;
            if (rand() % 100 <= 1 && probability_words[random_word] == -1) probability_words[random_word] = 1;
            else if (probability_words[random_word] == -1) probability_words[random_word] = 0;
            if (probability_words[random_word] > 0) break;
        }
        
        if (rand() % 2 == 0)
            probability_words[random_word] = zrada(ru_words[random_word], en_words[random_word], part_of_the_word[random_word],probability_words[random_word], subject_word[random_word], definition_word[random_word], status_word[random_word], transcription_word[random_word],"RUS"); // Русские слова
        else
            probability_words[random_word] = zrada(en_words[random_word], ru_words[random_word], part_of_the_word[random_word],probability_words[random_word], subject_word[random_word], definition_word[random_word], status_word[random_word], transcription_word[random_word],"ENG"); // Английские слова
  
   }
    return 0;
}