#include <iostream>
using namespace std;

#define ll long long

const int MAX=1e5;
int L, N, rF, rB, x[MAX], c[MAX];
bool stop[MAX];

int main(){
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	
	cin>>L>>N>>rF>>rB;

	for(int i=0; i<N; ++i)
		cin>>x[i]>>c[i];
	
	int max=0;
	for(int i=N-1; i>=0; --i) //if stop[i], stop here until farmer arrives
		if(c[i]>max){
			max=c[i];
			stop[i]=1;
		}
	int currX=0;
	ll f=0, b=0, ans=0;

	for(int i=0; i<N; ++i)
		if(stop[i]){
			f += (x[i] - currX) * (ll)rF;
			b += (x[i] - currX) * (ll)rB;
			ans += (f - b) * (ll)c[i];
			b=f;
			currX=x[i];
		}
	cout<<ans;
}
