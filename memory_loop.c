#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    char user_name[] = "Steve";
    char *ptr_username = user_name;

    int string_length = strlen(user_name);
    printf("The length of the string is: %d\n", string_length);

    printf("Memory address of first character: %p\n", ptr_username); // Memory address of Steve
    printf("Value contained in the address: %c\n", *ptr_username);

    printf("\n");
    printf("Looping to display values using pointers\n");
    printf("========================================\n");
    for(int i = 0; i < string_length; i++){
        printf("%c", *(ptr_username++)); 

        if(i == string_length - 1){
            printf("\n");

        }

    }

    ptr_username = user_name; // Reset pointer

    printf("\nSearching for a character in the string\n");
    printf("========================================\n");

    char target = 'e';
    int found = 0;
    int times_appeared = 0;

    // Loop as it changes the pointer
    for(int i = 0; i < string_length; i++){
        
        if(*(ptr_username++) == target){
            printf("Character found!\n");
            times_appeared++;

        }

    }

    if(!found){
        printf("Character not found!\n");

    }
    
    return 0;
}