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

#define ARRAYLEN 900

void InsertSort(int a[],int n)
{
	int i,j,t;
	for(i = 1;i < n;i++)
	{
		t =a[i];
		for(j = i-1;j >= 0&& t < a[j];--j)
			a[j + 1] = a[j];
		a[j + 1] = t;
	}
}

int main()
{
	clock_t start,finish;
   double totaltime;
   start=clock();
	int i,a[ARRAYLEN];
	for(i = 0;i < ARRAYLEN;i++)
		a[i] = 0;
	if(!CreateData(a,ARRAYLEN,1,1000))
	{
		cout << "生成随机数不成功";
		getch();
		return 1;
	}
	cout << "原数据：";
	for(i = 0;i < ARRAYLEN;i++)
		cout << a[i] << " ";
	cout << endl;
	InsertSort(a,ARRAYLEN);
	cout << "排序后：";
	for(i = 0;i <ARRAYLEN;i++)
		cout << a[i] << " ";
	cout << endl;
	finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<endl;
	getch();
	return 0;
}