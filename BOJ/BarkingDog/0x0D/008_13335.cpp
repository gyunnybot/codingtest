#include<iostream>
#include<queue>
using namespace std;

int n, w, L, a[1001], ret;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> w >> L;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int weight = 0; //현재 다리가 버티는 하중

	for (int i = 0; i < n; i++) {
		while (true) {
			if (q.size() == w) {
				weight -= q.front();
				q.pop();
			}

			if (weight + a[i] <= L) {
				break;
			}
			else {
				q.push(0);
				ret++;
			}
		}

		weight += a[i];
		q.push(a[i]);		

		ret++;
	}

	cout << ret + w;

	return 0;
}
