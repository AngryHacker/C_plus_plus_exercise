#include <iostream>
#include <iomanip>
#include "Student.h"
#include <string>
#include <cstring>

using namespace std;
#include<algorithm>
int main()
{
	StudentMIS sysu;
	StudentBase *pStudentBase = &sysu;
	FirstA *pFirstA = &sysu;
	FirstB *pFirstB = &sysu;
	FirstC *pFirstC = &sysu;
	StudentMIS *pStudentMIS = &sysu;
	cout<<endl<<setw(20)<<" "<<left<<setw(30)<<"欢迎进入学生信息管理系统！"<<endl<<endl;
	cout<<endl<<endl<<setw(18)<<" "<<left<<setw(20)<<"1.用户选择"<<setw(30)<<"2.退出系统"<<endl;
	cout<<endl<<setw(25)<<" "<<"请选择：";
	string init;
	while(cin>>init)
	{
		//输入异常处理
		if(init != "1" && init != "2")
		{
			system ("cls");
			cout<<endl<<endl<<setw(18)<<" "<<left<<setw(20)<<"1.用户选择"<<setw(30)<<"2.退出系统"<<endl;
			cout<<endl<<setw(20)<<" "<<"输入错误啦！重新选择吧：";
			continue;
		}
		if(init == "2") break;
		system ("cls");
	    cout<<endl<<endl<<setw(22)<<" "<<left<<setw(30)<<"用户登录账号选择中..."<<endl;
	    cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.招生办工作人员"<<"2.系教务员"<<endl;
	    cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.学位办工作人员"<<"4.返回上一层"<<endl;
	    cout<<endl<<setw(20)<<" "<<"请选择登录账号：";
	    string user;
	    while(cin>>user)
	    {
			//输入异常处理
		    if(user != "1" && user != "2" && user != "3" && user != "4")  
			{
				system ("cls");
				cout<<endl<<endl<<setw(22)<<" "<<left<<setw(30)<<"用户登录账号选择中..."<<endl;
	            cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.招生办工作人员"<<"2.系教务员"<<endl;
	            cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.学位办工作人员"<<"4.返回上一层"<<endl;
				cout<<endl<<setw(20)<<" "<<"输入错误啦！重新选择吧：";
				continue;
			}
			if(user == "1")
			{
				system ("cls");
				cout<<endl<<endl<<setw(25)<<" "<<left<<setw(30)<<"1.建立学生信息管理系统"<<endl;
	            cout<<endl<<setw(25)<<" "<<left<<setw(30)<<"2.修改学生资料"<<endl;
	            cout<<endl<<setw(25)<<" "<<left<<setw(30)<<"3.返回上一层"<<endl;
				cout<<endl<<setw(25)<<" "<<"请选择：";
				string choice;
				while(cin>>choice)
				{
					//输入异常处理
					if(choice != "1" && choice != "2" && choice != "3")
					{
						system ("cls");
						cout<<endl<<endl<<setw(25)<<" "<<left<<setw(30)<<"1.建立学生信息管理系统"<<endl;
	                    cout<<endl<<setw(25)<<" "<<left<<setw(30)<<"2.修改学生资料"<<endl;
	                    cout<<endl<<setw(25)<<" "<<left<<setw(30)<<"3.返回上一层"<<endl;
						cout<<endl<<setw(25)<<" "<<"输入错误啦！重新选择吧：";
						continue;
					}
					if(choice == "1")
					{
						pStudentBase->bulidBaseData();
					}
					else if(choice == "2")
					{
						pStudentBase->modifyData();
					}
					else break;
					system ("cls");
					cout<<endl<<endl<<setw(25)<<" "<<left<<setw(30)<<"1.建立学生信息管理系统"<<endl;
	                cout<<endl<<setw(25)<<" "<<left<<setw(30)<<"2.修改学生资料"<<endl;
	                cout<<endl<<setw(25)<<" "<<left<<setw(30)<<"3.返回上一层"<<endl;
					cout<<endl<<setw(25)<<" "<<"请再次选择：";
				}
			}
			else if(user == "2")
			{
				system ("cls");
				cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.A系教务员"<<"2.B系教务员"<<endl;
	            cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.C系教务员"<<"4.返回上一层"<<endl;
				cout<<endl<<setw(25)<<" "<<"请选择：";
				string major;
				while(cin>>major)
				{
					//输入异常处理
					if(major != "1" && major != "2" && major != "3" && major != "4")
					{
						system ("cls");
						cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.A系教务员"<<"2.B系教务员"<<endl;
	                    cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.C系教务员"<<"4.返回上一层"<<endl;
						cout<<endl<<setw(20)<<" "<<"输入错误啦！重新选择吧：";
						continue;
					}
					if(major == "1")
					{
						system ("cls");
						cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.录入主修学生成绩"<<"2.录入辅修学生成绩"<<endl;
						cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.统计优秀学生"<<"4.统计主修补考学生"<<endl;
						cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"5.统计辅修补考学生"<<"6.返回上一层"<<endl;
						cout<<endl<<setw(25)<<" "<<"请选择：";
						while(cin>>major)
						{
							if(major!="1"&&major!="2"&&major!="3"&&major!="4"&&major!="5"&&major!="6")
							{
								system ("cls");
								cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.录入主修学生成绩"<<"2.录入辅修学生成绩"<<endl;
						        cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.统计优秀学生"<<"4.统计主修补考学生"<<endl;
						        cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"5.统计辅修补考学生"<<"6.返回上一层"<<endl;
								cout<<endl<<setw(20)<<" "<<"输入错误啦！重新选择吧：";
						        continue;
							}
							if(major == "1")
							{
								pFirstA->inputA_MajorScore();
							}
							else if(major == "2") pFirstA->inputA_SecondScore();
							else if(major == "3") pFirstA->outputA_Good();
							else if(major == "4") pFirstA->outputA_MajorFail();
							else if(major == "5") pFirstA->outputA_SecondFail();
							else break;
							system ("cls");
							cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.录入主修学生成绩"<<"2.录入辅修学生成绩"<<endl;
						    cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.统计优秀学生"<<"4.统计主修补考学生"<<endl;
						    cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"5.统计辅修补考学生"<<"6.返回上一层"<<endl;
							cout<<endl<<setw(25)<<" "<<"请继续选择：";
						}
					}
					else if(major == "2")
					{
						system ("cls");
						cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.录入主修学生成绩"<<"2.录入辅修学生成绩"<<endl;
						cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.统计优秀学生"<<"4.统计主修补考学生"<<endl;
						cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"5.统计辅修补考学生"<<"6.返回上一层"<<endl;
						cout<<endl<<setw(25)<<" "<<"请选择：";
						while(cin>>major)
						{
							//输入异常处理
							if(major!="1"&&major!="2"&&major!="3"&&major!="4"&&major!="5"&&major!="6")
							{
								system ("cls");
								cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.录入主修学生成绩"<<"2.录入辅修学生成绩"<<endl;
						        cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.统计优秀学生"<<"4.统计主修补考学生"<<endl;
						        cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"5.统计辅修补考学生"<<"6.返回上一层"<<endl;
								cout<<endl<<setw(20)<<" "<<"输入错误啦！重新选择吧：";
						        continue;
							}
							if(major == "1")
							{
								pFirstB->inputB_MajorScore();
							}
							else if(major == "2") pFirstB->inputB_SecondScore();
							else if(major == "3") pFirstB->outputB_Good();
							else if(major == "4") pFirstB->outputB_MajorFail();
							else if(major == "5") pFirstB->outputB_SecondFail();
							else break;
							system ("cls");
							cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.录入主修学生成绩"<<"2.录入辅修学生成绩"<<endl;
						    cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.统计优秀学生"<<"4.统计主修补考学生"<<endl;
						    cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"5.统计辅修补考学生"<<"6.返回上一层"<<endl;
							cout<<endl<<setw(25)<<" "<<"请继续选择：";
						}
					}		
					else if(major == "3")
					{
						system ("cls");
						cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.录入主修学生成绩"<<"2.录入辅修学生成绩"<<endl;
						cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.统计优秀学生"<<"4.统计主修补考学生"<<endl;
						cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"5.统计辅修补考学生"<<"6.返回上一层"<<endl;
						cout<<endl<<setw(25)<<" "<<"请选择：";
						while(cin>>major)
						{
							//输入异常处理
							if(major!="1"&&major!="2"&&major!="3"&&major!="4"&&major!="5"&&major!="6")
							{
								system ("cls");
								cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.录入主修学生成绩"<<"2.录入辅修学生成绩"<<endl;
						        cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.统计优秀学生"<<"4.统计主修补考学生"<<endl;
						        cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"5.统计辅修补考学生"<<"6.返回上一层"<<endl;
								cout<<endl<<setw(20)<<" "<<"输入错误啦！重新选择吧：";
						        continue;
							}
							if(major == "1") pFirstC->inputC_MajorScore();
							else if(major == "2") pFirstC->inputC_SecondScore();
							else if(major == "3") pFirstC->outputC_Good();
							else if(major == "4") pFirstC->outputC_MajorFail();
							else if(major == "5") pFirstC->outputC_SecondFail();
							else break;
							system ("cls");
							cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.录入主修学生成绩"<<"2.录入辅修学生成绩"<<endl;
						    cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.统计优秀学生"<<"4.统计主修补考学生"<<endl;
						    cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"5.统计辅修补考学生"<<"6.返回上一层"<<endl;
							cout<<endl<<setw(25)<<" "<<"请继续选择：";
						}
					}
					else break;
					system ("cls");
					cout<<endl<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.A系教务员"<<"2.B系教务员"<<endl;
	                cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.C系教务员"<<"4.返回上一层"<<endl;
					cout<<endl<<setw(25)<<" "<<"请继续选择：";
				}
			}
			else if(user == "3")
			{
				system ("cls");
				cout<<endl<<endl<<setw(12)<<" "<<left<<setw(30)<<"1.设置主修学位需修课程数"<<"2.设置辅修学位需修课程数"<<endl;
				cout<<endl<<setw(12)<<" "<<left<<setw(30)<<"3.统计相关学位信息"<<"4.返回上一层"<<endl;
				cout<<endl<<setw(25)<<" "<<"请选择：";
				string choice;
				while(cin>>choice)
				{
					//输入异常处理
					if(choice != "1" && choice != "2" && choice != "3" && choice != "4")
					{
						system ("cls");
						cout<<endl<<endl<<setw(12)<<" "<<left<<setw(30)<<"1.设置主修学位需修课程数"<<"2.设置辅修学位需修课程数"<<endl;
				        cout<<endl<<setw(12)<<" "<<left<<setw(30)<<"3.统计相关学位信息"<<"4.返回上一层"<<endl;
						cout<<endl<<setw(20)<<" "<<"输入错误啦！重新选择吧：";
						continue;
					}
					if(choice == "1") pStudentMIS->degreeStanderOfFirst();
					else if(choice == "2") pStudentMIS->degreeStanderOfSecond();
					else if(choice == "3") pStudentMIS->degree();
					else break;
					system ("cls");
					cout<<endl<<endl<<setw(12)<<" "<<left<<setw(30)<<"1.设置主修学位需修课程数"<<"2.设置辅修学位需修课程数"<<endl;
				    cout<<endl<<setw(12)<<" "<<left<<setw(30)<<"3.统计相关学位信息"<<"4.返回上一层"<<endl;
					cout<<endl<<setw(25)<<" "<<"请继续选择：";
				}
			}
			else break;
			system ("cls");
			cout<<endl<<endl<<setw(22)<<" "<<left<<setw(30)<<"用户登录账号选择中..."<<endl;
	        cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"1.招生办工作人员"<<"2.系教务员"<<endl;
	        cout<<endl<<setw(15)<<" "<<left<<setw(25)<<"3.学位办工作人员"<<"4.返回上一层"<<endl;
			cout<<endl<<setw(20)<<" "<<"请继续选择：";
		}
		system ("cls");
	    cout<<endl<<endl<<setw(18)<<" "<<left<<setw(20)<<"1.用户选择"<<setw(30)<<"2.退出系统"<<endl;
	    cout<<endl<<setw(25)<<" "<<"请继续选择：";
	}
	return 0;
}
