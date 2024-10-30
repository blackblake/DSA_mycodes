#include <iostream>
using namespace std;

class SqList{
public:
    int* data;
    int capacity;
    int length;

    SqList(int n){
        data=new int(n);
    };
};

int main(){
    
    //处理第一行输入
    int k1,k2;
    cin>>k1>>k2;

    if(k1>k2){
        return false;
    }

    //第二行输入
    int n;
    cin>>n;

    //存储第三行输入
    SqList list(n);
    for(int i=0;i<n;i++){
        cin>>list.data[i];
    }


   int* help=new int(n);
   int j=0;

   for(int i=0;i<n;i++){
       if(list.data[i]<k1){
        help[j]=list.data[i];
        j++;
       }
    }
	
	cout<<j;
	
    for(int i=0;i<n;i++){
       if(list.data[i]>=k1&&list.data[i]<k2){
        help[j]=list.data[i];
        j++;
       }
    }
	
	cout<<j;
	
    for(int i=0;i<n;i++){
       if(list.data[i]>=k2){
        help[j]=list.data[i];
        j++;
       }
    }

    list.data=help;
    /*for(int i=0;i<n;i++){
        cout<<list.data[i]<<" ";
    }*/
	
    return 0;
}