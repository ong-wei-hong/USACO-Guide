#include <iostream>
using namespace std;

#define ll long long

const int mxN=100;
int N, X[mxN], Y[mxN];

int main(){
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  cin>>N;
  for(int i=0; i<N; ++i)
    cin>>X[i]>>Y[i];
  //taking i to be the corner, j to be the verticle and k the horizontal
  ll ans=-1;
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      for(int k=0; k<N; ++k){
	if(X[i]==X[j]&&Y[i]==Y[k]){
	  ll curr=(X[i]-X[k])*(Y[i]-Y[j]);
	  if(curr<0) curr*=-1;
	  ans=max(ans, curr);
	}
      }
    }
  }
  cout<<ans;
}
