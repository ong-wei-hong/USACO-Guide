#include <iostream>
using namespace std;

const int MxN=1e5;
int N, K, B, a[MxN+1];

int main(){
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	
	cin >> N >> K >> B;

	int b;
	for(int i=0; i<B; ++i){
		cin >> b;
		a[b] = 1;
	}
	for(int i=1; i<=N; ++i)
		a[i] += a[i-1];

	int minBroken = K;
	for(int i=K; i<=N; ++i)
		minBroken = min(minBroken, a[i] - a[i-K]);
	
	cout << minBroken;
}
