#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//取滑动窗口最小值的函数
void minQue(queue<int>&qu,int& min,int& max,int inpu){
    int temp=qu.back();
    if(qu.front()==min){
        qu.pop();
        if(qu.front()<temp){
            min=qu.front();
        }else{
            min=temp;
        }
    }
    else if(qu.front()==max){
    	qu.pop();
    	if(qu.front()>temp){
    		max=qu.front();
		}else{
			max=temp;
		}
	}
    
	else{
        qu.pop();
    }
    if(inpu<min){
        min=inpu;
    }
    if(inpu>max){
    	max=inpu;
	}
    qu.push(inpu);
}

int main(){
    int n, k;
cin >> n >> k;
vector<int> vec;     // 不需要指定大小，直接动态添加
vector<int> vec1;    // 保存第一行输出
vector<int> vec2;    // 保存第二行输出

for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    vec.push_back(val);  // 动态添加输入到 vec
}


    queue<int>qu;
    int min=vec[0];
   int max=vec[0];
    for(int i=0;i<k;i++){
        qu.push(vec[i]);
        if(vec[i]<min){
            min=vec[i];
        }
        if(vec[i]>max){
            max=vec[i];
        }
    }//滑动窗口初始化完毕,此时min等于前三个元素中的最小值
    vec1.push_back(min);
    vec2.push_back(max);
    int i=3;
    while (i!=n)
    {
        minQue(qu,min,max,vec[i]);
        vec1.push_back(min);
        vec2.push_back(max);
        i++;
    }
    
    for(int j=0;j<vec1.size();j++){
        if(j==vec1.size()-1){
			cout<<vec1[j]<<endl;
		}else{
			cout<<vec1[j]<<" ";
    	}
	}

    for(int j=0;j<vec2.size();j++){
        if(j==vec2.size()-1){
			cout<<vec2[j]<<endl;
		}else{
			cout<<vec2[j]<<" ";
    	}
    }

    return 0;
}