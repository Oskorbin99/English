#include <iostream>
#include "Other_1.h"
#include "Change_keyboard.h"
string Equalize_word_complement(string word, string word_B, string word_S, int count_al) // Делает чудо с БОЛЬШИМИ и маленькими буквами
{
    for (int i = 0; i < count_al; i++) {
        if (word[0] == word_B[i]) break;
        else if (word[0] == word_S[i]) {
            word[0] = word_B[i];
            break;
        }
    }

    for (int i = 1; i < size(word); i++) {
        for (int j = 0; j < count_al; j++) {
            if (word[i] == word_S[j]) break;
            else if (word[i] == word_B[j]) {
                word[i] = word_S[j];
                break;
            }
        }
    }
    return word;
}
string Equalize_word_o(string word, string Keyboard_layout)
{
    const int eng = 26;
    string eng_B = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string eng_S = "abcdefghijklmnopqrstuvwxyz";
    const int rus = 33;
    string rus_B = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string rus_S = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    if (Keyboard_layout == "ENG") {
            return Equalize_word_complement(word, eng_B, eng_S, eng);
    }
    else  if (Keyboard_layout == "RUS") {
        return Equalize_word_complement(word, rus_B, rus_S, rus);
    }
}
int count_new_words(vector<int>& probability_words, int b)
{
    int a = 0;
    for (int i=0; i<size(probability_words);i++)
    {
        if (probability_words[i] >0 && b == 3)
        a++;
        else if (probability_words[i] == 0 && b == 0)
        {a++; }
        else if (probability_words[i] == -1 && b == -1)
        {
            a++;
        }
    }
    return a;
}
int zrada(string a, string b, string part_of_the_word, int c, string subject_word, string definition_word, int status_word,string transcription_word,string Keyboard_layout) {
    string enter_words;
    if (Keyboard_layout == "ENG") Lang.set(sLang::ENG);
    else if (Keyboard_layout == "RUS") Lang.set(sLang::RUS);
    // Кодировка на этой строке - 1251
    cout << "Количество хп слова = " << c << endl;
    cout << "Перевод слова: ";
    if (Keyboard_layout == "RUS")
    {
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    }
    cout << b << endl;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Часть слова: ";
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout << part_of_the_word << endl;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
        if (Keyboard_layout == "RUS")
    {
            cout << "Транскрипция: ";
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

        cout << "[" + transcription_word + "]" << endl;
    }
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Тема: ";
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout << subject_word << endl;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    getline(cin,enter_words);
    enter_words = Equalize_word_o(enter_words, Keyboard_layout);
    if (enter_words != a) {
     if (c < 3)   c += 1;
     if (Keyboard_layout == "RUS")
     {
         SetConsoleOutputCP(1251);
         SetConsoleCP(1251);
         cout << "Дефиниция: ";
         cout<< definition_word << endl;
         SetConsoleOutputCP(1251);
         SetConsoleCP(1251);
         cout << "Ошибка. Попробуйте еще раз: " << endl;
         getline(cin, enter_words);
     }
        if (enter_words == a)
        {
            system("cls");
            c -= 1;
        }
        else
        {
            status_word = 0;
            system("cls");
            SetConsoleOutputCP(1251);
            SetConsoleCP(1251);
            cout << "Неправильно.\nОтвет: ";
            SetConsoleOutputCP(1251);
            SetConsoleCP(CP_UTF8);
            cout<< a << " = " << b << endl;
            cout << "Транскрипция: ";
            SetConsoleOutputCP(CP_UTF8);
            SetConsoleCP(CP_UTF8);
            cout << "[" + transcription_word + "]" << endl;
            cout << "----------------------------------------" << endl;
            SetConsoleOutputCP(1251);
            SetConsoleCP(1251);

        }
    }
    else {
        system("cls");
        c -= 1;
    }
    return c;
}
#pragma once
