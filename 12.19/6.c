#include <stdio.h>
int calcultar_add(int a,int b)
{
    return a + b;
}
int calcultar_minus(int a,int b)
{
    return a - b;
}
int calcultar_mutiply(int a,int b)
{
    return a * b;
}
int calcultar_divide(int a,int b)
{
    return a / b;
}
int calcultar_mode(int a,int b)
{
    return a % b;
}
typedef struct cal
{
    char aa;
    int (* handle)(int ,int );
}cal_t;
//*****************pay atention to the how to use struct
cal_t arry[] = { {'+',calcultar_add},{'-',calcultar_minus},{'*',calcultar_mutiply},{'/',calcultar_divide},{'%',calcultar_mode} };
//************************************************
int main(int argc, const char *argv[])
{
    char ss;
    int k = 0,j = 0,i = 0;
    int result = 0;
    while(1)
    {
        scanf("%c",&ss);
        if(ss == '#') break;
        scanf("%d %d",&j,&k);
        for (i = 0; i < 5; i++) 
        {
            if (arry[i].aa == ss) 
            {
                result = arry[i].handle(j,k);//notice the "handle"
            }
        }
        //getchar();//notice next puts
        printf("%d %c %d = %d\n",j,ss,k,result); 
    }
    return 0;
}
