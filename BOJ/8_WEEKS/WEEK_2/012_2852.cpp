#include<iostream>
#include<string> //to_string
using namespace std;

int n, team, asum, bsum, team_a, team_b;
string t, pre;

string print(int sum) {
	string d = "00" + to_string(sum / 60);
	string e = "00" + to_string(sum % 60);

	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

int str_to_int(string t) {
	return atoi(t.substr(0, 2).c_str()) * 60 + atoi(t.substr(3, 2).c_str());
}

void cal_time(int& sum, string t, string pre) {
	sum += str_to_int(t) - str_to_int(pre);

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> team >> t;

		if (team_a > team_b) {
			cal_time(asum, t, pre);
		}
		else if (team_a < team_b) {
			cal_time(bsum, t, pre);
		}

		team == 1 ? team_a++ : team_b++;
		pre = t;
	}

	//경기 종료 후 시간 계산
	if (team_a > team_b) {
		cal_time(asum, "48:00", pre);
	}
	else if (team_a < team_b) {
		cal_time(bsum, "48:00", pre);
	}

	cout << print(asum) << '\n' << print(bsum);

	return 0;
}
