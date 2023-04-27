#include <stdio.h>

void adminDash(){
    printf("welcome admin");
}

void createAccount(){
    FILE *file ;
    char id[20];
    char pass[20];

    file = fopen("userdata.txt","a");

    if (file == NULL)
        printf("\nUnable to open the file\n");
    else{
        printf("\nEnter UserID: \n");
        scanf(" %s",&id);

        printf("Now enter Password: \n");
        scanf(" %s",&pass);

        strcat(id,pass);
        printf("Account Created successfully \n\n\n ",id);
        fprintf(file,id );
        fprintf(file, "\n");
        fclose(file);
        printf("Please Login with the new ID\n");
        login();
    }

}


void userDash(char user[]){
    int ch;
    printf("\nWelome %s\n",user);
    printf("Choose one option:\n\n1.Book ticket\n2.See Booking History");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            // bookTkt(user);
            printf("booking on");
            break;
        case 2:
            // tktHistory(user);
            printf("see history");
            break;
        default:
            printf("Wrong choice");
            userDash(user);

    }

}

void login(){

    char str[100];
    char chk_username[100]; //takes input username
    char chk_pass[100]; //takes input password
    char authstr[100]; //makes a new array to store concatenated pass and username
    printf("Enter your username: ");
    scanf("%s",chk_username);
    printf("Enter your password: ");
    scanf("%s",chk_pass);

    strcpy( authstr,chk_username); // copies chk_username to authstr
    strcat( authstr, chk_pass ); // concatenate chk_pass to authstr

    FILE *fp = fopen("userdata.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    if(strcmp(authstr,"adminpass")==0){

        printf("admin auth succeess\n");
        adminDash();
        fclose(fp);
        return;


    }

    while (fgets(str, 100, fp) != NULL) {
        str[strcspn(str, "\n")] = '\0'; // remove newline character from input
        if (strcmp(str, authstr) == 0) {
            fclose(fp);
            printf("user auth succeess");
            userDash(chk_username);
            break;
        }
    }
    fclose(fp);
    int ch;
    printf("user not found\nDo you want to create a new account?\n1.Create a new account\n2.Login\n");
    scanf("%d",&ch);
    if(ch==1){
        createAccount();
    }
    else{
        login();
    }
    return 0;


}


void main(){

    login();

}
