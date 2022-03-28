#include <stdio.h>
int firstFit(int weight[], int n, int c)
{
 int res = 0;
 int bin_rem[n];
 for (int i = 0; i < n; i++) {
 int j;
 for (j = 0; j < res; j++) {
 if (bin_rem[j] >= weight[i]) {
 bin_rem[j] = bin_rem[j] - weight[i];
 break;
 }
 }
 if (j == res) {
 bin_rem[res] = c - weight[i];
 res++;
 }
 }
 return res;
}
int main()
{
 
 int weight[] = { 6, 12, 5, 4, 7, 8, 5, 6, 2,1 };
 int c = 10;
 int n = sizeof(weight) / sizeof(weight[0]);
 int a=firstFit(weight, n, c);
 printf("Number of bins required in First Fit : %d",a);
 return 0;
}
