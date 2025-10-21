#include<iostream>
#include<queue> //priority_queue
using namespace std;
typedef long long ll;

int t, k, temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> k;

		priority_queue<ll, vector<ll>, greater<ll>> pq; //pq greater = 최소 힙

		for (int i = 0; i < k; i++) {
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
