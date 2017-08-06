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
	cout << "�����������Ϣ��\n";
	for(i = 0; i < G->VertexNum ; i++)
	{
		getchar();
		cout << "��" << i+1 << "������:";
		cin >> G->Vertex[i];
	}
	cout << "���빹�ɸ��ߵ��������㼰Ȩֵ���ո���룩:\n";
	for(k = 0;k< G->EdgeNum ; k++)
	{
		getchar();
		cout << "��" << k + 1<< "���ߣ�";
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
	cout << "��������ͼ�����ͣ�0������1�����򣩣�";
	cin >> G.GraphType;
	cout << "����ͼ�Ķ��������ͱߵ�����:";
	cin >> G.VertexNum >> G.EdgeNum;
	for(i = 0;i < G.VertexNum;i++)
		for(j = 0; j< G.VertexNum ;j++)
			G.Edges[i][j] = MAXVALUE;
	CreateMatrixGraph(&G);
	cout << "��Ӿ������£�\n";
	OutMatrix(&G);
	getch();
	return 0;
}