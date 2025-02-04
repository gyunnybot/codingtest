#include<iostream>
#include<vector>
#include<algorithm> //sort
#include<queue> //priority_queue
using namespace std;
typedef long long ll;

int n, k, m, v, c;
vector<pair<int, int>> jewel_info;
vector<int> bag;
ll ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		jewel_info.push_back({ m,v });
	}

	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.push_back(c);
	}

	sort(jewel_info.begin(), jewel_info.end());
	sort(bag.begin(), bag.end());

	priority_queue<int, vector<int>, less<int>> pq;

	int j = 0;

	for (int i = 0; i < k; i++) {
		while (j < n && jewel_info[j].first <= bag[i]) {
			pq.push(jewel_info[j].second);
			j++;
		}

		if (!pq.empty()) {
			ret += pq.top(); pq.pop();
		}
	}

	cout << ret;

	return 0;
}
