// C++ program to implement Best First Search using priority
// queue
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<vector<pi> > graph;

// Function for adding edges to graph
void addedge(int x, int y, int cost)
{
	graph[x].push_back(make_pair(cost, y));
	graph[y].push_back(make_pair(cost, x));
}

// Function For Implementing Best First Search
// Gives output path having lowest cost
void best_first_search(int source, int target, int n)
{
	vector<bool> visited(n, false);
	// MIN HEAP priority queue
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	// sorting in pq gets done by first value of pair
	pq.push(make_pair(0, source));
	int s = source;
	visited[s] = true;
	while (!pq.empty()) {
		int x = pq.top().second;
		// Displaying the path having lowest cost
		cout << x << " ";
		pq.pop();
		if (x == target)
			break;

		for (int i = 0; i < graph[x].size(); i++) {
			if (!visited[graph[x][i].second]) {
				visited[graph[x][i].second] = true;
				pq.push(make_pair(graph[x][i].first,graph[x][i].second));
			}
		}
	}
}

// Driver code to test above methods
int main()
{
	// No. of Nodes
	int v = 14;
	graph.resize(v);

	// The nodes shown in above example(by alphabets) are
	// implemented using integers addedge(x,y,cost);
	addedge(0, 1, 1);
	addedge(0, 2, 4);
	addedge(1, 2, 3);
	addedge(1, 3, 6);
	addedge(1, 4, 7);
	addedge(2, 3, 8);
	addedge(3, 4, 10);

	int source = 0;
	int target = 4;

	// Function call
	best_first_search(source, target, v);

	return 0;
}
