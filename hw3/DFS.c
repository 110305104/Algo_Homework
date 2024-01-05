#pragma warning( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

int map[1000][1000];//n m
int visited[1000][1000];//n m
int n, m;
int count = 1;

int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

void cal(int a, int b) {

	if (visited[a][b] != 0)	return;
	else
	{
		count++;
		visited[a][b] = count;

		if (a - 1 >= 0 && map[a - 1][b] == map[a][b]) {
			cal(a - 1, b);
		}
		if (a + 1 < n && map[a + 1][b] == map[a][b]) {
			cal(a + 1, b);
		}
		if (b + 1 < m && map[a][b + 1] == map[a][b]) {
			cal(a, b + 1);
		}
		if (b - 1 >= 0 && map[a][b - 1] == map[a][b]) {
			cal(a, b - 1);
		}
	}

}



int main() {

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}


	int max_P = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0) {

				count = 0;
				cal(i, j);

				max_P = max(max_P, count);
			}
		}
	}
	printf("%d", max_P);

}