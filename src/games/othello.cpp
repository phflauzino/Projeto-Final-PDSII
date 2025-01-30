#include "othello.hpp"
#include <iostream>

Othello::Othello(std::shared_ptr<Jogador> j1, std::shared_ptr<Jogador> j2)
    : jogador1(j1), jogador2(j2), turnoJogador1(true) {
    inicializarTabuleiro();
}

void Othello::inicializarTabuleiro() {
    tabuleiro = std::vector<std::vector<char>>(8, std::vector<char>(8, ' '));
    tabuleiro[3][3] = tabuleiro[4][4] = 'X';
    tabuleiro[3][4] = tabuleiro[4][3] = 'O';
}

bool Othello::jogadaValida(int linha, int coluna) {
    if (linha < 0 || linha >= 8 || coluna < 0 || coluna >= 8 || tabuleiro[linha][coluna] != ' ') {
        return false;
    }
    return true;
}

void Othello::capturarPecas(int linha, int coluna) {
    tabuleiro[linha][coluna] = turnoJogador1 ? 'X' : 'O';
}

bool Othello::verificarFimDeJogo() {
    bool jogadasValidas = false;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (jogadaValida(i, j)) {
                jogadasValidas = true;
                break;
            }
        }
        if (jogadasValidas) break;
    }
    return !jogadasValidas;
}

void Othello::exibirJogadorAtual() {
    std::cout << "É a vez de " << (turnoJogador1 ? jogador1->getApelido() : jogador2->getApelido()) << std::endl;
}

void Othello::exibirTabuleiro() {
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
            turnoJogador1 = !turnoJogador1;
        } else {
            std::cout << "Jogada inválida. Tente novamente.\n";
        }
    }

    std::cout << "O jogo terminou!" << std::endl;
    exibirTabuleiro();

    int contadorX = 0, contadorO = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro[i][j] == 'X') contadorX++;
            if (tabuleiro[i][j] == 'O') contadorO++;
        }
    }

    if (contadorX > contadorO) {
        std::cout << "O vencedor é " << jogador1->getApelido() << " (X)!" << std::endl;
    } else if (contadorO > contadorX) {
        std::cout << "O vencedor é " << jogador2->getApelido() << " (O)!" << std::endl;
    } else {
        std::cout << "Empate! Ambos os jogadores têm o mesmo número de peças." << std::endl;
    }
}
