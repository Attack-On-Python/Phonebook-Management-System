struct phonebook 
{
	char name[45];
	unsigned long long int phnum;
	char address[100];
	char gender[10];
	char mail[50];
};

void menu(struct phonebook contact[],int n);
void modify(struct phonebook contact[],int n);
void list(struct phonebook contact[],int n);
void display(struct phonebook contact[],int i,int n);
void search(struct phonebook contact[],int n);
void delete(struct phonebook contact[],int n);
void add_delete(struct phonebook contact[],int n);
