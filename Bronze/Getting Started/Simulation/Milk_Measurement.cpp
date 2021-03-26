#include <bits/stdc++.h>
using namespace std;

const int mxN=100;
// change[x][y] is for cow x (0 is Bessie, 1 is Elsie, 2 is Mildred) on day y
int change[3][mxN+1], rate[3][mxN+1];

bool highest(int a,int b){
  int high=max(rate[0][b], max(rate[1][b], rate[2][b]));
  return rate[a][b]==high;
}

int main(){
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  int n;
  cin>>n;
  for(int i=0; i<n; ++i){
    int a, b, c;
    string name;
    cin>>a>>name>>b;
    if(name=="Bessie") c=0;
    if(name=="Elsie") c=1;
    if(name=="Mildred") c=2;
    change[c][a]=b;
  }

  for(int i=0; i<3; ++i)
    rate[i][0]=7;

  for(int i=1; i<=100; ++i)
    for(int j=0; j<3; ++j)
      rate[j][i]=rate[j][i-1]+change[j][i];

  int ans=0;
  for(int i=1; i<100; ++i){
    if(highest(0, i-1)!=highest(0, i)||highest(1, i-1)!=highest(1, i)||highest(2, i-1)!=highest(2, i))
      ++ans;
  }
  cout<<ans;
}
