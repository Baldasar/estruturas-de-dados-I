#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct cliente
{
    int cod;
    char nome[50];
    char telefone[20];
    char email[50];
};

struct carro
{
    int cod_cliente;
    char placa[10];
    char marca[20];
    char modelo[50];
};

struct no_cliente
{
    cliente value;
    no_cliente *prox;
    no_cliente *ant;
};

struct no_carro
{
    carro value;
    no_carro *prox;
    no_carro *ant;
};

bool listaVazia(no_cliente *lista)
{
    if (lista == NULL)
        return true;
    else
        return false;
}

no_cliente *criarListaCliente()
{
    return NULL;
}

no_carro *criarListaCarro()
{
    return NULL;
}

no_cliente *inserirOrdenadoNome(no_cliente *lista, cliente info)
{
    lista->prox->value = info;
    no_cliente *aux = lista;
    no_cliente *ant = NULL;
    while (aux != NULL && strcmp(aux->value.nome, info.nome) < 0)
    {
        ant = aux;
        aux = aux->prox;
    }
    if (ant == NULL)
    {
        lista->prox->prox = lista;
        return lista->prox;
    }
    else
    {
        ant->prox = lista->prox;
        lista->prox->prox = aux;
        return lista;
    }
}

no_carro *inserirAutomovel(no_carro *lista_carro, no_cliente *lista_cliente, carro info)
{
    if (listaVazia(lista_cliente))
    {
        cout << "Nao ha clientes cadastrados" << endl;
        return lista_carro;
    }

    no_cliente *aux = lista_cliente;

    while (aux != NULL && aux->value.cod != info.cod_cliente)
    {
        aux = aux->prox;
        if (aux->value.cod == info.cod_cliente)
        {
            no_carro *novo = new no_carro;
            novo->value = info;
            lista_carro->prox = novo;
            return lista_carro;
        }
    }
    if (aux == NULL)
    {
        cout << "Cliente nao encontrado" << endl;
        return lista_carro;
    }
}

no_carro *excluirAutomovelCod(no_carro *lista_carro, no_cliente *lista_cliente, carro info)
{
    if (lista_carro == NULL)
    {
        cout << "Nao ha carros cadastrados" << endl;
        return lista_carro;
    }

    no_carro *aux = lista_carro;
    
    while(lista_carro->value.cod_cliente != info.cod_cliente)
    {
        aux = aux->prox;
        if (aux->value.cod_cliente == info.cod_cliente)
        {
            no_carro *ant = aux->ant;
            ant->prox = aux->prox;
            delete aux;
            return lista_carro;
        }
    }
}

void buscarClientePeloNome(no_cliente *lista_cliente, cliente info) {
    if (listaVazia(lista_cliente))
    {
        cout << "Lista vazia" << endl;
        return;
    }

    no_cliente *aux = lista_cliente;
    while (aux != NULL && strcmp(aux->value.nome, info.nome) != 0)
    {
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        cout << "Cliente nao encontrado" << endl;
        return;
    }
    else
    {
        cout << "Cliente encontrado" << endl;
        cout << "Codigo: " << aux->value.cod << endl;
        cout << "Nome: " << aux->value.nome << endl;
        cout << "Telefone: " << aux->value.telefone << endl;
        cout << "Email: " << aux->value.email << endl;
    }
}

void buscarCarroPeloCliente(no_carro *lista_carro, cliente info) {
    if (lista_carro == NULL)
    {
        cout << "Nao ha carros cadastrados" << endl;
        return;
    }

    no_carro *aux = lista_carro;
    while (aux != NULL && aux->value.cod_cliente != info.cod)
    {
        aux = aux->prox;
        if (aux->value.cod_cliente == info.cod)
        {
            cout << "Carro encontrado" << endl;
            cout << "Placa: " << aux->value.placa << endl;
            cout << "Marca: " << aux->value.marca << endl;
            cout << "Modelo: " << aux->value.modelo << endl;
        }
    }
}

void listarClienteCarro(no_carro *lista_carro, no_cliente *lista_cliente) {
    if (listaVazia(lista_cliente))
    {
        cout << "Nao ha clientes cadastrados" << endl;
        return;
    }

    no_cliente *aux = lista_cliente;
    no_carro *aux_carro = lista_carro;

    while (aux != NULL)
    {
        cout << "Codigo: " << aux->value.cod << endl;
        cout << "Nome: " << aux->value.nome << endl;
        cout << "Telefone: " << aux->value.telefone << endl;
        cout << "Email: " << aux->value.email << endl;
        while (aux_carro != NULL)
        {
            if (aux->value.cod == aux_carro->value.cod_cliente)
            {
                cout << "Placa: " << aux_carro->value.placa << endl;
                cout << "Marca: " << aux_carro->value.marca << endl;
                cout << "Modelo: " << aux_carro->value.modelo << endl;
            }
            aux_carro = aux_carro->prox;
        }
        aux = aux->prox;
    }
}

void menu()
{
    no_cliente *lista_cliente;
    no_carro *lista_carro;
    cliente cliente;
    carro carro;
    int op = -1;

    while (op != 0)
    {
        system("cls");
        cout << "--- CADASTRO ---" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Cria Lista Cliente" << endl;
        cout << "2 - Cria Lista Carro" << endl;
        cout << "3 - Inserir Cliente" << endl;
        cout << "4 - Inserir Carro" << endl;
        cout << "5 - Excluir Carro" << endl;
        cout << "6 - Buscar Cliente pelo Nome" << endl; 
        cout << "7 - Buscar Carro pelo Cliente" << endl;
        cout << "8 - Listar Cliente e Carro" << endl;
        cout << "\nInforme a opcao: ";
        cin >> op;

        if (op == 1)
        {
            lista_cliente = criarListaCliente();
        }
        else if (op == 2)
        {
            lista_carro = criarListaCarro();
        }
        else if (op == 3)
        {
            lista_cliente = inserirOrdenadoNome(lista_cliente, cliente);
        }
        else if (op == 4)
        {
            lista_carro = inserirAutomovel(lista_carro, lista_cliente, carro);
        }
        else if(op == 5)
        {
            lista_carro = excluirAutomovelCod(lista_carro, lista_cliente, carro);
        }
        else if (op == 6)
        {
            buscarClientePeloNome(lista_cliente, cliente);
        }
        else if (op == 7)
        {
            buscarCarroPeloCliente(lista_carro, cliente);
        }
        else if (op == 8)
        {
            listarClienteCarro(lista_carro, lista_cliente);
        }
        else if (op == 0)
        {
            cout << "Saindo..." << endl;
            return;
        }
        else
        {
            cout << "Opcao invalida" << endl;
        }
    }
}

int main()
{
    menu();

    return 0;
}