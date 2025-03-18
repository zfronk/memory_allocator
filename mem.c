#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){

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

        // Capture invalid data
        if (scanf("%d", &num_of_elements) != 1) {
            while(getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            printf("\n");
            continue;
        }

        // VALID
        else{
            getchar(); // remove newline
            printf("Adding %d elements\n", num_of_elements);
            printf("\n");

            // Allocate memory
            int *array = malloc(sizeof(int) * num_of_elements); // ptr to store address of the allocated array

            if(array == NULL){
                printf("Memory allocation failed\n");
                printf("\n");
                continue;

            }

            printf("Memory allocation passed!\n");
            printf("Memory address of array: %p\n", array);


            printf("\nAllocate values to store in memory\n");
            printf("------------------------------------\n");

            
            
            // Loop to take input of elements // Loops num_of_elements times
            int i = 0;
            
            while(i < num_of_elements){
                
                bool prompting_values = true;
                
                // Loop to check buffer input conditions
                while(prompting_values){
                    printf("Enter value for element %d: ", i+1);

                    char check_character = getchar();
                    char enter = '\n';

                    if(check_character == enter){ // If enter remove the character
                        printf("You pressed enter!\n");
                        printf("\n");
                        continue;

                    }

                    ungetc(check_character, stdin); // Put the character back in the input buffer

                    // Invalid input
                    if(scanf("%d", array + i) != 1){
                        while(getchar() != '\n'); // Remove invalid input
                        printf("Invalid input. Please enter a number!\n");
                        printf("\n");
                        continue;

                    }

                    while(getchar() != '\n'); // Remove newline
                    
                    i++; // Move to next element

                    // Stop when numbers reached
                    if(i == num_of_elements){
                        prompting_values = false;

                    }
                }
                
                

            }


            printf("\nDone taking records\n");


            // Print records
            printf("\nValues stored: ");
            for(int i = 0; i < num_of_elements; i++ ){
                printf("%d ", *(array + i));

            }

            printf("\n");
            
            is_prompting = false;
            free(array);
            printf("Memory freed!\n");
            
            
            
 

        }


        

    }
    
    return 0;
}