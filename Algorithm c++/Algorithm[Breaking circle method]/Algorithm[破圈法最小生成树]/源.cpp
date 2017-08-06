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
	//��ʼ��
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
	//���붥��value

	cout << "����" << length << "������";
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
				edge_flag[i][j]=VIS;      //��ʼ��û����Ȧ
			else
				edge_flag[i][j]=UNVIS;    //������ж��㶼û���ʹ�
		} 
	}
	if(DFS_search() == true)              //�л�
	{
		                               //ɾ�����ı�  ��myvec���м�¼
		return true;
	}
	else
		return false;
}

bool graph::DFS_search()
{
	//���ñ��
	find_flag = false;
	//û�ҵ���
	stop_push_vector = false;
	for (int i = 0; i < length ; i++)
	{
		mark[i]=UNVIS;                     //��¼û����
	}
	for (int i = 0; i < length; i++)
	{
		if(find_flag == false && mark[i] == UNVIS)        //û���ʾͷ�����
			DFS_S(i);
	}

	if(find_flag == true)
	{
		//�ҵ���ɾ���洢��myvec�����ı�
		vector<node *>::iterator i;
		node *p1,*p2;
		p1 = *(myvec.begin());
		p2 = *(myvec.begin() + 1);
		int max_edge = matrix[GetEdge(p1->value)][GetEdge(p2->value)];    //ǰ2����ıߵĳ�

		for(i = myvec.begin()+1; (i+1) != myvec.end(); i++)             //�ӵ�(2,3)���߿�ʼ ��end-1,end
		{
			if( matrix[GetEdge((*i)->value)][GetEdge((*(i+1))->value)]  > max_edge)
			{
				max_edge =  matrix[GetEdge((*i)->value)][GetEdge((*(i+1))->value)];
				p1 = (*i);
				p2 = *(i+1);//�������ߣ���¼����
			}
		}
		//���ͷβ����γɵı��Ƿ����
		if(matrix[GetEdge((*myvec.begin())->value)][GetEdge((*(myvec.end()-1))->value)] > max_edge)
		{
			max_edge = matrix[GetEdge((*myvec.begin())->value)][GetEdge((*(myvec.end()-1))->value)];
			p1 = myvec.front();
			p2 = *(myvec.end()-1);
		}
		//ɾ��p1,p2֮��ı�
		matrix[GetEdge(p1->value)][GetEdge(p2->value)] = INF;
		matrix[GetEdge(p2->value)][GetEdge(p1->value)] = INF;
		return true;//��ʾ�л�
	}
	else
		return false;
}
void graph::DFS_S(int i)
{
	if(mark[i]==VIS)
	{
		find_flag = true; //�ҵ�����,���ñ��
		save_i = i;
		return;
	}
	else
	{
		mark[i]=VIS;
	}
	for (int j = 0; j < length; j++)
	{
		if(find_flag==false && edge_flag[i][j]==UNVIS && matrix[i][j]!=INF)//��·��δ���ʵĽ��
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
	cout<<endl<<"��С������Ϊ(������ȱ���):"<<endl;
	//��ʼ��
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
		if(mark[j]==UNVIS && matrix[i][j]!=INF)//��i�����ɴ������δ�����ʵ�j���ݹ�
		{
			DFS(j);
		}
	}
}


int main()
{
	//����ͼ
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
	cout<<"ԭ�ڽӾ���:"<<endl;
	for (int i = 0; i < g.length; i++)
	{
		for (int j = 0; j < g.length; j++)
		{
			if(g.matrix[i][j]==INF)
				cout<<"��\t"<<" ";
			else
				cout<<  g.matrix[i][j] << "\t";
		}
		cout<<endl;
	}


	while(g.haveloop())
	{
		//��haveloop�Ի������߽���ɾ������
	}


	cout<<endl<<"���ڽӾ���:"<<endl;
	for (int i = 0; i < g.length; i++)
	{
		for (int j = 0; j < g.length; j++)
		{
			if(g.matrix[i][j]==INF)
				cout<<"��\t"<<" ";
			else
				cout<<  g.matrix[i][j] << "\t";
		}
		cout<<endl;
	}

	//��ʱû��Ȧ��DFSһ�¾͵õ���С������
	g.DFS_show();
	return 0;
}