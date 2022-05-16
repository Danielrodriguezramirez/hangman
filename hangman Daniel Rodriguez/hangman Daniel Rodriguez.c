//JUEGO REALIZADO EN LENGUAJE C
//MAS DETALLES EN MI PAGINA WEB PROGRAMADOREC.COM

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

//PROTOTIPOS DE LAS FUNCIONES
void categorias();
void ingresoCategoria (int op);
void empezarJuego (char palabras[][15], char nombre[]);
void dibujo (int intentos);


//FUNCION PRINCIPAL MAIN
int main(){
	system("mode con cols=80 lines=25");
	categorias();
	system("pause");
	return 0;
}

//FUNCION CATEGORIAS, IMPRIME EN PANTALLA LAS CATEGORIAS Y PERMITE ELEGIR UNA
void categorias(){
	int op;
	do{
		system("cls");
		printf("\n\t\t\t\tHANGMAN\n\n");
		printf(" Levels\n\n");
		printf(" 1. level 1\n");
		printf(" 2. level 2\n");
		printf(" 3. level 3\n");
		printf(" 4. level 4\n\n");
		printf(" Choose your level: ");
		scanf("%i",&op);		
	}while(op<1 || op>4);

	if (op==1) ingresoCategoria(op);
	if (op==2) ingresoCategoria(op);
	if (op==3) ingresoCategoria(op);
	if (op==4) ingresoCategoria(op);
}


//ESTA FUNCION RECIBE UN VALOR, Y DEPENDIENDO DEL VALOR RECIBIDO LLAMA A OTRA FUNCION PARA EMPEZAR EL JUEGO
void ingresoCategoria (int op){
	char nombrecat[4][15] = {"Europe","SouthAmerica","Asia","Oceania"};
	char Europe [10][15] = {"RUSSIA","GERMANY","FRANCE","ITALY","SPAIN","UKRAINE","POLAND","ROMANIA","NETHERLANDS","BELGIUM"};
	char SouthAmerica [10][15] = {"BRAZIL","COLOMBIA","ARGENTINA","PERU","VENEZUELA","CHILE","ECUADOR","BOLIVIA","PARAGUAY","URUGUAY"};
	char Asia [10][15] = {"CHINA","INDIA","INDONESIA","BANGLADESH","JAPAN","PHILIPPINES","VIETNAM","TURKEY","IRAN","THAILAND"};
	char Oceania [10][15] = {"AUSTRALIA","FIJI","MICRONESI","SAMOA","VANUATU","KIRIBATI","TONGA","PALAU","TUVALU","NAURU"};
	
	switch(op){
		case 1:
			empezarJuego(Europe,nombrecat[op-1]);
			break;
		case 2:
			empezarJuego(SouthAmerica,nombrecat[op-1]);
			break;
		case 3:
			empezarJuego(Asia,nombrecat[op-1]);
			break;
		case 4:
			empezarJuego(Oceania,nombrecat[op-1]);
			break;	
	}	
}


//FUNCION QUE CONTIENE EL ALGORITMO DEL JUEGO
void empezarJuego (char palabras[][15], char nombre[]){
	int opcion,i,j,k,longitud,espacios,puntos=1200;
	char letra;
	int aciertos = 0;
	int intentos = 0;
	int ganar = 0;
	srand(time(NULL));
	
	opcion = rand() % 10; //SE GENERA UN NUMERO ALEATORIO COMPRENDIDO ENTRE 0 Y 9
	longitud = strlen(palabras[opcion]); //SE ALMACENA LA LONGITUD DE LA PALABRA 
	char frase[longitud];
	
	//SE COLOCAN GUIONES BAJOS EN EL ARRAY DE CARACTERES FRASE
	for(i=0; i < longitud; i++){
		frase[i] = '_';
	}
	
	
	do{
		aciertos = 0;
		system("cls");
		printf("\n\t\t\t\tHANGMAN\n\n");
		printf(" Level: %s\n\n",nombre);
		printf(" Tries left: %i",6-intentos);
		dibujo(intentos);
		
		//IMPRIME EL ARRAY DE CARACTERES FRASE
		printf("\n\n\n");
		for(i=0; i < longitud; i++){
			printf(" %c ",frase[i]);
		}

		
		if (intentos == 6){
			printf("\n\n YOU LOSE!!\n");
			printf(" The word is: %s\n\n",palabras[opcion]);
			printf(" Press a key to play again...");
			getch();
			categorias();	
		}
		
		
		//PROCESO QUE COMPRUEBA SI SE HA ADIVINADO LA PALABRA
		espacios=0;
		
		for (i = 0; i < longitud; i++){
			if (frase[i] == '_')
				espacios++;
		}
		
		
		if (espacios == 0){
			printf("\n\n CONGRATULATIONS.. YOU WIN!!\n\n");
			printf(" Press a key to play again...");
			getch();
			categorias();		
		}
		
		
		printf("\n\n Write a letter: ");
		scanf(" %c",&letra);
		
		//PROCESO QUE VERIFICA SI LA LETRA INGRESADA EXISTE EN LA PALABRA, SI ESTO ES VERDADERO, SE REEMPLAZA EL CARACTER GUION BAJO POR LA LETRA INGRESADA 
		for (j = 0; j < longitud; j++){
			if (letra == palabras[opcion][j]){
				frase[j] = letra;
				aciertos++;
			}	
		}
		
		if (aciertos == 0){
			intentos++;	
			puntos -= 200;
		}
		
		
			
	}while(intentos != 7);
	
	
	printf("\n\n");		
}

//FUNCION QUE REALIZA EL DIBUJO DE EL AHORCADO, RECIBE EL NUMERO DE INTENTOS Y CON ESE DATO REALIZA EL DIBUJO
void dibujo (int intentos){
	switch(intentos){
		case 0:
			printf("\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------");
			break;
		case 1:
			printf("\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------");
			break;
		case 2:
			printf("\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------");
			break;
		case 3:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------");
			break;
		case 4:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |\n    |\n    |\n ----------");
			break;
		case 5:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |      /\n    |\n    |\n ----------");
			break;
		case 6:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |      / ");
			printf("\\");
			printf("\n");
			printf("    |\n    |\n ----------");
			break;
	}
	
}


