/*


                      ========================================
					  =									     =
					  =                                      =
					  =		     user registration 			 =
					  =		   operations application		 =
					  =										 =
					  =										 =
					  ========================================
					  
		       	in this program, you can add, delete and list users.
					    https://github.com/yusufkarabocekz				   
				   		  
*/					  
					  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max_users 100 // max users = 100

int i; //for

// structure of information

struct User{
	char username[50];
	char password[50];
	char email[100];
	int age;
};


struct User users[max_users]; // user array

int userCount = 0; // number of current users

// user add function

void addUser()
{
	// the number of users cannot exceed the maximum number of users
	
	if (userCount>=max_users)
	{
		printf("The maximum number of users has been reached.\n");
		return;
	}
	
	// collection and recording of user information
	
	struct User newUser;
	
	printf("User Name: ");
	scanf("%s", &newUser.username);
	printf("Password: ");
	scanf("%s", &newUser.password);
	printf("e-Mail: ");
	scanf("%s", &newUser.email);
	printf("Age: ");
	scanf("%d", &newUser.age);
	
	// the number of users has increased
	
	users[userCount++] = newUser;
	
	printf("\n\nThe user was successfully added.\n");
			
	
}

// user listing function

void listUsers()
{
	
	// if the number of users is 0, there are no registered users
	
	if(userCount==0)
	{
		printf("There are no registered users\n\n");
		return;
	}
	
	// list of the users taken from the array
	
	printf("============== User List ==============\n\n");
	
	for(i=0;i<userCount;i++)
	{
		printf("User %d: \n", i+1);
		printf("User Name: %s\n", users[i].username);
		printf("Password: %s\n", users[i].password);
		printf("e-Mail: %s\n", users[i].email);
		printf("Age: %d\n", users[i].age);
	
	}
}

// user delete function

void deleteUser()
{
	
	// if the number of users is 0, there are no registered users
	
	if(userCount==0)
	{
		printf("There are no registered users.\n");
		return;
	}
	
	// retrieving the entered user name
	
	char targetUsername[50];
	printf("Enter the username that you want to delete: ");
	scanf("%49s", targetUsername);
	
	int foundIndex = -1;
	
	// if there is a user name entered, delete it from the user list
	
	for(i=0;i<userCount;i++)
	{
		if(strcmp(users[i].username, targetUsername) == 0)
		{
			foundIndex = i;
			break;
		}
	}
	
	if(foundIndex==-1)
	{
		printf("The user was not found.\n");
		
	}
	else
	{
		for(i=foundIndex; i<userCount-1;i++)
		{
			users[i] = users[i+1];
		}
		
		userCount--;
		printf("\nThe users was successfully deleted\n");
		
	}
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	
	int choice;
	
	// making a loop selection and calling functions and performing operations
	
	while(1)
	{
	
		printf("\n===== User Registration Application =====\n\n");
		printf("1 - User Add\n");
		printf("2 - List the Users\n");
		printf("3 - Delete User\n");
		printf("4 - Quit\n\n");
		
		printf("Make your choice: ");
		scanf("%d", &choice);
		printf("\n\n");
		
	switch(choice)
		{
		case 1:
			addUser();
			break;
		case 2:
			listUsers();
			break;
		case 3:
			deleteUser();
			break;
		case  4:
			printf("Exiting the application...\n");
			exit(0);
		default:
			printf("Invalid selection. Please try again.\n");
			break;
		}
	} 

	return 0;
}

