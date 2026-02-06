#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


void coppie(int dim) //parametri: matrice,  dimensione
{	//funzione che genera le coppie

	srand(time(NULL));
	
	char tabella[7][7];
	
	bool alfabeto[26]={false};
	/*for(int i=0;i<26;i++) //riempe l'array d'appoggio 
	{	
		alfabeto[i]=65+i;	
	}
	
	for(int i=0;i<7;i++) //setta tutti i valori al #
	{
		for(int k=0;k<7;k++)
		{
			tabella[i][k]=(char)35; //(char)35 equivale a # nel codice ascii 
		}
		
	}*/
	
	for(int i=0; i<dim; i++) //ciclo che genera lettere casuali per le varie posizioni. 
	{
		int x=rand()%26; //genera un numero casuale da 0-25 (che è la dimensione dell'array)
		
		while(alfabeto[x]==true) //se alfabeto in posizione x è già stato settato a true, continua a generare un'altra posizione
		{
			x=rand()%27;
		}
		
		/************************Inserire nella matrice****************************/

		for(int w=0; w<1;w++)
		{
		
		int j=rand()%dim; //variabile per secgliere una riga casuale tra 0-(dim-1) 
		int k=rand()%dim; //variabile per secgliere una colonna casuale tra 0-(dim-1)
		
		/*Perché rand di dim se la tabella è 7x7?
		con 7x7 utilizziamo tutta la matrice, e il valore potrebbe essere inserita anche fuori dallo spazio prestabilito (dim).
		Esempio: 
		dim=4
		Quindi la nostra tabella sarà uguale :
		****###
		****###
		****###
		****###
		
		Dove * sarà una lettera, # non verrà usato. Se facessimo 	int j=rand()%7; e int k=rand()%7;
		
		Potrebbe capitare 7 e 4, quindi andrebbe a scrivere fuori dalla nostra tabella */
		
		while(tabella[j][k]!=(char)35) //se quella posizione è già stata utilizzata, continua a generare un'altra posizione
		{
			int j=rand()%dim; 
			int k=rand()%dim;
			
		}
		
		tabella[j][k]=alfabeto[x];
		
		
		}
		
		alfabeto[x]=false; //una volta effettuato il controllo e scrittp nella tabella inserisce 0 nell'array alfabeto in posizione x, cosicche non possa essere riutilizzato
	}
	
	/************************Stampa tabella****************************/
	
	for(int i=1;i<=dim;i++) 
	{
		for(int k=0;k<dim;k++)
		{
			cout<<tabella[i-1][k]<<"   ";
		}
		
		if(i/dim==0)
		{
			cout<<endl;
		}
	}
	
}


int main(int argc, char** argv) {
	
	srand(time(NULL));
	
	cout<<"Benvenuti a: GIOCO MEMORY!!\n\n";

	//dichiarazione
	int dim=rand()%3+4; //il programma genera casualmente la dimensione della matrice compresa tra 4 e 15
	int tabella[7][7]; //variabile per la tabella di memory (massimo 15)
    
	
	//elaborazione
	cout<<"\nNumero di coppie: "<<dim<<endl; 
	
	/*for(int i=0;i<7;i++) //azzera tutti i valori della tabella
	{
		for(int k=0;k<7;k++)
		{
			tabella[i][k]=0;	
		}
	}
	
	for(int i=0; i<dim; i++) //ciclo che genera lettere casuali per le varie posizioni
	{
		
		char lettera=rand()%26+65; 
		for(int )
		
		
	}*/
	
	coppie(dim);		
	
	return 0;
}
