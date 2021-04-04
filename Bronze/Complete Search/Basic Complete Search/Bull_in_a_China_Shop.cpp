#include <iostream>
using namespace std;

int N, K, side[11][4];//N is the length, K is the num of pieces, side[i]={top, bot, right, left}
bool piece[11][8][8];

bool check(int i, int x, int y){ //check if location of piece is '#'
  bool ans=(x>=0&&x<N&&y>=0&&y<N&&piece[i][x][y]);
  return ans;
}

bool ok(int i, int j, int ix, int iy, int jx, int jy){ //check if pieces fit as desired
  for(int x=0; x<N; ++x){ //iterates through all locations for a particular config
    for(int y=0; y<N; ++y){
      bool piece_i=check(i, x+ix, y+iy);
      bool piece_j=check(j, x+jx, y+jy);

      if(piece_i&&piece_j) //'#' in same place
	return 0;

      if(piece[0][x][y]!=(piece_i||piece_j))//doesnt fit as desired
	return 0;
    }
  }
  return 1;
}

int main(){\
  freopen("bcs.in", "r", stdin);
  freopen("bcs.out", "w", stdout);
  
  cin>>N>>K;
  for(int i=0; i<=K; ++i){
    int top=N-1, bot=0, right=0, left=N-1;
    char c;
    for(int j=0; j<N; ++j){
      for(int k=0; k<N; ++k){
	cin>>c;
	piece[i][j][k]=(c=='#');
	if(piece[i][j][k]){
	  top=min(top, j);
	  bot=max(bot, j);
	  right=max(right, k);
	  left=min(left, k);
	}
      }
    }
    side[i][0]=top;
    side[i][1]=bot;
    side[i][2]=right;
    side[i][3]=left;
  }
  for(int i=1; i<=K; ++i){
    for(int j=i+1; j<=K; ++j){//iterate through all pieces
      for(int idx=side[i][1]-N+1; idx<=side[i][0]; ++idx){      // ##.. run x-2 to x
	for(int idy=side[i][2]-N+1; idy<=side[i][3]; ++idy){    // #... run y-2 to y
	  for(int jdx=side[j][1]-N+1; jdx<=side[j][0]; ++jdx){  // .... ie bot-N+1 to top
	    for(int jdy=side[j][2]-N+1; jdy<=side[j][3]; ++jdy){// .... and r-N+1 to l
	      if(ok(i, j, idx, idy, jdx, jdy)){
		  cout<<i<<" "<<j;
		  return 0;	
	      }
	    }
	  }
	}
      }
    }
  }
}
