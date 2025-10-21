#include<iostream>
#include<queue>
using namespace std;

int n, ret, visited[1000001];

void bfs(int n) {
	visited[n] = 1;

	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (cur == 1) {
			ret = visited[cur] - 1;
			break;
		}
		
		if (cur - 1 >= 1 && !visited[cur - 1]) {
			visited[cur - 1] = visited[cur] + 1;
			q.push(cur - 1);
		}

		if ((cur % 2) == 0 && !visited[cur / 2]) {
			visited[cur / 2] = visited[cur] + 1;
			q.push((cur / 2));
		}

		if ((cur % 3) == 0 && !visited[cur / 3]) {
			visited[cur / 3] = visited[cur] + 1;
			q.push((cur / 3));
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	bfs(n);

	cout << ret;

	return 0;
}
