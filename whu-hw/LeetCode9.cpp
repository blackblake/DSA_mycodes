#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isPalindrome(int x){
    string str=to_string(x);
    string invstr;
    for(int i=str.size()-1;i>=0;i--){
        invstr+=str[i];
    }
    if(str==invstr){
        return 1;
    }
    else{return 0;}
}

int main(){
    ifstream infile("in.txt");
    int num;
    infile>>num;
    
    cout<<isPalindrome(num);

    infile.close();
    return 0;
}