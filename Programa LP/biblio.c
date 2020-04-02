#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "biblio.h"

void print_grid(Grid grid){


 for(int i=0;i<grid.n;i++){
    for(int j=0;j<grid.n;j++){

      if(i==0){
         printf("%i",j);

      }

      else if(j==0){
         printf("%i",i);

      }
      else{
         putchar(grid.arr[i][j].ch);

       }
       printf(" ");

   }
   putchar('\n');
}
}

void initialize_grid(Grid *grid){



   for(int i=0;i<grid->n;i++){
     for(int j=0;j<grid->n;j++){

    grid->arr[i][j].ch='~';

   }
  }

  }

  void put_boat(Grid *grid,char ch){

      int x=0;
      int y=0;

      printf("Digite coordenadas do barco: \n");
      scanf("%i",&x);
      scanf("%i",&y);

      if(x>grid->n || y>grid->n||x==0||y==0){
        printf("Ponto inválido-Tente novamente\n");
        put_boat(grid,ch);
      }
      else{
        grid->arr[x][y].ch=ch;
      }
  }



void put_boat3(Grid *grid,char ch){

    int x_1=0;
    int y_1=0;
    int x_2=0;
    int y_2=0;
    int x_3=0;
    int y_3=0;

    int dir=-1;

    printf("Barco grande(três espaços)\n");

  //while(!(dir==1 || dir==0))

    printf("Barco horizontal(0) ou vertical(1): ");
    scanf("%i",&dir);



    /*if(!(dir==1 || dir==0)){
      printf("Input Inválido-Tente novamente\n");
    }*/
  //}

    printf("Digite coordenadas do barco do centro: ");
    scanf("%i",&x_2);
    scanf("%i",&y_2);

    if(dir==0){//BARCO horizontal

      x_1=x_2;
      x_3=x_2;

      y_1=y_2-1;
      y_3=y_2+1;

      if(y_2==1 || y_2==grid->n-1 || x_2>grid->n || y_2>grid->n || grid->arr[x_1][y_1].ch=='o' || grid->arr[x_2][y_2].ch=='o' || grid->arr[x_3][y_3].ch=='o'){
        printf("Ponto Inválido-Tente novamente\n");
        put_boat3(grid,ch);
      }
      else{
        grid->arr[x_1][y_1].ch=ch;
        grid->arr[x_2][y_2].ch=ch;
        grid->arr[x_3][y_3].ch=ch;
      }
    }
    else if(dir==1){//barco vertical

      y_1=y_2;
      y_3=y_2;

      x_1=x_2-1;
      x_3=x_2+1;

      if(x_2==1 || x_2==grid->n-1 || x_2>grid->n || y_2>grid->n || grid->arr[x_1][y_1].ch=='o' || grid->arr[x_2][y_2].ch=='o' || grid->arr[x_3][y_3].ch=='o'){
        printf("Ponto inválido-Tente novamente");
        printf("\n");
        put_boat3(grid,ch);
      }
      else{
        grid->arr[x_1][y_1].ch=ch;
        grid->arr[x_2][y_2].ch=ch;
        grid->arr[x_3][y_3].ch=ch;
      }

    }

}

void put_boatT(Grid *grid,int n_barcosT,char ch){





}


  void rand_grid(Grid *grid,int n_barcos,char ch){

    for(int i=0;i<n_barcos;i++){

      int x=rand()%(grid->n-1);
      int y=rand()%(grid->n-1);
      x++;
      y++;
      //printf("x: %i\n",x);
      //printf("y: %i\n",y);


      if(grid->arr[x][y].ch==ch){//para não repetir barcos
         n_barcos++;
      }

    grid->arr[x][y].ch=ch;
    }

  }

  void rand_grid3(Grid *grid,int n_barcos3,char ch){

    for(int i=0;i<n_barcos3;i++){

      int setup=-1;
      setup=rand()%2;

      if(setup==0){//horizontal

        int x_2=rand()%(grid->n-1);
        int y_2=rand()%(grid->n-1);
        x_2++;
        y_2++;
        int x_1=x_2;
        int x_3=x_2;
        int y_1=y_2-1;
        int y_3=y_2+1;

          if(y_2==1 || y_2==grid->n-1 || x_2>grid->n || y_2>grid->n || grid->arr[x_1][y_1].ch=='o' || grid->arr[x_2][y_2].ch=='o' || grid->arr[x_3][y_3].ch=='o'){//para não repetir barcos
            n_barcos3++;
          }
          else{
            grid->arr[x_1][y_1].ch=ch;
            grid->arr[x_2][y_2].ch=ch;
            grid->arr[x_3][y_3].ch=ch;
          }
      }
      else if(setup==1){
        int x_2=rand()%(grid->n-1);
        int y_2=rand()%(grid->n-1);
        x_2++;
        y_2++;
        int y_1=y_2;
        int y_3=y_2;
        int x_1=x_2-1;
        int x_3=x_2+1;


        if(x_2==1 || x_2==grid->n-1 || x_2>grid->n || y_2>grid->n || grid->arr[x_1][y_1].ch=='o' || grid->arr[x_2][y_2].ch=='o' || grid->arr[x_3][y_3].ch=='o'){//para não repetir barcos
         n_barcos3++;
        }
        else{

          grid->arr[x_1][y_1].ch=ch;
          grid->arr[x_2][y_2].ch=ch;
          grid->arr[x_3][y_3].ch=ch;
      }
    }
}
}




 void attack_grid(Grid *grid,Grid *grid_ataque){//grid é a grid do enemigo e grid_ataque é a visão de quem está a atacar dessa grid

   printf("\ncoordenadas do ataque: \n");
   int x=1;
   int y=1;
   scanf("%i",&x);
   scanf("%i",&y);

   if(x==0 || y==0 || x<0 || y<0 || x>=grid->n||y>=grid->n){
     printf("Input de ataque inválido tente novamente\n");
     attack_grid(grid,grid_ataque);
   }

    else if(grid->arr[x][y].ch=='~'){

     grid_ataque->arr[x][y].ch='F';
     grid->arr[x][y].ch='F';
     printf("Falhou\n");}

     else if(grid->arr[x][y].ch=='o'){

     grid_ataque->arr[x][y].ch='x';
     grid->arr[x][y].ch='x';

     grid->n_barcos--;
     printf("Acertou\n");

   }

}
