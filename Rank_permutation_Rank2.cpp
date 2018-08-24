#define mod 1000003
int fact(int n){
    int res=1;
    for(int i=1;i<=n;i++)
        res=((res%mod)*i)%mod;
    return res;
}

int Solution::findRank(string A) {
    unordered_map<char,int> c_ocr;
    int len=A.size();
    for(int i=0;i<len;i++){
        c_ocr[A[i]]+=1;
    }
    //vector<char> keys=c_ocr.enum_keys();
    int res=1;
    for(int i=0;i<len;i++){
        int count=0;
        for(int j=i+1;j<len;j++){
            if(A[i]<A[j])
                count++;
        }
        int temp=fact(len-i-1)%mod;
        int temp1=1;
        for(auto it=c_ocr.begin();it!=c_ocr.end();it++){
            temp1*=fact(it->second);
        }
       // temp1=pow()
        res+=(count*temp/temp1)%mod;
        res=res%mod;
        
        c_ocr[A[i]]-=1;
        //cout<<temp1<<endl;
        
    }
    return res;
    
    cout<<c_ocr[A[0]]<<endl;
        
}
