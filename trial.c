#include <stdio.h>

int main(){
unsigned int matrix[3] = {4,5,9};
unsigned int sum = 0;
for(unsigned int i = 0; i < 3; i++){
    sum += matrix[i]*matrix[i];
}
printf("%u", sum);
return 0;
}
