#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int quantidadePolinomios;
    printf("Digite a quantidade de termos do polinomio desejado: ");
    scanf("%d", &quantidadePolinomios);

    while(quantidadePolinomios == 0 | quantidadePolinomios < 0)
    {
        printf("Quantidade de termos invalida, digite novamente\n");
        printf("Digite a quantidade de termos do polinomio desejado: ");
        scanf("%d", &quantidadePolinomios);
    }

    float bases[quantidadePolinomios], expoentes[quantidadePolinomios];
    char operacoes[quantidadePolinomios - 1];
    char escolha[quantidadePolinomios];

    printf("Digite a base do primeiro membro do polinomio: ");
    scanf("%f", &bases[1]);

    printf("%.0fx^", bases[1]);          
    scanf("%f", &expoentes[1]);

    
    if(quantidadePolinomios == 1)
    {
        printf("\nPolinomio computado:\n%.0fx^%.0f\nEnviando para integracao...\n\n", bases[1], expoentes[1]);

    }

    if(quantidadePolinomios > 1 && quantidadePolinomios != 1)
    {
        printf("%.0fx^%.0f ", bases[1], expoentes[1]);
        scanf("%s", &operacoes[1]);

        if(quantidadePolinomios == 2)
        {
            printf("\nSeu polinomio possui variavel ou constante no segundo termo (V/C)?: ");
            scanf("%s", &escolha[1]);

            if(escolha[1] == 'C')
            {
                printf("%.0fx^%.0f %s ", bases[1], expoentes[1], &operacoes[1]);
                scanf("%f", &bases[2]);

                printf("\nPolinomio computado:\n%.0fx^%.0f %s %.0f\nEnviando para integracao...\n\n", bases[1], expoentes[1], &operacoes[1], bases[2]);
            }

            if(escolha[1] == 'V')
            {
                printf("%.0fx^%.0f %s ", bases[1], expoentes[1], &operacoes[1]);
                scanf("%f", &bases[2]);

                printf("%.0fx^%.0f %s %.0fx^", bases[1], expoentes[1], &operacoes[1], bases[2]);
                scanf("%f", &expoentes[2]);

                printf("\nPolinomio computado:\n%.0fx^%.0f %s %.0fx^%.0f\nEnviando para integracao...\n\n", bases[1], expoentes[1], &operacoes[1], bases[2], expoentes[2]);
            }
            
        }

        if(quantidadePolinomios == 3)
        {
            printf("%.0fx^%.0f %s ", bases[1], expoentes[1], &operacoes[1]);
            scanf("%f", &bases[2]);

            printf("%.0fx^%.0f %s %.0fx^", bases[1], expoentes[1], &operacoes[1], bases[2]);
            scanf("%f", &expoentes[2]);

            printf("%.0fx^%.0f %s %.0fx^%.0f ", bases[1], expoentes[1], &operacoes[1], bases[2], expoentes[2]);
            scanf("%s", &operacoes[2]);

            printf("\nSeu polinomio possui variavel ou constante no terceiro termo (V/C)?: ");
            scanf("%s", &escolha[2]);

            if(escolha[2] == 'C')
            {
                printf("%.0fx^%.0f %.1s %.0fx^%.0f %s ", bases[1], expoentes[1], &operacoes[1], bases[2], expoentes[2], &operacoes[2]);
                scanf("%f", &bases[3]);

                printf("\nPolinomio computado:\n%.0fx^%.0f %.1s %.0fx^%.0f %s %.0f\nEnviando para integracao...\n\n", bases[1], expoentes[1], &operacoes[1], bases[2], expoentes[2], &operacoes[2], bases[3]); 
            }

            if(escolha[2] == 'V')
            {
                printf("%.0fx^%.0f %.1s %.0fx^%.0f %s ", bases[1], expoentes[1], &operacoes[1], bases[2], expoentes[2], &operacoes[2]);
                scanf("%f", &bases[3]);

                printf("%.0fx^%.0f %.1s %.0fx^%.0f %s %.0fx^", bases[1], expoentes[1], &operacoes[1], bases[2], expoentes[2], &operacoes[2], bases[3]);
                scanf("%f", &expoentes[3]);

                printf("\nPolinomio computado:\n%.0fx^%.0f %.1s %.0fx^%.0f %s %.0fx^%.0f\nEnviando para integracao...\n\n", bases[1], expoentes[1], &operacoes[1], bases[2], expoentes[2], &operacoes[2], bases[3], expoentes[3]);
            }
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    float quantidadeRetangulos, intervaloInicial, intervaloFinal, baseComum;
    
    printf("Quantidade de retangulos: ");
    scanf("%f", &quantidadeRetangulos);

    while(quantidadeRetangulos == 0 | quantidadeRetangulos < 0)
    {
        printf("Quantidade de retangulos invalida, digite novamente\n");
        printf("Digite a quantidade de retangulos: ");
        scanf("%f", &quantidadeRetangulos);
    }

    printf("Intervalo Inicial: ");
    scanf("%f", &intervaloInicial);

    printf("Intervalo Final: ");
    scanf("%f", &intervaloFinal);

    baseComum = intervaloFinal / quantidadeRetangulos;
    printf("\nTamanho das bases e: %.2f\n", baseComum);

    float calculoAtual = 0, acumuladorAreas = 0;
    for(int i = 0; i <= intervaloFinal; baseComum++)
    {
       if(quantidadePolinomios == 1)
       {
        calculoAtual = bases[1] *  pow(baseComum, expoentes[1]);
        acumuladorAreas += calculoAtual;
        calculoAtual = 0;
       } 
    } 

    printf("%.2f", &acumuladorAreas);

    system("pause");
    return 0;
}