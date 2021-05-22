#include <iostream>
#include <map>
using namespace std;

#define ll long long

int n, x;
ll sum, ans;
map<ll, int> m;

int main(){
	cin >> n >> x;

	int a;
	m[0] = 1;
	for(int i=0; i<n; ++i){
		cin >> a;
		sum += a;
		ans += m[sum - x]; //if the first j elements = sum - x, the most recent i - j elements = x
		++m[sum];
	}
	cout << ans << "\n";
}
