#include<iostream>
#include<stack>
using namespace std;

stack<char> stk;
string str;
int ret;
int num = 1; //곱셈 계산을 위해 0이 아닌 1로 초기화

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;

	bool flag = false;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			num *= 2;
			stk.push(str[i]);
		}
		else if (str[i] == '[') {
			num *= 3;
			stk.push(str[i]);
		}
		else if (str[i] == ')') {
			if (stk.empty() || stk.top() != '(') {
				flag = true;
				break;
			}

			if (str[i - 1] == '(') {
				ret += num; //직전 문자와 쌍을 이룬다면 ret 갱신
			}

			stk.pop();
			num /= 2;
		}
		else if (str[i] == ']') {
			if (stk.empty() || stk.top() != '[') {
				flag = true;
				break;
			}

			if (str[i - 1] == '[') {
				ret += num; //직전 문자와 쌍을 이룬다면 ret 갱신
			}

			stk.pop();
			num /= 3;
		}
	}

	if (!stk.empty()) { //최종 점검
		flag = true;
	}

	if (flag) {
		cout << 0;
	}
	else {
		cout << ret;
	}

	return 0;
}
