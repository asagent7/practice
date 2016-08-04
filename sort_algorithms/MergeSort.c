#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *arr, int max, int min);
void Merge(int *arr, int max, int mid, int min);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: Enter length and data\n");
		return 1;
	}
	else
	{
		int n = atoi(argv[1]);

		if(argc - 2 != n)
		{
			printf("Error: Enter correct number of data elements\n");
			return 2;
		}
		else
		{
			int arr[n];
			for (int i = 0; i < n; i++)
			{
				arr[i] = atoi(argv[2+i]);
			}

			for (int i = 0; i < n; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
			MergeSort(arr, n - 1, 0);

			for (int i = 0; i < n; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");

			return 0;
		}
	}
}

void MergeSort(int *arr, int max, int min)
{
	if (max != min)
	{
		int mid = (max + min) >> 1;
		MergeSort(arr, mid, min);
		MergeSort(arr, max, mid + 1);
		Merge(arr, max, mid, min);
	}
}

void Merge(int *arr, int max, int mid, int min)
{
	int merged_arr[max - min + 1];
	int i = min, j = mid + 1, k = 0;

	while (i <= mid && j <= max)
	{
		if (arr[i] <= arr[j])
		{
			merged_arr[k++] = arr[i++];
		}
		else if (arr[i] > arr[j] )
		{
			merged_arr[k++] = arr[j++];
		}
	}

	while(i <= mid)
	{
		merged_arr[k++] = arr[i++];
	}

	while (j <= max)
	{
		merged_arr[k++] = arr[j++];
	}

	for (i = min, j = 0; i <= max; i++, j++)
	{
		arr[i] = merged_arr[j];
	}
}
