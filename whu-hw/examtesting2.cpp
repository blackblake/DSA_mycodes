/*#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct node
{
    int data;
    node*next;
    node(){
        next=nullptr;
    }
    node(int val){
        data=val;
        next=nullptr;
    }
};


int main(){
    node* rear=new node();
    rear->next=rear;

    string str;
    getline(cin,str);
	
    istringstream iss(str);

    char ch;
    // 使用字符串流逐个读取整数
    while (iss >> ch) {
        int n=ch-'0';
        node* p = new node(n);
        node* ptr = rear->next;
        rear->next = p;
        rear = rear->next;
        rear->next = ptr;
    }

    int k;
    cin>>k;

for(int x=k;x>=0;x--){
    int i=0;int n;node*p=rear->next->next;
    while(i<x){
        p=p->next;
        i++;
    }n=p->data;

    node*p1=new node(n); 
       node*ptr1=rear->next;
       rear->next=p1;
       rear=rear->next;
       rear->next=ptr1;
}

    node* pp=rear->next->next;
    while(pp!=rear){
        cout<<pp->data;
        pp=pp->next;    
    }
    
    cout<<rear->data;

    return 0;
}*/

#include<iostream>

using namespace std;
int main(){
    char c;
    cin>>c;

    //判断是否为数字，如果是数字那么会返回非0
    if(isdigit(c))
        cout<<"is digit";
    //来判断是否为字母，如果是字母那么返回非0
    else if(isalpha(c))
        cout<<"is char";

    return 0;
}