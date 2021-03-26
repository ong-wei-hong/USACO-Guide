#include <bits/stdc++.h>
using namespace std;

const int mxN=100;
int p[mxN], n, ans;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0; i<n; ++i)
    cin>>p[i];
  for(int i=0; i<n; ++i){ //sees if theres an average flower for each case (i, j)
    for(int j=i; j<n; ++j){
      int sum=0;
      for(int k=i; k<=j; ++k)
	sum+=p[k];
      for(int k=i; k<=j;++k){
	if(p[k]*(j-i+1)==sum){
	  ++ans;
	  break;
	}
      }
    }
  }
  cout<<ans;
}
