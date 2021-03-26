#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);
  int x, y;
  cin>>x>>y;

  ll ans=0, dir=1, dis=1;
  
  while(true){
    if((dir==1&&y>=x&&y<=x+dis)||(dir==-1&&y<=x&&y>=x-dis)){ //bessie in within range
      ans+=abs(y-x);
      cout<<ans;
      return 0;
    }else{
      dir*=-1;
      ans+=dis*2;//walk to end and back
      dis*=2;
    }
  }
}
