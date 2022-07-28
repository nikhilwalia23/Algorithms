#include <bits/stdc++.h>
using namespace std;
#define ll long long
//Segment Tree perform update and calulate operation on given range left to right in O(log n);

class Segment_tree
{
    //Segment Tree for sum;
    vector <ll> seg;
    vector <ll> v;
    public: Segment_tree(vector <ll> &arr)
    {
        v=arr;
        int n=arr.size();
        int sz=4*n;
        seg.assign(sz,-1);
        build_segment(0,arr.size()-1,0);
    }
    ll build_segment(int currl,int currr,int ind)
    {
        if(currl==currr)
        {
            return seg[ind]=v[currl];
        }
        else
        {
            int mid=(currl+currr)/2;
            return seg[ind]=build_segment(currl,mid,(2*ind)+1)+build_segment(mid+1,currr,(2*ind)+2);
        }
    }
	//here reql = left 0 based index of range 
	//reqr = right 0 based index of range
    ll query_segment(int currl,int currr,int reql,int reqr,int ind)
    {
        //Completely Inside
        if(currl>=reql && currr<=reqr)
        {
            return seg[ind];
        }
        //Completely Outside
        if(currl>reqr || currr<reql)
        {
            return 0;
        }
        //Completely equel
        if(currl==reql && currr==reqr)
        {
            return seg[ind];
        }
        int mid=(currl+currr)/2;
        return query_segment(currl,mid,reql,reqr,(2*ind)+1)+query_segment(mid+1,currr,reql,reqr,(2*ind)+2);
    }
	//here index = value of index of array to updated
	//val = new value at given index
    void update_segment(int currl,int currr,int index,int val,int ind)
    {
        if(currl==currr)
        {
            seg[ind]=val;
        }
        else
        {
            int mid=(currl+currr)/2;
            if(index<=mid)
            {
                update_segment(currl,mid,index,val,(2*ind)+1);
            }
            else
            {
                update_segment(mid+1,currr,index,val,(2*ind)+2);
            }
            seg[ind] = seg[(2*ind)+1]+seg[(2*ind)+2];
        }
    }
};
int main()
{
	int n;
	cin >> n;
	vector <ll> v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	Segment_tree sg(v);
	int l,r;
	cin >> l >> r;
	l--;
	r--;
	cout << sg.query_segment(0,n-1,l,r,0);
	return 0;
}
