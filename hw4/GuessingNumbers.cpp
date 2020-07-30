#include <iostream>
#include <vector>
#include "lp_solver.h"
using namespace std;

/*
** optimize z = c^T y  (optimize: GLP_MIN or GLP_MAX)
** subject to Ay <= b
** 
** return z
*/

//double lp_solver(int optimize, const vector<double>& c, const vector<vector<double> >& A, vector<double> &y, const vector<double> &b);

int main(){
    
    
    int n,k;
    cin >> n >> k;
    vector<vector<double> > A;
    A.resize(2*n+k);

    for(int i=0;i<2*n+k;i++)
    {
        A[i].resize(n,0);
    }
    /*for(int i=0;i<2*n+k;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j]=0;
        }
    }*/
    
    vector<double> b;
    b.resize(2*n+k);
    for(int i=0; i<k; i++)
    {
        
                char temp;
                cin >> temp;
                A[i][temp-97]=1;
                int temp2;
                cin >> temp2;
                b[i]=-temp2;
                cin >> temp;
                A[i][temp-97]=-1;
    
    }	
    int p=0,l=0;
    for(int i=k;i<2*n+k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<=n+k)
            {
                if(j==p)
                {
                    A[i][j]=1;
                }   
                b[i]=26;
            }
            else if(i>n+k) 
            {
                if(j==l)
                {
                    A[i][j]=-1;
                }
                b[i]=-1;
            }
        }
        p++;
        if(i>n+k)
        {
            l++;
        }
    }
    /*for(int i=0;i<2*n+k;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }*/

    

    
    vector<double> y;
    y.resize(n);
    
    
    
    vector<double> c;
    c.resize(n);
    for(int i=0;i<n;i++)
    {
        c[i]=1;
    }

    
    double z = lp_solver(GLP_MAX, c, A, y, b);
    
    //cout << "the optimal objective value is " << z << endl;
    //cout << "the optimal solution is (";	
    for(int i=0; i<n; ++i){
        cout << y[i] <<" ";
    }
    //cout << ")" << endl;
    return 0;
}
