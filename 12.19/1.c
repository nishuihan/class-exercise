// This file tell me the function index
// the function index need three steps
// first defintion,second assinment ,three calling
#include <stdio.h>
int add(int a,int b)
{
    return a + b;
}
int main(int argc, const char *argv[])
{
    int (* p)(int ,int);// please pay attention to the function index defintion
    int c=0;
    p=add;
    c= (*p)(2,5);//please notice the call of function index 
    printf("c =%d\n",c);
    return 0;
}
