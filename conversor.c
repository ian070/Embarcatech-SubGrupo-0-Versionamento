#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int menu();
int decimais(double n);
void volume();
void comprimento();
void area();
void temperature();
void tempo();
void conversaoBytes();


int main()
{
    int esc;
    do
    {
        esc = menu();
        switch (esc)
        {
        case 1:
            volume();
            break;

        case 2:
            comprimento();
            break;

        case 3:
            area();
            break;

        case 4:
            temperature();
            break;

        case 5:
            tempo();
            break;
        
        case 6:
            conversaoBytes();
            break;

        case 11:
            break;

        default:
            printf("Escolha invalida.\n");
            break;
        }
    } while (esc != 11);
    return 0;
}

void comprimento()
{
    double n;
    const char *unidades[] = {"Quilometro[km]", "Metro[m]", "Centimetro[cm]", "Milimetro[mm]", "Polegada[pol]"};
    const double fator[5][5] = {
        {1, 1000, 100000, 1000000, 39370.08},
        {0.001, 1, 100, 1000, 39.37},
        {0.00001, 0.01, 1, 10, 0.3937},
        {0.000001, 0.001, 0.1, 1, 0.03937},
        {0.0000254, 0.0254, 2.54, 25.4, 1}};
    int unidEntrada = 0, unidSaida = 0;
    printf("\n========== Conversao de comprimento ===========\n");
    printf("Qual unidade deseja converter? \n");
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("[%d] %s\n", i, unidades[i]);
    }
    printf("[>=6] Retornar ao menu principal...\n");
    scanf("%d", &unidEntrada);
    if (unidEntrada >= 6 || unidEntrada < 0)
    {
        printf("Saindo de conversao de comprimento...\n\n");
        return;
    }
    printf("Entre com um valor em para ser convertido: ");
    scanf("%lf", &n);
    fflush(stdin);
    printf("Para qual unidade deseja converter? \n");
    for (i = 0; i < 5; i++)
    {
        printf("[%d] %s\n", i, unidades[i]);
    }
    printf("[>=6] Retornar ao menu principal...\n");
    scanf("%d", &unidSaida);
    fflush(stdin);
    if (unidSaida >= 6 || unidSaida < 0)
    {
        printf("Saindo de conversao de comprimento...\n\n");
        return;
    }
    int precisao=decimais(n*fator[unidEntrada][unidSaida]);
    if (unidEntrada == unidSaida)
    {
        printf("\n\nUnidades de entrada e saidas iguais. Valor: %.1lf %s\n\n", n, unidades[unidEntrada]);
    }
    else
    {
        printf("\n\n%.1lf %s --> %.*f %s\n", n, unidades[unidEntrada], precisao,(n * fator[unidEntrada][unidSaida]), unidades[unidSaida]);
    }
};
// Função para o usuário escolher qual unidade de temperatura ele quer converter.
void temperature()
{
    int choice = 1;
    float temperature;

    while (choice != 0)
    {
        printf("\nESCOLHA QUAL CONVERSAO DE TEMPERATURA VOCE QUER FAZER\n\n");
        printf("CELSIUS PARA FAHRENHEIT            [1]\n");
        printf("CELSIUS PARA KELVIN                [2]\n");
        printf("FAHRENHEIT PARA CELSIUS            [3]\n");
        printf("FAHRENHEIT PARA KELVIN             [4]\n");
        printf("KELVIN PARA CELSIUS                [5]\n");
        printf("KELVIN PARA FAHRENHEIT             [6]\n");
        printf("SAIR DO CONVERSOR DE TEMPERATURA   [0]\n\n");

        printf("DIGITE SUA ESCOLHA: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("DIGITE A TEMPERATURA EM CELSIUS: ");
            scanf("%f", &temperature);
            printf("%.2f C EM FARENHEIT E %.2f F\n", temperature, (temperature * 1.8) + 32);
            break;
        case 2:
            printf("DIGITE A TEMPERATURA EM CELSIUS: ");
            scanf("%f", &temperature);
            printf("%.2f C EM KELVIN E %.2f K\n", temperature, temperature + 273.15);
            break;
        case 3:
            printf("DIGITE A TEMPERATURA EM FARENHEIT: ");
            scanf("%f", &temperature);
            printf("%.2f F EM CELSIUS E %.2f C\n", temperature, (temperature - 32) / 1.8);
            break;
        case 4:
            printf("DIGITE A TEMPERATURA EM FARENHEIT: ");
            scanf("%f", &temperature);
            printf("%.2f F EM KELVIN E %.2f K\n", temperature, ((temperature - 32) / 1.8) + 273.15);
            break;
        case 5:
            printf("DIGITE A TEMPERATURA EM KELVIN: ");
            scanf("%f", &temperature);
            printf("%.2f K EM CELSIUS E %.2f C\n", temperature, temperature - 273.15);
            break;
        case 6:
            printf("DIGITE A TEMPERATURA EM KELVIN: ");
            scanf("%f", &temperature);
            printf("%.2f K EM FRENHEIT E %.2f F\n", temperature, ((temperature - 273.15) * 1.8) + 32);
            break;
        case 0:
            return;
        default:
            printf("Escolha invalida, digit um número de 0 a 6.\n\n");
        }
    }
}
void area()
{
    int in, out, dif, s;
    unsigned int multi;
    float valor, conv;
    do
    { // Adição de laço de repetição.
        do
        { // Laço para valores inválidos.
            printf("\nEscolha a unidade de área de entrada:");
            printf("\n[1] km²");
            printf("\n[2] hm²");
            printf("\n[3] dam²");
            printf("\n[4] m²");
            printf("\n[5] dm²");
            printf("\n[6] cm²");
            printf("\n[7] mm²\n");
            scanf("\n%d", &in);
            if (in < 1 || in > 7)
            {
                printf("Opção inválida!\n"); // Notificação para valores invalidos
            }
        } while (in < 1 || in > 7);

        printf("Insira o valor de entrada:\n");
        scanf("\n%f", &valor);
        do
        { // Laço para valores inválidos.
            printf("\nEscolha a unidade de área de saída:");
            printf("\n[1] km²");
            printf("\n[2] hm²");
            printf("\n[3] dam²");
            printf("\n[4] m²");
            printf("\n[5] dm²");
            printf("\n[6] cm²");
            printf("\n[7] mm²\n");
            scanf("%d", &out);
            if (out < 0 || out > 7)
            { // Notificação para valores invalidos
                printf("Opção inválida!\n");
            }
        } while (out < 1 || out > 7);
        dif = in - out;
        multi = pow(100, fabs(dif)); // Exclusão da variável conv para reduzir quantidade de variável.
        if (dif < 0)
        {
            printf("O valor convertido é %.4e\n.", valor * multi); // Alteração do formato para notação científica.
        }
        if (dif > 0)
        {
            printf("O valor convertido é %.4e\n.", valor / multi);
        }
        if (dif == 0)
        {
            printf("O valor é %f\n.", valor * multi);
        }
        do
        { // Laço para valores inválidos.
            printf("Deseja realizar outra operação de conversão para área?\n");
            printf("[1] Sim\n");
            printf("[2] Não\n");
            scanf("%d", &s);
            if (s < 1 || s > 2)
            { // Notificação para valores invalidos
                printf("Opção inválida!\n");
            }
        } while (s < 1 || s > 2);
    } while (s == 1);

    printf("Entre com qualquer tecla para retornar.\n"); // Adição de saída para melhorar interface.
    getchar();
    getchar();
}

void volume()
{
    int tipo, tipo2;
    float volume;

    printf("digite a unidade para conversao\n");
    printf("[1] para m3\n");
    printf("[2] para dm3\n");
    printf("[3] para cm3\n");
    printf("[4] para mm3\n");
    scanf("%d", &tipo);

    printf("digite o volume\n");
    scanf("%f", &volume);

    printf("digite a unidade de saida\n");
    printf("[1] para m3\n");
    printf("[2] para dm3\n");
    printf("[3] para cm3\n");
    printf("[4] para mm3\n");
    scanf("%d", &tipo2);

    switch (tipo)
    {
    case 1: // m3
        switch (tipo2)
        {
        case 1:
            printf("Em m3: %f\n", volume);
            break;
        case 2:
            printf("Em dm3: %.1f\n", (volume * 10));
            break;
        case 3:
            printf("Em cm3: %.2f\n", (volume * 100));
            break;
        case 4:
            ("Em mm3: %.3f\n", (volume * 1000000));
            break;
        default:
            printf("Numero invalido.\n");
            break;
        }

        break;
    case 2: // dm3
        switch (tipo2)
        {
        case 1:
            printf("Em m3: %1f\n", (volume / 10));
            break;
        case 2:
            printf("Em dm3: %.f\n", volume);
            break;
        case 3:
            printf("Em cm3: %.f\n", (volume * 10));
            break;
        case 4:
            printf("Em mm3: %.2f\n", (volume * 100));
            break;
        default:
            printf("Numero invalido.\n");
            break;
        }
        break;
    case 3: // cm3
        switch (tipo2)
        {
        case 1:
            printf("Em m3: %.2f\n", (volume / 100));
            break;
        case 2:
            printf("Em dm3: %.f\n", (volume / 10));
            break;
        case 3:
            printf("Em cm3: %.f\n", volume);
            break;
        case 4:
            printf("Em mm3: %.f\n", (volume * 10));
            break;
        default:
            printf("Numero invalido.\n");
            break;
        }
        break;
    case 4: // mm3
        switch (tipo2)
        {
        case 1:
            printf("Em m3: %.3f\n", (volume / 1000));
            break;
        case 2:
            printf("Em dm3: %.2f\n", (volume / 100));
            break;
        case 3:
            printf("Em cm3: %.1f\n", (volume / 10));
            break;
        case 4:
            printf("Em mm3: %.f\n", volume);
            break;
        default:
            printf("Numero invalido.\n");
            break;
        }
        break;

    default:
        break;
    }
}
void tempo()
{
    int unidadeEntrada, unidadeSaida;
    float valor, convertido;

    printf("Selecione a unidade de tempo de entrada:\n");
    printf("[1] para segundos\n");
    printf("[2] para minutos\n");
    printf("[3] para horas\n");
    printf("[4] para dias\n");
    scanf("%d", &unidadeEntrada);

    printf("Digite o valor do tempo:");
    scanf("%f", &valor);

    printf("Selecione a unidade de tempo de saída:\n");
    printf("[1] para segundos\n");
    printf("[2] para minutos\n");
    printf("[3] para horas\n");
    printf("[4] para dias\n");
    scanf("%d", &unidadeSaida);

    switch (unidadeEntrada)
    {
    case 1:
        switch (unidadeSaida)
        {
        case 1:
            convertido = valor;
            break;
        case 2:
            convertido = valor / 60.0;
            break;
        case 3:
            convertido = valor / 3600.0;
            break;
        case 4:
            convertido = valor / 86400.0;
            break;
        default:
            printf("Unidade de saída inválida.\n");
            return;
        }
        break;

    case 2:
        switch (unidadeSaida)
        {
        case 1:
            convertido = valor * 60.0;
            break;
        case 2:
            convertido = valor;
            break;
        case 3:
            convertido = valor / 60.0;
            break;
        case 4:
            convertido = valor / 1440.0;
            break;
        default:
            printf("Unidade de saída inválida.\n");
            return;
        }
        break;

    case 3:
        switch (unidadeSaida)
        {
        case 1:
            convertido = valor * 3600.0;
            break;
        case 2:
            convertido = valor * 60.0;
            break;
        case 3:
            convertido = valor;
            break;
        case 4:
            convertido = valor / 24.0;
            break;
        default:
            printf("Unidade de saída inválida.\n");
            return;
        }
        break;

    case 4:
        switch (unidadeSaida)
        {
        case 1:
            convertido = valor * 86400.0;
            break;
        case 2:
            convertido = valor * 1440.0;
            break;
        case 3:
            convertido = valor * 24.0;
            break;
        case 4:
            convertido = valor;
            break;
        default:
            printf("Unidade de saída inválida.\n");
            return;
        }
        break;

    default:
        printf("Unidade de entrada inválida.\n");
        return;
    }

    printf("O valor foiconvertido para: %.2f\n", convertido);
}

void conversaoBytes()
{
    // TODO: Implementar a conversão de unidades de dados em um arquivo separado
    double valor;
    int unidEntrada = 0, unidSaida = 0;
    const char *unidades[] = {"bit", "byte", "KB", "MB", "GB", "TB"};
    const int num_unidades = 6;

    const double fator[6][6] = {
                // bit        byte               KB               MB                  GB                        TB

    /* bit */    {1,         0.125,           0.000125,          0.000000125,         0.000000000125,         0.000000000000125},
    /* byte */   {8,         1,               0.001,              0.000001,            0.000000001,            0.000000000001},
    /* kb */     {8000,      1000,            1,                  0.001,               0.000001,               0.000000001},
    /* MB */     {8000000,   1000000,         1000,               1,                   0.001,                   0.000001},
    /* GB */     {8000000000,1000000000,      1000000,            1000,                1,                       0.001},
    /* TB */     {8000000000000,1000000000000,1000000000,         1000000,             1000,                    1}
    };

    printf("\n========== Conversao de Unidades de Dados ==========\n");
    printf("Digite o valor a ser convertido: ");
    scanf("%lf", &valor);

    printf("Selecione a unidade de entrada:\n");
    for (int i = 1; i <= num_unidades; i++)
    {
        printf("[%d] %s\n", i, unidades[i-1]);
    }
    printf("Escolha: ");
    scanf("%d", &unidEntrada);

    if (unidEntrada < 1 || unidEntrada > num_unidades)
    {
        printf("Unidade de entrada inválida.\n");
        return;
    }

    printf("Selecione a unidade de saída:\n");
    for (int i = 1; i <= num_unidades; i++)
    {
        if (i != unidEntrada)
            printf("[%d] %s\n", i, unidades[i-1]);
    }
    printf("Escolha: ");
    scanf("%d", &unidSaida);

    if (unidSaida < 1 || unidSaida > num_unidades)
    {
        printf("Unidade de saída inválida.\n");
        return;
    }

    double resultado = valor * fator[unidEntrada-1][unidSaida-1];
    printf("%.2lf %s = %.2f %s\n", valor, unidades[unidEntrada-1], resultado, unidades[unidSaida-1]);
}

int menu()
{
    int esc;
    printf("\n========== Menu ==========\n");
    printf("[1] para conversao de volume\n");
    printf("[2] para conversao de comprimento\n");
    printf("[3] para conversao de area\n");
    printf("[4] para conversao de temperatura\n");
    printf("[5] para conversao de tempo\n");
    printf("[6] para conversao de unidade de dados (bytes)\n");
    printf("[11] para sair. \n");
    scanf("%d", &esc);
    if (esc == 11)
    {
        printf("\n*Saindo do aplicativo...\n\n");
    }
    return esc;
}
int decimais(double n)
{
    int precisao = 0;
    while (fabs(n - round(n)) > 1e-9&&precisao<10)
    {
        n *= 10;
        precisao++;
    }
    return precisao;
}