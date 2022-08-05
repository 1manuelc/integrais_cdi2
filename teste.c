#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int numA, numB, resultado;
    scanf("%d%d", &numA, &numB);
    resultado = pow(numA, numB);
    printf("%d", &resultado);

    
    system("pause");
    return 0;
}