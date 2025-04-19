#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

int n, a[1001];
bool flag;
vector<int> b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b.push_back(a[i] + a[j]); //두 수를 더한 값을 b에 저장
		}
	}

	sort(b.begin(), b.end()); //정렬
	b.erase(unique(b.begin(), b.end()), b.end()); //중복된 원소 제거

	for (int i = n - 1; i > 0; i--) { //k번째 수가 최대여야 하므로 역순 탐색
		for (int j = 0; j < i; j++) {
			if (binary_search(b.begin(), b.end(), a[i] - a[j])) {
				cout << a[i]; //a[i]는 k번째 수의 최댓값이 된다
				
				flag = true;
				break;
			}
		}

		if(flag) break;
	}

	return 0; //답이 항상 존재하는 경우만 입력으로 주어진다
}