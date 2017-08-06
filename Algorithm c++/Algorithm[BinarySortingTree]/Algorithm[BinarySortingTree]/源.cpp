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

//����������������������������С�ڸ��ڵ㣬���������ڸ��ڵ㣬�Դ�ѭ��

//������
#define ARRAYLEN 10
int source[] = {54,90,6,69,12,37,92,28,65,83};
typedef struct bst
{
	int data;
	struct bst *left;
	struct bst *right;
}BSTree;                       //����������ṹ
void InsertBST(BSTree *t,int key)
{
	BSTree *p,*parent,*head;
	if(!(p = new BSTree))
	{
		cout << "�����ڴ�ʧ��" << endl;
		exit(0);
	}
	p->data = key;
	p->left = p->right = NULL;
	head = t;
	while(head)                                     //������Ҫ��ӵĸ����
	{                                                
		parent = head;
		if(key < head->data)
			head = head->left;
		else
			head = head->right;
	}
	if(key < parent->data)
		parent ->left = p;
	else
		parent->right = p;
}
void CreateBST(BSTree *t,int data[],int n)               //�������е����ݲ������������
{
	int i;
	t->data = data[0];                    //���ڵ㸳ֵ
	t->left = t->right = NULL;
	for(i = 1;i < n;i++)
		InsertBST(t,data[i]);
}

void BST_LDR(BSTree *t)                  //�����������鴴�������������Ƿ�ɹ�
{
	if(t)
	{
		BST_LDR(t->left);                           //�������������
		cout << t->data << " ";                            //�������
		BST_LDR(t->right);                          //����������������ݹ�Ĺ���
	}
}


//���ҽ��

BSTree *SearchBST(BSTree *t,int key)
{
	if(!t || t->data == key)
		return t;
	else if(key > t->data)
		return(SearchBST(t->right,key));
	else
		return(SearchBST(t->left,key));
}

//ɾ�����
//���������1��ɾ��Ҷ��㣬��ɾȥ����
           //2��ɾ���Ľ����һ��������ֻ���޸Ľ��ĸ���㣬ʹ���ӽ��ָ���ֵΪleft��right
           //3����������������������������к�̽�㣬��Ҫ�ҳ���������������������Ҷ��㣬����������
void BST_Delete(BSTree *t,int key)
{
	BSTree *p,*parent,*l,*ll;
	int child = 0;
	if(!t) return;
	p = t;
	parent = p;
	while(p)
	{
		if(p-> data == key)
		{
			if(!p->left && !p->right)
			{
				if(p == t)
				{
					free(p);
				}
				else if(child == 0)
				{
					parent->left = NULL;
					free(p);
				}
				else
				{
					parent->right = NULL;
					free(p);
				}
			}
			else if(!p->left)
			{
				if(child == 0)
					parent->left = p->right;
				else
					parent->right = p->left;
				free(p);
			}
			else if(!p->right)
			{
				if(child == 0)
					parent->left = p->right;
				else
					parent->right = parent->left;
				free(p);
			}
			else
			{
				ll = p;
				l = p->right;
				while(l->left)
				{
					ll = l;
					l = l->left;
				}
				p->data = l->data;
				ll ->left = NULL;
				free(ll);
			}
			p = NULL;
		}
		else if(key < p->data)
		{
			child = 0;
			parent = p;
			p = p->left;
		}
		else
		{
			child = 1;
			parent = p;
			p = p->right;
		}
	}
}


int main()
{
	int i,key;
	BSTree bst,*pos;
	cout << "ԭ���ݣ�";
	for(i = 0;i < ARRAYLEN;i++)
		cout << source[i] << " ";
	cout << endl;
	CreateBST(&bst,source,ARRAYLEN);
	cout << "����������������";
	BST_LDR(&bst);
	cout << "\n����ؼ��֣�";
	cin >> key;
	pos = SearchBST(&bst,key);
	if(pos)
		cout << "���ҳɹ�����ַ�ǣ�" << pos << endl;
	else
		cout <<"����ʧ�ܣ�\n";
	cout << "����Ҫɾȥ�Ľ��ֵ��";
	cin >> key;
	BST_Delete(&bst,key);
	cout << "\nɾ������Ľ�㣺";
	BST_LDR(&bst);
	getch();
	return 0;

}





