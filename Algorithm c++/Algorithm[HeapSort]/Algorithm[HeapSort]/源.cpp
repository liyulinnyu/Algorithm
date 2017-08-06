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

struct StuInfo
{
	char id[8];
	char name[10];
	char classs[10];
	int age;
	float chinese;
	float math;
	float english;
	float total;
};
int CreateData(int arr[],int n,int min,int max)
{
	int i,j,flag;               //arr���������������ɵ��������n��ʾ��Ҫ���ɵ��������������max,min��ʾ����������ֵ����Сֵ
	srand(time(NULL));                
	if((max - min + 1) < n) return 0;         //����0��ʾ���ɲ��ɹ�
	for(i = 0;i < n;i++)                //arr����ֵ��������ʹ��
	{
		do
		{
			arr[i] = (max - min + 1)* rand() / (RAND_MAX + 1) + min;
			flag = 0;
			for(j = 0;j < i; j++)                //�ж��Ƿ������е�������ͬ������ͬ������������һ��
			{
				if(arr[i] == arr[j])                    
					flag = 1;
			}
		}
		while(flag);
	}
	return 1;
}

#define ARRAYLEN 5000

void HeapAdjust(int a[],int s,int n)
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

void HeapSort(int a[],int n)
{
	int t,i;
	int j;
	for(i = n/2-1;i >= 0;i--)
		HeapAdjust(a,i,n);
	for(i = n-1;i > 0;i--)
	{
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		HeapAdjust(a,0,i);
	}
}

int main()
{
	clock_t start,finish;
   double totaltime;
   start=clock();
	int a[ARRAYLEN],i;
	for(i = 0; i< ARRAYLEN;i++)
		a[i ] = 0;
	if(!CreateData(a,ARRAYLEN,1,10000))
	{
		cout << "������������ɹ�" ;
		getch();
		return 1;
	}
	cout << "ԭ���ݣ�";
	for(i = 0;i < ARRAYLEN;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	HeapSort(a,ARRAYLEN);
	cout << "�����";
	for(i = 0;i < ARRAYLEN;i++)
		cout << a[i] << " ";
	cout << endl;
	 finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<"\n�˳��������ʱ��Ϊ"<<totaltime<<"�룡"<<endl;
	getch();
	return 0;
}