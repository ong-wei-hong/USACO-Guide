#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int mxN=100;
int N;
pair<int, int> cows[mxN]; //cows[i].first is the time it arrives, cows[i].second is the time it takes

int main(){
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);

  cin>>N;
  for(int i=0; i<N; ++i)
    cin>>cows[i].first>>cows[i].second;
  sort(cows, cows+N);

  int time=0;
  for(int i=0; i<N; ++i){
    if(time>=cows[i].first)
      time+=cows[i].second;
    else
      time=cows[i].first+cows[i].second;
  }
  cout<<time;
}