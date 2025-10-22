#include<iostream>
#include<queue>
#include<vector>
#include<algorithm> //reverse
using namespace std;

int n, k, visited[100001], pre[100001];
vector<int> ret;

void bfs(int n) {
    visited[n] = 1;

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == k) break;

        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (0 <= next && next <= 100000) {
                if (!visited[next]) {
                    visited[next] = visited[cur] + 1;
                    q.push(next);

                    pre[next] = cur;
                }
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    bfs(n);

    int cur = k;

    while (true) {
        if (cur == n) {
            ret.push_back(cur);
            break;
        }

        ret.push_back(cur); //현재 노드의 값 추가
        cur = pre[cur]; //이전 노드로 이동
    }

    reverse(ret.begin(), ret.end()); //역순으로 정렬

    cout << visited[k] - 1 << '\n'; //방문 횟수 출력

    for (int i : ret) cout << i << ' '; //경로 출력

    return 0;
}
