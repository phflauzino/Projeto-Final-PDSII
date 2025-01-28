#include <iostream>
#include <unordered_map>
#include <regex>
#include "jogador.hpp"
#include "utils.hpp"
#include "JogoDaVelha.hpp"
#include "Lig4.hpp"
#include "Othello.hpp"

bool validarEmail(const std::string& email) {
    const std::regex padraoEmail(R"(^[\w.%+-]+@[\w.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, padraoEmail);
}

int main() {
    std::unordered_map<std::string, Jogador> jogadores;
    std::string entrada;

    while (true) {
        std::cout << "\nBem-vindo ao Jogo! Escolha uma opção:\n";
        std::cout << "  0 - Entrar.\n";
        std::cout << "  1 - Cadastrar um novo jogador.\n";
        std::cout << "  2 - Remover um jogador.\n";
        std::cout << "  3 - Jogar Othello.\n";
        std::cout << "  4 - Jogar Lig 4.\n";
        std::cout << "  5 - Jogar Jogo da Velha.\n";
        std::cout << "  6 - Sair do sistema.\n";

        std::cout << "Digite a opção desejada: ";
        std::getline(std::cin, entrada);

        if (entrada == "6") {
            std::cout << "Jogo encerrado.\n";
            break;
        }

        if (entrada == "1") { // Cadastrar Jogador
            std::cout << "Digite o apelido do jogador: ";
            std::string apelido;
            std::getline(std::cin, apelido);

            if (apelido.empty()) {
                std::cout << "ERRO: O apelido não pode estar vazio.\n";
                continue;
            }

            std::cout << "Digite o nome do jogador: ";
            std::string nome;
            std::getline(std::cin, nome);

            if (nome.empty()) {
                std::cout << "ERRO: O nome não pode estar vazio.\n";
                continue;
            }

            std::cout << "Digite o email do jogador: ";
            std::string email;
            std::getline(std::cin, email);

            if (!validarEmail(email)) {
                std::cout << "ERRO: Email inválido.\n";
                continue;
            }

            std::cout << "Digite a senha do jogador: ";
            std::string senha;
            std::getline(std::cin, senha);

            if (senha.empty()) {
                std::cout << "ERRO: A senha não pode estar vazia.\n";
                continue;
            }

            if (jogadores.find(apelido) != jogadores.end()) {
                std::cout << "ERRO: jogador já existente\n";
            } else {
                jogadores[apelido] = {apelido, nome, email, senha};
                std::cout << "Jogador " << apelido << " cadastrado com sucesso\n";
            }
        } else if (entrada == "2") { // Remover Jogador
            std::cout << "Digite o apelido do jogador a ser removido: ";
            std::string apelido;
            std::getline(std::cin, apelido);

            if (apelido.empty()) {
                std::cout << "ERRO: O apelido não pode estar vazio.\n";
                continue;
            }

            if (jogadores.find(apelido) == jogadores.end()) {
                std::cout << "ERRO: jogador inexistente\n";
            } else {
                jogadores.erase(apelido);
                std::cout << "Jogador " << apelido << " removido com sucesso\n";
            }
        } else if (entrada == "0") { // Entrar no sistema
            std::cout << "Digite o apelido: ";
            std::string apelido;
            std::getline(std::cin, apelido);

            if (apelido.empty()) {
                std::cout << "ERRO: O apelido não pode estar vazio.\n";
                continue;
            }

            std::cout << "Digite a senha: ";
            std::string senha;
            std::getline(std::cin, senha);

            if (senha.empty()) {
                std::cout << "ERRO: A senha não pode estar vazia.\n";
                continue;
            }

            if (jogadores.find(apelido) != jogadores.end() && jogadores[apelido].getSenha() == senha) {
                std::cout << "Bem-vindo, " << jogadores[apelido].getNome() << "!\n";
            } else {
                std::cout << "ERRO: apelido ou senha incorretos\n";
                continue;
            }
        } else if (entrada == "3") { // Jogar Othello
            if (jogadores.size() < 2) {
                std::cout << "ERRO: É necessário ter pelo menos dois jogadores cadastrados para jogar Othello.\n";
                continue;
            }

            std::cout << "Iniciando o jogo Othello...\n";
            auto it = jogadores.begin();
            Jogador* jogador1 = &it->second;
            ++it;
            Jogador* jogador2 = &it->second;
            Othello othello(jogador1, jogador2);

            while (!othello.verificarFimDeJogo()) {
                othello.exibirJogadorAtual();
                int linha, coluna;
                std::cout << "Digite a linha e a coluna: ";
                std::cin >> linha >> coluna;

                if (othello.jogadaValida(linha, coluna)) {
                    othello.capturarPecas(linha, coluna);
                } else {
                    std::cout << "Jogada inválida. Tente novamente.\n";
                }
            }
        } else if (entrada == "4") { // Jogar Lig 4
            if (jogadores.size() < 2) {
                std::cout << "ERRO: É necessário ter pelo menos dois jogadores cadastrados para jogar Lig 4.\n";
                continue;
            }

            std::cout << "Iniciando o jogo Lig 4...\n";
            auto it = jogadores.begin();
            Jogador jogador1 = it->second;
            ++it;
            Jogador jogador2 = it->second;
            Lig4 lig4(jogador1, jogador2);
            lig4.jogar();
        } else if (entrada == "5") { // Jogar Jogo da Velha
            if (jogadores.size() < 2) {
                std::cout << "ERRO: É necessário ter pelo menos dois jogadores cadastrados para jogar Jogo da Velha.\n";
                continue;
            }

            std::cout << "Iniciando o jogo Jogo da Velha...\n";
            auto it = jogadores.begin();
            Jogador jogador1 = it->second;
            ++it;
            Jogador jogador2 = it->second;
            JogoDaVelha jogoDaVelha;

            while (true) {
                jogoDaVelha.exibirTabuleiro();
                int linha, coluna;
                char jogadorAtual = (jogoDaVelha.getTurnoAtual() % 2 == 0) ? 'X' : 'O';
                std::cout << "Jogador " << (jogadorAtual == 'X' ? jogador1.getApelido() : jogador2.getApelido())
                          << " (" << jogadorAtual << "), faça sua jogada (linha coluna): ";
                std::cin >> linha >> coluna;

                if (!jogoDaVelha.fazerJogada(linha, coluna, jogadorAtual)) {
                    std::cout << "Jogada inválida. Tente novamente.\n";
                    continue;
                }

                if (jogoDaVelha.verificarVitoria(jogadorAtual)) {
                    jogoDaVelha.exibirTabuleiro();
                    std::cout << "Jogador " << (jogadorAtual == 'X' ? jogador1.getApelido() : jogador2.getApelido())
                              << " (" << jogadorAtual << ") venceu!\n";
                    break;
                }

                if (jogoDaVelha.verificarEmpate()) {
                    jogoDaVelha.exibirTabuleiro();
                    std::cout << "O jogo terminou empatado!\n";
                    break;
                }

                jogoDaVelha.passarTurno();
            }
        } else {
            std::cout << "ERRO: opção desconhecida\n";
        }
    }

    return 0;
}
