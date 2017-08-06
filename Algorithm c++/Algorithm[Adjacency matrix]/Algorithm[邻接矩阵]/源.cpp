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


#define VERTEX_MAX 26                            //ͼ��󶥵���
#define MAXVALUE 32767                           //���ֵ

typedef struct
{
	char Vertex[VERTEX_MAX];                   //���涥����Ϣ
	int Edges[VERTEX_MAX][VERTEX_MAX];         //����ߵ�Ȩ
	int isTrav[VERTEX_MAX];                    //������־

	int VertexNum;                             //��������

	int EdgeNum;                               //������

	int GraphType;                             //ͼ����(0:����ͼ, 1:����ͼ)
}MatrixGraph;


void Createlin(MatrixGraph *G);                //�����ڽӾ���
void Outlin(MatrixGraph *G);                   //����ڽӾ���

void Createlin(MatrixGraph *G)
{
	int j,k,weight;
	char start,end;
	for(int i = 0;i < G->VertexNum ; i++)
	{
	    cout << "�����" << i+1 << "���������Ϣ��" << " ";
		cin >> G->Vertex[i] ;
	}
	for(int i = 0; i < G->EdgeNum ; i++)
	{
	    cout << "�����" << i+1 << "���ߵĿ�ʼ�ڵ�ֵ�������ڵ�ֵ��Ȩ��" << " ";
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
	cout << "�ڽӾ������£�" << endl;
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
			    cout << "\t��";
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
	cout << "����ͼ���ͣ�0.����ͼ 1.����ͼ����" << " ";
	cin >> G.GraphType;
	cout << "���붥����������������" << " ";
	cin >> G.VertexNum >> G.EdgeNum;
	for(int i = 0;i < G.VertexNum; i++)
		for(int j = 0; j < G.VertexNum; j++)
			G.Edges[i][j] = MAXVALUE;
	Createlin(&G);
	Outlin(&G);
	getch();
}