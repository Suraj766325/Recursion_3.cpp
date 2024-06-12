// Q1)  Write a recursive function to reverse a number.
#include<iostream>
using namespace std;
void rev(int n,int sum)
{
    if(n==0)
    {
        cout<<sum;
        return;
    }
    sum=10*sum+n%10;
    rev(n/10,sum);
}
int main()
{
    int n;
    cin>>n;
    rev(n,0);
}




// Q2) Print all the increasing sequences of length k from first n natural numbers.
#include<iostream>
#include<vector>
using namespace std;
void sequence(vector<int>&original,vector<int>ans,vector<vector<int>>&v,int idx,int n,int k)
{
    if(ans.size()==k){
        v.push_back(ans);
        return;
    }
    if(ans.size()+n-idx<k) return;
    sequence(original,ans,v,idx+1,n,k);
    int i=original[idx];
    ans.push_back(i);
    sequence(original,ans,v,idx+1,n,k);
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>original;
    for(int i=1;i<=n;i++)
    original.push_back(i);
    vector<vector<int>>v;
    vector<int>ans;
    //call
    sequence(original,ans,v,0,n,k);
    //print
    for(vector<int>ele:v)
    {
        for(int num:ele)
        cout<<num;
    cout<<endl;
    }
}




// Q3) Given two sorted arrays A and B, generate all possible arrays such that the first element is taken
//    from A then from B then from A, and so on in increasing order till the arrays are exhausted. The
//    generated arrays should end with an element from B.
//    A = {10, 15, 25}
//    B = {1, 5, 20, 30}
//    Output: {10 20}, {10 20 25 30}, {10 30}, {15 20}, {15 20 25 30}, {15 30},{25 30}
