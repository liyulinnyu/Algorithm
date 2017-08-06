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

//二叉排序树：空树或者是左子树小于根节点，右子树大于根节点，以此循环

//插入结点
#define ARRAYLEN 10
int source[] = {54,90,6,69,12,37,92,28,65,83};
typedef struct bst
{
	int data;
	struct bst *left;
	struct bst *right;
}BSTree;                       //定义二叉树结构
void InsertBST(BSTree *t,int key)
{
	BSTree *p,*parent,*head;
	if(!(p = new BSTree))
	{
		cout << "申请内存失败" << endl;
		exit(0);
	}
	p->data = key;
	p->left = p->right = NULL;
	head = t;
	while(head)                                     //查找需要添加的父结点
	{                                                
		parent = head;
		if(key < head->data)
			head = head->left;
		else
			head = head->right;
	}
	if(key < parent->data)
		parent ->left = p;
	else
		parent->right = p;
}
void CreateBST(BSTree *t,int data[],int n)               //将数组中的数据插入二叉排序树
{
	int i;
	t->data = data[0];                    //根节点赋值
	t->left = t->right = NULL;
	for(i = 1;i < n;i++)
		InsertBST(t,data[i]);
}

void BST_LDR(BSTree *t)                  //用中序遍历检查创建二叉排序树是否成功
{
	if(t)
	{
		BST_LDR(t->left);                           //中序遍历左子树
		cout << t->data << " ";                            //输出数据
		BST_LDR(t->right);                          //中序遍历右子树，递归的过程
	}
}


//查找结点

BSTree *SearchBST(BSTree *t,int key)
{
	if(!t || t->data == key)
		return t;
	else if(key > t->data)
		return(SearchBST(t->right,key));
	else
		return(SearchBST(t->left,key));
}

//删除结点
//三种情况，1是删除叶结点，简单删去即可
           //2是删除的结点有一个子树，只需修改结点的父结点，使其子结点指针的值为left或right
           //3是有两个子树，需中序遍历出所有后继结点，需要找出这个结点右子树，最左侧的叶结点，来代替它。
void BST_Delete(BSTree *t,int key)
{
	BSTree *p,*parent,*l,*ll;
	int child = 0;
	if(!t) return;
	p = t;
	parent = p;
	while(p)
	{
		if(p-> data == key)
		{
			if(!p->left && !p->right)
			{
				if(p == t)
				{
					free(p);
				}
				else if(child == 0)
				{
					parent->left = NULL;
					free(p);
				}
				else
				{
					parent->right = NULL;
					free(p);
				}
			}
			else if(!p->left)
			{
				if(child == 0)
					parent->left = p->right;
				else
					parent->right = p->left;
				free(p);
			}
			else if(!p->right)
			{
				if(child == 0)
					parent->left = p->right;
				else
					parent->right = parent->left;
				free(p);
			}
			else
			{
				ll = p;
				l = p->right;
				while(l->left)
				{
					ll = l;
					l = l->left;
				}
				p->data = l->data;
				ll ->left = NULL;
				free(ll);
			}
			p = NULL;
		}
		else if(key < p->data)
		{
			child = 0;
			parent = p;
			p = p->left;
		}
		else
		{
			child = 1;
			parent = p;
			p = p->right;
		}
	}
}


int main()
{
	int i,key;
	BSTree bst,*pos;
	cout << "原数据：";
	for(i = 0;i < ARRAYLEN;i++)
		cout << source[i] << " ";
	cout << endl;
	CreateBST(&bst,source,ARRAYLEN);
	cout << "遍历二叉排序树：";
	BST_LDR(&bst);
	cout << "\n输入关键字：";
	cin >> key;
	pos = SearchBST(&bst,key);
	if(pos)
		cout << "查找成功，地址是：" << pos << endl;
	else
		cout <<"查找失败！\n";
	cout << "输入要删去的结点值：";
	cin >> key;
	BST_Delete(&bst,key);
	cout << "\n删除结点后的结点：";
	BST_LDR(&bst);
	getch();
	return 0;

}





