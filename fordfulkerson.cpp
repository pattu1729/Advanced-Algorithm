#include <stdio.h> 

int n; 
int e; 
int capacity[100][100]; 
int flow[100][100]; 
int color[100]; 
int pred[100]; 
int min(int x, int y) 
{ 
	return x < y ? x : y; 
} 
int head, tail; 
int q[100 + 2]; 

void enqueue(int x) 
{ 
	q[tail] = x; 
	tail++; 
	color[x] = 1; 
} 

int dequeue() 
{ 
	int x = q[head]; 
    head++; 
	color[x] = 2; 
    return x; 
} 

int bfs(int start, int target) 
{ 
	int u, v; 
	for (u = 0; u < n; u++) 
	{ 
		color[u] = 0; 
	} 
	head = tail = 0; 
	enqueue(start); 
	pred[start] = -1; 
	while (head != tail) 
	{ 
		u = dequeue(); 
			for (v = 0; v < n; v++) 
			{ 
 				if (color[v] == 0 && capacity[u][v] - flow[u][v] > 0) 
				{ 
					enqueue(v); 
					pred[v] = u; 
				} 
			} 
	} 
return color[target] == 2; 
}  

int fordFulkerson(int source, int sink) 
{ 
	int i, j, u; 
	int max_flow = 0; 
	for (i = 0; i < n; i++) 
	{ 
		for (j = 0; j < n; j++) 
		{ 
			flow[i][j] = 0; 
		} 
	} 
while (bfs(source, sink)) 
{ 
	int increment = 10000; 
	for (u = n - 1; pred[u] >= 0; u = pred[u]) 
	increment = min(increment, capacity[pred[u]][u] - flow[pred[u]][u]); 
	for (u = n - 1; pred[u] >= 0; u = pred[u]) 
 	{ 
		flow[pred[u]][u]+=increment; 
		flow[u][pred[u]]-=increment; 
	} 
	max_flow+=increment; 
} 

return max_flow; 
} 

int main() 
{ 
	n = 6; 
	e = 7; 
	capacity[0][1]=8; 
	capacity[0][4]=5; 
	capacity[1][2]=3; 
	capacity[2][4]=8; 
	capacity[2][5]=9; 
	capacity[3][5]=2; 
	capacity[4][2]=1; 
	capacity[4][3]=3; 
	int s=0,t=5; 
	printf("Maximum Flow is: %d\n", fordFulkerson(s,t)); 
} 

