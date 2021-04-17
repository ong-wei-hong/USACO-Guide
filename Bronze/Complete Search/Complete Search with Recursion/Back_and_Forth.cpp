#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

vector<int> a(10), b(10);
set<int> possible;

void search(int day, pair<int, vector<int>> x, pair<int, vector<int>> y){//moves a bucket from x to y
  if(day==4){
    possible.insert(x.first);
    return;
  }
  for(int i=0; i<(x.second).size(); ++i){
    int t=x.second[i];
    vector<int> X=x.second;
    X.erase(begin(X)+i);
    vector<int> Y=y.second;
    Y.push_back(t);
    search(day+1, {y.first+t, Y}, {x.first-t, X});
  }
}

int main(){
  freopen("backforth.in", "r", stdin);
  freopen("backforth.out", "w", stdout);

  vector<int> a(10), b(10);
  
  for(int i=0; i<10; ++i)
    cin>>a[i];
  for(int i=0; i<10; ++i)
    cin>>b[i];

  search(0, {1000, a}, {1000, b});
  cout<<possible.size();
}
