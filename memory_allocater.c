#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>


int main(){

	// Boolen to act as switch
    bool is_prompting = true; 

    while(is_prompting){
        printf("Enter number of elements in array: ");

        int num_of_elements; // Buffer to store the num of arrays
        
        char check_for_newline = getchar(); // Gets character
        char enter = '\n';

        // Check newline character
        if(check_for_newline == enter){
            printf("You pressed enter!\n");
            printf("\n");
            continue;
        }

        ungetc(check_for_newline, stdin); // If not enter put back character

        // Invalid data
        if (scanf("%d", &num_of_elements) != 1) {
            while(getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            printf("\n");
            continue;
        }

        // Is valid
        else{
            getchar(); // remove newline
            printf("Adding %d elements!\n", num_of_elements);
            printf("\n");

            // Allocate memory
            int *array = malloc(sizeof(int) * num_of_elements); // ptr to store address of the allocated array

            if(array == NULL){
                printf("Memory allocation failed\n");
                printf("\n");
                continue;

            }

			int *temp_mem = array; // Store array memory address
            printf("Memory allocation passed!\n");
            printf("Memory address of the first element in the array: %p\n", array);

			printf("\n");

            printf("Allocate values to store in memory\n");
            printf("++++++++++++++++++++++++++++++++++\n");

           	// Loop to take input of elements // Loops num_of_elements times
            int i = 0;
            
            while(i < num_of_elements){
                
                bool prompting_values = true;
                
                // Loop to check buffer input conditions
                while(prompting_values){
                    printf("Enter value for element %d: ", i+1);

                    char check_character = getchar();
                    char enter = '\n';
                    int value;

                    if(check_character == enter){ // If enter remove the character
                        printf("You pressed enter!\n");
                        printf("\n");
                        continue;

                    }

                    ungetc(check_character, stdin); // Put the character back in the input buffer

                    // Invalid input
                    if(scanf("%d", &value) != 1){
                        while(getchar() != '\n'); // Remove invalid input
                        printf("Invalid input. Please enter a number!\n");
                        printf("\n");
                        continue;

                    }

                    else{
                    	while(getchar() != '\n'); // Remove newline
                    	
                    	*temp_mem = value; // Paste to memory
                    	temp_mem++; // Move pointer
                    	i++; // Incerement
                    	
                    	// Stop when numbers reached
                    	if(i == num_of_elements){
                        	prompting_values = false;
                    	
    	           		}
                    }

                    
                }
                
                

            }


            printf("\nDone taking records\n");
            temp_mem = array; // Restore pointer


            // Print records
            printf("\nValues stored: ");
            for(int i = 0; i < num_of_elements; i++ ){
                printf("%d ", *(temp_mem++)); // Derefrence

            }

            printf("\n");

            temp_mem = array; // Restore the pointer 

			int sum = 0;
            printf("Sum of the values: ");

			for(int i = 0; i < num_of_elements; i++){
				sum += *(temp_mem);
				temp_mem++; // Move the pointer 
				
			}

			printf("%d\n", sum);

			printf("\n");
            
            free(array); // Free memory
            printf("Memory freed!\n");
			is_prompting = false; // Exit loop
            
            
            
 

        }


        

    }
    
    return 0;
}
