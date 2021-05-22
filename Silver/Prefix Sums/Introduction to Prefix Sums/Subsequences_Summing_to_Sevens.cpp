#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 7;
int N, first[7]; //first[i] stores the index of the first prefix sum which % 7 = i

int main(){
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

	cin >> N;
	
	memset(first, -1, sizeof(first));
	first[0] = 0;

	int cow, remainder = 0, ans = 0;
	for(int i=1; i<=N; ++i){
		cin >> cow;
		remainder = (remainder + cow) % MOD;
		if(first[remainder] == -1) first[remainder] = i;
		else ans = max(ans, i - first[remainder]);
	}
	cout << ans << "\n";
}
