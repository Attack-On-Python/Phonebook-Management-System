#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"server.h"

void menu(struct phonebook contact[],int n)
{						//50
	int choice;

	printf("***PHONEBOOK***\n");
	printf("\tMENU\n");
	printf("1.List\t\t2.Search\n3.Add/Delete\n4.Modify\n5.Exit\n");
	printf("Enter the option to be performed:\n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
		
			list(contact,n);		
			break;
		
		case 2:
						
			search(contact,n);
			break;
						//70
		case 3:
			
			add_delete(contact,n);
			break;
		
		case 4:
			
			modify(contact,n);
			break;
		
		case 5:
			
			exit(0);
			break;
		
		default:
		
			printf("ENTER A VALID OPTION!\n");
			printf("\n\n\n\n\n");
			menu(contact,n);
			
	}
}						//100

void search(struct phonebook contact[],int n)
{
	int choice;	int flag1=0, flag2=0, flag3=0;
	char ans1[10], ans2[10], ans3[10];
	unsigned long long int phnum_check; 
	char name_check[45];	char adrs_check[100];

	here:
	{
		printf("Enter option you're searching:\n\n1.Phone no.\t2.Name\n3.Address\t4.Go back to menu\n");
		scanf("%d",&choice);
		char yes[10]="yes";	char no[10]="no";
		switch(choice)
		{
			case 1:	
				
				printf("\n\nEnter phone number to be searched\n");
				scanf("%llu",&phnum_check);
				for(int i=0;i<n;i++)
				{
					if((contact[i].phnum==phnum_check))
					{
						flag1=1;
						printf("Number is present\n");
						this:
						{
							printf("Do u want the details to be displayed?(yes or no)\n");
							scanf("%s",ans1);
							if(strcmp(ans1,yes)==0)
							{
								display(contact,i,n);
								menu(contact,n);
							}
							else if(strcmp(ans1,no)==0)
							{
								printf("\n\n\n\n\n");
								menu(contact,n);
							}
							else
							{	printf("Please enter yes or no\n");
								goto this;
							}
							break;
						}	
					}
				}
				if(flag1==0)
				{
					printf("Number not present\n");
					printf("\n\n\n\n\n");
					menu(contact,n);
					break;
				}	
				break;
			
			case 2:
										//150
			
				printf("Enter name to be searched:\n");
				scanf("%s",name_check);
				for(int i=0;i<n;i++)
				{
					if(strcmp(contact[i].name,name_check)==0)
					{
						flag2=1;
						printf("Name is present\n");
						printf("Do u want the details to be displayed?(yes or no)\n");
						scanf("%s",ans2);
						if(strcmp(ans2,yes)==0)
						{
							display(contact,i,n);
							printf("\n\n\n\n\n");
							menu(contact,n);
						}
						if(strcmp(ans2,no)==0)
						{
							printf("\n\n\n\n\n");
							menu(contact,n);
						}
						break;
					}
				}
				if(flag2==0)
				{
					printf("Name not present\n");
					printf("\n\n\n\n\n");
					menu(contact,n);
				}	break;
				break;
			

			case 3:
			
				printf("Enter address:\n");
				scanf("%s",adrs_check);
				for(int i=0;i<n;i++)
				{
					if(strcmp(contact[i].address,adrs_check)==0)
					{
						printf("Address is present\n");
						printf("Do u want the details to be displayed?(yes or no)\n");
						scanf("%s",ans3);
						if(strcmp(ans3,yes)==0)
						{
							display(contact,i,n);
							printf("\n\n\n\n\n");
							menu(contact,n);
						}
						if(strcmp(ans3,no)==0)
						{
							printf("\n\n\n\n\n");
							menu(contact,n);
						}
					}
				}
				if(flag3==0)
				{
					printf("Address not present\n");
					printf("\n\n\n\n\n");
					menu(contact,n);
				}
				break;
			
			case 4:
			
				printf("\n\n\n\n\n");
				menu(contact,n);
				break;
						
			default:
			
				printf("ENTER A VALID OPTION!\n");
				goto here;
			
				

		}
	}
}

void modify(struct phonebook contact[],int n)
{
	char name_check[50];	unsigned long long int new_phnum;	char new_adrs[100]; char new_mail[50];    char y[10]="yes";	char no[10]="no";    char ans[5];
	int flag=0;
	printf("enter contact's name to be modified\n");
	scanf("%s",name_check);
	for(int i=0; i<n; ++i)
	{
		if(strcmp(name_check,contact[i].name)==0)
		{
			flag=1;
			printf("choose the option to be modified\n");
			there:
			{
				printf("1.phone number	  2.address	3.mail-id\n");
				int choice;
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
						printf("enter new phone number\n");
						scanf("%llu",&contact[i].phnum);
						break;
					case 2:					
						printf("enter new address\n");
						scanf("%s",new_adrs);
						strcpy(contact[i].address,new_adrs);
						break;
					case 3:
						printf("enter new mail-id\n");
						scanf("%s",new_mail);
						strcpy(contact[i].mail,new_mail);
						break;
					default:
						printf("please enter valid option\n");
						goto there;
				}
			}
	
			here: 
			{
				printf("\ndo you want to see the modified contact's details?\nyes/no\n");
				scanf("%s",ans);
				if(strcmp(ans,y)==0)
				{
					display(contact,i,n);
				}
				else if(strcmp(ans,no)==0)
				{
					printf("\n\n\n\n\n");
					menu(contact,n);
				}
				else
				{
					printf("please enter valid option\n"); 
					goto here;
				}
			} 
		}
	}
	if(flag==0) 
	{
		printf("contact doesn't exist!\n");
		printf("\n\n\n\n\n");
		menu(contact,n);
	}
}

void list(struct phonebook contact[],int n)
{
	char name_check[50]; int flag=0;
	printf("enter name whose details are to be listed\n");
	scanf("%s",name_check);
	for(int i=0; i<n; ++i)
	{
		if(strcmp(name_check,contact[i].name)==0)
		{
			flag=1;
			printf("name : %s\n",contact[i].name);
			printf("phone number : %llu\n",contact[i].phnum);
			printf("address : %s\n",contact[i].address);
			printf("gender : %s\n",contact[i].gender);
			printf("mail : %s\n",contact[i].mail);
			printf("\n\n\n\n\n");
			menu(contact,n);
		}
	}
	if(flag==0)	
	{
		char garbage;
		printf("contact doesn't exist!\n");
		printf("\n\n\n\n\n");
		menu(contact,n);
	}
}
	//333

void display(struct phonebook contact[],int i,int n)
{
	printf("name : %s\n",contact[i].name);
	printf("phone number : %llu\n",contact[i].phnum);
	printf("address : %s\n",contact[i].address);
	printf("gender : %s\n",contact[i].gender);
	printf("mail : %s\n",contact[i].mail);
	printf("\n\n\n\n\n");
	menu(contact,n);
}

void add_delete(struct phonebook contact[],int n)
{
	int choice; int flag=0; int choice1; struct phonebook b;
	me:
	{
	printf("enter option\n 1.add 2.delete\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	
		n++;char tn[20];char ta[100];char tg[10]; char tm[20];		 char y[10]="yes";	char no[10]="no";    char ans[5];
		int choice1;
		printf("\t Add a user!\n");
		printf("Enter name\n");
		scanf("%s",tn);
		strcpy(contact[n-1].name,tn);
		printf("Enter phone numer\n");
		scanf("%lld",&contact[n-1].phnum);
		printf("Enter address\n");
		scanf("%s",ta);
		strcpy(contact[n-1].address,ta);
		here:
		{
			printf("Enter option\n 1.male 2.female\n");
			scanf("%d",&choice1);
			switch(choice1)
			{
			case 1:
				strcpy(contact[n-1].gender,"male");
				break;
			case 2:
				strcpy(contact[n-1].gender,"female");
				break;
			default:
			{
				printf("enter valid option\n");
				goto here;
			}
			}
		}
		printf("Enter mail\n");
		scanf("%s",tm);
		strcpy(contact[n-1].mail,tm);
		
			herex: 
			{
				printf("\ndo you want to see the added contact's details?\nyes/no\n");
				scanf("%s",ans);
				if(strcmp(ans,y)==0)
				{
					display(contact,n-1,n);
				}
				else if(strcmp(ans,no)==0)
				{
					printf("\n\n\n\n\n");
					menu(contact,n);
				}
				else
				{
					printf("please enter valid option\n"); 
					goto herex;
				}
			} 
		printf("\n\n\n\n\n");					//430
		menu(contact,n);	
		break;
	case 2:
	
		
		printf("Enter the user to be deleted\n");	
		scanf("%s",b.name);
		for (int i=0;i<n;i++)
		{
			if (strcmp(contact[i].name, b.name)==0)
			{
				flag=1;
				for(int j=i;j<=n;j++)
				{
					contact[j]=contact[j+1];
					break;
				}
			}
		
		}
		if(flag==0)	
		printf("contact doesn't exist\n");	n--;
	 break;
	default: 
		printf("invalid entry\n");
		goto me;
	}
}
	
	printf("\n\n\n\n\n");
	menu(contact,n);
}
