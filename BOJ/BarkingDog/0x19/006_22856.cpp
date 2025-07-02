#include<iostream>
using namespace std;

int n, node, L, R, ret, end_node;
bool flag, visited[100001];
pair<int, int> adj[100001];

void semi_in_order(int here) {
	int left = adj[here].first;
	int right = adj[here].second;

	if (left != -1) {
		ret++;
		semi_in_order(left); //left가 루트 노드인 서브 트리 탐색

		if (!flag) { //루트 노드이지만 end_node가 아니라면 올라오기
			ret++;
		}
	}

	if (right != -1) {
		ret++;
		semi_in_order(right); //right가 루트 노드인 서브 트리 탐색

		if (!flag) { //루트 노드이지만 end_node가 아니라면 올라오기
			ret++;
		}
	}

	if (here == end_node) {
		flag = true;
	}

	return;
}

void in_order(int here) {
	if (here == -1) return;

	in_order(adj[here].first);
	end_node = here;
	in_order(adj[here].second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> node >> L >> R;

		adj[node].first = L;
		adj[node].second = R;
	}

	in_order(1); //중위 순회로 유사 중위 순회의 끝 end_node 찾기
	semi_in_order(1); //유사 중위 순회 시작. 루트 노드는 항상 1번 노드이다

	cout << ret;

	return 0;
}
