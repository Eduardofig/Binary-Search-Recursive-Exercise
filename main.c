#include <stdio.h>
#include <stdlib.h>
/* Aluno: Eduardo Figueiredo Freire Andrade
    Nusp: 11232820
    Exercicio: Busca Binaria e recursão*/


//função busca binaria iterativa
int binariaIterativa(int arr[], int procura, int n)
{
    int direita = n - 1;
    int esquerda = 0;
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (arr[meio] == procura)
            return meio;
        if (arr[meio] < procura)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }
    return -2;
}
//função busca binaria recursiva
int binariaRecursiva(int arr[], int esquerda, int direita, int procura)
{
    if (direita >= esquerda) {
        int meio = esquerda + (direita - esquerda)/ 2;
        if (arr[meio] == procura)
            return meio;
        if (arr[meio] > procura)
            return binariaRecursiva(arr, esquerda, meio - 1, procura);
        return binariaRecursiva(arr, meio + 1, direita, procura);
    }
    return -2;
}
//função busca sequencial
int sequencial(int arr[], int n, int procura){
    int j;
    for (j = 0; j < n; j++){
        if (arr[j] == procura)
            return j;}
        return -2;


}
//codigo principal que cria 3 arrays, um para os tipos de busca, outro para os respectivos numeros a serem pesquisados e o ultimo para o array de elementos principal, os for loops sao para receber o input do usuario
int main()
{
    int arr[100000], tipos[100000], procuras[100000], registros, buscas, tipo, c, k, i, resultado, e, d;

    scanf("%d %d", &registros, &buscas);
    for (c = 0; c < registros; c++)
        scanf("%d", &arr[c]);
    for (k = 0; k < buscas; k++)
        scanf("%d %d", &tipos[k], &procuras[k]);
    for (i = 0; i < buscas; i++){
        switch(tipos[i]){
        case 1:
            resultado = sequencial(arr, registros, procuras[i]);
            printf("%d\n", resultado + 1);
            break;
        case 2:
            resultado = binariaIterativa(arr, procuras[i], registros);
            printf("%d\n", resultado + 1);
            break;
        case 3:
            e = 0;
            d = registros - 1;
            resultado = binariaRecursiva(arr, e, d, procuras[i]);
            printf("%d\n", resultado + 1);
            break;
        default:
            break;
        }
    }
    return 0;
    }

