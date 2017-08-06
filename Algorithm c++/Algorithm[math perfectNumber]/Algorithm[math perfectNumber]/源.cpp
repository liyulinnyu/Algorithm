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



int main()
{
	int i,a,b1,b2,m,g1[100],g2[100],count;
	cout << "输入最大范围：";
	cin >> m;
	for(a = 1; a < m;a++)
	{
		for(i = 0; i < 100; i++)
			g1[i] = g2[i] = 0;
		count = 0;
		b1 = 0;
		for(i = 1;i < a/2 + 1; i++ )
		{
			if(a % i == 0)
			{
				g1[count ++] = i;
				b1 += i;
			}
		}
		count = 0;
		b2 = 0;
		for(i = 1; i < b1/2 + 1; i++)
		{
			if(b1 % 1 == 0)
			{
				g2[count++] = i;
				b2 = b2 + i;
			}
		}
		if(b2 == a && a < b1)
		{
			cout << "\n\n" << a << " -- " << b1 << "是亲密数，各因子为：";
			cout << endl << a << " = 1";
			count = 1;
			while(g1[count] > 0)
			{
				cout << " + " << g1[count];
				count ++;
			}
			cout << endl << b1 << " = 1";
			count = 1;
			while(g2[count] > 0)
			{
				cout << " + " << g2[count];
				count ++ ;
			}
		}
	}
	getch();
	return 0;
}