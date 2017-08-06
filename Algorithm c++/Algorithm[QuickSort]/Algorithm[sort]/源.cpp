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
int Division(int a[],int left,int right)
{
	int base = a[left];
	while(left < right)
	{
		while(left < right && a[right] > base)
			--right;
		a[left] = a[right];
		while(left < right && a[left] < base)
			++left;
		a[right] = a[left];
	}
	a[left] =  base;
	return left;
}
void QuickSort(int a[],int left,int right)
{
	int i ,j;
	if(left < right)
	{
		i = Division(a,left,right);
		QuickSort(a,left,i-1);
		QuickSort(a,i+1,right);
	}
}

int main()
{
	 clock_t start,finish;
   double totaltime;
   start=clock();
	int i,a[ARRAYLEN];
	for(i = 0;i < ARRAYLEN;i++)
		a[i]  = 0;
	if(!CreateData(a,ARRAYLEN,1,10000))
	{
		cout << "������������ɹ���\n";
		getch();
		return 1;
	}
	cout << "ԭ���ݣ�";
	for(i = 0;i < ARRAYLEN ; i++)
		cout << a[i] << " " ;
	cout << endl;
	QuickSort(a,0,ARRAYLEN -1);
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