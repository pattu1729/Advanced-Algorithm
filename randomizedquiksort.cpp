#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n;
void shufflerandom(int arr[])
{
srand(time(NULL));
int i, j, te;
for (i=n-1;i>0; i--)
{
j = rand()%(i + 1);
te = arr[i];
arr[i] = arr[j];
arr[j] = te;
}
}
void swap(int *a, int *b)
{
int te;
te = *a;
*a = *b;
*b = te;
}
int partion(int arr[],int low,int high)
{
//p low r-high
int pivotIndex=low+rand()%(high-low+1); //generates a random numberas a pivot

int pivot,j;
int i=low-1;
pivot=arr[pivotIndex];
swap(&arr[pivotIndex], &arr[high]);
for (j=low;j<high;j++)
{
if (arr[j]<pivot)
{
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i+1], &arr[high]);
return i + 1;
}
void quicksort(int arr[], int low, int high)
{
int j;
if (low<high)
{
j=partion(arr,low,high);
quicksort(arr,low,j-1);
quicksort(arr, j+1, high);
}
}
int main()
{

printf("Enter the Array size:");
scanf("%d",&n);
int i;
int arr[n];
printf("Enter the %d Elements in array:\n",n);
for (i = 0;i<n; i++)
scanf("%d",&arr[i]);
printf("Unsorted Array is:\n");
printf("[");
for (i = 0; i<n; i++)
printf(" %d ",arr[i]);
printf("]\n");
shufflerandom(arr); //To randomize the array
quicksort(arr, 0,n-1); //function to sort the elements of array
printf("Randomized Quick sort array is:\n");
printf("[");
for (i = 0; i <n; i++)
printf(" %d ", arr[i]);
printf("]\n");
return 0;
}
