#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MxN=100;
int N;
bool visited[MxN+1];
vector<int> from[MxN+1];

void dfs(int i){
	visited[i] = 1;
	for(int j: from[i])
		if(!visited[j])
			dfs(j);
}

bool allVisited(int i){
	dfs(i);
	for(int i=1; i<=N; ++i)
		if(!visited[i])
			return 0;
	return 1;
}

int main(){
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);

	cin>>N;

	int a, b;
	for(int i=0; i<N-1; ++i){
		cin>>a>>b;
		from[b].push_back(a);
	}

	for(int i=1; i<=N; ++i){
		memset(visited, 0, N+1);
		if(allVisited(i)){
			cout<<i;
			return 0;
		}	
	}
	cout<<-1;
}
