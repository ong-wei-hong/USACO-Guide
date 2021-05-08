#include <iostream>
using namespace std;

/* if even=odd, ans is even+odd
 * if even>odd, since n(even) is still even, ans=2*odd+1
 * if odd>even, since odd+odd is even, we pair two odd cows until one of the above requirements is fulfilled*/

int odd, even, N;

int main(){
	cin>>N;
	for(int i=0; i<N; ++i){
		int n;
		cin>>n;
		if(n%2) ++odd;
		else ++even;
	}
	while(odd>even){
		odd-=2;
		++even;
	}
	if(even>odd+1) even=odd+1;
	cout<<even+odd;
}
