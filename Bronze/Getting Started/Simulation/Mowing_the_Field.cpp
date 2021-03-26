#include <bits/stdc++.h>
using namespace std;

int farm[2002][2002];

int main(){
  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);

  for(int i=0; i<2002; ++i)
    for(int j=0; j<2002; ++j)
      farm[i][j]=-1;

  int ans=1e9, t=0, x=1000, y=1000;
  bool check=1;

  int n;
  cin>>n;
  for(int i=0; i<n; ++i){
    char d;
    int s;
    cin>>d>>s;

    auto update=[&] (int& v, bool pos){
      for(int j=1; j<=s; ++j){
	++t;
	if(pos) ++v;
	else --v;
	if(~farm[x][y]){
	  check=0;
	  ans=min(ans, t-farm[x][y]);
	}
	farm[x][y]=t;
      }
    };

    if(d=='N')
      update(y, 1);
    else if(d=='S')
      update(y, 0);
    else if(d=='E')
      update(x, 1);
    else if(d='W')
      update(x, 0);
  }
  if(check)
    cout<<-1;
  else
    cout<<ans;
}
