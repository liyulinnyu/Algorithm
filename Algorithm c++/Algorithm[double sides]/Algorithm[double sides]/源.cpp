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

#define VERTEX_MAX 26
#define MAXVALUE 32767
typedef struct
{
	char Vertex[VERTEX_MAX];
	int Edges[VERTEX_MAX][VERTEX_MAX];
	int isTrav[VERTEX_MAX];
	int VertexNum;
	int EdgeNum;
	int GraphType;
}MatrixGraph;
void CreateMatrixGraph(MatrixGraph *G);
void OutMatrix(MatrixGraph *G);

void CreateMatrixGraph(MatrixGraph *G)
{
	int i,j,k,weight;
	char start,end;
	cout << "输入各顶点信息：\n";
	for(i = 0; i < G->VertexNum ; i++)
	{
		getchar();
		cout << "第" << i+1 << "个顶点:";
		cin >> G->Vertex[i];
	}
	cout << "输入构成各边的两个顶点及权值（空格分离）:\n";
	for(k = 0;k< G->EdgeNum ; k++)
	{
		getchar();
		cout << "第" << k + 1<< "条边：";
		cin >> start >> end >> weight;
		for(i = 0;start != G->Vertex[i]; i++);
		for(j = 0;end!=G->Vertex[j] ;j++);
		G->Edges[i][j] = weight;
		if(G->GraphType == 0)
			G->Edges[j][i] = weight;
	}
}

void OutMatrix(MatrixGraph *G)
{
	int i,j;
	for(j = 0;j < G->VertexNum; j++)
		cout <<'\t'<< G->Vertex[j];
	cout << endl;
	for(i = 0; i< G->VertexNum ; i++)
	{
		cout << G->Vertex[i];
		for(j = 0;j < G->VertexNum;j++)
		{
			if(G->Edges[i][j] == MAXVALUE)
				cout << '\t';
			else
				cout << '\t' << G->Edges[i][j];
		}
		cout << endl;
	}
}

int main()
{
	MatrixGraph G;
	int i,j;
	cout << "输入生成图的类型（0：无向，1：有向）：";
	cin >> G.GraphType;
	cout << "输入图的顶点数量和边的数量:";
	cin >> G.VertexNum >> G.EdgeNum;
	for(i = 0;i < G.VertexNum;i++)
		for(j = 0; j< G.VertexNum ;j++)
			G.Edges[i][j] = MAXVALUE;
	CreateMatrixGraph(&G);
	cout << "领接矩阵如下：\n";
	OutMatrix(&G);
	getch();
	return 0;
}