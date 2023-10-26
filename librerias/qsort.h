#include<iostream>
#include<vector>

std::vector<int> crear_vector_desordenado(int vec_size);
void mostrar_vector(std::vector<int> vec, std::string label);
int getpivot(std::vector<int> vec);
void insertionsort(std::vector<int> &vec);
void quicksort(std::vector<int> &vec);