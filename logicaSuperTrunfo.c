#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() {
    // Semente random pro computador (baseado no tempo atual)
    srand(time(0));

    // ==================== VARIÁVEIS DAS DUAS CARTAS ====================
    // Mantidas: Carta 1 = Jogador, Carta 2 = Computador
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
    // Igual: usuário cadastra ambas (Carta 1 = Jogador, Carta 2 = Computador)
    printf("=== Cadastro da Carta do Jogador (Carta 1) ===\n");
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

    printf("\n=== Cadastro da Carta do Computador (Carta 2) ===\n");
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

    // ==================== PONTUAÇÃO ACUMULADA ====================
    // Inicializa pontos totais (Jogador = Carta 1, Computador = Carta 2)
    int pontos_jogador = 0;
    int pontos_computador = 0;

    // ==================== LOOP PARA MÚLTIPLAS RODADAS ====================
    // For pra exatamente 2 rodadas
    for (int rodada = 1; rodada <= 2; rodada++) {
        printf("\n=== Rodada %d ===\n", rodada);

        // ==================== ESCOLHA DO JOGADOR ====================
        // Menu pro jogador escolher
        int opcao_jogador;
        printf("=== Menu de Comparação (Jogador) ===\n");
        printf("Escolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Número de Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("Digite sua escolha (1-5): ");
        scanf("%d", &opcao_jogador);

        // ==================== ESCOLHA DO COMPUTADOR ====================
        // Novo: computador escolhe aleatoriamente (1-5)
        int opcao_computador = rand() % 5 + 1;  // Aleatório de 1 a 5
        printf("Computador escolheu o atributo %d!\n", opcao_computador);

        // ==================== FUNÇÃO AUXILIAR PRA COMPARAR UM ATRIBUTO ====================
        // Novo: pra evitar repetir código, criei uma lógica reutilizável pra comparar qualquer opcao
        // Retorna: 1 se Jogador (Carta 1) vence, 2 se Computador (Carta 2), 0 empate
            int comparar_atributo(int op) {
            float val1 = 0.0f, val2 = 0.0f;
            int eh_densidade = (op == 5);

            switch (op) {
                case 1: val1 = (float)populacao1; val2 = (float)populacao2; break;
                case 2: val1 = area1; val2 = area2; break;
                case 3: val1 = pib1; val2 = pib2; break;
                case 4: val1 = (float)pontos1; val2 = (float)pontos2; break;
                case 5: val1 = densidade1; val2 = densidade2; break;
                default: return 0;  // Inválido (não deve acontecer)
            };

            // Ternário encadeado: maior/menor dependendo da flag, com empate
            if (eh_densidade) {
                return (val1 < val2) ? 1 : (val1 > val2) ? 2 : 0;  // Menor vence
            } else {
                return (val1 > val2) ? 1 : (val1 < val2) ? 2 : 0;  // Maior vence
            }
        };

        // ==================== COMPARAÇÕES DA RODADA ====================
        // Compara escolha do jogador
        int vencedor_jogador = comparar_atributo(opcao_jogador);
        pontos_jogador += (vencedor_jogador == 1) ? 1 : 0;
        pontos_computador += (vencedor_jogador == 2) ? 1 : 0;

        // Compara escolha do computador
        int vencedor_comp = comparar_atributo(opcao_computador);
        pontos_jogador += (vencedor_comp == 1) ? 1 : 0;
        pontos_computador += (vencedor_comp == 2) ? 1 : 0;

        // ==================== EXIBIÇÃO DA RODADA ====================
        // Mostra resultados das duas comparações
        printf("\n=== Resultados da Rodada %d ===\n", rodada);
        printf("Comparação do Jogador (atributo %d): ", opcao_jogador);
        if (vencedor_jogador == 1) printf("Jogador venceu!\n");
        else if (vencedor_jogador == 2) printf("Computador venceu!\n");
        else printf("Empate!\n");

        printf("Comparação do Computador (atributo %d): ", opcao_computador);
        if (vencedor_comp == 1) printf("Jogador venceu!\n");
        else if (vencedor_comp == 2) printf("Computador venceu!\n");
        else printf("Empate!\n");
    }

    // ==================== PONTUAÇÃO FINAL E CAMPEÃO ====================
    // Igual, mas agora Jogador vs Computador
    printf("\n=== Fim do Jogo ===\n");
    printf("Pontuação Final:\n");
    printf("Jogador (Carta 1): %d ponto(s)\n", pontos_jogador);
    printf("Computador (Carta 2): %d ponto(s)\n", pontos_computador);

    if (pontos_jogador > pontos_computador) {
        printf("Vencedor Geral: Jogador (%s)!\n", cidade1);
    } else if (pontos_computador > pontos_jogador) {
        printf("Vencedor Geral: Computador (%s)!\n", cidade2);
    } else {
        printf("Vencedor Geral: Empate!\n");
    }

    printf("======================================\n");

    return 0;
}