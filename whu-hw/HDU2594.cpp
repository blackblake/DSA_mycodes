/*#include<iostream>
#include<vector>
#include<string>
using namespace std;

void getNext(vector<int>&next,string& s){
    int j=0;
    next[0]=0;
    for(int i=1;i<s.size();i++){
        while (j>0&&s[i]!=s[j])
        {
            j=next[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        next[i]=j;
    }
}

int main(){
    string s1,s2;
    while (cin>>s1)
    {
        cin>>s2;
        string str=s1+s2;
        vector<int>next(str.length());
        getNext(next,str);

        if(next[next.size()-1]>s1.length()){
            cout<<s1;
            cout<<" "<<s1.length();
        }
        else{
            for(int i=0;i<next[next.size()-1];i++){
                cout<<str[i];
            }

            if(next[next.size()-1]==0){cout<<0;}
            else{cout<<" "<<next[next.size()-1];}
        }
    }
    

    return 0;
}*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int nextval[100100];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    s1 += s2;  // 将 s2 连接到 s1 后面

    // 求新的 s1 的 next 数组
    int i = 0, k = -1;
    nextval[0] = -1;

    while (i < s1.length()) {
        if (k == -1 || s1[i] == s1[k]) {
            i++;
            k++;
            if (s1[i] == s1[k]) {
                nextval[i] = k;
            } else {
                nextval[i] = nextval[k];
            }
        } else {
            k = nextval[k];
        }
    }

    int common = nextval[s1.length() - 1] + 1;

    if (common > min(s1.length(), s2.length())) {
        common = min(s1.length(), s2.length());
    }

    cout << s1.substr(0, common) << " " << common << endl;

    return 0;
}
