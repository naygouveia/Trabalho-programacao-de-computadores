#include <stdio.h>

int main()
{
    // --- VARIÁVEIS DO SISTEMA ---
    int opcao;
    int presentes = 0;
    int capacidade = 15;
    int totalAcessosDia = 0;
    float valorDiaria = 25.0;
    float faturamentoTotal = 0.0;

    // --- LOOP PRINCIPAL (do/while) ---
    do
    {
        // Agora o menu apenas aparece abaixo do comando anterior
        printf("\n\n========================================\n");
        printf("              Fit Place GYM                 \n");
        printf("========================================\n");
        printf(" Alunos no local agora: %d / %d\n", presentes, capacidade);
        printf("----------------------------------------\n");
        printf(" 1. Registrar ENTRADA (Check-in)\n");
        printf(" 2. Registrar SAIDA (Check-out)\n");
        printf(" 3. Gerar RELATORIO de Ocupacao\n");
        printf(" 4. Fechamento de CAIXA\n");
        printf(" 0. Sair do Sistema\n");
        printf("----------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // --- PROCESSAMENTO DAS OPÇÕES (switch) ---
        switch (opcao)
        {
        case 1:
            if (presentes < capacidade)
            {
                presentes++;
                totalAcessosDia++;
                faturamentoTotal += valorDiaria;
                printf("\n>>> [OK] Check-in realizado!\n");
            }
            else
            {
                printf("\n>>> [AVISO] Academia lotada!\n");
            }
            break;

        case 2:
            if (presentes > 0)
            {
                presentes--;
                printf("\n>>> [OK] Check-out realizado!\n");
            }
            else
            {
                printf("\n>>> [ERRO] Nao ha alunos na academia.\n");
            }
            break;

        case 3:
            printf("\n--- RELATORIO DE OCUPACAO ATUAL ---\n");
            printf("Ocupacao: [");
            for (int i = 0; i < capacidade; i++)
            {
                if (i < presentes)
                    printf("#");
                else
                    printf(".");
            }
            printf("] %d%%\n", (presentes * 100) / capacidade);
            break;

        case 4:
            printf("\n--- RELATORIO DE FECHAMENTO ---\n");
            printf("Total de acessos hoje: %d\n", totalAcessosDia);
            printf("Faturamento: R$ %.2f\n", faturamentoTotal);
            break;

        case 0:
            printf("\nEncerrando sistema...\n");
            break;

        default:
            printf("\n[ERRO] Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}