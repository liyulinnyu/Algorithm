#include "head.h"

/*
    ֱ�Ӳ�������
    
    �ռ�Ƕȣ�  ֻ������r[0]�����ڰ���ʵ�ּ���,���Ӷ�ΪO(1)
    ʱ��Ƕȣ�  �����ڹؼ��ֱȽϺ��ƶ�Ԫ����

    ����������  ��������Ŀ�����һ�����������Σ� ����Ŀ�ϴ�ʱ����Ľ����ٹؼ��ֱȽϺ��ƶ���¼���ֲ����Ĵ���
*/


//����������飺

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

#define ARRAYLEN 10 //��Ҫ���������Ԫ������

//ֱ�Ӳ�������

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
	    cout << "������������ɹ�" << endl;
		getch();
		return;
	}
	cout << "ԭ���� : " << " ";
	for(i = 1; i < ARRAYLEN; i++)
		cout << a[i] << " ";
	cout << endl;
	InsertSort(a,ARRAYLEN);
	cout << "����� : " << " ";
	for(i = 1; i < ARRAYLEN; i++)
		cout << a[i] << " ";
	cout << endl;
	getch();
}

/*
    �۰��������

	���ö����������۰���ҵ����ܸ���˳����ң��Ż���������    ����û�иı�ʱ�临�Ӷȣ�����O(n^2)



void BinSort(int r[],int length)
{
    for(i = 2; i <= length; i++)
	{
	    x = r[i];
		low = 1;
		high = i - 1;
		while(low <= high)                             //ȷ��λ��
		{
		    mid = (low + high) / 2;
			if(x.key < r[mid].key) 
			    high = mid - 1;
			else
			    low = mid + 1;
		}
		for(j = i - 1; j >= low; --j)                  //��¼��������ƶ�
		    r[j + 1] = r[j];                           
		r[low] = x;                                    //�����¼
	}
}

*/



/*
    ϣ������

	���ڲ��������˼�룬���Ƚ�������Ĺؼ������зֳ����ɽ�С�������У�������������������ʹ���������
	����ȫ������ֱ�Ӳ������򡣶�������˵��ֱ�Ӳ�������ʱ�临�Ӷȿ�����ߵ�O(n)

	void shellsort(int a[].int n)
	{
	    int d,i,j,x;
		d = n / 2;
		while(d >= 1)                                    //ѭ��������Ϊ1ʱ����
		{
		    for(i = d; i < n; i++)
			{
			    x = a[i];                               //��ȡ�����е���һ������
				j = i - d;                             //������ǰһ�����ݵ����
				while(j >= 0 && a[j] > x)              //��һ��������ǰһ����
				{
				    a[j + d] = a[j];
					j = j - d;                        //�޸���ţ�������ǰ�Ƚ�
				}
				a[j + d] = x;                         //��������
			}
			d /= 2;                                    //��������
		}
	}

	
	
    	С��������ֱ�Ӳ������򣬴���������ϣ��
	
*/