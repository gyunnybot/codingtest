#include<iostream>
#include<queue> //priority_queue
using namespace std;

class cmp { //암기
public:
	bool operator()(int a, int b) {
		if (abs(a) != abs(b)) {
			return abs(a) > abs(b);
		}
		else {
			return a > 0 && b < 0;
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
