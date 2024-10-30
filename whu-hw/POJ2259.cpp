#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

queue<int> Q;        
queue<int> q[1010];  
int team[1000000];   // team[i] 表示成员 i 属于哪个团队

int main() {
    ifstream infile("in.txt");
    string str;
    int N;

    infile >> N;  // 读取团队数量
    for (int i = 1; i <= N; i++) {
        int n;infile >> n;  // 读取团队成员数量
        for (int j = 1; j <= n; j++) {
            int x;
            infile >> x;      // 读取成员编号
            team[x] = i;  // 将成员 x 归属到团队 i
        }
    }

    infile >> str;  // 读取操作
    while (str != "STOP") {
        if (str == "ENQUEUE") {
            int x;
            infile >> x;  // 读取要入队的成员编号
            if (q[team[x]].empty()) {  // 检查该团队是否为空
                Q.push(team[x]);  // 如果为空，将团队入队
            }
            q[team[x]].push(x);  // 将成员 x 入队
        } else {  // DEQUEUE
            cout << q[Q.front()].front() << endl;  // 输出队列头部成员
            q[Q.front()].pop();  // 移除队列头部成员
            if (q[Q.front()].empty()) {  
                Q.pop();
            }
        }
        infile >> str; 
    }
    
    return 0;
}