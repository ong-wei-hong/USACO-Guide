#include <iostream>
using namespace std;

int N, canvas[10][10];

bool appears(int c){
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			if(canvas[i][j]==c)
				return true;
	return false;
}

/*establish the left, right, top, bot bound of c2, 
 * if c1 appears inside, c1 is above c2*/

bool above(int c1, int c2){ //c1 above c2
	int top=N, bot=0, right=0, left=N;
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			if(canvas[i][j]==c2){
				top=min(top, i);
				bot=max(bot, i);
				left=min(left, j);
				right=max(right, j);
			}
	for(int i=top; i<=bot; ++i)
		for(int j=left; j<=right; ++j)
			if(canvas[i][j]==c1)
				return true;
	return false;
}

int main(){
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	cin>>N;
	for(int i=0; i<N; ++i){
		string s;
		cin>>s;
		for(int j=0; j<N; ++j)
			canvas[i][j]=s[j]-'0';
	}
	int ans=0;
	for(int i=1; i<=9; ++i)
		if(appears(i)){
			bool first=true;
			for(int j=1; j<=9; ++j)
				if(i!=j && appears(j) && above(i, j))
					first=false;
			if(first)
				++ans;
		}
	cout<<ans;
	return 0;
}
