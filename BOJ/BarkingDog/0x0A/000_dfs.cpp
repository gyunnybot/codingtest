#include<iostream>
#include<vector>
using namespace std;

bool visited[1001];
vector<int> adj[1001];

void dfs(int here) {
	visited[here] = true;

	for (int there : adj[here]) {
		if (!visited[there]) {
			dfs(there);
		}
	}

	return;
}