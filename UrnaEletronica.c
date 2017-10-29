/*
Autora: Camille de L. Jesus

Componente Curricular: EXA854 - MI Algoritmos

Data: /10/2014

Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Sistema para Urna Eletr�nica //

int main ()
{   //Os nomes das vari�veis s�o autoexplicativos e de f�cil entendimento, o que torna sua finalidade deduz�vel:

	int quantidade_eleitores = 0, voto_computado = 0, voto = 0, codigo_confirmacao = 0, votos_validos = 0, eleitor = 1;
	int voto0 = 0, voto_nulo = 0, voto17 = 0, voto22 = 0, voto31 = 0, voto38 = 0, recebe_voto17 = 0, recebe_voto22 = 0, recebe_voto31 = 0, recebe_voto38 = 0;

	float porcentual_17 = 0, porcentual_22 = 0, porcentual_31 = 0, porcentual_38 = 0, porcentual_0 = 0, porcentual_nulo = 0, porcentual_masculino = 0, porcentual_feminino = 0;
	float votos17_validos = 0, votos22_validos = 0, votos31_validos = 0, votos38_validos = 0;

	system ("color 0F");
	printf ("\n\t\t\t%c%c Sistema para Urna Eletr%cnica %c%c\n\n", 254, 254, 147, 254, 254);
	printf ("\nInforme a quantidade de eleitores: ");
	scanf ("%i", &quantidade_eleitores);   //Leitura pr�via da quantidade de eleitores.

	if (quantidade_eleitores > 0) {   //Para que haja a vota��o � necess�ria uma quantidade de eleitores maior que 0.
		
		while (voto_computado < quantidade_eleitores) {   //Compara��o entre vari�veis que enquanto for verdadeira gera o loop, quando for falsa exibir� o relat�rio de vota��o.
			system ("cls");
			printf ("\n\t%i%c Eleitor\n", eleitor, 167);   //Identifica��o do eleitor.
			printf ("\n\nPara votar digite: \n\n\n [0] - Voto Branco\n\n [17] - Sr%c. Maeli Gente Boa\n\n [22] - Sr. Loula do Brasil\n\n", 166);
			printf (" [31] - Dr%c. Lissandra Progresso\n\n [38] - Seu Maia da Ana\n\n", 166);
			scanf ("%i", &voto);   //Armazenamento do voto.
			system ("cls");

			if (voto == 0 || voto == 17 || voto == 22 || voto == 31 || voto == 38) {   //Verifica se o n�mero digitado for um dos c�digos de voto.
				//Verifica��o de voto:
				printf ("\nDigite: \n\n\n [1] - Confirmar\n\n [2] - Corrigir\n\n ");
				scanf ("%i", &codigo_confirmacao);

				if (codigo_confirmacao == 1) {   //Caso o eleitor queira confirmar o voto:
					voto_computado++;            //o voto � computado
					eleitor++;                   //e h� a mudan�a de eleitor.
					printf ("\n\n\nVoto confirmado.");
					getch ();
				} else {   //Caso o eleitor queira corrigir o voto; ele voltar� para o menu de candidatos e poder� votar novamente.
					printf ("\n\n\nVoto corrigido.");
					getch ();
					continue;   //Comando de desvio incondicional; pula os comandos intermedi�rios e passa para a pr�xima itera��o, no caso, novamente a vota��o.
				}
			} else {   //Caso o n�mero de voto n�o seja uma das op��es, o voto � anulado:
				printf ("\n\nVoto anulado.\a");
            	voto_computado++;   //o voto � computado
				eleitor++;          //h� a mudan�a de eleitor
				voto_nulo++;        //e soma 1 � vari�vel que armazena votos nulos.
				getch ();
			}

		    //Verifica��o de n�mero do voto e se houve confirma��o do mesmo, dependendo de qual c�digo foi digitado, ser� somado 1 �s respectivas vari�veis de armazenamento de voto.
			if (voto == 0 && codigo_confirmacao == 1) {
				voto0++;
			} else if (voto == 17 && codigo_confirmacao == 1) {
				voto17++;
			} else if (voto == 22 && codigo_confirmacao == 1) {
				voto22++;
			} else if (voto == 31 && codigo_confirmacao == 1) {
				voto31++;
			} else if (voto == 38 && codigo_confirmacao == 1) {
				voto38++;
			}

		}
		//C�lculo de porcentagem, exibi��o do total e da porcentagem de votos (no total) em cada op��o:
		system ("cls");
		//-no candidato n� 17
		porcentual_17 = (float)(voto17 * 100) / quantidade_eleitores;
		printf ("\n\nTotal de votos em Sr%c. Maeli Gente Boa: %i", 166, voto17);
		printf ("\nPorcentagem: %.2f%c", porcentual_17, 37);
		//-no candidato n� 22
		porcentual_22 = (float)(voto22 * 100) / quantidade_eleitores;
		printf ("\n\nTotal de votos em Sr. Loula do Brasil: %i", voto22);
		printf ("\nPorcentagem: %.2f%c", porcentual_22, 37);
		//-no candidato n� 31
		porcentual_31 = (float)(voto31 * 100) / quantidade_eleitores;
		printf ("\n\nTotal de votos em Dr%c. Lissandra Progresso: %i", 166, voto31);
		printf ("\nPorcentagem: %.2f%c", porcentual_31, 37);
		//-no candidato n� 38
		porcentual_38 = (float)(voto38 * 100) / quantidade_eleitores;
		printf ("\n\nTotal de votos em Seu Maia da Ana: %i", voto38);
		printf ("\nPorcentagem: %.2f%c", porcentual_38, 37);
		//-branco
		porcentual_0 = (float)(voto0 * 100) / quantidade_eleitores;
		printf ("\n\n\nTotal de votos Brancos: %i", voto0);
		printf ("\nPorcentagem: %.2f%c", porcentual_0, 37);
		//-nulo
		porcentual_nulo = (float)(voto_nulo * 100) / quantidade_eleitores;
		printf ("\n\nTotal de votos Nuloss: %i", voto_nulo);
		printf ("\nPorcentagem: %.2f%c\n\n\t\t", porcentual_nulo, 37);
		getch();
		system ("cls");
		//-nos candidatos de sexo masculino (candidato n� 22 e candidato n� 31)
		porcentual_masculino = (float)((voto22 + voto38) *100) / quantidade_eleitores;
    	printf ("\n\nTotal de votos em candidatos do sexo masculino: %i", voto22 + voto38);
    	printf ("\nPorcentagem: %.2f%c", porcentual_masculino);
		//-nos candidatos de sexo feminino (candidata n� 17 e candidata n� 31)
		porcentual_feminino = (float)((voto17 + voto31) *100) / quantidade_eleitores;
    	printf ("\n\n\nTotal de votos em candidatos do sexo feminino: %i", voto17 + voto31);
    	printf ("\nPorcentagem: %.2f%c", porcentual_feminino);
  		printf ("\n");

		/* Compara��o para estabelecer o(s) candidato(s) mais votado(s):
		[Foram usados v�rios "ifs" separadamente para no caso de empate, exibir os candidatos empatados.]
		Compara o n�mero de votos em cada candidato (por vez) com os demais candidatos, caso ele seja diferente de 0.*/
		if ((voto17 >= voto22) && (voto17 >= voto31) && (voto17 >= voto38) && (voto17 != 0)) {
  			printf ("\n\nA candidata [17] - Sr%c. Maeli Gente Boa foi a mais votada.", 166);
		}

		if ((voto22 >= voto17) && (voto22 >= voto31) && (voto22 >= voto38) && (voto22 != 0)) {
        	printf ("\n\nO candidato [22] - Sr. Loula do Brasil foi o mais votado.");
		}

		if ((voto31 >= voto17) && (voto31 >= voto22) && (voto31 >= voto38) && (voto31 != 0)) {
		printf ("\n\nA candidata [31] - Dr%c. Lissandra Progresso foi a mais votada.", 166);
		}

		if ((voto38 >= voto17) && (voto38 >= voto22) && (voto38 >= voto31) && (voto38 != 0)) {
			printf ("\n\nO candidato [38] - Seu Maia da Ana foi o mais votado.");
		}

		/* Verifica se algum candidato ficou sem voto:
		[Os votos s�o atribu�dos a vari�veis diferentes por que a vari�vel inicial de voto ainda ser� usada.
		Foram usados v�rios "ifs" separadamente por que mais de um candidato pode ter ficado sem voto.]
		Se sim, ela recebe o voto de todos os outros candidatos, para a compara��o do menos votado funcionar corretamente.
		Se n�o, ela recebe o valor que tinha anteriormente. */
		if (voto17 == 0) {
			recebe_voto17 = voto17 + voto22 + voto31 + voto38;
		} else {
			recebe_voto17 = voto17;
		}

		if (voto22 == 0) {
			recebe_voto22 = voto17 + voto22 + voto31 + voto38;
		} else {
			recebe_voto22 = voto22;
		}

		if (voto31 == 0) {
			recebe_voto31 = voto17 + voto22 + voto31 + voto38;
		} else {
			recebe_voto31 = voto31;
		}

		if (voto38 == 0) {
			recebe_voto38 = voto17 + voto22 + voto31 + voto38;
		} else {
			recebe_voto38 = voto38;
		}
		printf ("\n");

		/* Compara��o para estabelecer o(s) candidato(s) menos votado(s):
		[Foram usados v�rios "ifs" separadamente para no caso de empate, exibir os candidatos empatados.]
		Compara o n�mero de votos em cada candidato (por vez) com os demais candidatos, caso ele seja maior que 0.*/
		if ((voto17 <= recebe_voto22) && (voto17 <= recebe_voto31) && (voto17 <= recebe_voto38) && (voto17 > 0)) {
  			printf ("\n\nA candidata [17] - Sr%c. Maeli Gente Boa foi a menos votada.", 166);
		}

		if ((voto22 <= recebe_voto17) && (voto22 <= recebe_voto31) && (voto22 <= recebe_voto38) && (voto22 > 0)) {
        	printf ("\n\nO candidato [22] - Sr. Loula do Brasil foi o menos votado.");
		}

		if ((voto31 <= recebe_voto17) && (voto31 <= recebe_voto22) && (voto31 <= recebe_voto38) && (voto31 > 0)) {
			printf ("\n\nA candidata [31] - Dr%c. Lissandra Progresso foi a menos votada.", 166);
		}

		if ((voto38 <= recebe_voto17) && (voto38 <= recebe_voto22) && (voto38 <= recebe_voto31) && (voto38 > 0)) {
			printf ("\n\nO candidato [38] - Seu Maia da Ana foi o menos votado.");
		}
		votos_validos = quantidade_eleitores - (voto0 + voto_nulo);   //C�lculo dos votos v�lidos: total de eleitores - votos brancos e votos nulos.
		//C�lculo da porcentagem de votos v�lidos por candidato:
		votos17_validos = (float)(voto17 * 100) / votos_validos;
		votos22_validos = (float)(voto22 * 100) / votos_validos;
		votos31_validos = (float)(voto31 * 100) / votos_validos;
		votos38_validos = (float)(voto38 * 100) / votos_validos;

		//Pelo crit�rio da maioria absoluta de votos, verifica se alguma das porcentagens (de votos v�lidos por candidato) calculadas acima � maior que 50:
		if (votos17_validos > 50 || votos22_validos > 50 || votos31_validos > 50 || votos38_validos > 50) {   //se sim, n�o haver� segundo turno.
			printf ("\n\n\n\n\t\t\t %c%c%c N%co haver%c 2%c turno %c%c%c", 4, 4, 26, 198, 160, 167, 27, 4, 4);
		} else {   //se n�o, haver� segundo turno.
			printf ("\n\n\n\n\n\t\t\t\t %c%c%c Haver%c 2%c turno %c%c%c", 4, 4, 26, 160, 167, 27, 4, 4);
		}

		getch ();
		printf("\n");

	} else if (quantidade_eleitores < 0) {   //Caso a quantidade de eleitores informada seja um n�mero negativo.
		printf ("\n\n\n\aQuantidade de eleitores inv%clida.\n", 160);
		getch ();
	} else {  //Caso a quantidade de eleitores seja 0 ou letras.
		printf ("\n\n\nSem eleitores a votar.\n");
		getch ();
	}
	
	return 0;
}