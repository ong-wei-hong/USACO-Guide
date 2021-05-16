#include <iostream>
using namespace std;

const int MxN = 1e5;
int N, Q, cows[3][MxN + 1];

int main(){
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	ios_base::sync_with_stdio(0); //due to large io
	cin.tie(0);


	cin >> N >> Q;

	int id;
	for(int i=1; i<=N; ++i){
		for(int j=0; j<3; ++j)
			cows[j][i] = cows[j][i-1];

		cin>>id;
		++cows[id - 1][i];
	}


	int a, b;
	for(int i=0; i<Q; ++i){
		cin >> a >> b;
		cout << cows[0][b] - cows[0][a - 1] << " " << cows[1][b] - cows[1][a - 1] << " " << cows[2][b] - cows[2][a - 1] << "\n";
		//for loop does not work due to extra space
	}
}
