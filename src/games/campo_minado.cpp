#include "campo_minado.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

CampoMinado::CampoMinado(Jogador* jogador) : jogador(jogador), tamanho(8), numMinas(10) {
    inicializarTabuleiro();
    posicionarMinas();
}

void CampoMinado::inicializarTabuleiro() {
    tabuleiro.resize(tamanho, std::vector<char>(tamanho, '-'));
    tabuleiroVisivel.resize(tamanho, std::vector<char>(tamanho, '-'));
}

void CampoMinado::posicionarMinas() {
    srand(static_cast<unsigned int>(time(0)));
    int minasColocadas = 0;
    while (minasColocadas < numMinas) {
        int linha = rand() % tamanho;
        int coluna = rand() % tamanho;
        if (tabuleiro[linha][coluna] != '*') {
            tabuleiro[linha][coluna] = '*';
            minasColocadas++;
        }
    }
}

void CampoMinado::exibirTabuleiro() const {
    std::cout << "  ";
    for (int i = 0; i < tamanho; ++i)
        std::cout << i << " ";
    std::cout << "\n";

    for (int i = 0; i < tamanho; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < tamanho; ++j) {
            std::cout << tabuleiroVisivel[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool CampoMinado::jogadaValida(int linha, int coluna) const {
    return linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho;
}

bool CampoMinado::revelarCelula(int linha, int coluna) {
    if (!jogadaValida(linha, coluna) || tabuleiroVisivel[linha][coluna] != '-')
        return false;

    if (tabuleiro[linha][coluna] == '*') {
        tabuleiroVisivel[linha][coluna] = '*';
        return true; // Jogador atingiu uma mina
    }

    int minasAdjacentes = contarMinasAdjacentes(linha, coluna);
    tabuleiroVisivel[linha][coluna] = minasAdjacentes + '0';

    if (minasAdjacentes == 0) {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i != 0 || j != 0) {
                    revelarCelula(linha + i, coluna + j);
                }
            }
        }
    }

    return false;
}

int CampoMinado::contarMinasAdjacentes(int linha, int coluna) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int novaLinha = linha + i;
            int novaColuna = coluna + j;
            if (jogadaValida(novaLinha, novaColuna) && tabuleiro[novaLinha][novaColuna] == '*') {
                count++;
            }
        }
    }
    return count;
}

bool CampoMinado::verificarVitoria() const {
    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            if (tabuleiro[i][j] != '*' && tabuleiroVisivel[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

void CampoMinado::jogar() {
    bool gameOver = false;
    while (!gameOver) {
        exibirTabuleiro();
        int linha, coluna;
        std::cout << "Digite a linha e a coluna (separadas por espaço): ";
        std::cin >> linha >> coluna;

        if (!jogadaValida(linha, coluna)) {
            std::cout << "Jogada inválida. Tente novamente.\n";
            continue;
        }

        if (revelarCelula(linha, coluna)) {
            exibirTabuleiro();
            std::cout << "Você atingiu uma mina! Fim de jogo.\n";
            gameOver = true;
        } else if (verificarVitoria()) {
            exibirTabuleiro();
            std::cout << "Parabéns! Você venceu o jogo.\n";
            gameOver = true;
        }
    }
}
