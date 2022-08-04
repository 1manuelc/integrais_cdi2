#include <stdio.h>
#include <stdlib.h>

int main()
{
    float quantidadeRetangulos, intervalo[1], acumuladorAreaTotal;

    printf("Digite a quantidade de Retangulos: ");
    scanf("%f", &quantidadeRetangulos);  

    printf("Digite o ponto inicial do intervalo: ");
    scanf("%f", &intervalo[0]);

    printf("Digite o ponto final do intervalo: ");
    scanf("%f", &intervalo[1]);

    for(float i = intervalo[0]; i <= intervalo[1]; )
    {
        printf("%f", i);
    }


    system("pause");
    return 0;
}