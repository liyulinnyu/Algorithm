#include<iostream>
#include<vector>
#define INF 9999
#define UNVIS 0
#define VIS 1
using namespace std;
class node
{
public:
	char value;
	node(){}
};
class graph{
public:
	int save_i;
	bool stop_push_vector;
	bool  find_flag;
	vector <node*> myvec;
	int **matrix;
	bool **edge_flag;
	bool *mark;
	node *nodes;
	int length;
public:
	bool haveloop();
	graph(int num);
	int GetEdge(char value);
	void SetEdge(char i , char j , int weight);
	bool DFS_search();
	void DFS_S(int i);
	void DFS_show();
	void DFS(int i);

};

graph::graph(int num)
{
	length = num;
	mark = new bool[length];
	nodes = new node[length];
	matrix = new int*[length];
	edge_flag=new bool*[length];
	for(int i = 0; i < length; i++)
	{
		edge_flag[i]=new bool[length];
	}
	for(int i = 0; i < length; i++)
	{
		matrix[i]=new int[length];
	}
	//初始化
	for(int i = 0; i < length; i++)
	{
		mark[i]=UNVIS;
	}
	for(int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if(i==j)
				matrix[i][j]=0;
			else 
				matrix[i][j]=INF;		
		}
	}
	//输入顶点value

	cout << "输入" << length << "个顶点";
	for (int i = 0; i < length; i++)
	{
		cin >> nodes[i].value;	
	}
	
}
void graph::SetEdge(char i,char j,int weight)
{
	matrix[GetEdge(i)][GetEdge(j)] = weight;
	matrix[GetEdge(j)][GetEdge(i)] = weight;
}
int graph::GetEdge(char value)
{
	for (int i = 0; i < length; i++)
	{
		if(nodes[i].value == value)
			return i;
	}
	cout << "erro";
	return -1;
}
bool graph :: haveloop()
{
	myvec.clear();
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if(i == j)
				edge_flag[i][j]=VIS;      //初始化没有自圈
			else
				edge_flag[i][j]=UNVIS;    //标记所有顶点都没访问过
		} 
	}
	if(DFS_search() == true)              //有环
	{
		                               //删除最大的边  在myvec中有记录
		return true;
	}
	else
		return false;
}

bool graph::DFS_search()
{
	//重置标记
	find_flag = false;
	//没找到环
	stop_push_vector = false;
	for (int i = 0; i < length ; i++)
	{
		mark[i]=UNVIS;                     //记录没访问
	}
	for (int i = 0; i < length; i++)
	{
		if(find_flag == false && mark[i] == UNVIS)        //没访问就访问他
			DFS_S(i);
	}

	if(find_flag == true)
	{
		//找到并删除存储在myvec中最大的边
		vector<node *>::iterator i;
		node *p1,*p2;
		p1 = *(myvec.begin());
		p2 = *(myvec.begin() + 1);
		int max_edge = matrix[GetEdge(p1->value)][GetEdge(p2->value)];    //前2个点的边的长

		for(i = myvec.begin()+1; (i+1) != myvec.end(); i++)             //从第(2,3)个边开始 到end-1,end
		{
			if( matrix[GetEdge((*i)->value)][GetEdge((*(i+1))->value)]  > max_edge)
			{
				max_edge =  matrix[GetEdge((*i)->value)][GetEdge((*(i+1))->value)];
				p1 = (*i);
				p2 = *(i+1);//遍历各边，记录最大边
			}
		}
		//检测头尾结点形成的边是否最大
		if(matrix[GetEdge((*myvec.begin())->value)][GetEdge((*(myvec.end()-1))->value)] > max_edge)
		{
			max_edge = matrix[GetEdge((*myvec.begin())->value)][GetEdge((*(myvec.end()-1))->value)];
			p1 = myvec.front();
			p2 = *(myvec.end()-1);
		}
		//删除p1,p2之间的边
		matrix[GetEdge(p1->value)][GetEdge(p2->value)] = INF;
		matrix[GetEdge(p2->value)][GetEdge(p1->value)] = INF;
		return true;//表示有环
	}
	else
		return false;
}
void graph::DFS_S(int i)
{
	if(mark[i]==VIS)
	{
		find_flag = true; //找到环了,重置标记
		save_i = i;
		return;
	}
	else
	{
		mark[i]=VIS;
	}
	for (int j = 0; j < length; j++)
	{
		if(find_flag==false && edge_flag[i][j]==UNVIS && matrix[i][j]!=INF)//有路且未访问的结点
		{
			edge_flag[j][i]=VIS;
			edge_flag[i][j]=VIS;
			DFS_S(j);
		}
	}
	if(find_flag == true)
	{
		if(stop_push_vector == false)
		{
			myvec.push_back(&nodes[i]);
			if(i == save_i)
				stop_push_vector = true;
		}
		return;
	}

}
void graph::DFS_show()
{
	cout<<endl<<"最小生成树为(深度优先遍历):"<<endl;
	//初始化
	for (int i = 0; i < length; i++)
	{
		mark[i]=UNVIS;
	}
	for (int i = 0; i < length; i++)
	{
		if(mark[i]==UNVIS)
			DFS(i);
	}

	cout<<endl;
}
void graph::DFS(int i)
{
	cout<<nodes[i].value<<" ";
	mark[i]=VIS;
	for (int j = 0; j < length; j++)
	{
		if(mark[j]==UNVIS && matrix[i][j]!=INF)//从i出发可达的所有未被访问的j，递归
		{
			DFS(j);
		}
	}
}


int main()
{
	//无向图
	graph g(6);
	g.SetEdge('1','2',6);
	g.SetEdge('1','3',1);
	g.SetEdge('1','4',5);
	g.SetEdge('2','3',5);
	g.SetEdge('2','5',3);
	g.SetEdge('3','4',5);
	g.SetEdge('3','5',6);
	g.SetEdge('3','6',4);
	g.SetEdge('5','6',6);
	g.SetEdge('4','6',2);
	cout<<"原邻接矩阵:"<<endl;
	for (int i = 0; i < g.length; i++)
	{
		for (int j = 0; j < g.length; j++)
		{
			if(g.matrix[i][j]==INF)
				cout<<"∞\t"<<" ";
			else
				cout<<  g.matrix[i][j] << "\t";
		}
		cout<<endl;
	}


	while(g.haveloop())
	{
		//在haveloop对环的最大边进行删除操作
	}


	cout<<endl<<"新邻接矩阵:"<<endl;
	for (int i = 0; i < g.length; i++)
	{
		for (int j = 0; j < g.length; j++)
		{
			if(g.matrix[i][j]==INF)
				cout<<"∞\t"<<" ";
			else
				cout<<  g.matrix[i][j] << "\t";
		}
		cout<<endl;
	}

	//此时没有圈。DFS一下就得到最小生成树
	g.DFS_show();
	return 0;
}