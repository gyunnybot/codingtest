#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int bfs(vector<vector<int>>& maps) {
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    visited[0][0] = 1;

    queue<pair<int, int>> q;
    q.push({ 0,0 });

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (maps[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = visited[cur.first][cur.second] + 1;
                q.push({ ny,nx });
            }
        }
    }

    if (!visited[n - 1][m - 1]) {
        return -1;
    }
    else {
        return visited[n - 1][m - 1];
    }
}

int solution(vector<vector<int>> maps) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int answer = bfs(maps);

    return answer;
}
