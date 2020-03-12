

#include <iostream>
using namespace std;

int main()
{
    int num[ 5 ];

    *num = 100;
    *(&num[0+1]) = 90;
    *(&num[2]) = 80;
    *(&num[0+3]) = 70;
    *(&num[0+4]) = 60;
    
    for (int i = 0; i < 5; i++)
        cout << num[ i ] << " ";
    cout << endl;

    return( 0 );
}
