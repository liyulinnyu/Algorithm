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

#define  MAXV  100 
#define  INF  32767 

typedef int InfoType; 
typedef int Vertex; 

typedef struct 
{    
	int no;              
	InfoType info;            
} VertexType;             



//��������
typedef struct  
{    
	int edges[MAXV][MAXV]; 
	int n,e; 
	VertexType vexs[MAXV]; 
}MGraph;                         



//ͼ����
void Ppath(int path[][MAXV], int i, int j) 
{   
	int k; 
	k = path[i][j];
	if (k == -1)  
		return;             
	//�ݹ����
	Ppath(path,i,k);               
	cout << k << "  ";         
	//���k          
	Ppath( path , k , j );               
} 

void Dispath(int A[][MAXV],int path[][MAXV],int n) 
{ 
	int i,j; 
	for (i = 0;i < n;i ++) 
		for (j = 0 ;j < n; j++) 
			if (A[i][j] == INF) 
			{  
				if(i != j) cout << "��" << i << "��" << j << "������·��\n"; 
			} 
			else 
			{    
				cout << "��" << i << " ��" << j << " ��·��Ϊ: " << i << " "; 
				Ppath(path, i, j);  
				cout << j; 
				cout << " \t\t ·������Ϊ:"<< A[i][j] <<endl; 
			} 
} 

void Floyd(MGraph g) 
{   
	int A[MAXV][MAXV],path[MAXV][MAXV]; 
	int i,j,k; 
	for (i = 0;i < g.n; i++) 
		for (j = 0;j < g.n; j++) 
		{    
			A[i][j] = g.edges[i][j]; 
			path[i][j] = -1; 
		} 
		for (k = 0;k < g.n; k++) 
			for (i = 0;i < g.n; i++) 
				for (j = 0;j < g.n; j++) 
					if (A[i][j] > (A[i][k] + A[k][j])) 
					{ 
						A[i][j] = A[i][k] + A[k][j]; 
						path[i][j] = k;  
					} 
					Dispath(A,path,g.n);                         
//������·��
} 

void DispMat(MGraph g) 
{ 
	int i,j; 
	for(i = 0;i < g.n; i++) 
	{ 
		for(j = 0;j < g.n; j++) 
			if(g.edges[i][j] == INF) 
				cout << setw(3) <<" ��";
			else 
				cout << setw(3) << g.edges[i][j]; 
		cout << endl; 
	} 
} 

void Floyd(MGraph g); 
void Ppath(int path[][MAXV], int i, int j);
void Dispath(int A[][MAXV],int path[][MAXV],int n); 
void DispMat(MGraph g); 

void main() 
{ 
	int i,j; 
	MGraph g; 
	cout << "�����ڽӾ���g�ܶ�����g.n���ܱ�g.e��"; 
	cin >> g.n >> g.e; 
	cout << "�����ڽӾ���g��Ԫ��ֵ��\n"; 
	for(i = 0;i < g.n; i++) 
	{ 
		cout << "��" << i << "�У�"; 
		for(j = 0;j < g.n; j++) 
			cin >> g.edges[i][j]; 
	} 

	cout << "����ڽӾ���g��\n"; 
	DispMat(g); 
	cout << "���ÿ�Զ���֮������·����\n"; 
	Floyd(g); 
	cout << endl; 
}  