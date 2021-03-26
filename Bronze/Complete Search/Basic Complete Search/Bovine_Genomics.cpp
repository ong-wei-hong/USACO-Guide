#include <bits/stdc++.h>
using namespace std;

const int mxN=100;
int n, m, ans;
string a[2*mxN];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);
  cin>>n>>m;
  for(int i=0; i<2*n; ++i)
    cin>>a[i];
  for(int i=0; i<m; ++i){
    bool gene=1;
    for(int j=0; j<n; ++j){
      for(int k=n; k<2*n; ++k){
	if(a[j][i]==a[k][i]){ //if any of the 1st..n-1th spotted cow has the same genome as the nth to (2n-1)th plain cow, the gene is not a potential location
	  gene=0;
	  break;
	}
      }
    }
    if(gene)
      ++ans;
  }
  cout<<ans;
}
