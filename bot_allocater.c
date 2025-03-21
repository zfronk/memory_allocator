#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main entry point
int main(){
	printf("Hello there, lets allocate memory\n");
	printf("\n");

	char *ptr_username = malloc(sizeof(char)* 100); // around 100 bytes worth

	if(ptr_username == NULL){
		printf("Memory not allocated!\n");
	}

	printf("# Memory allocated successfully\n");
	char user[] = "Steve Aboll";

	strcpy(ptr_username, user); // Copy data to memory block
	int string_length = strlen(user);

	printf("\n");
	printf("First character to username is stored in %p\n", ptr_username);
	printf("Value stored: %s\n", ptr_username); // 
	printf("Number of characters: %d\n", string_length); // long interger

	printf("\nListing characters via memory address: ");
	
	// Loop by memory address
	char *ptr_trans_username = ptr_username;
	int i = 0;

	while(i < string_length){
		printf("%c", *(ptr_trans_username++)); // increment pointer copy in each loop
		i++;
		
	}

	printf("\nDone displaying characters\n");
	free(ptr_username);

	return 0;
}

