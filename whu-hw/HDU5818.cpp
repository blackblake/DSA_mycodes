#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct stack
{
    int data[10];//这个动态数组的问题待解决
    int top;
    stack(){
        top=-1;
    }
};


int main(){
    ifstream infile("in.txt");
    vector<int>vec;
    vector<int>vec2;
    
    int n;
    infile>>n;
    stack a;
    stack b;

    for(int i=0;i<n;i++){
        string str;
        infile>>str;
        if(str=="push"){
            char s;
            infile>>s;
            if(s=='A'){
                int e;infile>>e;
                a.top++;
                a.data[a.top]=e;
                vec.push_back(e);
            }
            else if(s=='B'){
                int e;infile>>e;
                b.top++;
                b.data[b.top]=e;
                vec.push_back(e);
            }
        }
        else if(str=="pop"){
            char s;
            infile>>s;
            if(s=='A'){
                if(a.top==-1){
                    return 0;
                };
                cout<<a.data[a.top]<<endl;
                vec2.push_back(a.data[a.top]);
                a.top--;
            }
            else if(s=='B'){
                if(b.top==-1){
                    continue;
                };
                cout<<b.data[b.top]<<endl;
                vec2.push_back(b.data[b.top]);
                b.top--;
            }
        }
        else if(str=="merge"){
        	bool flag=true;
    
            for(int j=vec.size()-1;j>=0;j--){
                    for(int p=0;p<vec2.size();p++){
                        if (vec2[p]==vec[j]){
                            flag=false;
                        }
                    }
                    if(flag==true){
                        cout<<vec[j]<<endl;
                    }
                    flag=true;
            }
    infile.close();
    return 0;
        }  
    }

}