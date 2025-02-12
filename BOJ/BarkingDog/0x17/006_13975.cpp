#include<iostream>
#include<queue> //priority_queue
using namespace std;
typedef long long ll;

int t, n, temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;

		priority_queue<ll, vector<ll>, greater<ll>> pq;

		for (int i = 0; i < n; i++) {
			cin >> temp;
			pq.push(temp);
		}

		ll ret = 0;

		while (pq.size() > 1) {
			ll a = pq.top(); pq.pop();
			ll b = pq.top(); pq.pop();

			ret += a + b;
			pq.push(a + b);
		}

		cout << ret << '\n';
	}

	return 0;
}
