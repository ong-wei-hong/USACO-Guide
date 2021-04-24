#include <iostream>
#include <algorithm>
using namespace std;
 
const int mxN=100;
int N, bales[mxN];
  
int main(){
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  cin>>N;
  for(int i=0; i<N; ++i)
    cin>>bales[i];
  sort(bales, bales+N);

  int ans=1;
  
  for(int i=0; i<N; ++i){
    int t=0, left_index=i, right_index=i;
    while(true){ //calculate how far left the explosion goes
      bool done=1;
      ++t;
      int left=bales[left_index]-t;
      while(left_index>0&&bales[left_index-1]>=left){ //if the next left bale combusts
	--left_index;
	done=0;
      }
      if(done) break;
    }

    t=0;
    while(true){ //same for right
      bool done=1;
      ++t;
      int right=bales[right_index]+t;
      while(right_index<(N-1)&&bales[right_index+1]<=right){
	++right_index;
	done=0;
      }
      if(done) break;
    }

    ans=max(ans, right_index-left_index+1);
  }
  cout<<ans;
}
