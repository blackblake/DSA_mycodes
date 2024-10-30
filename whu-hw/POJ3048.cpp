#include <iostream>
#include <fstream>
using namespace std;



int main(){

    int num;

    int result=0;
    int maxPrime=0;

    while (cin>>num)
    {
        for(int i=1;i<=num;i++){
            if (num%i==0){
                bool is=true;

                for(int j=2;j<i;j++){
                    if(i%j==0){
                        is=false;
                    }
                }

            if(is==true&&i>maxPrime){
                    maxPrime=i;
                    result=num;
            }   
                
            }
        }        
    }
    cout<<result;

    return 0;
}
