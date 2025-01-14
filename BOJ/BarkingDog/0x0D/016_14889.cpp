#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, board[21][21];
int ret = INT_MAX;
bool visited[21];
vector<int> v;

int cal(vector<int>& start, vector<int>& link) {
    pair<int, int> ret = { 0,0 };

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (i == j) continue;

            //start가 가진 i번째 원소값과 link가 가진 i번째 원소값은 서로 다르다
            ret.first += board[start[i]][start[j]];
            ret.second += board[link[i]][link[j]];
        }
    }

    return abs(ret.first - ret.second);
}

void combi(int start, vector<int>& v) {
    if (v.size() == n / 2) { //인원이 반으로 나뉘었을 때 능력치 계산하기
        vector<int> start, link;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                start.push_back(i);
            }
            else {
                link.push_back(i);
            }
        }

        ret = min(ret, cal(start, link));

        return;
    }

    for (int i = start + 1; i < n; i++) {
        visited[i] = 1;
        v.push_back(i);

        combi(i, v);

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
            cin >> board[i][j];
        }
    }

    combi(-1, v); //팀 나누기

    cout << ret;

    return 0;
}
