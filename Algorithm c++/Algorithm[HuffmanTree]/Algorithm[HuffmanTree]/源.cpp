#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<conio.h>
#include<deque>     //队列
#include<list>       //列表容器
#include<set>        //集合容器，多重集合容器
#include<windows.h>   //windows相关函数，窗体函数库
#include<iostream>   // I/O
#include<queue>      //队列
#include<vector>     
#include<stack>       //堆
#include<iomanip>     //目前包含4个函数：【setw(n)是设置域宽，就是要输出几个字符】【setfill(char c)括号中的字符要用单引号！ 用法 : 就是在预设宽度中如果                        已存在没用完的宽度大小，则用设置的字符c填充,注意顺序！！】  【setbase(int n) : 将数字转换为 n 进制,直接在加<<要输出的数即可】             【setprecision(n)可控制输出流显示浮点数的数字个数。C++默认的流输出数值有效位是6。setiosflags(ios::fixed)合用，可以控制小数点右边的数字个数】
#include<process.h>   
#include<dos.h> 
#include<cctype>   //isalpha()等
#include<map>      //映射
#include<string>    //字符串
#include<sstream>   //引用istringstream
#include<cstddef>   //size_t  ptrdiff_t类型的定义
#include<numeric>    //通用数值算法
#include<iterator>     //迭代器类，迭代器适配器


using namespace std;

#define LEAFNUM 10
#define HUFNUM LEAFNUM*2  
#define MAXNUM 999

class HufTree;

class NODE
{
private:
	char Data;
	double Weight;
	int Parent;
	int Lchild;
	int Rchild;
public:
	NODE()
	{
	    Data = '\0';
		Weight = 0;
		Parent = -1;
		Lchild = -1;
		Rchild = -1;
	}
	int Re_Lchild(){return Lchild;}
	int Re_Rchild(){return Rchild;}
	char Re_Data(){return Data;}
	double Re_Weight(){return Weight;}
	friend class HufTree;
};

class HufTree
{
private:
	int NodeNum;
	NODE HufArray[HUFNUM];
public:
	HufTree(){NodeNum = 0;}
	void SetTree(int i,double weight,char data);
	void CreateHufTree();
	void SelectMin(int i,int &p1,int &p2);
	void FindRoot();
	void PrintHufTree(int root);
};

void HufTree::SetTree(int i,double weight,char data)
{
	HufArray[i].Data = data;
	HufArray[i].Weight = weight;
}

void HufTree::CreateHufTree()
{
	cout << "查找权值最小的结点： " << endl;
	for(int i = LEAFNUM; i < HUFNUM - 1 ; i++)
	{
	    int p1 = 0;
	    int p2 = 0;
		SelectMin(i,p1,p2);
		cout << p1 << "     <-->      " << p2 << endl;
		HufArray[p1].Parent = i;
		HufArray[p2].Parent = i;
		HufArray[i].Lchild = p1;
		HufArray[i].Rchild = p2;
		HufArray[i].Weight = HufArray[p1].Weight + HufArray[p2].Weight;
	}
	cout << "*********************" << endl;
}

void HufTree::SelectMin(int i , int &p1, int &p2)
{
	int least1 = MAXNUM;
	int least2 = MAXNUM;
	for(int j = 0; j < i ; j++)
	{
		if(HufArray[j].Parent == -1)
		{
			if(HufArray[j].Weight < least1)
			{
				least2 = least1;
				least1 = HufArray[j].Weight;
				p2 = p1;
				p1 = j;
			}
			else
			{
				if(HufArray[j].Weight < least2)
				{
					least2 = HufArray[j].Weight;
					p2 = j;
				}
			}
		}
	}
}

void HufTree::FindRoot()
{
	int root;
	for(int i = 0 ; i < HUFNUM - 1; i++)
	{
		if(HufArray[i].Parent == -1)
		{
		    root = i;
			break;
		}
	}
	PrintHufTree(root);
}

void HufTree::PrintHufTree(int position)
{
	if(NodeNum == LEAFNUM)
	{
	    return;
	}
	else
	{
		if(HufArray[position].Data != '\0')
		{
			cout << "权值：" << HufArray[position].Weight << "    数值：" << HufArray[position].Data << "    这是叶节点" << endl;
			NodeNum += 1;
		}
		else
		{
			cout << "权值:" << HufArray[position].Weight << "这不是叶节点" << endl;
			PrintHufTree(HufArray[position].Lchild);
			PrintHufTree(HufArray[position].Rchild);
		}
	}
}

void main()
{
	HufTree mm;
	double weight;
	char data;
	cout << "输入" << LEAFNUM << "个节点（权值，数值）:" << endl;
	for(int i = 0; i < LEAFNUM ; i++)
	{
	    cin >> weight >> data;
		mm.SetTree(i,weight,data);
	}
	mm.CreateHufTree();
	mm.FindRoot();
}
