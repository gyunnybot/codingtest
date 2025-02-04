#include<iostream>
using namespace std;

int n;
char parent, L, R;
pair<char, char> adj[28];

void preorder(char here) {
	if (here == '.') return;

	cout << here;
	preorder(adj[here - 'A'].first);
	preorder(adj[here - 'A'].second);

	return;
}

void inorder(char here) {
	if (here == '.') return;

	inorder(adj[here - 'A'].first);
	cout << here;
	inorder(adj[here - 'A'].second);

	return;
}

void postorder(char here) {
	if (here == '.') return;

	postorder(adj[here - 'A'].first);
	postorder(adj[here - 'A'].second);
	cout << here;

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
	preorder('A'); cout << '\n';
	inorder('A'); cout << '\n';
	postorder('A');

	return 0;
}
