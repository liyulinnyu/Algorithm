#include "head.h"

/*
    直接插入排序
    
    空间角度：  只需设置r[0]监视哨帮助实现即可,复杂度为O(1)
    时间角度：  花费在关键字比较和移动元素上

    适用条件：  待排序数目较少且基本有序的情形， 当数目较大时，需改进减少关键字比较和移动记录两种操作的次数
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

#define ARRAYLEN 10 //需要排序的数据元素数量

//直接插入排序

void InsertSort(int a[], int n)
{
	int i , j , t;
	for(i = 1; i < n; i++)
	{
	    t = a[i];
		for(j = i - 1; j >= 0 && t < a[j]; --j)
			a[j + 1] = a[j];
		a[j + 1]  = t;
	}
}


void main()
{
	int i,a[ARRAYLEN];
	for(i = 0; i < ARRAYLEN; i++)
		a[i] = 0;
	if(!Create(a,ARRAYLEN,1,100))
	{
	    cout << "生成随机数不成功" << endl;
		getch();
		return;
	}
	cout << "原数据 : " << " ";
	for(i = 1; i < ARRAYLEN; i++)
		cout << a[i] << " ";
	cout << endl;
	InsertSort(a,ARRAYLEN);
	cout << "排序后 : " << " ";
	for(i = 1; i < ARRAYLEN; i++)
		cout << a[i] << " ";
	cout << endl;
	getch();
}

/*
    折半插入排序

	利用对有序表进行折半查找的性能高于顺序查找，优化插入排序    但并没有改变时间复杂度，还是O(n^2)



void BinSort(int r[],int length)
{
    for(i = 2; i <= length; i++)
	{
	    x = r[i];
		low = 1;
		high = i - 1;
		while(low <= high)                             //确定位置
		{
		    mid = (low + high) / 2;
			if(x.key < r[mid].key) 
			    high = mid - 1;
			else
			    low = mid + 1;
		}
		for(j = i - 1; j >= low; --j)                  //记录依次向后移动
		    r[j + 1] = r[j];                           
		r[low] = x;                                    //插入记录
	}
}

*/



/*
    希尔排序

	基于插入排序的思想，首先将待排序的关键字序列分成若干较小的子序列，对子序列做插入排序，使其基本有序
	最后对全部进行直接插入排序。对有序来说，直接插入排序时间复杂度可以提高到O(n)

	void shellsort(int a[].int n)
	{
	    int d,i,j,x;
		d = n / 2;
		while(d >= 1)                                    //循环至增加为1时结束
		{
		    for(i = d; i < n; i++)
			{
			    x = a[i];                               //获取序列中的下一个数据
				j = i - d;                             //序列中前一个数据的序号
				while(j >= 0 && a[j] > x)              //下一个数大于前一个数
				{
				    a[j + d] = a[j];
					j = j - d;                        //修改序号，继续向前比较
				}
				a[j + d] = x;                         //保存数据
			}
			d /= 2;                                    //减少缩量
		}
	}

	
	
    	小型数据用直接插入排序，大型数据用希尔
	
*/