#include <iostream>
using namespace std;

#define ll long long

const int N=2e5;
int t, n, q, a[N+1];
ll ipsEven[N+1], ipsOdd[N+1], psEven[N+1], psOdd[N+1]; 

void update(int i) {
	for(int j=i; j<=n; ++j) {
		if(j%2) { //odd element
			psOdd[j] = psOdd[j-1] + a[j];
			ipsOdd[j] = ipsOdd[j-1] + a[j] * j;
			psEven[j] = psEven[j-1];
			ipsEven[j] = ipsEven[j-1];
		} else {
			psEven[j] = psEven[j-1] + a[j];
			ipsEven[j] = ipsEven[j-1] + a[j] * j;
			psOdd[j] = psOdd[j-1];
			ipsOdd[j] = ipsOdd[j-1];
		}
	}
}

int main() {
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cin >> n >> q;	
		for(int j=1; j<=n; ++j)
			cin >> a[j];
		
		update(1);
		ll ans=0;
		char c;
		int left = n;
		bool needUpdate = true;
		for(int j=0; j<q; ++j){
			cin >> c;

			if(c == 'Q') {
				if(needUpdate) {
					update(left);
					needUpdate = false;
					left = n;
				}
				int l, r;
				cin >> l >> r;
				if(l%2){ //l is odd
					ans += ipsOdd[r] - ipsOdd[l-1];
					ans -= (psOdd[r] - psOdd[l-1]) * (l-1);
					ans -= ipsEven[r] - ipsEven[l-1];
					ans += (psEven[r] - psEven[l-1]) * (l-1);
				} else {
					ans += ipsEven[r] - ipsEven[l-1];
					ans -= (psEven[r] - psEven[l-1]) * (l-1);
					ans -= ipsOdd[r] - ipsOdd[l-1];
					ans += (psOdd[r] - psOdd[l-1]) * (l-1);
				}	
			} else {
				int x, v;
				cin >> x >> v;
				a[x] = v;
				needUpdate = true;
				left = min(x, left);
			}
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}
}
