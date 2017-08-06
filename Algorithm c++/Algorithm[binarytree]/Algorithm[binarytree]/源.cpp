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
#include<queue>                                                                                                            //����
#include<vector>     
#include<stack>                                                                                                             //��
#include<iomanip>     //Ŀǰ����4����������setw(n)�������������Ҫ��������ַ�����setfill(char c)�����е��ַ�Ҫ�õ����ţ� �÷� : ������Ԥ���������                        �Ѵ���û����Ŀ�ȴ�С���������õ��ַ�c���,ע��˳�򣡣���  ��setbase(int n) : ������ת��Ϊ n ����,ֱ���ڼ�<<Ҫ����������ɡ�             ��setprecision(n)�ɿ����������ʾ�����������ָ�����C++Ĭ�ϵ��������ֵ��Чλ��6��setiosflags(ios::fixed)���ã����Կ���С�����ұߵ����ָ�����
#include<process.h>   
#include<dos.h> 
#include<cctype>               //isalpha()��
#include<map>                                                                            //ӳ��
#include<string>                                               //�ַ���
#include<sstream>                                                          //����istringstream
#include<cstddef>                                              //size_t  ptrdiff_t���͵Ķ���
#include<numeric>                                                  //ͨ����ֵ�㷨
#include<iterator>                     //�������࣬������������

using namespace std;

#define QUEUE_MAXSIZE 50
typedef char DATA;
typedef struct ChainTree
{
	DATA data;
	struct ChainTree *left;
	struct ChainTree *right;
}ChainBinTree;

ChainBinTree *BinTreeInit(ChainBinTree *node)
{
	if(node != NULL)
		return node;
	else 
		return NULL;
}

int BinTreeAddNode(ChainBinTree *bt,ChainBinTree *node,int n) //btΪ����㣬nodeΪ�ӽڵ㣬n=1��ʾ�����������n=2���������
{
	if(bt == NULL)
	{
		cout << "����㲻���ڣ��������ø����\n";
		return 0;
	}
	switch(n)
	{
	case 1:
		if(bt -> left)
		{
			cout << "��������㲻Ϊ��\n";
			return 0;
		}
		else
			bt -> left = node;
		break;
	case 2:
		if(bt -> right)
		{
			cout << "��������㲻Ϊ��\n";
			return 0;
		}
		else
			bt -> right = node;
		break;
	default:
		cout << "��������\n";
		return 0;
	}
	return 1;
}

ChainBinTree *BinTreeLeft(ChainBinTree *bt)
{
	if(bt)
		return bt -> left;
	else
		return NULL;
}

ChainBinTree *BinTreeRight(ChainBinTree *bt)
{
	if(bt)
		return bt -> right;
	else
		return NULL;
}
//��ȡ״̬��������ȵ�
int BinTreeIsEmpty(ChainBinTree *bt)
{
	if(bt)
		return 0;
	else
		return 1;
}

int BinTreeDepth(ChainBinTree *bt)
{
	int dep1,dep2;
	if(bt == NULL)
		return 0;
	else
	{
		dep1 = BinTreeDepth(bt -> left);   //�ݹ����
		dep2 = BinTreeDepth(bt -> right);
		if(dep1 > dep2)
			return dep1 + 1;
		else
			return dep2 + 1;
	}
}
//����������
ChainBinTree *BinTreeFind(ChainBinTree *bt,DATA data)//����dataֵ�ĵ�
{
	ChainBinTree *p;
	if(bt == NULL)
		return NULL;
	else
	{
		if(bt ->data == data)
			return bt;
		else   //�ֱ������������ݹ����
		{
			if(p = BinTreeFind(bt ->left,data))
				return p;
			else if(p = BinTreeFind(bt ->right ,data))
				return p;
			else
				return NULL;
		}
	}
}
//�����
void BinTreeClear(ChainBinTree *bt)
{
	if(bt)
	{
		BinTreeClear(bt -> left);    //�����������
		BinTreeClear(bt -> right);
		free(bt);                    //�ͷŵ�ǰ���
		bt = NULL;
	}
	return;
}
//�������
void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *p))  //����ָ��oper��һ����Ҫ�Խ����в����ĺ�����oper����һ�������������б�д
{                                                                   //�Ա�Խ����в�ͬ�Ĳ�������ָ��oper������ָ�봫�ݵ�������������
	if(bt)
	{
		oper(bt);
		BinTree_DLR(bt->left,oper);
		BinTree_DLR(bt->right,oper);
	}
	return;
}
//�������
void BinTree_LDR(ChainBinTree *bt,void (*oper)(ChainBinTree *p))
{
	if(bt)
	{
		BinTree_DLR(bt->left,oper);
		oper(bt);
		BinTree_DLR(bt->right,oper);
	}
	return;
}
//�������
void BinTree_LRD(ChainBinTree *bt,void (*oper)(ChainBinTree *p))
{
	if(bt)
	{
		BinTree_DLR(bt->left,oper);
		BinTree_DLR(bt->right,oper);
		oper(bt);
	}
	return;
}
//�������
void BinTree_Level(ChainBinTree *bt,void (*oper)(ChainBinTree *p))
{
	
	ChainBinTree *p;
	ChainBinTree *q[QUEUE_MAXSIZE];
	int head = 0,tail = 0;
	if(bt)
	{
		tail = (tail + 1)%QUEUE_MAXSIZE;//����ѭ�����е�β���
		q[tail] = bt;                   //��������ָ�����
	}
	while(head != tail)
	{
		head = (head + 1)%QUEUE_MAXSIZE;  //����������
		p = q[head];   //�����Ԫ��
		oper(p);
		if(p -> left != NULL)   //����������������������
		{
			tail = (tail + 1 )%QUEUE_MAXSIZE;
			q[tail] = p->left;
		}
		if(p->right != NULL)
		{
			tail = (tail + 1)%QUEUE_MAXSIZE;
			q[tail] = p->right;
		}
	}
	return;
}




void oper(ChainBinTree *p)
{
	cout << p->data;
	return;
}

ChainBinTree *InitRoof()                 //��ʼ��������
{
	ChainBinTree *node;
	if(node = new ChainBinTree)
	{
		cout << "\n������������:";
		cin >> node->data;
		node ->left = NULL;
		node ->right = NULL;
		return node;
	}
	return NULL;
}

void AddNode(ChainBinTree *bt)
{
	ChainBinTree *node,*parent;
	DATA data;
	char select;
	if(node = new ChainBinTree)
	{
		cout << "\n����������������:";
		fflush(stdin);
		cin >> node->data;
		node ->left = NULL;
		node -> right = NULL;
		cout << "���븸������ݣ�";
		fflush(stdin);
		cin >> data;
		parent = BinTreeFind(bt ,data);
		if(!parent)
		{
			cout << "δ�ҵ������\n";
			delete node;
			return;
		}
		cout << "1.��ӵ�������\n 2.��ӵ�������\n";
		do
		{
			select = getch();
			select -= '0';
			if(select == 1||select == 2)
				BinTreeAddNode(parent,node,select);
         }while(select != 1&& select != 2);
    }
	return;
}


int main()
{

	ChainBinTree *root = NULL;
	char select;
	void (*oper1)(ChainBinTree *bt);
	oper1 = oper;
	do
	{
		cout << "\n1.���ö�������Ԫ��          2.��Ӷ��������              3.�������           4.�������  \n";
		cout << "5.�������                   6.�������                7.���������              0.�˳�\n";
	
		select = getch();
		switch(select)
		{
		case '1':
			root = InitRoof();
			break;
		case '2':
			AddNode(root);
			break;
		case '3':
			cout << "\n����������:";
			BinTree_DLR(root,oper1);
			cout << "\n";
			break;
		case '4':
			cout << "\n����������:";
			BinTree_LDR(root,oper1);
			cout << "\n";
			break;
		case '5':
			cout << "\n����������:";
			BinTree_LRD(root,oper1);
			cout << "\n";
			break;
		case '6':
			cout << "\n����������:";
			BinTree_Level(root,oper1);
			cout << "\n";
			break;
		case '7':
			cout << "\n���������Ϊ��" << BinTreeDepth(root);
			break;
		case '0':
			break;
		}
	}while(select != '0');
	BinTreeClear(root);
	root = NULL;
	getch();
	return 0;

}