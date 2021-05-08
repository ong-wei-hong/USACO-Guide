#include <iostream>
using namespace std;

const int MxN=10;
int N;
bool cows[MxN][MxN];
	
int flip(int x, int y){
	if(cows[x][y]){ //if cow is tipped
		for(int i=0; i<=x; ++i)
			for(int j=0; j<=y; ++j)
				cows[i][j]=!cows[i][j];
		return 1;
	}
	return 0;
}

int main(){
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);

	cin>>N;
	for(int i=0; i<N; ++i){
		string s;
		cin>>s;
		for(int j=0; j<N; ++j)
			cows[i][j]=(s[j]=='1');
	}
	int x=N-1, y=N-1, ans=0;
	while(x>=0&&y>=0){
		ans+=flip(x,y);
		if(x!=y) //checks the other orientation of rectangle
			ans+=flip(y,x);
		if(x>0)
			--x;
		else{
			--y;
			x=y;
		}
	}
	cout<<ans;
}
