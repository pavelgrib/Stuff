#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

void main_menu();

void grey_menu();
int grey(const unsigned int i, const unsigned int x);

void mesh_to_cube_menu();
char* mesh_grey_code(const unsigned int j, const unsigned int k, 
	const unsigned int mesh_x, const unsigned int mesh_y);

void concatenate_c_str(const char* front, const char* back, char* output) {
	sprintf(output, "%s%s", front, back);
}

char* int2bin(int input_integer, int charbits)
{
    size_t bits = sizeof(int) * charbits;

    char* str = malloc(bits);

    // type punning because signed shift is implementation-defined
    unsigned u = *(unsigned *)&input_integer;
    for(; charbits--; u >>= 1)
    	str[charbits] = u & 1 ? '1' : '0';

    return str;
}

unsigned int myLog2(const unsigned int x) {
	unsigned int temp = x;
	unsigned int targetlevel = 0;
	while (temp >>= 1) ++targetlevel;
	return targetlevel;
}

void print_choices() {
	printf("1) Calculate Grey code\n");
	printf("2) Convert Mesh to Hypercube\n");
	printf("3) Exit\n");
}


int main(int argc, char* argv[]) {
	main_menu();
}

void main_menu() {
	printf("Welcome to the Grey Code calculator.\n");
	printf("Select from the menu:\n");
	int selection;

	while ( true ) {
		print_choices();
		scanf("%d", &selection);

		if ( selection == 3 ) break;
		else if ( selection == 1 ) grey_menu();
		else if ( selection == 2 ) mesh_to_cube_menu();
	}
}

void grey_menu() {

	while ( true ) {
		int i, x;
		printf("input -1 return to main menu\n");
		printf("index of node (i): ");
		scanf("%d", &i);
		if ( i < 0 ) break;
		printf("dimension of hypercube (x): ");
		scanf("%d", &x);
		if ( x < 1 ) break;

		printf("\nGrey code for (%d, %d) is %d\n", i, x, grey(i,x));
	}
}

int grey(const unsigned int i, const unsigned int x) {
	if ( i == 0 && x == 1 ) {
		return 0;
	} else if ( i == 1 && x == 1) {
		return 1;
	} else {
		if ( i < pow(2, x-1) ) 
			return grey(i, x-1);
		else
			return pow(2, x-1) + grey(pow(2,x) - 1 - i, x-1);
	}
}


void mesh_to_cube_menu() {
	
	while ( true ) {
		unsigned mesh_x, mesh_y;
		printf("input -1 return to main menu\n");
		printf("input x dimension of mesh (power of 2): ");
		scanf("%d", &mesh_x);

		printf("input y dimension of mesh (power of 2): ");
		scanf("%d", &mesh_y);

		if ( mesh_x < 0 || mesh_y < 0 ) break;
		else {
			printf("Grey codes for nodes on %d-by-%d mesh:\n", mesh_x, mesh_y);
			int j, k;
			for ( j = 0; j < mesh_y; ++j ) {
				for ( k = 0; k < mesh_y; ++k ) {
					printf("(%d, %d) --> %s", j, k, mesh_grey_code(j, k, mesh_x, mesh_y) );
				}
				printf("\n");
			}
		}
	}	
}

char* mesh_grey_code(const unsigned int j, const unsigned int k, 
	const unsigned int mesh_x, const unsigned int mesh_y) {
	
	char* j_component = int2bin(grey(j, myLog2(mesh_y)), myLog2(mesh_y));
	char* k_component = int2bin(grey(k, myLog2(mesh_x)), myLog2(mesh_x));
	char* output = (char*) malloc( (myLog2(mesh_x) + myLog2(mesh_y)) * sizeof(int) );
	concatenate_c_str(k_component, j_component, output);
	return output;
}



