#include<iostream>
using namespace std;

int n, parent, L, R, ret, last_node;
bool visited[100001], flag;
pair<int, int> adj[100001];

void recur(int here) {
	int left = adj[here].first;
	int right = adj[here].second;

	if (left != -1) {
		ret++;
		recur(left);

		if (!flag) ret++;
	}

	if (right != -1) {
		ret++;
		recur(right);

		if (!flag) ret++;
	}

	if (here == last_node) {
		flag = true;
		return;
	}
}



void inorder(int here) {
	if (here == -1) return;

	inorder(adj[here].first);

	last_node = here;

	inorder(adj[here].second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> parent >> L >> R;

		adj[parent].first = L;
		adj[parent].second = R;
	}

	inorder(1);
	recur(1);

	cout << ret;

	return 0;
}
