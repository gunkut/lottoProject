#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char sure[5],alphabet[26];
    int guess_loto[6],confirm_loto[6],loto[49];
    int i,j,num=1,random_num,temp1,temp2;
    for(i=0;i<6;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%3d",num);
            if(num==49)
            {
                printf("  IPTAL");
            break;
            }
            num++;
        }
        printf("\n");
    }
    printf("\nenter 6 numbers between 1-49 (including 1 and 49)\n");
    for(i=0;i<6;i++)
    {
        printf("%d.number:",i+1);
        scanf("%d",&guess_loto[i]);
        while((guess_loto[i]<1 || guess_loto[i]>49))
        {
            printf("i said beetween 1-49 fucker.enter correctly.bitch.");
            printf("\n%d.number:",i+1);
            scanf("%d",&guess_loto[i]);
        }
    }
    printf("\ndo you want to change any number?[yes/no]\n");
    scanf("%s",&sure);
    
    int change_num,temp3,new_num,control;
    char okey[5];

    if(sure[0]=='y')
    {
        while(1)
        {
            while(1)
            {
            printf("which number do you want to change?\n");
            scanf("%d",&change_num);
            control=0;
            for(i=0;i<6;i++)
            {
                if(guess_loto[i]==change_num)
                {
                    control=1;
                    printf("enter your new number:");
                    scanf("%d",&new_num);
                    while(new_num<1 || new_num>49)
                    {
                        printf("please make sure that your number is between 1 and 49.\n");
                        printf("enter your new number:");
                        scanf("%d",&new_num);
                    }
                    temp3=guess_loto[i];
                    guess_loto[i]=new_num;
                    new_num=temp3;
                    break;
                }
            }
            if(control==1)
            break;
            else 
            printf("number not found.please try again\n");
            }
        printf("you good?[yes/no]\n");
        scanf("%s",&okey);
        if(okey[0]=='y')
        break;
        }
    }
    printf("\nyour numbers:   ");

    for(i=0;i<6;i++)
    printf("%3d",guess_loto[i]);
    printf("\n");
   
    printf("winning numbers:");
    for(i=0;i<6;i++)
    {
        random_num=1+rand()%49;
        while(loto[random_num-1]==1)
        {
            random_num=1+rand()%49;
        }
        confirm_loto[i]=random_num;
        loto[random_num-1]=1;
        printf("%3d",random_num);
    }

    int flag=0,winner_flag[6],k=0;

    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(confirm_loto[j]==guess_loto[i])
            {   
                winner_flag[k]=guess_loto[i];
                k++;
                flag++;
                break;
            }
        }
    }

    if(flag==1)
    printf("\nyou guessed %d number correct.",flag);
    else if(flag==0)
    printf("\nyou messed up.");
    else 
    printf("\nyou guessed %d numbers correct.",flag);

    if(flag>0)
    {
    printf("\nyour winner numbers are:"); 
    for(i=0;i<flag;i++)
        printf("%3d",winner_flag[i]);
    }

    if(flag==4 || flag==3)
    printf("\nyou win 10.000 turkish liras.");
    else if(flag==5)
    printf("\nyou win 200.000 turkish liras.");
    else if(flag==6)
    printf("\ncongrats,you win the jackpot");
    return 0;
}	