#include<iostream>
#include<queue> //priority_queue
using namespace std;

int k, temp;
priority_queue<int, vector<int>, less<int>> pq; //루트 노드를 시작점으로. 내림차순 = 최대 힙

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;

    for (int i = 0; i < k; i++) {
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
