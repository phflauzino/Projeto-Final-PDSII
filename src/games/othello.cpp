#include "othello.hpp"
#include <iostream>

Othello::Othello(std::shared_ptr<Jogador> j1, std::shared_ptr<Jogador> j2)
    : jogador1(j1), jogador2(j2), turnoJogador1(true) {
    inicializarTabuleiro();
}

void Othello::inicializarTabuleiro() {
    // Inicializa o tabuleiro 8x8 com espaços vazios
    tabuleiro = std::vector<std::vector<char>>(8, std::vector<char>(8, ' '));

    // Coloca as peças iniciais
    tabuleiro[3][3] = tabuleiro[4][4] = 'X';
    tabuleiro[3][4] = tabuleiro[4][3] = 'O';
}

bool Othello::jogadaValida(int linha, int coluna) {
    // Lógica para validar se a jogada é válida
    // Verifica se a célula está vazia e se a jogada é válida no contexto do Othello
    if (linha < 0 || linha >= 8 || coluna < 0 || coluna >= 8 || tabuleiro[linha][coluna] != ' ') {
        return false;
    }
    // A verificação detalhada para captura de peças deve ser implementada aqui
    return true;
}

void Othello::capturarPecas(int linha, int coluna) {
    // Implementa a lógica de captura das peças no Othello
    // Altera o tabuleiro após a jogada válida
    tabuleiro[linha][coluna] = turnoJogador1 ? 'X' : 'O';
}

bool Othello::verificarFimDeJogo() {
    // Verifica se o jogo terminou (se há mais jogadas válidas)
    // A lógica de fim de jogo pode ser baseada na ausência de jogadas válidas
    bool jogadasValidas = false;

    // Verificar se existe alguma jogada válida para qualquer um dos jogadores
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (jogadaValida(i, j)) {
                jogadasValidas = true;
                break;
            }
        }
        if (jogadasValidas) break;
    }

    // Se não houver jogadas válidas, o jogo termina
    return !jogadasValidas;
}

void Othello::exibirJogadorAtual() {
    std::cout << "É a vez de " << (turnoJogador1 ? jogador1->getApelido() : jogador2->getApelido()) << std::endl;
}

void Othello::exibirTabuleiro() {
    // Exibe o tabuleiro de Othello para o usuário
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << (tabuleiro[i][j] == ' ' ? '.' : tabuleiro[i][j]) << " ";
        }
        std::cout << std::endl;
    }
}

void Othello::jogar() {
    std::cout << "Iniciando o jogo Othello...\n";
    while (!verificarFimDeJogo()) {
        exibirTabuleiro();
        exibirJogadorAtual();

        int linha, coluna;
        std::cout << "Digite a linha e a coluna para a jogada: ";
        std::cin >> linha >> coluna;

        if (jogadaValida(linha, coluna)) {
            capturarPecas(linha, coluna);
            turnoJogador1 = !turnoJogador1;  // Alterna o turno
        } else {
            std::cout << "Jogada inválida. Tente novamente.\n";
        }
    }

    std::cout << "O jogo terminou!" << std::endl;
    exibirTabuleiro();
}
