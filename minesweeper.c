#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
int Grid[N][N];
int rows;
int columns;
int rp;
int cp;
void MineGrid(int x,int y); // creates the map
void Positioning(int x, int y); // allows the user to enter the positions of mines and player
void delay(float t);

int main(){

 printf("\t\tWelcome to Minesweeper Custom Map Creator");
 delay(0.4);
 printf("\n\tHere you can only create the map, Unfortunately you cannot play");
 delay(0.5);
 printf("\n\n\t\t IMPORTANT INFO : ");
  delay(0.3);
 printf("\n\n\t P refers to the position of the player");
  delay(0.4);
 printf("\n\t You can choose the mine densities here while placing the mines!!!! ");
  delay(0.5);
 printf("\n\t * is the low density mine indicated by the number 1");
 printf("\n\t # is the medium density mine indicated by the number 2");
 printf("\n\t @ is the high density mine indicated by the number 3");
  delay(2);
 printf("\n\n\t Lets create the map (!!!)");
  delay(0.4);

printf("\n\nEnter the number of rows (MAX 10 , MIN 3): ");
scanf("%d",&rows);
while(rows > 10 || rows<3){
        printf("\nEnter the valid number of rows : ");
scanf("%d",&rows);}

printf("\nEnter the number of columns (MAX 10 , MIN 3) : ");

scanf("%d",&columns);
while(columns > 10 || columns<3) {
    printf("\nEnter the valid number of columns : ");
scanf("%d",&columns);};

for(int i = 0;i<=rows;i++){
    for(int j = 0;j<columns;j++){
        Grid[i][j] = '-';
    }

}

MineGrid(rows,columns);
Positioning(rows,columns);
 delay(0.5);

printf("\n\n\n\tCONGRATS YOUVE SUCCESSFULLY CREATED THE MAP!!! TAKE A LOOK AT IT\n\n");

 delay(0.7);
 MineGrid(rows,columns);


}



void MineGrid(int x,int y){


for(int i = 0;i<x;i++){
    for(int j = 0;j<y;j++){

          printf("| ");
          printf("%c",Grid[i][j]);
          printf(" |    ");

    }
    printf("\n");
}

}



void Positioning(int x, int y){

printf("\nEnter the row of the current position of the player(Assuming that the first row is the 0th row) : ");
scanf("%d",&rp);
while(rp>(rows-1) || rp<0){
    printf("\nEnter the valid row position : ");
    scanf("%d",&rp);
}

printf("\nEnter the column of the current position of the player(Assuming that the first column is the 0th column) : ");
scanf("%d",&cp);
while(cp>(columns-1) || cp<0){
    printf("\nEnter the valid column position : ");
    scanf("%d",&cp);
}
Grid[rp][cp] = 'P';
printf("\n");

MineGrid(rows,columns);

int mines;
int density;

printf("\n");

printf("\nEnter the total number of mines (ATLEAST 1) : ");
scanf("%d",&mines);
while(mines>((rows*columns)-1) || mines<1){
    printf("\nEnter the valid number of mines(MINES CANNOT BE GREATER THAN OR EQUAL TO THE TOTAL BOXES) : ");
    scanf("%d",&mines);
}

int pmines;
printf("\nEnter the total number of mines to the right/left and above/below to the current position (MAX 5) : ");
scanf("%d",&pmines);
while(pmines > mines || pmines > 5){
    printf("\nInvalid number !!! Enter again(CANNOT BE GREATER THAN TOTAL MINES OR 5) : ");
    scanf("%d",&pmines);
}

int mpr;
int mpc;
int npr[N];
int npc[N];
int i = 0;
int j = 1;

while(1){


    printf("\nEnter the position(row) of the mine(Assuming the first row is the 0th row) : ");
    scanf("%d",&mpr);

    while(mpr>(rows-1) || mpr<0){
    printf("\nEnter the valid row position : ");
    scanf("%d",&mpr);
}

    printf("\nEnter the position(column) of the mine(Assuming the first column is the 0th column) : ");
    scanf("%d",&mpc);

    while(mpc>(rows-1) || mpc<0){
    printf("\nEnter the valid row position : ");
    scanf("%d",&mpc);
}


while(mpr == rp && mpc == cp){                                                                     //checks if the position is already occupied by the player
    printf("\nPosition already occupied, Please Enter again ");
     printf("\nEnter the position(row) of the mine(Assuming the first row is the 0th row) : ");
    scanf("%d",&mpr);
    printf("\nEnter the position(column) of the mine(Assuming the first column is the 0th column) : ");
    scanf("%d",&mpc);

}

for(i = 0;i<j;i++){                                //checks if the position is already occupied by the mine
    while
        (npr[i] == mpr && npc[i] == mpc){

        printf("\nPosition already occupied, Please Enter again ");
     printf("\nEnter the position(row) of the mine(Assuming the first row is the 0th row) : ");
    scanf("%d",&mpr);
    printf("\nEnter the position(column) of the mine(Assuming the first column is the 0th column) : ");
    scanf("%d",&mpc);

    }

}

    while((pmines == 0 && (mpr == rp || mpc == cp)) ) {
            printf("\nNo more mines can be placed to the right/left and above/below to the current position ");

              printf("\nEnter the position(row) of the mine(Assuming the first row is the 0th row) : ");
    scanf("%d",&mpr);
    printf("\nEnter the position(column) of the mine(Assuming the first column is the 0th column) : ");
    scanf("%d",&mpc);

    }


    printf("\nEnter the density number of the mine : ");
    scanf("%d",&density);
    while(density > 3){
        printf("\nDensity can only be 1 2 or 3. Enter again : ");
        scanf("%d",&density);
    }
printf("\n");
    switch(density){
    case 1:  Grid[mpr][mpc] = '*';
    break;
    case 2: Grid[mpr][mpc] = '#';
    break;
    case 3: Grid[mpr][mpc]= '@';
    break;

    }

   MineGrid(rows,columns);

     if(mpr == rp || mpc == cp) pmines --;
    mines--;

    printf("\nTotal mines left = %d",mines);
    if(mines == 0) break;


npr[i] = mpr;
npc[i] = mpc;
i++;
j++;
}

}

void delay(float t)  //delays t seconds
{
    clock_t start=0;
    start=clock();

    while((clock()-start)<(t*1000));

    return ;
}



