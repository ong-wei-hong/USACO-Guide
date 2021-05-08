#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MxN=100;
int N, M, grass[MxN+1];

int main(){
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

	cin>>N>>M;
	
	vector<int> pairs[N+1];

	int a, b;
	for(int i=0; i<M; ++i){
		cin>>a>>b;
		pairs[max(a, b)].push_back(min(a, b));
	}
	for(int i=1; i<=N; ++i){
		if(!pairs[i].size()) //if has no previous pastures
			grass[i] = 1;
		else{
			bool avail[5] = {1, 1, 1, 1, 1};
			for(int &j: pairs[i])
				avail[grass[j]]=0;
			for(int j=1; j<=4; ++j)
				if(avail[j]){
					grass[i] = j;
					break;
				}
		}
		cout<<grass[i];
	}
}