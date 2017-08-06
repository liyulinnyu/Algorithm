//注：这算法适用于有向图，测试变态数据有错。
#include<iostream>
#include<stack>
using namespace std;
const int MAXSIZE=7;
class Graph
{
private:
	int *data;//顶点信息
	int matrix[MAXSIZE][MAXSIZE];//顶点关系
	bool visited[MAXSIZE];//记录顶点的访问情况
	int edgeNum;//边数
	int vertexNum;//顶点数
public:
	Graph(int edgeNum=0,int vertexNum=0);
	~Graph();
	void createGraph(int *dataArray,int matrixArray[][MAXSIZE],int vertexNum,int edgeNum);//邻接矩阵
	void printData();
	void printMatrix();
	bool isRing();
	void DFS();
};
Graph::Graph(int edgeNum,int vertexNum)
{
	data=new int[MAXSIZE];
	this->edgeNum=edgeNum;
	this->vertexNum=vertexNum;
	for(int i=0;i<MAXSIZE;i++)
		visited[i]=false;
}
Graph::~Graph()
{
	delete []data;
}

void Graph::createGraph(int *dataArray,int matrixArray[][MAXSIZE],int vertexNum,int edgeNum)
{
	int i,j;
	this->vertexNum=vertexNum;
	this->edgeNum=edgeNum;
	for(i=0;i<this->vertexNum;i++) 
		this->data[i]=dataArray[i];
	for(i=0;i<this->vertexNum;i++)
	{
		for(j=0;j<this->vertexNum;j++)
		{
			this->matrix[i][j]=matrixArray[i][j];
		}
	}
}
void Graph::printData()
{
	for(int i=0;i<this->vertexNum;i++)
		cout<<this->data[i] << " ";
	cout<<endl;
}
void Graph::printMatrix()
{
	for(int i=0;i<this->vertexNum;i++)
	{
		for(int j=0;j<this->vertexNum;j++)
			cout<<this->matrix[i][j] << " ";
		cout<<endl;
	}
}
bool Graph::isRing()
{
	int i,j;
	bool flag=false;
	for(i=0;i<MAXSIZE;i++)
	{
		flag=false;
		for(j=0;j<MAXSIZE;j++)
		{
			if(matrix[j][i])
			{
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			for(j=0;j<MAXSIZE;j++)
				matrix[i][j]=0;
			visited[i]=true;
		}
	}
	for(i=0;i<MAXSIZE;i++)
		for(j=0;j<MAXSIZE;j++)
			if(matrix[i][j])
				return true;
	return false;
}
void Graph::DFS()
{
	int i,j,t;
	stack<int> s;
	for(i=0;i<this->vertexNum;i++)
	{
		if(!visited[i])
		{
			s.push(i);
			if(i!=0)
			    cout<<i+1;
			visited[i]=true;
			while(!s.empty())
			{
				t=s.top();
				s.pop();
				for(j=0;j<this->vertexNum;j++)
				{
					if(matrix[t][j]&&!visited[j])
					{
						t=j;
						break;
					}
				}
				if(!visited[t])
				{
					s.push(t);
					cout<<" " << t+1 << " ";
					visited[t]=true;
				}
			}
		}
	}
	cout<<endl;
}
int main()
{
	Graph g;
	int dataArray[7]={1,2,3,4,5,6,7};
	int matrixArray[7][7]={
		{0,1,0,0,0,0,0},
		{0,0,1,0,0,0,0},
		{0,0,0,1,0,0,0},
		{0,1,0,0,0,0,0},
		{1,0,0,0,0,0,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,0,1,0}
	};
	g.createGraph(dataArray,matrixArray,7,7);
	g.printData();

	g.printMatrix();
	if(g.isRing())
		g.DFS();
	return 0;
}