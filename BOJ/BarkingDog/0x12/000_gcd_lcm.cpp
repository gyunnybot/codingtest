//최대공약수
int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	else {
		return gcd(b % a, a);
	}
}

//최소공배수
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

//연립합동방정식
int chk() { //ex) 30명 미만 중 6인 1조 시 3명이 남고, 5인 1조 시 2명이 남는 인원 수는?
	for (int i = 3; i < 30; i += 6) {
		if (i % 5 == 2) {
			return i;
		}
	}

	return -1;
}