#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

int issort();
void rules();
void random ();
void display();
void play();

int a[4][4],i,j;
char n[10];

int main()
{
    rules();

    random(&a[4][4]);

    play(&a[4][4]);

    return 0;
}
void rules()
{
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);        //for colours
    printf("\t\t* Welcome To The Game ");

    printf("*\n -> Plz Enter Your Name - ");
    scanf("%s",&n);
                         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\t ----->* RULES OF THIS GAME *<-----\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2110);
    printf("1.You Can Move Only One Step At A Time By Arrow Key \n\n");

                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    printf("\tMove Up   : By Up Arrow Key\n");
    printf("\tMove Down : By Down Arrow Key\n");
    printf("\tMove Left : By Left Arrow Key\n");
    printf("\tMove Right: By Right Arrow Key\n\n");

                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2110);

    printf("2.You Can Move Number At Empty Position Only \n\n");

    printf("3.For Each Valid Move : Total Number Of Move Decreased By 1\n\n");

    printf("4.Winning Situation : Number In A 4*4 Matrix  Numbers Should Be In Order From 1 To 15 \n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);

    printf("\t->\tWinning Situation :\n\n\t");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf("\t---------------------");
    printf("\n\t");
        printf("\t|  1 |  2 |  3 |  4 |");
    printf("\n\t");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("\t|  5 |  6 |  7 |  8 |");
        printf("\n\t");
        printf("\t|  9 | 10 | 11 | 12 |");
    printf("\n\t");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printf("\t| 13 | 14 | 15 |    |");
    printf("\n\t");
        printf("\t---------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
    printf("\n5.You can Exit the game at any time by Pressing : 'E' Or :or 'e'\n So Try To Win minimum number of move \n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\t\t\t Happy Gaming , Good Luck  \n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("\t-------> Enter Any Key to Start The Game <-------");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    getch();
    system("cls");
}   //rules() end
void random()           //random function is for generate every time random numbers in array
{
    int n[16],i,j,u=15,l=0,temp;

    srand(time(0));

    for(i=0;i<=15;i++)
    {

        temp=(rand()%(u-l+1)+l);
        for(j=0;j<=i-1;j++)
        {
            if(temp==n[j])
                break;
        }
        if(j==i)
            n[i]=temp;
        else
            i--;
    }

        int k = 0;
        for( i = 0; i<=3; i++ )
        {
        for(j = 0; j<=3; j++ )
            {
                a[i][j] = n[k++];
            }
        }
}   //random()end

void display ()         //for display the numbers and matrix
{
    int q=1;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    printf("\t\t\t\tWelCome To NumGame\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("\n\t( Hello %s...)\n ",n);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

      printf("\n\n\t---------------------\n");
        for( i = 0; i<=3; i++ )
        {
            printf("\t");
            for(j = 0; j<=3; j++ )
            {
                printf("|");
                if(a[i][j]==0)
                    printf("  %c  ",a[i][j]);
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), q++);
                  printf(" %d ", a[i][j]);
                if(a[i][j]<10)
                    printf(" ");
                }
            }
            printf("|\n");
        }
        printf("\t---------------------\n");
}//display() end

int issort()
{
  int n = 4;
  int count=0;
  int d=1;
  for(int i = 0; i<n; i++)
  {
      for(int j = 0; j<n; j++)
      {
          if(a[i][j]==d);
          {
              count++;
          }
           d++;
      }

  }
  if(count==15)
  {
      printf("you won");
      return 1;
  }
  else{
    return 0;
  }

} //issort() end

void play()
{
    int move=100;
    while(move!=0)
    {

        display();              //calling display function for new generated numbers
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

        printf("\n\n\tRemaining Moves->%d ",move) ;

                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        for(i=0;i<=3;i++)
        {
            for(j=0;j<=3;j++)
            {
                if(a[i][j]==0)
                {

                    goto A;
                }
            }
        }A:
        printf("");

        char r;
            r=getch();

        switch(r)
        {
            case 75:
                //left
                if(j<3)
                {
                    a[i][j]=a[i][j+1];
                    a[i][j+1]=0;
                    move--;
                if(issort()==1){
                    printf("\n\tYou Win, in %d Moves", move);
                   }
                    break;
                }

            case 77:
                //right
                if(j>0)
                {
                    a[i][j]=a[i][j-1];
                    a[i][j-1]=0;
                    move--;
                    if(issort()==1){
                        printf("\n\tYou Win, in %d Moves", move);
                    }
                    break;
                }

            case 72:
                //top
                if(i<3)
                {
                    a[i][j]=a[i+1][j];
                    a[i+1][j]=0;
                    move--;
                if(issort()==1){
                    printf("\n\tYou Win, in %d Moves", move);
                  }
                    break;
                }

            case 80:
                //down
                if(i>0)
                {
                    a[i][j]=a[i-1][j];
                    a[i-1][j]=0;
                    move--;
                    if(issort()==1){
                        printf("\n\tYou Win, in %d Moves", move);
                    }
                    break;
                }
            case 69:
                    if(r==69)
                    {

                                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
                        printf("\n\n\n\n\n\t-------> Game has Been Finished! <-------\n\n\n\n\n\n\n\n\n\n");
                                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        return ;
                    }
                    break;

            case 101:

                    if(r==101)
                    {

                                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
                        printf("\n\n\n\n\n\t-------> Game has Been Finished! <-------\n\n\n\n\n\n\n\n\n\n");
                                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        return ;
                    }
                    break;

        } //switch ended.

                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
        printf("\n\n Continue...");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("cls");

        if(move == 0)
        {
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

            printf("\n\t\tYou loosed the Game!\n\n");

                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

            printf("\n\tIf you want to play again then press 1 else 0 :  \n\n\n\n\n\n\n\n\n\n\n\n\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            int x;
            scanf("%d", &x);
            if(x == 1)
            {
                move = 50;
                system("cls");
            }
            else
            {
                return;
            }
        }

    }//while end

}//play();