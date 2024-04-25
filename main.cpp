#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Definição da estrutura Funcionario
struct Funcionario {
    int prontuario;
    string nome;
    double salario;
};

// Função para adicionar um novo funcionário à lista
void incluirFuncionario(vector<Funcionario> &funcionarios) {
    Funcionario novoFuncionario;
    cout << "---------------------------" << endl;
    cout << "Incluir Novo Funcionario" << endl;
    cout << "---------------------------" << endl;
    cout << "Digite o prontuario: ";
    cin >> novoFuncionario.prontuario;

    // Verifica se o prontuário já existe na lista
    auto it = find_if(funcionarios.begin(), funcionarios.end(), 
                      [&novoFuncionario](const Funcionario& f) { return f.prontuario == novoFuncionario.prontuario; });
    if (it != funcionarios.end()) {
        cout << "Funcionario com o mesmo prontuario ja existe." << endl;
        return;
    }

    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, novoFuncionario.nome);
    cout << "Digite o salario: ";
    cin >> novoFuncionario.salario;

    funcionarios.push_back(novoFuncionario);
    cout << "Funcionario adicionado com sucesso." << endl;
}

// Função para excluir um funcionário da lista pelo prontuário
void excluirFuncionario(vector<Funcionario> &funcionarios) {
    int prontuario;
    cout << "---------------------------" << endl;
    cout << "Excluir Funcionario" << endl;
    cout << "---------------------------" << endl;
    cout << "Digite o prontuario do funcionario a ser excluido: ";
    cin >> prontuario;

    auto it = find_if(funcionarios.begin(), funcionarios.end(), 
                      [&prontuario](const Funcionario& f) { return f.prontuario == prontuario; });
    if (it != funcionarios.end()) {
        funcionarios.erase(it);
        cout << "Funcionario excluido com sucesso." << endl;
    } else {
        cout << "Funcionario nao encontrado." << endl;
    }
}

// Função para pesquisar um funcionário pelo prontuário
void pesquisarFuncionario(const vector<Funcionario> &funcionarios) {
    int prontuario;
    cout << "---------------------------" << endl;
    cout << "Pesquisar Funcionario" << endl;
    cout << "---------------------------" << endl;
    cout << "Digite o prontuario do funcionario a ser pesquisado: ";
    cin >> prontuario;

    auto it = find_if(funcionarios.begin(), funcionarios.end(), 
                      [&prontuario](const Funcionario& f) { return f.prontuario == prontuario; });
    if (it != funcionarios.end()) {
        cout << "Prontuario: " << it->prontuario << ", Nome: " << it->nome << ", Salario: " << it->salario << endl;
    } else {
        cout << "Funcionario nao encontrado." << endl;
    }
}

// Função para listar todos os funcionários
void listarFuncionarios(const vector<Funcionario> &funcionarios) {
    cout << "---------------------------" << endl;
    cout << "Lista de Funcionarios:" << endl;
    cout << "---------------------------" << endl;
    for (const auto& funcionario : funcionarios) {
        cout << "Prontuario: " << funcionario.prontuario << ", Nome: " << funcionario.nome << ", Salario: " << funcionario.salario << endl;
    }

    // Calcula o total dos salários
    double totalSalarios = 0;
    for (const auto& funcionario : funcionarios) {
        totalSalarios += funcionario.salario;
    }
    cout << "Total dos salarios: " << totalSalarios << endl;
}

int main() {
    vector<Funcionario> funcionarios;
    int opcao;

    do {
        cout << "\nMENU:" << endl;
        cout << "---------------------------" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Pesquisar" << endl;
        cout << "4. Listar" << endl;
        cout << "---------------------------" << endl;
        cout << "Digite sua opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            case 1:
                incluirFuncionario(funcionarios);
                break;
            case 2:
                excluirFuncionario(funcionarios);
                break;
            case 3:
                pesquisarFuncionario(funcionarios);
                break;
            case 4:
                listarFuncionarios(funcionarios);
                break;
            default:
                cout << "Opcao invalida." << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}
