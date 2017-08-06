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

#define ARRAYLEN 10
int source[] = {6,12,28,37,54,65,69,83,90,92};
int BinarySearch(int s[],int n,int key)
{
	int low,high,mid;
	low = 0;
	high = n - 1;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(s[mid] == key)
			return mid;
		else if(s[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main()
{
	int key,i,pos;
	cout << "输入关键字：";
	cin >> key;
	pos = BinarySearch(source,ARRAYLEN,key);
	cout << "原数据表：";
	for(int i = 0; i< ARRAYLEN;i++)
		cout << source[i] << " ";
	cout << endl;
	if(pos >= 0)
		cout << "查找成功，关键字在第" << pos+1 << "个位置" << endl;
	else
		cout << "查找失败" << endl;
	getch();
	return 0;
}