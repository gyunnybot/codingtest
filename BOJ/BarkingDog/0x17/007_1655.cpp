#include<iostream>
#include<queue> //priority_queue
using namespace std;

int n, temp;
priority_queue<int, vector<int>, less<>> max_pq; //루트 노드를 시작점으로. 내림차순 = 최대 힙
priority_queue<int, vector<int>, greater<>> min_pq; //루트 노드를 시작점으로. 오름차순 = 최소 힙

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    while (n--) {
        cin >> temp;

        if (max_pq.size() == min_pq.size()) {
            max_pq.push(temp); //최대 힙
        }
        else {
            min_pq.push(temp); //최소 힙
        }

        if (!max_pq.empty() && !min_pq.empty() && max_pq.top() > min_pq.top()) {
            max_pq.push(min_pq.top());
            min_pq.push(max_pq.top());

            max_pq.pop();
            min_pq.pop();
        }
        
        cout << max_pq.top() << '\n';
    }

    return 0;
}
