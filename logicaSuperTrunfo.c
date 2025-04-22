#include <stdio.h>
#include <string.h>

// Protótipo da função auxiliar
float obterValor(struct Carta c, int escolha);

// Definição da estrutura para armazenar dados das cartas
struct Carta {
    char estado[3];
    int codigocarta;
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int turisticos;
    float densidade;
    float pibper;
    float superpoder;
};

int main() {
    struct Carta carta1, carta2;

    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf("%2s", carta1.estado);
    printf("Código da carta: ");
    scanf("%d", &carta1.codigocarta);
    getchar();
    printf("Cidade: ");
    fgets(carta1.cidade, 50, stdin);
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Pontos turísticos: ");
    scanf("%d", &carta1.turisticos);

    carta1.densidade = (carta1.area > 0) ? carta1.populacao / carta1.area : 0;
    carta1.pibper = (carta1.populacao > 0) ? (carta1.pib * 1000000000) / carta1.populacao : 0;
    carta1.superpoder = (float)carta1.populacao + carta1.area + carta1.pib + carta1.turisticos + carta1.pibper + (carta1.densidade > 0 ? 1 / carta1.densidade : 0);

    getchar();

    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf("%2s", carta2.estado);
    printf("Código da carta: ");
    scanf("%d", &carta2.codigocarta);
    getchar();
    printf("Cidade: ");
    fgets(carta2.cidade, 50, stdin);
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Pontos turísticos: ");
    scanf("%d", &carta2.turisticos);

    carta2.densidade = (carta2.area > 0) ? carta2.populacao / carta2.area : 0;
    carta2.pibper = (carta2.populacao > 0) ? (carta2.pib * 1000000000) / carta2.populacao : 0;
    carta2.superpoder = (float)carta2.populacao + carta2.area + carta2.pib + carta2.turisticos + carta2.pibper + (carta2.densidade > 0 ? 1 / carta2.densidade : 0);

    int escolha1, escolha2;

    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n6. PIB per Capita\n");

    do {
        printf("Digite sua escolha (1-6): ");
        scanf("%d", &escolha1);
    } while (escolha1 < 1 || escolha1 > 6);

    printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
    do {
        printf("Digite sua escolha (1-6): ");
        scanf("%d", &escolha2);
    } while (escolha2 < 1 || escolha2 > 6 || escolha2 == escolha1);

    float val1_c1 = obterValor(carta1, escolha1);
    float val1_c2 = obterValor(carta2, escolha1);
    float val2_c1 = obterValor(carta1, escolha2);
    float val2_c2 = obterValor(carta2, escolha2);

    printf("\nComparando cartas:\n");
    printf("%s vs %s\n", carta1.cidade, carta2.cidade);

    // Mostrar valores escolhidos
    printf("\nAtributo 1 (%d): Carta 1 = %.2f, Carta 2 = %.2f\n", escolha1, val1_c1, val1_c2);
    printf("Atributo 2 (%d): Carta 1 = %.2f, Carta 2 = %.2f\n", escolha2, val2_c1, val2_c2);

    // Comparações e somas
    float soma1 = val1_c1 + val2_c1;
    float soma2 = val1_c2 + val2_c2;

    printf("\nSoma dos atributos:\nCarta 1 = %.2f\nCarta 2 = %.2f\n", soma1, soma2);

    if (soma1 > soma2) {
        printf("\nCarta 1 venceu!\n");
    } else if (soma2 > soma1) {
        printf("\nCarta 2 venceu!\n");
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}

// Função auxiliar para obter o valor com base na escolha do atributo
float obterValor(struct Carta c, int escolha) {
    switch (escolha) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.turisticos;
        case 5: return c.densidade > 0 ? 1 / c.densidade : 0; // menor densidade é melhor
        case 6: return c.pibper;
        default: return 0;
    }
}
