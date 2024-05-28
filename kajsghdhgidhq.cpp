/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int misteri(int n){
    if(n>100){
        return n-10;
    }else{
        return misteri(misteri(n+11));
    }
}

int main()
{
    cout<<misteri(50);
    

    return 0;
}
