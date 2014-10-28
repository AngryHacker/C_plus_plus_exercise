#include "Student.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin;
ofstream fout;

//建立学生管理系统
void StudentBase::bulidBaseData()
{
	//提示系统已建立
	if(mNum.size() != 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(25)<<" "<<"学生信息管理系统已建立！"<<endl;
		cout<<endl<<endl<<setw(25)<<" "<<"输入0返回上一层：";
	    string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(20)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	long num;
	string name,addr,major;
	int sex = 1,age;
	fin.open("Basefile.dat");
	fin>>num>>name>>sex;
	while((sex == 1 || sex == 0) && !fin.eof())
	{
		fin>>age>>major>>addr;
		mNum.push_back(num);
		mName.push_back(name);
		mSex.push_back(sex);
		mAge.push_back(age);
		mMajor.push_back(major);
		mAddr.push_back(addr);
		int pos = mNum.size() - 1;
		mPosition.insert(make_pair(num,pos));
		fin>>num>>name>>sex;
	}
	fin.close();
	system ("cls");
	cout<<endl<<endl<<setw(25)<<" "<<"学生信息录入完毕！"<<endl;
	cout<<endl<<setw(25)<<" "<<"以下为所有学生名单："<<endl;
	int i = 1;
	cout<<left;
	cout<<endl<<setw(25)<<" "<<setw(12)<<"学号"<<setw(10)<<"姓名"<<endl;
	for(map<long,int>::iterator it = mPosition.begin();it != mPosition.end();++it)
	{
		int pos = it->second;
		cout<<setw(20)<<"     "<<setw(4)<<i++<<setw(12)<<it->first<<setw(10)<<mName[pos]<<endl;
	}
	cout<<endl<<setw(25)<<" "<<"本届新生共有"<<mNum.size()<<"人!"<<endl;
	cout<<endl<<endl<<setw(25)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(20)<<" "<<"输入错误！按0返回上一层：";
	}
}

//修改学生基本资料
void StudentBase::modifyData()
{
	//异常，学生信息管理系统尚未建立
	if(mNum.size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(25)<<" "<<"输入0返回上一层：";
	    string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(20)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	system ("cls");
	cout<<endl<<endl<<setw(22)<<" "<<"以下为所有学生名单："<<endl;
	int i = 1;
	cout<<left;
	cout<<endl<<setw(20)<<" "<<setw(6)<<"编号"<<setw(12)<<"学号"<<setw(10)<<"姓名"<<endl;
	for(map<long,int>::iterator it = mPosition.begin();it != mPosition.end();++it)
	{
		int pos = it->second;
		cout<<setw(20)<<"     "<<setw(6)<<i++<<setw(12)<<it->first<<setw(10)<<mName[pos]<<endl;
	}
	cout<<endl<<setw(20)<<"        "<<setw(16)<<"1.修改学生信息"<<setw(10)<<"2.返回"<<endl; 
	cout<<endl<<setw(25)<<" "<<"请选择：";
	string str;
	int choose;
	while(cin>>str)
	{
		//输入异常处理
		if(str!= "1" && str != "2")
		{
			cout<<endl<<setw(20)<<"        "<<setw(16)<<"1.修改学生信息"<<setw(10)<<"2.返回"<<endl; 
	        cout<<endl<<setw(21)<<" "<<"错误输入！请重新选择：";
			continue;
		}
		if(str == "2") break;
		cout<<endl<<setw(20)<<" "<<"请输入您要修改的学生编号：";
		cin>>str;
		choose = 0;
		int n = str.size();
		bool correct = 1;
		for(int i = 0;i<n;++i)
		{
			if(!isdigit(str[i]))
			{
				correct = 0;
				break;
			}
			choose += (str[i] - '0')*pow(10,n-i-1);
		}
		if( n > 3 || choose > mNum.size()) correct = 0;
		//输入异常处理
		if(!correct)
		{
			system ("cls");
			cout<<endl<<setw(22)<<" "<<"无效输入！请重新选择！";
	        cout<<endl<<endl<<setw(22)<<" "<<"以下为所有学生名单："<<endl;
	        int i = 1;
	        cout<<left;
	        cout<<endl<<setw(20)<<" "<<setw(6)<<"编号"<<setw(12)<<"学号"<<setw(10)<<"姓名"<<endl;
	        for(map<long,int>::iterator it = mPosition.begin();it != mPosition.end();++it)
	        {
		        int pos = it->second;
		        cout<<setw(20)<<"     "<<setw(6)<<i++<<setw(12)<<it->first<<setw(10)<<mName[pos]<<endl;
	        }
	        cout<<endl<<setw(20)<<"        "<<setw(16)<<"1.修改学生信息"<<setw(10)<<"2.返回"<<endl; 
	        cout<<endl<<setw(25)<<" "<<"请选择：";
			continue;
		}
		map<long,int>::iterator it = mPosition.begin();
		for(int i=0;i<choose-1;++i) it++;
		choose = it->second;
		int num = mNum[choose];
		string name = mName[choose];
		int sex = mSex[choose];
		int age = mAge[choose];
		string addr = mAddr[choose];
		mPosition.erase(num);
		cout<<left<<endl;
		system ("cls");
		cout<<setw(18)<<" "<<"学号："<<setw(20)<<num<<"姓名："<<name<<endl;
		cout<<endl<<setw(18)<<" "<<"性别：";
		if(!sex) cout<<setw(20)<<"男";
		else cout<<setw(20)<<"女";
		cout<<"年龄："<<age<<endl;
		cout<<endl<<setw(18)<<" "<<"地址："<<addr<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<setw(10)<<"1.学号"<<setw(10)<<"2.姓名"<<setw(10)<<"3.性别"<<endl;
		cout<<endl<<setw(18)<<" "<<setw(10)<<"4.年龄"<<setw(10)<<"5.地址"<<setw(10)<<"6.返回"<<endl;
		cout<<endl<<setw(22)<<" "<<"请选择修改内容：";
		while(cin>>str)
		{
			if(str.size() == 1 && str[0] >= '1' && str[0] <= '6')
			{
				if(str=="1")
				{
					cout<<endl<<setw(20)<<" "<<"请输入学号：";
					cin>>num;
				}
				else if(str == "2")
				{
					cout<<endl<<setw(20)<<" "<<"请输入姓名： ";
					cin>>name;
				}
				else if(str == "3")
				{
					cout<<endl<<setw(20)<<" "<<"请输入性别（0 代表 男， 1 代表 女）：";
					while(cin>>str)
					{
						//输入异常处理
						if(str != "0" && str != "1")
						{
							cout<<endl<<setw(20)<<" "<<"输入错误啦！请重新输入性别吧（1 代表 男， 0 代表 女）：";
							continue;
						}
						if(str == "0") sex = 0;
						else sex = 1;
						break;
					}
				}
				else if(str == "4")
				{
					cout<<endl<<setw(20)<<" "<<"请输入年龄：";
					while(cin>>str)
					{
						bool is = 1;
						if(str.size() != 2 || !isdigit(str[0]) || !isdigit(str[1])) is = 0;
						//输入异常处理
						if(!is)
						{
							cout<<endl<<setw(20)<<" "<<"输入错误啦！请重新输入年龄吧：";
							continue;
						}
						age = str[0] - '0';
						str += str[1] * 10;
						break;
					}
				}
				else if(str == "5")
				{
					cout<<endl<<setw(20)<<" "<<"请输入地址：";
					cin>>addr;
				}
				else if(str == "6") break;
				cout<<endl<<setw(18)<<" "<<setw(10)<<"1.学号"<<setw(10)<<"2.姓名"<<setw(10)<<"3.性别"<<endl;
		        cout<<endl<<setw(18)<<" "<<setw(10)<<"4.年龄"<<setw(10)<<"5.地址"<<setw(10)<<"6.返回"<<endl;
		        cout<<endl<<setw(22)<<" "<<"请再次选择吧：";
			}
			//输入异常处理
			else
			{
				cout<<endl<<setw(18)<<" "<<setw(10)<<"1.学号"<<setw(10)<<"2.姓名"<<setw(10)<<"3.性别"<<endl;
		        cout<<endl<<setw(18)<<" "<<setw(10)<<"4.年龄"<<setw(10)<<"5.地址"<<setw(10)<<"6.返回"<<endl;
		        cout<<endl<<setw(22)<<" "<<"输入错误啦！请重新选择吧：";
			}
		}
		mNum.erase(mNum.begin()+choose);
		mName.erase(mName.begin()+choose);
		mSex.erase(mSex.begin()+choose);
		mAge.erase(mAge.begin()+choose);
		mAddr.erase(mAddr.begin()+choose);
		mNum.push_back(num);
		mName.push_back(name);
		mSex.push_back(sex);
		mAge.push_back(age);
		mAddr.push_back(addr);
		mPosition.clear();
		for(int i=0;i<mNum.size();++i)
		{
			mPosition.insert(make_pair(mNum[i],i));
		}
		system ("cls");
	    cout<<endl<<endl<<setw(22)<<" "<<"以下为所有学生名单："<<endl;
	    int i = 1;
	    cout<<left;
	    cout<<endl<<setw(20)<<" "<<setw(6)<<"编号"<<setw(12)<<"学号"<<setw(10)<<"姓名"<<endl;
	    for(map<long,int>::iterator it = mPosition.begin();it != mPosition.end();++it)
	    {
		    int pos = it->second;
		    cout<<setw(20)<<"     "<<setw(6)<<i++<<setw(12)<<it->first<<setw(10)<<mName[pos]<<endl;
	    }
	    cout<<endl<<setw(20)<<"        "<<setw(16)<<"1.修改学生信息"<<setw(10)<<"2.返回"<<endl; 
	    cout<<endl<<setw(25)<<" "<<"请选择：";
	}
	fout.open("Basefile.DAT");
	for(int i = 0;i<mNum.size();++i)
	{
		fout<<mNum[i]<<' '<<mName[i]<<' '<<mSex[i]<<' '<<mAge[i]<<' '<<mMajor[i]<<' '<<mAddr[i]<<endl;
	}
	fout.close();
}

vector<long> StudentBase::getmNum()
{
	return this->mNum;
}

vector<string> StudentBase::getmName()
{
	return this->mName;
}

vector<int> StudentBase::getmSex()
{
	return this->mSex;
}

vector<int> StudentBase::getmAge(){
	return this->mAge;
}

vector<string> StudentBase::getmAddr()
{
	return this->mAddr;
}

long StudentBase::getNumAtIndex(int i)
{
	return mNum[i];
}

string StudentBase::getNameAtIndex(int i)
{
	return mName[i];
}

int StudentBase::getSexAtIndex(int i)
{
	return mSex[i];
}

int StudentBase::getAgeAtIndex(int i)
{
	return mAge[i];
}

string StudentBase::getAddrAtIndex(int i)
{
	return mAddr[i];
}

//获得某学号在vector中的位置
int StudentBase::getmPosition(long Num)
{
	return mPosition.find(Num)->second;
}

FirstA::FirstA()
{
	char A[] = "mmmmmm";
	strcpy(mA_MajorDepName,A);
};

//录入A系学生主修成绩
void FirstA::inputA_MajorScore()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	    string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//主修学生信息已录入
	if(majorA_Num.size() != 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系主修学生成绩已录入！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	fin.open("AMajor.DAT");
	long num = 1;
	int score;
	char ch;
	fin>>num;
	while(num >= 0 && num <= 100000000 && !fin.eof())
	{
		majorA_Num.push_back(num);
		fin.get(ch);
		vector<int>s;
		while(ch == ' ' && !fin.eof()) 
		{
			fin>>score;
			s.push_back(score);
			fin.get(ch);
		}
		mA_FirstScore.push_back(s);
		fin>>num;
	}
	fin.close();
	system ("cls");
	cout<<endl<<setw(23)<<" "<<"主修学生成绩录入完毕！"<<endl;
	cout<<endl<<setw(23)<<" "<<"以下为所有主修学生成绩："<<endl;
	cout<<endl<<setw(20)<<" "<<setw(10)<<"学号"<<"各科目成绩"<<endl;
	for(int i=0;i<majorA_Num.size();++i)
	{
		cout<<setw(18)<<" "<<setw(10)<<majorA_Num[i];
		for(int j=0;j<mA_FirstScore[i].size();++j)
		{
			cout<<setw(5)<<mA_FirstScore[i][j];
		}
		cout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
}

//录入A系学生辅修成绩
void FirstA::inputA_SecondScore()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//辅修学生信息已录入
	if(secondA_Num.size() != 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系辅修学生成绩已录入！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	fin.open("AMinor.DAT");
	long num = 1;
	string str;
	int score;
	char ch;
	fin>>num;
	while(num >= 0 && num <= 100000000 && !fin.eof())
	{
		secondA_Num.push_back(num);
		fin.get(ch);
		fin>>str;
		A_Scond_MajorName.push_back(str);
		fin.get(ch);
		vector<int>s;
		while(ch == ' ' && !fin.eof())
		{
			fin>>score;
			s.push_back(score);
			fin.get(ch);
		}
		A_Fscore.push_back(s);
		fin>>num;
	}
	fin.close();
	system ("cls");
	cout<<endl<<setw(22)<<" "<<"辅修学生成绩录入完毕！"<<endl;
	cout<<endl<<setw(22)<<" "<<"以下为所有辅修学生成绩："<<endl;
	cout<<endl<<setw(20)<<" "<<setw(10)<<"学号"<<"各科目成绩"<<endl;
	for(int i=0;i<secondA_Num.size();++i)
	{
		cout<<setw(18)<<" "<<setw(10)<<secondA_Num[i];
		for(int j=0;j<A_Fscore[i].size();++j)
		{
			cout<<setw(5)<<A_Fscore[i][j];
		}
		cout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str1;
	while(cin>>str1)
	{
		if(str1 == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
}

//统计A系优秀学生
void FirstA::outputA_Good()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//学生信息尚未录入
	if(majorA_Num.size() == 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系学生成绩尚未录入！"<<endl;
		cout<<endl<<setw(18)<<" "<<"请先录入成绩！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	cout<<endl<<endl<<setw(18)<<" "<<"以下为本学期本系优秀学生："<<endl;
	cout<<endl<<"     "<<setw(12)<<"学号"<<setw(12)<<"姓名"<<setw(7)<<"性别"<<setw(7)<<"年龄"<<setw(20)<<"各科成绩"<<endl<<endl;
	fout.open("AGood.DAT");

	//统计A系主修优秀学生
	for(int i=0;i<majorA_Num.size();++i)
	{
		bool is = 1;
		int count = 0;
		for(int j=0;j<mA_FirstScore[i].size();++j)
		{
			if(mA_FirstScore[i][j] < 70)
			{
				is = 0;
				break;
			}
			if(mA_FirstScore[i][j] >= 85) count ++ ;
		}
		if(!is || count < 3) continue;
		long num = majorA_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<mA_FirstScore[i].size();++j) cout<<setw(4)<<mA_FirstScore[i][j];
		cout<<endl<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<mA_FirstScore[i].size();++j) fout<<' '<<mA_FirstScore[i][j];
		fout<<endl;
	}

	//统计A系辅修优秀学生
	for(int i=0;i<secondA_Num.size();++i)
	{
		bool is = 1;
		int count = 0;
		for(int j=0;j<A_Fscore[i].size();++j)
		{
			if(A_Fscore[i][j] < 70)
			{
				is = 0;
				break;
			}
			if(A_Fscore[i][j] >= 85) count ++ ;
		}
		if(!is || count < 3) continue;
		long num = secondA_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<A_Fscore[i].size();++j) cout<<setw(4)<<A_Fscore[i][j];
		cout<<endl<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<A_Fscore[i].size();++j) fout<<' '<<A_Fscore[i][j];
		fout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
	fout.close();
}

//统计A系主修不合格学生
void FirstA::outputA_MajorFail()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//学生信息尚未录入
	if(majorA_Num.size() == 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系主修学生成绩尚未录入！"<<endl;
		cout<<endl<<setw(18)<<" "<<"请先录入成绩！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	cout<<endl<<endl<<setw(18)<<" "<<"以下为本学期需补考的主修学生："<<endl;
	cout<<endl<<"     "<<setw(12)<<"学号"<<setw(12)<<"姓名"<<setw(7)<<"性别"<<setw(7)<<"年龄"<<setw(20)<<"补考科目成绩"<<endl;
	fout.open("AMajorFail.DAT");
	for(int i=0;i<majorA_Num.size();++i)
	{
		vector<int>fail;
		for(int j=0;j<mA_FirstScore[i].size();++j)
		{
			if(mA_FirstScore[i][j] < 60)
			{
				fail.push_back(mA_FirstScore[i][j]);
			}
		}
		if(fail.size() == 0) continue;
		long num = majorA_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<endl<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<fail.size();++j) cout<<setw(4)<<fail[j];
		cout<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<fail.size();++j) fout<<' '<<fail[j];
		fout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
	fout.close();
}

//统计A系辅修不合格学生
void FirstA::outputA_SecondFail()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//学生信息尚未录入
	if(secondA_Num.size() == 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系辅修学生成绩尚未录入！"<<endl;
		cout<<endl<<setw(18)<<" "<<"请先录入成绩！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	cout<<endl<<endl<<setw(18)<<" "<<"以下为本学期需补考的辅修学生："<<endl;
	cout<<endl<<"     "<<setw(12)<<"学号"<<setw(12)<<"姓名"<<setw(7)<<"性别"<<setw(7)<<"年龄"<<setw(20)<<"补考科目成绩"<<endl;
	fout.open("AMinorFail.DAT");
	for(int i=0;i<secondA_Num.size();++i)
	{
		vector<int>fail;
		for(int j=0;j<A_Fscore[i].size();++j)
		{
			if(A_Fscore[i][j] < 60)
			{
				fail.push_back(A_Fscore[i][j]);
			}
		}
		if(fail.size() == 0) continue;
		long num = secondA_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<endl<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<fail.size();++j) cout<<setw(4)<<fail[j];
		cout<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<fail.size();++j) fout<<' '<<fail[j];
		fout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
	fout.close();
}

char* FirstA::getA_MajorDepName()
{
	return mA_MajorDepName;
}

vector<long> FirstA::getA_MajorNum()
{
	return majorA_Num;
}

vector<long>FirstA::getA_SecondNum()
{
	return secondA_Num;
}

vector< vector<int> > FirstA::getA_FirstScore()
{
	return mA_FirstScore;
}

vector< vector<int> > FirstA::getA_FScore()
{
	return A_Fscore;
}

FirstB::FirstB()
{
	char B[] = "ffffff";
	strcpy(mB_MajorDepName,B);
}

//录入B系主修学生
void FirstB::inputB_MajorScore()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//主修学生信息已录入
	if(majorB_Num.size() != 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系主修学生成绩已录入！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	fin.open("BMajor.DAT");
	long num = 1;
	int score;
	char ch;
	fin>>num;
	while(num >= 0 && num <= 100000000 && !fin.eof())
	{
		majorB_Num.push_back(num);
		fin.get(ch);
		vector<int>s;
		while(ch == ' ' && !fin.eof())
		{
			fin>>score;
			s.push_back(score);
			fin.get(ch);
		}
		mB_FirstScore.push_back(s);
		fin>>num;
	}
	fin.close();
	cout<<endl<<setw(18)<<" "<<"主修学生成绩录入完毕！"<<endl;
	cout<<endl<<setw(18)<<" "<<"以下为所有主修学生成绩："<<endl;
	cout<<endl<<setw(20)<<" "<<setw(10)<<"学号"<<"各科目成绩"<<endl;
	for(int i=0;i<majorB_Num.size();++i)
	{
		cout<<setw(18)<<" "<<setw(10)<<majorB_Num[i];
		for(int j=0;j<mB_FirstScore[i].size();++j)
		{
			cout<<setw(5)<<mB_FirstScore[i][j];
		}
		cout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
}

//录入B系辅修学生
void FirstB::inputB_SecondScore()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//辅修学生信息已录入
	if(secondB_Num.size() != 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系辅修学生成绩已录入！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	fin.open("BMinor.DAT");
	long num = 1;
	string str;
	int score;
	char ch;
	fin>>num;
	while(num >= 0 && num <= 100000000 && !fin.eof())
	{
		secondB_Num.push_back(num);
		fin>>str;
		B_Scond_MajorName.push_back(str);
		fin.get(ch);
		vector<int>s;
		while(ch == ' ' && !fin.eof())
		{
			fin>>score;
			s.push_back(score);
			fin.get(ch);
		}
		B_Fscore.push_back(s);
		fin>>num;
	}
	fin.close();
	cout<<endl<<setw(22)<<" "<<"辅修学生成绩录入完毕！"<<endl;
	cout<<endl<<setw(22)<<" "<<"以下为所有辅修学生成绩："<<endl;
	cout<<endl<<setw(20)<<" "<<setw(10)<<"学号"<<"各科目成绩"<<endl;
	for(int i=0;i<secondB_Num.size();++i)
	{
		cout<<setw(18)<<" "<<setw(10)<<secondB_Num[i];
		for(int j=0;j<B_Fscore[i].size();++j)
		{
			cout<<setw(5)<<B_Fscore[i][j];
		}
		cout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str1;
	while(cin>>str1)
	{
		if(str1 == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
}

//统计B系辅修学生
void FirstB::outputB_Good()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//学生信息尚未录入
	if(majorB_Num.size() == 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系学生成绩尚未录入！"<<endl;
		cout<<endl<<setw(18)<<" "<<"请先录入成绩！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	cout<<endl<<endl<<setw(18)<<" "<<"以下为本学期本系优秀学生："<<endl;
	cout<<endl<<"     "<<setw(12)<<"学号"<<setw(12)<<"姓名"<<setw(7)<<"性别"<<setw(7)<<"年龄"<<setw(20)<<"各科成绩"<<endl<<endl;
	fout.open("BGood.DAT");

	//统计B系主修优秀学生
	for(int i=0;i<majorB_Num.size();++i)
	{
		bool is = 1;
		int count = 0;
		for(int j=0;j<mB_FirstScore[i].size();++j)
		{
			if(mB_FirstScore[i][j] < 70)
			{
				is = 0;
				break;
			}
			if(mB_FirstScore[i][j] >= 85) count ++ ;
		}
		if(!is || count < 3) continue;
		long num = majorB_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<mB_FirstScore[i].size();++j) cout<<setw(4)<<mB_FirstScore[i][j];
		cout<<endl<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<mB_FirstScore[i].size();++j) fout<<' '<<mB_FirstScore[i][j];
		fout<<endl;
	}

	//统计B系辅修优秀学生
	for(int i=0;i<secondB_Num.size();++i)
	{
		bool is = 1;
		int count = 0;
		for(int j=0;j<B_Fscore[i].size();++j)
		{
			if(B_Fscore[i][j] < 70)
			{
				is = 0;
				break;
			}
			if(B_Fscore[i][j] >= 85) count ++ ;
		}
		if(!is || count < 3) continue;
		long num = secondB_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<B_Fscore[i].size();++j) cout<<setw(4)<<B_Fscore[i][j];
		cout<<endl<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<B_Fscore[i].size();++j) fout<<' '<<B_Fscore[i][j];
		fout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
	fout.close();
}

//统计B系主修不合格学生
void FirstB::outputB_MajorFail()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//主修学生信息尚未录入
	if(majorB_Num.size() == 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系主修学生成绩尚未录入！"<<endl;
		cout<<endl<<setw(18)<<" "<<"请先录入成绩！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	cout<<endl<<endl<<setw(18)<<" "<<"以下为本学期需补考的主修学生："<<endl;
	cout<<endl<<"     "<<setw(12)<<"学号"<<setw(12)<<"姓名"<<setw(7)<<"性别"<<setw(7)<<"年龄"<<setw(20)<<"补考科目成绩"<<endl;
	fout.open("BMajorFail.DAT");
	for(int i=0;i<majorB_Num.size();++i)
	{
		vector<int>fail;
		for(int j=0;j<mB_FirstScore[i].size();++j)
		{
			if(mB_FirstScore[i][j] < 60)
			{
				fail.push_back(mB_FirstScore[i][j]);
			}
		}
		if(fail.size() == 0) continue;
		long num = majorB_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<endl<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<fail.size();++j) cout<<setw(4)<<fail[j];
		cout<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<fail.size();++j) fout<<' '<<fail[j];
		fout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
	fout.close();
}

//统计B系辅修不合格学生
void FirstB::outputB_SecondFail()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//辅修学生信息尚未录入
	if(majorB_Num.size() == 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系辅修学生成绩尚未录入！"<<endl;
		cout<<endl<<setw(18)<<" "<<"请先录入成绩！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	cout<<endl<<endl<<setw(18)<<" "<<"以下为本学期需补考的辅修学生："<<endl;
	cout<<endl<<"     "<<setw(12)<<"学号"<<setw(12)<<"姓名"<<setw(7)<<"性别"<<setw(7)<<"年龄"<<setw(20)<<"补考科目成绩"<<endl;
	fout.open("BMinorFail.DAT");
	for(int i=0;i<secondB_Num.size();++i)
	{
		vector<int>fail;
		for(int j=0;j<B_Fscore[i].size();++j)
		{
			if(B_Fscore[i][j] < 60)
			{
				fail.push_back(B_Fscore[i][j]);
			}
		}
		if(fail.size() == 0) continue;
		long num = secondB_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<endl<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<fail.size();++j) cout<<setw(4)<<fail[j];
		cout<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<fail.size();++j) fout<<' '<<fail[j];
		fout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
	fout.close();
}

char* FirstB::getB_MajorDepName()
{
	return mB_MajorDepName;
}

vector<long> FirstB::getB_MajorNum()
{
	return majorB_Num;
}

vector<long> FirstB::getB_SecondNum()
{
	return secondB_Num;
}

vector< vector<int> > FirstB::getB_FirstScore()
{
	return mB_FirstScore;
}

vector< vector<int> > FirstB::getB_FScore()
{
	return B_Fscore;
}

FirstC::FirstC()
{
	char C[] = "cccccc";
	strcpy(mC_MajorDepName,C);
}

//录入C系主修学生
void FirstC::inputC_MajorScore()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//主修学生信息已录入
	if(majorC_Num.size() != 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系主修学生成绩已录入！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	fin.open("CMajor.DAT");
	long num = 1;
	int score;
	char ch;
	fin>>num;
	while(num >= 0 && num <= 100000000 && !fin.eof())
	{
		majorC_Num.push_back(num);
		fin.get(ch);
		vector<int>s;
		while(ch == ' ' && !fin.eof())
		{
			fin>>score;
			s.push_back(score);
			fin.get(ch);
		}
		mC_FirstScore.push_back(s);
		fin>>num;
	}
	fin.close();
	cout<<endl<<setw(18)<<" "<<"主修学生成绩录入完毕！"<<endl;
	cout<<endl<<setw(18)<<" "<<"以下为所有主修学生成绩："<<endl;
	cout<<endl<<setw(20)<<" "<<setw(10)<<"学号"<<"各科目成绩"<<endl;
	for(int i=0;i<majorC_Num.size();++i)
	{
		cout<<setw(18)<<" "<<setw(10)<<majorC_Num[i];
		for(int j=0;j<mC_FirstScore[i].size();++j)
		{
			cout<<setw(5)<<mC_FirstScore[i][j];
		}
		cout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str1;
	while(cin>>str1)
	{
		if(str1 == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
}

//录入C系辅修学生
void FirstC::inputC_SecondScore()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//辅修学生信息已录入
	if(secondC_Num.size() != 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系主修学生成绩已录入！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	fin.open("CMinor.DAT");
	long num = 1;
	string str;
	int score;
	char ch;
	fin>>num;
	while(num >= 0 && num <= 100000000 && !fin.eof())
	{
		secondC_Num.push_back(num);
		fin>>str;
		C_Scond_MajorName.push_back(str);
		fin.get(ch);
		vector<int>s;
		while(ch == ' ' && !fin.eof())
		{
			fin>>score;
			s.push_back(score);
			fin.get(ch);
		}
		C_Fscore.push_back(s);
		fin>>num;
	}
	fin.close();
	cout<<endl<<setw(22)<<" "<<"辅修学生成绩录入完毕！"<<endl;
	cout<<endl<<setw(22)<<" "<<"以下为所有辅修学生成绩："<<endl;
	cout<<endl<<setw(20)<<" "<<setw(10)<<"学号"<<"各科目成绩"<<endl;
	for(int i=0;i<secondC_Num.size();++i)
	{
		cout<<setw(18)<<" "<<setw(10)<<secondC_Num[i];
		for(int j=0;j<C_Fscore[i].size();++j)
		{
			cout<<setw(5)<<C_Fscore[i][j];
		}
		cout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str1;
	while(cin>>str1)
	{
		if(str1 == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
}

//统计Ｃ系优秀学生
void FirstC::outputC_Good()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//学生信息已录入
	if(majorC_Num.size() == 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系学生成绩尚未录入！"<<endl;
		cout<<endl<<setw(18)<<" "<<"请先录入成绩！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	cout<<endl<<endl<<setw(18)<<" "<<"以下为本学期本系优秀学生："<<endl;
	cout<<endl<<"     "<<setw(12)<<"学号"<<setw(12)<<"姓名"<<setw(7)<<"性别"<<setw(7)<<"年龄"<<setw(20)<<"各科成绩"<<endl<<endl;
	fout.open("CGood.DAT");

	//统计C系主修优秀学生
	for(int i=0;i<majorC_Num.size();++i)
	{
		bool is = 1;
		int count = 0;
		for(int j=0;j<mC_FirstScore[i].size();++j)
		{
			if(mC_FirstScore[i][j] < 70)
			{
				is = 0;
				break;
			}
			if(mC_FirstScore[i][j] >= 85) count ++ ;
		}
		if(!is || count < 3) continue;
		long num = majorC_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<mC_FirstScore[i].size();++j) cout<<setw(4)<<mC_FirstScore[i][j];
		cout<<endl<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<mC_FirstScore[i].size();++j) fout<<' '<<mC_FirstScore[i][j];
		fout<<endl;
	}

	//统计C系辅修优秀学生
	for(int i=0;i<secondC_Num.size();++i)
	{
		bool is = 1;
		int count = 0;
		for(int j=0;j<C_Fscore[i].size();++j)
		{
			if(C_Fscore[i][j] < 70)
			{
				is = 0;
				break;
			}
			if(C_Fscore[i][j] >= 85) count ++ ;
		}
		if(!is || count < 3) continue;
		long num = secondC_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<C_Fscore[i].size();++j) cout<<setw(4)<<C_Fscore[i][j];
		cout<<endl<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<C_Fscore[i].size();++j) fout<<' '<<C_Fscore[i][j];
		fout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
	fout.close();
}

//统计C系主修不合格学生
void FirstC::outputC_MajorFail()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//主修学生信息尚未录入
	if(majorC_Num.size() == 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系主修学生成绩尚未录入！"<<endl;
		cout<<endl<<setw(18)<<" "<<"请先录入成绩！"<<endl;
		cout<<endl<<endl<<setw(18)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	cout<<endl<<endl<<setw(18)<<" "<<"以下为本学期需补考的主修学生："<<endl;
	cout<<endl<<"     "<<setw(12)<<"学号"<<setw(12)<<"姓名"<<setw(7)<<"性别"<<setw(7)<<"年龄"<<setw(20)<<"补考科目成绩"<<endl;
	fout.open("CMajorFail.DAT");
	for(int i=0;i<majorC_Num.size();++i)
	{
		vector<int>fail;
		for(int j=0;j<mC_FirstScore[i].size();++j)
		{
			if(mC_FirstScore[i][j] < 60)
			{
				fail.push_back(mC_FirstScore[i][j]);
			}
		}
		if(fail.size() == 0) continue;
		long num = majorC_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<endl<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<fail.size();++j) cout<<setw(4)<<fail[j];
		cout<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<fail.size();++j) fout<<' '<<fail[j];
		fout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
	    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
	fout.close();
}

//统计C系辅修不合格学生
void FirstC::outputC_SecondFail()
{
	//异常，学生信息管理系统尚未建立
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	//辅修学生信息尚未录入
	if(majorC_Num.size() == 0) 
	{
		system ("cls");
		cout<<endl<<setw(18)<<" "<<"本系辅修学生成绩尚未录入！"<<endl;
		cout<<endl<<setw(18)<<" "<<"请先录入成绩！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return ;
	}
	system ("cls");
	cout<<endl<<endl<<setw(18)<<" "<<"以下为本学期需补考的辅修学生："<<endl;
	cout<<endl<<"     "<<setw(12)<<"学号"<<setw(12)<<"姓名"<<setw(7)<<"性别"<<setw(7)<<"年龄"<<setw(20)<<"补考科目成绩"<<endl;
	fout.open("CMinorFail.DAT");
	for(int i=0;i<secondC_Num.size();++i)
	{
		vector<int>fail;
		for(int j=0;j<C_Fscore[i].size();++j)
		{
			if(C_Fscore[i][j] < 60)
			{
				fail.push_back(C_Fscore[i][j]);
			}
		}
		if(fail.size() == 0) continue;
		long num = secondC_Num[i];
		int pos = getmPosition(num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<left;
		cout<<endl<<"     "<<setw(12)<<num<<setw(12)<<name;
		if(!sex) cout<<setw(7)<<"男";
		else cout<<setw(7)<<"女";
		cout<<setw(7)<<age;
		for(int j=0;j<fail.size();++j) cout<<setw(4)<<fail[j];
		cout<<endl;
		fout<<num<<' '<<name<<' '<<sex<<' '<<age;
		for(int j=0;j<fail.size();++j) fout<<' '<<fail[j];
		fout<<endl;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
	fout.close();
}

char* FirstC::getC_MajorDepName()
{
	return mC_MajorDepName;
}

vector<long> FirstC::getC_MajorNum()
{
	return majorC_Num;
}

vector<long> FirstC::getC_SecondNum()
{
	return secondC_Num;
}

vector< vector<int> > FirstC::getC_FirstScore()
{
	return mC_FirstScore;
}

vector< vector<int> > FirstC::getC_FScore()
{
	return C_Fscore;
}

StudentMIS::StudentMIS()
{
	SA = 5;
	SB = 5;
	SC = 5;
	KA = 4;
	KB = 4;
	KC = 4;
}

//设置获得主修学位需修满课程数
void StudentMIS::degreeStanderOfFirst()
{
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	system ("cls");
	cout<<endl<<setw(20)<<" "<<"当前各系主修学位需修满课程数："<<endl;
	cout<<endl<<setw(22)<<" "<<setw(5)<<"A: "<<setw(3)<<SA<<setw(4)<<"B: "<<setw(3)<<SB<<setw(4)<<"C: "<<setw(3)<<SC<<endl;
	string courseNum;
	int cNum;
	cout<<endl<<endl<<setw(20)<<' '<<"请输入A系主修学位修满课程数：";
	while(cin>>courseNum)
	{
		bool is = 1;
		cNum = 0;
		if(courseNum.size() > 2) is = 0;
		for(int i = 0;i<courseNum.size();++i)
		{
			if(!isdigit(courseNum[i]))
			{
				is = 0;
				break;
			}
			cNum += (courseNum[i] - '0')*pow(10,courseNum.size() - i -1);
		}
		//输入异常处理
		if(!is)
		{
			cout<<endl<<endl<<setw(20)<<" "<<"输入课程数不符合标准！"<<endl;
			cout<<endl<<endl<<setw(20)<<' '<<"请输入A系主修学位修满课程数：";
			continue;
		}
		SA = cNum;
		break;
	}
	cout<<endl<<endl<<setw(20)<<' '<<"请输入B系主修学位修满课程数：";
	while(cin>>courseNum)
	{
		bool is = 1;
		cNum = 0;
		if(courseNum.size() > 2) is = 0;
		for(int i = 0;i<courseNum.size();++i)
		{
			if(!isdigit(courseNum[i]))
			{
				is = 0;
				break;
			}
			cNum += (courseNum[i] - '0')*pow(10,courseNum.size() - i -1);
		}
		//输入异常处理
		if(!is)
		{
			cout<<endl<<endl<<setw(20)<<" "<<"输入课程数不符合标准！"<<endl;
			cout<<endl<<endl<<setw(20)<<' '<<"请输入B系主修学位修满课程数：";
			continue;
		}
		SB = cNum;
		break;
	}
	cout<<endl<<endl<<setw(20)<<' '<<"请输入C系主修学位修满课程数：";
	while(cin>>courseNum)
	{
		bool is = 1;
		cNum = 0;
		if(courseNum.size() > 2) is = 0;
		for(int i = 0;i<courseNum.size();++i)
		{
			if(!isdigit(courseNum[i]))
			{
				is = 0;
				break;
			}
			cNum += (courseNum[i] - '0')*pow(10,courseNum.size() - i -1);
		}
		//输入异常处理
		if(!is)
		{
			cout<<endl<<endl<<setw(20)<<" "<<"输入课程数不符合标准！"<<endl;
			cout<<endl<<endl<<setw(20)<<' '<<"请输入C系主修学位修满课程数：";
			continue;
		}
		SC = cNum;
		break;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"当前各系主修学位需修满课程数："<<endl;
	cout<<endl<<setw(22)<<" "<<setw(5)<<"A: "<<setw(3)<<SA<<setw(4)<<"B: "<<setw(3)<<SB<<setw(4)<<"C: "<<setw(3)<<SC<<endl;
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
}

//设置获得辅修学位需修满课程数
void StudentMIS::degreeStanderOfSecond()
{
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	system ("cls");
	cout<<endl<<setw(20)<<" "<<"当前各系辅修学位需修满课程数："<<endl;
	cout<<endl<<setw(22)<<" "<<setw(5)<<"A: "<<setw(3)<<KA<<setw(4)<<"B: "<<setw(3)<<KB<<setw(4)<<"C: "<<setw(3)<<KC<<endl;
	string courseNum;
	int cNum;
	cout<<endl<<endl<<setw(20)<<' '<<"请输入A系辅修学位修满课程数：";
	while(cin>>courseNum)
	{
		bool is = 1;
		cNum = 0;
		if(courseNum.size() > 2) is = 0;
		for(int i = 0;i<courseNum.size();++i)
		{
			if(!isdigit(courseNum[i]))
			{
				is = 0;
				break;
			}
			cNum += (courseNum[i] - '0')*pow(10,courseNum.size() - i -1);
		}
		//输入异常处理
		if(!is)
		{
			cout<<endl<<endl<<setw(20)<<" "<<"输入课程数不符合标准！"<<endl;
			cout<<endl<<endl<<setw(20)<<' '<<"请输入A系辅修学位修满课程数：";
			continue;
		}
		KA = cNum;
		break;
	}
	cout<<endl<<endl<<setw(20)<<' '<<"请输入B系辅修学位修满课程数：";
	while(cin>>courseNum)
	{
		bool is = 1;
		cNum = 0;
		if(courseNum.size() > 2) is = 0;
		for(int i = 0;i<courseNum.size();++i)
		{
			if(!isdigit(courseNum[i]))
			{
				is = 0;
				break;
			}
			cNum += (courseNum[i] - '0')*pow(10,courseNum.size() - i -1);
		}
		//输入异常处理
		if(!is)
		{
			cout<<endl<<endl<<setw(20)<<" "<<"输入课程数不符合标准！"<<endl;
			cout<<endl<<endl<<setw(20)<<' '<<"请输入B系辅修学位修满课程数：";
			continue;
		}
		KB = cNum;
		break;
	}
	cout<<endl<<endl<<setw(20)<<' '<<"请输入C系辅修学位修满课程数：";
	while(cin>>courseNum)
	{
		bool is = 1;
		cNum = 0;
		if(courseNum.size() > 2) is = 0;
		for(int i = 0;i<courseNum.size();++i)
		{
			if(!isdigit(courseNum[i]))
			{
				is = 0;
				break;
			}
			cNum += (courseNum[i] - '0')*pow(10,courseNum.size() - i -1);
		}
		//输入异常处理
		if(!is)
		{
			cout<<endl<<endl<<setw(20)<<" "<<"输入课程数不符合标准！"<<endl;
			cout<<endl<<endl<<setw(20)<<' '<<"请输入C系辅修学位修满课程数：";
			continue;
		}
		KC = cNum;
		break;
	}
	cout<<endl<<endl<<setw(20)<<" "<<"当前各系辅修学位需修满课程数："<<endl;
	cout<<endl<<setw(22)<<" "<<setw(5)<<"A: "<<setw(3)<<KA<<setw(4)<<"B: "<<setw(3)<<KB<<setw(4)<<"C: "<<setw(3)<<KC<<endl;
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
}

//统计获得学位情况
void StudentMIS::degree()
{
	if(getmNum().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(20)<<" "<<"学生信息管理系统尚未建立！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请等待招生办人员建立学生管理系统！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	if(getA_FirstScore().size() == 0 && getB_FirstScore().size() == 0 && getC_FirstScore().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(18)<<" "<<"未找到任何主修学生成绩信息！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请通知各系教务员录入成绩！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}
	vector<long>degree,failDegree,num;
	vector< vector<int> >score;
	map<long,bool>getDegree;
	for(int i=0;i<getmNum().size();++i) getDegree.insert(make_pair(getmNum()[i],0));

	//统计A系主修学位获得者
	num = getA_MajorNum();
	score = getA_FirstScore();
	for(int i = 0;i<num.size();++i)
	{
		int count = 0;
		for(int j = 0;j<score[i].size();++j)
		{
			if(score[i][j] >= 60) count++;
		}
		if(count >= SA)
		{
			degree.push_back(num[i]);
			getDegree.find(num[i])->second = 1;
		}
		else failDegree.push_back(num[i]);
	}
	fout.open("Degree.DAT");
	fout<<"主修学位获得学生："<<endl;
	system ("cls");
	cout<<endl<<endl<<setw(20)<<" "<<"主修学位获得学生："<<endl;
	cout<<left;
	cout<<endl<<setw(8)<<" "<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"专业"<<setw(5)<<"性别"<<setw(5)<<"年龄"<<setw(10)<<"地址"<<endl;
	for(int i=0;i<degree.size();++i)
	{
		long m_Num = degree[i];
		int pos = getmPosition(m_Num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<setw(8)<<" "<<setw(10)<<m_Num<<setw(10)<<name<<setw(10)<<getA_MajorDepName();
		if(!sex) cout<<setw(5)<<"男";
		else cout<<setw(5)<<"女";
		cout<<setw(5)<<age<<setw(10)<<addr<<endl;
		fout<<m_Num<<" "<<name<<" "<<getA_MajorDepName()<<" "<<sex<<" "<<age<<" "<<addr<<endl;
	}
	degree.clear();
	if(getA_FScore().size() == 0 && getB_FScore().size() == 0 && getC_FScore().size() == 0)
	{
		system ("cls");
		cout<<endl<<endl<<setw(18)<<" "<<"未找到任何辅修学生成绩信息！"<<endl;
		cout<<endl<<endl<<setw(20)<<" "<<"请通知各系教务员录入成绩！"<<endl;
		fout.close();
		cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
		string str;
	    while(cin>>str)
	    {
		    if(str == "0") break;
		    else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	    }
		return;
	}

	//统计B系主修学位获得者
	num = getB_MajorNum();
	score = getB_FirstScore();
	for(int i = 0;i<num.size();++i)
	{
		int count = 0;
		for(int j = 0;j<score[i].size();++j)
		{
			if(score[i][j] >= 60) count++;
		}
		if(count >= SB)
		{
			getDegree.find(num[i])->second = 1;
			degree.push_back(num[i]);
		}
		else failDegree.push_back(num[i]);
	}
	for(int i=0;i<degree.size();++i)
	{
		long m_Num = degree[i];
		int pos = getmPosition(m_Num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<setw(8)<<" "<<setw(10)<<m_Num<<setw(10)<<name<<setw(10)<<getB_MajorDepName();
		if(!sex) cout<<setw(5)<<"男";
		else cout<<setw(5)<<"女";
		cout<<setw(5)<<age<<setw(10)<<addr<<endl;
		fout<<m_Num<<" "<<name<<" "<<getB_MajorDepName()<<" "<<sex<<" "<<age<<" "<<addr<<endl;
	}
	degree.clear();

	//统计C系主修学位获得者
	num = getC_MajorNum();
	score = getC_FirstScore();
	for(int i = 0;i<num.size();++i)
	{
		int count = 0;
		for(int j = 0;j<score[i].size();++j)
		{
			if(score[i][j] >= 60) count++;
		}
		if(count >= SC)
		{
			getDegree.find(num[i])->second = 1;
			degree.push_back(num[i]);
		}
		else failDegree.push_back(num[i]);
	}
	for(int i=0;i<degree.size();++i)
	{
		long m_Num = degree[i];
		int pos = getmPosition(m_Num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<setw(8)<<" "<<setw(10)<<m_Num<<setw(10)<<name<<setw(10)<<getC_MajorDepName();
		if(!sex) cout<<setw(5)<<"男";
		else cout<<setw(5)<<"女";
		cout<<setw(5)<<age<<setw(10)<<addr<<endl;
		fout<<m_Num<<" "<<name<<" "<<getC_MajorDepName()<<" "<<sex<<" "<<age<<" "<<addr<<endl;
	}
	degree.clear();

	//统计A系辅修学位获得者
	num = getA_SecondNum();
	score = getA_FScore();
	for(int i = 0;i<num.size();++i)
	{
		int count = 0;
		for(int j = 0;j<score[i].size();++j)
		{
			if(score[i][j] >= 60) count++;
		}

		//课程数符合要求且已获得主修学位才可获得辅修学位
		if(count >= KA && getDegree.find(num[i])->second)
		{
			degree.push_back(num[i]);
		}
	}
	fout<<endl<<"辅修学位获得学生："<<endl;
	cout<<endl<<endl<<setw(20)<<" "<<"辅修学位获得学生："<<endl<<endl;
	cout<<left;
	cout<<setw(8)<<" "<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"辅修专业"<<setw(5)<<"性别"<<setw(5)<<"年龄"<<setw(10)<<"地址"<<endl;
	for(int i=0;i<degree.size();++i)
	{
		long m_Num = degree[i];
		int pos = getmPosition(m_Num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<setw(8)<<" "<<setw(10)<<m_Num<<setw(10)<<name<<setw(10)<<getA_MajorDepName();
		if(!sex) cout<<setw(5)<<"男";
		else cout<<setw(5)<<"女";
		cout<<setw(5)<<age<<setw(10)<<addr<<endl;
		fout<<m_Num<<" "<<name<<" "<<getA_MajorDepName()<<" "<<sex<<" "<<age<<" "<<addr<<endl;
	}
	degree.clear();

	//统计B系辅修学位获得者
	num = getB_SecondNum();
	score = getB_FScore();
	for(int i = 0;i<num.size();++i)
	{
		int count = 0;
		for(int j = 0;j<score[i].size();++j)
		{
			if(score[i][j] >= 60) count++;
		}

		//课程数符合要求且已获得主修学位才可获得辅修学位
		if(count >= KB && getDegree.find(num[i])->second)
		{
			degree.push_back(num[i]);
		}
	}
	for(int i=0;i<degree.size();++i)
	{
		long m_Num = degree[i];
		int pos = getmPosition(m_Num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<setw(8)<<" "<<setw(10)<<m_Num<<setw(10)<<name<<setw(10)<<getB_MajorDepName();
		if(!sex) cout<<setw(5)<<"男";
		else cout<<setw(5)<<"女";
		cout<<setw(5)<<age<<setw(10)<<addr<<endl;
		fout<<m_Num<<" "<<name<<" "<<getB_MajorDepName()<<" "<<sex<<" "<<age<<" "<<addr<<endl;
	}
	degree.clear();

	//统计C系辅修学位获得者
	num = getC_SecondNum();
	score = getC_FScore();
	for(int i = 0;i<num.size();++i)
	{
		int count = 0;
		for(int j = 0;j<score[i].size();++j)
		{
			if(score[i][j] >= 60) count++;
		}

		//课程数符合要求且已获得主修学位才可获得辅修学位
		if(count >= KC && getDegree.find(num[i])->second)
		{
			degree.push_back(num[i]);
		}
	}
	for(int i=0;i<degree.size();++i)
	{
		long m_Num = degree[i];
		int pos = getmPosition(m_Num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<setw(8)<<" "<<setw(10)<<m_Num<<setw(10)<<name<<setw(10)<<getC_MajorDepName();
		if(!sex) cout<<setw(5)<<"男";
		else cout<<setw(5)<<"女";
		cout<<setw(5)<<age<<setw(10)<<addr<<endl;
		fout<<m_Num<<" "<<name<<" "<<getC_MajorDepName()<<" "<<sex<<" "<<age<<" "<<addr<<endl;
	}
	fout<<endl<<"不能获得主修学位学生："<<endl;
	cout<<endl<<endl<<setw(20)<<" "<<"不能获得主修学位学生："<<endl<<endl;
	cout<<left;
	cout<<setw(8)<<" "<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(5)<<"年龄"<<setw(10)<<"地址"<<endl;
	for(int i=0;i<failDegree.size();++i)
	{
		long m_Num = failDegree[i];
		int pos = getmPosition(m_Num);
		string name = getNameAtIndex(pos);
		int sex = getSexAtIndex(pos);
		int age = getAgeAtIndex(pos);
		string addr = getAddrAtIndex(pos);
		cout<<setw(8)<<" "<<setw(10)<<m_Num<<setw(10)<<name;
		if(!sex) cout<<setw(5)<<"男";
		else cout<<setw(5)<<"女";
		cout<<setw(5)<<age<<setw(10)<<addr<<endl;
		fout<<m_Num<<" "<<name<<" "<<sex<<" "<<age<<" "<<addr<<endl;
	}
	fout.close();
	cout<<endl<<endl<<setw(20)<<" "<<"输入0返回上一层：";
	string str;
	while(cin>>str)
	{
		if(str == "0") break;
		else cout<<endl<<endl<<setw(15)<<" "<<"输入错误！按0返回上一层：";
	}
}
