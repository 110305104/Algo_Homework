#pragma warning( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>
#include <stdio.h>
int V;
int graph[1005][1005];//n n

struct wood
{
	int start;
	int end;
};
typedef struct wood Wood;


int isOverlap(Wood A, Wood B) {

	if (A.start <= B.start && A.end > B.start)	return 1;
	if (A.start >= B.start && A.start < B.end)	return 1;
	return 0;
}


int minDistance(int dist[], bool sptSet[]) {
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}

void dijkstra(int src, int des) {
	des--;
	int dist[1005];
	bool sptSet[1005];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) dist[v] = dist[u] + graph[u][v];
	}
	printf("%d", dist[des]);
}

int main() {
	int n;

	scanf("%d", &n);
	V = n;
	Wood woods[1005];


	for (int i = 0; i < n; i++) {
		scanf("%d%d", &woods[i].start, &woods[i].end);
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)	graph[i][j] = 0;
			else
			{
				graph[i][j] = isOverlap(woods[i], woods[j]);
			}
		}
	}

	dijkstra(0, n);

}