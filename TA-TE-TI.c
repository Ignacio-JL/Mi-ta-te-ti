#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
int control(int,int);
void tablero(char[][3],int,int);
int asignacion (char[][3],char,int,int,int);
int ganador(char[][3]);


int main(){

    char t[3][3]={'1','2','3','4','5','6','7','8','9'};
    char p1='X',p2='O';
    int posicion,win=0,cont=0,error;///ERROR (1=INGRESO REPETIDO  |  0=DATO BIEN INGRESADO)
    while(win==0){///MIENTRAS NO HAYA UN GANADOR
    error=1;/// SIN ESTO EN CASO QUE EL DATO SE INGRESE BIEN, NO VOLVERIA A ENTRAR AL WHILE(L19)
    tablero(t,3,3);
    while(error==1){

    if(cont%2==0){
            printf("\n Turno de jugador 1\n");
            posicion=control(1,9);
            error=asignacion(t,p1,posicion,3,3);
                if(error==1)
    printf("\n lugar ya ocupado, intenta de nuevo\n");
    }
    else{
        printf("\n Turno de jugador 2\n");
        posicion=control(1,9);
        error=asignacion(t,p2,posicion,3,3);
        if(error==1)
    printf("\n lugar ya ocupado, intenta de nuevo\n");
    }
    }

    system("cls");
    win=ganador(t);
    if(win==1){
         tablero(t,3,3);
         printf("\n Felicidades jugador %d GANASTE xd !!!\n\n",(cont%2)+1);
        }
    cont++;


    }




return 0;
}
///
void tablero(char t[][3],int f,int c){
    int i,j;
    for(i=0;i<f;i++){
            printf("\n |");
        for(j=0;j<c;j++){
            printf(" %c |",t[i][j]);
        }
    printf("\n -------------");
    }

}

///
int control(int li,int ls){
    int dato,bobo=0;

    do{
            if(bobo==0){
        printf("\n ingrese posicion a jugar: ");
        scanf("%d",&dato);
        bobo=1;
            }
            else{
                printf("\n Error, selecciona entre el 1 y el 9 bobo: ");
                scanf("%d",&dato);
            }
    }
    while((dato<li)||(dato>ls));
    return(dato);

}
///
int asignacion(char t[][3],char marca,int p,int f,int c){
    int i,j,aux=1,cont=0,posi=-1;
    char dato='0'+p;
    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
            if(dato==t[i][j]){
                t[i][j]=marca;
                aux=0;
            }

        }
    }

    return(aux);

}
///
int ganador(char t[][3]){///SON 8 POSIBILIDADES LAS DE HACER TA-TE-TI
    int r=0;
        if(((t[0][0])==(t[0][1]))&&((t[0][1])==(t[0][2])))  ///1
        r=1;
        if(((t[1][0])==(t[1][1]))&&((t[1][1])==(t[1][2])))  ///2
        r=1;
        if(((t[2][0])==(t[2][1]))&&((t[2][1])==(t[2][2])))  ///3
        r=1;
        if(((t[0][0])==(t[1][0]))&&((t[1][0])==(t[2][0])))  ///4
        r=1;
        if(((t[0][1])==(t[1][1]))&&((t[1][1])==(t[2][1])))  ///5
        r=1;
        if(((t[0][2])==(t[1][2]))&&((t[1][2])==(t[2][2])))  ///6
        r=1;
        if(((t[0][0])==(t[1][1]))&&((t[1][1])==(t[2][2])))  ///7
        r=1;
        if(((t[0][2])==(t[1][1]))&&((t[1][1])==(t[2][0])))  ///8
        r=1;
        return(r);
}
