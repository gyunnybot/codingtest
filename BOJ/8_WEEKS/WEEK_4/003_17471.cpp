#include<iostream>
#include<climits> //INT_MAX
#include<vector>
using namespace std;

int n, m, a[11], connected, voted[11];
int ret = INT_MAX;
bool visited[11];
vector<int> adj[11];

pair<int, int> dfs(int here, int idx) {
    visited[here] = true;

    pair<int, int> ret = { 1,a[here] }; //{선거구가 idx인 구역의 개수, 선거구에 속한 구역의 인구}

    for (int there : adj[here]) {
        if (visited[there]) continue;
        if (voted[there] != idx) continue;

        pair<int, int> temp = dfs(there, idx);

        ret.first += temp.first;
        ret.second += temp.second;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    //구역별 인구 수
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    //구역 간 연결 관계 저장
    for (int i = 1; i <= n; i++) {
        cin >> m;

        for (int j = 0; j < m; j++) {
            cin >> connected;

            //양방향 간선
            adj[connected].push_back(i);
            adj[i].push_back(connected);
        }
    }

    for (int i = 1; i < (1 << n) - 1; i++) { //특정 선거구 독점(all or nothing)을 제외한 모든 경우의 수 조사
        fill(voted, voted + 11, 0); //구역별 선거 결과
        fill(visited, visited + 11, 0); //방문처리

        int vote_idx1 = 0;
        int vote_idx0 = 0;

        //선거구 나누기
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { //특정 경우의 수 i가 j + 1 번째 구역을 포함한다면
                vote_idx1 = j + 1;
                voted[vote_idx1] = 1; //포함된 구역은 선거구 결과 1로 저장
            }
            else {
                vote_idx0 = j + 1; //포함되지 않은 구역은 선거구 결과 0으로 저장
            }
        }

        //connected component를 기반으로 dfs
        pair<int, int> idx1_area = dfs(vote_idx1, 1);
        pair<int, int> idx0_area = dfs(vote_idx0, 0);

        if (idx1_area.first + idx0_area.first == n) { //구역이 정확히 둘로 나뉘었다면
            ret = min(ret, abs(idx1_area.second - idx0_area.second)); //인구수 차이의 최소 구하기
        }
    }

    cout << (ret == INT_MAX ? -1 : ret);

    return 0;
}
