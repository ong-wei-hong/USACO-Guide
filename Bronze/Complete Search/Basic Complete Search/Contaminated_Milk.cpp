#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Drink{
  int p, m, t;
};

struct Sick{ 
  int p, t;
};
  
const int mxN=50, mxM=50, mxD=1e4, mxT=100;
int N, M, D, S;
Drink drink[mxD]; //drink [d] has p, m, t
Sick sick[mxN]; //sick[n] has p, t

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("badmilk.in", "r", stdin);
  freopen("badmilk.out", "w", stdout);
  cin>>N>>M>>D>>S;
  for(int i=0; i<D; ++i)
    cin>>drink[i].p>>drink[i].m>>drink[i].t;
  for(int i=0; i<S; ++i)
    cin>>sick[i].p>>sick[i].t;
  
  vector<int> drank[N+1]; //drank[n] has m[] (only sick people)
  for(int i=0; i<D; ++i)
    for(int j=0; j<S; ++j)
      if(drink[i].p==sick[j].p&&drink[i].t<sick[j].t)
	drank[drink[i].p].push_back(drink[i].m);
  
  bool badMilk[M+1];//badMilk[m] == 1 if m is bad
  fill_n(badMilk, M+1, 1);
  
  for(int milk=1; milk<=M; ++milk){
    for(int person=1; person<=N; ++person){
      if(size(drank[person])){//if person is sick and drank milk
	bool possible=1;
	for(int drunk: drank[person]){
	  if(drunk==milk){
	    possible=0;
	    break;
	  }
	}
	if(possible)
	  badMilk[milk]=0;
      }
    }
  }
  
  bool isSick[N+1];//isSick[n] == 1 if n is sick
  fill_n(isSick, N+1, 0);
  
  for(int milk=1; milk<=M; ++milk)
    for(int i=0; i<D; ++i)
      if(badMilk[milk]&&drink[i].m==milk)
	isSick[drink[i].p]=1;
      
  int ans=0;
  for(int i=1; i<=N; ++i)
    ans+=isSick[i];

  cout<<ans;
}
