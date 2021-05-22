#include <iostream>
using namespace std;

#define ll long long

const int MxN = 2e5;
int n, sum, m[MxN];
ll ans;

int main(){
	cin >> n;

	int a;
	m[0] = 1;
	for(int i=0; i<n; ++i){
		cin >> a;
		sum = (sum + a % n + n) % n; // +n to account for -ve a
		ans += m[sum]; //if the sum of the first j elements mod n = sum mod n, the last i - j elements is divisible by n
		++m[sum];
	}
	cout << ans << "\n";
}
