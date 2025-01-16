#include<iostream>
#include<stack>
using namespace std;

int n, temp;
int cnt = 1;
bool flag;
string ret;
stack<int> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> temp;

		while (cnt <= temp) {
			ret += "+\n";
			stk.push(cnt);
			cnt++;
		}

		if (stk.top() != temp) {
			flag = true; //도중에 수열이 성립하지 않아도 일단 입력받는다
		}
		else {
			ret += "-\n";
			stk.pop();
		}
	}

	if (flag) {
		cout << "NO";
	}
	else {
		cout << ret;
	}

	return 0;
}
