#include<iostream>
#include<vector>
#include<string> //to_string
using namespace std;

struct info {
	string num;
	int s, b;
};
vector<info> v;

int n, s, b, ret;
string number;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number >> s >> b;
		v.push_back({ number,s,b });
	}

	for (int temp = 111; temp <= 999; temp++) {
		string temp_num = to_string(temp);

		if (temp_num[0] == '0' || temp_num[1] == '0' || temp_num[2] == '0') continue;
		if (temp_num[0] == temp_num[1] || temp_num[1] == temp_num[2] || temp_num[2] == temp_num[0]) continue;

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			int strike = 0;
			int ball = 0;

			if (temp_num[0] == v[i].num[0]) strike++;
			if (temp_num[1] == v[i].num[1]) strike++;
			if (temp_num[2] == v[i].num[2]) strike++;

			if (temp_num[0] == v[i].num[1] || temp_num[0] == v[i].num[2]) ball++;
			if (temp_num[1] == v[i].num[0] || temp_num[1] == v[i].num[2]) ball++;
			if (temp_num[2] == v[i].num[0] || temp_num[2] == v[i].num[1]) ball++;

			if (v[i].s == strike && v[i].b == ball) cnt++;
		}

		if (cnt == n) ret++;
	}

	cout << ret;

	return 0;
}
