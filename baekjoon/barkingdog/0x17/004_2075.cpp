#include<iostream>
#include<queue> //priority_queue
using namespace std;

int n, temp;
priority_queue<int, vector<int>, greater<int>> pq; //pq greater = 최소 힙

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n * n; i++) {
        cin >> temp;
        pq.push(temp);

        if (pq.size() > n) {
            pq.pop();
        }
    }
    
    cout << pq.top();

    return 0;
}
