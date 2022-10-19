#include <stdio.h>
#include <string.h>

typedef struct _i{
int p,v;
}Item;

Item *itens;
int **mochila;

int main(void) {
  freopen("file.in", "r", stdin);

  int C,N;
  scanf("%d", &C);

  while(C != 0){
    scanf("%d",&N);
    int c = 0;  
    itens = (Item*)malloc(sizeof(Item) * N);
    for(int i=0; i<N; i++){
      Item item;
      int p,v;
      scanf("%d %d", &p,&v);
      item.p = p;
      item.v = v;
      itens[i] = item;
    }

    mochila = (int**)malloc(sizeof(int*)*(N+1));

    for(int i=0; i<N+1; i++){
      mochila[i] = (int*)malloc(sizeof(int) * (C+1));
      memset(mochila[i], 0, sizeof(int) * (C+1));
    }
    //Resolver problema
    for(int i = 1; i < N+1; i++)
      for(int j=1; j < C+1; j++){
        if (itens[i-1].p <= j){
          int soma = itens[i-1].v + mochila[i-1][j - itens[i-1].p];
          int vatual = mochila[i-1][j];
          mochila[i][j] =  soma > vatual ? soma : vatual;
        }else{
          mochila[i][j] = mochila[i-1][j];
        }
      }
    
    // for(int i = 0; i < N+1; i++){
    //   for(int j=0; j < C+1; j++){
    //     printf("%3d", mochila[i][j]);
    //     }
    //   printf("\n");
    //   }
    // printf("\n");
    printf("%d ", mochila[N][C]);

    //Recuperar os itens da mochila

    for(int i = N-1; i >= 0; i--){
      int v = mochila[i+1][C];
      if(v != mochila[i][C]){
        printf("%d", i+1);
        C = C - itens[i].p;
      }
    }
    printf("\n");
    
    free(itens);
    for(int i=0; i<N; i++){
        free(mochila[i]);
    }
    free(mochila);
    scanf("%d", &C);

    
    
  }
  
  return 0;
}