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
	void Dijkstra(MatrixGraph *G);
	void Floyd(MatrixGraph *G);
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
	cout << "Dijkstra�㷨�����" << endl;
	Dijkstra(G);
	Floyd(G);
	
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

//���·��

void MatrixGraph :: Dijkstra(MatrixGraph *G)
{
	int weight[20];
	int path[20];
	int tmpvertex[20];
	int i,j,k,v0,min;
	cout << "����Դ��ı�ţ�" << " ";
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
	cout << "����" << G->Vertex[v0] << "������������·��Ϊ���յ�<-Դ�㣩��" << endl;
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
			cout << G->Vertex[i] << " <- " << G->Vertex[v0] << ":��·��" << endl;
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
	cout << "������㣬�յ㣺" ;
	cin >> start >> end;
	cout << "��С����Ϊ��";
	cout << A[start-1][end-1];
	cout << endl;

} 


void main()
{
	MatrixGraph G;
	G.Createlin();
}



