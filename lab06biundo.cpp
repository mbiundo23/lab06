#include <iostream>
#include <fstream>

const int MAX_SIZE = 100; // Define MAX_SIZE as a constant

void readFiletoMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size, const std::string &filename);
void printMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size);
void addMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size);
void subtractMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size);
void multiplyMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size);

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int size;
    std::string userInput;
    std::cout << "Enter a file: ";
    std::cin >> userInput;
    readFiletoMatrix(matrix1, matrix2, size, userInput);
    printMatrix(matrix1, matrix2, size);
    addMatrix(matrix1, matrix2, size);
    subtractMatrix(matrix1, matrix2, size);
    multiplyMatrix(matrix1, matrix2, size);
    return 0;
}

void readFiletoMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size, const std::string &filename) {
    std::ifstream MyFile(filename);
    MyFile >> size;
    if(!MyFile){
        std::cerr <<"Error opening file " << filename <<std::endl;
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            MyFile >> matrix1[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            MyFile >> matrix2[i][j];
        }
    }
}

void printMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size){
    std::cout << "Matrix One\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Matrix Two\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::right << matrix2[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void addMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size){

    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    std::cout << "Matrix Sum(A + B):\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void subtractMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size){

    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    
    std::cout << "Matrix Difference(A - B):\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void multiplyMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size){

    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
    
    std::cout << "Matrix Product(A + B):\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
}