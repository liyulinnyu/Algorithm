#include "head.h"


/*
    堆排序

	将向量中的存储的数据看成一棵完全二叉树，利用完全二叉树中双亲结点和孩子结点之间的内在关系
	以选择关键字最小的记录的过程。

	是对树形选择排序的改进，堆排序需要一个能够记录大小的辅助空间

	
	给出选择排序的直接算法：

	void selectsort(int a[],int n)
	{
	    int i,j,k,t;
	    for(i = 0; i < n - 1; i++)
	    {
	        k = i;
	        for(j = i + 1; j < n; j++)
	              if(a[k] > a[j]) k = j;
	        t = a[i];
	        a[i] = a[k];
	        a[k] = t;
	    }
	}
*/








//生成随机数组：

int Create(int arr[] , int n , int min , int max)
{
	int i,j,flag;
	srand(time(NULL));
	if((max - min + 1) < n) return 0;
	for(i = 0 ; i < n ; i++)
	{
	    do
		{
		    arr[i] = (max - min + 1) * rand()/(RAND_MAX + 1) + min;
			flag = 0;
			for(j = 0; j < i; j++)
			{
			    if(arr[i] == arr[j])
					flag = 1;
			}
		}while(flag);
	}
	return 1;
}

#define ARRAYLEN 10

void sift(int a[],int s,int n)
{
	int j,t;
	while(2*s + 1 < n)
	{
	    j = 2*s + 1;
		if((j + 1) < n)
		{
		    if(a[j] < a[j + 1])
				j++;
		}
		if(a[s] < a[j])
		{
		    t = a[s];
			a[s] = a[j];
			a[j] = t;
			s = j;
		}
		else
			break;
	}
}

void Duisort(int a[],int n)
{
	int t,i;
	int j;
	for(i = n / 2; i >= 0; i--)
		sift(a, i, n);
	for(i = n - 1; i > 0; i--)
	{
	    t = a[0];
		a[0] = a[i];
		a[i] = t;
		sift(a, 0, i);
	}
}

void main()
{
	int i,a[ARRAYLEN];
	for(i = 0 ; i < ARRAYLEN; i++)
		a[i] = 0;
	Create(a,ARRAYLEN,1,100);
	cout << "原数据 : ";
	for(i = 0; i < ARRAYLEN; i++)
		cout << a[i] << " ";
	cout << endl;
	Duisort(a,ARRAYLEN);
	cout << "排序后 : ";
	for(i = 0; i < ARRAYLEN; i++)
		cout << a[i] << " ";
	cout << endl;
	getch();

}