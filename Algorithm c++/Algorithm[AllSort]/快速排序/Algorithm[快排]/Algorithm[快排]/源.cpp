#include<iostream>  
using namespace std;  
void quickSort(int a[],int,int);  
int main()  
{  
	int array[]={34,65,12,43,67,5,78,10,3,70},k;  
	int len=sizeof(array)/sizeof(int);  
	cout<<"³õÊ¼:"<<endl;  
	for(k=0;k<len;k++)  
		cout<<array[k]<<",";  
	cout<<endl;  
	quickSort(array,0,len-1);  
	cout<<"ÅÅÐòºó:"<<endl;  
	for(k=0;k<len;k++)  
		cout<<array[k]<<",";  
	cout<<endl;  
	system("pause");  
	return 0;  
}  

void quickSort(int s[], int l, int r)  
{  
	if (l< r)  
	{        
		int i = l, j = r, x = s[l];  
		while (i < j)  
		{  
			while(i < j && s[j]>= x)  
				j--;   
			if(i < j)  
				s[i++] = s[j];  
			while(i < j && s[i]< x)
				i++;   
			if(i < j)  
				s[j--] = s[i];  
		}  
		s[i] = x;  
		quickSort(s, l, i - 1);
		quickSort(s, i + 1, r);  
	}  
}  