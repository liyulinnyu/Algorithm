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
	cout << "����ؼ��֣�";
	cin >> key;
	pos = BinarySearch(source,ARRAYLEN,key);
	cout << "ԭ���ݱ�";
	for(int i = 0; i< ARRAYLEN;i++)
		cout << source[i] << " ";
	cout << endl;
	if(pos >= 0)
		cout << "���ҳɹ����ؼ����ڵ�" << pos+1 << "��λ��" << endl;
	else
		cout << "����ʧ��" << endl;
	getch();
	return 0;
}