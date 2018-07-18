
Given a 2D array, find the maximum sum subarray in it. For example, in the following 2D array, the maximum sum subarray is highlighted with blue rectangle and sum of this subarray is 29.

                                                       

Input:
First line of every test case consists of T test case. First line of every test case consists of 2 integers R and C , denoting number of rows and columns. Second line consists of R*C spaced integers denoting number of elements in array.

Output:
Single line output, print the Max sum forming a rectangle in a 2-D matrix

Example:
Input:
1
4 5
1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6
Ouptut:
29





//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int kadane_max(int mat[],int n){
    int i,max_end=0,maximum_sa=0;
    for(i=0;i<n;i++){
        max_end+=mat[i];
        max_end=max(max_end,0);
        maximum_sa=max(max_end,maximum_sa);
    }
    return maximum_sa;
}

int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    int r,c,maximum=0,i,j,L,R;
	    cin>>r>>c;
	    int mat[r][c];
	    for(i=0;i<r;i++){
	        for(j=0;j<c;j++)
	        cin>>mat[i][j];
	    }
	    
	    //------------
	    int arr[r],rslt=0;
	    for (L=0;L<c;++L){
	        memset(arr,0,sizeof(arr));
	        for(R=L;R<c;++R){
	            for(i=0;i<r;++i){
	                arr[i]+=mat[i][R];
	            }
	            maximum=kadane_max(arr,r);
	            
	            rslt=max(rslt,maximum);
	        }
	    }
	   cout<<rslt<<endl;
	    
	    
	    
	}
	return 0;
}
