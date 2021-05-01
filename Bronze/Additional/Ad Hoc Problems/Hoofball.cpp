#include <iostream>
#include <algorithm>
using namespace std;

const int MxN=100;
int N, x[MxN], passed[MxN];

int target(int i){
	if(i==0) //1st cow
		return 1;
	if(i==N-1) //last cow
		return N-2;
	if(x[i]-x[i-1]>x[i+1]-x[i]) //left>right
		return i+1;
	else
		return i-1;
}

int main(){
	freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);

	cin>>N;
	for(int i=0; i<N; ++i)
		cin>>x[i];
	sort(x, x+N);

	for(int i=0; i<N; ++i)
		++passed[target(i)];

	int ans=0;
	for(int i=0; i<N; ++i){
		if(passed[i]==0)
			++ans;
		else if(passed[i]==1 && passed[target(i)]==1 && target(target(i))==i){ //duo
			++ans;
			passed[target(i)]=-1; //avoid double counting
		}
	}
	cout<<ans;
}


