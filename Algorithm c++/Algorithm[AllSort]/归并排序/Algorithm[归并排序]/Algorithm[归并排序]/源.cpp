#include "head.h"

#define MAX 32767

int merge(int *aarray, int p, int q,int r)
{
	int tempSum = 0;
	int n1 = q - p + 1;
	int n2 = r - q;
	int *left = NULL;
	int *right = NULL;
	int i , j , k;

	left = new int[n1 + 1];
	right = new int[n2 + 1];

	for(i = 0; i < n1; i++)
		left[i] = aarray[p + i];

	for(j = 0; j < n2; j++)
		right[j] = aarray[q + 1 + j];

	left[n1] = MAX;
	right[n2] = MAX;

	i = 0;
	j = 0;

	for(k = p; k <= r; k++)
	{
	    if(left[i] <= right[j])
		{
		    aarray[k] = left[i];
			i++;
		}
		else
		{
		    aarray[k] = right[j];
			j++;
			tempSum += n1 - i;
		}
	}
	delete left;
	delete right;
	left = NULL;
	right = NULL;
	return tempSum;
}

int mergeSort(int *aarray, int start, int end)
{
	int sum = 0;
	if(start < end)
	{
	    int mid = (start + end) / 2;
		sum += mergeSort(aarray, start, mid);
		sum += mergeSort(aarray, mid + 1, end);
		sum += merge(aarray, start, mid, end);
	}
	return sum;
}

void main()
{
	int aarray[5] = {9,1,0,5,4};
	int inversePairNum;

	int i;

	inversePairNum = mergeSort(aarray,0,4);
	for(i = 0 ; i < 5; i++)
		cout << aarray[i] << " " ;
	getch();
}