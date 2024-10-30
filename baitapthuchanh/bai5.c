double* maximum(double* a, int size){
    double *max;
    max = a;
    if (a==NULL) return NULL;
    double *tmp = a;
    for (int i = 0; i < size; i++) {
        if (*tmp > *max) max = tmp;
        tmp++;
    }
    
    return max;
}
