#include<iostream>
#include<vector>
using namespace std;

int n, temp, root, node;
bool visited[51];
vector<int> adj[51];

int dfs(int here) {
	visited[here] = true;

	int leaf = 0;
	int child = 0;

	for (int there : adj[here]) {
		if (there == node) {
			continue;
		}

		if (!visited[there]) {
			leaf += dfs(there);

			child++;
		}
	}

	if (!child) {
		leaf++;
	}

	return leaf;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		
		if (temp == -1) {
			root = i;
		}
		else {
			adj[temp].push_back(i);
		}
	}

	cin >> node;

	if (node == root) {
		cout << 0;
	}
	else {
		cout << dfs(root);
	}

	return 0;
}
