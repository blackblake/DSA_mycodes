#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    int row;
    int col;
    Node* next;
    Node(){
    	data=0;row=0;col=0;
        next=nullptr;
    }
    Node(int val,int m,int n){
        data=val;
        row=m;
        col=n;
        next=nullptr;
    }
};


int main(){
    ifstream infile("in.txt");
	int m1;
    int n1;
    infile>>m1>>n1;

    Node* head1=new Node();//R表头结点
    Node* tail1=head1;
    for(int i=1;i<=m1;i++){
        for(int j=1;j<=n1;j++){
            int val;infile>>val;
            Node* no=new Node(val,i,j);
            tail1->next=no;
            tail1=no;
        }
    }

/*测试代码
Node* temp=head1->next;
for(int i=1;i<=m1;i++){
        for(int j=1;j<=n1;j++){
            outfile<<temp->data<<" "<<temp->row<<" "<<temp->col<<endl;
            temp=temp->next;
        }
    }
*/
    int m2;
    int n2;
    infile>>m2>>n2;

    Node* head2=new Node();//R表头结点
    Node* tail2=head2;
    for(int i=1;i<=m2;i++){
        for(int j=1;j<=n2;j++){
            int val;infile>>val;
            Node* no=new Node(val,i,j);
            tail2->next=no;
            tail2=no;
        }
    }

    int x;int y;
    infile>>x>>y;
    infile.close();
    
    ofstream outfile("abc.out");
	Node* temp1=head1->next;
	while(temp1!=nullptr)
    {//遍历R的第i行（共遍历m1行）
        //在单行遍历中，找到该行col为x的结点，保存其data为t1；
        
        while (temp1&&temp1->col!=x)
        {
            temp1=temp1->next;
        }
        if(temp1){
        	int t1=temp1->data;	
		
        
		Node* temp2=head2->next;
        while(temp2!=nullptr)
        {//然后遍历S表的第j行（共m2行），在单行遍历中，找到该行col为y的结点，保存其val为t2；
                
            while (temp2&&temp2->col!=y)
            {
                temp2=temp2->next;
            }
        	if(temp2){
        		int t2=temp2->data;
			
			
            //如果t1>t2，那么连接当前R表的第i行和S表的第j行
            if(t1>t2){
                Node* tail1=head1->next;
                int num1=temp1->row;
                while(tail1&&tail1->row!=num1){
                	tail1=tail1->next;
				}
                while (tail1&&tail1->row==num1)
                {
                    outfile<<tail1->data<<" ";
                    tail1=tail1->next;
                }
                
                Node* tail2=head2->next;
                int num2=temp2->row;
                while(tail2&&tail2->row!=num2){
                	tail2=tail2->next;
				}
                while (tail2&&tail2->row==num2)
                {
                    outfile<<tail2->data<<" ";
                    tail2=tail2->next;
                }
                outfile<<endl;
            }
            temp2=temp2->next;
			}
        }
        temp1=temp1->next;
    }
	}
    outfile.close();

    return 0;
}