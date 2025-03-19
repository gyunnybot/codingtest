#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll n;
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	ll x = n;

	for (ll i = 2; i * i <= n; i++) {
		while (x % i == 0) {
			v.push_back(i);
			x /= i;			
		}
	}

	if (x != 1) { //유일하게 n의 제곱근보다 큰 마지막인 소인수가 있다면
		v.push_back(x);
	}

	cout << v.size() << '\n';
	
	for (ll i : v) {
		cout << i << ' ';
	}

	return 0;
}
