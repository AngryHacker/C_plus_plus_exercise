#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include "Menu.h"
#include "User.h"
using namespace std;
fstream inout;

//用于输出日期 
void printDate(Date date)
{
	cout<<left;
	cout<<date.getYear()<<'/'<<date.getMonth()<<'/'<<date.getDay()<<"-"<<date.getHour()<<'h';
}

//用于输出菜单 
void printMenu(Menu m)
{
	cout<<left;
	cout<<setw(20)<<m.getDishID()<<setw(20)<<m.getDishName()<<setw(20)<<m.getPrice()<<endl;
}


//用于输出订单 
void printOrder(Order myOrder)
{
	cout<<left;
	cout<<setw(7)<<myOrder.getDishID()<<setw(10)<<myOrder.getDishName()<<setw(6)<<myOrder.getPrice()<<setw(4)<<myOrder.getNum();
	cout<<setw(8)<<myOrder.getCustomerName()<<setw(8)<<myOrder.getPhone()<<setw(12)<<myOrder.getAdress();
	cout<<" ";printDate(myOrder.getBookDate());cout<<"  ";
	if(myOrder.getModify())
	{
		cout<<setw(10)<<"New"<<endl;
	}
	else cout<<setw(10)<<"Approved"<<endl;
}

//用于将菜单写入文件 
void outputMenu(Menu &iMenu)
{
	inout<<iMenu.getDishID()<<' '<<iMenu.getDishName()<<' '<<iMenu.getPrice()<<endl;
}

//用于将订单写入文件 
void outputOrder(Order &iOrder)
{
	Date date = iOrder.getBookDate();
	int modify = iOrder.getModify()? 1:0;
	inout<<iOrder.getDishID()<<' '<<iOrder.getDishName()<<' '<<iOrder.getPrice()<<' '<<iOrder.getNum()<<endl;
	inout<<iOrder.getCustomerName()<<' '<<iOrder.getAdress()<<' '<<iOrder.getPhone()<<endl;
	inout<<date.getYear()<<' '<<date.getMonth()<<' '<<date.getDay()<<' '<<date.getHour()<<' '<<modify<<endl;
}

Buyer::Buyer()
{
	name = "no";
	adress = "no"; 
	num = 0;
}

string Buyer::getName()
{
	return name;
}

//买家订菜 
void Buyer::bookOrder(vector<Menu>&myMenu,vector<Order>&order)
{
	int n,m = 0,i,year,month,day,hour,appNum = 0;
	string str;
	char ch;
	n = myMenu.size();
	num = myOrder.size();
	bool can = 1;
	//判断菜单是否为空 
	if(!n)
	{
		cout<<endl<<"Sorry! There is no dish for you to choose!"<<endl;
		return ;
	}
	cout<<left;
	cout<<endl<<"Here is the Menu :"<<endl;
	cout<<endl<<"        "<<setw(20)<<"DishID"<<setw(20)<<"DishName"<<setw(20)<<"Price"<<endl;
	for(i=0;i<n;++i)
	{
		cout<<"        ";
		printMenu(myMenu[i]);
	}
	//1为继续，2返回上一层 
	cout<<right;
	cout<<endl<<setw(30)<<"1.Continue"<<setw(20)<<"2.return"<<endl;
	while(cin>>str)
	{
		can = 1;
		if(str == "2") break;
		cout<<"Please input the dish ID : ";
		cin>>str;
	    for(i=0;i<n;++i)
	    {
		    if(myMenu[i].getDishID() == str)
			{
					myOrder.push_back(Order(myMenu[i],m));
					break;
			}
			//判断该编号是否存在 
			if(i == n-1)
			{
				cout<<endl<<"There is no such dish!"<<endl;
			    cout<<endl<<setw(30)<<"1.Continue"<<setw(20)<<"2.return"<<endl;
				can = 0;
			}

		}
		if(!can) continue;
		appNum ++;
		cout<<endl<<"Please input the count you want : ";
		cin>>m;
		myOrder[myOrder.size()-1].setnum(m);
		cout<<endl<<setw(30)<<"1.Continue"<<setw(20)<<"2.return"<<endl;
	}
	//判断有无新增菜单 
	if(appNum == 0)
	{
		cout<<endl<<"You haven't ordered anything!"<<endl;
		return;
	}
	//输出所有用户已预定的菜 
	cout<<left;
	cout<<endl<<"Here is the dish you have ordered:"<<endl;
	cout<<endl<<setw(20)<<"DishID"<<setw(20)<<"DishName"<<setw(20)<<"Price"<<endl;
	for(i=0;i<myOrder.size();++i)
	{
		printMenu(myOrder[i]);
	}
	//判断此时买家是否为匿名状态，是则跳过输入姓名，地址，电话 
	if(name == "no"||adress == "no")
	{
	    cout<<endl<<"Please input your name : ";
	    cin>>name;
	    cout<<endl<<"Please input your address : ";
	    cin>>adress;
	    cout<<endl<<"Please input your phone : ";
	    cin>>phone;
	}
	cout<<endl<<"Please input the date you want to have you dish,"<<endl;
	cout<<"just as 2013/5/2 14 (year/month/day hour) : "<<endl;
	cin>>year>>ch>>month>>ch>>day>>hour;
	bookDate.setYear(year);
	bookDate.setMonth(month);
	bookDate.setDay(day);
	bookDate.setHour(hour);
	for(int i=num;i<myOrder.size();++i){
		myOrder[i].setCustomerName(name);
		myOrder[i].setAdress(adress);
		myOrder[i].setPhone(phone);
		myOrder[i].setBookDate(bookDate);
	}
	inout.open("order.txt",ios::app);
	if(inout.fail())
	{
		cout<<endl<<"The system can't find the file!"<<endl;
		return;
	}
	for(i=num;i<myOrder.size();++i)
	{
		outputOrder(myOrder[i]);
	}
	inout.close();
	num = myOrder.size();
}

//买家查询订单 
void Buyer::inquireOrder(vector<Order>&order)
{
     //名字是否为空 
	if(name == "no"){
	    cout<<endl<<"please input your name : ";
	    cin>>name;
	}
	myOrder.clear();
	for(int i=0;i<order.size();++i)
	{
		if(order[i].getCustomerName() == name)
		{
			myOrder.push_back(order[i]);
		}
	}
	num = myOrder.size();
	if(num == 0)
	{
		cout<<endl<<"You haven't ordered any dish!"<<endl;
		return;
	}
	cout<<left;
	cout<<endl<<"Here is the dishes you have ordered :"<<endl; 
	cout<<endl<<setw(7)<<"DishID"<<setw(10)<<"DishName"<<setw(6)<<"price"<<setw(4)<<"num"<<setw(8)<<"Name";
	cout<<setw(8)<<"Phone"<<setw(12)<<"Address"<<setw(15)<<"Date"<<setw(10)<<"state"<<endl;
	for(int i=0;i<num;++i){
		printOrder(myOrder[i]);
	}
	return;
}

//买家取消订单 
void Buyer::modifyOrder(vector<Order>&order)
{
	num = myOrder.size();
	if(num == 0)
	{
		cout<<endl<<"You haven't ordered any dish!"<<endl;
		return ;
	}
	//输出买家自已的所有订单 
	cout<<left;
	cout<<endl<<"The dish you have ordered is :"<<endl;
	cout<<endl<<setw(7)<<"DishID"<<setw(10)<<"DishName"<<setw(6)<<"price"<<setw(4)<<"num"<<setw(8)<<"Name";
	cout<<setw(8)<<"Phone"<<setw(12)<<"Address"<<setw(15)<<"Date"<<setw(10)<<"state"<<endl;
	for(int i=0;i<num;++i)
	{
		printOrder(myOrder[i]);
	}
	//选择1-继续或2-返回上一层 
	cout<<right;
	cout<<endl<<setw(30)<<"1.Continue"<<setw(20)<<"2.return"<<endl;
	string str;
	int pos = -1,n=0;
	Order iOrder;
	int *cancleDish = new int[num+1],*cancle = new int[order.size()];
	memset(cancleDish,0,4*(num+1));
	memset(cancle,0,4*(order.size()));
	while(cin>>str)
	{
		if(str == "2") break;
		//判断无效输入 
		if(str != "1"){
			cout<<endl<<"Invalid input!"<<endl;
			cout<<endl<<setw(30)<<"1.Continue"<<setw(20)<<"2.return"<<endl;
			continue;
		}
		cout<<endl<<"Please input the dishID : ";
		cin>>str;
		for(int i=0;i<num;++i)
		{
			if(myOrder[i].getDishID() == str)
			{
                //该订单是否已确认 
				if(myOrder[i].getModify()){
					cout<<endl<<"The order have been canceled!"<<endl;
				    pos = i;
				    break;
				}
				else{
					cout<<endl<<"The order have been approved! You can't cancel it !"<<endl;
					pos = -2;
					break;
				}
			}
		}
		//查看该买家想取消的编号是否存在 
		if(pos < 0){
			if(pos == -1)
			   cout<<endl<<"There is no such dish you have ordered!"<<endl;
		}
		else{
			cancleDish[pos] = 1;
			n++;
		}
		pos = -1;
		cout<<right;
		cout<<endl<<setw(30)<<"1.Continue"<<setw(20)<<"2.return"<<endl;
	}
	//将更新的订单写入文件 
	inout.open("order.txt",ios::out);
	if(inout.fail())
	{
		cout<<endl<<"The system can't find the file!"<<endl;
		delete cancleDish;delete cancle;
		return;
	}
	for(int i=0;i<num;++i)
	{
		if(cancleDish[i]){
			for(int j=0;j<order.size();++j)
			{
				if(order[j] == myOrder[i])
				{
					cancle[j] = 1;
					break;
				}
			}
		}
	}
	for(int i=0;i<order.size();++i)
	{
		if(cancle[i]){
			continue;
		}
		outputOrder(order[i]);
	}
	inout.close();
	num -= n;
	delete cancleDish;delete cancle;
}

int Buyer::getNum()
{
	return num;
}

Seller::Seller()
{
	password = "888888";
}

void Seller::appendMenu(vector<Menu>&myMenu)
{
	cout<<endl<<"Do you want to append Menu?  Y/N"<<endl;
	string ch;
	int k = myMenu.size();
	while(cin>>ch)
	{
        //判断无效输入 
	    if(ch != "Y" && ch != "y") break;
	    cout<<endl<<"please input the dish name : ";
	    string str;
	    Menu iMenu;
	    double d;
	    cin>>str;
	    iMenu.setDishName(str);
	    cout<<endl<<"Please input the dish ID : ";
	    cin>>str;
	    iMenu.setDishID(str);
	    cout<<endl<<"Please input the price of the dish : ";
	    cin>>d;
	    iMenu.setPrice(d);
	    myMenu.push_back(iMenu);
		cout<<endl<<"The dish have been added to the menu!"<<endl;
		cout<<endl<<"Do you want to continue to append Menu? Y/N"<<endl;
	}
	//将新增菜单写入文件 
	inout.open("menu.txt",ios::app);
	if(inout.fail())
	{
		cout<<endl<<"The system can't find the file!"<<endl;
		return;
	}
	for(int i=k;i<myMenu.size();++i)
	{
		outputMenu(myMenu[i]);
	}
	inout.close();
	return;
}

void Seller::cancelMenu(vector<Menu>&myMenu)
{
	cout<<endl<<"Do you want to cancel Menu? Y/N"<<endl;
	string str;
	string ch;
	Menu iMenu;
	vector<Menu>::iterator it = myMenu.begin();
	while(cin>>ch)
	{
		it = myMenu.begin();
		if(ch == "N" || ch == "n") break;
		//判断无效输入 
		if(ch != "Y" && ch != "y")
		{
			cout<<endl<<"Invalid input!Please input again!"<<endl;
			cout<<endl<<"Do you want to cancel Menu? Y/N"<<endl;
			continue;
		}
		//输出所有菜单 
		cout<<left;
	    cout<<endl<<"Here is the Menu :"<<endl;
	    cout<<endl<<"        "<<setw(20)<<"DishID"<<setw(20)<<"DishName"<<setw(20)<<"Price"<<endl;
	    for(int i=0;i<myMenu.size();++i)
	    {
		    cout<<"        ";
		    printMenu(myMenu[i]);
	    }
		cout<<endl<<"Please input the dish ID you want cancel : ";
		cin>>str;
		for(int i=0;i<myMenu.size();++i)
		{
			if(myMenu[i].getDishID() == str)
			{
				myMenu.erase(it+i);
				cout<<endl<<"The dish have been canceled!"<<endl;
				break;
			}
			//找不到该编号 
			if(i == myMenu.size()-1)
			{
				cout<<endl<<"There is no such dish!Please input again!"<<endl;
			}
		}
		cout<<endl<<"Do you want to continue to cancel Menu? Y/N"<<endl;
	}
	//将修改后菜单写入文件 
	inout.open("menu.txt",ios::out);
	if(inout.fail())
	{
		cout<<endl<<"The system can't find the file!"<<endl;
		return;
	}
	for(int i=0;i<myMenu.size();++i)
	{
		outputMenu(myMenu[i]);
	}
	inout.close();
}

//卖家查询订单 
void Seller::inquireOrder(vector<Order>&order)
{
     //没有订单则输出提示并返回上一层 
	if(order.size() == 0)
	{
		cout<<endl<<"There is no any order!"<<endl;
		return ;
	}
	cout<<left;
	cout<<endl<<"Here is the order :"<<endl;
	cout<<endl<<setw(7)<<"DishID"<<setw(10)<<"DishName"<<setw(6)<<"price"<<setw(4)<<"num"<<setw(8)<<"Name";
	cout<<setw(8)<<"Phone"<<setw(12)<<"Address"<<setw(15)<<"Date"<<setw(10)<<"state"<<endl;
	for(int i=0;i<order.size();++i)
	{
		printOrder(order[i]);
	}
	return;
}

//卖家确认订单 
void Seller::modifyOrder(vector<Order>&order)
{
	int *pos = new int[order.size()+1],count = 0;
	memset(pos,0,sizeof(pos));
	for(int i=0;i<order.size();++i)
	{
		if(order[i].getModify())
		{
			count++;
			pos[i] = 1;
		}
	}
	//没有未确认订单则提示后返回上一层 
	if(count == 0)
	{
		cout<<endl<<"All order have been approved!"<<endl;
		return ;
	}
	cout<<left;
	cout<<endl<<"Here is the order you haven't approve : "<<endl;
	cout<<endl<<setw(7)<<"DishID"<<setw(10)<<"DishName"<<setw(6)<<"price"<<setw(4)<<"num"<<setw(8)<<"Name";
	cout<<setw(8)<<"Phone"<<setw(12)<<"Address"<<setw(15)<<"Date"<<setw(10)<<"state"<<endl;
	count = 0;
	for(int i=0;i<order.size();++i)
	{
		if(pos[i]&&order[i].getModify())
		{
			count++;
			cout<<count<<endl;
			printOrder(order[i]);
		}
	}
	//卖家可选择 1-全部确认 或 2-逐个确认 或 3-返回 
	cout<<right;
	cout<<endl<<setw(20)<<"1.Aprove all"<<setw(25)<<"2.Aprove one by one"<<setw(20)<<"3.return"<<endl;
	string n;
	while(cin>>n)
	{
		if(n == "1" || n == "2" || n == "3") break;
		else{
			cout<<endl<<"Invalid input!"<<endl;
			cout<<endl<<setw(20)<<"1.Aprove all"<<setw(25)<<"2.Aprove one by one"<<setw(20)<<"3.return"<<endl;
		}
	}
	if( n == "3") return;
	if(n == "1")
	{
		for(int i=0;i<order.size();++i)
		{
			if(pos[i])
				order[i].setModify();
		}
	}
	else
	{
		cout<<right;
		cout<<endl<<setw(30)<<"1.Continue"<<setw(20)<<"2.return"<<endl;
	    int k,m;
		while(cin>>m)
		{
			if(m == 2) return;
			if(m != 1){
				cout<<endl<<"Invalid input!"<<endl;
				return ;
			}
			cout<<endl<<"Please input the number of order:";
			cin>>m;
			//检验输入正确性 
			if( m > count)
			{
				cout<<endl<<"There is only "<<count<<" order!"<<endl;
				cout<<endl<<"Please input again!"<<endl;
			}
			else if( m <= 0)
			{
				cout<<endl<<"The number must be positive !"<<endl;
			}
			else
			{
				k = 0;
				for(int i=0;i<order.size();++i)
				{
					if(pos[i])
					{
						k++;
						if(k == m)
						{
							order[i].setModify();
							cout<<endl<<"The order have approved!"<<endl;
						}
					}
				}
			}
			cout<<right;
			cout<<endl<<setw(30)<<"1.Continue"<<setw(20)<<"2.return"<<endl;
		}
	}
	//将修改后的订单写入文件 
	inout.open("order.txt",ios::out);
	if(inout.fail())
	{
		cout<<endl<<"The system can't find the file!"<<endl;
		return;
	}
	for(int i=0;i<order.size();++i)
	{
		outputOrder(order[i]);
	}
	inout.close();

}

void Seller::setPassword(string p)
{
	password = p;
}

string Seller::getPassword()
{
	return password;
}
