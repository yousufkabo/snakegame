//name :yousuf abdullah kabbo
//id   :2311128042
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int width =20,height=20,gameOVER;
int x,y,fruitx,fruity,score,flag;
int tailx[100],taily[100];
int countTAIL = 0;
void setup (void) //defining where the fruits and the snake has to be appear
{
    gameOVER = 0;
    x = width/2;
    y = height/2;
    lebel1:
    fruitx = rand()%20;
    if(fruitx == 0)
    {
        goto lebel1;
    }
    lebel2:
    fruity = rand()%20;
    if(fruity == 0)
    {
        goto lebel2;
    }
    score = 0;
}
void border (void) //making the hole border of the game an as well as the score
{
    system("cls");
    int i,j,k;
    for(i=0;i<=width;i++)
    {
        for(j=0;j<=height;j++)
        {
            if(i == 0 || i  == height || j == 0 || j == width)
            {
                printf("*");
            }
            else
            {
                if(i == x && j == y)
                {
                    printf("O");
                }
                else if(i == fruitx && j == fruity)
                {
                    printf("@");
                }
                else
                {
                    int ch = 0;
                    for(k=0;k<countTAIL;k++)
                    {
                        if(i == tailx[k] && j == taily[k])
                        {
                            printf("o");
                            ch = 1;
                        }
                    }
                    if(ch == 0)
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("SCORE - %d", score);
}
void keyboard (void) //choosing button so that we can move the snake
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
            flag=1;
            break;
        case 's':
            flag=2;
            break;
        case 'w':
            flag = 3;
            break;
        case 'd':
            flag = 4;
            break;
        case 'x':
            gameOVER = 1;
            break;
        }
    }
}
void makeLOGIC ()
{
    //increasing the snake through arrays
    int prevX = tailx[0];
    int prevY = taily[0];
    int prev2X,prev2Y;
    tailx[0] = x;
    taily[0] = y;
    for(int i=1;i<countTAIL;i++)
    {
        prev2X = tailx[i];
        prev2Y = taily[i];
        tailx[i] = prevX;
        taily[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(flag)//making movement of the snake
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        x--;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }
    if(x < 0 || x > width || y < 0 || y > height)
    {
        gameOVER = 1;
    }
    for(int i=0;i<countTAIL;i++)
    {
        if(x == tailx[i] && y == taily[i])
            gameOVER = 1;
    }
    if(x == fruitx && y == fruity)
    {
        lebel3:
        fruitx = rand()%20;
        if(fruitx == 0)
        {
            goto lebel3;
        }
        lebel4:
        fruity = rand()%20;
        if(fruity == 0)
        {
            goto lebel4;
        }
        score = score +10;
        countTAIL++;
    }

}
int main (void)
{
    char startin,control;
    char name[100];
    printf("~~~~~~~~~~SNAKE GAMW~~~~~~~~~~\n");
    printf("please enter your name \n");
    gets(name);
    printf("hi %s good luck\n", name);
    printf("press y and enter to play the snake game\n");
    scanf("%c", &startin);
    if(startin == 'y' || startin == 'Y')
    {

        char c;
        label5:

           setup();
    while(!gameOVER)
    {
        border();
        keyboard();
        makeLOGIC();
        for(int m=0;m<1000;m++)
        {
            for(int n=0;n<1000;n++)
            {
                for(int k=600;k<1000;k++)
                {

                }
            }
        }
    }

    printf("\n press y to continue again\n");
    scanf("%c", &c);
    if(c == 'y' || c == 'Y')
        goto label5;
    return 0;
    }

}
