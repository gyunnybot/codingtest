#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

int n, temp;
vector<int> v, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;

		v.push_back(temp);
		ret.push_back(temp);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++) {
		cout << lower_bound(v.begin(), v.end(), ret[i]) - v.begin() << ' ';
	}

	return 0;
}