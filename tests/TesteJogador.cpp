#include "doctest.h"
#include "jogador.hpp"

TEST_CASE("Testando a classe Jogador") {
    // Teste do construtor padrão
    Jogador jogador1;
    CHECK(jogador1.getApelido() == "");
    CHECK(jogador1.getNome() == "");
    CHECK(jogador1.getEmail() == "");
    CHECK(jogador1.getSenha() == "");

    // Teste do construtor parametrizado
    Jogador jogador2("jogador1", "João Silva", "joao@exemplo.com", "senha123");
    CHECK(jogador2.getApelido() == "jogador1");
    CHECK(jogador2.getNome() == "João Silva");
    CHECK(jogador2.getEmail() == "joao@exemplo.com");
    CHECK(jogador2.getSenha() == "senha123");

    SUBCASE("Testando os métodos setters e getters") {
        jogador1.setApelido("jogador2");
        jogador1.setNome("Maria Oliveira");
        jogador1.setEmail("maria@exemplo.com");
        jogador1.setSenha("senha456");

        CHECK(jogador1.getApelido() == "jogador2");
        CHECK(jogador1.getNome() == "Maria Oliveira");
        CHECK(jogador1.getEmail() == "maria@exemplo.com");
        CHECK(jogador1.getSenha() == "senha456");
    }

    SUBCASE("Testando as mudanças de estado do jogador") {
        Jogador jogador3("player1", "Carlos Souza", "carlos@exemplo.com", "senha789");
        CHECK(jogador3.getApelido() == "player1");

        jogador3.setApelido("player_updated");
        CHECK(jogador3.getApelido() == "player_updated");

        jogador3.setEmail("carlos_updated@exemplo.com");
        CHECK(jogador3.getEmail() == "carlos_updated@exemplo.com");
    }
}

