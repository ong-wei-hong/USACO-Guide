#include <iostream>
using namespace std;

const int N=200;
int n, m, swampNum[N+1][N+1];
bool sturdy[N][N];

int main() {
	freopen("fortmoo.in", "r", stdin);
	freopen("fortmoo.out", "w", stdout);

	cin >> n >> m;

	char c;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> c;
			sturdy[i][j] = (c == '.');
			swampNum[i][j+1] = swampNum[i][j] + (c == 'X');
		}
	}

	int ans = 0;
	for(int i=0; i<m; ++i) {
		for(int j=i+1; j<m; ++j) {
			int k=0;
			for(int l=0; l<n; ++l) {
				bool mValid = (swampNum[l][j+1] - swampNum[l][i]) == 0;
				if(k == l && !mValid) { // find the first valid m and set it as the left most row
					++k;
					continue;
				}
				if(!sturdy[l][i] || !sturdy[l][j]) { //if the column is invalid
					k = l + 1;
				} else if (mValid && k != l) {
					ans = max(ans, (j - i + 1) * (l - k + 1));
				}
			}
		}
	}

	cout << ans << "\n";
}
