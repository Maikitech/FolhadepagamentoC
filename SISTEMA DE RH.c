#include <stdio.h>
#include <string.h>

int main()
{
    int menu1, menu2;
    char razaoSocial[50];
    char cnpj[20];
    char endereco[50];
    int mesAtual;
    char nomeCompleto[30];
    char cargo[20];
    int mesAniversario;
    char mensagemAniversario[50];
    int numHorastrabalhadas;
    float valorHora;
    float somaNormal = 0.0;
    float adicional25 = 0.0;
    float adicional50 = 0.0;
    float salarioBruto = 0.0;
    int horasNormais = 220;
    int horasExcedentes25 = 0;
    int horasExcedentes50 = 0;
    float inss = 0.0;
    float salarioLiquidoinss;
    float irpf = 0.0;
    float salarioLiquidoirpf;
    float totalDescontos;
    char faixa[50];
    printf("\n=====   BEM-VINDO AO SISTEMA DE RH !   ===\n\n");
    do
    {

        printf("\n=====   PROGRAMA FOLHA DE PAGAMENTO   ====\n\n");
        printf("\n====   Digite uma opcao abaixo:   =======\n\n");
        printf("     1) - Cadastrar os dados da empresa:     \n");
        printf("     2) - Calcular o salario mensal:         \n");
        printf("     3) - Imprimir o Contracheque:           \n");
        printf("     4) - Sair do programa:                \n\n");
        printf("============================================\n\n");
        scanf("%i", &menu1);
        getchar();

        switch (menu1)
        {
        case 1:
            printf("\nCERTO! VAMOS CADASTRAR OS DADOS DA SUA EMPRESA !\n\n");
            printf("Pimeiramente digite a razao social da sua empresa:\n");
            fgets(razaoSocial, sizeof(razaoSocial), stdin);
            razaoSocial[strcspn(razaoSocial, "\n")] = '\0';

            printf("Agora digite o CNPJ:(SOMENTE NUMEROS)\n");
            fgets(cnpj, sizeof(cnpj), stdin);
            cnpj[strcspn(cnpj, "\n")] = '\0';

            printf("E por fim digite o endereco da sua empresa:\n");
            fgets(endereco, sizeof(endereco), stdin);

            printf("\nCADASTRO CONCLUIDO COM SUCESSO ! \n\n");

            break;

        case 2:
            printf("\nOK, VOCE SELECIONOU A OPCAO - CALCULAR SALARIO  MENSAL!\n\n");
            printf("\nPRIMEIRAMENTE VAMOS PRECISAR DE ALGUMAS INFORMACOES, VAMOS LA ?  \n\n");
            printf("Digite o mes atual:(EX: '01' para Janeiro)\n");
            scanf("%i", &mesAtual);
            getchar();

            printf("Digite o nome completo do funcionario: (EX: NOMESOBRENOME )\n");
            fgets(nomeCompleto, sizeof(nomeCompleto), stdin);
            nomeCompleto[strcspn(nomeCompleto, "\n")] = 0;

            printf("Digite o cargo do funcionario: (EX: CARGOCOMPLETO )\n");
            fgets(cargo, sizeof(cargo), stdin);
            cargo[strcspn(cargo, "\n")] = 0;

            printf("Digite o mes em que nasceu: (EX: '01' para Janeiro)\n");
            scanf("%i", &mesAniversario);
            getchar();

            printf("Digite o numero de horas trabalhadas: (SOMENTE NUMEROS)\n");
            scanf("%i", &numHorastrabalhadas);
            getchar();

            printf("Digite o valor de cada hora trabalhada desse funcionario:(EX: 15)\n");
            scanf("%f", &valorHora);
            getchar();
            printf("\nCADASTRO CONCLUIDO COM SUCESSO ! \n\n");

            do
            {
                printf("\n   OLA, VOCE ESTA NO MENU DE CALCULO ! \n\n");
                printf("\n                VAMOS COMECAR ?            \n\n");
                printf("\n   DIGITE A OPCAO DESEJADA ABAIXO:\n\n");
                printf("1) - Calcular salario bruto mensal: \n");
                printf("2) - Calcular INSS: \n");
                printf("3) - Calcular IRPF: \n");
                printf("4) - Voltar ao menu inicial: \n");
                scanf("%i", &menu2);
                getchar();

                switch (menu2)
                {
                case 1:
                    if (numHorastrabalhadas <= 220)
                    {
                        somaNormal = numHorastrabalhadas * valorHora;
                    }
                    else if (numHorastrabalhadas <= 240)
                    {
                        horasExcedentes25 = numHorastrabalhadas - horasNormais;
                        somaNormal = numHorastrabalhadas * valorHora;
                        adicional25 = horasExcedentes25 * valorHora * 1.25;
                    }
                    else
                    {
                        horasExcedentes25 = 20;
                        horasExcedentes50 = numHorastrabalhadas - 240;
                        somaNormal = numHorastrabalhadas * valorHora;
                        adicional25 = horasExcedentes25 * valorHora * 1.25;
                        adicional50 = horasExcedentes50 * valorHora * 1.50;
                    }
                    salarioBruto = somaNormal + adicional25 + adicional50;
                    printf("\nOK, VOCE SELECIONOU A OPCAO - CALCULAR SALARIO BRUTO MENSAL!\n\n");
                    printf("\nAGUARDE UM INSTANTE ENQUANTO CALCULAMOS PARA VOCE...\n\n");
                    printf("Salario Base: R$ %.2f\n\n", somaNormal);
                    printf("Adicional 25%%: R$ %.2f\n\n", adicional25);
                    printf("Adicional 50%%: R$ %.2f\n\n", adicional50);
                    printf("Salario Bruto: R$ %.2f\n\n", salarioBruto);
                    printf("CALCULO CONCLUIDO COM SUCESSO !\n");

                    break;

                case 2:
                    if (salarioBruto <= 1412.00)
                    {
                        inss = salarioBruto * 0.075;
                    }
                    if (salarioBruto <= 2666.68)
                    {
                        inss = (salarioBruto * 0.09) - 21.18;
                    }
                    if (salarioBruto <= 4000.03)
                    {
                        inss = (salarioBruto * 0.12) - 101.18;
                    }
                    if (salarioBruto <= 7786.02)
                    {
                        inss = (salarioBruto * 0.14) - 181.18;
                    }

                    salarioLiquidoinss = salarioBruto - inss;
                    printf("\nOK, VOCE SELECIONOU A OPCAO - CALCULAR INSS!\n\n");
                    printf("\nAGUARDE UM INSTANTE ENQUANTO CALCULAMOS PARA VOCE...\n\n");
                    printf("O valor do INSS a ser pago : R$ %.2f\n\n", inss);
                    printf("O valor total a receber : R$ %.2f\n\n", salarioLiquidoinss);
                    printf("CALCULO CONCLUIDO COM SUCESSO !\n");

                    break;

                case 3:
                    if (salarioBruto <= 2259.20)
                    {
                        irpf = 0.0;
                        snprintf(faixa, sizeof(faixa), "Isento");
                    }
                    else if (salarioBruto <= 2826.65)
                    {
                        irpf = (salarioLiquidoinss * 0.075) - 169.44;
                        snprintf(faixa, sizeof(faixa), "7.5%%");
                    }
                    else if (salarioBruto <= 3751.05)
                    {
                        irpf = (salarioLiquidoinss * 0.15) - 381.44;
                        snprintf(faixa, sizeof(faixa), "15%%");
                    }
                    else if (salarioBruto <= 4664.68)
                    {
                        irpf = (salarioLiquidoinss * 0.225) - 662.77;
                        snprintf(faixa, sizeof(faixa), "22.5%%");
                    }
                    else if (salarioBruto > 4664.68)
                    {
                        irpf = (salarioLiquidoinss * 0.275) - 896.00;
                        snprintf(faixa, sizeof(faixa), "27.5%%");
                    }
                    else
                    {
                        printf("Valor digitado incorretamente, tente novamente\n");
                        return 1;
                    }

                    salarioLiquidoirpf = salarioLiquidoinss - irpf;

                    printf("\nOK, VOCE SELECIONOU A OPCAO - CALCULAR IRPF!\n\n");
                    printf("\nAGUARDE UM INSTANTE ENQUANTO CALCULAMOS PARA VOCE...\n\n");
                    printf("Calculo de IRPF:\n\n");
                    printf("O valor do IRPF a ser pago: R$ %.2f\n", irpf);
                    printf("O valor total a receber: R$ %.2f\n", salarioLiquidoirpf);
                    printf("Faixa de desconto aplicada: %s\n", faixa);
                    printf("CALCULO CONCLUIDO COM SUCESSO!\n\n");

                    break;

                case 4:
                    printf("Saindo do menu interativo.\n");
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
                }
            } while (menu2 != 4);
            break;

        case 3:

            totalDescontos = inss + irpf;

            if (mesAtual == mesAniversario)
                printf("Sucesso! Impressao de contracheque gerada com sucesso ! :\n");
            printf("\n==================================================================\n");
            printf("EMPREGADOR                          RECIBO DE PAGAMENTO DE SALARIO\n");
            printf("NOME:%s\n", razaoSocial);
            printf("ENDERECO:%s", endereco);
            printf("CNPJ:%s", cnpj);
            printf(" \n");
            printf("\n==================================================================\n");
            printf("NOME COMPLETO: %s\n", nomeCompleto);
            printf("FUNCAO: %s\n", cargo);
            printf("MES: %d", mesAtual);
            printf("\n==================================================================\n");
            printf("==================================================================\n");
            printf("\nINFORMACOES:                                   |\n");
            printf("Salario Bruto:                                 |    R$ %.2f\n", salarioBruto);
            printf("INSS:                                          |    R$ %.2f\n", inss);
            printf("IRPF:                                          |    R$ %.2f\n", irpf);
            printf("FAIXA IRPF:                                    |        %s\n", faixa);
            printf("                                               |\n");
            printf("Total descontos:                               |    R$ %.2f\n", totalDescontos);
            printf("                                               |\n");
            printf("Salario Liquido:                               |    R$ %.2f\n", salarioLiquidoirpf);
            printf("\n==================================================================\n");
            printf("Mensagem: \n");
            if (mesAtual == mesAniversario)
            {
                printf("Parabens ! Feliz aniversario ! %s\n", mensagemAniversario);
            }
            printf("\n==================================================================\n");
            printf("==================================================================\n");

            break;

        case 4:
            printf("Saindo do programa....3....2....1...\n");
            break;

        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (menu1 != 4);
    printf("Volte sempre! ");
}
