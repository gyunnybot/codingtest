#include<iostream>
#include<climits> //INT_MAX
#include<vector>
using namespace std;

int n, m, a[11], temp, voted[11];
int ret = INT_MAX;
bool visited[11];
vector<int> adj[11];

pair<int, int> dfs(int here, int num) {
    visited[here] = true;

    pair<int, int> ret = { 1,a[here] }; //{선거구 idx가 num인 선거구의 개수, 해당 선거구에 속한 인구}

    for (int there : adj[here]) {
        if (visited[there]) continue;
        if (voted[there] != num) continue;

        pair<int, int> temp = dfs(there, num);

        ret.first += temp.first;
        ret.second += temp.second;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    //선거구에 속한 인구수
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> m;

        //연결 관계
        for (int j = 0; j < m; j++) {
            cin >> temp;

            adj[temp].push_back(i);
            adj[i].push_back(temp);
        }
    }

    for (int i = 1; i < (1 << n) - 1; i++) { //특정 선거구 독점(all or nothing)을 제외한 모든 경우의 수 조사
        fill(voted, voted + 11, 0); //선거구 결과 저장
        fill(visited, visited + 11, 0); //방문처리

        int vote_idx1 = 0;
        int vote_idx2 = 0;

        //선거구 나누기
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { //특정 경우의 수가 j + 1 번째 선거구를 포함한다면
                vote_idx1 = j + 1;
                voted[vote_idx1] = 1; //포함된 선거구는 1로 선거구 결과 저장
            }
            else {
                vote_idx2 = j + 1; //포함되지 않은 선거구는 0으로 저장
            }
        }

        //connected component를 기반으로 dfs
        pair<int, int> idx1_area = dfs(vote_idx1, 1);
        pair<int, int> idx2_area = dfs(vote_idx2, 0);

        if (idx1_area.first + idx2_area.first == n) { //정확히 둘로 나뉘었다면
            ret = min(ret, abs(idx1_area.second - idx2_area.second)); //인구수 차이의 최소 구하기
        }
    }

    cout << (ret == INT_MAX ? -1 : ret);
    
    return 0;
}
