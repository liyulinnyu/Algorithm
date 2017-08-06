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
#define QUEUE_MAXSIZE 50                                          //                    线索二叉树生成
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

void BinTreeThreading_LDR(ThreadBinTree *bt)           //二叉树按中序线索化
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

ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt)//求指定结点的后继
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
	//遍历二叉树
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
	    cout << "输入根节点数据：" << " ";
		cin >> node->data;
		node->left = NULL;
		node->right = NULL;
		return BinTreeInit(node);
	}
	return NULL;
}

int BinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n) //bt为父结点，node为子节点，n=1表示添加左子树，n=2添加右子树
{
	if(!bt)
	{
	    cout << "请先设置根节点！" << endl;
		return 0;
	}
	switch(n)
	{
	case 1:
		if(bt->left)
		{
		    cout << "左节点不为空" << endl;
			return 0;
		}
		else
			bt->left = node;
		break;
	case 2:
		if(bt->right)
		{
		    cout << "右节点不为空" << endl;
			return 0;
		}
		else
			bt->right = node;
		break;
	default:
		cout << "参数错误" << endl;
		return 0;
	}
	return 1;
}

ThreadBinTree *BinTreeFind(ThreadBinTree *bt,DATA data)            //查找data值的点
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
	    cout << "输入要增加的节点数值：" << " ";
		fflush(stdin);
		cin >> node->data;
		node->left = NULL;
		node->right = NULL;
		cout << "输入父结点的值：" << " ";
		fflush(stdin);
		cin >> data;
		parent = BinTreeFind(bt,data);
		if(!parent)
		{
		    cout << "没有对应的父结点" << endl;
			delete node;
			return;
		}
		do
		{
		    cout << "选择增加在 1.左节点 2.右节点" << " ";
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
		delete bt;      //删除指向的节点数据
		bt = NULL;      //防止野指针的出现
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
		cout << "\n1.设置二叉树根元素              2.添加二叉树结点\n";
		cout << "3.生成中序线索二叉树            4.遍历线索二叉树\n";
		cout << "0.退出\n";
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
			cout << "\n生成中序线索二叉树完毕\n";
			break;
		case '4':
			cout << "\n中序线索二叉树遍历结果：";
			ThreadBinTree_LDR(root,oper1);
			cout << endl;
			break;
		case '0':
			break;
        }
	}while(select != '0');
		BinTreeClear(root);
	root = NULL;                      //避免野指针
	getch();
	return 0;
}