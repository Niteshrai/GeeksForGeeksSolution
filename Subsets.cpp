
Given an array of integers that might contain duplicates, return all possible subsets.

Note Output:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        The subsets must be sorted lexicographically.

Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

Input:
First is T , no of test cases. 1<=T<=500
Every test case has two lines.
First line is N, size of array. 1<=N<=12
Second line contains N space seperated integers(x). 1<=x<=9.

Output:
One line per test case, every subset enclosed in () and in every set intergers should be space seperated.(See example)

Example:
Input:
2
3
1 2 2
4
1 2 3 3

Output:
()(1)(1 2)(1 2 2)(2)(2 2)
()(1)(1 2)(1 2 3)(1 2 3 3)(1 3)(1 3 3)(2)(2 3)(2 3 3)(3)(3 3)

 
 
 
 

//--------------------------------_Solution------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;



int main() {
	int test;
	cin>>test;
	while(test--){
	    int n,arr[15];
	    cin>>n;
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	   sort(arr,arr+n);
	   int pow_set=0;
	   unordered_map<string,int> hash;
	   vector<string> subsets;
	   while(pow_set<(1<<n)){
	       int index=0;
	       int m=1<<index;
	       vector<char> numbers;
	       while(m<=pow_set){
	           if((m&pow_set)==m){
	               char numb=arr[index]+'0';
	               numbers.push_back(numb);
	           }
	           index++;
	           m=1<<index;
	           
	           
	       }
	       int i=0;
	       string res="";
	       if(numbers.size()>0){
	       for( i=0;i<numbers.size()-1;i++)
	           res=res+numbers[i]+" ";
	           res=res+numbers[i];
	       
	       }
	       if(hash[res]==0){
	           hash[res]=1;
	           subsets.push_back(res);
	       }
	       
	       pow_set+=1;
	   }
	   sort(subsets.begin(),subsets.end());
	   for(int i=0;i<subsets.size();i++)
	        cout<<"("<<subsets[i]<<")";
	   cout<<endl;
	   
	}
	return 0;
}
