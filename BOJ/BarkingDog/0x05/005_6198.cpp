#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

int n, height; //n <= 80,000
stack<int> stk; //모든 빌딩은 일렬로 서 있고 오른쪽으로'만' 볼 수 있다? stack 활용!
ll ret; //ret <= n * (n + 1) / 2 -> 64억? long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> height;

		while (!stk.empty() && stk.top() <= height) {
			stk.pop(); //본인을 내려다볼 수 없는 빌딩 pop
		}
		
		ret += stk.size(); //본인을 내려다볼 수 있는 빌딩의 수(skt.size())를 ret에 추가
		stk.push(height);
	}

	cout << ret; //전체로 보면, 본인을 내려다볼 수 있는 빌딩 수의 총합은 본인이 내려다볼 수 있는 빌딩 수의 총합이 된다
	
	return 0;
}
