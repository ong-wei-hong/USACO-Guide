#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*an invalid tree has a cow with characteristics from two seperate branches
* ie theres cow with A not B, cow with B not A and cow with A and B
* the tree is invalid as the cow with A and B cannot be a child node of both A not B and B not A*/

const int MxN=25;
int N;
vector<string> characteristics[25], all_characteristics;

bool crossed(int i, int j){ // trying to find cow with all_characteristics[i] and / or all_characteristics[j]
	bool A=0, B=0, AB=0;
	for(int k=0; k<N; ++k){ //looking at each cow
		bool a=0, b=0;
		for(int l=0; l<characteristics[k].size(); ++l){ //looking at each cow's characteristic
			if(characteristics[k][l] == all_characteristics[i]) a=1;
			if(characteristics[k][l] == all_characteristics[j]) b=1;
		}
		if(a && b) AB=1;
		else if(a) A=1;
		else if(b) B=1;
	}
	return AB && A && B;
}

int main(){
	freopen("evolution.in", "r", stdin);
	freopen("evolution.out", "w", stdout);

	cin>>N;
	int K;
	string s;
	for(int i=0; i<N; ++i){
		cin>>K;
		for(int j=0; j<K; ++j){
			cin>>s;
			characteristics[i].push_back(s);
			if(find(all_characteristics.begin(), all_characteristics.end(), s) == all_characteristics.end())
				all_characteristics.push_back(s);
		}
	}

	for(int i=0; i<all_characteristics.size(); ++i)
		for(int j=i+1; j<all_characteristics.size(); ++j)
			if(crossed(i, j)){ //checks all pairs of characteristics if "crossed"
				cout<<"no\n";
				return 0;
			}
	cout<<"yes\n";
}
