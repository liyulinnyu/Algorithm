#include <stdio.h>

void print_arr(int *arr, int arr_len);
void radixsort(int *arr, int base_bit, int arr_len);
long power_int(int base_n, int exp);

int main()
{
	int arr[] = {512, 51, 13, 6, 61, 40, 72, 93, 49, 25, 201, 364};
	int base_bit = 3;
	int arr_len = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, arr_len);
	radixsort(arr, base_bit, arr_len);
	print_arr(arr, arr_len);
	return 0;
}

void radixsort(int *arr, int base_bit, int arr_len)
{
	int temp_arr[10][12];
	long max_base;
	max_base = power_int(10, base_bit);
	int base = 1;
	int i, j;
	int bit;
	int count[10] = {0};
	int k = 0;
	while (base <= max_base) {
		for (i = 0; i < arr_len; i++) {
			bit = (arr[i] / base) % 10;
			temp_arr[bit][count[bit]] = arr[i];
			count[bit]++;
		}
		for (i = 0; i < 10; i++) {
			if (count[i] != 0) {
				for (j = 0; j < count[i]; j++) {
					arr[k] = temp_arr[i][j];
					k++;
				}
				count[i] = 0;
			}
		}
		base *= 10;
		k = 0;
	}

}

void print_arr(int *arr, int arr_len)
{
	int i = 0;
	while (i < arr_len) {
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

long power_int(int base_n, int exp)
{
	int i;
	long result = 1;
	for (i = 1; i < exp; i++) {
		result *= base_n;
	}
	return result;
}