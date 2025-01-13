#include<iostream>
#include<algorithm> //sort
#include<set> //multiset
using namespace std;
typedef long long ll;

int n, k, c, m, v;
pair<int, int> jewel_info[300001];
multiset<int> bag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> jewel_info[i].second >> jewel_info[i].first; //무게, 가치
	}

	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.insert(c);
	}

	sort(jewel_info, jewel_info + n); //가치를 기준으로 정렬

	ll ret = 0;

	for (int i = n - 1; i >= 0; i--) {
		m = jewel_info[i].second, v = jewel_info[i].first;

		multiset<int>::iterator it = bag.lower_bound(m);

		if (it == bag.end()) continue;

		ret += v;
		bag.erase(it);
	}

	cout << ret;

	return 0;
}