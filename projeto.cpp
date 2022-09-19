#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<fstream>

using namespace std;

struct show
{
	int codigo;
	char nomeartistico[100];
	int formacao;
	char tipomusica[100];
	char musica[100];
	bool excluido;
	int votos;
};

show apresentacao;

fstream arquivo;

void cadastro()
{
	apresentacao.votos = 0;

	do
	{
		cout << "Código do participante: " << endl;
		cin >> apresentacao.codigo;
	}
	while(!(apresentacao.codigo > 0));

	cin.ignore();

	do
	{
		cout << "Digite seu nome artistico: " << endl;
		cin.getline(apresentacao.nomeartistico, 100);
	}
	while(!(strlen(apresentacao.nomeartistico) > 0));

	do
	{
		cout << "Tipo de formação (Solo, Dupla, Banda): " << endl;
		cout << "1 - Solo " << endl;
		cout << "2 - Dupla " << endl;
		cout << "3 - Banda " << endl;
		cin >> apresentacao.formacao;
	}
	while(!(apresentacao.formacao == 1 || apresentacao.formacao == 2 || apresentacao.formacao == 3));

	cin.ignore();

	do
	{
		cout << "Tipo de musica: " << endl;
		cin.getline(apresentacao.tipomusica, 100);
	}
	while(!(strlen(apresentacao.tipomusica) > 0));

	do
	{
		cout << "Nome da musica: " << endl;
		cin.getline(apresentacao.musica, 100);
	}
	while(!(strlen(apresentacao.musica) > 0));

	apresentacao.excluido = false;

	arquivo.seekp(0, arquivo.end);

	arquivo.write((char*) &apresentacao, sizeof(apresentacao));
}

void listar()
{
	bool encontrado = false;
	arquivo.seekg(0, arquivo.beg);

	while(arquivo.read((char*) &apresentacao, sizeof(apresentacao)))
	{
		if(apresentacao.excluido == false)
		{
			cout << "Código: " << apresentacao.codigo << endl;
			cout << "Nome artistico: " << apresentacao.nomeartistico << endl;
			cout << "Tipo de formação (Solo, Dupla, Banda): " << endl;
			cout << "1 - Solo " << endl;
			cout << "2 - Dupla " << endl;
			cout << "3 - Banda " << endl;
			cout << apresentacao.formacao << endl;
			cout << "Tipo de musica: " << apresentacao.tipomusica << endl;
			cout << "Nome da musica: " << apresentacao.musica << endl;

			cout << endl;

			encontrado = true;
		}
	}

	if(!encontrado)
		cout << "Não há participantes!" << endl;

	arquivo.clear();
}

void editar()
{
	int codigo;
	char op;
	bool encontrado = false;

	do
	{
		cout << "Entre com o código do participante que você deseja editar: " << endl;
		cin >> codigo;
	}
	while(!(codigo > 0));

	arquivo.seekg(0, arquivo.beg);

	while(arquivo.read((char*) &apresentacao, sizeof(apresentacao)))
	{
		if(codigo == apresentacao.codigo && apresentacao.excluido == false)
		{
			cout << "Dados: " << endl;
			cout << "Código: " << apresentacao.codigo << endl;
			cout << "Nome artistico: " << apresentacao.nomeartistico << endl;
			cout << "Tipo de formação (Solo, Dupla, Banda): " << endl;
			cout << "1 - Solo: " << endl;
			cout << "2 - Dupla: " << endl;
			cout << "3 - Banda: " << endl;
			cout << apresentacao.formacao << endl;
			cout << "Tipo de musica: " << apresentacao.tipomusica << endl;
			cout << "Nome da musica: " << apresentacao.musica << endl;

			do
			{
				cout << "Deseja editar(S/N)?" << endl;
				cin >> op;
			}
			while(!(op == 'S' || op == 'N'));

			if(op == 'S')
			{
				cin.ignore();

				do
				{
					cout << "Digite seu nome artistico: " << endl;
					cin.getline(apresentacao.nomeartistico, 100);
				}
				while(!(strlen(apresentacao.nomeartistico) > 0));

				do
				{
					cout << "Tipo de formação (Solo, Dupla, Banda): " << endl;
					cout << "1 - Solo: " << endl;
					cout << "2 - Dupla: " << endl;
					cout << "3 - Banda: " << endl;
					cin >> apresentacao.formacao;
				}
				while(!(apresentacao.formacao == 1 || apresentacao.formacao == 2 || apresentacao.formacao == 3));

				cin.ignore();

				do
				{
					cout << "Tipo de musica: " << endl;
					cin.getline(apresentacao.tipomusica, 100);
				}
				while(!(strlen(apresentacao.tipomusica) > 0));

				do
				{
					cout << "Nome da musica: " << endl;
					cin.getline(apresentacao.musica, 100);
				}
				while(!(strlen(apresentacao.musica) > 0));

				arquivo.seekp(arquivo.tellp() - sizeof(apresentacao));

				arquivo.write((char*) &apresentacao, sizeof(apresentacao));
			}

			encontrado = true;
		}
	}

	if(!encontrado)
		cout << "Participante não encontrado!" << endl;

	arquivo.clear();
}

void pesquisar()
{
	int codigo;
	bool encontrado = false;

	do
	{
		cout << "Entre com o código do participante que você deseja pesquisar: " << endl;
		cin >> codigo;
	}
	while(!(codigo > 0));
	arquivo.seekg(0, arquivo.beg);

	while(arquivo.read((char*) &apresentacao, sizeof(apresentacao)))
	{
		if(codigo == apresentacao.codigo && apresentacao.excluido == false)
		{
			cout << "Dados: " << endl;
			cout << "Código: " << apresentacao.codigo << endl;
			cout << "Nome artistico: " << apresentacao.nomeartistico << endl;
			cout << "Tipo de formação (Solo, Dupla, Banda): " << endl;
			cout << "1 - Solo " << endl;
			cout << "2 - Dupla " << endl;
			cout << "3 - Banda " << endl;
			cout << apresentacao.formacao << endl;
			cout << "Tipo de musica: " << apresentacao.tipomusica << endl;
			cout << "Nome da musica: " << apresentacao.musica << endl;

			encontrado = true;
		}
	}
	if(!encontrado)
	{
		cout << "Participante não encontrado!" << endl;
	}

	arquivo.clear();
}

void excluir()
{
	int codigo;
	char op;
	bool encontrado = false;

	do
	{
		cout << "Entre com o código do participante que você deseja excluir: " << endl;
		cin >> codigo;
	}
	while(!(codigo > 0));

	arquivo.seekg(0, arquivo.beg);


	while(arquivo.read((char*) &apresentacao, sizeof(apresentacao)))
	{
		if(codigo == apresentacao.codigo && apresentacao.excluido == false)
		{
			cout << "Dados: " << endl;
			cout << "Código: " << apresentacao.codigo << endl;
			cout << "Nome artistico: " << apresentacao.nomeartistico << endl;
			cout << "Tipo de formação (Solo, Dupla, Banda): " << endl;
			cout << "1 - Solo " << endl;
			cout << "2 - Dupla " << endl;
			cout << "3 - Banda " << endl;
			cout << apresentacao.formacao << endl;
			cout << "Tipo de musica: " << apresentacao.tipomusica << endl;
			cout << "Nome da musica: " << apresentacao.musica << endl;

			encontrado = true;

			do
			{
				cout << "Deseja excluir(S/N)?" << endl;
				cin >> op;
			}
			while(!(op == 'S' || op == 'N'));

			if(op == 'S')
			{
				apresentacao.excluido = true;

				arquivo.seekp(arquivo.tellp() - sizeof(apresentacao));

				arquivo.write((char*) &apresentacao, sizeof(apresentacao));
			}
		}
	}
	if(!encontrado)
		cout << "Participante não encontrado!" << endl;

	arquivo.clear();
}

void extra()
{
	int codigo_cantor;
	bool encontrado = false;

	do
	{
		cout << "Digite o codigo do cantor com melhor apresentação" << endl;
		cin >> codigo_cantor;
	}
	while(!(codigo_cantor > 0));

	arquivo.seekg(0, arquivo.beg);

	while(arquivo.read((char*) &apresentacao, sizeof(apresentacao)))
	{
		if(codigo_cantor == apresentacao.codigo && apresentacao.excluido == false)
		{
			apresentacao.votos = apresentacao.votos + 1;
			arquivo.seekp(arquivo.tellp() - sizeof(apresentacao));
			arquivo.write((char*) &apresentacao, sizeof(apresentacao));
			encontrado = true;
		}
	}
	if(!encontrado)
	{
		cout << "Participante não encontrado!" << endl;
	}

	arquivo.clear();
}

void campea()
{
	int maior = 0;
	int codigo;

	arquivo.seekg(0, arquivo.beg);
	while(arquivo.read((char*) &apresentacao, sizeof(apresentacao)))
	{
		if(apresentacao.excluido == false && apresentacao.votos > maior)
		{
			maior = apresentacao.votos;
			codigo = apresentacao.codigo;
		}
	}
	arquivo.clear();

	cout << endl;

	arquivo.seekg(0, arquivo.beg);
	while(arquivo.read((char*) &apresentacao, sizeof(apresentacao)))
	{
		if(apresentacao.codigo == codigo)
		{
			cout << "VENCEDOR:" << endl;
			cout << "Código: " << apresentacao.codigo << endl;
			cout << "Nome artistico: " << apresentacao.nomeartistico << endl;
			cout << "Tipo de formação (Solo, Dupla, Banda): " << endl;
			cout << "1 - Solo " << endl;
			cout << "2 - Dupla " << endl;
			cout << "3 - Banda " << endl;
			cout << apresentacao.formacao << endl;
			cout << "Tipo de musica: " << apresentacao.tipomusica << endl;
			cout << "Nome da musica: " << apresentacao.musica << endl;
			cout << "Votos: " << apresentacao.votos << endl;
		}
	}
	arquivo.clear();
}

int main()
{
	setlocale(LC_ALL, "PORTUGUESE");

	arquivo.open("TheVoice.txt", ios :: in | ios :: out | ios :: binary);

	if(!arquivo.is_open())
		arquivo.open("TheVoice.txt", ios :: in | ios :: out | ios :: binary | ios :: trunc);

	int opcao;

	do
	{
		do
		{
			cout << "Menu: " << endl;
			cout << "1 - Cadastrar " << endl;
			cout << "2 - Editar " << endl;
			cout << "3 - Listar " << endl;
			cout << "4 - Pesquisar " << endl;
			cout << "5 - Excluir " << endl;
			cout << "6 - Votar " << endl;
			cout << "7 - Campeão" << endl;
			cout << "8 - Sair" << endl;

			cout << "Entre com a opção" << endl;
			cin >> opcao;
		}
		while(!(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5 || opcao == 6 || opcao == 7 || opcao == 8));

		switch(opcao)
		{
		case 1:
			cadastro();
			system("pause");
			system("cls");
			break;
		case 2:
			editar();
			system("pause");
			system("cls");
			break;
		case 3:
			listar();
			system("pause");
			system("cls");
			break;
		case 4:
			pesquisar();
			system("pause");
			system("cls");
			break;
		case 5:
			excluir();
			system("pause");
			system("cls");
			break;
		case 6:
			extra();
			system("pause");
			system("cls");
			break;
		case 7:
			campea();
			system("pause");
			system("cls");
			break;
		}
	}
	while(opcao != 8);

	arquivo.close();

	return 0;
}
