#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);
  int x1, x2, x3, x4, y1, y2, y3, y4;
  cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
  int p=0; //points covered;
  if(x3<=x1&&x4>=x1&&y3<=y1&&y4>=y1) ++p; //lower left
  if(x3<=x2&&x4>=x2&&y3<=y1&&y4>=y1) ++p; //lower right
  if(x3<=x2&&x4>=x2&&y3<=y2&&y4>=y2) ++p; //upper right
  if(x3<=x1&&x4>=x1&&y3<=y2&&y4>=y2) ++p; //upper left

  if(p<2)
    cout<<(x2-x1)*(y2-y1);
  else if(p==4)
    cout<<0;
  else{
    int llx=max(x1, x3);//lower left x
    int urx=min(x2, x4);//upper right x
    int lly=max(y1, y3);//lower left y
    int ury=min(y2, y4);//upper right y
    cout<<(x2-x1)*(y2-y1)-(urx-llx)*(ury-lly);
  }
}
