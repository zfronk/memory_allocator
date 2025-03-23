#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){

	int element;
	printf("Enter three elements...\n");

	int *array = malloc(sizeof(int) * 3); // Memory address to store three intergers

	if(array != NULL){
		int *temp_address = array; // Stores same mem address
		printf("Memory allocated successfully!\n");

		printf("\n");

		for(int i = 0; i < 3; i++){
			printf("Element %d: ", (i +1));
			scanf("%d", &element);  // Get input and copy to variable in stack

			*temp_address = element; //  assigning data to memory

			//printf("\n");
			printf("Data stored in memory address: %p\n", temp_address);
			temp_address++; // move the pointer
			printf("\n");

		
		}


		printf("Done collecting and storing data!\n");

		temp_address = array; // Restore the pointer to original place
		printf("Original memory address: %p\n", temp_address); // Display

		printf("\n");

		printf("Printing via memory address: ");

		for(int i = 0; i < 3; i++){
			printf("%d ", *(temp_address));
			temp_address++; // Move the pointer
			
		}

		printf("\n");

		printf("Done!\n");

		printf("\n");


		printf("Adding via memory address: ");
		temp_address = array; // Restore the pointer
		int sum = 0;

		for(int i = 0; i < 3; i++){
			sum += *(temp_address);
			temp_address++;
			
		}

		printf("%d\n", sum);

		printf("Done! Memory freed...\n");


		
	}

	else{
		printf("Memory not allocated\n");
		return 1;
	}

	
	
	return 0;
}
