#pragma once
class order {
private:
	int paymentAccountPayer;
	int paymentAccountRecipient;
	int sum;
public:
	order();
	order(int paymentAccountPayer, int paymentAccountRecipient, int sum);
	order(order& copy);
	int getPaynemtAccountPayer(); 
	int getPaynemtAccountRecipient();
	int setSum();
	void setPaynemtAccountPayer(int newPaynemtAccountPayer);
	void setPaynemtAccountRecipient(int newPaynemtAccountRecipient);
	void setSum(int newSum);
	void print();
};