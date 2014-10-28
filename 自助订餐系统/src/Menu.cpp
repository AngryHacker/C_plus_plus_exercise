#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include "Menu.h"
using namespace std;

Date::Date(int y ,int m ,int d ,int h )
{
	year = y;
	month = m;
	day = d;
	hour = h;
}

Date::Date()
{
	year = 2012;
	month = 12;
	day = 12;
	hour = 12;
}

bool Date::operator==(Date date2)
{
	if(date2.year == year && date2.month == month && date2.day == day && date2.hour == hour) return true;
	return false;
}

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

int Date::getHour()
{
	return hour;
}

void Date::setYear(int y)
{
	year = y;
}

void Date::setMonth(int m)
{
	month = m;
}

void Date::setDay(int d)
{
	day = d;
}

void Date::setHour(int h)
{
	hour = h;
}

Menu::Menu()
{
}

Menu::Menu(string dishName,string dishID,double price)
{
		this->dishName = dishName;
		this->dishID = dishID;
		this->price = price;
}

void Menu::setDishName(string name)
{
	dishName = name;
}

void Menu::setDishID(string ID)
{
	dishID = ID;
}

void Menu::setPrice(double p)
{
	price = p;
}

string Menu::getDishName()
{
	return dishName;
}

string Menu::getDishID()
{
	return dishID;
}

double Menu::getPrice()
{
	return price;
}


Order::Order()
{
	modify = 1;
}

Order::Order(string dishName,string dishID,double price,string customerName,string adress,string phone,Date date):Menu(dishName,dishID,price),bookDate(date)
{
	this->customerName = customerName;
	this->adress = adress;
	this->phone = phone;
	modify = 1;
}

Order::Order(string dishName,string dishID,double price): Menu(dishName,dishID,price)
{
	modify = 1;
}

Order::Order(Menu m,int n):Menu(m),num(n)
{
	modify = 1;
};

const bool Order::operator==(Order order2)
{
	if(order2.dishID != dishID) return false;
	if(order2.dishName != dishName) return false;
	if(order2.customerName != customerName) return false;
	if(order2.phone != phone) return false;
	if(order2.adress != adress ) return false;
	if(!(order2.bookDate == bookDate)) return false;
	return true;
}

string Order::getCustomerName()
{
	return customerName;
}

string Order::getAdress()
{
	return adress;
}

string Order::getPhone(){
	return phone;
}

Date Order::getBookDate()
{
	return bookDate;
}

bool Order::getModify()
{
	return modify;
}

int Order::getNum()
{
	return num;
}

bool Order::setCustomerName(string customerName)
{
	if(!modify) return false;
	this->customerName = customerName;
	return true;
}

bool Order::setAdress(string adress)
{
	if(!modify) return false;
	this->adress = adress;
	return true;
}

bool Order::setPhone(string phone)
{
	if(!modify) return false;
	this->phone = phone;
	return true;
}

void Order::setModify()
{
	modify = 0;
}

bool Order::setBookDate(Date bookDate)
{
	if(!modify) return false;
	this->bookDate = bookDate;
	return true;
}

bool Order::setnum(int num)
{
	if(!modify) return false;
	this->num = num;
	return true;
}