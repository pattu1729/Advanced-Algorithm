#include<stdio.h>
int bestFit(int weight[], int n, int c)
{
 int res = 0;
 int bin_rem[n];
 for (int i = 0; i < n; i++) {
 int j;
 int min = c + 1, bi = 0;
 for (j = 0; j < res; j++) {
 if (bin_rem[j] >= weight[i] && bin_rem[j] -
 weight[i] < min) {
 bi = j;
 min = bin_rem[j] - weight[i];
 }
 }
 if (min == c + 1) {
 bin_rem[res] = c - weight[i];
 res++;
 }
 else
 bin_rem[bi] -= weight[i];
 }
 return res;
}
int main()
{
 int weight[] = {5, 4, 1, 3, 7, 1};
 int c = 10;
 int n = sizeof(weight) / sizeof(weight[0]);
 int b=bestFit(weight, n, c);
 printf("Number of bins required in Best Fit : %d",b);
 return 0;
}
