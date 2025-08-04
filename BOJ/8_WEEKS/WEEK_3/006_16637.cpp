#include<iostream>
#include<vector>
#include<climits> //INT_MIN
using namespace std;
typedef long long ll;

int n;
ll ret = INT_MIN; //정답은 2 ^ 31보다 작고, -(2 ^ 31)보다 크다
string s;
vector<int> num; //0보다 크거나 같고, 9보다 작거나 같은 정수
vector<char> oper;

ll cal(char c, int a, int b) {
    if (c == '+') return a + b;
    if (c == '*') return a * b;
    if (c == '-') return a - b;
}

//단, 괄호 안에는 연산자가 하나만 들어 있어야 한다. O(2 ^ N)
void recur(int idx, ll sum) {
    if (idx == oper.size()) {
        ret = max(ret, sum);
        return;
    }

    if (idx < oper.size()) {
        recur(idx + 1, cal(oper[idx], sum, num[idx + 1]));
    }

    if (idx + 1 < oper.size()) {
        ll temp = cal(oper[idx + 1], num[idx + 1], num[idx + 2]); //단, 괄호 안에는 연산자가 하나만 들어 있어야 한다
        recur(idx + 2, cal(oper[idx], sum, temp));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            num.push_back(s[i] - '0');
        }
        else {
            oper.push_back(s[i]);
        }
    }

    recur(0, num[0]); //연산자 우선순위는 모두 동일하기 때문에, 수식을 계산할 때는 왼쪽에서부터 순서대로 계산해야 한다

    cout << ret;

    return 0;
}
