#include "lig4.hpp"
#include <iostream>
#include <memory>

Lig4::Lig4(const std::shared_ptr<Jogador>& jogador1, const std::shared_ptr<Jogador>& jogador2)
    : Tabuleiro(6, 7),  // Chame o construtor adequado de Tabuleiro (com 6 linhas e 7 colunas)
      jogador1(jogador1), jogador2(jogador2), jogadorAtual(jogador1) {
}

void Lig4::jogar() {
    bool fimDeJogo = false;

    while (!fimDeJogo) {
        exibirTabuleiro();
        std::cout << "Jogador " << jogadorAtual->getApelido() << " (" 
                  << jogadorAtual->getApelido()[0]
                  << "), escolha uma coluna (0-6): ";
        int coluna;
        std::cin >> coluna;

        if (coluna < 0 || coluna >= 7 || tabuleiro[0][coluna] != ' ') {
            std::cout << "Coluna cheia ou inválida. Escolha outra.\n";
            continue;
        }

        inserirPeca(coluna, jogadorAtual->getApelido()[0]);

        if (verificarVitoria(jogadorAtual->getApelido()[0])) {
            exibirTabuleiro();
            std::cout << "Jogador " << jogadorAtual->getApelido() << " venceu!\n";
            fimDeJogo = true;
        } else {
            // Alterna entre os jogadores
            jogadorAtual = (jogadorAtual == jogador1) ? jogador2 : jogador1;
        }
    }
}

bool Lig4::inserirPeca(int coluna, char simbolo) {
    for (int i = 5; i >= 0; --i) {
        if (tabuleiro[i][coluna] == ' ') {
            tabuleiro[i][coluna] = simbolo;
            return true;
        }
    }
    return false;
}

bool Lig4::verificarVitoria(char simbolo) const {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (tabuleiro[i][j] == simbolo) {
                // Verificar horizontal
                if (j + 3 < 7 && tabuleiro[i][j] == tabuleiro[i][j + 1] &&
                    tabuleiro[i][j] == tabuleiro[i][j + 2] &&
                    tabuleiro[i][j] == tabuleiro[i][j + 3])
                    return true;

                // Verificar vertical
                if (i + 3 < 6 && tabuleiro[i][j] == tabuleiro[i + 1][j] &&
                    tabuleiro[i][j] == tabuleiro[i + 2][j] &&
                    tabuleiro[i][j] == tabuleiro[i + 3][j])
                    return true;

                // Verificar diagonal (crescente)
                if (i + 3 < 6 && j + 3 < 7 &&
                    tabuleiro[i][j] == tabuleiro[i + 1][j + 1] &&
                    tabuleiro[i][j] == tabuleiro[i + 2][j + 2] &&
                    tabuleiro[i][j] == tabuleiro[i + 3][j + 3])
                    return true;

                // Verificar diagonal (decrescente)
                if (i - 3 >= 0 && j + 3 < 7 &&
                    tabuleiro[i][j] == tabuleiro[i - 1][j + 1] &&
                    tabuleiro[i][j] == tabuleiro[i - 2][j + 2] &&
                    tabuleiro[i][j] == tabuleiro[i - 3][j + 3])
                    return true;
            }
        }
    }
    return false;
}

void Lig4::verificarVencedor() const {
    // Mostra quem foi o vencedor com base no último jogador que fez a jogada
    if (jogadorAtual == jogador1) {
        std::cout << jogador1->getApelido() << " (X) é o vencedor!\n";
    } else {
        std::cout << jogador2->getApelido() << " (O) é o vencedor!\n";
    }
}
