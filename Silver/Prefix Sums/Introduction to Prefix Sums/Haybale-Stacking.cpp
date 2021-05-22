#include <iostream>
#include <algorithm>
using namespace std;

const int MxN=1e6;
int haybales[MxN], N, K;

int main(){
	cin >> N >> K;
	
	int A, B;
	for(int i=0; i<K; ++i){
		cin >> A >> B;
		++haybales[A-1];
		--haybales[B];
	}

	for(int i=1; i<N; ++i)
		haybales[i] += haybales[i-1];

	sort(haybales, haybales + N);

	cout<<haybales[N/2];
}
