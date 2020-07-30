#include "OJ.h"

#include <bits/stdc++.h>
using namespace std;

void naive(vector<Point> &points)
{
    int n = (int) points.size()/2;
    do{
        oj.set_match(points);
        display();
    } while ( update(n,points) );
}

void DC(vector<Point> &points){
    
    if(points.size()<=4)
    {
         naive(points);
         return;
    }
    
        vector<Point> sub1, sub2;
        partition(points,sub1,sub2);
        //oj.set_match(sub1);
        //oj.set_match(sub2);
        oj.set_match(points[0].id,points[1].id);
        display();
        DC(sub1);
        DC(sub2);
    
    // D&C ...
}
