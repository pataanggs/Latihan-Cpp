#include <iostream>
#include <stack>
using namespace std;

void displayStack(stack<int> s)
{
 int n = s.size();

  for(int i=0; i<n;i++)
 {
  cout<<s.top()<<" ";
  s.pop();
 }
 cout<<"\n";

 }

int main()
{
  stack<int> s;

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  cout<<"Isi elemen stack : ";
  displayStack(s);

  s.pop();

   cout<<"Stack setelah operasi pop : ";
  displayStack(s);

  cout<<"Element paling atas : "<<s.top()<<"\n";
    
  cout<<"Stack is empty (1 - YES / 0 - NO) : "<<s.empty()<<"\n";

  cout<<"Ukuran dari stack : "<<s.size()<<"\n";

   return 0;
}