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

#define  MAXV  100 
#define  INF  32767 

typedef int InfoType; 
typedef int Vertex; 

typedef struct 
{    
	int no;              
	InfoType info;            
} VertexType;             



//顶点类型
typedef struct  
{    
	int edges[MAXV][MAXV]; 
	int n,e; 
	VertexType vexs[MAXV]; 
}MGraph;                         



//图类型
void Ppath(int path[][MAXV], int i, int j) 
{   
	int k; 
	k = path[i][j];
	if (k == -1)  
		return;             
	//递归出口
	Ppath(path,i,k);               
	cout << k << "  ";         
	//输出k          
	Ppath( path , k , j );               
} 

void Dispath(int A[][MAXV],int path[][MAXV],int n) 
{ 
	int i,j; 
	for (i = 0;i < n;i ++) 
		for (j = 0 ;j < n; j++) 
			if (A[i][j] == INF) 
			{  
				if(i != j) cout << "从" << i << "到" << j << "不存在路径\n"; 
			} 
			else 
			{    
				cout << "从" << i << " 到" << j << " 的路径为: " << i << " "; 
				Ppath(path, i, j);  
				cout << j; 
				cout << " \t\t 路径长度为:"<< A[i][j] <<endl; 
			} 
} 

void Floyd(MGraph g) 
{   
	int A[MAXV][MAXV],path[MAXV][MAXV]; 
	int i,j,k; 
	for (i = 0;i < g.n; i++) 
		for (j = 0;j < g.n; j++) 
		{    
			A[i][j] = g.edges[i][j]; 
			path[i][j] = -1; 
		} 
		for (k = 0;k < g.n; k++) 
			for (i = 0;i < g.n; i++) 
				for (j = 0;j < g.n; j++) 
					if (A[i][j] > (A[i][k] + A[k][j])) 
					{ 
						A[i][j] = A[i][k] + A[k][j]; 
						path[i][j] = k;  
					} 
					Dispath(A,path,g.n);                         
//输出最短路径
} 

void DispMat(MGraph g) 
{ 
	int i,j; 
	for(i = 0;i < g.n; i++) 
	{ 
		for(j = 0;j < g.n; j++) 
			if(g.edges[i][j] == INF) 
				cout << setw(3) <<" ∞";
			else 
				cout << setw(3) << g.edges[i][j]; 
		cout << endl; 
	} 
} 

void Floyd(MGraph g); 
void Ppath(int path[][MAXV], int i, int j);
void Dispath(int A[][MAXV],int path[][MAXV],int n); 
void DispMat(MGraph g); 

void main() 
{ 
	int i,j; 
	MGraph g; 
	cout << "输入邻接矩阵g总顶点数g.n和总边g.e："; 
	cin >> g.n >> g.e; 
	cout << "输入邻接矩阵g的元素值：\n"; 
	for(i = 0;i < g.n; i++) 
	{ 
		cout << "第" << i << "行："; 
		for(j = 0;j < g.n; j++) 
			cin >> g.edges[i][j]; 
	} 

	cout << "输出邻接矩阵g：\n"; 
	DispMat(g); 
	cout << "输出每对顶点之间的最短路径：\n"; 
	Floyd(g); 
	cout << endl; 
}  