#include <stdio.h>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

void	Swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	SelectionSort(int arr[], int size)
{
	int	min;
	int index = 0;

	for (int j = 0; j < size; j++)
	{	
		min = INT_MAX;
		for (int i = j; i < size; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
				index = i;
			}
		}
		Swap(&arr[j], &arr[index]);
	}
}

void	BubbleSort(int arr[], int size)
{
	for (int j = 0; j < size; j++)
	{	
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				Swap(&arr[i], &arr[i + 1]);
		}
		size--;
	}
}

void	QuickSort(int arr[], int left, int right)
{
	int size = right - left + 1;
	int	pivot_index = (size / 2) + left;
	int pivot_value = arr[pivot_index];

	Swap(&arr[pivot_index], &arr[right]);
	right--;
	while (left != right)
	{
		if (arr[left] >= pivot_value)
			break;
		left++;
	}
	while (left != right)
	{
		if (arr[right] < pivot_value)
			break;
		right--;
	}
	if (left == right)
		Swap(&arr[pivot_index], &arr[left]);
	else
		Swap(&arr[left], &arr[right]);


}

int	main()
{
	int	arr[10] = {100, 50, 60, 10, 15, 20, 40, 30, 90, 80};
	int	len = sizeof(arr) / sizeof(int);

	//Swap(&arr[0], &arr[1]);
	
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	//SelectionSort(arr, len);
	//BubbleSort(arr, len);
	//printf("%d\n", len);
	QuickSort(arr, 0, len - 1);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return (0);
}
