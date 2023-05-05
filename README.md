# Movie_Ticket_Booking

This is a simple movie booking program written in C that allows users to view running movies, book tickets, and view their booking history. The program uses text files to store data such as the list of running movies, user account information, and booking history for each user.
The program starts with a login screen that prompts the user to enter their account ID and password. If the ID and password are correct, the user is taken to the user dashboard where they can select an option to view running movies, book tickets, view booking history, or log out.
The user can view the list of running movies and select a movie they want to watch. They can choose the type of seat and the number of tickets they want to purchase. The program calculates the price of the ticket based on the seat type and the number of tickets selected. The user is then prompted to confirm the purchase, and if they confirm, the program saves the booking information in a text file and displays a message confirming the successful purchase.
The user can also view their booking history, which shows a list of all the movies they have booked in the past. The program reads the booking history data from a text file that is specific to each user.
The program also has an option for creating a new user account. If a user does not have an account, they can create a new account by entering a new ID and password. The program saves the new account information in a text file.
Finally, there is an admin dashboard that is not currently implemented in the program. It could be used to manage the list of running movies or to view the booking history of all users.

### MODULES USED
1. main() - the first function that is executed in c program
2. login() - the function that prompts username and password from user checks if the combination is available in userdata.txt if so open user dashboard else asks for creating an account
3. userDash() - Dashboard of user where user can view all running movies, book ticket, see his booking history and also logout.
4. createAccount() - Allows user to create a new account and saves the username+password combination to userdata.txt file
5. Booktkt() - Allows user to select one of the running movies, seat type, number of seats and calculates the price and finally forwarding it to payment gateway
6. runningMovies() - reads movielist.txt and saves the running movies as in the array called list and returns the number of movies in the currently running
7. paymentGateway() - takes in users name, movies selected, seat type, number of seat, price and saves it to a file with the name of the user. Eg user with the name will have a file sam.txt
8. bookHistory() - opens the file having the name of the user and display content in the file. Shows the booking history of that user

