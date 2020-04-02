#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "biblio.h"


int main(void){

  int n=0;//tamano da grid
  int game=0;//se game==1 programa termina
  int n_barcos=0;//número de barcos pequenos
  int n_barcos3=0;//número de barcos de tres lugares
  int setup=0;
  srand(time(0));

  Grid grid1;
  Grid grid2;
  Grid grid1_ataque;
  Grid grid2_ataque;

  printf("Tamanho da grelha: ");
  scanf("%i",&n);

  grid1.n=n+1;
  grid2.n=n+1;
  grid1_ataque.n=n+1;
  grid2_ataque.n=n+1;

  Barco** arr1=(Barco**)malloc(grid1.n*sizeof(Barco*));

  for(int i=0;i<grid1.n;i++){
    arr1[i]=(Barco*)malloc(grid1.n*sizeof(Barco));
  }
  grid1.arr=arr1;

  Barco** arr2=(Barco**)malloc(grid2.n*sizeof(Barco*));
  for(int i=0;i<grid2.n;i++){
    arr2[i]=(Barco*)malloc(grid2.n*sizeof(Barco));
  }
  grid2.arr=arr2;

  Barco** arr1_ataque=(Barco**)malloc(grid1_ataque.n*sizeof(Barco*));
  for(int i=0;i<grid1_ataque.n;i++){
    arr1_ataque[i]=(Barco*)malloc(grid1_ataque.n*sizeof(Barco));
  }
  grid1_ataque.arr=arr1_ataque;

  Barco** arr2_ataque=(Barco**)malloc(grid2_ataque.n*sizeof(Barco*));
  for(int i=0;i<grid2_ataque.n;i++){
    arr2_ataque[i]=(Barco*)malloc(grid2_ataque.n*sizeof(Barco));
  }
  grid2_ataque.arr=arr2_ataque;


  initialize_grid(&grid1);
  initialize_grid(&grid2);
  initialize_grid(&grid1_ataque);
  initialize_grid(&grid2_ataque);

  printf("\nGrid jogador 1:\n ");
  printf("\n");
  print_grid(grid1);

  printf("\nGrid jogador 2:\n ");
  printf("\n");
  print_grid(grid2);

  printf("\nNúmero de peças de barco pequenos(ocupam um espaço): ");
  scanf("%i",&n_barcos);

  printf("\nNúmero de peças de barcos grandes(ocupam três espaços): ");
  scanf("%i",&n_barcos3);

  grid1.n_barcos=n_barcos+3*n_barcos3;
  grid2.n_barcos=n_barcos+3*n_barcos3;

  system("clear");


  printf("Setup jogador 1: \n");

  printf("  Setup Random(0) ou Setup Manual(1): ");
  scanf("%i",&setup);


  if(setup==0){//setup random

    rand_grid(&grid1,n_barcos,'o');
    rand_grid3(&grid1,n_barcos3,'o');

  }
  else if(setup==1){//setup manual
    print_grid(grid1);

    for(int i=0;i<n_barcos;i++){
      put_boat(&grid1,'o');
      print_grid(grid1);
    }
    for(int i=0;i<n_barcos3;i++){
      put_boat3(&grid1,'o');
      print_grid(grid1);
    }

  }

  system("clear");


  printf("Setup jogador 2: \n");
  printf("  Setup Random(0) ou Setup Manual(1): ");
  scanf("%i",&setup);

  if(setup==0){//setup random

      rand_grid(&grid2,n_barcos,'o');
      rand_grid3(&grid2,n_barcos3,'o');

}
  else if(setup==1){//setup manual
    print_grid(grid2);

    for(int i=0;i<n_barcos;i++){
      put_boat(&grid2,'o');
      print_grid(grid2);
    }

    for(int i=0;i<n_barcos3;i++){
      put_boat3(&grid2,'o');
      print_grid(grid2);
    }

    print_grid(grid2);
  }


  system("clear");


////////////////////////////////////////////////

int next=0;
   while(game==0){

     printf("Jogador 1: \n");
     print_grid(grid1);

     printf("\nVisão do campo de ataque: \n");
     print_grid(grid1_ataque);

     attack_grid(&grid2,&grid1_ataque);

     if(grid2.n_barcos==0){
       printf("Jogador 1 venceu!!\n");
       break;
     }

     printf("Próximo jogador(clicar num número e em enter)\n");
     scanf("%i",&next);
     system("clear");

     printf("SALA DE ESPERA\n");
     printf("Jogador 2 clique num número e em enter\n");
     scanf("%i",&next);
     system("clear");

     printf("Jogador 2: \n");
     print_grid(grid2);

     printf("\nVisão do campo de ataque: \n");
     print_grid(grid2_ataque);

     attack_grid(&grid1,&grid2_ataque);

     if(grid1.n_barcos==0){
       printf("Jogador 2 venceu!!\n");
       break;
     }

     printf("Próximo jogador (clicar num número e em enter)\n");
     scanf("%i",&next);

     system("clear");

     printf("SALA DE ESPERA\n");
     printf("Jogador 1 clique num número e em enter\n");
     scanf("%i",&next);
     system("clear");
   }



  for(int i=0;i<grid1.n;i++){
    free(grid1.arr[i]);
  }
  for(int i=0;i<grid2.n;i++){
    free(grid2.arr[i]);
  }
  for(int i=0;i<grid1_ataque.n;i++){
    free(grid1_ataque.arr[i]);
  }
  for(int i=0;i<grid2_ataque.n;i++){
    free(grid2_ataque.arr[i]);
  }
}
