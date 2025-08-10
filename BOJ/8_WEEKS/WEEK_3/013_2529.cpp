#include<iostream>
#include<vector>
#include<algorithm> //sort
#include<string> //to_string
using namespace std;

char oper[10];
bool visited[10];
int k;
vector<string> ret;

bool check(char pre, char now, char oper) {
    if (pre < now && oper == '<') return true;
    if (pre > now && oper == '>') return true;

    return false;
}

void recur(int idx, string num) {
    if (idx == k + 1) {
        ret.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++) { //부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수
        if (visited[i]) continue; //선택된 숫자는 모두 달라야 한다

        if (idx == 0 || check(num[idx - 1], i + '0', oper[idx - 1])) {
            visited[i] = true;

            recur(idx + 1, num + to_string(i));

            visited[i] = false;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> oper[i];
    }

    recur(0, "");

    sort(ret.begin(), ret.end());

    cout << ret[ret.size() - 1] << '\n' << ret[0];

    return 0;
}
