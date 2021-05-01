#include <iostream>
using namespace std;

#define ll long long

const int mxN=1e3;
int N, grid[mxN][mxN];

int main(){
	cin>>N;
	for(int y=0; y<N; ++y)
		for(int x=0; x<N; ++x)
			cin>>grid[y][x];

	//calculate the score prioritising alterations in x axis first
	ll xAns=0;
	for(int y=0; y<N; ++y){
		ll sums[2]={0, 0};
		for(int x=0; x<N; ++x)
			sums[x%2]+=grid[y][x];
		xAns+=max(sums[0], sums[1]);
	}
	

	//calculate the score prioristing alterations in y axis
	ll yAns=0;
	for(int x=0; x<N; ++x){
		ll sums[2]={0, 0};
		for(int y=0; y<N; ++y)
			sums[y%2]+=grid[y][x];
		yAns+=max(sums[0], sums[1]);
	}
	cout<<max(xAns, yAns);
}
