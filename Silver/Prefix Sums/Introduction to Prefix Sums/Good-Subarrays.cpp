#include <iostream>
#include <map>
using namespace std;

/* let Pi be the prefix sum of the first i elements
 * [i, j] is good if Pj - Pi = j - i (sum of elements from i to j = length of i to j)
 * thus Pj - j = Pi - i, so we store the values and frequency of Pi - i
 * ans is the sum of all Pi - i with the same value */

#define ll long long
#define pi pair<int, ll>

const int MxN=1e5;
int t, n, a[MxN+1];

int main(){
	cin >> t;
	for(int i=0; i<t; ++i) {
		cin >> n;
		char c;
		for(int i=1; i<=n; ++i) {
			cin >> c;
			a[i] = c - '0';
		}
		for(int i=1; i<=n; ++i) {
			a[i] += a[i-1];
		}
		map<int, ll> length;
		for(int i=0; i<=n; ++i)
			++length[a[i] - i];
		ll ans = 0;
		for(pi p: length){
			ll s = p.second;
			ans += s * (s - 1) / 2;
		}
		cout << ans <<"\n";
	}
}
