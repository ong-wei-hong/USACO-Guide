#include <iostream>
using namespace std;

const int MxN = 2e5;
int n, q, x[MxN+1];

//treat this like a typical prefix sum problem
int main(){
	cin >> n >> q;
	
	for(int i=1; i<=n; ++i){
	cin >> x[i];
	x[i] ^= x[i-1];
	}
	
	int a, b;
	for(int i=0; i<q; ++i){
	cin >> a >> b;
	cout << (x[a-1] ^ x[b]) << "\n";
	}
}
