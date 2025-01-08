#include<iostream>
using namespace std;
typedef long long ll;

int n;
ll ret;

void recur(int st, int dest, int n) {
	int mid = 6 - st - dest;

	if (n == 1) { //원판이 한 개라면 목적지까지 direct로 옮길 수 있다
		cout << st << ' ' << dest << '\n';
		return;
	}

	recur(st, mid, n - 1); //시작 위치에 있는 1 ~ n-1번 원판을 mid로 옮긴다

	cout << st << ' ' << dest << '\n'; //시작 위치에 있는 n번 원판을 목적지로 옮긴다

	recur(mid, dest, n - 1); //mid에 있는 n-1개의 원판을 목적지로 옮긴다
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	
	ret = (1 << n) - 1; //귀납적으로 도출한 이동 횟수

	cout << ret << '\n';

	recur(1, 3, n); //첫 번째 장대에서 세 번째 장대로 원판 이동

	return 0;
}