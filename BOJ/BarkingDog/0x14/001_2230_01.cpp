#include<iostream>
#include<algorithm> //sort
#include<climits> //INT_MAX
using namespace std;

int n, m, a[100001];
int ret = INT_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int ed = 0;

	//길이 또는 값의 차이 등을 살펴볼 때 사용되는 투 포인터 반복문 형식
	for (int st = 0; st < n; st++) { //같은 수를 고를 수도 있다
		while (ed < n && a[ed] - a[st] < m) {
			ed++;
		}

		if (ed == n) break;

		ret = min(ret, a[ed] - a[st]);
	}

	cout << ret; //항상 차이가 M 이상인 두 수를 고를 수 있다. (답이 나오지 않는 경우는 없음)

	return 0;
}
