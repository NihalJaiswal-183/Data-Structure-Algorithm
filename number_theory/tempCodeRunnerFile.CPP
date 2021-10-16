int exp(int a,int b,int c){
    if(b==0){
        return 1;

    }
    if(b%2==0){
    int temp=exp(a,b/2,c);
    return (temp%c*temp%c)%c;

    }
    else{
     int temp=exp(a,b/2,c);
     return (a%c*temp%c)%c;
    }
   
}