#include<iostream>
using namespace std;

int n;
char parent, L, R;
bool visited[28];
pair<char, char> adj[28];

void preorder(char here) {
	if (here == '.') return;

	if (!visited[here - 'A']) {
		visited[here - 'A'] = true;
		cout << here;

		preorder(adj[here - 'A'].first);
		preorder(adj[here - 'A'].second);
	}


	return;
}

void inorder(char here) {
	if (here == '.') return;

	if (!visited[here - 'A']) {
		inorder(adj[here - 'A'].first);

		visited[here - 'A'] = true;
		cout << here;

		inorder(adj[here - 'A'].second);
	}

	return;
}

void postorder(char here) {
	if (here == '.') return;

	if (!visited[here - 'A']) {
		postorder(adj[here - 'A'].first);
		postorder(adj[here - 'A'].second);

		visited[here - 'A'] = true;
		cout << here;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> parent >> L >> R;

		adj[parent - 'A'].first = L;
		adj[parent - 'A'].second = R;
	}

	//항상 A가 루트 노드가 된다
	preorder('A'); fill(&visited[0], &visited[0] + 28, false); cout << '\n';

	inorder('A'); fill(&visited[0], &visited[0] + 28, false); cout << '\n';

	postorder('A');

	return 0;
}
