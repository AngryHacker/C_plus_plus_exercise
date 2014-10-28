#include"Menu.h"
#include<vector>

#ifndef USER_H
#define USER_H
class User{
private:

public:
	virtual void modifyOrder(vector<Order>&)=0;
	virtual void inquireOrder(vector<Order>&)=0;
};
#endif

//卖家有密码成员变量 
#ifndef SELLER_H
#define SELLER_H
class Seller:public User{
private:
	string password;
public:
	Seller();
	void modifyOrder(vector<Order>&);
	void inquireOrder(vector<Order>&);
	void appendMenu(vector<Menu>&);
	void cancelMenu(vector<Menu>&);
	void setPassword(string);
	string getPassword();
};
#endif

//买家有名字、地址、电话、订单日期、自己的订单数量 和一个 vector<Order>类型的用于存储买家自己的所有订单 
#ifndef BUYER_H
#define BUYER_H
class Buyer:public User{
private:
	vector<Order>myOrder;
	string name,adress,phone;
	Date bookDate;
	int num;
public:
	Buyer();
	void bookOrder(vector<Menu>&,vector<Order>&);
	void modifyOrder(vector<Order>&);
	void inquireOrder(vector<Order>&);
	int getNum();
	string getName();
	void setNum(int);
};
#endif
