/*
Assigned by:
Noy Meir 311401277
Daniella Babayev 316013630
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void quicksort(int *arr, int first, int last);
void assign_graph(int *arr,int n);

void main()
{
	int n, i, *arr;
	printf("Please enter number of Nodes in graph G: \n");
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	printf("Please enter %d natural numbers as the degrees of the nodes in G: \n", n);
	for (i = 0; i < n; i++)
	{
		printf("#%d number:", i + 1);
		scanf("%d", &(arr[i]));
	}

	assign_graph(arr, n);

	free(arr);
}

void assign_graph(int *arr, int n)
{
	/*m=|E|, a=a(G)*/
	/*initialize the a and m pointers values*/
	int i, sum=0, m = 0, a = 0;
	
	/*first we will sort the list array of degrees by quicksort*/
	quicksort(arr, 0, n - 1);

	/*we add all the values of the nodes in arr to m, and then divide by 2, it will give us the number of edges*/
	for (i = 0; i < n; i++)
	{
		m += arr[i];
	}
	m /= 2;

	/*we add the value of each node in the array into sum variable, and we increase the value of a in 1 each iteration*/
	/*the iteration continues until sum will be equal or bigger than m */
	for (i = 0; sum<m; i++)
	{
		sum += arr[i];
		a++;
	}

	/*output*/
	/*printing the sorted array, m = |E|, and a = a(G)*/
	printf("The sorted list is:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	printf("The number of edges of G:\n");
	printf("m = |E| = %d\n", m);
	printf("a(G) = %d\n", a);
}

void quicksort(int *arr, int first, int last)
{
	int i, j, pivot, temp;

	if (first < last) {
		pivot = first;
		i = first;
		j = last;

		while (i < j) {
			while (arr[i] <= arr[pivot] && i < last)
				i++;
			while (arr[j] >arr[pivot])
				j--;
			if (i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		quicksort(arr, first, j - 1);
		quicksort(arr, j + 1, last);

	}
}
