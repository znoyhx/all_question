//
// Created by a on 24-12-5.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;

int main() {

while(true){
	string s;
	cin >> s;
	int n = s.size();
	int m;
	int posPoint, posSemi;
	for (int i = 0; i < n; i++) {
		if (s[i] == '.') {
			m = 1;
			break;
		} else if (s[i] == '/') {
			m = 2;
			break;
		} else if (s[i] == '%') {
			m = 3;
			break;
		}
		if (i == n - 1) {
			m = 0;
		}

	}
	//1是小数点，2是除号，3是百分号
	if (m == 1) {
		string s1 = s.substr(0, s.find('.'));
		//substr右边是开区间，放心用
		string s2 = s.substr(s.find('.') + 1);
		reverse(s1.begin(), s1.end());
		int a = 0;
		while (true) {
			if (s1[a] == '0') {
				s1.erase(a, 1);
			} else {
				break;
			}

		}
		reverse(s2.begin(), s2.end());
		if (s2.size() != 1) {
			int b = s2.size() - 1;
			while (true) {
				if (s2[b] == '0') {
					s2.erase(b, 1);
				} else {
					break;
				}

			}
		}

		s = s1 + '.' + s2;
		cout << s << endl;

	}
	if (m == 2) {
		string s1 = s.substr(0, s.find('/'));
		//substr右边是开区间，放心用
		string s2 = s.substr(s.find('/') + 1);
		reverse(s1.begin(), s1.end());
		int a = 0;
		while (true) {
			if (s1[a] == '0') {
				s1.erase(a, 1);
			} else {
				break;
			}

		}

		reverse(s2.begin(), s2.end());

		int b = 0;
		while (true) {
			if (s2[b] == '0') {
				s2.erase(b, 1);
			} else {
				break;
			}

		}
		s = s1 + '/' + s2;
		cout << s << endl;
	}
	if (m == 3) {

		reverse(s.begin(), s.end() - 1);
		int a = 0;
		while (true) {

			if (s[a] == '0') {
				s.erase(a, 1);
			} else {
				break;
			}

		}
		cout << s << endl;
	}
	if (m == 0) {
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
}

	return 0;
}
