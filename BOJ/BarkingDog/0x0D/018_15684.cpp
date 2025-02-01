#include<iostream>
#include<climits> //INT_MAX
using namespace std;

bool visited[31][11];
int n, m, h, j, a, b, result;
int ret = INT_MAX;

bool check() {
    for (int i = 1; i <= n; i++) {
        int start = i;

        for (int j = 1; j <= h; j++) {
            if (start < n && visited[j][start]) {
                start++;
            }
            else if (start - 1 >= 1 && visited[j][start - 1]) {
                start--;
            }
        }

        if (start != i) return false;
    }

    return true;
}

void dfs(int here, int cnt) {
    if (here > h || cnt > 3) {
        return;
    }

    if (check()) {
        ret = min(ret, cnt);
        return;
    }

    for (int i = here; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (visited[i][j] || (j + 1 < n && visited[i][j + 1]) ||
                (j - 1 >= 1 && visited[i][j - 1])) continue;

            visited[i][j] = 1;

            dfs(i, cnt + 1);

            visited[i][j] = 0;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        visited[a][b] = 1; //b번 세로선과 b + 1번 세로선을 a번째 가로선 위치에서 연결
    }

    dfs(1, 0); //첫 번째 가로선부터 시작

    result = (ret == INT_MAX ? -1 : ret);

    cout << result;

    return 0;
}
