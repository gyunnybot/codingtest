#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, m, a[51][51];
int ret = INT_MAX;
vector<pair<int, int>> house, chicken; //집 목록, 치킨집 목록
vector<int> v; //선택된 치킨집의 인덱스를 저장하는 벡터 v
vector<bool> visited(2501, false);

int cal_city_dist(vector<pair<int, int>>& house, vector<int>& v) {
	int city_dist = 0;

	for (pair<int, int> home : house) {
		int individual_dist = INT_MAX;

		for (int i : v) {
			int abs_y = abs(home.first - chicken[i].first);
			int abs_x = abs(home.second - chicken[i].second);

			individual_dist = min(individual_dist, abs_y + abs_x); //개인별로 치킨 거리 계산
		}

		city_dist += individual_dist; //치킨 거리를 합산해 도시의 치킨 거리 완성
	}

	return city_dist;
}

void combi(int start, vector<int>& v, vector<bool>& visited) {
	if (v.size() == m) { //m개를 방문한다면
		ret = min(ret, cal_city_dist(house, v));
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++) {
		if (visited[i]) continue;

		v.push_back(i);
		visited[i] = true;

		combi(i, v, visited);

		v.pop_back();
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

	combi(-1, v, visited);

	cout << ret;

	return 0;
}
