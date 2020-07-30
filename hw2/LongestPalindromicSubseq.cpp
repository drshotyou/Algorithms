#include <iostream>
#include <string>
#include <algorithm>
int sols[4000][4000];
using namespace std;

string reorder(string s3)
{
	string newS3 = s3;
	for(int j=0;j<newS3.length()/2;j++)
	{
		char temp = newS3[j];
		newS3[j]=newS3[newS3.length()-j-1];
		newS3[newS3.length()-j-1]=temp;
	}
	return newS3;
}

int lcs(string s2, string s1 ,int l2, int l1)
{
	
	
	for(int i=0;i<l1+1;i++)
	{
		for(int j=0;j<l2+1;j++)
		{
			
			if(i==0 || j==0)
			{
				sols[i][j]=0;
			}
			else if(s1[i-1]==s2[j-1])
			{
				sols[i][j] = 2 + sols[i-1][j-1];
			}
			else
			{
				sols[i][j] =max(sols[i-1][j],sols[i][j-1]);
			}
		}		
	}
	return (sols[l1][l2])+1;
	
}

 

int main () 
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	
	int results[10000]={1};
	//results[0]=1;
	string input;
	cin >> 	input;
	//cout << input << endl;
	string firstHalf,secondHalf;
	for(int i=1;i<input.length();i++)
	{
		//divide input string
		firstHalf=input.substr(0,i);
		secondHalf=input.substr(i+1);
		//reorder it so comparing becomes easier
		secondHalf=reorder(secondHalf);
		//save result for this comparison
		int sizeOne=firstHalf.size();
		int sizeTwo=secondHalf.size();
		long long total =  lcs(firstHalf,secondHalf,sizeOne,sizeTwo);
		results[i]=total;
	}
	//print results
	for(int i=0;i<input.length();i++)
	{
		cout << results[i] << " ";
	}
	
	return 0;
}
