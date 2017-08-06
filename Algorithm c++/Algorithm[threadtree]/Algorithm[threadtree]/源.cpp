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
#define QUEUE_MAXSIZE 50                                          //                    ��������������
typedef char DATA;
typedef enum
{
	SubTree = 0,
	Thread = 1
}NodeFlag;
typedef struct ThreadTree
{
	DATA data;
	NodeFlag lflag;
	NodeFlag rflag;
	struct ThreadTree *left;
	struct ThreadTree *right;
}ThreadBinTree;
ThreadBinTree *Previous = NULL;

void BinTreeThreading_LDR(ThreadBinTree *bt)           //������������������
{
	if(bt)
	{
		BinTreeThreading_LDR(bt->left);
		bt->lflag = bt->left?SubTree:Thread;
		bt->rflag = bt->right?SubTree:Thread;
		if(Previous)
		{
			if(Previous->rflag == Thread)
				Previous->right = bt;
			if(bt->lflag == Thread)
				bt->left = Previous;
		}
		Previous = bt;
		BinTreeThreading_LDR(bt->right);
	}
}

ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt)//��ָ�����ĺ��
{
	ThreadBinTree *nextNode = NULL;
	if(!bt)
		return NULL;
	if(bt->rflag == Thread)
		return bt->right;
	else
	{
		nextNode = bt->right;
		while(nextNode->lflag == SubTree)
			nextNode = nextNode->left;
		return nextNode;
	}

}

ThreadBinTree *BinTreePrevious_LDR(ThreadBinTree *bt)
{
	ThreadBinTree *preNode = NULL;
	if(!bt)
		return NULL;
	if(bt->lflag == Thread)
		return bt->left;
	else
	{
		preNode = bt->left;
		while(preNode->lflag == SubTree)
			preNode = preNode->left;
		return preNode;
	}
}

void ThreadBinTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p))
	//����������
{
    if(bt)
	{
		while(bt->lflag == SubTree)
			bt = bt->left;
		do
		{
		    oper(bt);
			bt = BinTreeNext_LDR(bt);
		}while(bt);
	}
}

void oper(ThreadBinTree *p)
{
	cout << p->data << " ";
}

ThreadBinTree *BinTreeInit(ThreadBinTree *node)
{
	if(node!=NULL)
		return node;
	else
		return NULL;
}

ThreadBinTree *InitRoot()
{
	ThreadBinTree *node;
	if(node = new ThreadBinTree)
	{
	    cout << "������ڵ����ݣ�" << " ";
		cin >> node->data;
		node->left = NULL;
		node->right = NULL;
		return BinTreeInit(node);
	}
	return NULL;
}

int BinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n) //btΪ����㣬nodeΪ�ӽڵ㣬n=1��ʾ�����������n=2���������
{
	if(!bt)
	{
	    cout << "�������ø��ڵ㣡" << endl;
		return 0;
	}
	switch(n)
	{
	case 1:
		if(bt->left)
		{
		    cout << "��ڵ㲻Ϊ��" << endl;
			return 0;
		}
		else
			bt->left = node;
		break;
	case 2:
		if(bt->right)
		{
		    cout << "�ҽڵ㲻Ϊ��" << endl;
			return 0;
		}
		else
			bt->right = node;
		break;
	default:
		cout << "��������" << endl;
		return 0;
	}
	return 1;
}

ThreadBinTree *BinTreeFind(ThreadBinTree *bt,DATA data)            //����dataֵ�ĵ�
{
	ThreadBinTree *p;
	if(bt == NULL)
		return NULL;
	if(bt->data == data)
		return bt;
	else
	{
		if(p = BinTreeFind(bt->left,data))
			return p;
		else if(p = BinTreeFind(bt->right,data))
			return p;
		else
			return NULL;
	}
}

void AddNode(ThreadBinTree *bt)
{
	ThreadBinTree *node,*parent;
	DATA data;
	char select;
	if(node = new ThreadBinTree)
	{
	    cout << "����Ҫ���ӵĽڵ���ֵ��" << " ";
		fflush(stdin);
		cin >> node->data;
		node->left = NULL;
		node->right = NULL;
		cout << "���븸����ֵ��" << " ";
		fflush(stdin);
		cin >> data;
		parent = BinTreeFind(bt,data);
		if(!parent)
		{
		    cout << "û�ж�Ӧ�ĸ����" << endl;
			delete node;
			return;
		}
		do
		{
		    cout << "ѡ�������� 1.��ڵ� 2.�ҽڵ�" << " ";
			select = getch();
			select -= '0';
			if(select == 1 || select == 2)
				BinTreeAddNode(parent,node,select);
		}while(select != 1 && select != 2);
	}
}

void BinTreeClear(ThreadBinTree *bt)
{
	if(bt)
	{
		BinTreeClear(bt->left);
		BinTreeClear(bt->right);
		delete bt;      //ɾ��ָ��Ľڵ�����
		bt = NULL;      //��ֹҰָ��ĳ���
	}
	return;
}

int main()
{
	ThreadBinTree *root = NULL;
	char select;
	void (*oper1)(ThreadBinTree *p);
	oper1 = oper;                                      
	do
	{
		cout << "\n1.���ö�������Ԫ��              2.��Ӷ��������\n";
		cout << "3.������������������            4.��������������\n";
		cout << "0.�˳�\n";
		select = getch();
		switch(select)
		{
		case '1':
			root = InitRoot();
			break;
		case '2':
			AddNode(root);
			break;
		case '3':
			BinTreeThreading_LDR(root);
			cout << "\n���������������������\n";
			break;
		case '4':
			cout << "\n�����������������������";
			ThreadBinTree_LDR(root,oper1);
			cout << endl;
			break;
		case '0':
			break;
        }
	}while(select != '0');
		BinTreeClear(root);
	root = NULL;                      //����Ұָ��
	getch();
	return 0;
}