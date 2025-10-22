#include<iostream>
#include<vector>
using namespace std;

bool visited[1001];
vector<int> adj[1001];

void dfs(int here) {
	visited[here] = true;
	cout << here << ' ';

	for (int there : adj[here]) {
		if (!visited[there]) {
			dfs(there);
		}
	}

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	adj[1].push_back(2);
	adj[1].push_back(3);

	adj[2].push_back(4);
	adj[2].push_back(5);

	dfs(1);

	return 0;
}
