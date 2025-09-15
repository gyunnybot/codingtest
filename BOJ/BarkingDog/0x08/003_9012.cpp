#include<iostream>
#include<stack>
using namespace std;

int n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s;

		stack<char> stk;

		for (char a : s) {
			if (stk.empty()) {
				stk.push(a); //비어있다면 무조건 push
			}
			else {
				if (stk.top() == '(' && a == ')') { //괄호가 사라지는 경우
					stk.pop();
				}
				else {
					stk.push(a);
				}
			}
		}

		if (!stk.empty()) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}

	return 0;
}
