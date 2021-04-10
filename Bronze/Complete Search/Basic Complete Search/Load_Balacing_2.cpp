#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define x first
#define y second

int main(){
  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  int N;
  cin>>N;

  vector<pair<int, int>> cows(N);
  for(int i=0; i<N; ++i)
    cin>>cows[i].x>>cows[i].y;

  sort(cows.begin(), cows.end());

  int ans=1000;
  vector<int> ys(N);
  for(int dx=0; dx<=N; ++dx){//split the cows into 2 groups of dx and N-dx
    for(int i=0; i<N; ++i)
      ys[i]=cows[i].y;
    
    auto ylb=ys.begin();
    auto yla=ys.begin()+dx;
    auto yrb=ys.begin()+dx;
    auto yra=ys.end();

    sort(ylb, yla);//sort the y positions of the group separately
    sort(yrb, yra);

    int szl=dx, szr=N-dx;

    for(int i=0; i<N; ++i){
      int y=cows[i].y+1;
      auto it1=lower_bound(ylb, yla, y);
      auto it2=lower_bound(yrb, yra, y);
      int ll=it1-ylb;
      int lr=it2-yrb;
      int ul=szl-ll;
      int ur=szr-lr;
      int m=max({ll, lr, ul, ur});
      ans=min(ans, m);
    }
  }
  cout<<ans;
}
