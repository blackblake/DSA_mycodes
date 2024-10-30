#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


void Borrow(int ui,int bi,vector<vector<int>>&users,vector<vector<int>>&books){
    //check the book bi wether it's in the library
    if(books[bi-1][0]==0){
        cout<<"The book is not in the library now"<<endl;
    }else{
        if(users[ui-1][0]==9){
            cout<<"You are not allowed to borrow any more"<<endl;
        }else{
            users[ui-1].push_back(bi);
            users[ui-1][0]+=1;
            books[bi-1][0]=0;
            books[bi-1][1]=ui;
            cout<<"Borrow success"<<endl;
        }
    }

}

void Returnx(int bi,vector<vector<int>>&users,vector<vector<int>>&books){
    if(books[bi-1][0]==1){
        cout<<"The book is already in the library"<<endl;
    }else{
        books[bi-1][0]=1;
        int x=books[bi-1][1];//fetch ui
        users[x-1][0]-=1;
        for(int j=0;j<users[x-1].size();j++){
            if(users[x-1][j]==bi){
                users[x-1][j]=-1;
            }
        }
        cout<<"Return success"<<endl;
    }
}

void Query(int ui,vector<vector<int>>&users,vector<vector<int>>&books){
    if(users[ui-1][0]==0){
        cout<<"Empty"<<endl;
    }else{
        sort(users[ui-1].begin()+1,users[ui-1].end(),less<int>());
        for(int j=1;j<users[ui-1].size();j++){
            if(users[ui-1][j]!=-1){
            	cout<<users[ui-1][j]<<" ";
			}
        }
        cout<<endl;
    }
}



int main(){
    int M;int N;
    while(cin>>M>>N){

    vector<vector<int>>users(M);
    for(int i=0;i<users.size();i++){
    	users[i].push_back(0);
	}
    vector<vector<int>>books(N,vector<int>(2));
    for(int i=0;i<books.size();i++){
    	books[i][0]=1;
	}

    int C;//C instructions
    cin>>C;
    for(int i=0;i<C;i++){
        char ch;
        cin>>ch;
        switch (ch)
        {
        case 'B':
            int x;int y;
            cin>>x>>y;
            Borrow(x,y,users,books);
            break;
        case 'R':
            int z;
            cin>>z;
            Returnx(z,users,books);
            break;
        case 'Q':
            int ui;
            cin>>ui;
            Query(ui,users,books);
            break;
        default:
        	break;
        }
    
    }
    cout<<endl;
}
    return 0;
}