#include <bits/stdc++.h>
using namespace std;

//Sparce Table help you get Maximum,Minimum in given left to right with O(1) time complexity

int query_table(vector <vector <int>> &lookup,int l,int r)
{
    int ele=r-l+1;
    int sz=log2(ele);
    int nx=l+(ele-(1<<sz));
    return max(lookup[l][sz],lookup[nx][sz]);
}
int main()
{ 
    // Scan Length Of Vector
    int m;
    cin  >> m;
    
    //Scan  Values in Vector
    vector <int> v(m);
    for(int i=0;i<m;i++)
	  {
		  cin >> v[i];
	  }
    int width=int(log2(m));
    width++;
    //Create Sparce Table
    vector <vector<int>> lookup(m,vector <int> (width,-1));
    
    //Intialise Sparce Table of size 1;
    for(int i=0;i<m;i++)
    {
        lookup[i][0]=v[i];
    }
    
    //Fill Sparce Table
    int ele=1;
    for(int w=1;w<width;w++)
    {
        ele=ele<<1;
        for(int i=0;i+ele-1<m;i++)
        {
            int nx=i+(ele>>1);
            lookup[i][w]=max(lookup[i][w-1],lookup[nx][w-1]);
        }
    }
    //Scaning 1 index Bases Values
    int l,r;
    cin >> l >> r;
    
    //Get Maximum in Range l to r in O(1) time Complexity
    cout << query_table(lookup,l-1,r-1);
    return 0;
}
