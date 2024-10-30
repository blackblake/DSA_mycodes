#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int sumDistance(vector<int>vec,int sec){
    int x=vec[0];
    int y=vec[1];
	int sum=x+(sec-1)*y;
    return sum;
}

void erasevec(vector<int>&vec){//记得引用传参
    vec[0]=0;
    vec[1]=0;
}


int main(){
	ifstream infile("in.txt");
    int N;infile>>N;
    vector<vector<int>>vec(N);

    for(int x=0;x<N;x++){
        int i;infile>>i;
        int j;infile>>j;
        vector<int>subvec(2);
        subvec[0]=i;
        subvec[1]=j;
        vec[x]=subvec;
    }

    int n=1;
    while (n<=N)
    {
        int temp=0;
        int flag=0;
        for(int i=0;i<vec.size();i++){
        	int sum=sumDistance(vec[i],n);
            if(sum>temp){
                temp=sumDistance(vec[i],n);
                flag=i;
            }
        }
        cout<<flag+1<<" ";
        erasevec(vec[flag]);
        n++;
    }
    

    return 0;
}