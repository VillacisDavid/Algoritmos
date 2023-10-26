/*
*   Multiplicacion de matrices cuadradas secuencial simple, secuencial optimizada y paralela
*   Multiplica las matrices MatrixA(m,n) y MatrixB(n,k) y almacena el resultado en MatrixC(m,k)
*   donde m, n y k seran iguales debido a que para el ejercicio se usara matrices cuadradas.
*/

#include <stdlib.h>
#include <time.h>
#include "gemm.h"

using std::cout;
using std::endl;

void matrixMultiply(Matrix &matA, Matrix &matB, Matrix &matC){

    /* Manejar matrices incorrectas */
    if(matA.cols != matB.rows){
        cout<<"No es posible multiplicar estas matrices"<<endl;
        return;
    }

    int sum;
    for(int i=0; i<matC.rows; i++){
        for(int j=0; j<matC.cols; j++){
            sum=0;
            for(int idx=0; idx<matA.cols; idx++){
                sum+=matA.getPos(i,idx)*matB.getPos(idx,j);
            }
            matC.setPos(i,j,sum);
        }
    }
}

// void ComputeTile(Matrix *matA, Matrix *matB, Matrix *matC, int x, int y, const int TILE)
// {
//     for (int i = x; i < x + TILE; ++i)
//     {
//         for (int j = y; j < y + TILE; ++j)
//         {
//             for (int idx = 0; idx < matA.rows; ++idx)
//             {
//                 matC.data[i*matC.cols + j] += matA.data[i*matA.cols + idx] * matB.data[idx*matB.cols + j];
//             }
//         }
//     }
// }

// void multiplicar_paralelo_tiling(matrix *matA, matrix *matB, matrix *matC)
// {
//     const int TILE = SIZE/NUM_THREADS;
//     #pragma omp parallel for num_threads(NUM_THREADS) collapse(2)
//         for (int i = 0; i < matC.rows; i += TILE)
//         {
//             for (int j = 0; j < matC.cols; j += TILE)
//             {
//                 ComputeTile(matA, matB, matC, i, j, TILE);   
//             }
//         }
// }

