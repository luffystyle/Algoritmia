/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
//     FILA  COL
int mov[8][2];

void movimientos(){
     //x        //y       
    mov[0][0]= -1 ; mov[0][1]=0 ;
    mov[1][0]= -1 ; mov[1][1]=1 ;
    mov[2][0]= 0  ; mov[2][1]=1 ;
    mov[3][0]= 1  ; mov[3][1]=1 ;
    mov[4][0]= 1  ; mov[4][1]=0 ;
    mov[5][0]= 1  ; mov[5][1]=-1;
    mov[6][0]= 0  ; mov[6][1]=-1;
    mov[7][0]= -1 ; mov[7][1]=-1;
};

int busca(int fil,int col,char palabra[],char tablero[][5],int longi){
    int nfil,ncol, j;
    //primero ver si es la letra principal de la plabra buscada
    if(tablero[fil][col]!=palabra[0]) return 0;
    //movernos con los movimientos para la siguiente letra de la palabra buscada
    for(int i=0;i<8;i++){
        //con el i=0;
        // como ya tenemos ejemplo la fil=3 y col 2 vamos a sumarle las cordenadas de los movvimientos para q se muevan
        //  nfil = 3 + -1
        nfil= fil + mov[i][0];
        // ncol = 2 + 0
        ncol= col +mov[i][1];
        //vemos la palabra que buscamos
        for(j=1;j<longi;j++){
            //verificamos si slago del tablero
            if(ncol<0 || nfil<0 || ncol>=5 || nfil>=4) break;
            if(tablero[nfil][ncol] != palabra[j] ) break;
            //si esta bien lo que sigue es la letra de la palabra q buscamos
            //entonces nos movemos en esa posicion si es hacia arriba entonces nos movemos con respecto a esa posicion;
            nfil = nfil + mov[i][0];
            ncol = ncol + mov[i][1];

        }
        if(j==longi) return 1;
        
    }
    return 0;
    
}


void llenarTabla(int fil,int col,char palabra[],char tablero[][5],int longi,char tablVac[][5]){
    int nfil,ncol, j,bandera;
    //primero ver si es la letra principal de la plabra buscada
    if(tablero[fil][col]==palabra[0]){
        //movernos con los movimientos para la siguiente letra de la palabra buscada
        for(int i=0;i<8;i++){
            nfil= fil + mov[i][0];
            ncol= col +mov[i][1];
            //vemos la palabra que buscamos
            for(j=1;j<longi;j++){
                //verificamos si slago del tablero
                if(ncol<0 || nfil<0 || ncol>=5 || nfil>=4) break;
                if(tablero[nfil][ncol] != palabra[j] ) break;
                nfil = nfil + mov[i][0];
                ncol = ncol + mov[i][1];
            } 
            if(j==longi){
                tablVac[fil][col]=tablero[fil][col];
                nfil= fil + mov[i][0];
                ncol= col +mov[i][1];
                for(int k=1;k<longi;k++){
                    tablVac[nfil][ncol]=tablero[nfil][ncol];
                    nfil = nfil + mov[i][0];
                    ncol = ncol + mov[i][1];
                }
                               
            }
        }
    }
    
}



int cantidadPalabras(char palabra[],char tablero[][5],int longi){
    int k=0;
    
    for(int x=0;x<4;x++){
        for(int y=0;y<5;y++){
            if(tablero[x][y]==palabra[0]){
                int j,nfil,ncol;
                for(int i=0;i<8;i++){
                    nfil= x + mov[i][0];
                    ncol= y +mov[i][1];
                    //vemos la palabra que buscamos
                    for(j=1;j<longi;j++){
                        //verificamos si slago del tablero
                        if(ncol<0 || nfil<0 || ncol>=5 || nfil>=4) break;
                        if(tablero[nfil][ncol] != palabra[j] ) break;
                        nfil = nfil + mov[i][0];
                        ncol = ncol + mov[i][1];
                    }
                    
                    if(j==longi){
                        k++;
                    }   
                }

            }            
        }
        
    } 
    return k;
}



void pupiletras(char palabra[],char tablero[][5],int longitud,char tablaVac[][5]){
    //filas y luego columnas
    for(int i=0;i<4;i++){
        //esto nos permitira movernos de fila y columans en la tabla
        for(int j=0;j<5;j++){
            //un ejemplo es que te puedes quedar en la tabla [3][2] = tabla[i][j]
            llenarTabla(i,j,palabra,tablero,longitud,tablaVac);
            if(busca(i,j,palabra,tablero,longitud)){
                cout<<"Encontre la palabra en "<<i<<" "<<j<<endl;
            }
        }
        
    }
    
    
    
}


int main(int argc, char** argv) {
    char tablero[][5]={
        {'G','A','T','O','G'},
        {'O','G','O','L','O'},
        {'L','B','O','C','L'},
        {'R','A','T','L','N'}
    };
    char tablVac[][5]={
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '}
    };
    
    int longPalabra=3;
    char palabra[]={'G','O','L'};
    movimientos();
    pupiletras(palabra,tablero,longPalabra,tablVac);
    cout<<"Cantidad de soluciones encontradas"<<endl<<cantidadPalabras(palabra,tablero,longPalabra);
    cout<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            cout<<tablVac[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}

