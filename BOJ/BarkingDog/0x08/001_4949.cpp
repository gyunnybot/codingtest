#include<iostream>
#include<stack>
#include<string> //getline
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (getline(cin, s)) { //공백을 포함한 입력 받기
		if (s == ".") break;

		stack<char> stk;

		for (char a : s) {
			if (a == '(' || a == ')' || a == '[' || a == ']') {
				if (stk.empty()) { //비어있다면 무조건 push
					stk.push(a);
				}
				else {
					if (stk.top() == '(' && a == ')') { //괄호가 사라지는 경우 1
						stk.pop();
					}
					else if (stk.top() == '[' && a == ']') { //괄호가 사라지는 경우 2
						stk.pop();
					}
					else {
						stk.push(a);
					}
				}
			}
			
			if (a == '.') {
				stk.push(a);
			}
		}

		if (stk.size() == 1 && stk.top() == '.') {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}

	return 0;
}
