#include <stdio.h> 
#include<string.h> 

void search(char string[][20],int n,char word[]) 
{ 
	int l,mid,u; 
	l=0; 
	u=n; 
	do 
	{ 
		mid =(l+u)/2; 
	    if ((strcmp(word,string[mid]))<0) 
	 		u=mid-1; 
	 	else if((strcmp(word,string[mid]))>0) 
	 		l= mid+1; 
	}while((strcmp(word,string[mid])!=0)&&l<=u); 

if((strcmp(word,string[mid]))==0) 
	printf("String Present\n"); 
else 
	printf("String Not Present\n"); 
} 

int main() 
{ 
	char string[20][20],t[20],word[20]; 
	int i, j, n; 
	printf("Enter the number of Strings:\n"); 
	scanf("%d", &n); 
	printf("Enter the Strings:\n"); 
 	for (i=0;i<n;i++) 
 		scanf("%s",string[i]); 
			for (i=1;i<n;i++) 
 			{ 
 				for (j=1;j<n;j++) 
 				{ 
					if (strcmp(string[j-1],string[j])>0) 
 					{ 
						strcpy(t,string[j-1]); 
						strcpy(string[j-1],string[j]); 
						strcpy(string[j],t); 
 					} 
 				} 
 			} 
 printf("\nEnter the String to be searched:\n"); 
 scanf("%s",word); 
 search(string,n,word); 
} 
