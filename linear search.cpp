#include<stdio.h> 

#include<string.h> 

void search(char string[][100],int n,char word[]) 
{ 
	int i,found=0; 
		for(i=0;i<n;i++) 
		{ 
			if(strcmp(word,string[i])==0) 
			{ 
				found=1; 
				printf("String %s is there\n",word); 
			} 
		} 
		
		if(found==0) 
			printf("String %s is not there\n",word); 
} 

int main() 
{ 
	char string[100][100],word[40]; 
	int i,n; 
	printf("Enter the number of Strings:\n"); 
	scanf("%d",&n); 
	printf("Enter the Strings:\n"); 
	for(i=0;i<n;i++) 
	{ 
		scanf("%s",string[i]); 
	} 
	printf("Enter the string to be search:"); 
	scanf("%s",word); 
	search(string,n,word); 
} 


