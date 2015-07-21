#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


static bool IsLetter(char * );
static bool IsDigit(char *);
static bool IsSymbol(char *);
void fun();

int main (){
	char *password, *password_conf;
	
	char c[20];
	bool a,b,d;

//	printf("Please enter the password : ");
	password = getpass("enter password : ");
	password_conf = getpass("confirm the password : ");

	printf("password_conf = %s\n", password_conf);
	
	if(!strcmp(password,password_conf)== 0){
		
		printf("Congratulations you successfully registeres in the program\n");
	}
	
	else{
		
		printf("Passwords dont match please try again\n");
		fun();
	}

	strcpy(c,password_conf);

	printf("c = %s\n",c);

	a = IsLetter(c);
	b = IsDigit(c);
	d = IsSymbol(c);

	printf("a = %d b = %d d = %d\n",a,b,d );

	if(a && b && d){
		printf("%s\n", "Very strong\n");
	}
	else if((a && b) || (a && d) || (b && d)){
		printf("%s\n", "Modarate\n");
	}
	else
		printf("%s\n", "Weak\n");
}

bool IsLetter(char *c)
{
	char *L;
	int a,i;
	L = c;
	a = strlen(L);
	// printf("%s\n", L);

	for(i = 0; i < a; i++){
		if ((L[i] >= 'a' && L[i] <= 'z') || (L[i] >= 'A' && L[i] <= 'Z'))
		{
			return 1;
		}
	}
	return 0;
}

static bool IsDigit(char *c)
{
	char *L;
	int a, i;
	L = c;
	a = strlen(L);
	for(i = 0;i < a; i++){
		if(L[i] >= '0' && L[i] <= '9'){
			return 1;
		}
	}
	return 0;
}

static bool IsSymbol(char *c)
{
	char *L;
	int a, i;
	L = c;
	a = strlen(L);
	for(i = 0;i < a; i++){
		if(L[i] > 32 && L[i] < 127 && !IsDigit((L + i)) && !IsLetter((L + i))){
			return 1;
			// break;
		}
	}
	return 0;

}

void fun(){
	printf("%s\n", "sorry wrong match\n");
}