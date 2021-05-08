#include <iostream>
#include <algorithm>
using namespace std;

/*to find min num swaps,
 * min swaps = num of elements in wrong position - 1
 * since moving an element in correct pos would require moving it back to the original position
 * thus increasing num swaps*/

const int MxN=100;
int N, cows[MxN], sorted[MxN];

int main(){
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);

	cin>>N;
	for(int i=0; i<N; ++i){
		cin>>cows[i];
		sorted[i]=cows[i];
	}
	sort(sorted, sorted+N);

	int ans=-1;
	for(int i=0; i<N; ++i)
		ans+=(sorted[i]!=cows[i]);

	cout<<max(0, ans);
}
