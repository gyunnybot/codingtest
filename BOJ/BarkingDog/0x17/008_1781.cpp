#include<iostream>
#include<vector>
#include<algorithm> //sort
#include<queue> //priority_queue
using namespace std;

int n, deadline, cup_noodle, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> deadline >> cup_noodle;
		v.push_back({ deadline,cup_noodle });
	}

	sort(v.begin(), v.end()); //데드라인 기준 오름차순 정렬

	for (int i = 0; i < n; i++) {
		pq.push(v[i].second); //컵라면 갯수를 최소 힙에 push

		if (pq.size() > v[i].first) { //데드라인에 맞게 pq.size() 조절
			pq.pop();
		}
	}

	while (!pq.empty()) {
		ret += pq.top();
		pq.pop();
	}

	cout << ret;

	return 0;
}
