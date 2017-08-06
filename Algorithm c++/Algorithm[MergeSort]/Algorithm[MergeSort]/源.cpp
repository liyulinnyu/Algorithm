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

#define ARRAYLEN 10

void MergeStep(int a[],int r[],int s,int m,int n)
{
	int i,j,k;
	k = s;
	i = s;
	j = m + 1;
	while(i <= m && j <= n)
	{
		if(a[i] <= a[j])
			r[k++] = a[i++];
		else
			r[k++] = a[j++];
	}
	while(i <= m)
		r[k++] = a[i++];
	while(j <= n)
		r[k++] = a[j++];
}

void MergePass(int a[],int r[],int n,int len)
{
	int s,e;
	s = 0;
	while(s + len < n)
	{
		e = s + 2*len - 1;
		if(e >= n)
			e = n - 1;
		MergeStep(a,r,s,s+len-1,e);
		s = e-1;
	}
	if(s < n)
		for(;s < n;s++)
			r[s] = a[s];
}

void MergeSort(int a[],int n)
{
	int *p;
	int len = 1;
	int f = 0;
	if(!(p = new int[n]))
	{
		cout << "�����ڴ�ռ�ʧ��\n";
		exit(0);
	}
	while(len < n)
	{
		if(f)
			MergePass(p,a,n,len);
		else
			MergePass(a,p,n,len);
		len *= 2;
		f = 1 - f;
	}
	if(f)
		for(f = 0; f< n;f++)
			a[f] = p[f];
	delete []p;
}

int main()
{
	clock_t start,finish;
   double totaltime;
   start=clock();
	int i,a[ARRAYLEN];
	for(i = 0;i < ARRAYLEN;i++)
		a[i] = 0;
	if(!CreateData(a,ARRAYLEN,1,100))
	{
		cout << "��������ɲ��ɹ�";
		getch();
		return 1;
	}
	cout << "ԭ���ݣ�";
	for(i = 0;i < ARRAYLEN;i++)
		cout << a[i] << " ";
	cout << endl;
	MergeSort(a,ARRAYLEN);
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