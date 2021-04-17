#include <iostream>
using namespace std;

const int mxN=12;
int N, wormhole[mxN+1], X[mxN+1], Y[mxN+1], in_front[mxN+1];//wormhole[i]=j means i and j are pairs, i=(X[i], Y[i]), in_front[i]=j means j is in front of i (X[j]>X[i]&&Y[j]==Y[i])

bool cycle(){
  for(int i=1; i<=N; ++i){
    int curr=i;
    for(int j=0; j<N; ++j)
      curr=in_front[wormhole[curr]];
    if(curr!=0) return 1;
  }
  return 0;
}

int solve(){//goes through all possible pairings
  int i, ans=0;
  for(i=1; i<=N; ++i)//find first unparied wormhole
    if(!wormhole[i]) break;

  if(i>N)//all wormholes are paired
    return cycle();

  for(int j=i+1; j<=N; ++j){//pair i and j
    if(wormhole[j]==0){//find next unpaired wormhole
      wormhole[i]=j;
      wormhole[j]=i;
      ans+=solve();
      wormhole[i]=wormhole[j]=0;//reset pairing for next combination
    }
  }
  return ans;
}

int main(){
  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);

  cin>>N;
  for(int i=1; i<=N; ++i)//start counting from 1, so 0 would indicate no wormhole present
    cin>>X[i]>>Y[i];

  for(int i=1; i<=N; ++i)
    for(int j=1; j<=N; ++j)
      if(X[j]>X[i]&&Y[i]==Y[j])//j right of i
	if(!in_front[i]||X[j]<X[in_front[i]])
	  in_front[i]=j;
  
  cout<<solve();
}
