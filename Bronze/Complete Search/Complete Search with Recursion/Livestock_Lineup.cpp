#include <iostream>
#include <algorithm>
using namespace std;

int N;
string cows[8]={"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"}, constraints[7][2];

int index(string cow){
  for(int i=0; i<8; ++i)
    if(cow==cows[i])
      return i;
  return -1;
}

bool valid(){
  for(int i=0; i<N; ++i)
    if(abs(index(constraints[i][0])-index(constraints[i][1]))!=1)
      return 0;
  return 1;
}

int main(){
  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);
  cin>>N;  
  for(int i=0; i<N; ++i){
    string a, b, t;
    cin>>constraints[i][0]>>t>>t>>t>>t>>constraints[i][1];
  }
  do{
    if(valid()){
      for(int i=0; i<8; ++i)
	cout<<cows[i]<<endl;
      return 0;
    }
  }while(next_permutation(cows, cows+8));
}
