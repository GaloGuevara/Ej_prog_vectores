/*En un evento de votación participan 5 candidatos representados por números del 1 al 5
Los votos se podrán ingresar desordenadamente, y el ingreso termina con el #0

Candidato 1
Candidato 2
Candidato 3
Candidato 4
Candidato 5
*/
//Inclusión de bibliotecas varias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define candidatos 5 //definimos el total de candidatos que participan

int main(int argc, char const *argv[])
{
    int votos[candidatos] = {0, 0, 0, 0, 0}; //vector que cuenta los votos obtenidos por cada candidato
    int var = 6; //una variable que me sirva para contar los votos y sea diferente de 1 a 5 y diferente de 5 para que no interactue con el prog desde la linea 22
    printf("Ingrese numeros del 1 al 5 para ingresar los votos, y 0 para salir, notar que digitos mayores que 5 no hacen nada en el programa.\n");

    do
    {
        scanf("%d%*c", &var);//almacenamos la variable ingresada por el usuario
        switch (var) //utilizamos un switch para ir manejando la informacion en el vector de votos
        {
        case 1:
            votos[0] += 1; //sumas un voto para el candidato 1
            break;
        case 2:
            votos[1] += 1; //sumas un voto para el candidato 2
            break;
        case 3:
            votos[2] += 1; //sumas un voto para el candidato 3
            break;
        case 4:
            votos[3] += 1; //sumas un voto para el candidato 4
            break;
        case 5:
            votos[4] += 1; //sumas un voto para el candidato 5
            break;
        default: //en caso de no ingresar un numero seleccionado no pasa nada :D
            break;
        }
    } while (var != 0);//condicion de salida, mientras sea diferente de 0 va a seguir pidiendo numeros
    
    printf("---------------------------------------------------------------------------------------\n");//linea por estética
    printf("El resultado de la votacion es:\n\nCandidato1 : %d votos\nCandidato2 : %d votos\nCandidato3 : %d votos\nCandidato4 : %d votos\nCandidato5 : %d votos\n\n", votos[0], votos[1], votos[2], votos[3], votos[4]); //muestor en pantalla el total de votos por candidato

    int ganador = 0; //almacenamos el numero del ganador 
    int votos_ganador = 0; //almacenamos el total de los votos del ganador

    //bloque donde obtenemos el candidato con el mayor numero de votos
    for (int i = 0; i < 5; i++)
    {
        if (votos[i] > votos_ganador)
        {
            ganador = i + 1;
            votos_ganador = votos[i];
        }
    }

    int contador_ganadores = 0; // variable que cuenta cuantos ganadores hay, es decir, cuantos candidatos tienen el maximo numeor de votos
    int ganadores[5] = {0, 0, 0, 0, 0}; // vector donde ninguno es ganador, por tanto tienen 0 y en caso de ganar, obtienen el valor 1

    //bloque donde obtenemos el total de ganadores
    for (int i = 0; i < 5; i++)
    {
        if (votos_ganador == votos[i])//comparamos el total de votos con cada uno de los ganadores
        {
            contador_ganadores += 1; //sumamos 1 al contador ganadores
            ganadores[i] = 1; //cambiamos el valor del vector ganadores para cada respectivo puesto por 1 para decir que gano
        }
    }

    //bloque para comparar si se tiene un solo ganador o existe empate
    if (contador_ganadores == 1)//existe un solo ganador
    {
        printf("El ganador es el candidato %d\n", ganador);
    }
    else if (contador_ganadores > 1)//si existen más de un ganador, se tiene empate
    {
        printf("Existe un empate con los candidatos:\n");
        for (int i = 0; i < 5; i++)//como no sabemos cuantos ganadores hay, mostramos en pantalla los ganadores mediante saltos de lineas
        {
            if (ganadores[i] == 1) //aqui evaluamos si ganaron o no
            {
                printf("cantidato%d\n", i + 1); //mostramos en pantalla el ganador, sumando 1 al i porque empezamos a contar los vectores desde 0, no se olviden
            }
        }
    }

    //final del codigo :D :D
    return 0;
}