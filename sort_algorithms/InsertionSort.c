#include <stdio.h>
#include <stdlib.h>

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
			int j, temp;
			for (int i = 1; i < n; i++)
			{
				temp = arr[i];
				for (j = i - 1; j >= 0 && temp < arr[j]; j--)
				{
					arr[j+1] = arr[j];
				}
				arr[j+1] = temp;
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

