#include "order.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size = 0;
    order* orders = nullptr; 
    int newPaymentAccountPayer;
    int newPaymentAccountRecipient;
    int newSum;
    int number;
    order tempOld;
    order temp;
    order* newOrders;

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

                    // Вставляем новый элемент в нужную позицию
                    newOrders[position] = temp;

                    // Копируем оставшиеся элементы
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
                    return 0;
                }
            }
        case 3:
            delete[] orders; 
            return 0;
        }
    }
}
