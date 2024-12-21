#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

string s;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	while (s.size()) {
		v.push_back(s);
		s.erase(0, 1);
	}

	sort(v.begin(), v.end());

	for (string s : v) {
		cout << s << '\n';
	}

	return 0;
}
