#include <iostream>

class Matrix{
    // m = i = rows ; n = j = cols
    public:
        int rows, cols, size;
        int* data;

        Matrix(int r, int c){
            rows=r;
            cols=c;
            size = rows*cols;
            data = (int*) malloc(size*sizeof(int));
            fillMatrix(1);
        }

        ~Matrix(){
            free(data);
        }

        int getPos(int i, int j){
            return data[i*cols + j];
        }

        void setPos(int i, int j, int value){
            data[i*cols + j]=value;
        }
    
        void fillMatrix(int value){
            for (int i = 0; i < size; i++){
                data[i]=value;
            }
        }

        void print(){
            std::cout<<"Matrix "<<rows<<"x"<<cols<<std::endl;
            std::cout<<"Inicio***"<<std::endl;
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < cols; j++){
                    std::cout<<getPos(i,j)<<" ";
                }
                std::cout<<std::endl;
            }
            std::cout<<"***fin"<<std::endl;
        }
};

void matrixMultiply(Matrix &matA, Matrix &matB, Matrix &matC);