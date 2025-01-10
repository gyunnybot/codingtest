#include<iostream>
#include<algorithm> //stable_sort
#include<vector>
using namespace std;

int n, age;
string name;
vector<pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		v.push_back({ age,name });
	}

	stable_sort(v.begin(), v.end(), cmp); //입력 순서를 유지한다

	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}
