#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdbool.h> 
#include<conio.h>
int n,*a,c=0;
void nQueens();
void print();
int safe(int);
bool queens(int,int);
//Function for checking the boundary conditions.
int safe(int pos)
{
    int i;
    if(pos==1 && a[pos]>n)  // if the first crossing the board length
        return 0;
    for(i=1;i<pos;i++)
        if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos)))||(a[pos]>n)) // checking the dialgonal and the column coonditions and also the board length
            return 0;
    return 1;
}
//Function For printing the ChessBoard.
void print()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        printf("|");
        for(j=1;j<=n;j++)
            if(j==a[i])
                printf("Q|");
            else
                printf("_|");
        printf("\n");
    }
    printf("\n");
}
//Function for placing the queen in the board
bool queens(int col,int q)
{
    int i;
    if(q>n) // All the queens are placed.
        return true;
    else if(q<1)  // meas that all queens can not be placed further
        return false;
    else
    {   a[q]=col;
        if(safe(q)) // Checking the queen's position violeting the conditions or not.
        {            
            queens(1,q+1);  //if not proceed further.
        }
        else
        {   //if not then teke the queen off and tryto place it in the next column.
            col=a[q];   
            a[q]=0;
            if(col+1>n) // if the column size is crossing the the board then
            {
                col=a[q-1]; //take off the the previous queen
                a[q-1]=0;
                queens(col+1,q-1);  //and try to place it in the next column and so on.
            }
            else
            {
                queens(col+1,q);
            }
               
        }
            
    }
}


void nQueens()
 {
    int p=a[1];
    queens(p+1,1);// Calls the queens function for recursively with the every next column for the first queen
    if(a[n]!=0)
    {
        printf("Solution No: %d\n",c+1);
        print();
        c++;
        if(c==4) //For printing max 4 no of solutions.
            return;
        nQueens();
    }
    else
        return;
    
 }
 
int main()
{
    int i;
    printf("enter the size of ChessBoard: ");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*(n+1));
    for(i=0;i<=n;i++)
        a[i]=0;
    nQueens();
    if(c==0)    // after checking the all possibilities but still nothing.
        printf("\n No Soln exists..\n");
        
    return 0;
}