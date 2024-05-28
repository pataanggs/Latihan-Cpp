#include <iostream>
using namespace std;


void tampilan(){
    cout<<"PROGRAM KALKULATOR"<<endl;
}

void pilihan(){
    cout<<"======================"<<endl;
    cout<<"1.faktorial"<<endl;
    cout<<"2.";
}


int faktorial(int a){
    if(a==1){
        return 1;
    }else {
        return a *faktorial(a-1);
    }
}



int main(){
    tampilan();
    pilihan();
    cout<<endl;
    int pilihan;
    int angka;
    cout<<"masukkan pilihan ";
    cin>>pilihan;

    switch (pilihan)
    {
    case 1:
        cout<<"masukkan angka ";
        cin>>angka;
        cout<<"nilai dari "<<angka<<" faktorial adalah "<<faktorial(angka);
        break;
    
    default:
        break;
    }

    


    return 0;
}