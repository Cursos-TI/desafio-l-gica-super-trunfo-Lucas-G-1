#include <stdio.h>
#include <string.h>

int main() {
    // ==================== VARIÁVEIS DAS DUAS CARTAS ====================
    // Mantidas iguais ao código base: uma pra cada campo das cartas
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[100], cidade2[100];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;                    // em bilhões de reais
    int pontos1, pontos2;

    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;  // Calculado, mas não usado no menu deste nível

    // ==================== CADASTRO DAS CARTAS ====================
    // Igual ao base: lê os dados das duas cartas do usuário
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código: ");
    scanf("%s", codigo1);
    getchar();  // Limpa o buffer pro fgets
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
    getchar();  // Limpa o buffer
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
    // Igual ao base: calcula densidade e PIB per capita (mesmo que PIB per capita não seja usado no menu)
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    pib_per_capita1 = (pib1 * 1e9f) / populacao1;
    pib_per_capita2 = (pib2 * 1e9f) / populacao2;

    // ==================== MENU INTERATIVO ====================
    // Novo: menu pro usuário escolher o atributo usando switch
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

    // ==================== LÓGICA DE COMPARAÇÃO COM SWITCH ====================
    // Usamos switch pra decidir qual atributo comparar
    // Dentro de cada case: if-else encadeado pra determinar vencedor ou empate
    // Variáveis auxiliares pra nome do atributo e valores (pra exibição flexível)
    const char *nome_atributo = "";  // Nome do atributo escolhido
    float val1 = 0.0f, val2 = 0.0f;  // Valores do atributo (usamos float pra cobrir todos)
    int vencedor = 0;                // 1 = Carta 1, 2 = Carta 2, 0 = Empate

    switch (opcao) {
        case 1:  // População (maior vence)
            nome_atributo = "População";
            val1 = (float)populacao1;
            val2 = (float)populacao2;
            if (val1 > val2) {
                vencedor = 1;
            } else if (val1 < val2) {
                vencedor = 2;
            } else {
                vencedor = 0;  // Empate
            }
            break;

        case 2:  // Área (maior vence)
            nome_atributo = "Área";
            val1 = area1;
            val2 = area2;
            if (val1 > val2) {
                vencedor = 1;
            } else if (val1 < val2) {
                vencedor = 2;
            } else {
                vencedor = 0;
            }
            break;

        case 3:  // PIB (maior vence)
            nome_atributo = "PIB";
            val1 = pib1;
            val2 = pib2;
            if (val1 > val2) {
                vencedor = 1;
            } else if (val1 < val2) {
                vencedor = 2;
            } else {
                vencedor = 0;
            }
            break;

        case 4:  // Pontos Turísticos (maior vence)
            nome_atributo = "Número de Pontos Turísticos";
            val1 = (float)pontos1;
            val2 = (float)pontos2;
            if (val1 > val2) {
                vencedor = 1;
            } else if (val1 < val2) {
                vencedor = 2;
            } else {
                vencedor = 0;
            }
            break;

        case 5:  // Densidade Demográfica (menor vence)
            nome_atributo = "Densidade Demográfica";
            val1 = densidade1;
            val2 = densidade2;
            if (val1 < val2) {
                vencedor = 1;
            } else if (val1 > val2) {
                vencedor = 2;
            } else {
                vencedor = 0;
            }
            break;

        default:  // Opção inválida (segurança)
            printf("Opção inválida! Escolha entre 1 e 5.\n");
            return 1;  // Sai do programa com erro (pode mudar pra repetir o menu se quiser)
    }

    // ==================== EXIBIÇÃO DO RESULTADO ====================
    // Mostra o resultado da comparação, com nomes, valores e vencedor/empate
    printf("\n======================================\n");
    printf("Comparação de cartas (Atributo: %s)\n\n", nome_atributo);

    // Exibe valores com formato apropriado (inteiros sem decimais, floats com 2 casas)
    if (opcao == 2 || opcao == 3 || opcao == 5) {  // Floats
        printf("Carta 1 - %s (%c): %.2f\n", cidade1, estado1, val1);
        printf("Carta 2 - %s (%c): %.2f\n\n", cidade2, estado2, val2);
    } else {  // Inteiros
        printf("Carta 1 - %s (%c): %.0f\n", cidade1, estado1, val1);
        printf("Carta 2 - %s (%c): %.0f\n\n", cidade2, estado2, val2);
    }

    if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (vencedor == 2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    printf("======================================\n");

    return 0;
}