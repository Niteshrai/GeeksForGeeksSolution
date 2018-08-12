

/*
Given a boolean 2D matrix (0-based index), find whether there is path from (0,0) to (x,y) and if there is one path, print the minimum no of steps needed to reach it, else print -1 if the destination is not reachable. You may move in only four direction ie up, down, left and right. The path can only be created out of a cell if its value is 1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines . The first line of each test case contains two integers n and m denoting the size of the matrix. Then in the next line are n*m space separated values of the matrix. The following line after it contains two integers x and y denoting the index of the destination.

Output:
For each test case print in a new line the min no of steps needed to reach the destination.

Constraints:
1<=T<=100
1<=n,m<=20

Example:
Input:
2
3 4
1 0 0 0 1 1 0 1 0 1 1 1
2 3
3 4
1 1 1 1 0 0 0 1 0 0 0 1
0 3
Output:
5
3


*/
//------------------------Solution Using BFS---------------------------------
//BFS give optimal solution always .

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int m,n;
struct Node{
    int x,y,dist;
};
bool isValidStep(vector<vector<int>> A, vector<vector<bool>> visited,int row,int col){
    
    return (row>=0)&&(col>=0)&&(row<m)&&(col<n)&&!visited[row][col]&&A[row][col];
}

int bfs(vector<vector<int>> A ,int i,int j,int x,int y){
    //---------Visted Array initaliztion-------
    vector<vector<bool>> visited(m);
    for(int i=0;i<m;i++){
	        visited[i]=vector<bool> (n);
	        for(int j=0;j<n;j++)
	            visited[i][j]=false;}
    
    //------------------------------------------
    if(A[i][j]==0)
        return -1;
    queue<Node> q;
    
    visited[i][j]=true;
    q.push({i,j,0});
    int min_dist=INT_MAX;
    while(!q.empty()){
        Node nodePt=q.front();
        q.pop();
        int currX=nodePt.x;
        int currY=nodePt.y;
        int dist=nodePt.dist;
        
        if(currX==x && currY==y){
            //min_dist=dist;
            return dist;
            break;
        }
        //check up down right left 
        if(isValidStep(A,visited,currX+1,currY)){
            q.push({currX+1,currY,dist+1});
            visited[currX+1][currY]=true;
        }
        if(isValidStep(A,visited,currX-1,currY)){
            q.push({currX-1,currY,dist+1});
            visited[currX-1][currY]=true;
        }
        if(isValidStep(A,visited,currX,currY+1)){
            q.push({currX,currY+1,dist+1});
            visited[currX][currY+1]=true;
        }
        if(isValidStep(A,visited,currX,currY-1)){
            q.push({currX,currY-1,dist+1});
            visited[currX][currY-1]=true;
        }
        //-----------
        
    }
    
    return -1;
    
    
    
}


int main() {
	int testCase;
	cin>>testCase;
	while(testCase--){
	    int x,y;
	    //--------input-----------
	    cin>>m>>n;
	    vector<vector<int>> mat(m);
	    for(int i=0;i<m;i++){
	        mat[i]=vector<int> (n);
	        for(int j=0;j<n;j++)
	            cin>>mat[i][j];
	            
	    }
	    cin>>x>>y;
	    //------input----------------
	    //-------funtioncall---------
	    cout<< bfs(mat,0,0,x,y)<<endl;
	    
	    /*/-------output--------------
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++)
	            cout<<mat[i][j]<<" ";
	            cout<<endl;
	    }
	    cout<<endl;
	    //-----------------------------*/
	}
	
	return 0;
}
