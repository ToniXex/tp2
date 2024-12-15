#include "order.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>  

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::fstream fin("hello.txt");

    std::string strh;
    std::string str;

    while (!fin.eof()) {
        getline(fin, strh);
        str += strh;
    }
    

    int size = 0;
    order* orders = nullptr; 
    int newPaymentAccountPayer;
    int newPaymentAccountRecipient;
    int newSum;
    int number;
    order tempOld;
    order temp;
    order* newOrders;
    std::string maxline = "";
    int maxP = 0;
    std::string templine = "";
    int maxPtemp = 0;
    std::string end = ".?!";
    std::string punk = ",;:-()";
    int fl = 1;

    while (true) {
        std::cout << "1 - первое задание\n";
        std::cout << "2 - второе задание\n";
        std::cout << "3 - выход\n";

        std::cin >> number;
        switch (number) {
        case 1:
            while (true) {
                std::cout << "1 - добавить order\n";
                std::cout << "2 - вывести список orders\n";
                std::cout << "3 - вывести снятую сумму со счета определенного платильщика\n";
                std::cout << "4 - выход\n";

                std::cin >> number;
                switch (number) {
                case 1: {
                    size++;
                    std::cout << "Введите расчетный счет платильщика: ";
                    std::cin >> newPaymentAccountPayer;
                    temp.setPaynemtAccountPayer(newPaymentAccountPayer);

                    std::cout << "Введите расчетный счет получателя: ";
                    std::cin >> newPaymentAccountRecipient;
                    temp.setPaynemtAccountRecipient(newPaymentAccountRecipient);

                    std::cout << "Перечисляемая сумма в рублях: ";
                    std::cin >> newSum;
                    temp.setSum(newSum);

                    newOrders = new order[size];
                    int position = 0;
                    while (position < size - 1 && orders[position].getPaynemtAccountPayer() < temp.getPaynemtAccountPayer()) {
                        newOrders[position] = orders[position];
                        position++;
                    }

                    newOrders[position] = temp;

                    for (int i = position; i < size - 1; i++) {
                        newOrders[i + 1] = orders[i];
                    }


                    delete[] orders;
                     
                    orders = newOrders;

                    break;
                }
                case 2: {
                    std::cout << "Список orders:\n";
                    for (int i = 0; i < size; i++) {
                        orders[i].print();
                    }
                    break;
                }
                case 3: {
                    int PaymentAccountPayer;
                    std::cout << "Введите номер расчетного счета плательщика: ";
                    std::cin >> PaymentAccountPayer;

                    bool found = false;
                    for (int i = 0; i < size; i++) {
                        if (orders[i].getPaynemtAccountPayer() == PaymentAccountPayer) {
                            orders[i].print();
                            found = true;
                        }
                    }

                    if (!found) {
                        std::cout << "Такого расчетного счета нет\n";
                    }

                    break;
                }
                case 4:
                    delete[] orders;
                    return 0;
                }
            }
        case 2:
            for (int i = 0; i < str.length(); i++) {
                if (end.find(str[i]) != std::string::npos) {
                    templine += str[i];
                    if (maxPtemp > maxP) {
                        maxline = templine;
                        maxP = maxPtemp;
                    }
                    else if (maxPtemp == maxP) {
                        maxline += templine;
                        
                    }
                    maxPtemp = 0;
                    templine = "";
                }
                else if (punk.find(str[i]) != std::string::npos) {
                    maxPtemp++;
                    templine += str[i];
                }
                else {
                    templine += str[i];
                }
                
            }
            if (maxPtemp > maxP) {
                maxline = templine;
                maxP = maxPtemp;
                templine = "";
            }
            else if (maxPtemp == maxP) {
                maxline += templine;
            }
            std::cout << maxline;
        case 3:
            return 0;
        }
    }
}
