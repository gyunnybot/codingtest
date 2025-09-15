#include<iostream>
#include<queue>
using namespace std;

int n, m, dist[2000001], x, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    int bit = 2;
    
    while (bit <= n) {
        bit <<= 1;
    }

    for (int i = 0; i < bit; i++) {
        dist[i] = 0;
    }

    queue<int> q;

    cin >> m;

    while (m--) {
        cin >> x;
        
        dist[x] = 1;
        q.push(x);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int b = 1; b < bit; b <<= 1) {
            int next = cur ^ b;

            if (dist[next]) continue; //안전도는 안전거리의 최솟값

            dist[next] = dist[cur] + 1; //안전거리 구하기
            q.push(next);
        }
    }

    for (int i = 0; i <= n; i++) {
        if (dist[i] > ret) {
            ret = dist[i]; //안전도가 제일 높은 비밀번호의 안전도 구하기
        }
    }

    cout << ret - 1;

    return 0;
}

/**
 * a ^ b = c라면 a ^ c = b, b ^ c = a이 성립한다
 * 
 * XOR 연산에서 0은 상대 비트를 따라가고, 1은 비트를 반전시키므로 b = 1, 2, 4, 8... 탐색 방식은 자연스럽다
 * 
 * 예를 들어, 초기 비밀번호가 3이고 b = 1, 2, 4, 8이라면 XOR 연산 값은 2, 1, 7, 11이 반환되는데,
 * 1번 명제에 따르면 3 ^ (2, 1, 7, 11) = (1, 2, 4, 8)이므로 3과 안전거리가 1인 수의 집합은 2, 1, 7, 11임을 알 수 있다
 * 
 * 2, 1, 7, 11을 또 다시 b = 1, 2, 4, 8로 XOR 연산을 진행하면 초기 비밀번호 3과 안전거리가 2인 집합을 찾을 수 있게 된다
 * */