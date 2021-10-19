#include<iostream>
#include<math.h>
using namespace std;
int main ()
{ int n;
 cout<<"nhap so n: ";cin>>n;
 for (int i=1;i<=n;i++)
 if (sqrt(i)==int (sqrt(i)))
 cout<<i<<" ";
 cout<<endl;
 return 0;
}
