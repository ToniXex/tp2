#include "order.h"
#include <iostream>

order::order()
{
	this->paymentAccountPayer = 0;
	this->paymentAccountRecipient = 0;
	this->sum = 0;
}

order::order(int paymentAccountPayer, int paymentAccountRecipient, int sum)
{
	this->paymentAccountPayer = paymentAccountPayer;
	this->paymentAccountRecipient = paymentAccountRecipient;
	this->sum = sum;
}

order::order(order& copy)
{
	this->paymentAccountPayer = copy.paymentAccountPayer;
	this->paymentAccountRecipient = copy.paymentAccountRecipient;
	this->sum = copy.sum;
}

int order::getPaynemtAccountPayer()
{
	return this->paymentAccountPayer;
}

int order::getPaynemtAccountRecipient()
{
	return this->paymentAccountRecipient;
}

int order::setSum()
{
	return this->sum;
}

void order::setPaynemtAccountPayer(int newPaynemtAccountPayer)
{
	this->paymentAccountPayer = newPaynemtAccountPayer;
}

void order::setPaynemtAccountRecipient(int newPaynemtAccountRecipient)
{
	this->paymentAccountRecipient = newPaynemtAccountRecipient;
}

void order::setSum(int newSum)
{
	this->sum = newSum;
}

void order:: print()
{
	std::cout << "расчетный счет платильщика: " << this->paymentAccountPayer << "\n";
	std::cout << "расчетный счет получателя: " << this->paymentAccountRecipient << "\n";
	std::cout << "сумма платежа в рублях: " << this->sum << "\n";
}