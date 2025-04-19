#include<iostream>
#include<queue> //priority_queue
using namespace std;

int n, temp;
priority_queue<int, vector<int>, greater<int>> pq; //루트 노드를 시작점으로. 오름차순 = 최소 힙

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        if (temp == 0) {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            pq.push(temp);
        }
    }

    return 0;
}
