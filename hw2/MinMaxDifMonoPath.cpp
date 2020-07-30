#include <iostream>
#include <cstdlib>
#include <climits>
#include <algorithm>

using namespace std;
long long minVal=0;
long long minMax(int y,int x,int n);
long long arr[1001][1001];
long long sol[1001][1001];
int main()
{
    int n;
    cin.sync_with_stdio(false);
	cin.tie(NULL);
    
    cin >> n;
    //read input
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> arr[i][j];
        }
    }
    //solo para confirmar arrays
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/
    
    //initialize el sol array
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sol[i][j]=-1;
        }
    }
    long long ans = minMax(n-1,n-1,n);
    cout << ans << endl;
    
    return 0;
}
//ignora que le mando n, eso era otro approach
long long minMax(int y,int x,int n)
{
	//yo empiezo de n,n hasta 0,0
	//if filled, return ese ans
    if(sol[y][x]!=-1)
    {
        return sol[y][x];
    }
    
    long long count1;
	long long count2;
    long long countLeft=LLONG_MAX;
    long long countDown=LLONG_MAX;
   	//if at first slot 0,0 return 0 o va a accesar negative indexes
    if(x == 0 && y == 0)
    {
        sol[y][x]=0;
         
        return sol[y][x];
    }
    
    if(y-1>=0)
    {
    	//traverses down
    	count2 = abs(arr[y][x] - arr[y-1][x]);
        countDown=max(count2,minMax(y-1,x,n));
         
    }
    if(x-1>=0)
    {
    	//traverses left
    	count1 = abs(arr[y][x] - arr[y][x-1]);
        countLeft=max(count1,minMax(y,x-1,n));
        
    }
    return sol[y][x]=(countDown<countLeft)?countDown:countLeft;
}

/*if(sol[x][y]<minVal)
         {
            minVal=sol[x][y];
         }*/
         //return sol[x][y] = count;
