#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;
typedef long long ll;

int n, m, t;
vector<int> minu, plu;
ll ret;

void oper(vector<int>& v) {
    while (1 < v.size()) { //원소 2개 이상
        ret += (*(v.end() - 1)) * (*(v.end() - 2)); //벡터 내 절대값이 가장 큰 두 원소끼리의 곱
        v.pop_back();
        v.pop_back();
    }

    if (!v.empty()) { //하나 남은 원소는 괄호로 묶을 수 없으므로 덧셈
        ret += v[0];
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;

        if (t == 1) { //1은 곱셈 연산보다 순수 덧셈이 더 큰 최대 합을 만든다
            ret++;
        }
        else if (0 < t) {
            plu.push_back(t);
        }
        else {
            minu.push_back(t);
        }
    }

    sort(plu.begin(), plu.end()); //1, 2, 3...
    sort(minu.begin(), minu.end(), greater<>()); //-1, -2, -3...

    oper(plu);
    oper(minu);

    cout << ret;

    return 0;
}
