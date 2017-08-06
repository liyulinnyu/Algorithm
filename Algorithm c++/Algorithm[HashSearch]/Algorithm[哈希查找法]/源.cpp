#include "head.h"

#define haxi_LEN 13
#define TABLE_LEN 8

int data[TABLE_LEN] = {56,68,92,39,95,62,29,55};



void Inserthaxi(int hash[],int m,int data)
{
	int i;
	i = data % 13;
	while(hash[i])
	{
	    i = (++i) % m;
	}
	hash[i] = data;
}

void Createhaxi(int hash[],int m,int data[],int n)
{
	int i;
	for(i = 0; i < n; i++)
		Inserthaxi(hash,m,data[i]);
}

int haxisou(int hash[],int m,int key)
{
	int i;
	i = key % 13;
	while(hash[i] && hash[i] != key)
		i = (++i) % m;
	if(hash[i] == 0)
		return -1;
	else
		return i;
}

int main()
{
	int key,i,pos;
	int hash[haxi_LEN] = {0};
	Createhaxi(hash,haxi_LEN,data,TABLE_LEN);
	cout << "哈希表中各元素值：" << endl;
	for(i = 0; i < haxi_LEN ; i++)
		cout << hash[i] << " ";
	cout << endl;
	cout << "输入查找的关键字：" << " ";
	cin >> key;
	pos = haxisou(hash,haxi_LEN,key);
	if(pos > 0)
		cout << "查找成功，关键字位于数组的第" << pos << "个位置" << endl;
	else
		cout << "查找失败" << endl;
	getch();
	return 0;
}