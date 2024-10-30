#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct stack
{
    int* data;
    int top;
    int max;

    stack(int n){
        data=new int[n];
        top=-1;
        max=n;
    }

    void push(int val){
        if(top!=max-1){
            top++;
            data[top]=val;
        }
    }

   void pop(){
        if(top!=-1){
            int e = data[top];
            top--;
        }
    }

    int gettop(){
        if(top!=-1){
            int e=data[top];
            return e;
        }
    }
};


int main(){
    int N;

    while(cin>>N&&N!=0){
    	int x;

    while(cin>>x&&x!=0){
		stack stk(N);
    	queue<int>qu;
        qu.push(x);
        for(int i=1;i<N;i++){
        int e;
        cin>>e;
        qu.push(e);
    }
   
    for(int i=1;i<=N;i++){
        stk.push(i);

        while (stk.gettop()==qu.front())
        {
           qu.pop();
           stk.pop();
        }
        
    }

    if(stk.top==-1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    }cout<<endl;
	}
    
    

    return 0;}