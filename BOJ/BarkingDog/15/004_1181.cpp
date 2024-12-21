#include<iostream>
#include<algorithm> //sort, unique
#include<vector>
using namespace std;

vector<string> v;
string s;
int n;

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else {
		return a.size() < b.size();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);

	v.erase(unique(v.begin(), v.end()), v.end());

	for (string s : v) {
		cout << s << '\n';
	}

	return 0;
}
