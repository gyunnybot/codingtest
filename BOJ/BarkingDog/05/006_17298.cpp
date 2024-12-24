#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int n, temp, arr[1000001];
stack<int> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	vector<int> ret(n, -1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		while (!stk.empty() && arr[stk.top()] < arr[i]) {
			ret[stk.top()] = arr[i];
			stk.pop();
		}

		stk.push(i); //idx push
	}

	for (int i = 0; i < n; i++) {
		cout << ret[i] << ' ';
	}

	return 0;
}
