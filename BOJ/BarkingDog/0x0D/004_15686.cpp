#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, m, a[51][51];
int ret = INT_MAX; //도시의 치킨 거리의 최솟값 계산
vector<pair<int, int>> home, chicken; //집 목록, 치킨집 목록
vector<int> v; //combi 함수에 따라 선택(방문)된 치킨집을 저장하는 벡터 v
vector<bool> visited(2501, false);

int cal_city_dist(vector<pair<int, int>>& house, vector<int>& v) {
	int city_dist = 0;

	for (pair<int, int> home : house) {
		int individual_dist = INT_MAX; //각각의 집에서 가까운 치킨집과의 거리 계산

		for (int selected_number : v) {
			int abs_y = abs(home.first - chicken[selected_number].first);
			int abs_x = abs(home.second - chicken[selected_number].second);

			individual_dist = min(individual_dist, abs_y + abs_x);
		}

		city_dist += individual_dist; //치킨 거리를 합산해 도시의 치킨 거리 완성하기
	}

	return city_dist;
}

void combi(int start, vector<int>& v, vector<bool>& visited) {
	if (v.size() == m) { //m개를 방문한다면
		ret = min(ret, cal_city_dist(home, v));
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
				home.push_back({ i,j });
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
