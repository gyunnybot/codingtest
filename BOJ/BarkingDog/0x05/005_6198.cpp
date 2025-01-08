#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

int n, height;
stack<int> stk; //모든 빌딩은 일렬로 서 있고 오른쪽으로'만' 볼 수 있다 = stack 활용
ll ret; //최대 64억

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	//monotone stack
	while (n--) {
		cin >> height;

		while (!stk.empty() && stk.top() <= height) {
			stk.pop();
		}
		
		ret += stk.size(); //본인이 내려다볼 수 있는 빌딩 수의 총합 = 본인을 내려다볼 수 있는 빌딩 수의 총합

		stk.push(height);
	}

	cout << ret;

	return 0;
}
