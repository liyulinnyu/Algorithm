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
		cout << "��" << i << "����:";
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
		cout << "����" << i << ":";
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
	cout << "��������ͼ�����ͣ�0������ͼ��1������ͼ��:";
	cin >> G.GraphType;
	cout << "����ͼ�Ķ��������ͱ�������";
	cin >> G.VextexNum >> G.EdgeNum;
	cout << "���빹�ɸ��ߵ��������㼰Ȩֵ���ո�ֿ�����\n";
	CreateGraph(&G);
	cout << "���ͼ����ӱ�\n";
	OutList(&G);
	getch();
	return 0;
}