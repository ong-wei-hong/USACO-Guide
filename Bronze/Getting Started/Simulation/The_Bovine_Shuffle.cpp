#include <bits/stdc++.h>

const int mxN=100;
int n, shuffle[mxN+1], order[mxN+1], prev[mxN+1];

int main(){
  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);
  std::cin>>n;
  for(int i=1; i<=n; ++i)
    std::cin>>shuffle[i];
  for(int i=1; i<=n; ++i)
    std::cin>>order[i];
  for(int i=0; i<3; ++i){ //goes through the reverse shuffle
    for(int j=1; j<=n; ++j)
      prev[j]=order[shuffle[j]];
    for(int j=1; j<=n; ++j)
      order[j]=prev[j];
  }
  for(int i=1; i<=n; ++i)
    std::cout<<order[i]<<std::endl;
}
