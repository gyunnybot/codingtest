#include<iostream>
#include<vector>
#include<string> //to_string
using namespace std;

struct info {
	string number;
	int strike, ball;
};
vector<info> v;

int n, s, b, ret;
string num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num >> s >> b;
		v.push_back({ num,s,b });
	}

	for (int temp = 111; temp <= 999; temp++) {
		string temp_num = to_string(temp);

		if (temp_num[0] == '0' || temp_num[1] == '0' || temp_num[2] == '0') continue;
		if (temp_num[0] == temp_num[1] || temp_num[1] == temp_num[2] || temp_num[2] == temp_num[0]) continue;

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			int strike = 0;
			int ball = 0;

			if (temp_num[0] == v[i].number[0]) strike++;
			if (temp_num[1] == v[i].number[1]) strike++;
			if (temp_num[2] == v[i].number[2]) strike++;

			if (temp_num[0] == v[i].number[1] || temp_num[0] == v[i].number[2]) ball++;
			if (temp_num[1] == v[i].number[0] || temp_num[1] == v[i].number[2]) ball++;
			if (temp_num[2] == v[i].number[0] || temp_num[2] == v[i].number[1]) ball++;

			if (v[i].strike == strike && v[i].ball == ball) cnt++;
		}

		if (cnt == n) ret++;
	}

	cout << ret;

	return 0;
}
