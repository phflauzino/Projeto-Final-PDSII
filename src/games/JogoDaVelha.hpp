#ifndef JOGODAVELHA_HPP
#define JOGODAVELHA_HPP

#include "tabuleiro.hpp"
#include "../players/jogador.hpp"
#include <memory>

class JogoDaVelha : public Tabuleiro {
private:
    int turnoAtual;

public:
    JogoDaVelha();

    bool fazerJogada(int linha, int coluna, char jogador);
    bool verificarVitoria(char jogador) const;
    bool verificarEmpate() const;
    void passarTurno();
    void jogar();
    int getTurnoAtual() const { return turnoAtual; }
};

#endif
