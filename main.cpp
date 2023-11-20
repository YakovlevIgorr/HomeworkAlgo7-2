#include <iostream>
#include <fstream>


void open(int* array[], int size_array){

    std::ifstream input;
    input.open("input.txt");
    if(input) {
        input.seekg(2, std::ios_base::beg);
        for (int i = 0; i < size_array; i++) {
            for (int k = 0; k < size_array; k++) {
                input >> array[i][k];
            }
        }
    }else std::cout << "Error open file";

}

void deep(int* array[], int* array_count, int size_array, int pic){//Порядок обхода вершин: 5 4 7 2 1 3 6
    array_count[0] = pic;//1 3 6 7 2 5 4
    int count = 1;
    bool position_bool = true;

    for(int i = 0; i < size_array; i++){
        for(int k = 0; k < size_array; k++){

            if(array[k][pic - 1] == 1){//hповерка на повтор
                for(int j = 0; j < count; j++){
                    if(array_count[j] == k + 1){
                        position_bool = false;
                        break;
                    }
                }
                if(position_bool){
                    array_count[count] = k + 1;
                    count++;
                }else position_bool = true;
            }

        }
        pic = array_count[count - 1];
    }

}


void print(int* array[], int size_array){
    for(int i = 0; i < size_array; i++){
        for(int k = 0; k < size_array; k++) {
            std::cout << array[i][k] << "  ";
        }
        std::cout << "\n";
    }
}

void print_array(int* array, int size){
    std::cout << "Порядок обхода вершин: ";
    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int size_array;
    std::ifstream input;
    input.open("input.txt");
    input >> size_array;


    int* array_count = new int[size_array];
    int pic;//с какой вершины начать поиск
    int** array = new int*[size_array];

    while (true) {
        std::cout << "Введите вершину с которой начнется обход граф в ширину ";
        std::cin >> pic;
        if(pic > 0 || pic < size_array) break;
    }

    for(int i = 0; i < size_array; i++){
        array[i] = new int[size_array];
    }

    open(array, size_array);
    //print(array, size_array);
    deep(array, array_count,size_array, pic);
    print_array(array_count,size_array);
    //print(array, size_array);

    delete[] array_count;
    for(int i = 0; i < size_array; i++){
        delete[] array[i];
    }
    delete[] array;

    return 0;
}