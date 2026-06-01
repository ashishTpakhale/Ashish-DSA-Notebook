string solve(int N, int X, const vector<int>& A) {
    bool flag =false;
    string str;
    for(int i=0;i<N;i++){
        if(A[i]==X){
            flag=true;
            break;
        }
    }
    str=(flag?"Yes":"No");
    return str;
}

