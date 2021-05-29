#include <iostream>
using namespace std;

const int MxN=1e5;
int A[MxN], N, b1[MxN], b2[MxN];

/* let a = nx, b = mx
 * if a>b, a%b = (m - pn)x
 * repeat until m-pn == 0 ie b is denominator of a*/
int gcd(int a, int b) {
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main(){
	cin >> N;
	for(int i=0; i<N; ++i)
		cin >> A[i];

	b1[0] = A[0];
	b2[N-1] = A[N-1];

	for(int i=1; i<N; ++i){
		b1[i] = gcd(b1[i-1], A[i]);
		b2[N-1-i] = gcd(b2[N-i], A[N-i-1]);
	}
	int ans=max(b1[N-2], b2[1]);//exclude the last and first element
	for(int i=1; i<N-1; ++i)
		ans=max(ans, gcd(b1[i-1],b2[i+1]));
	cout << ans;
}
