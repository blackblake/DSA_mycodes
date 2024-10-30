#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(){
        next=nullptr;
    }
    Node(int val){
        data=val;
        next=nullptr;
    }
};

int countsize(Node* s){
	Node*p=s;
	int cnt=0;
	while(p!=nullptr){
		p=p->next;
		cnt++;
	}
	return cnt;
}

int main(){
    int N;
    cin>>N;

    
    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        Node* head=new Node(1);
        Node* rear=head;

        for(int j=2;j<=n;j++){//create list
            Node*p=new Node(j);
            rear->next=p;
            rear=rear->next;
        }
        
        
        int cnt=1;
        

		while (countsize(head)>3)//not less than 3
        {
            if(cnt%2==0){//even number--3
                Node* p1=head->next;
                Node* p2=head->next;
                while (p1->next)
                {
                    p2=p1->next->next;
                    p1->next=p2;
                    if(p2){
                        p1=p2;
                        if(p2->next){
                            p2=p2->next;
                            p1=p2;
                        }else{
                        	break;
						}
                    }else{
						break;
					}
                }
                
            }
            else if(cnt%2==1){//odd number--2
                Node* p1=head;
                Node* p2=head;
                while (p1)
                {
                    if(p1->next){
                        p2=p1->next->next;
                        p1->next=p2;
                        p1=p2;  
                    }else{
                    	break;
					}
                }
            }
            cnt++;
        }

        Node* ptr=head;
        while (ptr->next!=nullptr)//print list
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<ptr->data;
    }

    return 0;
}