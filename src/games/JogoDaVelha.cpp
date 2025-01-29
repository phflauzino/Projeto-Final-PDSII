#include "JogoDaVelha.hpp"

JogoDaVelha::JogoDaVelha() : Tabuleiro(3, 3), turnoAtual(0) {}

bool JogoDaVelha::fazerJogada(int linha, int coluna, char jogador) {
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas || !estaVazio(linha, coluna)) {
        return false;
    }
    setPosicao(linha, coluna, jogador);
    return true;
}

bool JogoDaVelha::verificarVitoria(char jogador) const {
    // Verifica linhas, colunas e diagonais
    for (int i = 0; i < linhas; ++i) {
        if (getPosicao(i, 0) == jogador && getPosicao(i, 1) == jogador && getPosicao(i, 2) == jogador)
            return true;
        if (getPosicao(0, i) == jogador && getPosicao(1, i) == jogador && getPosicao(2, i) == jogador)
            return true;
    }
    if (getPosicao(0, 0) == jogador && getPosicao(1, 1) == jogador && getPosicao(2, 2) == jogador)
        return true;
    if (getPosicao(0, 2) == jogador && getPosicao(1, 1) == jogador && getPosicao(2, 0) == jogador)
        return true;
    return false;
}

bool JogoDaVelha::verificarEmpate() const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (estaVazio(i, j)) {
                return false;
            }
        }
    }
    return true;
}

void JogoDaVelha::passarTurno() {
    turnoAtual++;
}
