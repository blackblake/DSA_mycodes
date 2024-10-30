#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct stack
{
    char* data;
    int top;
    int max;

    stack(int n){
        data = new char[n];
        top = -1;
        max = n;
    }

    void push(char val){
        if(top != max-1){
            top++;
            data[top] = val;
        }
    }

   void pop(){
        if(top != -1){
            top--;
        }
    }

    char gettop(){
        if(top != -1){
            return data[top];
        } else {
            return '\0'; // 当栈为空时返回空字符
        }
    }
};

int main(){
	//ifstream infile("in.txt");
    int N;
    cin >> N;
    
    stack stk(N);
    vector<char> vec1(N);
    vector<char> vec2(N);

    for(int i = 0; i < N; i++){
        char e;
        cin >> e;
        vec1[i] = e; // 注意：直接赋值，而不是 push_back！
    }
    
    for(int i = 0; i < N; i++){
        char e;
        cin >> e;
        vec2[i] = e;
    }

    int j = 0;
    for(int i = 0; i < N; i++){
        char e = vec2[i];

        if(stk.top == -1){
            stk.push(vec1[j]);
            j++;
        }

        while(stk.gettop() != e && j < N){
            stk.push(vec1[j]);
            j++;
        }

        if(stk.gettop() == e){
            stk.pop();
        } else {
            // 若无法找到匹配元素，直接输出 false 并返回
            cout << "false" ;
            return 0;
        }
    }

    // 若栈为空，说明匹配成功
    if(stk.top == -1){
        cout << "true" ;
    }
    else{
        cout << "false" ;
    }
	
	//cin.close(); 
    return 0;
}
