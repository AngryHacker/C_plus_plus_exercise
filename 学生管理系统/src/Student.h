#include <iostream>
#include <vector>
#include <map>
using namespace std;

class StudentBase
{
private:
	vector<long>mNum;
	vector<string>mName;
	vector<int>mSex;
	vector<int>mAge;
	vector<string>mAddr;
	vector<string>mMajor;
	map<long,int>mPosition;
public:
	void bulidBaseData();
	void modifyData();
	vector<long> getmNum();
	vector<string> getmName();
	vector<int> getmSex();
	vector<int> getmAge();
	vector<string> getmAddr();
	long getNumAtIndex(int);
	string getNameAtIndex(int);
	int getSexAtIndex(int);
	int getAgeAtIndex(int);
	string getAddrAtIndex(int);
	int getmPosition(long);
};

class FirstA: virtual public StudentBase
{
private:
	char mA_MajorDepName[30];
	vector<long>majorA_Num;
	vector<long>secondA_Num;
	vector<string>A_Scond_MajorName;
	vector< vector<int> >mA_FirstScore;
	vector< vector<int> >A_Fscore;
public:
	FirstA();
	void inputA_MajorScore();
	void inputA_SecondScore();
	void outputA_Good();
	void outputA_MajorFail();
	void outputA_SecondFail();
	char *getA_MajorDepName();
	vector<long> getA_MajorNum();
	vector<long>getA_SecondNum();
	vector< vector<int> >getA_FirstScore();
	vector< vector<int> >getA_FScore();
};

class FirstB: virtual public StudentBase
{
private:
	char mB_MajorDepName[30];
	vector<long>majorB_Num;
	vector<long>secondB_Num;
	vector<string>B_Scond_MajorName;
	vector< vector<int> >mB_FirstScore;
	vector< vector<int> >B_Fscore;
public:
	FirstB();
	void inputB_MajorScore();
	void inputB_SecondScore();
	void outputB_Good();
	void outputB_MajorFail();
	void outputB_SecondFail();
	char *getB_MajorDepName();
	vector<long> getB_MajorNum();
	vector<long>getB_SecondNum();
	vector< vector<int> >getB_FirstScore();
	vector< vector<int> >getB_FScore();
};

class FirstC: virtual public StudentBase
{
private:
	char mC_MajorDepName[30];
	vector<long>majorC_Num;
	vector<long>secondC_Num;
	vector<string>C_Scond_MajorName;
	vector< vector<int> >mC_FirstScore;
	vector< vector<int> >C_Fscore;
public:
	FirstC();
	char *getC_MajorDepName();
	void inputC_MajorScore();
	void inputC_SecondScore();
	void outputC_Good();
	void outputC_MajorFail();
	void outputC_SecondFail();
	vector<long> getC_MajorNum();
	vector<long>getC_SecondNum();
	vector< vector<int> >getC_FirstScore();
	vector< vector<int> >getC_FScore();
};

class StudentMIS: public FirstA, public FirstB, public FirstC
{
private:
	int SA,SB,SC;
	int KA,KB,KC;
public:
	StudentMIS();
	void degreeStanderOfFirst();
	void degreeStanderOfSecond();
	void degree();
};
