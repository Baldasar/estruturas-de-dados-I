#include <iostream>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;

struct Item
{
    float valor;
    int cod;
    string nome;
};

class Pedido
{
public:
    int codPedido;
    string nomeCliente;
    float valorTotal;
    queue<Item> itens;

public:
    Pedido(int codPedido, string nomeCliente, float valorTotal)
    {
        this->codPedido = codPedido;
        this->nomeCliente = nomeCliente;
        this->valorTotal = valorTotal;
    }

    Pedido()
    {
        this->codPedido = 0;
        this->nomeCliente = "";
        this->valorTotal = 0;
    }

    void adicionarItem(Item item)
    {
        itens.push(item);
    }

    ~Pedido()
    {
    }
};

class Carrinho
{
public:
    queue<Item> itens;

public:
    void adicionarItem(Item item)
    {
        itens.push(item);
    }

    Pedido fecharPedido(int codPedido, string nomeCliente)
    {
        Pedido pedido(codPedido, nomeCliente, 0);
        int tam = itens.size();

        for (int i = 0; i < tam; i++)
        {

            pedido.adicionarItem(itens.back());
            pedido.valorTotal += itens.back().valor;
            removeItem();
        }
        return pedido;
    }

    void removeItem()
    {
        queue<Item> aux;
        int tam = itens.size();
        for (int i = 0; i < tam - 1; i++)
        {
            aux.push(itens.front());
            itens.pop();
        }
        itens = aux;
    }

    ~Carrinho()
    {
    }
};

void imprimeMenu(string cardapio[], int valores[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << i << " - " << cardapio[i] << " - R$" << valores[i] << endl;
    }
}

void imprimePedidos(queue<Pedido> pedidos)
{
    system("clear");
    if (pedidos.empty())
    {
        cout << "Nenhum pedido foi feito" << endl;
        return;
    }

    while (!pedidos.empty())
    {
        Pedido pedido = pedidos.front();
        cout << "-----------------------------------" << endl;
        cout << "Codigo do Pedido: " << pedido.codPedido << endl;
        cout << "Nome do Cliente: " << pedido.nomeCliente << endl;
        cout << "Valor Total: " << pedido.valorTotal << endl;
        cout << "-----------------------------------" << endl;
        cout << "Itens: " << endl;
        while (!pedido.itens.empty())
        {
            Item item = pedido.itens.front();
            cout << item.nome << endl;
            pedido.itens.pop();
        }
        cout << "-----------------------------------" << endl;
        pedidos.pop();
    }
}

void imprimirPedido(Pedido pedido)
{
    cout << "-----------------------------------" << endl;
    cout << "Codigo do Pedido: " << pedido.codPedido << endl;
    cout << "Nome do Cliente: " << pedido.nomeCliente << endl;
    cout << "Valor Total: " << pedido.valorTotal << endl;
    cout << "-----------------------------------" << endl;
    cout << "Itens: " << endl;
    while (!pedido.itens.empty())
    {
        Item item = pedido.itens.front();
        cout << item.nome << endl;
        pedido.itens.pop();
    }
    cout << "-----------------------------------" << endl;
}

void imprimeCarrinho(queue<Item> itens)
{
    if (itens.empty())
    {
        cout << "Nenhum item foi adicionado" << endl;
        return;
    }
    float valorTotal = 0;
    while (!itens.empty())
    {
        Item item = itens.front();
        cout << item.nome << endl;
        valorTotal += item.valor;
        itens.pop();
    }
    cout << "Valor Total: " << valorTotal << endl;
}

void limparCarrinho(queue<Item> &itens)
{
    while (!itens.empty())
    {
        itens.pop();
    }
}

void gerarCarrinho(queue<Pedido> &pedidos)
{
    Pedido pedido;
    Carrinho carrinho;
    Item item;
    string cardapio[10] = {"Arroz", "Feijao", "Macarrao", "Batata Frita", "Hamburguer", "Pizza", "Coxinha", "Pastel", "Bolo", "Suco"};
    int valores[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int opcao;
    do
    {
        if (opcao != 4 && opcao != 5)
        {
            system("clear");
        }
        cout << "---------------Opções--------------" << endl;
        cout << "01 - Adicionar item" << endl;
        cout << "02 - Limpar Carrinho" << endl;
        cout << "03 - Remover Ultimo item inserido" << endl;
        cout << "04 - Listar Carrinho" << endl;
        cout << "05 - Gerar pedido" << endl;
        cout << "99 - Sair" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Digite a opção:";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            system("clear");
            cout << "--------------Cardapio-------------" << endl;
            imprimeMenu(cardapio, valores);
            cout << "-----------------------------------" << endl
                 << endl;
            cout << "Digite o codigo do lanche: ";
            cin >> item.cod;
            item.valor = valores[item.cod];
            item.nome = cardapio[item.cod];
            carrinho.adicionarItem(item);
            break;
        case 2:
            system("clear");
            limparCarrinho(carrinho.itens);
            break;
        case 3:
            system("clear");
            carrinho.removeItem();
            break;
        case 4:
            system("clear");
            cout << "--------------Carrinho-------------" << endl;
            imprimeCarrinho(carrinho.itens);
            cout << "-----------------------------------" << endl
                 << endl;
            break;
        case 5:
            system("clear");
            if (carrinho.itens.empty())
            {
                cout << "Não Foi possivel gerar o pedido pois o carrinho está vazio" << endl;
                break;
            }
            cout << "Digite o nome do cliente: ";
            cin >> pedido.nomeCliente;
            pedido.codPedido = pedidos.size() + 1;
            pedido = carrinho.fecharPedido(pedido.codPedido, pedido.nomeCliente);
            imprimirPedido(pedido);
            pedidos.push(pedido);
            break;
        }
    } while (opcao != 99);
}

int main()
{
    queue<Pedido> pedidos;
    int opcao;

    do
    {
        if (opcao != 10)
        {
            system("clear");
        }
        cout << "---------------Opções--------------" << endl;
        cout << "01 - Gerar carrinho" << endl;
        cout << "10 - Listar Pedidos" << endl;
        cout << "99 - Sair" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Digite a opção:";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            gerarCarrinho(pedidos);
            break;
        case 10:
            imprimePedidos(pedidos);
            break;
        }
    } while (opcao != 99);

    return 0;
}