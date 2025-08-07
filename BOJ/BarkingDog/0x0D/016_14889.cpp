#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, a[21][21];
int ret = INT_MAX;
vector<bool> visited(21, false);
vector<int> v;

int soccer(vector<int>& start, vector<int>& link) {
    pair<int, int> ret = { 0,0 }; //곧바로 += 연산을 해야하므로 0으로 초기화

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (i == j) continue;

            ret.first += a[start[i]][start[j]];
            ret.second += a[link[i]][link[j]];
        }
    }

    return abs(ret.first - ret.second);
}

void combi(int start, vector<int>& v, vector<bool>& visited) {
    if (v.size() == n / 2) {
        vector<int> start, link;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                start.push_back(i);
            }
            else {
                link.push_back(i);
            }
        }

        ret = min(ret, soccer(start, link));

        return;
    }

    for (int i = start + 1; i < n; i++) {
        visited[i] = 1;
        v.push_back(i);

        combi(i, v, visited);

        visited[i] = 0;
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    combi(-1, v, visited); //팀 나누기

    cout << ret;

    return 0;
}
