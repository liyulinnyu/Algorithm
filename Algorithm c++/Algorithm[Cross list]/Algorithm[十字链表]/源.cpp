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
#include<queue>      //����
#include<vector>     
#include<stack>       //��
#include<iomanip>     //Ŀǰ����4����������setw(n)�������������Ҫ��������ַ�����setfill(char c)�����е��ַ�Ҫ�õ����ţ� �÷� : ������Ԥ���������                        �Ѵ���û����Ŀ�ȴ�С���������õ��ַ�c���,ע��˳�򣡣���  ��setbase(int n) : ������ת��Ϊ n ����,ֱ���ڼ�<<Ҫ����������ɡ�             ��setprecision(n)�ɿ����������ʾ�����������ָ�����C++Ĭ�ϵ��������ֵ��Чλ��6��setiosflags(ios::fixed)���ã����Կ���С�����ұߵ����ָ�����
#include<process.h>   
#include<dos.h> 
#include<cctype>   //isalpha()��
#include<map>      //ӳ��
#include<string>    //�ַ���
#include<sstream>   //����istringstream
#include<cstddef>   //size_t  ptrdiff_t���͵Ķ���
#include<numeric>    //ͨ����ֵ�㷨
#include<iterator>     //�������࣬������������

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
	Olgraph olgraph;               //����ͼ��ʮ������洢�ṹ


};

template <class TElemType>
void Graph<TElemType>::CreateOlgraph()  // ����ʮ������
{
	int i,j,m,n;
	float w;
	TElemType v1,v2;
	ArcBox *p;
	cout << "��������ͼ�Ķ������ͱ���:" << endl;
	cin >> olgraph.vexnum >> olgraph.arcnum;
	olgraph.vex = (Vertex<TElemType> *)malloc(olgraph.vexnum * sizeof(Vertex<TElemType>));
	cout << "���붥�����Ϣ:" << endl;
	for(i = 0;i < olgraph.vexnum;i++)
	{
		cin >> olgraph.vex[i].data;
		olgraph.vex[i].firstin = olgraph.vex[i].firstout = NULL;
	}

	cout << "������ߵĻ�β�뻡ͷ��㼰����ߵ�Ȩֵ:" << endl;

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
void Graph<TElemType>::PrintOlgraph()  // ���ʮ������
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
	118  cout << "�����յ�����:";
	119  cin >> a >> b;
	120  gph.Shortestpath_DIJ(a,b);
	121  gph.DestroyDN();
	122  return 0;*/
	Graph<int> gph;
	gph.CreateOlgraph();
	gph.PrintOlgraph();

	return 0;
}
