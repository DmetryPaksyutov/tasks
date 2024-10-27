﻿/*Задача D. RACI
Имя входного файла: стандартный ввод
Имя выходного файла: стандартный вывод
Ограничение по времени: 2 секунды
Ограничение по памяти: 512 мебибайт
Николай на лекциях по менеджменту дал студентам задание составить для проекта матрицу
RACI. Это матрица распределения ответственности, в которой перечислены все заинтересованные
стороны проекта и уровни их вовлечённости в отдельные задачи. Уровни обозначаются буквами
«R», «A», «C» и «I». При отсутствии вовлечённости используется «-». Уровни вовлечённости имеют
следующее значение:
• R (Responsible): выполняет задачу (если таких нет, то Accountable выполняет задачу самостоятельно)
• A (Accountable): принимает задачу у Responsible; для каждой задачи должен быть ровно один
экземпляр этого уровня вовлечённости — в отличие от остальных уровней, которых может быть
сколько угодно
• C (Consulted): консультирует в процессе выполнения задачи
• I (Informed): получает информацию о ходе выполнения задачи
Помогите студентам проверить корректность заполнения матрицы.
Формат входных данных
Первая строка содержит два целых числа n и m — число строк и столбцов матрицы RACI
(1 ⩽ n, m ⩽ 100).
Далее следуют n строк, каждая из которых содержит по m элементов, разделённых пробелами.
Каждая строка соответствует задаче, а каждый столбец — заинтересованной стороне.
Каждый элемент матрицы — либо заглавная английская буква «R», «A», «C» или «I», либо минус
«-», означающий, что данная заинтересованная сторона по этой задаче не имеет никакого уровня
вовлечённости.
Формат выходных данных
Выведите «Yes», если матрица корректна, или «No» иначе. Регистр букв не важен.*/


using namespace std;

#include <iostream>
#include <map>

int main()
{
    int a, b;
    char mat[100][100];
    cin >> a >> b;
    bool f = false;
    for (int i = 0; i < a; i++) {

        for (int j = 0; j < b; j++) {
            char c;
            cin >> c;
            mat[i][j] = tolower(c);
        }
        
    }

    for (int i = 0; i < a; i++) {

        map<char, bool> fs;
        fs['a'] = false;
        fs['r'] = false;
        fs['i'] = false;
        fs['c'] = false;

        for (int j = 0; j < b; j++) {
            if (mat[i][j] == 'a' && fs['a'] == true) {
                f = true;
                break;
            }
            else {
                fs[mat[i][j]] = true;
            }
        }

        //cout << f << " " << fs['a'] << " " << fs['i'] << " " << fs['c'] << "\n";

        if (f || !fs['a'] ) {
            f = true;
            break;
        }
    }

    if (f) cout << "No";
    else cout << "Yes";
}

