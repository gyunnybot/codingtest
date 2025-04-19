#include<iostream>
#include<algorithm> //sort
#include<set> //multiset
using namespace std;
typedef long long ll;

int n, k, c, m, v;
pair<int, int> jewel_info[300001];
multiset<int> bag;
ll ret;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> jewel_info[i].first >> jewel_info[i].second; //무게, 가격
	}

	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.insert(c); //multiset : 오름차순으로 자동 정렬
	}

	sort(jewel_info, jewel_info + n, cmp); //가격을 기준으로 오름차순 정렬

	for (int i = n - 1; i >= 0; i--) { //가격이 높은 보석을 우선적으로 챙긴다
		m = jewel_info[i].first, v = jewel_info[i].second;

		multiset<int>::iterator it = bag.lower_bound(m); //multiset::lower_bound
		//multiset<int>::iterator it = lower_bound(bag.begin(), bag.end(), m); //트리 기반 컨테이너에서 std::lower_bound = O(N)

		if (it == bag.end()) continue; //여유가 되지 않는다면 다음 보석으로 진행

		ret += v;
		bag.erase(it);
	}

	cout << ret;

	return 0;
}
