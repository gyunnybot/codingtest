#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int n, L, val;
deque<pair<int, int>> dq;
vector<int> ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> L;

    for (int i = 0; i < n; i++) {
        cin >> val;

        while (!dq.empty() && dq.back().second >= val) {
            dq.pop_back(); //구간 내에서 최소값을 찾을 때까지 pop_back
        }

        dq.push_back({ i,val }); //두 가지 정보가 필요한 유형

        while (dq.front().first <= i - L) {
            dq.pop_front(); //구간 이동 시 pop_front
        }

        ret.push_back(dq.front().second);
    }

    for (int i : ret) {
        cout << i << ' ';
    }

    return 0;
}
