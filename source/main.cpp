#include<iostream>
#include<string>
#include"qsort.h"
#include"gemm.h"
#include<omp.h>

using std::cin;
using std::vector;
using std::cout;
using std::endl;
using std::string;

void show_opts(){
    cout<<"[s] Ordenamiento"<<endl;   
    cout<<"[b] Busqueda"<<endl; 
    cout<<"[g] Multiplicacion de matrices"<<endl;   
    cout<<"[h] Ayuda"<<endl;
    cout<<"[q] Salir"<<endl;
}

void HandleSearch(){
    cout<<"En desarrollo..."<<endl;
}

void HandleGEMM(){
    int rows,cols,value;
    char display='n';
    double inicio,fin;

    cout<<"Matriz A:"<<endl;
    cout<<"Filas: ";
    cin>>rows;
    cout<<"Columnas: ";
    cin>>cols;
    cout<<"Valor de relleno: ";
    cin>>value;
    Matrix a = Matrix(rows,cols);
    a.fillMatrix(value);

    cout<<"Matriz B:"<<endl;
    cout<<"Filas: ";
    cin>>rows;
    cout<<"Columnas: ";
    cin>>cols;
    cout<<"Valor de relleno: ";
    cin>>value;
    Matrix b = Matrix(rows,cols);
    b.fillMatrix(value);
    
    Matrix c = Matrix(a.rows,b.cols);

    inicio = omp_get_wtime();
    /* Multiplicacion */
    matrixMultiply(a,b,c);
    fin = omp_get_wtime() - inicio;
    
    cout<<"Mostrar? [s/N]"<<endl;
    cin>>display;
    if(display=='s') c.print();
    cout<<"Tiempo de ejecucion: "<<fin<<endl;
}

void HandleSorting(){
    /* Cantidad de elementos a ordenar */
    int NUM_ELEMENTOS, iteraciones;
    char display = 'n';
    cout<<"Numero de elementos a ordenar"<<endl;
    cin>>NUM_ELEMENTOS;
    cout<<"Iteraciones"<<endl;
    cin>>iteraciones;
    cout<<"Mostrar? [s/N]"<<endl;
    cin>>display;

    double inicio,fin;
    /* Iniciar vector */
    vector<int> vector;

    /* Suma de los tiempos de ejecucion de la funcion quicksort */
    double sum=0;
    /* Iteraciones */
    for (int i = 0; i < iteraciones; i++){
        vector.clear();
        vector = crear_vector_desordenado(NUM_ELEMENTOS);
        inicio = omp_get_wtime();
        /* Ordenamiento */
        quicksort(vector);
        fin = omp_get_wtime() - inicio;
        sum += fin;
    }

    if( display == 's'){
        mostrar_vector(vector,"Ultimo vector ordenado");
    }
    
    // Mostrar tiempos de ejecucion 
    cout <<"Suma de tiempos de ordenamiento: "<< sum <<endl;
    cout <<"Promedio de tiempos de ordenamiento: "<< sum/iteraciones <<endl;
}

int main(int argc, char const *argv[]){
    srand((unsigned) time(NULL));
    int exit=0;
    char op_selected;

    cout<<"\t\\\\    //\\\\"<<endl;
    cout<<"\t \\\\  //__\\\\ aLGORITMOS"<<endl;
    cout<<"\t  \\\\//    \\\\"<<endl; 

    cout<< "Opciones: "<<endl;
    show_opts();

    while(exit==0){
        cout<<">> ";
        cin>>op_selected;
        
        switch(op_selected){
            case 'h':
                show_opts();
                break;

            case 's':
                HandleSorting();
                break;

            case 'g':
                HandleGEMM();
                break;
            
            case 'b':
                HandleSearch();
                break;

            case 'q':
                exit=1;
                break;

            default:
            cout<<"Opcion Invalida"<<endl;
                break;
        }
    }

    return 0;

}
