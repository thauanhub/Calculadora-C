#include <stdio.h>
#include <stdbool.h>

float soma(float x, float y){
    float resultado = x + y;
    return resultado;
}

float subtracao(float x, float y){
    return x - y;
}

float multiplicacao(float x, float y){
    return x*y;
}

float divisao(float x, float y){
    return x/y;
}

int main(){

    float num1 = 0, num2 = 0, resultado = 0; 
    char operacao = ' ', opcao = '0';

    while(opcao != 5 && opcao != 'n'){
        bool erro = false; 
        
        /*Inicializar menu*/
        printf("===============================\n");
        printf("      Calculadora Simples  \n");
        printf("===============================\n");
        printf("Selecione uma operação:\n");
        printf("1. Adição\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Sair\n");

        /*Escolher operação*/

        setbuf(stdin, NULL);
        printf("Opção:\n");
        scanf("%c", &opcao);

        if(opcao == '5'){
            printf("Obrigado por usar a calculadora! Até a próxima.");
            return 0;
        }

        else if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4'){
            printf("Número fora do intervalo ou entrada não numérica. Digite um valor válido.\n");
            continue;
        }

        /*Digitar dois números*/
        printf("Digite o primeiro número: ");
        scanf("%f", &num1);
        printf("Digite o segundo número: ");
        scanf("%f", &num2);

       
       if(opcao == '1'){
            resultado = soma(num1, num2);
            operacao = '+';
       }

       else if(opcao == '2'){
            resultado = subtracao(num1, num2);
            operacao = '-';
       }

       else if(opcao == '3'){
            resultado = multiplicacao(num1, num2);
            operacao = '*';       
        }

        else if(opcao == '4'){
            if(num2 == 0){
                    printf("Erro: Divisão por zero não é permitida.\n");
                    erro = true;
                }
                else{
                    resultado = divisao(num1, num2);
                    operacao = '/';
                }
        }

        /*Imprimir a resposta*/
        if(!erro){
            printf("Resultado: %f %c %f = %f\n", num1, operacao, num2, resultado);
        }

        /*Deseja realizar outra operação?(s/n)*/
        while(opcao != 's' && opcao != 'n' ){
            printf("Deseja realizar outra operação?(s/n)\n");
            setbuf(stdin, NULL);
            scanf("%c", &opcao);
            if(opcao == 'S' || opcao == 's'){
                opcao = 's';
                printf("\033[H\033[J");
            }
            else if(opcao == 'N' || opcao == 'n'){
                opcao = 'n';
                printf("Obrigado por usar a calculadora! Até a próxima.");
            }
            else{
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
            }
        }
    }
    return 0;
}