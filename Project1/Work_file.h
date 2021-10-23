#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>  // sort
#include <cstdio>
#include <cstdlib>
using namespace std;
string string_1251_to_utf_8(char* buf) {
    string rus_word = buf;
    //cout << rus_word.length() << endl;
    string rus,rus1;
    string output1 = "";
    string rus_B = "�����Ũ��������������������������";
    string rus_S = "��������������������������������";
    // A-А �-Б �- В �- Г �- Е �-Е �-Ё �- �- �- �- �- �- �- 
    //�- �- �- �- �- �- �- �- �- �- �- �- �- �- �- �- �- �-
    vector <string> rus_utf_8_B = {"А", "Б", "В","Г","Д","Е","Ё","Ж","З","И","Й","К","Л","М","Н","О","П","Р","С","Т","У","Ф","Х","Ц","Ч","Ш","Щ","Ъ","Ы","Ь","Э","Ю","Я"};
    vector <string> rus_utf_8_S = { "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я"};
  /*  int k = -1;
    for (int i = 0; i < rus_word.length(); i = i + 2)
    {
        rus = rus_word[i];
        rus1 = rus_word[i + 1];
        rus = rus + rus1;
        k++;
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);
      cout << rus << " == " << rus_utf_8_S[k] << endl;
        
    }*/
    for (int i = 0; i < rus_word.length(); i=i+2)
    {

        for (int j = 0; j < 33; j++)
        {

            rus = rus_word[i];
            if (rus == " ")
            {
                i--;
                output1 = output1 + " ";
                break;
            }
            else if (rus == "-")
            {
                i--;
                output1 = output1 + "-";
                break;
            }
            rus1=rus_word[i+1];
            rus = rus + rus1;
            if (rus == rus_utf_8_B[j])
            {
                output1 = output1 + rus_B[j];
                break;
            }
            else if (rus == rus_utf_8_S[j])
            {
                output1 = output1 + rus_S[j];
                break;
            }
        }
    }
    return output1;
}
int funk_true_word( int probability_words)
{
    if (probability_words == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void read_file(string file, vector<string>& en_word, vector<string>& ru_word, vector<string>& part_of_the_word, vector<int>& probability_words, int& count, vector<string>& subject_word, vector<string>& definition_word, vector<int>& status_word,vector<string>& transcription_word,vector<string>& ru_save_words)
{
    count = 0;
    string out_s;
    ifstream i(file);
    string fafa;

    char buf[1000]; // ������� char ������.
    for (; !i.eof(); count++)   {
        getline(i,out_s); // ����������� ������ �� ����� � string
        strcpy(buf, out_s.c_str()); // string ������ � char ������
        char* pch = strtok(buf, "/"); // ����������� ������ �����
        en_word.push_back(pch); // ������� ����� ������� ������� � ���� ���� �����
        pch = strtok(NULL, "/"); // ����������� ������ �����
        part_of_the_word.push_back(pch); // ������� ����� ������� ������� � ���� ���� �����
        pch = strtok(NULL, "/");
        transcription_word.push_back(pch);
        pch = strtok(NULL, "/"); // ����������� ������ �����
        subject_word.push_back(pch); // ������� ����� ������� ������� � ���� ���� �����
        pch = strtok(NULL, "/"); // ����������� ������ �����
        definition_word.push_back(pch); // ������� ����� ������� ������� � ���� ���� �����
        pch = strtok(NULL, "/"); // ����������� ������ �����, ������ ����� 
        string a = pch; // ���������� ����� � ������
        if (a != "-1" and a != "0" and a != "1" and a != "2" and a != "3")
        {
            setlocale(0, "");
            cout << "� ������ " << count + 1 << " ������� �������� ���������� ������. " << endl;
            cout << " �������� �� ���������� ��������:'-1','0','1','2','3'" << endl;
        }
        probability_words.push_back(atoi(a.c_str())); // ������� ����� ������� ������� � ���� ���� ���� ����� ������� ��������, ��� ��� �� �����, � �����
        pch = strtok(NULL, "/"); // ����������� ��������� ����� 
         // ������� ����� ������� ������� � ���� ���� �����
      //  cout << pch << endl;
        ru_save_words.push_back(pch);
        fafa = string_1251_to_utf_8(pch);
        ru_word.push_back(fafa);
        status_word.push_back(funk_true_word(probability_words[probability_words.size()-1]));

    }
    i.close();
}
void write_file(string file, vector<string>& en_word, vector<string>& ru_word, vector<string>& part_of_the_word, 
                vector<int>& probability_words, int& count, vector<string>& subject_word, vector<string>& definition_word, vector<string> transcription_word)
{
    int tmp;
    string tmp_word;
    string abc = "";
    // strcmp (a,b)
    for (int i = 0; i < en_word.size()-1; ++i) { // ������
        for (int j = i + 1; j < en_word.size(); ++j) { // ����
            if (probability_words[j] <probability_words[i]) { // j-� ������, ��� ���� �������� � i-� 
                //////////////////////////////
               tmp_word = en_word[i];
                en_word[i] = en_word[j];
                en_word[j] = tmp_word ;
                //////////////////////////////
                tmp_word = ru_word[i];
                ru_word[i] = ru_word[j];
                ru_word[j] = tmp_word ;
                //////////////////////////////
                tmp_word = part_of_the_word[i];
                part_of_the_word[i] = part_of_the_word[j];
                part_of_the_word[j] = tmp_word;
                //////////////////////////////
                tmp = probability_words[i];
                probability_words[i] = probability_words[j];
                probability_words[j] = tmp;
                //////////////////////////////
                tmp_word = subject_word[i];
                subject_word[i] = subject_word[j];
                subject_word[j] = tmp_word;
                //////////////////////////////
                tmp_word = definition_word[i];
                definition_word[i] = definition_word[j];
                definition_word[j] = tmp_word;
                //////////////////////////////
                tmp_word = transcription_word[i];
                transcription_word[i] = transcription_word[j];
                transcription_word[j] = tmp_word;
            }
        }
    }
    int zrada = 0;

    for (int k = -1; k <= 3; ++k)
    {
        for (int i = zrada; probability_words[i] == k and i<count-1; ++i) { // ������
            if (i +1 != count)
            for (int j = i + 1; probability_words[j] == k ; ++j) { // ����
                char a[90], b[90];
                strcpy(a, en_word[j].c_str());
                strcpy(b, en_word[i].c_str());
                if (strcmp(a, b) < 0) { // j-� ������, ��� ���� �������� � i-�
                    //////////////////////////////
                    tmp_word = en_word[i];
                    en_word[i] = en_word[j];
                    en_word[j] = tmp_word;
                    //////////////////////////////
                    tmp_word = ru_word[i];
                    ru_word[i] = ru_word[j];
                    ru_word[j] = tmp_word;
                    //////////////////////////////
                    tmp_word = part_of_the_word[i];
                    part_of_the_word[i] = part_of_the_word[j];
                    part_of_the_word[j] = tmp_word;
                    //////////////////////////////
                    tmp = probability_words[i];
                    probability_words[i] = probability_words[j];
                    probability_words[j] = tmp;
                    //////////////////////////////
                    tmp_word = subject_word[i];
                    subject_word[i] = subject_word[j];
                    subject_word[j] = tmp_word;
                    //////////////////////////////
                    tmp_word = definition_word[i];
                    definition_word[i] = definition_word[j];
                    definition_word[j] = tmp_word;
                    //////////////////////////////
                    tmp_word = transcription_word[i];
                    transcription_word[i] = transcription_word[j];
                    transcription_word[j] = tmp_word;
                }
                if (j + 1 == count) break;
            }
            zrada = i + 1;
        }
    }
   std::ofstream out(file);
    for (int i = 0; i < en_word.size();  i++)
    {
        if (i != (en_word.size() - 1))
            out <<
            en_word[i] + "/" + part_of_the_word[i] +"/"+ transcription_word[i] + "/" + subject_word[i] + "/" +
            definition_word[i] + "/" + to_string(probability_words[i]) + "/"
            + ru_word[i] << endl;
        else
            out <<
            en_word[i] + "/" + part_of_the_word[i] + "/" + transcription_word[i]+"/" + subject_word[i] + "/" +
            definition_word[i] + "/" + to_string(probability_words[i]) + "/"
            + ru_word[i];
}
    out.close();
    
}

#pragma once
