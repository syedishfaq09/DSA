#include<stdio.h>
int main () {
    int arr1[2][2] = {{1,1},{1,1}};
    int arr2[2][2] = {{2,2},{2,2}};

    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {

        int mul[i][j];
        mul[i][j] = arr1[i][j] * arr2[i][j];
        printf("%d ",mul[i][j]);
    }
    printf("\n");
}
}