#include <iostream>
using namespace std;

int r,c,m;
int b[10][10];
int x[10][10];
int k[10];
int i,j;

void flip()
{
    for( i=0 ; i<r ; i++ )
    {
        for( j=0 ; j<c ; j++ )
        {
            x[r-i-1][j] = b[i][j];
        }
    }
    for( i=0 ; i<r ; i++ )
    {
        for( j=0 ; j<c ; j++ )
        {
            b[i][j] = x[i][j];
        }
    }
}

void turn_left_90()
{
    int tmp;
    for( i=0 ; i<r ; i++ )
    {
        for( j=0 ; j<c ; j++ )
        {
            x[c-j-1][i] = b[i][j];
        }
    }
    tmp = r;
    r = c;
    c = tmp;
    for( i=0 ; i<r ; i++ )
    {
        for( j=0 ; j<c ; j++ )
        {
            b[i][j] = x[i][j];
        }
    }
}

int main()
{
    int first_print = 0;
    while(cin>>r>>c>>m)
    {
        for( i=0 ; i<r ; i++ )
        {
            for( j=0 ; j<c ; j++ )
            {
                cin>>b[i][j];
            }
        }
        for( i=0 ; i<m ; i++ )
        {
            cin>>k[i];
        }
        for( int g=m-1 ; g>=0 ; g-- )
        {
            if(k[g]==1)
            {
                flip();
            }
            else
            {
                turn_left_90();
            }
        }
        cout<<r<<" "<<c<<endl;
        for( i=0 ; i<r ; i++ )
        {
            first_print = 0;
            for( j=0 ; j<c ; j++ )
            {
                if(first_print == 0)
                {
                    first_print = 1;
                }
                else
                {
                    cout<<" ";
                }
                cout<<b[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
