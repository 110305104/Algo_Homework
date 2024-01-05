#include <stdio.h>
#pragma warning( disable : 4996 )
#include <stdio.h>

#define MAX_NODES 1002//因為ReadGraph的node是從1開始不是0 要多留空間

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int num_nodes;
void printG();
int hasCycleUtil(int graph[MAX_NODES][MAX_NODES], int num_nodes, int node, int parent);

//讀圖 
int ReadGraph() {
    int neighbor, num_vertices;
    char temp;
    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        int size = 0;
        int node;
        do {
            if (scanf("%d%c", &neighbor, &temp) == EOF) {
                graph[node][neighbor] = 1;
                break;
            }
            if (size == 0) {
                node = neighbor;
                size++;
            }
            else
            {
                graph[node][neighbor] = 1;
            }
        } while (temp != '\n');
    }
    return num_vertices;
}

//dfs標記connected nodes 
void dfs(int graph[MAX_NODES][MAX_NODES], int num_nodes, int node) {
    visited[node] = 1;

    for (int i = 1; i <= num_nodes; i++) {//因為ReadGraph的node是從1開始不是0 for迴圈要從1開始跑不然會錯(多一組connected component)
        if (graph[node][i] && !visited[i]) {
            dfs(graph, num_nodes, i);
        }
    }
}

//算NumOfConnectedComponents
int countConnectedComponents(int graph[MAX_NODES][MAX_NODES], int num_nodes) {
    int count = 0;

    for (int i = 1; i <= num_nodes; i++) {
        visited[i] = 0;
    }

    for (int i = 1; i <= num_nodes; i++) {
        if (!visited[i]) {
            dfs(graph, num_nodes, i);
            count++;
        }
    }

    return count;
}

//判斷是否有cycle
int hasCycle(int graph[MAX_NODES][MAX_NODES], int num_nodes) {
    for (int i = 1; i <= num_nodes; i++) {
        visited[i] = 0;
    }

    for (int i = 1; i <= num_nodes; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(graph, num_nodes, i, -1)) {
                return 1;
            }
        }
    }

    return 0;
}

int hasCycleUtil(int graph[MAX_NODES][MAX_NODES], int num_nodes, int node, int parent) {
    visited[node] = 1;

    for (int i = 1; i <= num_nodes; i++) {
        if (graph[node][i]) {
            if (!visited[i]) {
                if (hasCycleUtil(graph, num_nodes, i, node)) {
                    return 1;
                }
            }
            else if (i != parent) {
                return 1;
            }
        }
    }

    return 0;
}


int main() {

    num_nodes = ReadGraph();

    //printG();

    for (int i = 0; i <= num_nodes; i++) {
        visited[i] = 0;
    }
    

    int num_components = countConnectedComponents(graph, num_nodes);
    //printf("\nNumber of connected components: %d\n", num_components);
  
    if (num_components - 1 < 0)  printf("0 ");
    else printf("%d ", num_components-1);

    if (hasCycle(graph, num_nodes)) {
        //printf("The graph contains a cycle.\n");
        printf("1");
    }
    else {
        //printf("The graph does not contain a cycle.\n");
        printf("0");
    }

    return 0;
}



//確認讀進來的圖是對的
void printG() {

    printf("\t");
    for (int i = 1; i <= num_nodes; i++) {
        printf("%d\t", i);
    }
    printf("\n");

    for (int i = 0; i < num_nodes; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < num_nodes; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

}