#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    queue<int> q;
    
    
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    
    int cnt = 1; 
    
    while (q.size() > 2) {
        int size = q.size();
        queue<int> temp;
        
        if (cnt % 2 == 1) { 
            int skip = 0;
            while (!q.empty()) {
                int person = q.front();
                q.pop();
                
                if (++skip == 3) {
                    
                    skip = 0;
                } else {
                    temp.push(person);
                }
            }
        } else {
            int skip = 0;
            while (!q.empty()) {
                int person = q.front();
                q.pop();
                
                if (++skip == 2) {
                   
                    skip = 0; 
                } else {
                    temp.push(person);
                }
            }
        }
        
        q = temp; 
        cnt++;
    }
    
   
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
