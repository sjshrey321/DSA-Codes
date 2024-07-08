int fib2(int n, int *arr)
{
    if ( n==0 || n==1){ return 0;}
    else{
        if ( arr[n] != 0){
            return arr[n];
        }
        else{
            int out= fib2(n-1,arr) + fib2(n-2,arr);
            arr[n]= out ; 
            return out; }
    }
}

int fib3(int n)
{
    int *arr= new int[n]; 
    if ( n ==0 or n==1 ){
        arr[n]=n; 
    }
    else {
        for (int i=2; i<= n; i++)
        {
            arr[i] = arr[n-1] + arr[n-2] ; 

        }
    }
    int out = arr[n]; 
    delete []arr ;
    return out; 
}