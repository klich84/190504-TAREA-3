#include "190502 DEFINICIONFUNC.h"

	int Trama1 [20];
	int Trama2 [20];
	int n=0, numrep=0,ronda;

//escoje los 20 numeros aleatoriamente
void NumerosAleatorios ()
{
	const int tamano = 20;
	//int Trama1 [tamano];
	srand(time(NULL));
	for (int i=0;i<tamano;i++)
	{
		Trama1[i] = rand() % 500;
	} 
}

//Muestra la Trama de los 20 numeros iniciales
void MostrarTrama1 ()
{
	//Mostrar Trama inicial
	cout<<"Trama inicial = ";
	for(int i=0;i<20;i++)
	{
		cout<<Trama1[i]<<" ";
	}
}

//Pide al usuario cuantas veces quiere que se repita el cifrado
void RondaActualizacion()
{
	//1. Rondas de actualizacion
	cout<<endl;
	cout<<endl<<"Digite el numero de veces que quiera que se repita el proceso:"<<endl;
	cin>>numrep;
}
//Actualiza los numeros de la trama inicial con los numeros hallados actualmente
void ActualizandoTrama1()
{
	//3. Actualizando Trama1
	cout<<endl;
	for(int i=0;i<20;i++)
	{
		Trama1[i] = Trama2[i];
	}
}

//Muestra la Trama con los numeros actualizados
void MostrarTrama1Actu()
{
	cout<<endl;
	cout<<"Ronda"<<ronda+1<<"="<<"  ";
	for(int i=0;i<20;i++)
	{
		cout<<Trama1[i]<<" ";
	}
}


//Cifrado de la trama
void cipherData()//void Cifrado()
{
	//2. Proceso de cifrado
	ronda=0;
	for(int i=0;i<numrep;i++)
	{
		for(int i=0;i<20;i++)
		{
			if(i%2==0)	//a. si la posicion es par
			{
				if(i==0)
				{
					Trama2[i] = Trama1[i+5]-Trama1[i+1];
				}
				else if (i==5)
				{
					Trama2[i] = Trama1[i-1]-Trama1[i-5];
				}
				else
				{
					Trama2[i] = Trama1[i-1]-Trama1[i+1];
				}
				
			}
			else //b. Si la posicion es impar
			{
				if(i==0)
				{
					Trama2[i] = Trama1[i+5]+Trama1[i+1];
				}
				else if (i==5)
				{
					Trama2[i] = Trama1[i-1]+Trama1[i-5];
				}
				else
				{
					Trama2[i] = Trama1[i-1]+Trama1[i+1];
				}
			}
		}
		
	ActualizandoTrama1();
	MostrarTrama1Actu();
	ronda++;
	}
}
