#include<stdio.h> 
#define INF 99999 

int main() 
{ 
 	int graph[4][4]= 
 	{ 
 		{5,10,INF,10}, 
 		{11,12,3,INF}, 
		{3,INF,7,11}, 
 		{2,10,INF,0} 
 	}; 
 	
 	int dist[4][4],i,j,k; 
 	for(i=0;i<4;i++) 
 	for(j=0;j<4;j++) 
 	dist[i][j]=graph[i][j]; 
 	for (k=0;k<4;k++) 
 	{ 
 		for(i=0;i<4;i++) 
 		{ 
 			for(j=0;j<4;j++) 
 			{ 
 				if(dist[i][k]+dist[k][j]<dist[i][j]) 
 				{ 
 					dist[i][j]=dist[i][k]+dist[k][j]; 
				} 
 			} 
 		} 
 	} 
 	
	printf("The Matrix is:\n"); 
 	for(i=0;i<4;i++) 
 	{ 
 		for(j=0;j<4;j++) 
 		{ 
			if(dist[i][j]==INF) 
			printf("%7s","INF"); 
 		else 
 			printf("%7d",dist[i][j]); 
 		} 
 	printf("\n"); 
 	} 
} 

