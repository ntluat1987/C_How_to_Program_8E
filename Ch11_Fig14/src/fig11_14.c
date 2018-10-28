// Fig. 11.14: fig11_14.c
// Reading a random-access file sequentially
#include <stdio.h>

// clientData structure definition               
struct clientData {
	unsigned int acctNum; // account number
	char lastName[15]; // account last name
	char firstName[10]; // account first name
	double balance; // account balance
};

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	FILE *cfPtr; // accounts.dat file pointer

	// fopen opens the file; exits if file cannot be opened
	if ((cfPtr = fopen("accounts.dat", "rb")) == NULL) {
		puts("File could not be opened.");
	} else {
		printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name",
				"Balance");

		// read all records from file (until eof)
		while (!feof(cfPtr)) {
			// create clientData with default information
			struct clientData client = { 0, "", "", 0.0 };

			int result = fread(&client, sizeof(struct clientData), 1, cfPtr);
			printf("%d\n", result);
			// display record
			if (result != 0 && client.acctNum != 0) {
				printf("%-6d%-16s%-11s%10.2f\n", client.acctNum,
						client.lastName, client.firstName, client.balance);
			}
		}

		fclose(cfPtr); // fclose closes the file
	}
}

/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/