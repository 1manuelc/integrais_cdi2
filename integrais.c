#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define ANIM for(int i = 0; i <= 100; i += 10) { printf("Calculando: %d%%", i); for(int j = 0; j < 12; j++) { printf("."); Sleep(20);}printf("\r"); for(int k = 0; k < 28; k++) { printf(" "); }printf("\r");}
#define ZERAR_BASES_EXPOENTES float bases[4] = {0, 0, 0, 0}, expoentes[4] = {0, 0, 0, 0};
#define ZERAR_CARACTERES char operacoes[3] = {'0', '0', '0'}, escolha[3] = {'0', '0', '0'};
char continuar = '0';

int getTermos() {
    int quantidadePolinomios = 0;
    printf("Digite a quantidade de termos do polinomio desejado: ");
    scanf("%d", &quantidadePolinomios);

    while((quantidadePolinomios == 0) | (quantidadePolinomios < 0))
    {
        printf("Quantidade de termos invalida, digite novamente: \n");
        scanf("%d", &quantidadePolinomios);
    }
    return(quantidadePolinomios);
}
float getRetangulos() {
    float quantidadeRetangulos = 0;
    printf("Quantidade de retangulos: ");
    scanf("%f", &quantidadeRetangulos);

    while((quantidadeRetangulos == 0) | (quantidadeRetangulos < 0))
        {
            printf("Quantidade de retangulos invalida, digite novamente\n");
            printf("Digite a quantidade de retangulos: ");
            scanf("%f", &quantidadeRetangulos);
        }
    return(quantidadeRetangulos);
}
float getIntervalo1() {
    float intervaloInicial = 0;
    printf("Intervalo Inicial: ");
    scanf("%f", &intervaloInicial);
    return(intervaloInicial);
}
float getIntervalo2() {
    float intervaloFinal = 0;
    printf("Intervalo Final: ");
    scanf("%f", &intervaloFinal);
    return(intervaloFinal);
}

int main() {
    do {   
        int quantidadePolinomios = getTermos(quantidadePolinomios);

        continuar = '0';
        ZERAR_BASES_EXPOENTES;
        ZERAR_CARACTERES;

        printf("Digite a base do primeiro membro do polinomio: ");
        scanf("%f", &bases[1]);

        printf("%.0fx^", bases[1]);
        scanf("%f", &expoentes[1]);

        if(quantidadePolinomios == 1) {   
            system("cls");
            printf("\nPolinomio computado:\n%.0fx^%.0f\nEnviando para integracao...\n\n", bases[1], expoentes[1]);
        }

        if(quantidadePolinomios == 2) {
            printf("%.0fx^%.0f ", bases[1], expoentes[1]);
            scanf("%s", &operacoes[1]);

            printf("\nSeu polinomio possui variavel ou constante no segundo termo (V/C)?: ");
            scanf("%s", &escolha[1]);

            if(escolha[1] == 'C') {
                printf("%.0fx^%.0f %s ", bases[1], expoentes[1], &operacoes[1]);
                scanf("%f", &bases[2]);
                system("cls");
                printf("\nPolinomio computado:\n%.0fx^%.0f %s %.0f\nEnviando para integracao...\n\n", bases[1], expoentes[1], &operacoes[1], bases[2]);
            }

            if(escolha[1] == 'V') {
                printf("%.0fx^%.0f %s ", bases[1], expoentes[1], &operacoes[1]);
                scanf("%f", &bases[2]);
                printf("%.0fx^%.0f %s %.0fx^", bases[1], expoentes[1], &operacoes[1], bases[2]);
                scanf("%f", &expoentes[2]);

                system("cls");
                printf("\nPolinomio computado:\n%.0fx^%.0f %s %.0fx^%.0f\nEnviando para integracao...\n\n", bases[1], expoentes[1], &operacoes[1], bases[2], expoentes[2]);
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        float quantidadeRetangulos = getRetangulos(quantidadeRetangulos);
        float intervaloInicial = getIntervalo1(intervaloInicial);
        float intervaloFinal = getIntervalo2(intervaloFinal);
        float baseComum = (intervaloFinal - intervaloInicial) / quantidadeRetangulos;
        printf("\nTamanho das bases: %.2f\n", baseComum);

        ANIM;

        float calculoAtual = 0, acumuladorSomaDeAreas = 0;
        for(float i = intervaloInicial + baseComum; i <= intervaloFinal; i += baseComum)
        {
            if(quantidadePolinomios == 1) {
                calculoAtual = (bases[1] * (pow(i, expoentes[1]))) * baseComum;
                acumuladorSomaDeAreas += calculoAtual;
            }

            if(quantidadePolinomios == 2) {
                if(escolha[1] == 'C') {
                    switch(operacoes[1]) {
                        case '+':
                        calculoAtual = (((bases[1] * (pow(i, expoentes[1]))) + bases[2]) * baseComum);
                        acumuladorSomaDeAreas += calculoAtual;
                        break;

                        case '-':
                        calculoAtual = (((bases[1] * (pow(i, expoentes[1]))) - bases[2]) * baseComum);
                        acumuladorSomaDeAreas += calculoAtual;
                        break;

                        case '*':
                        calculoAtual = (((bases[1] * (pow(i, expoentes[1]))) * bases[2]) * baseComum);
                        acumuladorSomaDeAreas += calculoAtual;
                        break;

                        case '/':
                        if(bases[2] != 0) {
                            calculoAtual = (((bases[1] * (pow(i, expoentes[1]))) / bases[2]) * baseComum);
                            acumuladorSomaDeAreas += calculoAtual;
                        }
                        break;
                    }
                }

                if(escolha[1] == 'V') {
                    switch(operacoes[1]) {
                        case '+':
                        calculoAtual = ((bases[1] * (pow(i, expoentes[1]))) * baseComum) + ((bases[2] * (pow(i, expoentes[2]))) * baseComum);
                        acumuladorSomaDeAreas += calculoAtual;
                        break;

                        case '-':
                        calculoAtual = ((bases[1] * (pow(i, expoentes[1]))) * baseComum) - ((bases[2] * (pow(i, expoentes[2]))) * baseComum);
                        acumuladorSomaDeAreas += calculoAtual;
                        break;

                        case '*':
                        calculoAtual = ((bases[1] * (pow(i, expoentes[1]))) * baseComum) * ((bases[2] * (pow(i, expoentes[2]))) * baseComum);
                        acumuladorSomaDeAreas += calculoAtual;
                        break;

                        case '/':
                        if(bases[2] != 0) {
                            calculoAtual = ((bases[1] * (pow(i, expoentes[1]))) * baseComum) / ((bases[2] * (pow(i, expoentes[2]))) * baseComum);
                            acumuladorSomaDeAreas += calculoAtual;
                        } else {
                            printf("Nao foi possivel dividir, pois seu denominador e = 0");
                        }
                        break;

                    }
                }
            }
        }

        printf("\nR%.0f = %.2f\n\n", quantidadeRetangulos, acumuladorSomaDeAreas);

        printf("Deseja calcular novamente, com outro polinomio?\a (S/N): ");
        scanf("%s", &continuar);
        if(continuar == 'S') {
            system("cls");}

    } while (continuar == 'S');
    
    return 0;
}
