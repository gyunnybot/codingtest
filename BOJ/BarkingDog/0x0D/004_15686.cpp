#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, m, a[51][51];
int ret = INT_MAX;
vector<pair<int, int>> house, chicken; //집 위치, 치킨집 위치 저장
vector<int> chicken_list; //선택된 치킨집의 인덱스 저장
vector<bool> visited(14, false);

int cal_city_dist(vector<pair<int, int>>& house, vector<int>& chicken_list) {
	int city_dist = 0;

	for (pair<int, int> h : house) {
		int dist = INT_MAX;

		for (int i : chicken_list) {
			int abs_y = abs(h.first - chicken[i].first);
			int abs_x = abs(h.second - chicken[i].second);

			dist = min(dist, abs_y + abs_x);
		}

		city_dist += dist;
	}

	return city_dist;
}

void combi(int start, vector<int>& chicken_list, vector<bool>& visited) {
	if (chicken_list.size() == m) {
		ret = min(ret, cal_city_dist(house, chicken_list));
	}

	for (int i = start + 1; i < chicken.size(); i++) {
		if (visited[i]) continue;

		chicken_list.push_back(i);
		visited[i] = true;

		combi(i, chicken_list, visited);

		chicken_list.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (a[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	combi(-1, chicken_list, visited);

	cout << ret;

	return 0;
}
