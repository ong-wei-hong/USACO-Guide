#include <iostream>
using namespace std;

const int MxN=1e5;
int N, g[MxN+1][3];

int main(){
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	cin >> N;

	char c;
	for(int i=1; i<=N; ++i){
		g[i][0] = g[i-1][0];
		g[i][1] = g[i-1][1];
		g[i][2] = g[i-1][2];

		cin >> c;
		if(c == 'H') ++g[i][0];
		if(c == 'P') ++g[i][1];
		if(c == 'S') ++g[i][2];
	}

	int ans = 0;
	for(int i=1; i<=N; ++i){
		auto sol = [&] (int a, int b){
			ans = max(ans, g[i][a] + g[N][b] - g[i][b]); //points gained from choosing a from 0 to i and b from i + 1 to N
		};
		sol(0, 1);
		sol(0, 2);
		sol(1, 0);
		sol(1, 2);
		sol(2, 0);
		sol(2, 1);
	}
	cout << ans << "\n";
}
