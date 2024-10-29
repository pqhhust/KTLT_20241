void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
    
    for (int i = 0; i <= (l + r) / 2; i++) {
        tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }
    
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    
    for (int i = 0; i <= (l + r) / 2; i++) {
        tmp = *(arr + i);
        *(arr + i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = tmp;
    }
}