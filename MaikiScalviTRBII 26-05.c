#include <stdio.h>
#include <string.h>

int main()
{
    // case 1:
    int menu1, menu2;
    char razaoSocial[20];
    int cnpj;
    char endereco[50];
    // case2:
    int mesAtual;
    char nomeCompleto[30];
    char cargo[20];
    int mesAniversario;
    int numHorastrabalhadas;
    float valorHora;
    // case 2 parte conta
    
    float soma25;
    float soma50;
    float horasExcedentes25;
    float horasExcedentes50;
    // case 3 IRPF
    float imposto = 0.0;
    // Inicializa variáveis
    float somaNormal = 0.0;
    float adicional25 = 0.0;
    float adicional50 = 0.0;
    float salarioBruto;

    do
    {
        printf("Programa FOLHA DE PAGAMENTO\n\n");
        printf("Selecione uma opcao abaixo:\n\n");
        printf("1) - Configurar dados da empresa:\n");
        printf("2) - Calcular salario mensal:\n");
        printf("3) - Imprimir Contracheque:\n");
        printf("4) - Sair:\n");
        scanf("%i", &menu1);

        switch (menu1)
        {       // Primeiro Menu
        case 1: // Configurar dados da empresa.
            printf("Configurando dados da empresa:\n\n");
            printf("Digite a razao social da empresa:\n");
            scanf("%s", &razaoSocial);
            printf("Digite o CNPJ:\n");
            scanf("%i", &cnpj);
            printf("Digite o endereço:\n");
            scanf("%s", &endereco);
            break;

        case 2: // Calcular salario mensal.
            printf("Digite o mes atual:(EX: '01' para Janeiro)\n");
            scanf("%i", &mesAtual);

            printf("Digite o nome completo do funcionario:\n");
            scanf("%s", &nomeCompleto);

            printf("Digite o cargo do funcionario:\n");
            scanf("%s", &cargo);

            printf("Digite o mes de aniversário:\n");
            scanf("%i", &mesAniversario);

            printf("Digite o numero de horas trabalhadas:\n");
            scanf("%i", &numHorastrabalhadas);

            printf("Digite o valor de cada hora trabalhada desse funcionário:\n");
            scanf("%f", &valorHora);

            // Partindo para as contas
            do
            {
                printf("Menu interativo, selecione uma opção abaixo:\n\n");
                printf("1) - Calcular salario bruto mensal: \n");
                printf("2) - Calcular INSS: \n");
                printf("3) - Calcular IRPF: \n");
                printf("4) - Sair: \n");
                scanf("%i", &menu2);

                switch (menu2)
                {
                case 1:
                    // Calcula o salário com base nas horas trabalhadas
                    if (numHorastrabalhadas <= 220)
                    {
                        somaNormal = numHorastrabalhadas * valorHora;
                    }
                    else if (numHorastrabalhadas <= 240)
                    {
                        int horasNormais = 220;
                        int horasExcedentes25 = numHorastrabalhadas - horasNormais;
                        somaNormal = horasNormais * valorHora;
                        adicional25 = horasExcedentes25 * valorHora * 0.25;
                    }
                    else
                    {
                        int horasNormais = 220;
                        int horasExcedentes25 = 20; // 240 - 220 = 20 horas
                        int horasExcedentes50 = numHorastrabalhadas - 240;
                        somaNormal = horasNormais * valorHora;
                        adicional25 = horasExcedentes25 * valorHora * 0.25;
                        adicional50 = horasExcedentes50 * valorHora * 0.50;
                    }

                    // Calcula o salário bruto
                    salarioBruto = somaNormal + adicional25 + adicional50;

                    // Exibe o resultado
                    printf("Salario Base: R$ %.2f\n", somaNormal);
                    printf("Adicional 25%%: R$ %.2f\n", adicional25);
                    printf("Adicional 50%%: R$ %.2f\n", adicional50);
                    printf("Salario Bruto: R$ %.2f\n", salarioBruto);
                           

                    break;

                case 2: // calculado INSS

                    printf("Calculo de INSS:\n");
                    printf("Calculo de INSS:\n");
                    printf("Calculo de INSS:\n");
                    break;
                case 3:
                    printf("Calculo IRPF:\n");
                    printf("");
                    float salario;

                    if (salario <= 2259.20)
                    {
                        imposto = 0.0;
                    }
                    else if (salario <= 2826.65)
                    {
                        imposto = (salario * 0.075) - 169.44;
                    }
                    else if (salario <= 3751.05)
                    {
                        imposto = (salario * 0.15) - 381.44;
                    }
                    else if (salario <= 4664.68)
                    {
                        imposto = (salario * 0.225) - 662.77;
                    }
                    else
                    {
                        imposto = (salario * 0.275) - 896.00;
                    }

                    printf("Calculo de IRPF:\n");

                    break;
                case 4:
                    printf("Saindo do menu interativo.\n");
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
                }
            } while (menu2 != 4); // Final do segundo while menu2
            break; // Adicionado break aqui para evitar cair no próximo case

        case 3: // Imprimir contracheque.
            printf("Impressão de contracheque pendente.\n");
            break;

        case 4: // Sair
            printf("Saindo do programa.\n");
            break;

        default:
            printf("Opção inválida.\n");
            break;
        }
    } while (menu1 != 4); // Final do primeiro while menu1
}






 //TESTANDO NOVO CASE 1 DO MENU2
                    // if (numHorastrabalhadas <= 220)
                    // {
                    //    somaNormal = (numHorastrabalhadas * valorHora);
                    //    printf("A soma do numero de horas trabalhadas adicionando o valor por hora, fica em R$ %.2f\n", somaNormal);
                    //}

                    // if (numHorastrabalhadas >= 221 && numHorastrabalhadas <= 240)
                    //{
                    //    horasExcedentes25 = (numHorastrabalhadas - 220);
                    //    somaNormal = (horasExcedentes25 * valorHora * 1.25) + (220 * valorHora);
                    //    printf("O valor a ser pago de horas normais com horas excedentes é de R$ %.2f\n", somaNormal);
                    //}
                    // if (numHorastrabalhadas>240)
                    //{
                    //    horasExcedentes50 = (numHorastrabalhadas - 239);
                    //    somaNormal = (horasExcedentes50 * valorHora * 1.50)+(239 * valorHora);
                    //    printf("O valor a ser pago de horas normais com horas excedentes é de R$ %.2f\n", somaNormal);
                    //}