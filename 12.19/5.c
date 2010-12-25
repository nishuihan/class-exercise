#include <stdio.h>
typedef int (* fun_t)(int ,int );
int cat_add(int a,int b)
{
    return a + b
}
int cat_minus(int a,int b)//minus
{
    return a - b;
}
int cat_multply(int a,int b)//mutiply
{
    return a * b;
}
int cat_dev(int a,int b)//divide
{
    return a / b;
}
int main(int argc, const char *argv[])
{
    fun_t p;
    //int (* fun_t)(int ,int );
    int c;
    int i=0,j=0;
    char  ss;
    scanf("%c",&ss);
    printf("%c\n",ss);
    while(ss!='#')
    {
        switch(ss)
        {
            case '+':
                scanf("%d %d",&i,&j);
                //scanf("%d",&i);
                //scanf("%d",&j);
                printf("%d,%d\n",i,j);
                p=cat_add;
                c=(* p)(i,j); 
                printf("%d %c %d = %d\n",i,ss,j,c);
                break;
            case '-':
                scanf("%d %d",&i,&j);
                printf("%d,%d\n",i,j);
                p=cat_minus;
                c=(* p)(i,j); 
                printf("%d %c %d = %d\n",i,ss,j,c);
                break;
            case '*':
                scanf("%d %d",&i,&j);
                printf("%d,%d\n",i,j);
                p=cat_multply;
                c=(* p)(i,j); 
                printf("%d %c %d = %d\n",i,ss,j,c);
                break;
            case '/':
                scanf("%d %d",&i,&j);
                printf("%d,%d\n",i,j);
                p=cat_dev;
                c=(* p)(i,j); 
                printf("%d %c %d = %d\n",i,ss,j,c);
                break;
                //default : printf("again\n");
        }
        scanf("%c",&ss);
    }
    return 0;
}
