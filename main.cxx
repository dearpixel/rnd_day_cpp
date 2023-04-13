/*
   TODO
   + Чтение файлов
   + Запись файлов
   + Настройка генератора простым txt файлом
   + Генерация плана на день
   - Докинуть сюда же тот самый todo файл чтобы из него и брать случайную задачу
 */
#include "dpcalls.h"

vector<string> plan = ReadAllLines("source.txt");

int main() {
  dpInit();
  for (int i = 0; i < plan.size()-1; i++)
    cout << words(plan[i])[0] << " " << replace(words(plan[i])[rnd(1,words(plan[i]).size())], "_", " ") << endl;
}