#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Valor de PI
#define PI 3.14159265

/*Função que calula a distacia atravez de coordendas de latidude o longitude*/
double calcDistancia(double lat_inicial, double long_inicial, double lat_final, double long_final) {

    double d2r = 0.017453292519943295769236;

    double dlong = (long_final - long_inicial) * d2r;
    double dlat = (lat_final - lat_inicial) * d2r;

    double temp_sin = sin(dlat/2.0);
    double temp_cos = cos(lat_inicial * d2r);
    double temp_sin2 = sin(dlong/2.0);

    double a = (temp_sin * temp_sin) + (temp_cos * temp_cos) * (temp_sin2 * temp_sin2);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

    return 6368.1 * c;
}


int main(int argc, char const *argv[])
{	//Praça
	double lat_inicial = -4.96889272;
	double long_inicial = -39.01631355;
	//UFC
	double lat_final = -4.97846956;
	double long_final = -39.05673981;

	double distancia = calcDistancia(lat_inicial,long_inicial, lat_final, long_final);

	printf("Distancia: %f\n", distancia);
	
	return 0;
}