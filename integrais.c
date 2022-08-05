#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int quantidadePolinomios;
    printf("Digite a quantidade de membros do polinomio desejado: ");
    scanf("%d", &quantidadePolinomios);

    float bases[quantidadePolinomios], expoentes[quantidadePolinomios];
    char operacoes[quantidadePolinomios - 1];
    char escolha[quantidadePolinomios];

    printf("Digite a base do primeiro membro do polinomio: ");
    scanf("%f", &bases[0]);

    printf("%.0fx^", bases[0]);          
    scanf("%f", &expoentes[0]);

    if(quantidadePolinomios == 1)
    {
        printf("\nPolinomio computado:\n%.0fx^%.0f\nEnviando para integracao...\n\n", bases[0], expoentes[0]);

    }

    if(quantidadePolinomios > 1 && quantidadePolinomios != 1)
    {
        printf("%.0fx^%.0f ", bases[0], expoentes[0]);
        scanf("%s", &operacoes[0]);

        printf("\nSeu polinomio possui variavel ou constante no segundo termo (V/C)?: ");
        scanf("%s", &escolha[0]);

        if(escolha[0] == 'C')
        {
            printf("%.0fx^%.0f %s ", bases[0], expoentes[0], &operacoes[0]);
            scanf("%f", &bases[1]);

            if(quantidadePolinomios == 2)
            {
                printf("\nPolinomio computado:\n%.0fx^%.0f %s %.0f\nEnviando para integracao...\n\n", bases[0], expoentes[0], &operacoes[0], bases[1]);
            }
        }
    }

    system("pause");
    return 0;
}