#include <stdio.h>




// void tktHistory(char user[]){
//     printf("history of %s",user);
// }

// void bookTkt(char user[]){
//     printf("Ticket booked for %s",user);

void userDash(char user[]){
    int ch;
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
    FILE* ptr = fopen("userdata.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }


    char chk_username[100]; //takes input username
    char chk_pass[100]; //takes input password
    char authstr[100]; //makes a new array to store concatenated pass and username
    printf("Enter your username: ");
    scanf("%s",chk_username);
    printf("Enter your password: ");
    scanf("%s",chk_pass);

    strcpy( authstr,chk_username); // copies chk_username to authstr
    strcat( authstr, chk_pass ); // concatenate chk_pass to authstr

    // validator
    char buf[100];
    while (fscanf(ptr, "%s %*s",
                  buf)
           == 1){
         if(strcmp(authstr,"adminpass")==0){
            fclose(ptr);
            printf("admin succeess");
            break;
        }
        else if(strcmp(buf,authstr)==0){
            fclose(ptr);
            printf("user auth succeess");
            userDash(chk_username);
            break;
        }
    }


}


void main(){

    login();

}

