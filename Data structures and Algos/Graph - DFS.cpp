// Each vertex has a node ID
// Graph represented by an adjacency list
// Need to keep track of visited vertices. (otherwise maybe lead to infinite loops in cyclic graphs)
// Assume 0 as starting node
// Assume that all other vertices are reachable from starting node.

vector<int> graph[SIZE];

bool visited[SIZE];
mem(visited,false); // Setting all values to false

void DFS(int v)
{
	visited[v] = true;

	for (int i = 0; i<graph[v].size(); i++)
	{
		int neighbour = graph[v][i];
		if (!visited[neighbour])
			DFS(neighbour);
	}
}

DFS(0);