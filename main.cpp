// Bibliotecas
#include "mainwindow.h"
#include "Algoritmos/Pathfinding/Backtracking.hpp"
#include "Algoritmos/Pathfinding/a_star.hpp"
#include "Data_Structures/nodo.hpp"
#include "Data_Structures/lista.hpp"
#include "Algoritmos/Genético/gen_Engine.hpp"

#include <QApplication>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "Algoritmos/Genético/poblacion.hpp"
#include <bitset>

using namespace std;

// Declaracion de funciones
void print_maze(int(*maze)[10]);
int Backtracking_test();
int A_star_test();
void lista_test();

int main(){

    /*string binary = bitset<8>(3).to_string();
    cout<<binary<<endl;

    unsigned long dec = bitset<8>(binary).to_ulong();
    cout<<dec<<endl;

    binary.replace(5,1,"1"); // Así cambia las cosas en el binario
    cout<<binary<<endl;*/



    //lista_test();
    Poblacion* P = new Poblacion(90);
    //P->Ordenar();
    P->print_Estadistica();

    /*Lista<Gladiador*> *nextG = new Lista<Gladiador*>();
    for(int i = 0; i < 10; i++){
        nextG->push_back(new Gladiador());
    }*/

    //Gen_Engine::Crossover(P);
    P->print_Estadistica();
    //P->print_Gladiadores();

    //cout<<"Backtracking:"<<endl;
    //Backtracking_test();

    //cout<<"A*:"<<endl;
    //A_star_test();
    return 0;
}

/*
 * Funcion que se encarga de  realizar una prueba al algoritmo Backtracking
 */
int Backtracking_test(){
    // Declarar la matriz que se usara como laberinto
    int maze[][10] = { {0,0,1,0,0,0,0,0,1,0},
                       {0,0,1,0,1,1,1,0,1,0},
                       {0,1,1,0,0,0,0,0,1,0},
                       {0,1,0,0,1,1,1,0,0,0},
                       {0,0,1,0,1,0,1,0,0,0},
                       {0,0,0,0,1,0,0,0,1,1},
                       {1,1,0,1,1,0,1,1,1,1},
                       {0,0,0,1,0,0,1,0,0,1},
                       {0,0,0,1,0,0,1,0,1,0},
                       {0,0,0,1,0,0,0,0,1,0}};

    Backtracking* solver = new Backtracking();
    string my_path = solver->Backtracking_Search(maze);
    int time = solver->get_Time();
    delete(solver);
    cout<<my_path<<endl;
    cout<<"Encuentra la ruta en: "<< time<<" us"<<endl;
    return 0;
}

// Imprime el laberinto en la consola
void print_maze(int(*maze)[10]){
    for(int row=0;row<10;row++){
      cout<<"{ ";
      for(int col=0;col<10;col++){
        cout<<maze[row][col]<<" ";
      }
      cout<<" }"<<endl;
    }
}

// Función que ejecuta el algoritmo A*
int A_star_test(){

    // Declarar un laberinto
    int maze[][10] = { {0,0,1,0,0,0,0,0,1,0},
                       {0,0,1,0,1,1,1,0,1,0},
                       {0,1,1,0,0,0,0,0,1,0},
                       {0,1,0,0,1,1,1,0,0,0},
                       {0,0,1,0,1,0,1,0,0,0},
                       {0,0,0,0,1,0,0,0,1,1},
                       {1,1,0,1,1,0,1,1,1,1},
                       {0,0,0,1,0,0,1,0,0,1},
                       {0,0,0,1,0,0,1,0,1,0},
                       {0,0,0,1,0,0,0,0,1,0}};

    // Ejecutar el algoritmo A*
    A_star* solver = new A_star();
    solver->A_star_Search(maze,make_pair(0,0));

    // Obtener la ruta como String
    string my_Path = solver->get_Path();
    int time = solver->get_Time();
    delete(solver);

    // Muestra en consola la ruta encontrada
    cout<<my_Path<<endl;
    cout<<"Encuentra la ruta en: "<<time<<" us"<<endl;
    return 0;
}
