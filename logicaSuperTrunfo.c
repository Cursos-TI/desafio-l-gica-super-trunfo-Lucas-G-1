#include <stdio.h>
#include <string.h>

int main() {
    // ==================== VARIÁVEIS DAS DUAS CARTAS ====================
    // Mantidas iguais: campos das cartas + cálculos
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[100], cidade2[100];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;                    // em bilhões de reais
    int pontos1, pontos2;

    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;  // Calculado, mas não usado no menu

    // ==================== CADASTRO DAS CARTAS ====================
    // Igual: lê dados do usuário
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código: ");
    scanf("%s", codigo1);
    getchar();  // Limpa buffer
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
    getchar();  // Limpa buffer
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
    // Igual: densidade e PIB per capita
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    pib_per_capita1 = (pib1 * 1e9f) / populacao1;
    pib_per_capita2 = (pib2 * 1e9f) / populacao2;

    // ==================== MENU INTERATIVO ====================
    // Igual: switch pra escolher atributo
    int opcao;
    printf("\n=== Menu de Comparação ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &opcao);

    // ==================== LÓGICA DE COMPARAÇÃO COM SWITCH E TERNÁRIO ====================
    // Integração: switch ramifica a opção, ternário decide vencedor/empate de forma compacta
    // Variáveis auxiliares pra atributo e valores
    const char *nome_atributo = "";  // Nome do atributo
    float val1 = 0.0f, val2 = 0.0f;  // Valores (float pra todos)
    int vencedor = 0;                // 1 = Carta 1, 2 = Carta 2, 0 = Empate

    switch (opcao) {
        case 1:  // População (maior vence)
            nome_atributo = "População";
            val1 = (float)populacao1;
            val2 = (float)populacao2;
            vencedor = (val1 > val2) ? 1 : (val1 < val2) ? 2 : 0;  // Ternário encadeado: maior? 1 : menor? 2 : empate
            break;

        case 2:  // Área (maior vence)
            nome_atributo = "Área";
            val1 = area1;
            val2 = area2;
            vencedor = (val1 > val2) ? 1 : (val1 < val2) ? 2 : 0;
            break;

        case 3:  // PIB (maior vence)
            nome_atributo = "PIB";
            val1 = pib1;
            val2 = pib2;
            vencedor = (val1 > val2) ? 1 : (val1 < val2) ? 2 : 0;
            break;

        case 4:  // Pontos Turísticos (maior vence)
            nome_atributo = "Número de Pontos Turísticos";
            val1 = (float)pontos1;
            val2 = (float)pontos2;
            vencedor = (val1 > val2) ? 1 : (val1 < val2) ? 2 : 0;
            break;

        case 5:  // Densidade (menor vence)
            nome_atributo = "Densidade Demográfica";
            val1 = densidade1;
            val2 = densidade2;
            vencedor = (val1 < val2) ? 1 : (val1 > val2) ? 2 : 0;  // Ternário invertido pro menor vencer
            break;

        default:  // Inválido
            printf("Opção inválida! Escolha entre 1 e 5.\n");
            return 1;
    }

    // ==================== PONTUAÇÃO SIMPLES ====================
    // Novo: usa ternário pra dar 1 ponto ao vencedor (integração com if no final)
    int pontos_carta1 = (vencedor == 1) ? 1 : 0;
    int pontos_carta2 = (vencedor == 2) ? 1 : 0;

    // ==================== EXIBIÇÃO DO RESULTADO ====================
    // Mostra comparação + pontuação final
    printf("\n======================================\n");
    printf("Comparação de cartas (Atributo: %s)\n\n", nome_atributo);

    // Formato flexível pros valores (inteiros sem decimais, floats com 2)
    if (opcao == 2 || opcao == 3 || opcao == 5) {  // Floats
        printf("Carta 1 - %s (%c): %.2f\n", cidade1, estado1, val1);
        printf("Carta 2 - %s (%c): %.2f\n\n", cidade2, estado2, val2);
    } else {  // Inteiros
        printf("Carta 1 - %s (%c): %.0f\n", cidade1, estado1, val1);
        printf("Carta 2 - %s (%c): %.0f\n\n", cidade2, estado2, val2);
    }

    // Integração: if pra mostrar resultado da rodada (com ternário já usado antes)
    if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (vencedor == 2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    // Pontuação final: integra com if pra declarar o campeão geral
    printf("\nPontuação Final:\n");
    printf("Carta 1: %d ponto(s)\n", pontos_carta1);
    printf("Carta 2: %d ponto(s)\n", pontos_carta2);

    if (pontos_carta1 > pontos_carta2) {
        printf("Campeã Geral: Carta 1 (%s)!\n", cidade1);
    } else if (pontos_carta2 > pontos_carta1) {
        printf("Campeã Geral: Carta 2 (%s)!\n", cidade2);
    } else {
        printf("Campeã Geral: Empate!\n");
    }

    printf("======================================\n");

    return 0;
}