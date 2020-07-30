#include "OJ.h"
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
bool update(int n,vector<Point> &points);

void naive(vector<Point> &points)
{
    int n = (int) points.size()/2;
    do{
        oj.set_match(points);
        display();
    } while ( update(n,points) );
}

void DC(vector<Point> &points){
    if(points.size()<=2000)
    {
         naive(points);
         return;
    }
        vector<Point> sub1, sub2;
        partition(points,sub1,sub2);
        oj.set_match(points[0].id,points[1].id);
        display();
        DC(sub1);
        DC(sub2);
}
/*
void partition(vector<Point>&points,vector<Point>&a,vector<Point>&b)
{
    int n = (int)points.size()/2;
    vector<int> leftR,leftB,rightR,rightB;
    Point A,B,P;
    int lR=0,lB=0,rR=0,rB=0;
    for(int i=0;i<n;i++)
    {
        A=point[i];
        B=point[n+i];
        for(int j=0;j<n;j++)
        {
            Point a,b;
            a={points[j].x,points[j].y};
            b={points[n+j].x,points[n+j].y};
            long long sideA = ((a.x-A.x)*(B.y-A.y))
                                -((B.x-A.x)*(a.x-A.y));
            long long  sideB = ((b.x-A.x)*(B.y-A.y))
                               -((B.x-A.x)*(b.y-A.y));

            if(sideA<0)
            {
                lR++;
                leftR.push_back(j);
            }
            else if(sideA>0)
            {
                rR++;
                rightR.push_back(j);
            }
            else if(sideB<0)
            {
                lB++;
                leftB.push_back(j);
            }
            else if(sideB>0)
            {
                rB++;
                rightB.push_back(j);
            }
            if((lB==lR)&&(rR==rB))
            {
                for(int j=0;j<lR;j++)
                {
                    a.push_back(points[rightR[j]]);
                    b.push_back(points[leftR[j]]);
                }
                for(int j=0;j<rR;j++)
                {
                    a.push_back(points[rightB[j]]);
                    b.push_back(points[leftB[j]]);
                }
                points.clear();
                points.push_back(A);
                points.push_back(B);
                return;
            }

        }

    }
}
*/
bool update (int n, vector<Point> &points)
{   
    vector<Line> linesInSet(n);
    bool intersects=false;
    for(int i=0;i<n;i++)
    {
        linesInSet[i]={points[i],points[n+i]-points[i]};
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(intersection(linesInSet[i],linesInSet[j]))
            {
                Point temp;
                temp=points[n+i];
                points[n+i]=points[n+j];
                points[n+j]=temp;
                linesInSet[i]={points[i],points[n+i]-points[i]};
                linesInSet[j]={points[j],points[n+j]-points[j]};
                intersects=true;
            }
        }
    }
    return intersects;
}
