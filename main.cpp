#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "masukan n :";
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cout<<" ";
        }
        for(int j = 1;j<=i;j++){
            cout<<"* ";
        }
        
        cout<<endl;
    }
    
    for(int i = n;i>=0;i--){
        for(int j=i;j<=n;j++){
            cout<<" ";
        }
        for(int j = 1;j<=i;j++){
            cout<<"* ";
        }
        
        cout<<endl;
    }
    
    return 0;
}