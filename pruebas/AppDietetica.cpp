// AppDietética v1.0
// por Ander Raso

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// definimos todas las variables que usaremos
	char again, salir; // sirve para preguntar si queremos volver a calcular algo
	string sexo;
	bool success; // sirve para comrpobar si hemos elegido bien el sexo
	double a, b, c, d, mb, mt, altura, peso, edad, actividad, pCintura, pCadera, icc, PIdevine, PIrobinson, PImiller, PIhamwi, PIlemmens, PImedia, porcentSobrePI, imc, pMuineca, constitucion;
	
	do // Preguntaremos lo que queramos calcular siempre que la variable again sea 's'
	{
		cout << "\n¿Qué te gustaría calcular?\n\n";
		cout << "1 - Metabolismo\n";
		cout << "2 - ICC (Índice cintura-cadera)\n";
		cout << "3 - Peso ideal\n";
		cout << "4 - IMC (índice de masa corporal)\n";
		cout << "5 - Complexión corporal\n";
		cout << "6 - Salir\n";

		// Elegimos la opción que queramos
		int choice;
		cout << "\nElección (1-6): ";
		cin >> choice;

		// Depende de la elección tendremos diferentes casos, cada cual será una fórmula para calcular diferente cosa
		switch (choice)
		{
			case 1:
				cout << "\n##########################################\n";
				cout << "HAS ELEGIDO CALCULAR EL METABOLISMO.\n";
				cout << "##########################################\n";

				// Recogemos datos
				// Preguntamos el sexo y si no lo definimos bien lo vuelve a preguntar
				do
				{
					cout << "Sexo (h/m): ";
					cin >> sexo;

					if ( sexo == "h" || sexo == "m" )
					{
						success = true;
					}
					else
					{
						cout << "\nPara elegir sexo utiliza la letra h para hombre o m para mujer.\n";
						success = false;
					}
				} while ( !success );

				cout << "Edad: ";
				cin >> edad;

				cout << "Altura (cm): ";
				cin >> altura;

				cout << "Peso (kg): ";
				cin >> peso;

				/* 
			    INDICE DE ACTIVIDAD FÍSICA - se multiplica al metabolismo basal para calcular el metabolismo total
			    1 -    para una persona inactiva o totalmente sedentaria, 
			    1,2 - para una persona que realiza una actividad física ligera (andar un poco), 
			    1,4 - para alguien que realiza actividad media (actividades cotidianas dinámicas), 
			    1,6 - Para una persona muy activa (actividades cotidianas dinámicas y ejercicio de forma regular un mínimo de 3 veces a la semana), 
			    1,8 - Persona de actividad extrema (actividades de elevado consumo calórico, trabajos extremos, deportistas de élite...)
				*/

			    cout << "\nINDICE DE ACTIVIDAD FÍSICA\n";
			    cout << "1   : Para una persona inactiva o totalmente sedentaria\n";
			    cout << "1.2 : Para una persona que realiza una actividad física ligera (andar un poco)\n";
			    cout << "1.4 : Para alguien que realiza actividad media (actividades cotidianas dinámicas)\n";
			    cout << "1.6 : Para una persona muy activa (actividades cotidianas dinámicas y ejercicio de forma regular un mínimo de 3 veces a la semana)\n";
			    cout << "1.8 : Persona de actividad extrema (actividades de elevado consumo calórico, trabajos extremos, deportistas de élite...)\n\n";

				cout << "Actividad: ";
				cin >> actividad;

				// Datos para metabolismo basal - hombre
				if ( sexo == "h" )
				{
			        a = 66.4730;
			        b = 13.7516;
			        c = 5.0033;
			        d = 6.7550;
			    }

			    // Datos para metabolismo basal - mujer
			    else if ( sexo == "m" )
			    {
			        a = 655.0955;
			        b = 9.5634;
			        c = 1.8496;
			        d = 4.6756;
			    }

			    // Calcular metabolismo basal
				mb = a+(b*peso)+(c*altura)-(d*edad);

				// CASOS ESPECIALES UNA VEZ CALCULADO EL METABOLISMO BASAL
			    /* 
			        Tercera edad
			        Reducción de 200 Kcal desde los 50 años hasta menos de 75 años
			        Reducción de 500 Kcal en hombres 75 años o más
			        Reducción de 400 Kcal en mujeres 75 años o más
			    */
			    if ( (edad >= 50) && (edad < 75) ) { mb -= 200; }
			    if ( edad >= 75 )
			    {
			        if( sexo == "h" ) { mb -= 500; }
			        if( sexo == "m" ) { mb -= 400; }
			    }

			    // Calcular metabolismo total
			    mt = mb*actividad;

			    // Por último mostramos los datos
				cout << "\n##########################################";
				cout << "\nMETABOLISMO BASAL: " << mb << " kcal";
				cout << "\n##########################################\n";

				cout << "\n##########################################";
				cout << "\nMETABOLISMO TOTAL: " << mt << " kcal";
				cout << "\n##########################################\n";

				break;

			case 2:
				cout << "\n##########################################\n";
				cout << "HAS ELEGIDO CALCULAR EL ICC.\n";
				cout << "##########################################\n";

				// Recogemos datos
				do
				{
					cout << "Sexo (h/m): ";
					cin >> sexo;

					if ( sexo == "h" || sexo == "m" )
					{
						success = true;
					}
					else
					{
						cout << "\nPara elegir sexo utiliza la letra h para hombre o m para mujer.\n";
						success = false;
					}
				} while ( !success );

				cout << "Perímetro cintura (cm): ";
				cin >> pCintura;

				cout << "Perímetro cadera (cm): ";
				cin >> pCadera;

				// Cálculo del ICC
		    	icc = pCintura / pCadera;

		    	// Mostramos resultados
		        if (sexo == "h") {
		            if (icc >= 1) {
		                cout << icc << " : Riesgo Cardiovascular\n";
		            } else {
		                cout << icc << " : Sin Riesgo Cardiovascular\n";
		            }
		        }
		        else if (sexo == "m") {
		            if (icc >= 0.85) {
		                cout << icc << " : Riesgo Cardiovascular\n";
		            } else {
		                cout << icc << " : Sin Riesgo Cardiovascular\n";
		            }
		        }

				break;

			case 3:
				cout << "\n##########################################\n";
				cout << "HAS ELEGIDO CALCULAR EL PESO IDEAL.\n";
				cout << "##########################################\n";

				do
				{
					cout << "Sexo (h/m): ";
					cin >> sexo;

					if ( sexo == "h" || sexo == "m" )
					{
						success = true;
					}
					else
					{
						cout << "\nPara elegir sexo utiliza la letra h para hombre o m para mujer.\n";
						success = false;
					}
				} while ( !success );

				// Recogemos datos
				cout << "Altura (cm): ";
				cin >> altura;

				cout << "Peso (kg): ";
				cin >> peso;


				// Fórmulas según sexo
				if (sexo=="h") {
				    PIdevine=((altura-152.4)*(0.91)+50);
				    PIrobinson= ((altura - 152.4)* (0.748)+52);
				    PImiller= ((altura - 152.4)* (0.555)+56.2);
				    PIhamwi= ((altura - 152.4)* (1.063)+48.2);
				    PIlemmens= 22*((altura/100)*(altura/100));
				}
				else if (sexo=="m") {
				    PIdevine=  ((altura-152.4)* (0.91) +45.5);
				    PIrobinson= ((altura - 152.4)* (0.669)+49);
				    PImiller= ((altura - 152.4)* (0.5354)+53.1);
				    PIhamwi= ((altura - 152.4)* (0.866)+45.5);
				    PIlemmens= 22*((altura/100)*(altura/100));
				}

			    // Cálculo del peso ideal
				PImedia = (PIdevine+PIrobinson+PImiller+PIhamwi+PIlemmens)/5;

			    // Cálculo del % sobre el peso ideal
			    /* Esta seria la formula
			        97 ---- 100%
			        78 ---- X %

			        X = 78*100/97
			     */
				porcentSobrePI = peso*100/PImedia;

				// Mostramos resultados
				cout << "\n##########################################\n";
				cout << "CÁLCULOS PESO IDEAL (kg)\n";
				cout << "Devine: "<< PIdevine <<"\n";
				cout << "Robinson: "<< PIrobinson <<"\n";
				cout << "Miller: "<< PImiller <<"\n";
				cout << "Hamwi: "<< PIhamwi <<"\n";
				cout << "Lemmens: "<< PIlemmens <<"\n";
				cout << "---Media peso ideal: "<< PImedia <<"\n";
				cout << "---Porcentaje sobre peso ideal: "<< porcentSobrePI <<" %\n";
				cout << "##########################################\n";

				break;

			case 4:
				cout << "\n##########################################\n";
				cout << "HAS ELEGIDO CALCULAR EL IMC.\n";
				cout << "*No apto para deportitas ni ancianos.\n";
				cout << "##########################################\n";

				// Recogemos datos
				cout << "Altura (m): ";
				cin >> altura;

				cout << "Peso (kg): ";
				cin >> peso;

				// Cálculo del IMC
				imc = peso / (altura*altura);
			    /* -------- RESULTADO DE IMC ----------
			        Desnutrido   <18,5
			        Normal   18,5-24,9
			        Sobrepeso grado I    25-26,9
			        Sobrepeso grado II   27-29,9
			        Obesidad tipo I  30-34,6
			        Obesidad tipo II     35-39,9
			        Obesidad tipo III(mórbida)   40-49,9
			    */
			    if(imc>=10 && imc<18.5){cout << imc << " : Desnutrición\n"; }
			    else if(imc>=18.5 && imc<=24.9){cout << imc << " : Normopeso\n"; }
			    else if(imc>=25 && imc<=26.9){cout << imc << " : Sobrepeso Grado I\n"; }
			    else if(imc>=27 && imc<=29.9){cout << imc << " : Sobrepeso Grado II\n"; }
			    else if(imc>=30 && imc<=34.6){cout << imc << " : Obesidad Tipo I\n"; }
			    else if(imc>=35 && imc<=39.9){cout << imc << " : Obesidad Tipo II\n"; }
			    else if(imc>40){cout << imc << " : Obesidad Tipo III(mórbida)\n"; }
			    //si el resultado no es un número avisa del error
			    else { cout << "Parece que has definido mal algún campo.\n"; }

				break;

			case 5:
				cout << "\n##########################################\n";
				cout << "HAS ELEGIDO CALCULAR COMPLEXIÓN CORPORAL.\n";
				cout << "##########################################\n";

				// Recogemos datos
				do
				{
					cout << "Sexo (h/m): ";
					cin >> sexo;

					if ( sexo == "h" || sexo == "m" )
					{
						success = true;
					}
					else
					{
						cout << "\nPara elegir sexo utiliza la letra h para hombre o m para mujer.\n";
						success = false;
					}
				} while ( !success );

				cout << "Altura (cm): ";
				cin >> altura;

				cout << "Perímetro muñeca (cm): ";
				cin >> pMuineca;

				// Calculamos la constitución corporal
				constitucion = (altura / pMuineca);

				// Resultado
				/*
				        Ectomorfo   Mesomorfo    Endomorfo
				Varón   > 10,4      10,4 – 9,6   < 9,6

				Mujer   > 10,9      10,9 – 9,9   < 9,9
				*/
			    if (sexo == "h") {
			        if (constitucion >= 10.4) {cout << constitucion << " : Ectomorfo\n";}
			        if (constitucion < 10.4 & constitucion > 9.6) {cout << constitucion << " : Mesomorfo\n";}
			        if (constitucion <= 9.6) {cout << constitucion << " : Endomorfo\n";}
			    }
			    else if (sexo == "m") {
			        if (constitucion >= 10.9) {cout << constitucion << " : Ectomorfo\n";}
			        if (constitucion < 10.9 & constitucion > 9.9) {cout << constitucion << " : Mesomorfo\n";}
			        if (constitucion <= 9.9) {cout << constitucion << " : Endomorfo\n";}
			    }

			case 6:
				salir = 's';
				break;

			default:
				cout << "Has elegido una opción no válida.\n";

		}

		// si nuestra opcion no ha sido la de salir preguntamos si queremos hacer otro cálculo
		if (salir != 's') 
		{
			cout << "\n¿Quieres hacer algún otro cálculo? (s/n): ";
			cin >> again; // recordamos que mientras again = 's' volveremos al principio a preguntar
		}
		
	} while (again == 's');

	cout << "\n##########################################\n";
	cout << "***-Gracias por usar AppDietetica v1.0-***\n";
	cout << "##########################################\n\n";

	return 0;
}