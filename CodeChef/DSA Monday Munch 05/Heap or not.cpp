string isMinHeap(int A[], int N) {
    // write your code here 
    bool flag=true;
    for(int i=0;i<(N/2);i++)
    if((A[i] > A[(2*i+1)] && (2*i+1)<N) ||( A[i] > A[(2*i+2)] &&(2*i+2)<N)) flag=false;
    return (flag?"Yes":"No");
}
