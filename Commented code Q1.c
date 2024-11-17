#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool isValid(const int arr[], int length, int pos);
void remove_element(int arr[], int length, int pos);
void insert_element(int arr[], int length, int pos, int value);
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[][3]);
void trans_matrix(int nRows, int nCols, const int mat[][3], int mat_transp[][2]);
bool found_duplicate(int arr[], int length);

int main() {
    int arr[5] = {10, 20, 30, 40, 50}; // Original 1D array of size 5
    int arr2d[2][3];        // 2D array of 2 rows and 3 coloumns

    printf("1. Adjusting positions and elements in an array: \n\n");
    // Display the original array
    printf("Initial array contents: ");
    for (int i = 0; i < 5; i++) {            // looped through all the elements of the array for displaying
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Check validity of positions
    printf("Check validity of positions: ");
    printf("isValid(arr, 5, 2): %s, isValid(arr, 5, 5): %s\n", 
           isValid(arr, 5, 2) ? "Yes" : "No", 
           isValid(arr, 5, 5) ? "Yes" : "No");

    // remove_element function
    printf("Removing element at index 2...\n");
    remove_element(arr, 5, 2);
    printf("Array after removal: ");       // looped through all the elements of the array for displaying
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reset array for inserting a number of the original array
    int arr_test[5] = {10, 20, 30, 40, 50};

    // insert_element function
    int value_to_insert = 80;
    int pos_to_insert = 2;
    printf("Inserting %d at index %d...\n", value_to_insert, pos_to_insert);
    insert_element(arr_test, 5, pos_to_insert, value_to_insert);
    printf("Array after insertion: ");
    for (int i = 0; i < 5; i++) {                   // looped through all the elements of the array for displaying
        printf("%d ", arr_test[i]);
    }
    printf("\n\n");
    printf("2. Reshaping a 1D Array to a 2D Array:\n\n");

    // Display the 1D array before reshaping
    int arr1d[6] = {4, 5, 6, 7, 8, 9};
    printf("Array in 1D format: ");      
    for (int i = 0; i < 6; i++) {                      // looped through all the elements of the array for displaying
        printf("%d ", arr1d[i]);
    }
    printf("\n");

    // reshape function
    printf("Reshaping the 1D array to 2D...\n");
    reshape(arr1d, 6, 2, 3, arr2d);
    printf("Reshaped 2D array:\n");
    for (int i = 0; i < 2; i++) {                // looped through all the elements of the array for displaying
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }

    // function to transpore matrix
    int mat[2][3] = {{4, 5, 6}, {7, 8, 9}};
    int mat_transp[3][2];
    printf("Transposing matrix...\n");
    trans_matrix(2, 3, mat, mat_transp);
    printf("Transposed matrix:\n");
    for (int i = 0; i < 3; i++) {                        // looped through all the elements of the array for displaying
        for (int j = 0; j < 2; j++) {
            printf("%d ", mat_transp[i][j]);
        }
        printf("\n");
    }

    // Test found_duplicate function
    int arr_with_duplicates[5] = {1, 2, 3, 2, 5};
    printf("Checking for duplicates...\n");
    printf("Duplicates found in arr_with_duplicates: %s\n", 
           found_duplicate(arr_with_duplicates, 5) ? "Yes" : "No");
    printf("Duplicates found in arr: %s\n", 
           found_duplicate(arr, 5) ? "Yes" : "No");

    return 0;
}

// Function to check if the position is valid within the array
bool isValid(const int arr[], int length, int pos) {
    return (pos >= 0 && pos < length);
}

// Function to remove an element from the array
void remove_element(int arr[], int length, int pos) {
    if (!isValid(arr, length, pos)) {
        printf("Invalid position for removal.\n");
        return;
    }
    for (int i = pos; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = arr[0];  // Keep the first element unchanged
}

// Function to insert an element into the array
void insert_element(int arr[], int length, int pos, int value) {
    if (!isValid(arr, length, pos)) {
        printf("Invalid position for insertion.\n");
        return;
    }
    for (int i = 0; i < pos; i++) {
        arr[i] = arr[i + 1];
    }
    arr[pos] = value;
}

// Function to reshape a 1D array into a 2D array
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[][3]) {
    if (length != nRows * nCols) {
        printf("Error: 1D array size does not match 2D array dimensions.\n");
        return;
    }
    int index = 0;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            arr2d[i][j] = arr[index++];
        }
    }
}

// Function to transpose a matrix
void trans_matrix(int nRows, int nCols, const int mat[][3], int mat_transp[][2]) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            mat_transp[j][i] = mat[i][j];
        }
    }
}

// Function to check for duplicates in the array
bool found_duplicate(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) return true;
        }
    }
    return false;
}