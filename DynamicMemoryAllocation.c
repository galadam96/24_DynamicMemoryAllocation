//DATE: 2023.09.19
//PURPOSE: Program that prints user input with dyanmic memory allocation

#include <stdio.h>
#include <stdlib.h>

int main() {

	char* pString = NULL; //initialize pointer, pointing to nothing
	int stringSize = 0;

	printf("Enter the number of characters you want to input:");
	scanf("%i", &stringSize);

	//Empty the input buffer that added a newline character with scanf
	int c;
	while ((c = getchar()) != '\n' && c != EOF);


	pString = (char*)malloc(stringSize * sizeof(char)); //allocate the user input number of character size in bytes
	
	//Handling failed allocation
	if (pString == NULL) {
		printf("\n\nDEBUG: Pointers points to NULL!");
	}
	
	printf("Enter the text:");
	fgets(pString, stringSize * sizeof(char), stdin);
	printf("\nText entered: %s", pString);
	free(pString); //frees memory
	pString = NULL; // pointer points to nothing again
	return 0;
}