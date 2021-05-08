#include <iostream>
using namespace std;

int K, N;

int main(){
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);

	cin>>K>>N;
	for(int i=0; i<N; ++i){
		int X, l=0, r=0, t=0;
		cin>>X;

		/* build a "triangle" on the left and right
		 * the left is from 0 to max speed
		 * the right is from max speed to X
		 * the sum of l and r is the max dist travelled
		 * if dist > K, time still remains the same as Bessie can run at a lower speed instead
		 * time is not lower as t-1 would be tested before*/

		for(int curr=1;;++curr){ 
			l += curr; //add the distance travelled with increasing speed
			++t;
			if(l + r >= K){
				cout<<t<<"\n";
				break;
			}
			if(curr >= X){
				r += curr; //add the distance travelled at current speed 
				++t; //increase t as 1 more second is needed to slow down to X
				if(l + r >= K){
					cout<<t<<"\n";
					break;
				}
			}
		}
	}
}
