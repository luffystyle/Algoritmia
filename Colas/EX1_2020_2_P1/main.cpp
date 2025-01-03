/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: AlienCoders
 *
 * Created on 17 de mayo de 2023, 11:51 PM
 */

#include <cstdlib>
#include "cola.h"
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Cola Productos;
    construir(Productos);
    
    ElemPro p;
    ifstream archProd("productos.txt", ios::in);
    
    while(true){
        archProd>>p.tipoLote>>p.codigo;
        
         encolarConPrioridad(Productos, p);
         mostrar(Productos);
         
         if(archProd.get()=='\n') break;
    }

    mostrar(Productos);
    
    

    return 0;
}

