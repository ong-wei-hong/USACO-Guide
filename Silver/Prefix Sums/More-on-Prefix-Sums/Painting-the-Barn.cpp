#include <iostream>
using namespace std;

const int X=1e3;
int n, k, paint[X+1][X+1];

int main() {
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	int x1, y1, x2, y2;
	for(int i=0; i<n; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		++paint[x1][y1];
		--paint[x2][y1];
		--paint[x1][y2];
		++paint[x2][y2];
	}

	int ans = 0;
	for(int i=0; i<=X; ++i) {
		for(int j=0; j<=X; ++j) {
			if(i) paint[i][j] += paint[i-1][j];
			if(j) paint[i][j] += paint [i][j-1];
			if(i && j) paint[i][j] -= paint[i-1][j-1];
			ans += (paint[i][j] == k);
		}
	}	
	cout << ans << "\n";
}
