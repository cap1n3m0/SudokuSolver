#include <iostream> 
#include <vector> 
#include <iterator> 
#include <set> 
#include <map> 

const int SIZE = 9; 

void check(int grid[SIZE][SIZE], int possibleNumber, int rowNumber, int colNumber, bool& flag) {
    for (int colCheck = 0; colCheck < SIZE; colCheck++) {
        if (grid[rowNumber][colCheck] == possibleNumber) {
            flag = true; 
            // std::cout << "Cannot use the number " << possibleNumber << "\n"; 
            return; 
        }      
    } 
    for (int rowCheck = 0; rowCheck < SIZE; rowCheck++) {
        if (grid[rowCheck][colNumber] == possibleNumber) {
            flag = true; 
            // std::cout << "Cannot use the number " << possibleNumber << "\n"; 
            std::cout << grid[rowCheck][colNumber] << " is equal to " << possibleNumber << "\n"; 
            return; 
        }      
    } 
}

void place(int grid[SIZE][SIZE], int rowNumber, int colNumber) {
    bool flag = false; 
    for (int possibleNumber = 1; possibleNumber < SIZE; possibleNumber++) {
        check(grid, possibleNumber, rowNumber, colNumber, flag); 
        if (!flag) {
            grid[rowNumber][colNumber] = possibleNumber; 
            return; 
        }
    }
}

void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << grid[i][j] << " "; 
        }
        std::cout << std::endl; 
    }   
}

void solve(int grid[SIZE][SIZE]) {
    for (int missingCellX = 0; missingCellX < SIZE; missingCellX++) {
        for (int missingCellY = 0; missingCellY < SIZE; missingCellY++) {
            if (grid[missingCellX][missingCellY] == 0) {
                std::cout << "is replacing " << missingCellX << ", " << missingCellY << std::endl;
                place(grid, missingCellX, missingCellY); 
            }
        }
    }
    printGrid(grid); 
    return; 
}

int main() {
    int grid[SIZE][SIZE] = 
        {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };  
    // std::cout << grid[3][0] << std::endl; 
    solve(grid); 
    return 0; 
}