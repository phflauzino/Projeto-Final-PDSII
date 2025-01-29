#ifndef JOGODAVELHA_HPP
#define JOGODAVELHA_HPP

#include "tabuleiro.hpp"

class JogoDaVelha : public Tabuleiro {
private:
    int turnoAtual;

public:
    JogoDaVelha();

    bool fazerJogada(int linha, int coluna, char jogador);
    bool verificarVitoria(char jogador) const;
    bool verificarEmpate() const;
    void passarTurno();
    int getTurnoAtual() const { return turnoAtual; }
};

#endif
