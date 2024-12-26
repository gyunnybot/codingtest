#include<iostream>
#include<algorithm> //sort
#include<queue> //priority_queue
using namespace std;

int n, st, ed;
vector<pair<int, int>> debate;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> st >> ed;
		debate.push_back({ st,ed });
	}

	sort(debate.begin(), debate.end());

	for (int i = 0; i < debate.size(); i++) {
		pq.push(debate[i].second); //끝나는 시각을 오름차순으로 저장

		//현재 회의의 시작시간이 진행중인 회의 이후에 끝난다면 강의실 추가 없이 사용
		if (pq.top() <= debate[i].first) {
			pq.pop();
		}
	}

	//pq의 size = 반드시 생성해야 하는 강의실의 수
	cout << pq.size();

	return 0;
}
