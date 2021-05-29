#include <iostream>
using namespace std;

#define ll long long

string s;
int count[2019];

int main(){
	cin >> s;
	int num=0, n=s.size(), pow=1;

	count[0] = 1;
	for(int i=n-1; i>=0; --i) {
		num = (num + pow * (s[i] - '0')) % 2019;

		++count[num];
		pow = pow * 10 % 2019; //prevent num from becoming too large
	}
	ll ans = 0;
	for(int i=0; i<2019; ++i) {
		ans += (long long)count[i] * (count[i] - 1) / 2;
	}

	cout << ans << "\n";
}
