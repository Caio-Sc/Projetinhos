/*
PGC_Exp07e8 - Sistema de hotel (Check-in, Check-out, Familia, Hospede, Visao geral, Taxa de ocupacao, Pesquisar, Alterar Dados).
Pedro Alcantara Krivochein - 14/05/2021
Gustavo Barbieri Esposar - 14/05/2021
Caio de Nasi Sclavi - 14/05/2021
*/

#include <stdio.h>

typedef struct hospede
{
	char nome[100];
	int idade;
	char cpf[14];
	char email[100];
	int apartamento;
} tipoHospede;

typedef struct familia
{
	int membrosTotal, dependentes, responsaveis;
	tipoHospede membros[10];
} tipoFamilia;

typedef struct apartamento
{
	int status; //-1 - Desocupado, 0 - Reservado, 1 - Ocupado.
	int andar;
	int apartamento;
	tipoFamilia familia;
} tipoApartamento;

int main()
{
	tipoApartamento apartamentos[280]; //Matriz dos apartamentos [andar * apartamento].
	for (int i = 0; i < 280; i++)	   //Deixa todos os apartamentos com valor -1 (Apartamento Livre).
		apartamentos[i].status = -1;

	int hospedeAtual = 0; //Variavel auxiliar para saber o id do hospede.
	int familiaAtual = 0;

	char selecao;					  //Variavel auxiliar para saber a escolha do usuario dentro do menu.
	int andar = -1, apartamento = -1; //Variaveis auxilixar para saber o andar e o apartamento escolhidos pelo usuario.
	int apartamentosOcupados = 0, apartamentosReservados = 0;	  //Numero de apartamentos ocupados, numero de apartamentos reservados.

	int ch; //Variavel auxiliar para limpar buffer.

	int h, membros, apAtual; //Variaveris auxiliar

	char dado[100]; //Variavel auxiliar para receber o dado para pesquisa do hospede.
	int guardaDados[4]; //Variavel auxiliar para ajudar na pesquisa e alteracao de dados do hospede.

	//Numero do apartamento = (apartamento + 100 * andar).

	while (selecao != '0')
	{
		printf("|====================================================================|\n");

		printf("\n\t\t\t     -=-=-MENU-=-=-\n"
			   "1 - Fazer check-in.\n"
			   "2 - Fazer check-out.\n"
			   "3 - Fazer reserva.\n"
			   "4 - Desfazer reserva.\n"
			   "5 - Checar reservas.\n"
			   "6 - Checar apartamentos (Visao geral).\n"
			   "7 - Checar apartamento (Especifico).\n"
			   "8 - Taxa de ocupacao.\n"
			   "9 - Procurar por um hospede / Alterar dados\n"
			   "0 - Sair/Voltar.\n\n"
			   "Selecao: ");

		scanf(" %c", &selecao);

		do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer

		switch (selecao)
		{ //Selecao do menu.

			//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

		case '0': //Finalizar programa.
			printf("\n-=-=-=-=-=-=-=-=-=-=-=-\n");

			printf("\n-=FINALIZANDO SISTEMA=-\n");

			break;

			//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

		case '1': //Check-in.
			printf("\n|====================================================================|\n");

			printf("\n\t\t\t   -=-=-Check-in-=-=-\n");

			printf("\n\t\t\t     -=APARTAMENTO=-    \n"
				   "\t\t\t      0 - Voltar       \n\n");

			do
			{ //Loopa enquanto o apartamento escolhido estiver ocupado, até usuario dititar 0 para voltar ou até quando o usuário digitar que não quer continuar.

				do
				{ //Garante que o andar seja valido (entre 1 e 20).
					printf("Andar (1 a 20): ");
					scanf("%d", &andar);

					if ((andar < 1 || andar > 20) && andar != 0)
						printf("Andar invalido (Tem de ser de 1 a 20).\n");

				} while ((andar < 1 || andar > 20) && andar != 0);

				if (andar == 0) //Caso o andar seja 0, retornar ao menu.
					continue;

				do
				{ //Garante que o apartamento seja valido (entre 1 e 14).
					printf("Os quartos disponiveis para o andar %d sao: ", andar);
					for (char i = 0; i < 14; i++)			  //Rotaciona por quarto do andar escolhido para verificar os quartos validos
						if (apartamentos[(andar - 1) * 14 + i].status == -1) //Checa se o quarto é valido
							printf("%d ", i + 1);			  //Informa o usuario os quartos validos do andar
					printf("\nApartamento (1 a 14): ");
					scanf("%d", &apartamento);

					if ((apartamento < 1 || apartamento > 14) && apartamento != 0)
						printf("Apartamento invalido (Tem de ser de 1 a 14).\n");

				} while ((apartamento < 1 || apartamento > 14) && apartamento != 0);

				if (apartamento == 0) //Caso o apartamento seja 0, retornar ao menu.
					continue;

				if (apartamentos[(andar - 1) * 14 + (apartamento - 1)].status != -1) { //Checa se o apartamento esta ocupado (Diferente de -1).
					printf("\nO APARTAMENTO No.%d ESTA OCUPADO\n"
						   "Deseja digitar outro apartamento? (s/n)\n",
						   apartamento + 100 * andar); //Calcula o numero do apartamento (apartamento + 100 * andar).
					scanf(" %c", &selecao);
				}

			} while (apartamentos[(andar - 1) * 14 + (apartamento - 1)].status != -1 && andar != 0 && apartamento != 0 && selecao != 'n' && selecao != 'N');

			if (andar == 0 || apartamento == 0)
				continue; //Caso tenha escolhido o comando voltar, retornar ao menu.
			if (selecao == 'n' || selecao == 'N')
				continue; //Caso tenha escolhido que nao quer tentar outro apartamento, retornar ao menu.

			do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer.

			selecao = '\0'; //Limpa a seleção.

			apAtual = (andar - 1) * 14 + (apartamento - 1); //Pega a posicao do apartamento na lista 0 a 279.
			
			printf("\n -=DADOS DO HOSPEDE=-  \n\n");

			printf("Nome completo: ");
			fgets(apartamentos[apAtual].familia.membros[0].nome, 100, stdin);

			do{ //Loopa enquanto a idade for menor que 18 ou caso o usuario queira cancelar o check-in.
				printf("Idade: ");
				scanf("%d", &apartamentos[apAtual].familia.membros[0].idade);

				if(apartamentos[apAtual].familia.membros[0].idade < 18){
					printf("Voce precisa ter mais de 18 anos para fazer um check-in.\n"
						   "Voce deseja cancelar o check-in (s/n)\n");
					scanf(" %c", &selecao);
				}

			}while(apartamentos[apAtual].familia.membros[0].idade < 18 && selecao != 'S' && selecao != 's');

			if (selecao == 's' || selecao == 'S')
				continue; //Caso tenha escolhido que quer cancelar o check-in, retornar ao menu.

			do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer.

			printf("CPF: ");
			fgets(apartamentos[apAtual].familia.membros[0].cpf, 14, stdin);

			printf("E-mail: ");
			fgets(apartamentos[apAtual].familia.membros[0].email, 100, stdin);
			
			do{ //Loopa enquanto os membros na familia nao forem entre 1 e 10.
				printf("Quantos membros na familia? (1 a 10) ");
				scanf("%d", &membros);
				
				if(membros < 1 || membros > 10)
					printf("Quantidade invalida.\n");
				
			}while(membros < 1 || membros > 10);
				
			apartamentos[apAtual].familia.membrosTotal = membros; //Atualiza a quantidade de membros da familia.

			apartamentos[apAtual].familia.membros[0].apartamento = apartamento + 100 * andar; //Atualiza o apartamento do membro da familia.

			apartamentos[apAtual].familia.responsaveis++; //Adiciona um responsavel na familia.

			do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer.

			for(int i = 1; i < membros; i++){ //Loopa coletando os dados dos outros membros da familia.
				printf("\nNome completo: ");
				fgets(apartamentos[apAtual].familia.membros[i].nome, 100, stdin);

				do{
					printf("Idade: ");
					scanf("%d", &apartamentos[apAtual].familia.membros[i].idade);

					if(apartamentos[apAtual].familia.membros[i].idade < 1)
						printf("Idade invalida.\n");

					do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer.

				}while(apartamentos[apAtual].familia.membros[i].idade < 1);

				if(apartamentos[apAtual].familia.membros[i].idade < 18){ //Checa se e menor de idade, se sim, nao pergunta cpf e e-mail e adiciona um dependente.
					apartamentos[apAtual].familia.dependentes++;

				}else{
					apartamentos[apAtual].familia.responsaveis++;

					printf("CPF: ");
					fgets(apartamentos[apAtual].familia.membros[i].cpf, 14, stdin);

					printf("E-mail: ");
					fgets(apartamentos[apAtual].familia.membros[i].email, 100, stdin);
				}

				apartamentos[apAtual].familia.membros[i].apartamento = apartamento + 100 * andar;
			}

			apartamentos[apAtual].status = 1; // Ocupa o apartamento, colocando-o igual a 1.
			apartamentosOcupados++;

			printf("\n -=CHECK-IN CONCLUIDO=-\n"
				   "APARTAMENTO No.%d OCUPADO\n",
				   apartamento + 100 * andar);

			printf("\nPressione ENTER para continuar.");
			getchar(); //Pausa o console, esperando alguma tecla do usuario.

			break;

			//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

		case '2': //Check-out.
			printf("\n-=-=-=-=-=-=-=-=-=-=-=-\n");

			printf("\n-=-=-=-Check-out-=-=-=-\n");

			printf("\n    -=APARTAMENTO=-    \n"
				   "      0 - Voltar       \n\n");

			do
			{ //Garante que o andar seja valido (entre 1 e 20).
				printf("Andar (1 a 20): ");
				scanf("%d", &andar);

				if ((andar < 1 || andar > 20) && andar != 0)
					printf("Andar invalido (Tem de ser de 1 a 20).\n");

			} while ((andar < 1 || andar > 20) && andar != 0);

			if (andar == 0) //Caso o andar seja 0, retornar ao menu.
				continue;

			do
			{ //Garante que o apartamento seja valido (entre 1 e 14).
				printf("Os quartos ocupados no andar %d sao: ", andar);
				for (char i = 0; i < 14; i++)							//Rotaciona por quarto do andar escolhido para verificar os quartos validos
					if (apartamentos[(andar - 1) * 14 + i].status == 1) //Checa se o quarto é valido
						printf("%d ", i + 1);							//Informa o usuario os quartos validos do andar
				printf("\nApartamento (1 a 14): ");						//Informa o usuario os quartos validos do andar
				scanf("%d", &apartamento);
		
				if ((apartamento < 1 || apartamento > 14) && apartamento != 0)
					printf("Apartamento invalido (Tem de ser de 1 a 14).\n");

			} while ((apartamento < 1 || apartamento > 14) && apartamento != 0);

			if (apartamento == 0) //Caso o apartamento seja 0, retornar ao menu.
				continue;

			apAtual = (andar - 1) * 14 + (apartamento - 1);

			if (apartamentos[apAtual].status != -1){ //Checa se o apartamento esta ocupado (Diferente de -1).
				apartamentos[apAtual].status = -1; //Deixa o apartamento livre (Igual a -1).

				apartamentosOcupados--;

				for(int i = 0; i < apartamentos[apAtual].familia.membrosTotal; i++){ //Reseta a familia do quarto quando da check-out.
					for(int j = 0; j < 100; j++){
						apartamentos[apAtual].familia.membros[i].nome[j] = '\0';
						apartamentos[apAtual].familia.membros[i].cpf[j] = '\0';
						apartamentos[apAtual].familia.membros[i].email[j] = '\0';
					}
					apartamentos[apAtual].familia.membrosTotal = 0;
					apartamentos[apAtual].familia.dependentes = 0;
					apartamentos[apAtual].familia.responsaveis = 0;
				}

				printf("\n-=CHECK-OUT CONCLUIDO=-\n"
					   "APARTAMENTO No.%d LIVRE\n",
					   apartamento + 100 * andar);
			}
			else
			{
				printf("\nO APARTAMENTO No.%d NAO ESTA OCUPADO\n", apartamento + 100 * andar);
			}

			do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer

			printf("\nPressione ENTER para continuar.");
			getchar(); //Pausa o console, esperando alguma tecla do usuario.

			break;

		//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		
		case '3': //Fazer reservas.
			printf("\n-=-=-=-=-=-=-=-=-=-=-=-\n");

			printf("\n-=-=-FAZER RESERVA-=-=-\n");

			printf("\n    -=APARTAMENTO=-    \n"
				   "      0 - Voltar       \n\n");

			do
			{ //Loopa enquanto o apartamento escolhido estiver ocupado, até usuario dititar 0 para voltar ou até quando o usuário digitar que não quer continuar.

				do
				{ //Garante que o andar seja valido (entre 1 e 20).
					printf("Andar (1 a 20): ");
					scanf("%d", &andar);

					if ((andar < 1 || andar > 20) && andar != 0)
						printf("Andar invalido (Tem de ser de 1 a 20).\n");

				} while ((andar < 1 || andar > 20) && andar != 0);

				if (andar == 0) //Caso o andar seja 0, retornar ao menu.
					continue;

				do
				{ //Garante que o apartamento seja valido (entre 1 e 14).
					printf("Os quartos disponiveis para o andar %d sao: ", andar);
					for (char i = 0; i < 14; i++)							//Rotaciona por quarto do andar escolhido para verificar os quartos validos
						if (apartamentos[(andar - 1) * 14 + i].status == -1) //Checa se o quarto é valido
							printf("%d ", i + 1);							//Informa o usuario os quartos validos do andar
					printf("\nApartamento (1 a 14): ");
					scanf("%d", &apartamento);

					if ((apartamento < 1 || apartamento > 14) && apartamento != 0)
						printf("Apartamento invalido (Tem de ser de 1 a 14).\n");

				} while ((apartamento < 1 || apartamento > 14) && apartamento != 0);

				if (apartamento == 0) //Caso o apartamento seja 0, retornar ao menu.
					continue;

				if (apartamentos[(andar - 1) * 14 + (apartamento - 1)].status != -1) { //Checa se o apartamento esta ocupado (Diferente de -1).
					printf("\nO APARTAMENTO No.%d ESTA OCUPADO\n"
						   "Deseja digitar outro apartamento? (s/n)\n",
						   apartamento + 100 * andar); //Calcula o numero do apartamento (apartamento + 100 * andar).
					scanf(" %c", &selecao);
				}

			} while (apartamentos[(andar - 1) * 14 + (apartamento - 1)].status != -1 && andar != 0 && apartamento != 0 && selecao != 'n' && selecao != 'N');

			if (andar == 0 || apartamento == 0)
				continue; //Caso tenha escolhido o comando voltar, retornar ao menu.
			if (selecao == 'n' || selecao == 'N')
				continue; //Caso tenha escolhido que nao quer tentar outro apartamento, retornar ao menu.

			do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer.

			selecao = '\0'; //Limpa a seleção.

			apAtual = (andar - 1) * 14 + (apartamento - 1); //Pega a posicao do apartamento na lista 0 a 279.
			
			printf("\n -=DADOS DO HOSPEDE=-  \n\n");

			printf("Nome completo: ");
			fgets(apartamentos[apAtual].familia.membros[0].nome, 100, stdin);

			do{ //Loopa enquanto a idade for menor que 18 ou caso o usuario queira cancelar o check-in.
				printf("Idade: ");
				scanf("%d", &apartamentos[apAtual].familia.membros[0].idade);

				if(apartamentos[apAtual].familia.membros[0].idade < 18){
					printf("Voce precisa ter mais de 18 anos para fazer um check-in.\n"
						   "Voce deseja cancelar o check-in (s/n)\n");
					scanf(" %c", &selecao);
				}

			}while(apartamentos[apAtual].familia.membros[0].idade < 18 && selecao != 'S' && selecao != 's');

			if (selecao == 's' || selecao == 'S')
				continue; //Caso tenha escolhido que quer cancelar o check-in, retornar ao menu.
			
			do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer

			printf("CPF: ");
			fgets(apartamentos[apAtual].familia.membros[0].cpf, 14, stdin);

			printf("E-mail: ");
			fgets(apartamentos[apAtual].familia.membros[0].email, 100, stdin);

			membros = 0;
			do{ //Loopa enquanto os membros na familia nao forem entre 1 e 10.
				printf("Quantos membros na familia? (1 a 10) ");
				scanf("%d", &membros);
				
				if(membros < 1 || membros > 10)
					printf("Quantidade invalida.\n");
				
			}while(membros < 1 || membros > 10);

			apartamentos[apAtual].familia.membrosTotal = membros; //Atualiza a quantidade de membros da familia.

			apartamentos[apAtual].status = 0; // Reserva o apartamento, colocando-o igual a 0.

			apartamentosReservados++;

			printf("\n -=RESERVA CONCLUIDA=- \n"
				   "APARTAMENTO No.%d RESERVADO\n",
				   apartamento + 100 * andar);

			do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer

			printf("\nPressione ENTER para continuar.");
			getchar(); //Pausa o console, esperando alguma tecla do usuario.

			break;

		//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		
		case '4': //Desfazer reservas.
			printf("\n-=-=-=-=-=-=-=-=-=-=-=-\n");

			printf("\n-=-DESFAZER RESERVAS-=-\n");

			printf("\n    -=APARTAMENTO=-    \n"
				   "      0 - Voltar       \n\n");

			do
			{ //Garante que o andar seja valido (entre 1 e 20).
				printf("Andar (1 a 20): ");
				scanf("%d", &andar);

				if ((andar < 1 || andar > 20) && andar != 0)
					printf("Andar invalido (Tem de ser de 1 a 20).\n");

			} while ((andar < 1 || andar > 20) && andar != 0);

			if (andar == 0) //Caso o andar seja 0, retornar ao menu.
				continue;

			do
			{ //Garante que o apartamento seja valido (entre 1 e 14).
				printf("Os quartos ocupados no andar %d sao: ", andar);
				for (char i = 0; i < 14; i++)							//Rotaciona por quarto do andar escolhido para verificar os quartos validos
					if (apartamentos[(andar - 1) * 14 + i].status != -1) //Checa se o quarto é valido
						printf("%d ", i + 1);							//Informa o usuario os quartos validos do andar
				printf("\nApartamento (1 a 14): ");
				scanf("%d", &apartamento);

				if ((apartamento < 1 || apartamento > 14) && apartamento != 0)
					printf("Apartamento invalido (Tem de ser de 1 a 14).\n");

			} while ((apartamento < 1 || apartamento > 14) && apartamento != 0);

			if (apartamento == 0) //Caso o apartamento seja 0, retornar ao menu.
				continue;

			if (apartamentos[(andar - 1) * 14 + (apartamento - 1)].status != -1){ //Checa se o apartamento esta ocupado/reservado (Diferente de -1).
				apartamentos[(andar - 1) * 14 + (apartamento - 1)].status = -1; //Deixa o apartamento livre (Igual a -1).

				apartamentosReservados--;

				printf("\n-=RESERVA DESFEITA=-\n"
					   "APARTAMENTO No.%d LIVRE\n",
					   apartamento + 100 * andar);
			}
			else
			{
				printf("\nO APARTAMENTO No.%d NAO ESTA OCUPADO\n", apartamento + 100 * andar);
			}

			do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer

			printf("\nPressione ENTER para continuar.");
			getchar(); //Pausa o console, esperando alguma tecla do usuario.
			break;

		//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		
		case '5': //Checar reservas.
			printf("\n-=-=-=-=-=-=-=-=-=-=-=-\n");

			printf("\n-=-=-=-RESERVAS=-=-=-=-\n\n");

			for(int i = 0; i < 280; i++)
				if(apartamentos[i].status == 0)
					printf("Andar: %d\n"
						   "Apartamento: %d\n"
						   "Reserva por: %s"
						   "Membros da familia: %d\n\n", (i / 14) + 1, i % 14 + 1, apartamentos[i].familia.membros[0].nome, apartamentos[i].familia.membrosTotal);
				
			printf("\nPressione ENTER para continuar.");
			getchar(); //Pausa o console, esperando alguma tecla do usuario.
			break;

		//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		
		case '6': //Mostrar apartamentos.
			printf("\n-=-=-=-=-=-=-=-=-=-=-=-\n");

			printf("\n-=-=-APARTAMENTOS=-=-=-\n\n"
				   "R - Reservado\n\n"
				   "O - Ocupado\n\n");

			printf("Livres   - %d\n", 280 - apartamentosOcupados - apartamentosReservados);
			printf("Ocupados - %d\n", apartamentosOcupados);
			printf("Reservados - %d\n\n", apartamentosReservados);

			printf("    ");
			for(int i = 0; i < 14; i++) //Adiciona os numeros dos apartamentos na parte de cima da matriz.
				if(i >= 9)
					printf("%d  ", i + 1);
				else
					printf(" %d  ", i + 1);

			printf("\n");
			for (int i = 19; i >= 0; i--)
			{ //Adiciona os numeros dos andares (de cima para baixo).
				printf("%2d |", i + 1);

				for (int j = 0; j < 14; j++)
				{ //Adiciona os apartamentos (Livre - ' ' | Ocupado - 'X').
					if (apartamentos[i * 14 + j].status == 0)
						printf(" R |");
					else if (apartamentos[i * 14 + j].status == 1)
						printf(" O |");
					else
						printf("   |");
				}
				printf("\n");
			}

			printf("\nPressione ENTER para continuar.");
			getchar(); //Pausa o console, esperando alguma tecla do usuario.

			break;

			//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

		case '7': //Dados apartamento (Especifico).

			printf("\n-=-=-=-=-=-=-=-=-=-=-=-\n");

			printf("\n-=-=-=APARTAMENTO=-=-=-\n"
				   "      0 - Voltar       \n\n");

			do
			{ //Garante que o andar seja valido (entre 1 e 20).
				printf("Andar (1 a 20): ");
				scanf("%d", &andar);

				if ((andar < 1 || andar > 20) && andar != 0)
					printf("Andar invalido (Tem de ser de 1 a 20).\n");

			} while ((andar < 1 || andar > 20) && andar != 0);

			if (andar == 0) //Caso o andar seja 0, retornar ao menu.
				continue;

			do
			{ //Garante que o apartamento seja valido (entre 1 e 14).
				printf("Apartamento (1 a 14): ");
				scanf("%d", &apartamento);

				if ((apartamento < 1 || apartamento > 14) && apartamento != 0)
					printf("Apartamento invalido (Tem de ser de 1 a 14).\n");

			} while ((apartamento < 1 || apartamento > 14) && apartamento != 0);

			if (apartamento == 0) //Caso o apartamento seja 0, retornar ao menu.
				continue;

			apAtual = (andar - 1) * 14 + (apartamento - 1);

			if (apartamentos[apAtual].status != -1)
			{												  //Checa se o apartamento esta ocupado (Diferente de -1).
				h = 0;//apartamentos[andar - 1][apartamento - 1]; //Pega o id do hospede, a partir da matriz dos apartamentos.
				printf("\nNo.Apartamento: %d\n"
					   "\n      -=FAMILIA=-      \n"
					   "Membros: %d\n"
					   "Dependentes: %d\n"
					   "Responsaveis: %d\n\n",
					   apartamento + 100 * andar, apartamentos[apAtual].familia.membrosTotal, apartamentos[apAtual].familia.dependentes, apartamentos[apAtual].familia.responsaveis); //Pega os dados do hospede a partir do seu id.
				printf("Voce gostaria de ver os dados dos membros da familia?(s/n): ");
				scanf(" %c", &selecao);
				if (selecao == 's' || selecao == 'S')
				{
					for (int i = 0; i < apartamentos[apAtual].familia.membrosTotal; i++)
					{
						printf("\nNome: %s", apartamentos[apAtual].familia.membros[i].nome);
						printf("Idade: %d\n", apartamentos[apAtual].familia.membros[i].idade);

						if(apartamentos[apAtual].familia.membros[i].idade >= 18) //Checa se é menor de idade.
							printf("CPF: %s", apartamentos[apAtual].familia.membros[i].cpf);

						printf("Apartamento: %d\n", apartamentos[apAtual].familia.membros[i].apartamento);

						if(apartamentos[apAtual].familia.membros[i].idade >= 18) //Checa se é menor de idade.
							printf("Email: %s\n", apartamentos[apAtual].familia.membros[i].email);
					}
				}
			}
			else
			{
				printf("\nNo.Apartamento: %d\n\n"
					   "ESTE APARTAMENTO ESTA LIVRE. \n",
					   apartamento + 100 * andar);
			}

			do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer

			printf("\nPressione ENTER para continuar.");
			getchar(); //Pausa o console, esperando alguma tecla do usuario.

			break;

			//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

		case '8': //Taxa de ocupacao.
			printf("\n-=-=-=-=-=-=-=-=-=-=-=-\n");

			printf("\n-=-DADOS DE OCUPACAO-=-\n"
				   "\n   -=Apartamentos=-    \n"
				   "Livres   - %d\n"
				   "Ocupados - %d\n"
				   "Reservados - %d\n"
				   "Taxa     - %.2f%c\n",
				   280 - apartamentosOcupados - apartamentosReservados, apartamentosOcupados, apartamentosReservados, ((float)(apartamentosOcupados + apartamentosReservados) / 280) * 100, '%');

			printf("\nPressione ENTER para continuar.");
			getchar(); //Pausa o console, esperando alguma tecla do usuario.

			break;

			//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

		case '9': //Procurar por um hospede.
			printf("\n-=-=-=-=-=-=-=-=-=-=-=-\n");

			printf("Por qual dado voce deseja procurar pelo hospede?\n\n"
				   "1 - Nome\n"
				   "2 - CPF\n"
				   "3 - E-mail\n"
				   "0 - Voltar\n"
				   "-> ");

			do
			{ //Loopa enquanto o usuário não escolher uma das opções.
				scanf(" %c", &selecao);
			} while (selecao != '1' && selecao != '2' && selecao != '3' && selecao != '0');

			if(selecao == '0') //Volta ao menu caso o usuario escolha voltar.
				continue;

			do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer

			for (int i = 0; dado[i] != '\0'; i++) //Limpa a variavel "dado".
				dado[i] = '\0';

			printf("\nDigite aqui o dado: ");
			fgets(dado, 100, stdin);

			guardaDados[0] = -1; //Reseta a variavel de checagem se houve um resultado.
			for (int i = 0; i < 280; i++) //Loopa pelos apartamentos.
				if (apartamentos[i].status != -1) //Checa se o apartamento esta ocupado/reservado.
					for (int j = 0; j < apartamentos[i].familia.membrosTotal; j++) //Loopa pelos membros da familia naquele apartamento.
						for (int k = 0; dado[k] != '\0'; k++) //Checa se todos os caracteres batem com o dado inserido pelo usuario.
							switch (selecao)
							{
							case '1': //Nome
									if (apartamentos[i].familia.membros[j].nome[k] == dado[k])
									{
										if (dado[k + 1] == '\n') //Caso chegue no final e todos os dados batam, ele salva o caminho ate o membro (Apartamento e numero do membro).
										{
											guardaDados[0] = i;
											guardaDados[1] = j;
										}
									}
									else
									{
										break; //Caso os dados nao batam, vai para o proximo membro.
									}
								break;
							case '2': //CPF
									if (apartamentos[i].familia.membros[j].cpf[k] == dado[k])
									{
										if (dado[k + 1] == '\n') //Caso chegue no final e todos os dados batam, ele salva o caminho ate o membro (Apartamento e numero do membro).
										{
											guardaDados[0] = i;
											guardaDados[1] = j;
										}
									}
									else
									{
										break; //Caso os dados nao batam, vai para o proximo membro.
									}
								break;
							case '3': //E-mail
									if (apartamentos[i].familia.membros[j].email[k] == dado[k])
									{
										if (dado[k + 1] == '\n') //Caso chegue no final e todos os dados batam, ele salva o caminho ate o membro (Apartamento e numero do membro).
										{
											guardaDados[0] = i;
											guardaDados[1] = j;
										}
									}
									else
									{
										break; //Caso os dados nao batam, vai para o proximo membro.
									}
								break;
							}

			if (guardaDados[0] != -1)
			{
				printf("\n      -=HOSPEDE=-      \n");
				printf("1 - Nome: %s", apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].nome);
				printf("2 - Idade: %d\n", apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].idade);

				if(apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].idade >= 18) //Checa se o membro e maior de idade.
					printf("3 - CPF: %s", apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].cpf);

				printf("4 - Apartamento: %d\n", apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].apartamento);

				if(apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].idade >= 18) //Checa se o membro e maior de idade.
					printf("5 - Email: %s\n", apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].email);
					
				do {//Loopa enquanto o usuario nao altere um dado ou queira sair.
					printf("Gostaria de editar algum dado? (s/n): ");
					scanf(" %c", &selecao);

					if (selecao == 'S' || selecao == 's')
					{
						printf("Qual dado gostaria de alterar?: ");
						scanf(" %c", &selecao);

						do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer

						switch (selecao)
						{
						case '1': //Nome.
							printf("Coloque o novo nome: ");
							fgets(apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].nome, 100, stdin);
							printf("Nome alterado com sucesso!");
							break;

						case '2': //Idade.
							printf("Coloque a nova idade: ");
							scanf("%d", apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].idade);

							do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer

							printf("Idade alterada com sucesso!");
							break;
						case '3': //CPF
							printf("Coloque o novo CPF: ");

							fgets(apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].cpf, 14, stdin);

							printf("CPF alterado com sucesso!");
							break;
						case '4': //Apartamento
							printf("\n  -=NOVO APARTAMENTO=- \n\n");
							do { //Garante que o andar seja valido (entre 1 e 20).
								printf("Andar (1 a 20): ");
								scanf("%d", &andar);

								if ((andar < 1 || andar > 20) && andar != 0)
									printf("Andar invalido (Tem de ser de 1 a 20).\n");

							} while ((andar < 1 || andar > 20) && andar != 0);

							if (andar == 0) //Caso o andar seja 0, retornar ao menu.
								continue;

							do
							{ //Garante que o apartamento seja valido (entre 1 e 14).
								printf("Apartamento (1 a 14): "); //Informa o usuario os quartos validos do andar
								scanf("%d", &apartamento);
						
								if ((apartamento < 1 || apartamento > 14) && apartamento != 0)
									printf("Apartamento invalido (Tem de ser de 1 a 14).\n");
									
							} while ((apartamento < 1 || apartamento > 14) && apartamento != 0);

							if (apartamento == 0) //Caso o apartamento seja 0, retornar ao menu.
								continue;
							
							do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer

							guardaDados[2] = (andar - 1) * 14 + (apartamento - 1);

							if (apartamentos[guardaDados[2]].status != -1) //Checa se o apartamento esta ocupado (Diferente de -1).
							{
								printf("Apartamento em uso, escolha outro por favor\n");

								printf("Pressione ENTER para continuar");
								getchar(); //Pausa o console, esperando por uma tecla do usuario.

								guardaDados[3] = 0; //Sair do loop.
							}
							else
							{
								printf("Voce deseja mover todos os membros da familia desse quarto? (s/n)\n");
								scanf(" %c", &selecao);

								if(selecao == 'S' || selecao == 's'){
									apartamentos[guardaDados[2]].status = 1; //Ocupa o novo apartamento.

									for(int i = 0; i < apartamentos[guardaDados[0]].familia.membrosTotal; i++) //Roda pelos membros da familia, colocando o seu novo apartamento.
										apartamentos[guardaDados[0]].familia.membros[i].apartamento = apartamento + 100 * andar;

									apartamentos[guardaDados[2]].familia = apartamentos[guardaDados[0]].familia; //Atualiza a familia do novo apartamento.
									apartamentos[guardaDados[0]].status = -1; //Desocupa o apartamento antigo.

								}else{
									apartamentos[guardaDados[2]].status = 1; //Ocupa o novo apartamento.
									apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].apartamento = apartamento + 100 * andar; //Atualiza o apartamento do membro que esta mudando.
									apartamentos[guardaDados[2]].familia = apartamentos[guardaDados[0]].familia; //Atualiza a familia do novo apartamento.

									apartamentosOcupados++;

									if(apartamentos[guardaDados[0]].familia.membrosTotal <= 1) //Caso nao haja mais membros no antigo apartamento, deixa ele livre.
										apartamentos[guardaDados[0]].status = -1;
								}

								printf("Apartamento alterado com sucesso!");
								guardaDados[3] = 0; //Sair do loop.
							}
							break;
						case '5':
							printf("Coloque o novo email: ");
							fgets(apartamentos[guardaDados[0]].familia.membros[guardaDados[1]].email, 100, stdin);
							printf("Email alterado com sucesso!");
							break;
						}
					}
				} while(guardaDados[3] == 0 && selecao != 'N' && selecao != 'n');
				
				do { ch = fgetc(stdin); } while (ch != EOF && ch != '\n'); //Limpar buffer

				printf("\nPressione ENTER para continuar.");
				getchar(); //Pausa o console, esperando alguma tecla do usuario.
			}
			else
			{
				printf("HOSPEDE NAO ENCONTRADO\n");

				printf("\nPressione ENTER para continuar.");
				getchar(); //Pausa o console, esperando alguma tecla do usuario.
			}

			break;

			//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

		default: //Voltar
			continue;
			break;
		}
	}
}