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



int main()
{
	int i,a,b1,b2,m,g1[100],g2[100],count;
	cout << "�������Χ��";
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
			cout << "\n\n" << a << " -- " << b1 << "����������������Ϊ��";
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