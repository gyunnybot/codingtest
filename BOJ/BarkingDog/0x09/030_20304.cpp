#include<iostream>
#include<queue>
using namespace std;

int n, m, dist[2000001], x, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    int bit = 2;
    
    while (bit <= n) {
        bit <<= 1;
    }

    for (int i = 0; i < bit; i++) {
        dist[i] = 0;
    }

    queue<int> q;

    while (m--) {
        cin >> x;
        dist[x] = 1;
        q.push(x);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int b = 1; b < bit; (b <<= 1)) {
            int next = cur ^ b;

            if (dist[next]) continue;

            dist[next] = dist[cur] + 1; //안전거리의 최솟값인 안전도 구하기
            q.push(next);
        }
    }

    for (int i = 0; i <= n; i++) {
        if (dist[i] > ret) {
            ret = dist[i]; //안전도가 제일 높은 비밀번호의 안전도 도출하기
        }
    }

    cout << ret - 1;

    return 0;
}
