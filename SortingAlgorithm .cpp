/******
排序算法
******/
#include <iostream>
#include <stdlib.h>
#include <time.h>
//得出结论，面对大数据，各种排序算法的效率为，冒泡排序<选择排序<希尔排序<快速排序=堆排序，快速排序和堆排序的效率远高于其他排序
using namespace std;
void bubbling(int *number)
{
	for (int i = 0; i < (_msize(number)) / 4; i++)
	{
		for (int j = 0; j < (_msize(number)) / 4 - 1; j++)
		{
			if (*(number + j) > *(number + j + 1))
			{
				*(number + j) += *(number + j + 1);
				*(number + j + 1) = *(number + j) - *(number + j + 1);
				*(number + j) -= *(number + j + 1);
			}
		}
	}
}
void select(int *number)
{
	for (int i = 0; i < (_msize(number)) / 4 - 1; i++)
	{
		for (int j = i + 1; j < (_msize(number)) / 4; j++)
		{
			if (*(number + i) > *(number + j))
			{
				*(number + i) += *(number + j);
				*(number + j) = *(number + i) - *(number + j);
				*(number + i) -= *(number + j);
			}
		}
	}
}
void shell(int *number)
{
	int n = _msize(number) / 4;
	if (n < 2)
		return;
	int step = n / 2;
	while (step >= 1)
	{
		for (int start = 0; start < step; start++)
		{
			for (int i = start + step; i < n; i += step)
			{
				for (int j = i - step; j >= 0; j -= step)
				{
					if (*(number + j) > *(number + j + step))
					{
						*(number + j) += *(number + j + step);
						*(number + j + step) = *(number + j) - *(number + j + step);
						*(number + j) -= *(number + j + step);
					}
				}
			}
		}
		step /= 2;
	}
}
void quick(int *arr, int low, int high)
{
	if (low < high)
	{
		int i = low;
		int j = high;
		int k = arr[low];
		while (i < j)
		{
			while (i < j && arr[j] >= k)
			{
				j--;
			}
			if (i < j)
			{
				arr[i++] = arr[j];
			}
			while (i < j && arr[i] < k)
			{
				i++;
			}
			if (i < j)
			{
				arr[j--] = arr[i];
			}
		}
		arr[i] = k;
		quick(arr, low, i - 1);
		quick(arr, i + 1, high);
	}
}
void HeapAdjust(int a[], int s, int m)
{
	int rc, j;
	rc = a[s];
	for (j = 2 * s; j <= m; j = j * 2)
	{
		if (j < m && a[j] < a[j + 1])
			j++;
		if (rc > a[j])
			break;
		a[s] = a[j];
		s = j;
	}
	a[s] = rc;
}
void heap(int a[])
{
	int temp, i, j, n;
	n = _msize(a) / 4;
	for (i = n / 2; i > 0; i--)
	{
		HeapAdjust(a, i, n);
	}
	for (i = n; i > 0; i--)
	{
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		HeapAdjust(a, 1, i - 1);
	}
}
int main(void)
{
	srand(time(NULL));
	clock_t start, end;
	int *number;
	int times = 10;
	int len;
	cin >> len;
	number = (int *)malloc(sizeof(int) * len);
	while (times)
	{
		start = clock();
		for (int i = 0; i < len; i++)
		{
			*(number + i) = rand() % 100000;
		}
		quick(number, 0, len - 1);
		/*for(int i=0;i<len;i++){
    	cout<<*(number+i)<<" ";
	}*/
		end = clock();
		cout << "第" << 11 - times << "次时间为:" << (double)(end - start) / CLOCKS_PER_SEC << endl;
		;
		times--;
	}
	return 0;
}
