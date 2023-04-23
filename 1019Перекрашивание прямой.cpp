#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>


int b[20], p, s, n;

std::string str;
int main() {
    std::string sep = "+------------------------------+--------+-------------+";
    std::cout << sep << std::endl;
    std::cout << "|Contest name                  |Date    |ABCDEFGHIJKLM|\n";
    std::cout << sep << std::endl;

    std::cin >> n;

    for (int t = 1; t <= n; t++)
    {
        //название
        getline(std::cin, str);
        std::cout << "|";
        std::cout << str;
        for (int i = 1; i <= 30 - str.length(); i++)
            std::cout << ' ';

        //дата
        getline(std::cin, str);
        std::cout << '|' << str << '|';

        //ввод количества задач, и количества отправок
        std::cin >> p >> s;
        memset(b, 0, sizeof(b));

        for (int i = 1; i <= s; i++) {
            char ch;
            //название задачи(A,B...)
            std::cin >> ch;
            int j = int(ch - 'A');
            //результат проверки
            getline(std::cin, str);
            if (str == "Accepted")
                b[j] = 1;
            else if (b[j] == 0)
                b[j] = -1;
        }

        for (int i = 0; i < 13; i++) {
            if (i > p - 1)
                std::cout << ' ';
            else if (b[i] == 0)
                std::cout << '.';
            else if (b[i] == -1)
                std::cout << 'x';
            else
                std::cout << 'o';
        }
        std::cout << '|' << std::endl;
        std::cout << sep << std::endl;
    }
    return 0;
}