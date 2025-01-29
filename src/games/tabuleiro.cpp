#include "tabuleiro.hpp"

Tabuleiro::Tabuleiro() : linhas(0), colunas(0), tabuleiro(0, std::vector<char>(0)) {
}

Tabuleiro::Tabuleiro(int tamanho) : linhas(tamanho), colunas(tamanho) {
    tabuleiro.resize(linhas, std::vector<char>(colunas, ' '));
}

Tabuleiro::Tabuleiro(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    tabuleiro.resize(linhas, std::vector<char>(colunas, ' '));
}

void Tabuleiro::exibirTabuleiro() const {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            std::cout << (j == 0 ? "" : "|") << tabuleiro[i][j];
        }
        std::cout << std::endl;
        if (i < linhas - 1) {
            std::cout << std::string(colunas * 2 - 1, '-') << std::endl;
        }
    }
}

bool Tabuleiro::estaVazio(int linha, int coluna) const {
    return tabuleiro[linha][coluna] == ' ';
}

void Tabuleiro::setPosicao(int linha, int coluna, char valor) {
    tabuleiro[linha][coluna] = valor;
}

char Tabuleiro::getPosicao(int linha, int coluna) const {
    return tabuleiro[linha][coluna];
}
