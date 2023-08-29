#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct info
{
    char name[50];
    int phone;
    char email[50];
};

struct no
{
    info value;
    no *prox;
};

bool listaVazia(no *lista)
{
    if (lista == NULL)
        return true;
    else
        return false;
}

no *criarLista()
{
    return NULL;
}

no *insereInicio(no *lista, info info)
{
    no *novo = new no;
    novo->value = info;
    novo->prox = lista;
    return novo;
}

no *inserirOrdenadoNome(no *lista, info info)
{
    lista->prox->value = info;
    no *aux = lista;
    no *ant = NULL;
    while (aux != NULL && strcmp(aux->value.name, info.name) < 0)
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

no *excluirNome(no *lista, info info)
{
    if (listaVazia(lista))
    {
        cout << "Lista vazia" << endl;
        return lista;
    }

    no *aux = lista;
    while (strcmp(aux->prox->value.name, info.name) != 0)
    {
        aux = aux->prox;
    }
    no *aux2 = aux->prox;
    aux->prox = aux->prox->prox;
    delete aux2;
    return lista;
}

void buscarNome(no *lista, info info)
{
    if (listaVazia(lista))
    {
        cout << "Lista vazia" << endl;
        return;
    }

    no *aux = lista;
    while (strcmp(aux->value.name, info.name) != 0)
    {
        aux = aux->prox;
    }
    cout << "Nome: " << aux->value.name << endl;
    cout << "Telefone: " << aux->value.phone << endl;
    cout << "Email: " << aux->value.email << endl;
}

void buscarPhone(no *lista, info info)
{
    if (listaVazia(lista))
    {
        cout << "Lista vazia" << endl;
        return;
    }

    no *aux = lista;
    while (aux->prox->value.phone != info.phone)
    {
        aux = aux->prox;
    }
    cout << "Nome: " << aux->prox->value.name << endl;
    cout << "Telefone: " << aux->prox->value.phone << endl;
    cout << "Email: " << aux->prox->value.email << endl;
}

void imprimeLista(no *lista)
{
    if (listaVazia(lista))
    {
        cout << "Lista vazia" << endl;
        return;
    }

    no *p;
    for (p = lista; p != NULL; p = p->prox)
    {
        cout << "Nome: " << p->value.name << endl;
        cout << "Telefone: " << p->value.phone << endl;
        cout << "Email: " << p->value.email << endl;
        cout << endl;
    }
}

void menu()
{
    no *lista;
    info value;
    int op = -1;

    while (op != 0)
    {
        system("cls");
        cout << "--- CADASTRO ---" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Criar lista" << endl;
        cout << "2 - Inserir no inicio" << endl;
        cout << "3 - Inserir ordenado por nome" << endl;
        cout << "4 - Excluir pelo nome" << endl;
        cout << "5 - Buscar nome" << endl;
        cout << "6 - Buscar telefone" << endl;
        cout << "7 - Imprimir lista" << endl;
        cout << "\nInforme a opcao: ";
        cin >> op;
        if (op == 1)
        {
            lista = criarLista();
        }
        else if (op == 2)
        {
            cout << "Informe o nome: ";
            cin >> value.name;
            cout << "Informe o numero: ";
            cin >> value.phone;
            cout << "Informe o e-mail: ";
            cin >> value.email;
            lista = insereInicio(lista, value);
        }
        else if (op == 3)
        {
            cout << "Informe o nome: ";
            cin >> value.name;
            cout << "Informe o numero: ";
            cin >> value.phone;
            cout << "Informe o e-mail: ";
            cin >> value.email;
            lista = inserirOrdenadoNome(lista, value);
        }
        else if (op == 4)
        {
            cout << "Informe o nome: ";
            cin >> value.name;
            lista = excluirNome(lista, value);
        }
        else if (op == 5)
        {
            cout << "Informe o nome: ";
            cin >> value.name;
            buscarNome(lista, value);
        }
        else if (op == 6)
        {
            cout << "Informe o numero: ";
            cin >> value.phone;
            buscarPhone(lista, value);
        }
        else if (op == 7)
        {
            imprimeLista(lista);
        }
    }
}

int main()
{
    menu();

    return 0;
}