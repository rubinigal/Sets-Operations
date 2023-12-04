#include "set.h"

void read_set(set *p1,int num)
{
    /*setting the proper bit to 1*/
    (*p1)[num/BIT] = (*p1)[num/BIT] | (1 << (BIT-1-(num%BIT)));
    
}

char* print_set(set *p1)
{
    int i,j,counter=0,num; /*counter is cause we were asked to put up to 16 number per line*/
    char number[CMD_SIZE];
    char* s = (char*)malloc(CMD_SIZE*sizeof(char));
    memset(s, '\0', CMD_SIZE);
    
    for ( i = 0; i < (BIT*2); i++)
    {
        for ( j = 0; j < BIT; j++)
        {
            if ((*p1)[i] & (1 << (BIT-1-j))) /*i check if the bit number is 1 and then i change the number to string and then use realloc to maximaze the space*/
            {
                num = (i * 8) + j;
                sprintf(number, "%d,", num);
                s = (char*)realloc(s, strlen(s)+strlen(number)+1);
                strcat(s, number);
                counter++;
                if (counter == (BIT*2))
                {
                    s = (char*)realloc(s, strlen(s)+2);
                    strcat(s, "\n");
                    counter = 0;
                }
                
            }
            
        }
        
    }
    
    s[strlen(s) - 1]='\0'; /*remove last ','*/
    return s;
}

void union_set(set *p1,set *p2,set *p3)
{
    int i;
    for ( i = 0; i < (BIT*2); i++)
    {
        (*p3)[i] = (*p1)[i] | (*p2)[i];
    }
    
}

void intersect_set(set *p1,set *p2,set *p3)
{
    int i;
    for ( i = 0; i < (BIT*2); i++)
    {
        (*p3)[i] = (*p1)[i] & (*p2)[i];
    }
}

void sub_set(set *p1,set *p2,set *p3)
{
    int i;
    for ( i = 0; i < (BIT*2); i++)
    {
        (*p3)[i] = (*p1)[i] & ~(*p2)[i];
    }
}

void symdiff_set(set *p1,set *p2,set *p3)
{
     int i;
    for ( i = 0; i < (BIT*2); i++)
    {
        (*p3)[i] = (*p1)[i] ^ (*p2)[i];
    }
}

void stop(void)
{
    exit(4);
}
