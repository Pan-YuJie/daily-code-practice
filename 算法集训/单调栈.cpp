#include <iostream>
using namespace std;
const int N = 100010;
int arr[N], i=0;

int main()
{
   int n;
   cin >> n;
   while (n -- )
   {
	 int x;
     cin >>x;
     while(arr[i]>=x && i)
     {
       i--;
     }
     if(!i)
     {
       cout<<-1<<' ';
     }
     else
     {
       cout<< arr[i]<<' ';
     }

     arr[++i]=x;

   }
  
}
