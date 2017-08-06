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


#define VERTEX_MAX 26                            //图最大顶点数
#define MAXVALUE 32767                           //最大值

typedef struct
{
	char Vertex[VERTEX_MAX];                   //保存顶点信息
	int Edges[VERTEX_MAX][VERTEX_MAX];         //保存边的权
	int isTrav[VERTEX_MAX];                    //遍历标志

	int VertexNum;                             //顶点数量

	int EdgeNum;                               //边数量

	int GraphType;                             //图类型(0:无向图, 1:有向图)
}MatrixGraph;


void Createlin(MatrixGraph *G);                //创建邻接矩阵
void Outlin(MatrixGraph *G);                   //输出邻接矩阵

void Createlin(MatrixGraph *G)
{
	int j,k,weight;
	char start,end;
	for(int i = 0;i < G->VertexNum ; i++)
	{
	    cout << "输入第" << i+1 << "个顶点的信息：" << " ";
		cin >> G->Vertex[i] ;
	}
	for(int i = 0; i < G->EdgeNum ; i++)
	{
	    cout << "输入第" << i+1 << "条边的开始节点值，结束节点值，权：" << " ";
		cin >> start >> end >> weight;
		for(j = 0; start != G->Vertex[j]; j++);
		for(k = 0; end != G->Vertex[k]; k++);
		G->Edges[j][k] = weight;
		if(G->GraphType == 0)
		{
		    G->Edges[k][j] = weight;
		}
	}
}

void Outlin(MatrixGraph *G)
{
	cout << "邻接矩阵如下：" << endl;
	for(int i = 0;i < G->VertexNum; i++)
	{
		cout << "\t" << G->Vertex[i];
	}
	cout << endl;
	for(int i = 0;i < G->VertexNum ; i++)
	{
		cout << G->Vertex[i];
		for(int j = 0; j < G->VertexNum ; j++)
		{
			
			if(G->Edges[i][j] == MAXVALUE)
			{
			    cout << "\t∞";
			}
			else
			{
				cout << "\t" << G->Edges[i][j];
			}
		}
		cout << endl;
	}

}

void main()
{
	MatrixGraph G;
	cout << "输入图类型（0.无向图 1.有向图）：" << " ";
	cin >> G.GraphType;
	cout << "输入顶点数量，边数量：" << " ";
	cin >> G.VertexNum >> G.EdgeNum;
	for(int i = 0;i < G.VertexNum; i++)
		for(int j = 0; j < G.VertexNum; j++)
			G.Edges[i][j] = MAXVALUE;
	Createlin(&G);
	Outlin(&G);
	getch();
}