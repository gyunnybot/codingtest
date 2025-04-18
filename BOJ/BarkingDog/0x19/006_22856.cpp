#include<iostream>
using namespace std;

int n, parent, L, R, ret, last_node;
bool flag, visited[100001];
pair<int, int> adj[100001];

void recur(int here) {
	int left = adj[here].first;
	int right = adj[here].second;

	if (left != -1) {
		ret++;
		recur(left);

		if (!flag) { //left가 루트인 서브 트리 탐색 후 올라오기
			ret++;
		}
	}

	if (right != -1) {
		ret++;
		recur(right);

		if (!flag) { //right가 루트인 서브 트리 탐색 후 올라오기
			ret++;
		}
	}

	if (here == last_node) {
		flag = true;
		return; //last_node를 만나면 즉시 return
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

	inorder(1); //중위 순회로 유사 중위 순회의 끝 찾기
	recur(1); //유사 중위 순회 시작

	cout << ret;

	return 0;
}
