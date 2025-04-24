#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma carta
typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

// Função para mostrar a carta
void mostrarCarta(Carta c) {
    printf("Nome: %s\n", c.nome);
    printf("Força: %d\n", c.forca);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Inteligência: %d\n", c.inteligencia);
}

// Função para verificar condições especiais de vitória
int verificarVitoriaAutomatica(Carta c1, Carta c2) {
    int somaC2 = c2.forca + c2.velocidade + c2.inteligencia;

    if (strcmp(c1.nome, "Dragão Vermelho") == 0 && somaC2 < 180) {
        printf(">>> %s venceu automaticamente com seu poder especial!\n", c1.nome);
        return 1;
    }

    if (strcmp(c1.nome, "Golem de Pedra") == 0 && c1.forca > 85 && c2.inteligencia < 60) {
        printf(">>> %s venceu automaticamente com sua força bruta!\n", c1.nome);
        return 1;
    }

    return 0; // sem vitória automática
}

// Função para comparar dois atributos
void comparar(Carta c1, Carta c2, int atributo) {
    // Verificar vitória automática
    if (verificarVitoriaAutomatica(c1, c2)) return;
    if (verificarVitoriaAutomatica(c2, c1)) return;

    int valor1, valor2;

    switch (atributo) {
        case 1: valor1 = c1.forca; valor2 = c2.forca; printf("Comparando FORÇA...\n"); break;
        case 2: valor1 = c1.velocidade; valor2 = c2.velocidade; printf("Comparando VELOCIDADE...\n"); break;
        case 3: valor1 = c1.inteligencia; valor2 = c2.inteligencia; printf("Comparando INTELIGÊNCIA...\n"); break;
        default: printf("Atributo inválido.\n"); return;
    }

    printf("%s: %d VS %s: %d\n", c1.nome, valor1, c2.nome, valor2);

    if (valor1 > valor2)
        printf(">>> %s venceu!\n", c1.nome);
    else if (valor1 < valor2)
        printf(">>> %s venceu!\n", c2.nome);
    else
        printf(">>> Empate!\n");
}

int main() {
    // Duas cartas de exemplo
    Carta carta1 = {"Dragão Vermelho", 90, 70, 60};
    Carta carta2 = {"Golem de Pedra", 88, 40, 55};

    printf("=== CARTA 1 ===\n");
    mostrarCarta(carta1);

    printf("\n=== CARTA 2 ===\n");
    mostrarCarta(carta2);

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Força\n");
    printf("2 - Velocidade\n");
    printf("3 - Inteligência\n");

    int escolha;
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    printf("\n=== RESULTADO ===\n");
    comparar(carta1, carta2, escolha);

    return 0;
}