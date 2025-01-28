#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "JogoDaVelha.hpp"
#include "doctest.h"

TEST_CASE("Teste de jogadas validas e invalidas") {
  JogoDaVelha jogo;

  CHECK(jogo.fazerJogada(0, 0, 'X') == true);
  CHECK(jogo.fazerJogada(0, 0, 'O') == false);
  CHECK(jogo.fazerJogada(1, 1, 'O') == true);
  CHECK(jogo.fazerJogada(3, 3, 'X') == false);
}

TEST_CASE("Teste de condicoes de vitoria") {
  JogoDaVelha jogo;
  jogo.fazerJogada(0, 0, 'X');
  jogo.fazerJogada(0, 1, 'X');
  jogo.fazerJogada(0, 2, 'X');
  CHECK(jogo.verificarVitoria("X") == true);
  CHECK(jogo.verificarVitoria("O") == false);
}

TEST_CASE("Teste de empate") {
  JogoDaVelha jogo;
  jogo.fazerJogada(0, 0, 'X');
  jogo.fazerJogada(0, 1, 'O');
  jogo.fazerJogada(0, 2, 'X');
  jogo.fazerJogada(1, 0, 'X');
  jogo.fazerJogada(1, 1, 'O');
  jogo.fazerJogada(1, 2, 'X');
  jogo.fazerJogada(2, 0, 'O');
  jogo.fazerJogada(2, 1, 'X');
  jogo.fazerJogada(2, 2, 'O');
  CHECK(jogo.verificarEmpate() == true);
}

TEST_CASE("Teste de excecoes") {
  JogoDaVelha jogo;
  CHECK_THROWS_AS(jogo.fazerJogada(3, 3, 'X'), std::out_of_range);
}
