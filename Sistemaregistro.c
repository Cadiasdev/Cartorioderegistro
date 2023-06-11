#include <stdio.h> //biblioteca responsavel pela comunicação com o usuário
#include <stdlib.h> //biblioteca responsavel pela alocação de espaço em memoria 
#include <locale.h> //biblioteca resposavel pela alocação de texto por região
#include <string.h> //biblioteca responsavel pela string

int registration(){

    char data [40];
    char name [40];
    char email [40];
    char phone [40];
    char office [40];

    printf("\nEnter the name to be registered:\n");
    scanf("%s", name);

    strcpy(data,name);

    FILE *file; 
    file = fopen(data, "w");
    fprintf(file, name);
    fclose(file);

    file = fopen(data, "a");
    fprintf(file, ",");
    fclose(file);

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

    printf("\n Enter username:");
    scanf("%s", name);

    FILE *file;
    file = fopen(name, "r");
    
    if(file == NULL){

        printf("\nUser not found");

    }
    
    while(fgets(content, 200, file) != NULL){

        printf("\nThis is user information: \n\n");
        printf("%s", content);
        printf("\n\n");

    }

        system("pause");
    
}

int delete(){

    char name [40];

    printf("\nEnter the name you want to deltete: ");
    scanf("%s",name);

    remove(name);

    FILE *file;
    file = fopen(name, "r");

    if(file == NULL){

        printf("\n'%s' deleted successfully.\n\n ", name);
        system("pause");
        
    } 
    return 0;
    

}

int main(){

    int opcao = 0;
    int x = 1;

    for(x=1; x=1;){

    system("cls");

    printf("Welcome to the shoppull registration system!!\n");
    printf("\nplease choose one of the options below\n");
    printf("\n\t1 - Resgister new user?\n");
    printf("\t2 - Query user?\n");
    printf("\t3 - Delete user?\n");
    printf("\t4 - Close program\n");
    printf("\noption:");

    scanf("%d", &opcao);
    system("cls");

    switch(opcao){

        case 1:
        printf("You chose the option register user\n\n");
        system("pause");
        registration();
        break;

        case 2:
        printf("You chose the option query user\n\n");
        system("pause");
        query();
        break;

        case 3:
        printf("you chose the option delete user\n\n");
        system("pause");
        delete();
        break;

        case 4:
        printf("You chose the option close program. To the next : )\n\n");
        return 0;
        break;

        default:
        printf("This option does not exist in our system. try any of the options mentioned above\n\n");
        system("pause");
        break;
    }
    
    }
}