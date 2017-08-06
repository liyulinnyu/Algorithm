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
#include<queue>                                                                                                            //队列
#include<vector>     
#include<stack>                                                                                                             //堆
#include<iomanip>     //目前包含4个函数：【setw(n)是设置域宽，就是要输出几个字符】【setfill(char c)括号中的字符要用单引号！ 用法 : 就是在预设宽度中如果                        已存在没用完的宽度大小，则用设置的字符c填充,注意顺序！！】  【setbase(int n) : 将数字转换为 n 进制,直接在加<<要输出的数即可】             【setprecision(n)可控制输出流显示浮点数的数字个数。C++默认的流输出数值有效位是6。setiosflags(ios::fixed)合用，可以控制小数点右边的数字个数】
#include<process.h>   
#include<dos.h> 
#include<cctype>               //isalpha()等
#include<map>                                                                            //映射
#include<string>                                               //字符串
#include<sstream>                                                          //引用istringstream
#include<cstddef>                                              //size_t  ptrdiff_t类型的定义
#include<numeric>                                                  //通用数值算法
#include<iterator>                     //迭代器类，迭代器适配器

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

int BinTreeAddNode(ChainBinTree *bt,ChainBinTree *node,int n) //bt为父结点，node为子节点，n=1表示添加左子树，n=2添加右子树
{
	if(bt == NULL)
	{
		cout << "父结点不存在，请先设置父结点\n";
		return 0;
	}
	switch(n)
	{
	case 1:
		if(bt -> left)
		{
			cout << "左子树结点不为空\n";
			return 0;
		}
		else
			bt -> left = node;
		break;
	case 2:
		if(bt -> right)
		{
			cout << "右子树结点不为空\n";
			return 0;
		}
		else
			bt -> right = node;
		break;
	default:
		cout << "参数错误！\n";
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
//获取状态：计算深度等
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
		dep1 = BinTreeDepth(bt -> left);   //递归调用
		dep2 = BinTreeDepth(bt -> right);
		if(dep1 > dep2)
			return dep1 + 1;
		else
			return dep2 + 1;
	}
}
//二叉树查找
ChainBinTree *BinTreeFind(ChainBinTree *bt,DATA data)//查找data值的点
{
	ChainBinTree *p;
	if(bt == NULL)
		return NULL;
	else
	{
		if(bt ->data == data)
			return bt;
		else   //分别向左右子树递归查找
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
//清空树
void BinTreeClear(ChainBinTree *bt)
{
	if(bt)
	{
		BinTreeClear(bt -> left);    //清空左右子树
		BinTreeClear(bt -> right);
		free(bt);                    //释放当前结点
		bt = NULL;
	}
	return;
}
//先序遍历
void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *p))  //函数指针oper是一个需要对结点进行操作的函数，oper函数一般在主调程序中编写
{                                                                   //以便对结点进行不同的操作，将指向oper函数的指针传递到遍历函数即可
	if(bt)
	{
		oper(bt);
		BinTree_DLR(bt->left,oper);
		BinTree_DLR(bt->right,oper);
	}
	return;
}
//中序遍历
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
//后序遍历
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
//按层遍历
void BinTree_Level(ChainBinTree *bt,void (*oper)(ChainBinTree *p))
{
	
	ChainBinTree *p;
	ChainBinTree *q[QUEUE_MAXSIZE];
	int head = 0,tail = 0;
	if(bt)
	{
		tail = (tail + 1)%QUEUE_MAXSIZE;//计算循环队列的尾序号
		q[tail] = bt;                   //二叉树根指针进队
	}
	while(head != tail)
	{
		head = (head + 1)%QUEUE_MAXSIZE;  //计算队首序号
		p = q[head];   //获得首元素
		oper(p);
		if(p -> left != NULL)   //有左子树，则左子树进队
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

ChainBinTree *InitRoof()                 //初始化二叉树
{
	ChainBinTree *node;
	if(node = new ChainBinTree)
	{
		cout << "\n输入根结点数据:";
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
		cout << "\n输入二叉树结点数据:";
		fflush(stdin);
		cin >> node->data;
		node ->left = NULL;
		node -> right = NULL;
		cout << "输入父结点数据：";
		fflush(stdin);
		cin >> data;
		parent = BinTreeFind(bt ,data);
		if(!parent)
		{
			cout << "未找到父结点\n";
			delete node;
			return;
		}
		cout << "1.添加到左子树\n 2.添加到右子树\n";
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
		cout << "\n1.设置二叉树根元素          2.添加二叉树结点              3.先序遍历           4.中序遍历  \n";
		cout << "5.后序遍历                   6.按层遍历                7.二叉树深度              0.退出\n";
	
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
			cout << "\n先序遍历结果:";
			BinTree_DLR(root,oper1);
			cout << "\n";
			break;
		case '4':
			cout << "\n中序遍历结果:";
			BinTree_LDR(root,oper1);
			cout << "\n";
			break;
		case '5':
			cout << "\n后序遍历结果:";
			BinTree_LRD(root,oper1);
			cout << "\n";
			break;
		case '6':
			cout << "\n安层遍历结果:";
			BinTree_Level(root,oper1);
			cout << "\n";
			break;
		case '7':
			cout << "\n二叉树深度为：" << BinTreeDepth(root);
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