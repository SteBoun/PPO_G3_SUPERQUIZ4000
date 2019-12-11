#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

int lire_bouton(int pinBouton,bool etatRechercher)
{
	int i = 0;
	int verif = 0;
	while(i < 15)
	{
		verif += digitalRead(pinBouton);
		i++;
	}
	//si ca correspond a la recherche donner l'état
	if(verif == i && etatRechercher == true)
	{
		return(1);
	}
	else if(verif == 0 && etatRechercher == false)//retourne létat non rechercher
	{
		return(0);
	}
	//retourne -1 quand l'état n'est pas trouver
	else
	{
		return(-1);
	}
}

bool VerifResultat(int bonneReponse,int btn1 ,int btn2 ,int btn3)
{
	bool valider = false;
	bool resultat = 0;
	int Vbtn1 = 0;
	int Vbtn2 = 0;
	int Vbtn3 = 0;
	
	while(valider == false)
	{
		Vbtn1 = lire_bouton(btn1,1);
		Vbtn2 = lire_bouton(btn2,1);
		Vbtn3 = lire_bouton(btn3,1);
		if((Vbtn1 == 1 && bonneReponse == 1) || (Vbtn2 == 1 && bonneReponse == 2) || (Vbtn3 == 1 && bonneReponse == 3))
		{
			resultat = true;
			valider = true;
		}
		else((Vbtn1 == 1 && bonneReponse != 1) || (Vbtn2 == 1 && bonneReponse != 2) || (Vbtn3 == 1 && bonneReponse != 3)))
		{
			resultat = false;
			valider = true;
		}
	}
	return(resultat);
}

void RemiseZeroBtn(int btn1 ,int btn2 ,int btn3)
{
	while(lire_bouton(btn1,0) != 0 && lire_bouton(btn2,0) != 0 && lire_bouton(btn3,0) != 0)
	{
		//afficher un message sur l'interface exemple :   std::cout << "remet le potentiomètre en position de départ";
	}
}

int main()
{
	//initialisation wiring pi obligatoire // executer au début du programme
	wiringPiSetup();
	//ceci est un exemple les valeur sont à changer
	VerifResultat(2,21,22,23);
	RemiseZeroBtn(21,22,23);
	//question suivante
	VerifResultat(1,21,22,23);
	RemiseZeroBtn(21,22,23);
	//question suivante ....
	return 0;
}
