#include <iostream>
#include <set>
using namespace std;

const int Mxk=2e3;
int k, n, judge[Mxk + 1], points[Mxk + 1];

int main(){
  cin >> k >> n;
  for(int i = 1; i <= k; ++i){
    cin >> judge[i];
    judge[i] += judge[i - 1];
  }
  for(int i = 0; i < n; ++i)
    cin >> points[i];
  set<int> initial;//initial point = point - sum of judge
  for(int i = 1; i <= k; ++i)
      initial.insert(points[0] - judge[i]);
  int ans = 0;
  for(int i : initial){
    set<int> check;
    for(int j = 1; j <= k; ++j)
      check.insert(i + judge[j]);
    bool valid = 1;
    for(int j = 0; j < n; ++j)
      valid &= check.count(points[j]);
    ans+=valid;
  }
  cout << ans;
}
