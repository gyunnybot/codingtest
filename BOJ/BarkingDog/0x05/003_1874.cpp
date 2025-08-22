#include<iostream>
#include<stack>
using namespace std;

int n, val;
int cnt = 1;
bool flag;
string ret;
stack<int> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> val;

		while (cnt <= val) {
			ret += "+\n";
			stk.push(cnt);
			cnt++;
		}

		if (stk.top() != val) {
			flag = true; //도중에 수열이 성립하지 않아도 일단 입력받는다
		}
		else {
			ret += "-\n";
			stk.pop();
		}
	}

	if (flag) { //수열이 성립하지 않는 경우(순차적으로 쌓이지 않았을 경우)
		cout << "NO";
	}
	else {
		cout << ret;
	}

	return 0;
}
