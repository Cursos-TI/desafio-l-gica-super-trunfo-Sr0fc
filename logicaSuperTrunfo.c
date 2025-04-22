#include <stdio.h>

int main() {
    // Estrutura de dados para duas cartas
    char estado[2][3];     // Estado como string (ex: "SP")
    int codigocarta[2];    // Código numérico da carta
    char cidade[2][50];    // Nome da cidade
    unsigned long int populacao[2]; // Número da população
    float area[2];         // Área da cidade
    float pib[2];          // PIB da cidade
    int turisticos[2];     // Número de pontos turísticos
    float densidadepopulacional[2];   // Densidade populacional
    float pibper[2];       // PIB per capita
    float superPoder[2];   // Super Poder

    // Cadastro das duas cartas
    for (int i = 0; i < 2; i++) {
        printf("\nCadastro da Carta %d:\n", i + 1);
        printf("Digite a sigla do estado (ex: SP, RJ): ");
        scanf("%2s", estado[i]);

        printf("Digite o código da carta: ");
        scanf("%d", &codigocarta[i]);
        getchar(); // Limpa o buffer do Enter após o scanf anterior

        printf("Digite o nome da cidade: ");
        fgets(cidade[i], 50, stdin);

        printf("Digite o número da população: ");
        scanf("%lu", &populacao[i]);

        printf("Informe a área (km²): ");
        scanf("%f", &area[i]);

        printf("Informe o PIB (em bilhões): ");
        scanf("%f", &pib[i]);

        printf("Quantidade de pontos turísticos: ");
        scanf("%d", &turisticos[i]);
    }

    // Cálculo dos atributos derivados
    for (int i = 0; i < 2; i++) {
        densidadepopulacional[i] = (area[i] > 0) ? (populacao[i] / area[i]) : 0;
        pibper[i] = (populacao[i] > 0) ? (pib[i] * 1e9) / populacao[i] : 0;
        superPoder[i] = populacao[i] + area[i] + (pib[i] * 1e9) + turisticos[i] + pibper[i] + (1.0 / (densidadepopulacional[i] + 1));
    }

    // Menu interativo
    int opcao;
    printf("\nMenu de Comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Escolha o atributo para comparar (1-5): ");
    scanf("%d", &opcao);

    printf("\nComparando %s e %s\n", cidade[0], cidade[1]);

    switch(opcao) {
        case 1:
            printf("Atributo: Populacao\n");
            printf("%s: %lu\n", cidade[0], populacao[0]);
            printf("%s: %lu\n", cidade[1], populacao[1]);
            if (populacao[0] > populacao[1]) {
                printf("Vencedora: %s\n", cidade[0]);
            } else if (populacao[1] > populacao[0]) {
                printf("Vencedora: %s\n", cidade[1]);
            } else {
                printf("Empate!\n");
            }
            break;
        case 2:
            printf("Atributo: Area\n");
            printf("%s: %.2f km²\n", cidade[0], area[0]);
            printf("%s: %.2f km²\n", cidade[1], area[1]);
            if (area[0] > area[1]) {
                printf("Vencedora: %s\n", cidade[0]);
            } else if (area[1] > area[0]) {
                printf("Vencedora: %s\n", cidade[1]);
            } else {
                printf("Empate!\n");
            }
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", cidade[0], pib[0]);
            printf("%s: %.2f bilhões\n", cidade[1], pib[1]);
            if (pib[0] > pib[1]) {
                printf("Vencedora: %s\n", cidade[0]);
            } else if (pib[1] > pib[0]) {
                printf("Vencedora: %s\n", cidade[1]);
            } else {
                printf("Empate!\n");
            }
            break;
        case 4:
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d\n", cidade[0], turisticos[0]);
            printf("%s: %d\n", cidade[1], turisticos[1]);
            if (turisticos[0] > turisticos[1]) {
                printf("Vencedora: %s\n", cidade[0]);
            } else if (turisticos[1] > turisticos[0]) {
                printf("Vencedora: %s\n", cidade[1]);
            } else {
                printf("Empate!\n");
            }
            break;
        case 5:
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.2f hab/km²\n", cidade[0], densidadepopulacional[0]);
            printf("%s: %.2f hab/km²\n", cidade[1], densidadepopulacional[1]);
            if (densidadepopulacional[0] < densidadepopulacional[1]) {
                printf("Vencedora: %s\n", cidade[0]);
            } else if (densidadepopulacional[1] < densidadepopulacional[0]) {
                printf("Vencedora: %s\n", cidade[1]);
            } else {
                printf("Empate!\n");
            }
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }

    return 0;
}
