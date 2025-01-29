#include "tabuleiro.hpp"
#include "doctest.h"

TEST_CASE("Testando o Tabuleiro") {
    // Teste de criação do tabuleiro quadrado
    Tabuleiro tab1(3);  // Tabuleiro 3x3
    CHECK(tab1.getPosicao(0, 0) == ' ');
    CHECK(tab1.getPosicao(1, 1) == ' ');
    CHECK(tab1.getPosicao(2, 2) == ' ');

    SUBCASE("Testando criação de tabuleiro retangular") {
        Tabuleiro tab2(3, 5);  // Tabuleiro 3x5
        CHECK(tab2.getPosicao(0, 0) == ' ');
        CHECK(tab2.getPosicao(2, 4) == ' ');
        CHECK(tab2.getPosicao(1, 2) == ' ');
    }

    SUBCASE("Testando o método estaVazio") {
        // Criando um tabuleiro 3x3 e verificando se está vazio
        Tabuleiro tab3(3);
        CHECK(tab3.estaVazio(0, 0) == true);
        tab3.setPosicao(0, 0, 'X');
        CHECK(tab3.estaVazio(0, 0) == false);  // Agora a posição está ocupada
    }

    SUBCASE("Testando o método setPosicao e getPosicao") {
        Tabuleiro tab4(3);
        tab4.setPosicao(1, 1, 'O');
        CHECK(tab4.getPosicao(1, 1) == 'O');
        tab4.setPosicao(1, 1, 'X');
        CHECK(tab4.getPosicao(1, 1) == 'X');
    }

    SUBCASE("Testando a exibição do tabuleiro") {
        Tabuleiro tab5(3);
        tab5.setPosicao(0, 0, 'X');
        tab5.setPosicao(1, 1, 'O');
        tab5.setPosicao(2, 2, 'X');
        
        // Espera-se que o tabuleiro seja impresso corretamente
        tab5.exibirTabuleiro();
        // Aqui você pode manualmente verificar a saída no console ou usar outra estratégia de captura de saída
    }
}
