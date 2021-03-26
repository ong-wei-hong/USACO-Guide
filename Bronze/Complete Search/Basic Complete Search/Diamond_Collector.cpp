#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int a[mxN], n, k, ans;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);
  cin>>n>>k;
  for(int i=0; i<n; ++i)
    cin>>a[i];
  sort(a, a+n);
  for(int i=0; i<n; ++i){ //goes through every possible combination by setting the smallest diamond
    int count=1;
    for(int j=i+1; j<n; ++j){
      if(a[j]>a[i]+k)
	break;
      ++count;
    }
    ans=max(ans, count);
  }
  cout<<ans;
}
