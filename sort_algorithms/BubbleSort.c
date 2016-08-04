#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(int argc, char *argv[])
{
	int swap_flag = 0;

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

			for (int i = 0; i < n - 1; i++)
			{
				swap_flag = 0;
				for (int  j = 0; j < n - i -1; j++)
				{
					if (arr[j] > arr[j+1])
					{
						swap(&arr[j], &arr[j+1]);
						swap_flag = 1;
					}
				}
				if (!swap_flag)
				{
					break;
				}
			}

			for (int i = 0; i < n; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");

			return 0;
		}
	}
}

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
