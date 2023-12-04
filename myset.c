#include "set.h"

int main()
{
    static set SETA, SETB, SETC, SETD, SETE, SETF;
    set *whatSET[] = {&SETA, &SETB, &SETC, &SETD, &SETE, &SETF};
    char c,func[CMD_SIZE];
    char* array; /*will be used to get the string from print_set*/
    int i,whatSet,cc,num,numc; /*cc=comma counter, numc = number counter*/
    memset(SETA, 0, sizeof(SETA)); /*reseting the groups*/
    memset(SETB, 0, sizeof(SETB));
    memset(SETC, 0, sizeof(SETC));
    memset(SETD, 0, sizeof(SETD));
    memset(SETE, 0, sizeof(SETE));
    memset(SETF, 0, sizeof(SETF));

    for (;;)
    {
        printf("Please enter your command:\n");
        if(scanf("%s",func) == 1)
        {
            printf("your command is: %s\n",func);
            if (strcmp(func, "read_set") == 0) /*read_set*/
            {
                i = 0;
                numc = 0;
                while (((c=getchar())!=EOF) && (c!='\n'))/*loop to get the whole string includes white space and tab*/
                {
                    if((i == 5) && (isdigit(c))) /*checking if its a digit or not and proper comma in between*/
                    {
                        numc++; /*cecking if thier is a space between 2 numbers and send an error*/
                        cc = 0;
                        if (numc > 1)
                        {
                            printf("Missing comma\n");
                            i = 0;
                            break;
                        }
                        num = atoi(&c);
                        if (isdigit(c=getchar()))
                        {
                            num *= 10;
                            num += atoi(&c);
                            if (isdigit(c=getchar()))
                            {
                                num *= 10;
                                num += atoi(&c);
                                c=getchar();
                            }
                                
                        }
                        if (num > MAXNUM) /*checking the number is in range*/
                        {
                            printf("Invalid set member - value out of range\n");
                            i = 0;
                            break;
                        }
                        read_set(whatSET[whatSet],num); /*adding number by number to the same group*/ 
                       
                    }

                    if ((c == ' ') || (c == '\t')) /*we skip the irelevant spaces and tabs*/
                    {
                        continue;
                    }  
                    
                    if (i < 4) /*getting and checking the set name*/
                    {                    
                        if (((i == 0) && (c != 'S'))||((i == 1) && (c != 'E'))||((i == 2) && (c != 'T')))
                        {
                            printf("Undefined set name\n");
                            break;
                        }

                        if (i == 3)
                        {
                            if ((0 > (c - 'A')) || (5 < (c - 'A')))
                            {
                                printf("Undefined set name\n");
                                break;
                            }
                            whatSet = (c - 'A');
                        }
                        i++;
                        continue;
                    }

                    if (i == 4) /*need comma after a set name*/
                    {
                        if (c == '\n')
                        {
                            printf("Missing parameter\n");
                            break;
                        }
                        if (c != ',')
                        {
                            printf("Missing comma\n");
                            break;
                        }
                        cc = 1; 
                        memset (whatSET[whatSet], 0, sizeof(set)); /*reseting the group*/
                        i++;
                        continue;
                    }

                    if (c == ',') /*checking Multiple consecutive commas*/
                    {
                        if (cc==1)
                        {
                            printf("Multiple consecutive commas\n");
                            i = 0;
                            break;
                        }
                        cc = 1;
                        numc = 0;
                        continue;
                    }

                    if (c == '.') /*no float*/
                    {
                        printf("Invalid set member - not an integer\n");
                        i = 0;
                        break;
                    }

                    if (c == '-') /*we check that the user ender with proper -1*/
                    {
                        if (cc != 1)
                        {
                            printf("Missing comma\n");
                            i = 0;
                            break;
                        }
                        if((c=getchar()) != '1')
                        {
                            printf("Invalid set member - value out of range\n");
                            i = 0;
                            break;
                        }
                        if ((c=getchar()) != '\n') /*one if before we checked that we get a 1*/
                        {
                            if (c == EOF)
                            {
                                printf("No more input, the system didnt stop properly\n");
                                exit(1);
                            }
                            
                            printf("Extraneous text after end of command\n");
                            i = 0;
                            break;
                        }
                        break; /*user ended properly the input on numbers*/
                    }  
                        
                    printf("Invalid set member - not an integer\n"); /*if the code got here that means that its an invalid char*/
                    i = 0;
                    break;    
                }

                if(c == EOF) /*end of file stop and not with the stop command*/
                {
                    printf("No more input, the system didnt stop properly\n");
                    exit(1);
                }
                if (i < 5) /*the input was incorrect so we skip to next command*/
                {
                    memset (whatSET[whatSet], 0, sizeof(set)); /*reseting the group, the input was wrong so we need to delete the changes*/
                    while ((c = getchar()) != '\n' && c != EOF); /*to clear the buffer before next command*/
                    continue;
                }
                
            }/*end of read_set*/

            else if (strcmp(func, "print_set") == 0) /*print_set*/
            {
                i = 0;
                while (((c=getchar())!=EOF) && (c!='\n'))/*loop to get the whole string includes white space and tab*/
                { 
                    if ((c == ' ') || (c == '\t')) /*we skip the irelevant spaces and tabs*/
                    {
                        continue;
                    }  
                    
                    if (i < 4) /*getting and checking the set name*/
                    {                    
                        if (((i == 0) && (c != 'S'))||((i == 1) && (c != 'E'))||((i == 2) && (c != 'T')))
                        {
                            printf("Undefined set name\n");
                            break;
                        }

                        if (i == 3)
                        {
                            if ((0 > (c - 'A')) || (5 < (c - 'A')))
                            {
                                printf("Undefined set name\n");
                                break;
                            }
                            whatSet = (c - 'A');
                        }
                        i++;
                        continue;
                    }  

                    if (!((c == ' ') || (c == '\t'))) /*check Extraneous text after end of command*/
                    {
                        printf("Extraneous text after end of command\n");
                        break;
                    }
                                     
                }

                if(c == EOF) /*end of file stop and not with the stop command*/
                {
                    printf("No more input, the system didnt stop properly\n");
                    exit(1);
                }
                if (!((c == '\n'))) /*we got a break command from while and the input string didnt end as needed*/
                {
                    while ((c = getchar()) != '\n' && c != EOF); /*to clear the buffer before next command*/
                    continue;
                }
                
                array = print_set(whatSET[whatSet]);
                if(array == NULL) /*realloc faild to alocate space*/
                {
                    printf("Failed to allocate memory\n");
                    exit(2);
                }
                if (array[0] == '\0') /*empty group*/
                {
                    printf("The set is empty\n");
                    continue;
                }
                
                printf("%s\n", array);
                free(array); /*the address comes from using realloc so we need to free it*/
            } /*end of print_set*/

            else if (((strcmp(func, "union_set") == 0) || (strcmp(func, "intersect_set") == 0) || (strcmp(func, "sub_set") == 0) || (strcmp(func, "symdiff_set") == 0))) /*all the functions that need 3 group names*/
            {
                int whatSet1 = -1, whatSet2 = -1;
                i = 0;
                while (((c=getchar())!=EOF) && (c!='\n'))/*loop to get the whole string includes white space and tab*/
                { 
                    if ((c == ' ') || (c == '\t')) /*we skip the irelevant spaces and tabs*/
                    {
                        continue;
                    }  
                    
                    if (i < 4) /*getting and checking the set name*/
                    {                    
                        if (((i == 0) && (c != 'S'))||((i == 1) && (c != 'E'))||((i == 2) && (c != 'T')))
                        {
                            printf("Undefined set name\n");
                            break;
                        }

                        if (i == 3)
                        {
                            if ((0 > (c - 'A')) || (5 < (c - 'A')))
                            {
                                printf("Undefined set name\n");
                                break;
                            }
                            whatSet = (c - 'A');
                        }
                        i++;
                        continue;
                    } 

                    if (i == 4) /*saving the 3 groups*/
                    {
                        if (whatSet1 == -1) /*will save the first and second groups number*/
                        {
                            whatSet1 = whatSet;
                            i = 0;
                        }
                        else if (whatSet2 == -1)
                        {
                            whatSet2 = whatSet;
                            i = 0;
                        }
                        else 
                        {
                           i++; /*to stop steping into this if and countiniue to check the rest of command*/
                           continue;
                        }

                        if (c != ',') /*after the set name should be a comma*/
                        {
                            printf("Missing comma\n");
                            break;
                        }
                        continue;

                    }
                     
                    printf("Extraneous text after end of command\n"); /*if the command came to here then the input is wrong*/
                    break;
                    
                    
                }
                
                if(c == EOF) /*end of file stop and not with the stop command*/
                {
                    printf("No more input, the system didnt stop properly\n");
                    exit(1);
                }

                if (!((c == '\n'))) /*we got a break command from while and the input string didnt end as needed*/
                {
                    while ((c = getchar()) != '\n' && c != EOF); /*to clear the buffer before next command*/
                    continue;
                }
                
                if (strcmp(func, "union_set") == 0)
                {
                    union_set(whatSET[whatSet1],whatSET[whatSet2],whatSET[whatSet]);
                }
                else if (strcmp(func, "intersect_set") == 0)
                {
                    intersect_set(whatSET[whatSet1],whatSET[whatSet2],whatSET[whatSet]);
                }
                else if (strcmp(func, "sub_set") == 0)
                {
                    sub_set(whatSET[whatSet1],whatSET[whatSet2],whatSET[whatSet]);
                }
                else
                {
                    symdiff_set(whatSET[whatSet1],whatSET[whatSet2],whatSET[whatSet]);
                }
                        
            }

            else if (strcmp(func, "stop") == 0)
            {
                stop();
            }

            else
                printf("Undefined command name: %s\n",func); /*will give an error and will wait for the next input command*/
        }

    }
    return 0;
}
