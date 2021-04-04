#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int x[100], y[100], N, B;
set<int> a, b;

int main(){
  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);
  cin>>N>>B;
  for(int i=0; i<N; ++i){
    cin>>x[i]>>y[i];
    a.insert(x[i]+1);
    b.insert(y[i]+1);
  }
  int ans=101;
  for(int i: a){
    for(int j: b){
      int m=0, n=0, o=0, p=0;
      for(int k=0; k<N; ++k){
	if(x[k]<i&&y[k]<j)
	  ++m;
	else if(x[k]<i&&y[k]>j)
	  ++n;
	else if(x[k]>i&&y[k]<j)
	  ++o;
	else if(x[k]>i&&y[k]>j)
	  ++p;
      }
      ans=min(ans, max({m, n, o, p}));
    }
  }
  cout<<ans;
}
