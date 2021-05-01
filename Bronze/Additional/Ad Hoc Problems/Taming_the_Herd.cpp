#include <iostream>
using namespace std;

int N, a[100];

int main(){
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	cin>>N;
	for(int i=0; i<N; ++i)
		cin>>a[i];
	if(a[0]>0){ //no consistent with first day outbreak
		cout<<-1;
		return 0;
	}
	a[0]=0; //we know there's an outbreak on first day
	/* t tracks the lowest 'real' value of a[i]
	 * min is the min number of breakouts
	 * add is the additional number of breakouts possible*/
	int t=-1, min=0, add=0;
	for(int i=N-1; i>=0; --i){
		if(t!=-1 && a[i]!=-1 && a[i]!=t){ //if a[i] is inconsistent with t (exception when a[i] or t =-1)
			cout<<-1;
			return 0;
		}
		if(t==-1) //t takes a[i] value
			t=a[i];
		if(a[i]==-1)
			a[i]=t;
		if(a[i]==0)
			++min;
		if(a[i]==-1)
			++add;
		if(t>-1) //--t as the iteration is backwards
			--t;
	}
	cout<<min<<" "<<min+add;
}
