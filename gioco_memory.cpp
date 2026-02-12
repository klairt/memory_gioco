#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void coppie(int dim)
{
	char tabella[dim][dim]; //tabella con la dimensione casuale scelta

	bool alfabeto[26];

	for(int i=0; i<26; i++) //riempie l'array alfabeto (che servirà dopo a tenere traccia di tutte le lettere usate) a false.
	{
		alfabeto[i]=false;
	}


	for(int i=0; i<dim; i++) //riempie la tabella con dei - per dire che è vuota
	{
		for(int j=0;j<dim;j++)
		{
			tabella[i][j]='-';
		}
	}
	for(int i=0;i<dim*2;i++)
	{
		char x=rand()%26+65;
		while(alfabeto[(int)x-65]==true) //se la lettera è già stata usata, continua a generare finché non ne trovi un'altra
		{
			 x=rand()%26+65;
		}

		for(int j=0;j<2;j++)
		{
			int r=rand()%dim; //genera posizione casuale per la riga
			int c=rand()%dim;//genera posizione casuale per la colonna
			if(tabella[r][c]=='-')
			{
				tabella[r][c]=x; //se la posizione non è già stata occupata, riempie con la lettera generata prima
			}else
			{
				j--; //altrimenti dovrà rifare il ciclo
			}
		}
		alfabeto[(int)x-65]=true;
	}

	for(int i=0; i<dim; i++) //riempie la tabella con dei - per dire che è vuota
	{
		for(int j=0;j<dim;j++)
		{
			cout<<tabella[i][j];
		}
		cout<<endl;
	}

}

int main() {

	srand(time(NULL));
	cout<<"Benvenuti al gioco memory!!\n\n";
	int dimensione_matrice= rand()%4+4; //genera casualmente la dimensione della matrice quadrata scegliendo un numero tra 4 e 7

	cout<<"Il numero di coppie è: "<<dimensione_matrice<<"\n\n";

	coppie(dimensione_matrice);

	return 0;
}
