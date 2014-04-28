/***************************************
***********产生从头到尾的10个数字，并且每次都不重复********
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


#define NUMSIZE 10

int num_flag = 0;
void gen_10random_nums(void)
{
    int k;
    int x=0;
    int y=10;
    int i=0;
    int tmp;
    int buf[NUMSIZE];
    srand(time(NULL));
    for(i=0;i<NUMSIZE;i++)
    {
        while(1)
        {
#if 0//ok with time

            printf("-->>random:%d\n",rand());
            k=(x+rand()%(y-x+1))+(time(NULL));
            tmp=k%10;
#else//not good
            tmp=rand()%10;
#endif
            printf("tmp:%d\n",tmp);
            if(num_flag>>tmp&0x01)
                continue;
            buf[i] = tmp;
            num_flag |= 1<<(tmp);
            break;
        }
        printf("buf[%d]:%d\n",i,buf[i]);

    }
    printf("result:");
    for(i=0;i<NUMSIZE;i++)
    {
        printf("%d",buf[i]);

    }
    printf("\n");
}

int main(void)
{
    gen_10random_nums();
    printf("Hello World!\n");
    return 0;
}

