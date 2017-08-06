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

#define MAXVALUE 32767                           //最大值

class MatrixGraph
{
private:
	char Vertex[15];
	int Edges[15][15];
	int isTrav[15];
	int VertexNum;
	int EdgeNum;
	int GraphType;
public:
	void Createlin();
	void Showlin(MatrixGraph *G);
	void Dijkstra(MatrixGraph *G);
	void Floyd(MatrixGraph *G);
};

void MatrixGraph :: Createlin()
{
	MatrixGraph *G;
	G = new MatrixGraph;
	cout << "输入生成图的类型（0.无向图，1.有向图）：" << " ";
	cin >> G->GraphType;
	cout << "输入图的顶点数量和边数量：" << " ";
	cin >> G->VertexNum >> G->EdgeNum;
	for(int i = 0 ; i < G->VertexNum; i ++)
		for(int j = 0; j < G->VertexNum; j++)
			G->Edges[i][j] = MAXVALUE;
	
	char start,end;
	int	weight,m,n;
	for(int i = 0 ; i < G->VertexNum; i++)
	{
	    cout << "输入第"  << i+1 << "个节点的值：" << " ";
		cin >> G->Vertex[i];
	}
	for(int k = 0 ; k < G->EdgeNum; k++)
	{
	    cout << "输入第" << k + 1 << "条边的起点，终点，权值：" << ' ';
		cin >> start >> end >> weight;
		for(m = 0; start != G->Vertex[m] ;m++);
		for(n = 0; end != G->Vertex[n] ; n++);
		G->Edges[m][n] = weight;
		if(G->GraphType == 0)
			G->Edges[n][m] = weight;
	}

	cout << "邻接矩阵：" <<endl;
	Showlin(G);
	cout << "Dijkstra算法输出：" << endl;
	Dijkstra(G);
	Floyd(G);
	
}

void MatrixGraph :: Showlin(MatrixGraph *G)
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

//最短路径

void MatrixGraph :: Dijkstra(MatrixGraph *G)
{
	int weight[20];
	int path[20];
	int tmpvertex[20];
	int i,j,k,v0,min;
	cout << "输入源点的编号：" << " ";
	cin >> v0;
	v0--;
	for(i = 0;i < G->VertexNum; i++)
	{
		weight[i] = G->Edges[v0][i];
		if(weight[i] < MAXVALUE && weight[i] > 0)
			path[i] = v0;
		tmpvertex[i] = 0;
	}
	tmpvertex[v0] = 1;
	weight[v0] = 0;
	for(i = 0; i < G->VertexNum; i++)
	{
		min = MAXVALUE;
		k = v0;
		for(j = 0;j < G->VertexNum; j++)
			if(tmpvertex[j] == 0 && weight[j] < min)
			{
			    min = weight[j];
				k = j;
			}
		tmpvertex[k] = 1;
		for(j = 0;j < G->VertexNum; j++)
			if(tmpvertex[j] == 0 && weight[k] + G->Edges[k][j] < weight[j])
			{
				weight[j] = weight[k] + G->Edges[k][j];
				path[j] = k;
			}
	}
	cout << "顶点" << G->Vertex[v0] << "到各顶点的最短路径为（终点<-源点）；" << endl;
	for(i = 0; i < G->VertexNum; i++)
	{
		if(tmpvertex[i] == 1)
		{
		    k = i;
			while(k != v0)
			{
			    j = k;
				cout << G->Vertex[k] << " <- ";
				k = path[k];
			}
			cout << G->Vertex[k] << endl;
		}
		else
			cout << G->Vertex[i] << " <- " << G->Vertex[v0] << ":无路径" << endl;
	}
}





void MatrixGraph :: Floyd(MatrixGraph *G)
{
    int A[20][20];
    int path[20][20];
	int i,j,k,n = G->VertexNum;
	int start,end;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
	    {
			A[i][j] = G->Edges[i][j];
			path[i][j] = -1;
		}
	for(k = 0; k < n; k++)
	{ 
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(A[i][j] > (A[i][k] + A[k][j]))
				{
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				} 
	} 
	cout << "输入起点，终点：" ;
	cin >> start >> end;
	cout << "最小距离为：";
	cout << A[start-1][end-1];
	cout << endl;

} 


void main()
{
	MatrixGraph G;
	G.Createlin();
}



