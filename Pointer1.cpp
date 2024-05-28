#include <iostream>
#include <string>
using namespace std;

int main(){
    
    string ngek;
    int count=0;
    
    cin>>ngek;
    
    for(int i=0;i<ngek.length();i++){
        
        if(ngek[i]=='B'){
            continue;
        }
        if(i%2==0){
            if(ngek[i]=='O'){
                count++;
            }
        }else{
            if(ngek[i]=='~'){
                count++;
            }
        }
    }
    
    cout<<count/2<<" domba tersesat.";
    
    return 0;
}