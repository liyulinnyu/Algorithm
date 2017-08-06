#include "head.h"

class BSTTree
{
private:
	int data;
	BSTTree *left;
	BSTTree *right;
	
public:
	void Insertdata(BSTTree *t,int key);
	void Createtree(BSTTree *t, int data[],int n);
	void BST_LDR(BSTTree *t);
	void Deleteer(BSTTree *t,int key);
	int Searchercha(BSTTree *t,int key);
};

void BSTTree :: Createtree(BSTTree *t, int data[],int n)
{
	int i;
	t->data = data[0];
	t->left = t->right = NULL;
	for(i = 1;i < n; i++)
	{
		Insertdata(t,data[i]);
	}
}

void BSTTree :: Insertdata(BSTTree *t,int number)
{
	BSTTree *p , *head , *parent;
	p = new BSTTree;
	p->data = number;
	p->left = p->right = NULL;
	head = t;
	while(head)
	{
		parent = head;
		if(number < head->data)
			head = head->left;
		else
			head = head->right;
	}
	if(number < parent->data)
		parent->left = p;
	else
		parent->right = p;
}

void BSTTree :: BST_LDR(BSTTree *t)
{
	if(!t) return;
	if(t)
	{
		BST_LDR(t->left);
		cout << t->data << " ";
		BST_LDR(t->right);
	}
}

void BSTTree :: Deleteer(BSTTree *t,int number)
{
	BSTTree *p,*parent,*l,*l1;
	int child = 0;
	if(!t) return;
	p = t;
	parent = p;
	while(p)
	{
		if(p->data == number)
		{
			if(!p->left && !p->right)      //����������Ϊ��
			{
				if(p == t)                //��ɾ�����Ǹ��ڵ�
				{
					delete p;
				}
				else if(child == 0)               //�����Ϊ������
				{
					parent->left = NULL;           //���ø����������Ϊ��
					delete p;
				}
				else                                //�����Ϊ������
				{
					parent->right = NULL;           
					delete p;
				}
			}


			else if(!p->left)                         //������Ϊ�գ���������Ϊ��
			{
				if(child == 0)
					parent->left = p->right;
				else
					parent->right = p->right;
				delete p;
			}

			else if(!p->right)                        //������Ϊ�գ���������Ϊ��
			{
				if(child == 0)
					parent->left = p->left;
				else
					parent->right = p->left;
				delete p;
			}

			else
			{
				l1 = p;
				l = p->right;
				while(l->left)
				{
					l1 = l;
					l = l->left;
				}
				p->data = l->data;
				if(p != l1)
				    l1->left = l->right;
				else
					p->right = l->right;
                delete l;
			}
			p = NULL;
		}
		else if(number < p->data)
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


int BSTTree::Searchercha(BSTTree *t,int key)
{
	if(!t) return 0;
	if(t->data == key)
		return t->data;
	else if(key > t->data)
		return Searchercha(t->right,key);
	else
		return Searchercha(t->left,key);
}



void main()
{          
	int i,number = 0;
	int data[10] = {13,15,33,14,18,19,20,53,8,1};
	BSTTree p;
	int t = 0;
	cout << "ԭ���ݣ�" << " ";
	for(i = 0;i < 10; i++) 
		cout << data[i] << " ";
	cout << endl;
	p.Createtree(&p,data,10);
	cout << endl;
	cout << "����������������" << endl;
	p.BST_LDR(&p);
	cout << endl;
	cout << "����Ҫɾ��������" << " ";
	cin >> number;
	p.Deleteer(&p,number);

	cout << "ɾ����" << endl;
	p.BST_LDR(&p);

	cout << endl;
	cout << "����ؼ��֣�" << " ";
	cin >> number;
	t = p.Searchercha(&p,number);
	cout << "�ڵ㣺" << " " << t << endl;
    
	getch();
}

