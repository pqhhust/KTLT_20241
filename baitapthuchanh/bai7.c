#include <stdio.h>
#include <stdlib.h>

int *a;
int n, tmp;

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    //#Allocate memory
    
    a = (int*)calloc(0, n * sizeof(int));
    
    for(int i = 0; i < n; i++)
        scanf("%d", a + i); 
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    //#Sort array
    
    int check = 1;
    for (int i = 0; i < n - 1; i++) {
        if (*(a + i) > *(a + i + 1)) {
            check = 0;
            break;
        }
    }
    if (check == 0) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (*(a + j) > *(a + j + 1)) {
                    tmp = *(a + j);
                    *(a + j) = *(a + j + 1);
                    *(a + j + 1) = tmp;
                }
            }
        }
    }
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    free(a);
    return 0;
}