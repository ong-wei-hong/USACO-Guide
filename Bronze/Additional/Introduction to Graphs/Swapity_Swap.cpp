#include <iostream>
using namespace std;

int N, K, A1, A2, B1, B2, cows[101];

int next(int i){
	if(A1<=i && A2>=i)
		i = A1 + A2 - i; //the higher initial is, the lower end is
	if(B1<=i && B2>=i)
		i = B1 + B2 - i;
	return i; 
}

int main(){
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);

	cin>>N>>K>>A1>>A2>>B1>>B2;

	for(int i=1; i<=N; ++i){
		int s=1, curr=next(i);
		while(curr != i){
			++s;
			curr=next(curr);
		}
		int k = K % s; //the number of swaps to get an equivalent result
		for(int j=0; j<k; ++j)
			curr=next(curr);
		cows[curr] = i;
	}
	for(int i=1; i<=N; ++i)
		cout<<cows[i]<<"\n";
}
