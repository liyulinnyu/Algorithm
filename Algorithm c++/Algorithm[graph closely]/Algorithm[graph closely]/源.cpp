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

#define VERTEX_MAX 20

typedef struct edgeNode
{
	int Vertex;
	int weight;
	struct edgeNode *next;
}EdgeNode;

typedef struct 
{
	EdgeNode * AdjList[VERTEX_MAX];
	int VextexNum ,EdgeNum;
	int GraphType;
}ListGraph;
void CreateGraph(ListGraph *G);
void OutList(ListGraph *G);

void CreateGraph(ListGraph *G)
{
	int i,weight;
	int start,end;
	EdgeNode *s;
	for(i = 1;i<=G->VextexNum;i++)
		G->AdjList[i] = NULL;
	for(i =1;i<=G->EdgeNum;i++)
	{
		getchar();
		cout << "第" << i << "条边:";
		cin >> start >> end >> weight;
		s = new EdgeNode;
		s->next = G->AdjList[start];
		s->Vertex = end;
		s->weight = weight;
		G->AdjList[start] = s;
		if(G->GraphType == 0)
		{
			s = new EdgeNode;
			s->next = G->AdjList[end];
			s->Vertex = start;
			s->weight = weight;
			G->AdjList[end] =s;
		}
	}
}

void OutList(ListGraph *G)
{
	int i;
	EdgeNode *s;
	for(i =1;i<=G->VextexNum;i++)
	{
		cout << "顶点" << i << ":";
		s = G->AdjList[i];
		while(s)
		{
			cout << "->" << s->Vertex <<"(" << s->weight << ")";
			s =s->next;
		}
		cout << endl;
	}
}

int main()
{
	ListGraph G;
	cout << "输入生成图的类型（0：无向图，1：有向图）:";
	cin >> G.GraphType;
	cout << "输入图的顶点数量和边数量：";
	cin >> G.VextexNum >> G.EdgeNum;
	cout << "输入构成各边的两个顶点及权值（空格分开）：\n";
	CreateGraph(&G);
	cout << "输出图的领接表：\n";
	OutList(&G);
	getch();
	return 0;
}