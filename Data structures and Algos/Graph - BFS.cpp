
// Each vertex has a node ID
// Graph represented by an adjacency list
// Need to keep track of visited vertices. (otherwise maybe lead to infinite loops in cyclic graphs)
// Assume 0 as starting node
// Assume that all other vertices are reachable from starting node.


vector<int> graph[SIZE];

bool visited[SIZE];
mem(visited,false); // Setting all values to false

queue<int> q;
q.insert(0);

while (!q.empty)
{	
	int node = q.pop();

	cout << "visited " << node;

	for (int i = 0; i<graph[node].size(); i++)
	{	
		int neighbour = graph[node][i];
		if (!visited[neighbour])
			{	visited[neighbour] = true;
				q.insert(neighbour);
			}
	}
}