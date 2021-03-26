#include <bits/stdc++.h>
using namespace std;

string s[3];
set<set<char>> winners[3];

void insert(vector<pair<int, int>> lines){
  set<char> c;
  for(pair<int, int>&p: lines)//counts the number of unique letters in a line
    c.insert(s[p.first][p.second]);
  winners[c.size()-1].insert(c);//inserts into a set to prevent double counting
}

int main(){
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);
  for(int i=0; i<3; ++i)
    cin>>s[i];
  for(int i=0; i<3; ++i) //rows
    insert({{i, 0}, {i, 1}, {i, 2}});
  for(int i=0; i<3; ++i) //columns
    insert({{0, i}, {1, i}, {2, i}});
  insert({{0, 0}, {1, 1}, {2, 2}}); //diagonals
  insert({{0, 2}, {1, 1}, {2, 0}});
  cout<<winners[0].size()<<endl;
  cout<<winners[1].size()<<endl;
}
