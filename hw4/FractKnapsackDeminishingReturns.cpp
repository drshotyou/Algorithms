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
    
    /*
     * The following code solves the linear program
     * 
     * minimize    7 y1 + 11 y2 + 13 y3
     * subject to  y1 - y3 <= 1
     *             2 y1 + y2 + 3 y3 <= 2
     *
     *
     * i.e. return min{c^T y : Ay <= b}
     */
    int n,W,V;
    cin >> n >> W >> V;
    vector<double> w,v,p;
    w.resize(n);
    v.resize(n);
    p.resize(n);
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        w[i]=temp;
    }
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        v[i]=temp;
    }
    //cout << endl;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        p[i]=temp;
        //cout << p[i] << " ";
    }


    vector<vector<double> > A;
    A.resize(4*n+2);
    for(int i=0; i<4*n+2; ++i){
        A[i].resize(2*n);
    }	
    int k=0,l=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2*n;j+=2)
        {
            //A[i][j]=w[i]+w[i]*0.8;
            if(i==0)
            {
                
                    A[i][j]=w[j/2];
                    A[i][j+1]=w[j/2];
                
                
            }
            else if(i==1)
            {
                
                    A[i][j]=v[j/2];
                    A[i][j+1]=v[j/2];
                
            }
            /*else if(i>1 && i<=n)
            {
                if(i-2==k)
                {
                    A[i][j]=1;
                    
                }
                else
                {
                    A[i][j]=0;
                }
            }
            else if(i>n)
            {
                if(j==l)
                {
                    A[i][j]=-1;
                    
                }
                else{
                    A[i][j]=0;
                }
                
            }*/
        }
        /*if(i>1)
        {
            k++;
        }
        if(i>=n)
        {
            l++;
        }*/
    }
    //cout << endl;
    //cout << endl;
    for(int i=2;i<4*n+2;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            if(i<2*n+2)
            {
                if(j==k)
                {
                    A[i][j]=1;
                }
                else
                {
                    A[i][j]=0;
                }
            }
            else if(i>=2*n+2)
            {
                if(j==l)
                {
                    A[i][j]=-1;
                }
                else
                {
                    A[i][j]=0;
                }
            }
        }
        k++;
        if(i>=2*n+2)
        {
            l++;
        }
    }
    //cout << endl;
    //cout << endl;
    /*for(int i=0;i<4*n+2;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }*/
    //cout << endl;

    
    vector<double> y;
    y.resize(2*n);
    
    vector<double> b;
    b.resize(4*n+2);

    for(int i=0;i<4*n+2;i++)
    {
        if(i==0)
        {
            b[i]=W;
        }
        else if(i==1)
        {
            b[i]=V;
        }
        else if(i>1 && i<2*n+2)
        {
            b[i]=1;
        }
        else if(i>=2*n+2)
        {
            b[i]=0;
        }
    }
    /*for(int i=0;i<4*n+2;i++)
    {
        cout << b[i] << " ";
    }*/
    
    vector<double> c;
    c.resize(2*n);
    for(int i=0;i<2*n;++i)
    {
        if(i%2==1)
        {
            c[i]=1*p[i/2];
        }
        else if(i%2==0)
        {
            c[i]=0.80*p[i/2];
        }
        /*else
        {
            c[i]=1;
        }*/
        
    }
    //cout << endl;

    double z = lp_solver(GLP_MAX, c, A, y, b);
    
    cout << z << endl;
    //cout << "the optimal objective value is " << z << endl;
    //cout << "the optimal solution is (";	
    for(int i=0; i<2*n; i+=2){
        cout << y[i]+y[i+1] << " ";
    }
    //cout << ")" << endl;
    return 0;
}
