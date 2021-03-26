#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);
  int n, m;
  cin>>n>>m;
  int limit [100], counter=0;
  for(int i=0; i<n; ++i){
    int length, speed;
    cin>>length>>speed;
    for(int j=0; j<length; ++j){
      limit[counter]=speed;
      ++counter;
    }
  }
  int bessie[100];
  counter=0;
  for(int i=0; i<m; ++i){
    int length, speed;
    cin>>length>>speed;
    for(int j=0; j<length; ++j){
      bessie[counter]=speed;
      ++counter;
    }
  }
  int ans=0;
  for(int i=0; i<100; ++i) //compares the speed and limit at all points of road
    ans=max(ans, bessie[i]-limit[i]);

  cout<<ans;
}
