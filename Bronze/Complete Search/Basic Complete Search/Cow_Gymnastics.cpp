#include <bits/stdc++.h>
using namespace std;

const int mxN=20;
int k, n, ans, a[mxN];
bool b[mxN][mxN]; //b[i][j] means i+1th did better than the j+1th cow once or more

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);
  cin>>k>>n;
  for(int i=0; i<k; ++i){
    for(int j=0; j<n; ++j)
      cin>>a[j];
    for(int j=0; j<n; ++j)
      for(int l=j+1; l<n; ++l)
	b[a[j]-1][a[l]-1]=1;
  }
  for(int i=0; i<n; ++i){
    for(int j=i+1; j<n; ++j){
      if(b[i][j]&&b[j][i]) continue;
      ++ans;
    }
  }
  cout<<ans;
}
