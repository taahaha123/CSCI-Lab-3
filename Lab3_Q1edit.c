#include <stdio.h> 
#include <stdbool.h>
#define SIZE 24
#define nRows 8
#define nCols 3
// PROTOTYPES
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
void remove_element(int arr[],int length, int pos);
bool isValid(const int arr[], int length, int pos);
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[nRows][nCols]);
void trans_matrix(int nRows, int nCols, const int mat[nRows][nCols], int mat[nCols][ nRows]);
bool found_duplicate(int arr[],int length);

int main() {

int arr[SIZE];
int arr2d[nRows][nCols];
print_matrix(arr2d,nRows);
//Call to different functions
}

void print_array(int array[], int length){
   for(int i=0;i<length; i++)
      printf("array[%d]= %d\n", i, array[i]);
}

void print_matrix(int mat[][nCols], int rows){
   for(int i=0;i<rows; i++){
    for(int j=0;j<nCols; j++)
         printf("mat[%d][%d]= %d\n", i,j, mat[i][j]);
    puts("");     
   }     
}

//FUNCTION DEFINITIONS
bool isValid(const int arr[], int length, int pos) {
   return (pos >= 0 && pos < length);
}

void remove_element(int arr[],int length, int pos) {
   if (!isValid(arr, length, pos)) {
      printf("Invalid input %d for the array length %d", pos, length);
   }
   for (int i = pos; i <= length - 1; i++) {
      arr[i] = arr[i + 1];
   }
      
}