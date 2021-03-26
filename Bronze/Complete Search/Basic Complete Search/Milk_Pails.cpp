#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen("pails.in","r",stdin);
  freopen("pails.out","w",stdout);
  int x, y, m, ans=0;
  cin>>x>>y>>m;
  for(int i=0; i<1001; ++i){ //goes through every combination of x and y
    if(i*x>m)
      break;
    for(int j=0; j<1001; ++j){
      int curr=i*x+j*y;
      if(curr>m)
	break;
      ans=max(ans, curr);
    }
  }
  cout<<ans;
}
