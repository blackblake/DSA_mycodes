#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

struct stack
{
    char* data;
    int top;
    int max;

    stack(int n){
        data=new char[n];
        top=-1;
        max=n;
    }

    void push(char val){
        if(top!=max-1){
            top++;
            data[top]=val;
        }
    }

   void pop(){
        if(top!=-1){
            char e = data[top];
            top--;
        }
    }

    char gettop(){
        if(top!=-1){
            char e=data[top];
            return e;
        }
    }
};


int main(){
    ifstream infile("in.txt");
    int N;infile>>N;
    
    stack stk(N);
    vector<char>vec1(N);
    vector<char>vec2(N);

    for(int i=0;i<N;i++){
        char e;
        infile>>e;
        vec1.push_back(e);
    }
    
    int j=0;
    for(int i=0;i<N;i++){
        char e;
        infile>>e;
        if(stk.top==-1){
            stk.push(vec1[j]);
            j++;
        }

        while(stk.gettop()!=e){
            stk.push(vec1[j]);
            j++;
        }

        if(stk.gettop()==e){
            stk.pop();
        }
    }

    if(stk.top!=-1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
	
	infile.close();
	
    return 0;}