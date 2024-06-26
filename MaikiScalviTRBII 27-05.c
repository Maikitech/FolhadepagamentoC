#include <stdio.h>
#include <string.h>

int main()
{
    int menu1, menu2;
    char razaoSocial[20];
    int cnpj;
    char endereco[50];
    int mesAtual;
    char nomeCompleto[30];
    char cargo[20];
    int mesAniversario;
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

    do
    {
        printf("Programa FOLHA DE PAGAMENTO\n\n");
        printf("Selecione uma opcao abaixo:\n\n");
        printf("1) - Configurar dados da empresa:\n");
        printf("2) - Calcular salario mensal:\n");
        printf("3) - Imprimir Contracheque:\n");
        printf("4) - Sair:\n");
        scanf("%i", &menu1);
        getchar(); // Limpar o buffer de entrada após scanf

        switch (menu1)
        {
        case 1:
            printf("\nConfigurando dados da empresa:\n\n");
            printf("Digite a razao social da empresa:\n");
            fgets(razaoSocial, sizeof(razaoSocial), stdin);
            
            
            printf("Digite o CNPJ:(SOMENTE NUMEROS)\n");
            scanf("%i", &cnpj);
            getchar();
            
            printf("Digite o endereço:\n");
            fgets(endereco, sizeof(endereco), stdin); 
            
            break;

        case 2:
            printf("Digite o mes atual:(EX: '01' para Janeiro)\n");
            scanf("%i", &mesAtual);
            getchar(); 
            
            printf("Digite o nome completo do funcionario:\n");
            fgets(nomeCompleto, sizeof(nomeCompleto), stdin);
            nomeCompleto[strcspn(nomeCompleto, "\n")] = 0; 

            printf("Digite o cargo do funcionario:\n");
            fgets(cargo, sizeof(cargo), stdin);
            cargo[strcspn(cargo, "\n")] = 0; 

            printf("Digite o mes de aniversário:(EX: '01' para Janeiro)\n");
            scanf("%i", &mesAniversario);
            getchar(); 

            printf("Digite o numero de horas trabalhadas:(SOMENTE NUMEROS)\n");
            scanf("%i", &numHorastrabalhadas);
            getchar(); 

            printf("Digite o valor de cada hora trabalhada desse funcionário:(EX: 15.00)\n");
            scanf("%f", &valorHora);
            getchar(); 

            do
            {
                printf("\nMenu interativo, selecione uma opção abaixo:\n\n");
                printf("1) - Calcular salario bruto mensal: \n");
                printf("2) - Calcular INSS: \n");
                printf("3) - Calcular IRPF: \n");
                printf("4) - Sair: \n");
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

                    printf("Salario Base: R$ %.2f\n", somaNormal);
                    printf("Adicional 25%%: R$ %.2f\n", adicional25);
                    printf("Adicional 50%%: R$ %.2f\n", adicional50);
                    printf("Salario Bruto: R$ %.2f\n", salarioBruto);

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
                    printf("Calculo de INSS:\n");
                    printf("O valor do INSS a ser pago é: R$ %.2f\n", inss);
                    printf("O valor total a receber é: R$ %.2f\n", salarioLiquidoinss);

                    break;

                case 3:
                    if (salarioBruto <= 2259.20)
                    {
                        irpf = 0.0;
                    }
                    else if (salarioBruto <= 2826.65)
                    {
                        irpf = (salarioLiquidoinss * 0.075) - 169.44;
                    }
                    else if (salarioBruto <= 3751.05)
                    {
                        irpf = (salarioLiquidoinss * 0.15) - 381.44;
                    }
                    else if (salarioBruto <= 4664.68)
                    {
                        irpf = (salarioLiquidoinss * 0.225) - 662.77;
                    }
                    else if (salarioBruto > 4664.68)
                    {
                        irpf = (salarioLiquidoinss * 0.275) - 896.00;
                    }
                    else
                    {
                        printf("Valor digitado incorretamente, tente novamente\n");
                    }
                    salarioLiquidoirpf = salarioLiquidoinss - irpf;
                    printf("Calculo de IRPF:\n");
                    printf("O valor do IRPF a ser pago é: R$ %.2f\n", irpf);
                    printf("O valor total a receber é: R$ %.2f\n", salarioLiquidoirpf);

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
            printf("Impressão de contracheque pendente.\n");
            break;

        case 4:
            printf("Saindo do programa.\n");
            break;

        default:
            printf("Opção inválida.\n");
            break;
        }
    } while (menu1 != 4);
}