#include<iostream>
#include<queue> //priority_queue
using namespace std;

class cmp {
	public:
		bool operator()(int a, int b) {
			if (abs(a) != abs(b)) {
				return abs(a) > abs(b); //절댓값이 가장 작은 값을 pq.top()으로 = 최소 힙 = greater(우선순위 큐는 반대)
			}
			else {
				return a > b; //가장 작은 값을 pq.top()으로 = 최소 힙 = greater(우선순위 큐는 반대)
			}
		}
};

int n, temp;
priority_queue<int, vector<int>, cmp> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
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
