#include<iostream>
#include<queue> //priority_queue
using namespace std;

int k, temp;
priority_queue<int, vector<int>, greater<int>> pq; //루트 노드를 시작점으로. 오름차순 = 최소 힙

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;

    for (int i = 0; i < k * k; i++) {
        cin >> temp;
        pq.push(temp);

        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    cout << pq.top();

    return 0;
}
