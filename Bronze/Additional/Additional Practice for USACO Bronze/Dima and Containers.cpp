#include <iostream>
using namespace std;

const int MxN=1e5;
int n, a[MxN];

int main(){
	cin >> n;

	for(int i=0; i<n; ++i)
		cin >> a[i];

	int max1 = -1, max2 = -1, max3 = -1;
	int index = 0;
	for(int i=0; i<n; ++i){
		if(a[i]){ //find the three highest to pop
			if(a[i] > max1){
				max3 = max2;
				max2 = max1;
				max1 = a[i];
			}else if(a[i] > max2){
				max3 = max2;
				max2 = a[i];
			}else if(a[i] > max3)
				max3 = a[i];
		}else{ //if a is 0 ie pop all containers
			while(index < i){ //cout the push commands before the pop
				if(a[index] == max1){ //-1 means max is empty, 0 means max has pushed already
					cout << "pushStack\n";
					max1 = 0;
				}else if(a[index] == max2){
					cout << "pushQueue\n";
					max2 = 0;
				}else if(a[index] == max3){
					cout << "pushFront\n";
					max3 = 0;
				}else
					cout << "pushBack\n";
				++index;
			}
			if(max1) //cout the pop commands
				cout << "0\n";
			else if(max2)
				cout<<"1 popStack\n";
			else if(max3)
				cout<<"2 popStack popQueue\n";
			else
				cout<<"3 popStack popQueue popFront\n";
			++index;
			max1 = max2 = max3 = -1;
		}
	}

	while(index < n){ //handle the push commands after the last pop
		cout<<"pushBack\n";
		++index;
	}
}
