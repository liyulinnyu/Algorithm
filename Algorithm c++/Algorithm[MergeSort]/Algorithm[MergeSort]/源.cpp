#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<conio.h>
#include<deque>     //队列
#include<list>       //列表容器
#include<set>        //集合容器，多重集合容器
#include<windows.h>   //windows相关函数，窗体函数库
#include<iostream>   // I/O
#include<queue>      //队列
#include<vector>     
#include<stack>       //堆
#include<iomanip>     //目前包含4个函数：【setw(n)是设置域宽，就是要输出几个字符】【setfill(char c)括号中的字符要用单引号！ 用法 : 就是在预设宽度中如果                        已存在没用完的宽度大小，则用设置的字符c填充,注意顺序！！】  【setbase(int n) : 将数字转换为 n 进制,直接在加<<要输出的数即可】             【setprecision(n)可控制输出流显示浮点数的数字个数。C++默认的流输出数值有效位是6。setiosflags(ios::fixed)合用，可以控制小数点右边的数字个数】
#include<process.h>   
#include<dos.h> 
#include<cctype>   //isalpha()等
#include<map>      //映射
#include<string>    //字符串
#include<sstream>   //引用istringstream
#include<cstddef>   //size_t  ptrdiff_t类型的定义
#include<numeric>    //通用数值算法
#include<iterator>     //迭代器类，迭代器适配器

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
	int i,j,flag;               //arr【】用来保存生成的随机数，n表示需要生成的随机数的数量，max,min表示随机数的最大值和最小值
	srand(time(NULL));                
	if((max - min + 1) < n) return 0;         //返回0表示生成不成功
	for(i = 0;i < n;i++)                //arr返回值供主程序使用
	{
		do
		{
			arr[i] = (max - min + 1)* rand() / (RAND_MAX + 1) + min;
			flag = 0;
			for(j = 0;j < i; j++)                //判断是否与已有的数字相同，若相同，则重新生成一个
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
		cout << "分配内存空间失败\n";
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
		cout << "随机数生成不成功";
		getch();
		return 1;
	}
	cout << "原数据：";
	for(i = 0;i < ARRAYLEN;i++)
		cout << a[i] << " ";
	cout << endl;
	MergeSort(a,ARRAYLEN);
		cout << "排序后：";
		for(i = 0;i < ARRAYLEN;i++)
			cout << a[i] << " ";
		cout << endl;
		  finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<endl;
		getch();
		return 0;
}