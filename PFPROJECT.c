#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


struct chefs
{
	char Name[50];
	float rating;
}c1,c2;


struct servers
{
	char Name[50];
	int numberoftables;
}s[7];


struct buspersons
{
	char Name[50];
	float numberofhours;
}b[5];


struct ORDER
{
    char x[100][100];
};

struct Form 
{
	int Persons;
    char Date[30];
	char Name[30];
	char Session[25];	
};

struct Tables
{
	char t_two[10][40];
	char t_seven[20][40];
	char t_five[22][40];
	char Party[1][40];
	char t_smallParty[2][40];
	
};

int FuncForm(void);

int Pass(char Check[]);

void Order (void);

void record(void);

void Managerfunc (void);

int t_two_c = 0, t_seven_c = 0, t_five_c = 0, t_s_p_c = 0, t_party_c = 0;


	
int main()
{
	
	int i=0, a=0, wrong = 0;
	char ch1, ch2, x;
	char Password[30];
	
	while (x != 'B')
	{
		printf("\n\tWELCOME TO C'est La vie' COMPUTRIZED SYSTEM\n");
		printf("\n\n");
		system("COLOR 04");
		system("pause");
	    system("cls");
	    system("COLOR 07");
		
		printf("\n\t\t\t\t\t WELCOME TO C'est La vie'\n\n");
	    printf(" SELECT MODE\n\t PRESS M KEY FOR MANAGER MODE\n\t PRESS C KEY FOR CUSTOMER MODE\n\t PRESS B TO TERMINATE(END) THE WHOLE PROGRAM\n");
	    scanf(" %c", &ch1);
	    
	    
	    if (ch1 ==  'b' || ch1 == 'B')
	    {
	    	break;
		}
	
	    switch (ch1)
	    {
		    case 'C':
		    case 'c':
                printf("\nDO YOU WANT TO DINE IN OR MAKE RESERVATIONS\n");
                printf(" PRESS D FOR DINE IN\n PRESS R FOR RESERVATION\n");
                scanf(" %c", &ch2);
             
                switch (ch2)
                {
             	    case 'D':
             	    case 'd':
             		    system("cls");
             		
             		    FILE *ptr;
	                    char ch;
	
	                    ptr = fopen("Menu.txt", "r");
	                    
	                    system("COLOR E0");
	
	                    while (ch != EOF)
	                    {
		                    ch = fgetc(ptr);
		                    printf("%c", ch);
	                    }
	
	                    fclose(ptr);
	
	                    printf("\n\n");
	                    Order();
             		
             		    break;
             		
             	    case 'R':
				    case 'r':
				        FuncForm();
				        break;
				        
				    default:
					    printf("\nWrong key pressed.....");
					    break;    
		        }
		    
		        break;
			 
		    case 'M':
		    case 'm':
			    while(i <= 4)
			    {
			 	    printf("\n\tEnter Password: ");
			        scanf(" %[^\n]s", &Password);
			 
			        a = Pass(Password);
			 	
			 	    if (i == 4)
			 	    {
			 		    wrong = 1;
			 		    break;
				    }
				
				    else
				    {
					    if (a == 0)
			 	        {
			 	    	    printf("\nOops! Wrong Password entered.\n");
				        }
				
				        else
				        {
				    	    break;
				        }
				    }
			 	
			 	    i++;
		        }
		    
		        if (wrong == 1)
		        {
		    	    printf("You have entered the wrong password for more than 4 times, program is now locked");
		    	    break;
			    }
			
			    else
			    {
			    	system("cls");
				    printf("\n\tUnlocked.\n");
				    Managerfunc();
		   	    }
		     
			   
			    break;
			    
			default:
			    printf("Wrong key entered.....");
			    break;    
	        

        }
	}
	
	printf("ENDED");
	return 0;    
}


//FUNCTIONS PART:

int FuncForm(void)
{
	struct Form S1;
	struct Tables T1;
	
	int x=0, j=0, f=0;
	
	system("cls");
	printf("You are in reservations section");
	
	printf("\n\tPlease fill out form for Reservation\n");
	
	printf("Name : ");
	scanf(" %[^\n]s", &S1.Name);
	
	printf("Session: \n 1)Dinner \n 2) Lunch \n\t= ");
	scanf(" %[^\n]s", &S1.Session);
	
	printf("Persons: ");
	scanf("%d", &S1.Persons);
	
	
	if ((S1.Persons == 3) || (S1.Persons == 2))
	{
		if (t_two_c >= 11)
		{
			x = 0;
		}
		
		else
		{
			strcpy(T1.t_two[t_two_c], S1.Name);
			t_two_c++;
			j = t_two_c;
			x = 1;
		}
		
	}
	
	else if ((S1.Persons == 5) || (S1.Persons == 6))
	{
		if (t_five_c >= 23)
		{
			x = 0;
		}
		
		else
		{
			strcpy(T1.t_five[t_five_c], S1.Name);
			t_five_c++;
			j = t_five_c;
			x = 1;
		}
	}
	
	else if ((S1.Persons >= 7) && (S1.Persons <= 10))
	{
		if (t_seven_c >= 21)
		{
			x = 0;
		}
		
		else
		{
			strcpy(T1.t_seven[t_seven_c], S1.Name);
			t_seven_c++;
			j = t_seven_c;
			x = 1;
		}
	}
	
	else if ((S1.Persons >10) && (S1.Persons <=20))
	{
		if (t_s_p_c >= 3)
		{
			x = 0;
		}
		
		else
		{
			strcpy(T1.t_smallParty[t_s_p_c], S1.Name);
			t_s_p_c++;
			j = t_s_p_c;
			x = 1;
		}
	}
	
	else if ((S1.Persons > 20) && (S1.Persons <= 40))
	{
		if (t_party_c >= 1)
		{
			x = 0;
		}
		
		else
		{
			strcpy(T1.Party[t_party_c], S1.Name);
			t_party_c++;
			j = t_party_c;
			x = 1;
		}
	}
	
	else
	{
		f = 2;
	}
	
	
	if (x == 0)
	{
		printf("Sorry, booking is full for this date.");
	}
	
	else if (f == 2)
	{
		printf("Sorry, cant accomodate large amount of people.");
	}
	
	else
	{
		system("cls");
		system("COLOR B5");
	    printf("Your Reservation has been made\n DETAILS:\n");
		
		printf("Name: %s\n", S1.Name);
	    printf("Session: %s\n", S1.Session);
	    printf("Table %d has been booked for %s", j, S1.Name);
	    
	    printf("\n\nPress Enter to end and exit.....");
	    getch();
	    
	    system("CLS");
	    
	    
	}
	
};


int Pass(char Check[])
{
	int x;
	char password[20] = "Manager1234";
	
	x = strcmp(password, Check);
	
	if (x == 0)
	{
		return 1;
	}
	
	else 
	{
		return 0;
	}
};

void Order (void)
{
	struct ORDER S1;
    
    char y[2][2];
    float price, Total;
    int i=0, order =1;
    int q = 0, j=0;
    
    
    
    printf("\t\tEnter ID's of the items you want, press '0' to place the order when done");
    printf("\n\t(Note: if you want to remove or cancel any item that you order, you can do so by entering the same of its quantity again with a negative sign.)");

    while (order != 0)
    {
    	printf("\n\tID: ");
        scanf("%d", &order);
        
        if (order == 0)
        {
        	break;
		}

        printf("\tQuantity: ");
        scanf("%d", &q);

        switch (order)
        {
            case 1001:
                price = 8.5;
                Total =  Total + (q * price);
                
                strcpy(S1.x[i], "Soup of the day     x"); //5 spaces
                
                sprintf(y[0], "%d", q);
                strcat(S1.x[i], y[0]);
                
                i++;
                break;
            
            case 1002:
		        price = 9.0;
			    Total = Total + (q * price);
				
				strcpy(S1.x[i], "Dynamite Prawns     x");
				sprintf(y[0], "%d", q);
                strcat(S1.x[i], y[0]);
                
				i++;
				break;
				
			case 1003:
			    price = 7.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Chicken Strips     x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1004:
			    price = 8.5;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Bruschetta Italiano     x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1005:
			    price = 10.5;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Salt and Pepper Calimari     x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1006:
			    price = 12.5;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Garlic king prawns     x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;	

			case 1007:
			    price = 13.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Chicken Souvlaki     x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;		 
				
			case 1008:
			    price = 18.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Fettuccine carbonara     x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;	
				       
			case 1009:
			    price = 20.5;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Chicken Supreme     x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;		      
				
			case 1010:
			    price = 20.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Tarragon Chicken    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;		 
            
            case 1011:
			    price = 20.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Spaghetti Marinara   x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;	
				
			case 1012:
			    price = 25.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "T-Bone   x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;		

            case 1013:
			    price = 27.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Rib on the Bone   x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1014:
			    price = 25.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Scotch Fillet    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;	

			case 1015:
			    price = 26.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "New York style    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1016:
			    price = 30.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Filet mignon    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1017:
			    price = 15.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Ceaser Salad    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1018:
			    price = 15.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Great Salad    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1019:
			    price = 9.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Mashed potato    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;	
				
			case 1020:
			    price = 10.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Stir fry rice    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1021:
			    price = 10.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Fries and aloli    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1022:
			    price = 9.5;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Gravy   x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;					
				
			case 1023:
			    price = 9.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Banana cream pie    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1024:
			    price = 8.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Cherry Cobbler    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			case 1025:
			    price = 8.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Carrot Cake    x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;			
				
			case 1026:
			    price = 10.0;
				Total = Total + (q * price);
				
				strcpy(S1.x[i], "Molten Chocolate Cake   x");
				sprintf(y[0], "%d", q);
				strcat(S1.x[i], y[0]);
				
				i++;
				break;
				
			default:
			  	printf("\nID does not exist. Wrong ID entered.");
				break;  				        

        }
    	
	}
	
	system("cls");
	system("COLOR B4");
	printf("\t\t Order placed!");
	printf("\n\n\t---Items ordered---");
	
	
	for (j=0; j<=i; j++)
	{
		printf("\n\t%s", S1.x[j]);
	}
    
    printf("\n\nTotal Bill: $%.1f", Total);
    
    printf("\n\n\tThank you for visiting our resturaunt. Your order has been recieved.");
    printf("\n\tOur staff will guide you towards your table, and your food will be served as soon as its ready.");
    
    printf("\n\n\tPress enter to save and exit.....");
    
    getch();
    
    system("CLS");
	
}


void Managerfunc(void)
{
	int choice, count;
	char viewchoice, searchname[50];
	printf("Choose the position you want to calculate the salary of\n Enter\n 1 for chefs\n 2 for servers\n 3 for buspersons \n");
	scanf("%d", &choice);
	printf("Do you want to calculate salary of a single employee or all employees at once\n Enter 'S' for a single employee\n Enter 'A' for all employees\n");
	scanf(" %c", &viewchoice);
	
	record();
	switch(choice)
	{
		
	    case 1:;
	        
		    float chef1bonus,chef2bonus,chef1salary,chef2salary;
		    
			switch(viewchoice)
			{
				case 'A':
			    case 'a':
			
		     	    printf("-----Chef List-----\n 1) %s\n 2) %s\n", c1.Name, c2.Name); 
		            printf("Enter chef rating out of 5 for %s: ", c1.Name);
		            scanf("%f", &c1.rating); 
	        	    system("cls");
        		    printf("Enter chef rating out of 5 for %s: ", c2.Name);
        		    scanf("%f", &c2.rating);
        		    system("cls");
		
        		    if(c1.rating>=4.3 && c1.rating < 4.6)
	        	    {
			            chef1bonus=0.05*1000.0;
			            chef1salary=chef1bonus + 1000.0;
		            }
		            else if(c1.rating>=4.6 && c1.rating<=5.0)
		            {
			            chef1bonus=0.1*1000.0;
			            chef1salary=chef1bonus + 1000.0;
	      	        }
	    	        else
	    	        {
	    		        chef1bonus=0.0;
		    	        chef1salary=1000.0;
		            }
		
		            if(c2.rating>=4.3 && c2.rating < 4.6)
		            {
			            chef2bonus=0.05*1000.0;
			            chef2salary=chef2bonus + 1000.0;
	     	        }
		            else if(c2.rating>=4.6 && c2.rating<=5.0)
		            {
		     	        chef2bonus=0.1*1000.0;
			            chef2salary=chef2bonus + 1000.0;
	     	        }
		            else
		            {
			            chef2bonus=0.0;
			            chef2salary=1000.0;
		            }
		
		            printf("Name of chef: %s\nrating: %.1f \nBonus: $%.1f\nSalary for this month: $%.1f\n\n\n",c1.Name,c1.rating,chef1bonus,chef1salary);
		            printf("Name of chef: %s\nrating: %.1f \nBonus: $%.1f\nSalary for this month: $%.1f\n\n\n",c2.Name,c2.rating,chef2bonus,chef2salary);
		            
		            break;
		            
		        case 'S':
		        case 's':
		        	printf("-----Chef List-----\n 1) %s\n 2) %s\n", c1.Name, c2.Name); 
		            
		        	printf("Enter Name of Chef you want to calculate the salary for:");
		        	scanf(" %[^\n]s", &searchname);
		        	
		        	if(strcmp(searchname, c1.Name) == 0)
		        	{
		        		printf("Enter chef rating out of 5 for %s: ", c1.Name);
		                scanf("%f", &c1.rating); 
		                
						
						if(c1.rating>=4.3 && c1.rating < 4.6)
	        	         {
			                chef1bonus=0.05*1000.0;
			                chef1salary=chef1bonus + 1000.0;
		                }
		                else if(c1.rating>=4.6 && c1.rating<=5.0)
		                {
			                chef1bonus=0.1*1000.0;
			                chef1salary=chef1bonus + 1000.0;
	      	            }
	    	            else
	    	            {
	    		            chef1bonus=0.0;
		    	            chef1salary=1000.0;
		                }
		                printf("Name of chef: %s\nrating: %.1f \nBonus: $%.1f\nSalary for this month: $%.1f\n\n\n",c1.Name,c1.rating,chef1bonus,chef1salary);
					}
					
					else if(strcmp(searchname, c2.Name) == 0)
					{
						if(c2.rating>=4.3 && c2.rating < 4.6)
		                {
			                chef2bonus=0.05*1000.0;
			                chef2salary=chef2bonus + 1000.0;
	     	            }
		                else if(c2.rating>=4.6 && c2.rating<=5.0)
		                {
		     	            chef2bonus=0.1*1000.0;
			                chef2salary=chef2bonus + 1000.0;
	     	            }
		                else
		                {
			                chef2bonus=0.0;
			                chef2salary=1000.0;
		                }
		                printf("Name of chef: %s\nrating: %.1f \nBonus: $%.1f\nSalary for this month: $%.1f\n\n\n",c2.Name,c2.rating,chef2bonus,chef2salary);					
					}
					else 
					{
					    count++;
					}
					if(count > 2)
					{
						printf("Invalid employee name. Not found in system");
					}
		            break;
		        default:printf("Invalid");
		            break;
		
	        }
	    break;
	  
	 case 2:; 
	  	int i;
	  	float serverbonus[7],serversalary[7];
	  	
		
		  
		printf("-----Server List------\n");
	  	for(i=0;i<=7;i++)
	  	{
	  		printf("%d) %s\n",i+1, s[i].Name);
		}
		switch(viewchoice)
		{
			case 'A':
			case 'a':	
		        for(i=0;i<=7;i++)
		        {
			        printf("Enter number of tables served by %s:", s[i].Name);
	  		        scanf("%d", &s[i].numberoftables);
	  		        system("cls");

	  		        if(s[i].numberoftables>=65 && s[i].numberoftables<70)
	  		        {
	  			        serverbonus[i]=400.0*0.1;
	  			        serversalary[i]=serverbonus[i]+400.0;
			    
				    }
			
			        else if(s[i].numberoftables>=70 && s[i].numberoftables<75)
	  	     	    {
	  			        serverbonus[i]=400.0*0.15;
	  			        serversalary[i]=serverbonus[i]+400.0;
			        }
			        else if(s[i].numberoftables>=75)
	  		        {
	  			        serverbonus[i]=400.0*0.2;
	  			        serversalary[i]=serverbonus[i]+400.0;
			        }
			        else
			        {
				        serverbonus[i]=0.00;
				        serversalary[i]=400.00;
			        }
			
		        }
		
		        for(i=0;i<=7;i++)
		        {
			        printf("Name: %s\nNo. of tables served: %d\nBonus: $%.2f \nSalary: $%.2f\n\n",s[i].Name,s[i].numberoftables,serverbonus[i],serversalary[i]);
		        }
		        
			
			    break;
			    
			case 'S':
			case 's':
				count=0;
				
				printf("Enter name of Server you want to calculate the salary for: ");
				scanf(" %[^\n]s", &searchname);
				
				for(i=0;i<=7;i++)
				{
					if (strcmp(searchname, s[i].Name) == 0)
					{
						printf("Enter number of tables served by %s:", s[i].Name);
	  		            scanf("%d", &s[i].numberoftables);
	  		            system("cls");

	  		            if(s[i].numberoftables>=65 && s[i].numberoftables<70)
	  		            {
	  			            serverbonus[i]=400.0*0.1;
	  			            serversalary[i]=serverbonus[i]+400.0;
			    
				        }
			
			              else if(s[i].numberoftables>=70 && s[i].numberoftables<75)
	  	     	        {
	  			            serverbonus[i]=400.0*0.15;
	  			            serversalary[i]=serverbonus[i]+400.0;
			            }
			            else if(s[i].numberoftables>=75)
	  		            {
	  			            serverbonus[i]=400.0*0.2;
	  			            serversalary[i]=serverbonus[i]+400.0;
			            }
			            else
			            {
				            serverbonus[i]=0.00;
				            serversalary[i]=400.00;
			            }
			            printf("Name: %s\nNo. of tables served: %d\nBonus: $%.2f \nSalary: $%.2f\n\n",s[i].Name,s[i].numberoftables,serverbonus[i],serversalary[i]);
				    }
				    
					else 
					{
					    count++;
					}
					if(count > 8)
					{
						printf("Invalid employee name. Not found in system");
					}
				
				}
			    break;
			
			defauult: printf("Invalid choice entered");
			    break;
	   }
	   break;
	   
	   
	 case 3:;
	 
	 	float buspersonsalary[4];
	    printf("-----Busperson List-----\n");
	    switch(viewchoice)
	    {
	    	case 'A':
	    	case 'a':
		
		        for(i=0;i<=4;i++)
		        {
			        printf("%d) %s\n", i+1, b[i].Name);
		        }
		
		        for(i=0;i<=4;i++)
		        {
			        printf("Enter the number of hours worked by %s: ", b[i].Name);
			        scanf("%f", &b[i].numberofhours);
			        buspersonsalary[i]=b[i].numberofhours*5.0;
			        system("cls");
		
		        }
		
		
		        for(i=0;i<=4;i++)
		        {
			        printf("Name: %s\nNumber of hours worked: %.1f hrs\nSalary of this month: $%.1f \n\n", b[i].Name, b[i].numberofhours, buspersonsalary[i]);
		
		        }	  	  	
	
	            break;
	        
	        
	        case 'S':
	        case 's':
	        	count=0;
	        	for(i=0;i<=4;i++)
		        {
			        printf("%d) %s\n", i+1, b[i].Name);
		        }
		
	        	printf("Enter Name of Chef you want to Calculate the salary for:");
		        scanf(" %[^\n]s", &searchname);
		        for(i=0;i<=4;i++)
				{
				
	        	    if(strcmp(searchname, b[i].Name) == 0)
					{
						printf("Enter the number of hours worked by %s: ", b[i].Name);
			            scanf("%f", &b[i].numberofhours);
			            buspersonsalary[i]=b[i].numberofhours*5.0;
			            system("cls");
			            printf("Name: %s\nNumber of hours worked: %.1f hrs\nSalary of this month: $%.1f \n\n", b[i].Name, b[i].numberofhours, buspersonsalary[i]);
	      			}
	      			else 
					{
					    count++;
					}
					if(count > 5)
					{
						printf("Invalid employee name. Not found in system");
					}
	            }
	            break;
	            
	        default: printf("Invalid");
	            break;
	    
	    }
	    
	    break;
	    
	default: printf("Invalid");
	            break;
	
	}
				
};


void record(void)
{
	char x1[] = "Ahmed Khalid";
	strcpy(c1.Name, x1);
	
	char x2[]= "Aun Abbas";
	strcpy(c2.Name,x2);

	char x3[]="Tariq Cheema";
	strcpy(s[0].Name,x3);
	
	char x4[]="Adil Rizwan";
	strcpy(s[1].Name,x4);
	
	char x5[]="Tanveer Ali";
	strcpy(s[2].Name,x5);
	
	char x6[]="Ibtesam Hussain";
	strcpy(s[3].Name,x6);
	
	char x7[]="Adyan Wasif";
	strcpy(s[4].Name,x7);
	
	char x8[]="David Bolton";
	strcpy(s[5].Name,x8);
	
	char x9[]="Afaq Ahmed";
	strcpy(s[6].Name,x9);
	
	char x10[]="Rabbi noor Farooqui";
	strcpy(s[7].Name,x10);

	char x11[]="Asif Matrikchi";
	strcpy(b[0].Name,x11);
	
	char x12[]="Irfan Junejo";
	strcpy(b[1].Name,x12);
	
	char x13[]="Khursheed Ali";
	strcpy(b[2].Name,x13);
	
	char x14[]="Nasir Shaka";
	strcpy(b[3].Name,x14);
	
	char x15[]="Amir DaVinci";
	strcpy(b[4].Name,x15);
};
