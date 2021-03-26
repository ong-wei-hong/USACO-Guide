#include <bits/stdc++.h>
using namespace std;

const int mxN=1e4;
int n, r[mxN];

int main(){
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);
  cin>>n;
  int total=0;
  for(int i=0; i<n; ++i){
    cin>>r[i];
    total+=r[i];
  }
  int ans=INT_MAX;
  for(int i=0; i<n; ++i){
    int curr=0, cows=total;
    for(int j=0; j<n; ++j){
      cows-=r[(i+j)%n];
      curr+=cows; 
    }
    ans=min(ans, curr);
  }
  cout<<ans;
}
