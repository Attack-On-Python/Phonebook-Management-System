#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"server.h"

extern int n;

int main()						//20
{
	struct phonebook contact[50];

	int n=3;

	strcpy(contact[0].name,"Spoorthi");
	contact[0].phnum=1234567890;
	strcpy(contact[0].address,"Bengaluru");
	strcpy(contact[0].gender,"female");
	strcpy(contact[0].mail,"abcde123@gmail.com");

	strcpy(contact[1].name,"Shreya");
	contact[1].phnum=9987654321;
	strcpy(contact[1].address,"Bengaluru");
	strcpy(contact[1].gender,"female");
	strcpy(contact[1].mail,"somethin@yahoo.com");

	strcpy(contact[2].name,"Pramatha");
	contact[2].phnum=7439544890;
	strcpy(contact[2].address,"Carvar");
	strcpy(contact[2].gender,"female");
	strcpy(contact[2].mail,"destdgdhh@gmail.com");
 
	

	menu(contact,n);

	return 0;
}
