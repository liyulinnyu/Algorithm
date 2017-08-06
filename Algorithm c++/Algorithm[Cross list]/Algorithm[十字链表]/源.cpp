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


template <class TElemType>
class Graph
{
public:
	void CreateOlgraph();
	void PrintOlgraph();
private:
	struct ArcBox
	{
		int headvex,tailvex;
		ArcBox *hlink,*tlink;
		float weight;
	};

	template <class TElemType>
	struct Vertex
	{
		TElemType data;
		ArcBox *firstin,*firstout;
	};

	struct Olgraph
	{
		int vexnum,arcnum;
		Vertex<TElemType> *vex;
	};
	Olgraph olgraph;               //有向图的十字链表存储结构


};

template <class TElemType>
void Graph<TElemType>::CreateOlgraph()  // 创建十字链表
{
	int i,j,m,n;
	float w;
	TElemType v1,v2;
	ArcBox *p;
	cout << "输入有向图的顶点数和边数:" << endl;
	cin >> olgraph.vexnum >> olgraph.arcnum;
	olgraph.vex = (Vertex<TElemType> *)malloc(olgraph.vexnum * sizeof(Vertex<TElemType>));
	cout << "输入顶点的信息:" << endl;
	for(i = 0;i < olgraph.vexnum;i++)
	{
		cin >> olgraph.vex[i].data;
		olgraph.vex[i].firstin = olgraph.vex[i].firstout = NULL;
	}

	cout << "输入各边的弧尾与弧头结点及有向边的权值:" << endl;

	for(i = 0;i < olgraph.arcnum;i++)
	{
		cin >> v1 >> v2 >> w;
		for(j = 0;j < olgraph.vexnum;j++)
		{
			if(v1 == olgraph.vex[j].data) m = j;
			if(v2 == olgraph.vex[j].data) n = j;
		}
		p = (ArcBox *)malloc(sizeof(ArcBox));
		p->headvex = n;p->tailvex = m;
		p->weight = w;
		p->hlink = olgraph.vex[n].firstin;olgraph.vex[n].firstin = p;
		p->tlink = olgraph.vex[m].firstout;olgraph.vex[m].firstout = p;
	}
}         //end CreateOlgraph


template <class TElemType>
void Graph<TElemType>::PrintOlgraph()  // 输出十字链表
{
	int k;
	ArcBox *p;
	cout << "    The Vertex Outdegree = >  " << endl;
	for(k = 0; k <olgraph.vexnum; k ++)
	{  
		p = olgraph.vex[k].firstout;
		cout << "    Vertex:" << k+1 << "";
		while(p != NULL)
		{

			cout << "<"<<(p->tailvex)+1 << "," << (p->headvex)+1<< ">" << " ";
			p = p-> tlink;

		}
		cout << endl;

	}


	cout << "    The Vertex Indegree = >  " << endl;
	for(k = 0; k <olgraph.vexnum; k ++)
	{  
		p = olgraph.vex[k].firstin;
		cout << "    Vertex:" << k+1 << "";
		while(p != NULL)
		{

			cout << "<"<<(p->tailvex)+1 << "," << (p->headvex)+1<< ">" << " ";
			p = p-> hlink;

		}
		cout << endl;

	}

}

int main()
{
	/*Graph<int> gph;
	116  gph.CreateDN();
	117  int a,b;
	118  cout << "输入终点和起点:";
	119  cin >> a >> b;
	120  gph.Shortestpath_DIJ(a,b);
	121  gph.DestroyDN();
	122  return 0;*/
	Graph<int> gph;
	gph.CreateOlgraph();
	gph.PrintOlgraph();

	return 0;
}
