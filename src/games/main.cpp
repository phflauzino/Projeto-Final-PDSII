#include <iostream>
#include <unordered_map>
#include <regex>
#include <fstream>
#include <stdexcept>
#include "../players/jogador.hpp"
#include "../utils/utils.hpp"
#include "JogoDaVelha.hpp"
#include "lig4.hpp"
#include "othello.hpp"

// Função para validar o email
bool validarEmail(const std::string& email) {
    const std::regex padraoEmail(R"(^[\w.%+-]+@[\w.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, padraoEmail);
}

// Função para cadastrar jogadores
void cadastrarJogadores(std::unordered_map<std::string, Jogador>& jogadores) {
    std::string entrada;

    while (true) {
        try {
            std::cout << "\nBem-vindo ao sistema de cadastro de jogadores!\n";
            std::cout << "Digite 's' para sair do cadastro ou qualquer outra tecla para continuar.\n";
            std::getline(std::cin, entrada);

            if (entrada == "s") {
                break;
            }

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
        } catch (const std::exception& e) {
            std::cout << "Ocorreu um erro: " << e.what() << "\n";
        }
    }
}

// Função para remover um jogador
void removerJogador(std::unordered_map<std::string, Jogador>& jogadores) {
    try {
        std::string apelido;
        std::cout << "Digite o apelido do jogador a ser removido: ";
        std::getline(std::cin, apelido);

        auto it = jogadores.find(apelido);
        if (it != jogadores.end()) {
            jogadores.erase(it);
            std::cout << "Jogador " << apelido << " removido com sucesso!\n";
        } else {
            std::cout << "Jogador não encontrado.\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Ocorreu um erro ao tentar remover o jogador: " << e.what() << "\n";
    }
}

// Função para verificar se há jogadores suficientes
bool verificarJogadoresSuficientes(const std::unordered_map<std::string, Jogador>& jogadores) {
    if (jogadores.size() < 2) {
        std::cout << "ERRO: É necessário ter pelo menos dois jogadores cadastrados para jogar.\n";
        return false;
    }
    return true;
}

// Função para salvar os jogadores em um arquivo
void salvarJogadores(const std::unordered_map<std::string, Jogador>& jogadores) {
    try {
        std::ofstream arquivo("jogadores.txt");

        if (!arquivo.is_open()) {
            throw std::runtime_error("ERRO: Não foi possível abrir o arquivo para salvar.");
        }

        for (const auto& jogador : jogadores) {
            arquivo << jogador.second.getApelido() << "\n"
                    << jogador.second.getNome() << "\n"
                    << jogador.second.getEmail() << "\n"
                    << jogador.second.getSenha() << "\n";
        }

        std::cout << "Jogadores salvos com sucesso!\n";
        arquivo.close();
    } catch (const std::exception& e) {
        std::cout << "Ocorreu um erro ao salvar jogadores: " << e.what() << "\n";
    }
}

// Função para carregar os jogadores de um arquivo
void carregarJogadores(std::unordered_map<std::string, Jogador>& jogadores) {
    try {
        std::ifstream arquivo("jogadores.txt");

        if (!arquivo.is_open()) {
            std::cout << "Nenhum arquivo de jogadores encontrado, iniciando cadastro...\n";
            return;  // Se o arquivo não existir, simplesmente retorna
        }

        std::string apelido, nome, email, senha;
        while (std::getline(arquivo, apelido) && std::getline(arquivo, nome) &&
               std::getline(arquivo, email) && std::getline(arquivo, senha)) {
            jogadores[apelido] = Jogador(apelido, nome, email, senha);
        }

        std::cout << "Jogadores carregados com sucesso!\n";
        arquivo.close();
    } catch (const std::exception& e) {
        std::cout << "Ocorreu um erro ao carregar jogadores: " << e.what() << "\n";
    }
}

// Função para login
bool login(const std::unordered_map<std::string, Jogador>& jogadores, std::shared_ptr<Jogador>& jogadorLogado) {
    try {
        std::string apelido, senha;

        std::cout << "Digite seu apelido: ";
        std::getline(std::cin, apelido);

        // Verificar se o jogador existe
        auto it = jogadores.find(apelido);
        if (it == jogadores.end()) {
            std::cout << "Jogador não encontrado.\n";
            return false;
        }

        std::cout << "Digite sua senha: ";
        std::getline(std::cin, senha);

        // Verificar se a senha está correta
        if (it->second.getSenha() == senha) {
            jogadorLogado = std::make_shared<Jogador>(it->second);
            std::cout << "Login bem-sucedido, " << apelido << "!\n";
            return true;
        } else {
            std::cout << "Senha incorreta.\n";
            return false;
        }
    } catch (const std::exception& e) {
        std::cout << "Erro no processo de login: " << e.what() << "\n";
        return false;
    }
}

// Função para entrar ou cadastrar um jogador
void entrarOuCadastrar(std::unordered_map<std::string, Jogador>& jogadores) {
    try {
        std::string opcao;
        std::cout << "Escolha uma opção:\n";
        std::cout << "1 - Cadastrar um novo jogador\n";
        std::cout << "2 - Fazer login\n";
        std::cout << "Digite sua opção (1 ou 2): ";
        std::getline(std::cin, opcao);

        if (opcao == "1") {
            cadastrarJogadores(jogadores);
        } else if (opcao == "2") {
            std::shared_ptr<Jogador> jogadorLogado;
            if (login(jogadores, jogadorLogado)) {
                std::cout << "Bem-vindo de volta, " << jogadorLogado->getApelido() << "!\n";
            } else {
                std::cout << "Login falhou.\n";
            }
        } else {
            std::cout << "Opção inválida. Tente novamente.\n";
            entrarOuCadastrar(jogadores);
        }
    } catch (const std::exception& e) {
        std::cout << "Erro no processo de entrada ou cadastro: " << e.what() << "\n";
    }
}

// Função para garantir o login de dois jogadores
void garantirLoginDoisJogadores(std::unordered_map<std::string, Jogador>& jogadores, std::shared_ptr<Jogador>& jogador1, std::shared_ptr<Jogador>& jogador2) {
    try {
        while (true) {
            std::cout << "\n** Jogador 1 **\n";
            if (login(jogadores, jogador1)) {
                std::cout << "Jogador 1 logado com sucesso!\n";
                break;
            }

            std::cout << "Tente novamente para o Jogador 1.\n";
        }

        while (true) {
            std::cout << "\n** Jogador 2 **\n";
            if (login(jogadores, jogador2)) {
                std::cout << "Jogador 2 logado com sucesso!\n";
                break;
            }

            std::cout << "Tente novamente para o Jogador 2.\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Erro no processo de login dos jogadores: " << e.what() << "\n";
    }
}

// Função para selecionar o jogo
void selecionarJogo(std::unordered_map<std::string, Jogador>& jogadores) {
    try {
        std::shared_ptr<Jogador> jogador1, jogador2;
        
        garantirLoginDoisJogadores(jogadores, jogador1, jogador2);

        std::string entrada;

        while (true) {
            std::cout << "\nEscolha um jogo para jogar:\n";
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

            if (entrada == "3") {
                std::cout << "Iniciando o jogo Othello...\n";
                Othello jogoOthello(jogador1, jogador2); 
                jogoOthello.jogar();  
            } else if (entrada == "4") {
                std::cout << "Iniciando o jogo Lig 4...\n";
                Lig4 jogoLig4(jogador1, jogador2); 
                jogoLig4.jogar();  
            } else if (entrada == "5") {
                std::cout << "Iniciando o jogo Jogo da Velha...\n";
                JogoDaVelha jogoJogoDaVelha;  
                jogoJogoDaVelha.jogar();  
            } else {
                std::cout << "ERRO: opção desconhecida\n";
            }
        }
    } catch (const std::exception& e) {
        std::cout << "Erro no processo de seleção do jogo: " << e.what() << "\n";
    }
}

int main() {
    std::unordered_map<std::string, Jogador> jogadores;

    // Carregar os jogadores do arquivo
    carregarJogadores(jogadores);

    // Entrar ou cadastrar jogadores
    entrarOuCadastrar(jogadores);

    // Salvar os jogadores no arquivo
    salvarJogadores(jogadores);

    // Selecionar e jogar um jogo
    selecionarJogo(jogadores);

    return 0;
}


