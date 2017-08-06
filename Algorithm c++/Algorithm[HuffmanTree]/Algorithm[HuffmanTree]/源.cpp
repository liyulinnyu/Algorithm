#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<conio.h>
#include<deque>     //����
#include<list>       //�б�����
#include<set>        //�������������ؼ�������
#include<windows.h>   //windows��غ��������庯����
#include<iostream>   // I/O
#include<queue>      //����
#include<vector>     
#include<stack>       //��
#include<iomanip>     //Ŀǰ����4����������setw(n)�������������Ҫ��������ַ�����setfill(char c)�����е��ַ�Ҫ�õ����ţ� �÷� : ������Ԥ���������                        �Ѵ���û����Ŀ�ȴ�С���������õ��ַ�c���,ע��˳�򣡣���  ��setbase(int n) : ������ת��Ϊ n ����,ֱ���ڼ�<<Ҫ����������ɡ�             ��setprecision(n)�ɿ����������ʾ�����������ָ�����C++Ĭ�ϵ��������ֵ��Чλ��6��setiosflags(ios::fixed)���ã����Կ���С�����ұߵ����ָ�����
#include<process.h>   
#include<dos.h> 
#include<cctype>   //isalpha()��
#include<map>      //ӳ��
#include<string>    //�ַ���
#include<sstream>   //����istringstream
#include<cstddef>   //size_t  ptrdiff_t���͵Ķ���
#include<numeric>    //ͨ����ֵ�㷨
#include<iterator>     //�������࣬������������


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
	cout << "����Ȩֵ��С�Ľ�㣺 " << endl;
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
			cout << "Ȩֵ��" << HufArray[position].Weight << "    ��ֵ��" << HufArray[position].Data << "    ����Ҷ�ڵ�" << endl;
			NodeNum += 1;
		}
		else
		{
			cout << "Ȩֵ:" << HufArray[position].Weight << "�ⲻ��Ҷ�ڵ�" << endl;
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
	cout << "����" << LEAFNUM << "���ڵ㣨Ȩֵ����ֵ��:" << endl;
	for(int i = 0; i < LEAFNUM ; i++)
	{
	    cin >> weight >> data;
		mm.SetTree(i,weight,data);
	}
	mm.CreateHufTree();
	mm.FindRoot();
}
