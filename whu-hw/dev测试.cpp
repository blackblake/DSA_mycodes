#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	vector<int>vec(6);
	for(int i=0;i<6;i++){
		int val;
		cin>>val;
		vec[i]=val;
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<6;i++){
		cout<<vec[i];
	}
	return 0;
} 
