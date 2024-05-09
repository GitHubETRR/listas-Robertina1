#include <stdio.h>
#include <stdlib.h>
#define MAX_MUS 10
#define SALIR 3
typedef struct museosbs{
    char Nombre[50];
    char Direccion[50];
    struct museosbs *next;
}museosbs_t;

museosbs_t * lista_museos=NULL;
void menu(void);
void imprimir_museosbs(museosbs_t * museosbs);
void pedir_datos(museosbs_t * museosbs);
void ver_lista(void);
void cargar_museosbs(void);
void liberar_memoria(void);

int main(){
    menu();
    liberar_memoria();
    return 0;
}

void imprimir_museosbs(museosbs_t * museosbs){
    printf("Nombre: %s\n",museosbs->Nombre);
    printf("Direccion: %s\n",museosbs->Direccion);
    printf("+++++++++++++++++++++++\n\n");
}

void pedir_datos(museosbs_t * museosbs){
    printf("Por favor ingrese el nombre de un museo de Buenos Aires:\n");
    scanf(" %[^\n]",museosbs->Nombre);
    printf("Ahora ingrese la direccion de dicho museo:\n");
    scanf(" %[^\n]",museosbs->Direccion);

}

void menu(void){
    int opcion;
    do{
        printf("1_Cargar un nuevo museo de Buenos Aires\n");
        printf("2_Ver todos los museos de Buenos Aires cargados\n");
        printf("3_Salir del programa de mueseos de Buenos Aires\n");
        scanf(" %d",&opcion);
        if(opcion==1)cargar_museosbs();
        if(opcion==2)ver_lista();
    }while(opcion!=SALIR);
    
}

void cargar_museosbs(){
    museosbs_t * museosbs_aux;
    museosbs_aux=malloc(sizeof(museosbs_t));
    if(museosbs_aux==NULL){
        printf("La memoria es insuficiente\n");
    }else{
        pedir_datos(museosbs_aux);
        museosbs_aux->next=lista_museos;
        lista_museos=museosbs_aux;
    }
    
}

void ver_lista(void){
    museosbs_t *lista=lista_museos;
    while(lista!=NULL){
        imprimir_museosbs(lista);
        lista=lista->next;
    }
    
}

void liberar_memoria(void){
    museosbs_t * aux=NULL;
    while(lista_museos!=NULL){
        aux=lista_museos;
        lista_museos=lista_museos->next;
        free(aux);
    }
}