#include <stdio.h>

//formula da velocidade media
float vm(float s_1, float s_2, float t_1, float t_2 ){
	float res = 0;

	res = (s_2 - s_1) / (t_2 - t_1);

	return res;
}

int main(int argc, char const *argv[])
{

	float res = vm(30, 20, 4, 2);

	printf("Velocidade media: %f \n", res);

	return 0;
}