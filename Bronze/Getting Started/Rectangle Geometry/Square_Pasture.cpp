#include <bits/stdc++.h>
using namespace std;

int minX=11, minY=11, maxX=-1, maxY=-1;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("square.in", "r", stdin);
  freopen("square.out", "w", stdout);
  for(int i=0; i<8; ++i){ //the area is the square of the larger distance, between the smallest and largest x or the smallest and largest y
    if(i%2==0){
      int x;
      cin>>x;
      minX=min(x, minX);
      maxX=max(x, maxX);
    }else{
      int y;
      cin>>y;
      minY=min(y, minY);
      maxY=max(y, maxY);
    }
  }
  int ans;
  ans=max(maxX-minX, maxY-minY);
  cout<<ans*ans;
}
