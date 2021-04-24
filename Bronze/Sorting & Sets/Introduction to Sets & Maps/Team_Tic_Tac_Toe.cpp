#include <iostream>
#include <set>
using namespace std;

string lines[3];
set<set<char>> winners[4]; //winners[i]=set of i cows who win together

void valid(char a, char b, char c){
  set<char> cows;
  cows.insert({a, b, c});
  
  winners[cows.size()].insert(cows);  
}

int main(){
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);

  for(int i=0; i<3; ++i)
    cin>>lines[i];
  
  for(int i=0; i<3; ++i) //horizontal
    valid(lines[i][0], lines[i][1], lines[i][2]);

  for(int i=0; i<3; ++i) //verticals
    valid(lines[0][i], lines[1][i], lines[2][i]);

  //two diagonals
  valid(lines[0][0], lines[1][1], lines[2][2]);
  valid(lines[0][2], lines[1][1], lines[2][0]);

  cout<<winners[1].size()<<endl<<winners[2].size();
}
