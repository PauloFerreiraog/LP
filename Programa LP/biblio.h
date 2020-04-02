
typedef struct {

  char ch;

}Barco;

typedef struct {

     int n;

     Barco **arr;
     int n_barcos;//jogo termina quando n_barcos==0

  }Grid;

void print_grid(Grid);

void initialize_grid(Grid *);

void put_boat(Grid *,char);


void put_boat3(Grid *,char);

void rand_grid(Grid *,int,char);

void rand_grid3(Grid*,int,char);

void attack_grid(Grid *grid,Grid *grid_ataque);
