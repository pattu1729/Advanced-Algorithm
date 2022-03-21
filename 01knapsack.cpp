#include<stdio.h> 

int max(int a,int b) 
{ 
	return a>b?a:b; 
} 

void knapsack(int wt,int wei[],int val[],int n) 
{ 
 	int i,j; 
 	int arr[n+1][wt+1]; 
 	for(i=0;i<=n;i++) 
  	{ 
 		for(j=0;j<=wt;j++) 
 		{ 
 			if(i==0||j==0) 
 				arr[i][j]=0; 
 			else if (wei[i-1]<=j)
 				arr[i][j]=max(val[i-1]+arr[i-1][j-wei[i-1]],arr[i-1][j]); 
 			else 
 				arr[i][j]=arr[i-1][j]; 
 		} 
	} 
 	printf("The total value for the kanapsack weight %d is %d:\n",wt,arr[n][wt]); 
} 

int main() 
{ 
 	int i,n,val[20],wei[20],wt;; 
 	printf("Enter the number of items:\n"); 
 	scanf("%d",&n); 
 	printf("Enter the value of an items:"); 
 	for(i=0;i<n;i++) 
 		scanf("%d",&val[i]); 
 	printf("Enter the weightght of an items:"); 
 	for(i=0;i<n;i++) 
 		scanf("%d",&wei[i]); 
 	for(i=0;i<n;i++) 
 		printf("The value of an item %d is %d and it weight is %d.\n",i+1,val[i],wei[i]); 
 	printf("Enter the weight of an kanpsack:"); 
 	scanf("%d",&wt); 
 	knapsack(wt,wei,val,n); 
 	return 0; 
} 


