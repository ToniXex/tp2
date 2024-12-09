#include "order.h"
#include <iostream>
#include <windows.h>

int main() {
	order* orders;
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int newPaymentAccountPayer;
	int newPaymentAccountRecipient;
	int newSum;
	int number;
	
	while (1) {
		std::cout << "1 - добавить order\n";
		std::cout << "2 - вывести список orders\n";

		std::cin >> number;
		switch (number)
		{
		case 1:
		std::cout << "1 - добавить order\n";
		std::cout << "2 - вывести список orders\n";
		std::cout << "3 - вывести снятую сумму со счета определенного платильщика\n";

		std::cin >> number;
		switch (number) {
		case 1:
			std::cout << "введите расчетный счет платильщика\n";
			std::cin >> newPaymentAccountPayer;
			std::cout << "введите расчетный счет получателя\n";
			std::cin >> newPaymentAccountRecipient;
			std::cout << "перечисляемая сумма в рублях\n";
			std::cin >> newSum;
			order* newOrders = new order[sizeof(orders) + 1];

			for (int i = 0; i < sizeof(orders) + 1; i++) {
				newOrders[i] =  orders[i];
			}
			order tempOld;
			order temp(newPaymentAccountPayer,newPaymentAccountRecipient,newSum);
			int fl = 1;

			for(int i = 0; i < sizeof(newOrders); i++){
				if(fl){
					if(newOrders[i].getPaynemtAccountPayer() >= newPaymentAccountPayer ){
						tempOld = newOrders[i];
						newOrders[i] = temp;
						temp = tempOld;
						fl = 0;
					}
				}
				else{
					tempOld = newOrders[i];
					newOrders[i] = temp;
					temp = tempOld;
				}
			}
			delete[] orders;
			orders = newOrders;
			break;
		case 2:
			std::cout << "список:\n"
			for(int i  = 0; i < sizeof(orders)){
				orders[i].print();
			}
			break;
			case 3:
			int PaymentAccountPayer;
			std::cout << "введите номер расчетного счета платильщика: "
			std:: cin >> PaymentAccountPayer;
			for(int i = 0; i < sizeof(orders); i++){
				if(orders[i].getPaynemtAccountPayer == PaymentAccountPayer ){
					orders[i].print();
					break;
				}
			}
			std::cout << "Такого рачетного счета нет";
			break;
	}
	break;
	case 2:
	
		}
		
	}

}