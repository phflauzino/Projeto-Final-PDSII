#ifndef LIG4_HPP
#define LIG4_HPP

#include "tabuleiro.hpp"
#include "../players/jogador.hpp"
#include <memory> 

class Lig4 : public Tabuleiro {
private:
    std::shared_ptr<Jogador> jogador1, jogador2;  
    std::shared_ptr<Jogador> jogadorAtual; 

public:
    Lig4(const std::shared_ptr<Jogador>& jogador1, const std::shared_ptr<Jogador>& jogador2);

    void jogar();
    bool inserirPeca(int coluna, char simbolo);
    bool verificarVitoria(char simbolo) const;
    void verificarVencedor() const;
};

#endif
