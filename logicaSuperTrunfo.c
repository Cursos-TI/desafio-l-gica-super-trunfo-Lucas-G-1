#include <stdio.h>
#include <string.h>

int main() {
    // ==================== VARIÁVEIS DAS DUAS CARTAS ====================
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[100], cidade2[100];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;                    // em bilhões de reais
    int pontos1, pontos2;

    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;

    // ==================== CADASTRO DAS CARTAS ====================
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código: ");
    scanf("%s", codigo1);
    getchar();
    printf("Nome da Cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0';
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontos1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código: ");
    scanf("%s", codigo2);
    getchar();
    printf("Nome da Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0';
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontos2);

    // ==================== CÁLCULOS ====================
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    pib_per_capita1 = (pib1 * 1e9f) / populacao1;
    pib_per_capita2 = (pib2 * 1e9f) / populacao2;

    // ==================== ESCOLHA DO ATRIBUTO A SER COMPARADO ====================
    // Aqui você escolhe qual atributo vai ser usado na comparação.
    // Troque o comentário para mudar o atributo:
    // #define ATRIBUTO_POPULACAO
    // #define ATRIBUTO_AREA
    // #define ATRIBUTO_PIB
    // #define ATRIBUTO_DENSIDADE
    // #define ATRIBUTO_PIB_PER_CAPITA

    #define ATRIBUTO_AREA    // ←←← Estamos comparando População agora

    // ==================== COMPARAÇÃO ====================
    int carta_vencedora;
    const char *nome_atributo;
    int valor1, valor2;                     // para exibição

    #ifdef ATRIBUTO_POPULACAO
        nome_atributo = "População";
        if (populacao1 > populacao2) carta_vencedora = 1;
        else                         carta_vencedora = 2;
        valor1 = populacao1;
        valor2 = populacao2;
    #elif defined(ATRIBUTO_AREA)
        nome_atributo = "Área";
        if (area1 > area2) carta_vencedora = 1;
        else               carta_vencedora = 2;
        valor1 = (int)area1;
        valor2 = (int)area2;
    #elif defined(ATRIBUTO_PIB)
        nome_atributo = "PIB";
        if (pib1 > pib2) carta_vencedora = 1;
        else             carta_vencedora = 2;
        valor1 = (int)pib1;
        valor2 = (int)pib2;
    #elif defined(ATRIBUTO_DENSIDADE)
        nome_atributo = "Densidade Populacional";
        if (densidade1 < densidade2) carta_vencedora = 1;   // menor densidade vence
        else                         carta_vencedora = 2;
        valor1 = (int)densidade1;
        valor2 = (int)densidade2;
    #elif defined(ATRIBUTO_PIB_PER_CAPITA)
        nome_atributo = "PIB per Capita";
        if (pib_per_capita1 > pib_per_capita2) carta_vencedora = 1;
        else                                   carta_vencedora = 2;
        valor1 = (int)pib_per_capita1;
        valor2 = (int)pib_per_capita2;
    #endif

    // ==================== EXIBIÇÃO DO RESULTADO ====================
    printf("\n======================================\n");
    printf("Comparação de cartas (Atributo: %s)\n\n", nome_atributo);

    printf("Carta 1 - %s (%c): %d\n", cidade1, estado1, valor1);
    printf("Carta 2 - %s (%c): %d\n\n", cidade2, estado2, valor2);

    if (carta_vencedora == 1)
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    else
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);

    printf("======================================\n");

    return 0;
}