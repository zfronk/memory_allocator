#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	char message[] = "Hello there";
	char *message_ptr = message; // Store address to the character

	// Display by address
	for(size_t i = 0; i < strlen(message) + 1; i++){ // Print till end
		printf("%c", *message_ptr++); // Dereference // Move the pointer
		if(i == strlen(message)){
			printf("\n");
			
		}
	}


	return 0;
}
