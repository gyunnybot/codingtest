#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool visited[1001];
vector<int> adj[1001];

void bfs(int here) {
	visited[here] = true;

	queue<int> q;
	q.push(here);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << ' ';

		for (int next : adj[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
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

	bfs(1); //1 2 3 4 5

	return 0;
}