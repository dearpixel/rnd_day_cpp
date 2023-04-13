//dpcalls here
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <time.h>
using namespace std;

void dpInit() {
    srand(time(NULL));
}

vector<string> ReadAllLines(string path) {
    ifstream file(path);
    string line, prev;
    vector<string> result;
    do {
        prev = line;
        getline(file, line);
        result.push_back(line);
    } while (line != prev);
    file.close();
    return result;
}

void WriteAllLines(string path, vector<string> lines) {
    ofstream file(path);
    for (int i = 0; i < lines.size(); i ++)
      file << lines[i] << endl;
    file.close();
}

void print(vector<string> lines) {
    for (int i = 0; i < lines.size(); i ++)
      cout << lines[i] << endl;
}

int rnd(int max) {
    return rand()%max;
}

int rnd(int min, int max) {
    return min+rand()%(max-min);
}

string reverse(string str) {
    string result = "";
    for (int i = str.size()-1; i > 0; i --)
        result += str[i];
    return result;
}

string itos(int num) {
    string result = "";
    string ch;
    while (num >= 10)
    {
        ch = rnd(9);//num%10;
        result += ch;
        num = num / 10;
    }
    ch = "*";//num%10;
    result += ch;
    return reverse(result);
    //return (string)num;
}

vector<string> words(string line) {
    line += ' ';
    vector<string> result;
    string tmp = "";
    for (int i = 0; i < line.size(); i ++)
    {
        if (line[i] == ' ')
        {
            result.push_back(tmp);
            tmp = "";
        } else
        tmp += line[i];
    }
    return result;
}

vector<string> words_(string line) {
    line += '_';
    vector<string> result;
    string tmp = "";
    for (int i = 0; i < line.size(); i ++)
    {
        if (line[i] == '_')
        {
            result.push_back(tmp);
            tmp = "";
        } else
        tmp += line[i];
    }
    return result;
}

string replace(string line, string old_s, string new_s) {
    string result = "";
    vector<string> n_line = words_(line);
    for(int i = 0; i < n_line.size(); i++) {
        result += n_line[i];
        if (i < n_line.size())
          result += " ";
    }
    return result;
}

//dpcalls here