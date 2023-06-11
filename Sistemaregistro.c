#include <stdio.h> //library responsible for communication with the user
#include <stdlib.h> //library responsible for memory space allocation 
#include <locale.h> //library responsible for text allocation by region
#include <string.h> //library responsible for the string

int registration(){ //responsible for registering users on the system

    //start of creating variables
    char data [40];
    char name [40];
    char email [40];
    char phone [40];
    char office [40];
    //end of variable/string creation

    printf("\nEnter the name to be registered:\n"); //collecting user information
    scanf("%s", name); //%s refers to string

    strcpy(data,name); //responsible for copying string values

    FILE *file; //create the file in the database
    file = fopen(data, "w"); //open and create the file
    fprintf(file, name); //save the value of the variable
    fclose(file); //close the file

    file = fopen(data, "a"); //open and create the file
    fprintf(file, ","); //save the value of the variable
    fclose(file); //close the file

    printf("\nEnter the e-mail to be registered:");
    scanf("%s", email);

    file = fopen(data, "a");
    fprintf(file, email);
    fclose(file);

    file = fopen(data, "a");
    fprintf(file, ",");
    fclose(file);

    printf("\nEnter the phone to be registered:\n");
    scanf("%s", phone);

    file = fopen(data, "a");
    fprintf(file, phone);
    fclose(file);

    file = fopen(data, "a");
    fprintf(file,",");
    fclose(file);

    printf("\nEnter the job to be registered:\n\n");
    scanf("%s", office);

    file = fopen(data, "a");
    fprintf(file, office);
    fclose(file);

    system("pause");

}

int query(){

    char name [40];
    char content[200];

    printf("\n Enter username:"); //collecting user information
    scanf("%s", name);

    FILE *file; //create the file in the database
    file = fopen(name, "r"); //open and create the file
    
    if(file == NULL){

        printf("\nUser not found");

    }
    
    while(fgets(content, 200, file) != NULL){ //read the file

        printf("\nThis is user information: \n\n");
        printf("%s", content);
        printf("\n\n");

    }

        system("pause"); //pause program execution
    
}

int delete(){

    char name [40];

    printf("\nEnter the name you want to deltete: ");
    scanf("%s",name);

    remove(name); //allows to remove the file

    FILE *file; //create the file in the database
    file = fopen(name, "r"); //open and create the file

    if(file == NULL){ //check if the file is null

        printf("\n'%s' no longer in the system.\n\n ", name);
        system("pause");
        
    } 
    return 0;

}

int main(){

    int opcao = 0; //defines the variables
    int x = 1;

    for(x=1; x=1;){ //replay control

    system("cls");

    //start of menu
    printf("Welcome to the shoppull registration system!!\n");
    printf("\nplease choose one of the options below\n");
    printf("\n\t1 - Resgister new user?\n");
    printf("\t2 - Query user?\n");
    printf("\t3 - Delete user?\n");
    printf("\t4 - Close program\n");
    printf("\noption:");
    //end of menu

    scanf("%d", &opcao);
    system("cls");

    switch(opcao){ //start menu selection

        //function call
        case 1:
        printf("You chose the option register user\n\n");
        system("pause");
        registration();
        break;

         //function call
        case 2:
        printf("You chose the option query user\n\n");
        system("pause");
        query();
        break;

         //function call
        case 3:
        printf("you chose the option delete user\n\n");
        system("pause");
        delete();
        break;

         //function call
        case 4:
        printf("You chose the option close program. To the next : )\n\n");
        return 0;
        break;

        default:
        printf("This option does not exist in our system. try any of the options mentioned above\n\n");
        system("pause");
        break;
        //end of selection
    }
    
    }
}
