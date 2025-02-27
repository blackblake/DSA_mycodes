#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    fstream infile("in.txt");
    
    int n,m;
    infile>>n>>m;
    vector<int>vec1(n);
    vector<int>vec2(m);
    vector<int>vec3(n+m+1);
    vec3[n+m]=0;
    vector<int>result(n+m);

    for(int i=0;i<vec1.size();i++){
        infile>>vec1[i];
    }

    for(int i=0;i<vec2.size();i++){
        infile>>vec2[i];
    }

    for(int i=0;i<n;i++){
        vec3[i]=vec1[i];
    }

    int j=0;
    for(int i=n;i<n+m;i++){
        vec3[i]=vec2[j];
        j++;
    }

   sort(vec3.begin(),vec3.end(),greater<int>());

    for(int i=0;i<n+m;i++){
        if(vec3[i]!=vec3[i+1]){
            result[result.size()-1-i]=vec3[i];
        }
    }
    
    for(int i=0;i<result.size();i++){
    	if(result[i]!=0){
			cout<<result[i]<<" ";
		}
	}

    return 0;
}