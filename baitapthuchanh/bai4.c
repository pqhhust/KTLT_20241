int counteven(int* arr, int size){
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (*arr % 2 == 0) count++;
        arr++;
    }
    return count;    
}