#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);
  int m, n, k;
  cin>>m>>n>>k;
  for(int i=0; i<m; ++i){
    string s;
    cin>>s;
    for(int j=0; j<k; ++j){
      for(int l=0; l<n; ++l)
	for(int p=0; p<k; ++p)
	  cout<<s[l];
      cout<<endl;
    }
  }
}
