#include <stdio.h>
char lines[100][100];


void paymentGateway(char user[],char selectedMovie[],char seat,int no_Of_Tickets,int price){
    printf("Payment gateway says Hi");
    //printf("%s %s %c %d %d",user,selectedMovie,seat,no_Of_Tickets,price);
    //printf("%s",selectedMovie);
}

int runningMovies(){
    #define MAX_LINES 100
    #define MAX_LENGTH 100
    char str[MAX_LENGTH];
    //char lines[MAX_LINES][MAX_LENGTH];
    int i = 0;
    FILE *fp = fopen("movieslist.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(str, MAX_LENGTH, fp) != NULL) {
        str[strcspn(str, "\n")] = '\0'; // remove newline character from input
        strncpy(lines[i], str, MAX_LENGTH);
        i++;
        if (i >= MAX_LINES) {
            printf("Error: too many lines in file.\n");
            return 1;
        }
    }

    fclose(fp);

    // Print the array to verify that it was filled correctly


    //userDash(user);
    return i;

}

void BookTkt(char user[]){
    char selectedMovie[100]; // saves the movie which user wants to.
    char seat; //saves whether balcony or nomal
    int no_Of_Tickets,price;
    int ch; //choice whether to purchase ticket or cancel it

    int i=runningMovies(),j;
    printf("Choose the movie:\n");
    for(j=0;j<i;j++){
        printf("%d -- %s\n",j+1,lines[j]);
    }
    scanf("%d",&j);
    strcpy(selectedMovie,lines[j]);
    //printf("%s",selectedMovie);

    printf("====Balcony seat price = Rs.120=====\n");
    printf(" ====Normal seat price = Rs.70=====\n\n");
    printf("Enter B for balcony and N for normal...\n");
    printf("Select the seat: \n");

    scanf(" %c",&seat);

    if(seat=='B' || seat=='b'){
        price=120;
    }
    else{
        price=70;
    }

    printf("Enter the number of tickets required:\n");
    scanf("%d",&no_Of_Tickets);

    price=price*no_Of_Tickets;

    printf("Total price would be: %d\n\n",price);

    printf("Are you sure you want to purchase the ticket?\nPress Y to purchase and N to cancel\n");
    scanf(" %c",&ch);

    if(ch=='Y' || ch=='y'){
        paymentGateway(user,selectedMovie,seat,no_Of_Tickets,price);
    }
    else{
        userDash(user);
    }




}



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
    printf("\n-------------------------------------------------------------------");
	printf("\n");
	printf("\t Movie Ticket booking ");
	printf("\n");
	printf("\n-------------------------------------------------------------------");
    printf("\n\tPress <1> View All Movie");
	printf("\n\tPress <2> Book Ticket");
	printf("\n\tPress <3> View All Booking history");
   	//printf("\n\tPress <0> Exit ");
    printf("\nEnter your choice:   ");
    scanf("%d",&ch);
    if(ch==1){
        printf("Running movies are: \n");
        int i=runningMovies(),j;
        for (j = 0; j < i; j++) {
            printf("%s\n", lines[j]);
        }

        userDash(user);
    }
    else if(ch==2){
        BookTkt(user);
    }
    else if(ch==3){
        printf("Seeing booking History");
    }
    else{
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
        fclose(fp);
        printf("admin auth succeess\n");
        adminDash();
        return;


    }

    while (fgets(str, 100, fp) != NULL) {
        str[strcspn(str, "\n")] = '\0'; // remove newline character from input
        if (strcmp(str, authstr) == 0) {
            //fclose(fp);
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
