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


#define MAXVALUE 32767                           //���ֵ

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
	void DFSTraverse(MatrixGraph *G);
	void DFSM(MatrixGraph *G,int i);
	void BFSTraverse(MatrixGraph *G);
	void BFSM(MatrixGraph *G,int k);
};

void MatrixGraph :: Createlin()
{
	MatrixGraph *G;
	G = new MatrixGraph;
	cout << "��������ͼ�����ͣ�0.����ͼ��1.����ͼ����" << " ";
	cin >> G->GraphType;
	cout << "����ͼ�Ķ��������ͱ�������" << " ";
	cin >> G->VertexNum >> G->EdgeNum;
	for(int i = 0 ; i < G->VertexNum; i ++)
		for(int j = 0; j < G->VertexNum; j++)
			G->Edges[i][j] = MAXVALUE;
	
	char start,end;
	int	weight,m,n;
	for(int i = 0 ; i < G->VertexNum; i++)
	{
	    cout << "�����"  << i+1 << "���ڵ��ֵ��" << " ";
		cin >> G->Vertex[i];
	}
	for(int k = 0 ; k < G->EdgeNum; k++)
	{
	    cout << "�����" << k + 1 << "���ߵ���㣬�յ㣬Ȩֵ��" << ' ';
		cin >> start >> end >> weight;
		for(m = 0; start != G->Vertex[m] ;m++);
		for(n = 0; end != G->Vertex[n] ; n++);
		G->Edges[m][n] = weight;
		if(G->GraphType == 0)
			G->Edges[n][m] = weight;
	}

	cout << "�ڽӾ���" <<endl;
	Showlin(G);
	DFSTraverse(G);
	BFSTraverse(G);
}

void MatrixGraph :: Showlin(MatrixGraph *G)
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

//����ͼ

void  MatrixGraph :: DFSTraverse(MatrixGraph *G)
{
	for(int i = 0;i < G->VertexNum; i++)
		G->isTrav[i] = 0;
	cout << "������ȱ�����㣺" << endl;
	for(int i = 0;i < G->VertexNum; i++)
		if(!G->isTrav[i])
			DFSM(G,i);
	cout << endl;
} 

void  MatrixGraph :: DFSM(MatrixGraph *G,int i)
{
	G->isTrav[i] = 1;
	cout << "->" << G->Vertex[i];
	for(int j = 0; j < G->VertexNum; j++)
	{
		if(G->Edges[i][j] != MAXVALUE && !G->isTrav[j])
			DFSM(G,j);
	}
}

void  MatrixGraph :: BFSTraverse(MatrixGraph *G)
{
	for(int i = 0 ; i < G->VertexNum ; i++)
		G->isTrav[i] = 0;
	cout << "������ȱ����ڵ㣺" << endl;
	for(int i = 0; i < G->VertexNum ; i++)
		if(!G->isTrav[i])
			BFSM(G,i);
	cout << endl;
}

void  MatrixGraph :: BFSM(MatrixGraph *G,int k)
{
	int i;
	queue <int> Q;
	cout << "->" << G->Vertex[k];
	G->isTrav[k] = 1;
    Q.push(k);
	while(!Q.empty())
	{
		i = Q.front();
		Q.pop();
        for(int j = 0; j < G->VertexNum ; j++)
		{
			if(G->Edges[i][j] != MAXVALUE && !G->isTrav[j])
			{
				cout << "->" << G->Vertex[j];
				G->isTrav[j] = 1;
				Q.push(j);
			}
		}
	}

}



void main()
{
	MatrixGraph G;
	G.Createlin();
}


