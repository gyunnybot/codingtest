/*
삼성 2018 상반기 오후 2번 문제 - 병원 거리 최소화하기

사람 기준으로 병원을 돌려서 최소 거리 찾고 합산. 병원 기준이라면 병원이 한 개면 한 사람 거리만 측정되니까 오류

참조자 없어도 답은 나오지만 순열 특성 상 call by value로 하면 횟수*O(N)이 되므로 일반적인 경우 붙이는게 좋은 듯

시간복잡도 O(13C6 * N*M)
*/

#include <algorithm> // min
#include <climits> // INT_MAX
#include <iostream>
#include <vector>
using namespace std;

int n, m, a[51][51];
int ret = INT_MAX;
bool visited[14];
vector<pair<int, int>> person, hospital;
vector<int> selected_hospital_idx;

int calculate_all_hospital_dist(vector<pair<int, int>> &person, vector<int> &selected_hospital_idx) {
  int total_dist = 0;

  for (pair<int, int> p : person) {
    int min_dist = INT_MAX;

    for (int i : selected_hospital_idx) {
      min_dist = min(min_dist, abs(p.first - hospital[i].first) + abs(p.second - hospital[i].second));
    }

    total_dist += min_dist;
  }

  return total_dist;
}

void select_hospital_idx(int idx, vector<int> &selected_hospital_idx) {
  if (selected_hospital_idx.size() == m) {
    ret = min(ret, calculate_all_hospital_dist(person, selected_hospital_idx));
    return;
  }

  for (int i = idx + 1; i < hospital.size(); i++) {
    if (visited[i]) {
      continue;
    }

    selected_hospital_idx.push_back(i);
    visited[i] = true;

    select_hospital_idx(i, selected_hospital_idx);

    selected_hospital_idx.pop_back();
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
        person.push_back({i, j});
      } else if (a[i][j] == 2) {
        hospital.push_back({i, j});
      }
    }
  }

  select_hospital_idx(-1, selected_hospital_idx);

  cout << ret;

  return 0;
}
