#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    string s;
        int i=0;
        while(i<chars.size()){
            char ch=chars[i];
            
            if(chars[i]=='0'){
                i++;
				continue;
            }
            
            s+=ch;

            int cnt=1;
            for(int j=i+1;j<chars.size();j++){
                if(chars[j]==ch){
                    cnt+=1;
                    chars[j]='0';
                }
            }
            if(cnt>1){
                string s0=to_string(cnt);
                s+=s0;
            }
            i++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            chars[i]=s[i];
        }
        
        return s.length();
}

int main() {
    /*vector<char> chars;
    char ch;

    while (cin >> ch) {
        chars.push_back(ch);
    }

    // 压缩数组并获取新长度
    int newLength = compress(chars);

    // 输出压缩后的数组
    for (int i = 0; i < newLength; ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;
*/
    
    int num=stoi("666");
    cout<<num;
    return 0;
}
