#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void info();
void addrecord();
void viewrecord();
void searchrecord();
void deleterecord();
void login();
void exit();

struct record
{
	char id[10];
    char name[30];
    char age[6];
    char gender[10];
    char weight[20];
    char height[20];
    char haircolor[20];
    char eyecolor[20];
    char crime[40];
    char details[20];
    char court[20];
	char act[20];
    char punishment[50];
    char faddress[20];
    char fir[20];
    char emergencyc[20];
    char emergencyr[20];
    char datearr[20];
} a;

void info()
{
    printf("\n\n\n\t\t\t\t\t'' WELCOME to POLICE FIR RECORD MANAGEMENT ''\n\n\n");
    printf("\n\t\t\t\tCreated by :\n\n");
    printf("\t\t\t\tName:\tShahriar Rahman\t\t\tId:\t2022-3-60-036\n");
    printf("\t\t\t\tName:\tMd. Maruf Ahmed Anik\t\tId:\t2022-3-60-040\n");
    printf("\t\t\t\tName:\tMd. Fahimur Rahman\t\tId:\t2022-3-60-046\n");
    printf("\t\t\t\tName:\tMishal Ibna Mashud\t\tId:\t2022-3-60-053\n");
    printf("\n\n\n\t\t\t\tPress any key to continue . . . . . . \n");
    getchar();
    system("cls");
}

int main()
   {
    info();
	login();
	action();
	getchar();
    }

void action ()
{
        system("cls");
        int n;

       while(1)
    {
        printf("\t\t\t\t'' MAIN MENU''\n\n\n\n");
        printf("\t\t1. ADD FIR RECORD");
        printf("\n\t\t2. SEARCH RECORD");
        printf("\n\t\t3. LIST RECORD");
		printf("\n\t\t4. DELETE RECORD");
        printf("\n\t\t5. EXIT");
        printf("\n\n\t\tENTER YOUR CHOICE(1-6) :  ");
        scanf("%d",&n);

            if (n==1)
            {
           addrecord();
            break;
            }
            else if (n==2)
            {
             searchrecord();
            break;
            }
            else if (n==3)
            {
            viewrecord();
            break;
            }
            else if (n==4)
            {
            deleterecord();
            break;
            }
            else if (n==5)
            {
            Exit ();
        	  break;
            }
            else
            {
            printf("\n\t\tYOU ENTERED WRONG CHOICE.");
            printf("\n\n\t\tPRESS ANY KEY TO TRY AGAIN . . . .");
            getch();
            break;
            }
        system("cls");
    }
  return 0;
}

void addrecord( )
{
    system("cls");
    FILE *fp ;
    char another = 'Y' ,id[10];
    char filename[30];
    int choice;

    printf("\t\t\t \t '' ADD RECORDS  ''");
    printf("\n\n\tENTER FIRST NAME OF CONVICT(To Check whether record exists or not): ");
    fflush(stdin);
    gets(filename);

    fp = fopen ("filename", "ab" ) ;

    if ( fp == NULL )
    {

        fp=fopen("filename","ab");
        if(fp==NULL)
        {

            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return ;

        }
    }

    while ( another == 'Y'|| another=='y' )

    {
        choice=0;
        fflush(stdin);

		printf ( "\tENTER CONVICT CODE(To check whether it matches or not): ");
        scanf("%s",id);

		rewind(fp);

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.id,id)==0)
            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                choice=1;

            }

        }

        if(choice==0)
        {

            strcpy(a.id,id);

            printf("\n\tENTER NAME OF CONVICT: ");
            gets(a.name);
			printf("\tENTER SEX: ");
            gets(a.gender);
            printf("\tENTER AGE: ");
            gets(a.age);
            printf("\tENTER WEIGHT: ");
            gets(a.weight);
            printf("\tENTER HEIGHT(FT): ");
            gets(a.height);
            printf("\tENTER HAIRCOLOR: ");
            gets(a.haircolor);
            printf("\tENTER EYECOLOR: ");
            gets(a.eyecolor);
            printf("\tENTER FACE DETAILS: ");
            gets(a.details);
			printf("\tENTER CRIME: ");
            gets(a.crime);
            printf("\tENTER COURT: ");
            gets(a.court);
            printf("\tACT(under which convicted): ");
            gets(a.act);
            printf("\tENTER CONVICTION: ");
            gets(a.punishment);
            printf("\tCOMPLETE ADDRESS OF POLICE STATION: ");
            gets(a.faddress);
            printf("\tENTER POLICE NUMBER: ");
            gets(a.fir);
            printf("\tENTER EMERGENCY CONTACT: ");
            gets(a.emergencyc);
            printf("\tENTER RELATION OF EMERGENCY CONTACT WITH CONVICT: ");
            gets(a.emergencyr);
            printf("\tENTER DATE OF ARREST: ");
            gets(a.datearr);

            fwrite ( &a, sizeof ( a ), 1, fp ) ;
            printf("\nYOUR RECORD IS ADDED...\n");

        }

        printf ( "\n\tADD ANOTHER RECORD...(Y/N) \t" ) ;
        fflush ( stdin ) ;
        another = getch( ) ;

    }

    fclose ( fp ) ;
    printf("\n\n\tPRESS ANY KEY TO  GO TO THE MAIN MENU...");
    getch();
    action();

}

void searchrecord( )

{
	system("cls");
    FILE *fp ;
	char id[16],choice,filename[14];
    int ch;


    printf("\t\t\t\t'' SEARCH RECORDS '' ");


    do
	{

		printf("\n\tENTER THE PRISONER NAME TO BE SEARCHED:");
        fflush(stdin);
        gets(filename);

        fp = fopen ( "filename", "rb" ) ;


    		printf("\nENTER CONVICT CODE:");
            gets(id);
            system("cls");
            printf("\nTHE WHOLE RECORD IS:");

            while ( fread ( &a, sizeof ( a ), 1, fp ) == 1 )
            if(strcmpi(a.id,id)==0)
               { printf("\n");
                printf("\nCONVICT'S NAME IS: %s",a.name);
                printf("\nCONVICT'S GENDER IS: %s",a.gender);
                printf("\nCONVICT'S AGE IS: %s",a.age);
                printf("\nCONVICT'S WEIGHT IS: %s",a.weight);
                printf("\nCONVICT'S HEIGHT IS: %s",a.height);
                printf("\nCONVICT'S HAIRCOLOR IS: %s",a.haircolor);
				printf("\nCONVICT'S EYECOLOR IS: %s",a.eyecolor);
                printf("\nCONVICT'S CRIME IS: %s",a.crime);
                printf("\nFACE DETAIL: %s",a.details);
                printf("\nCOURT IS: %s",a.court);
                printf("\nACT IS: %s",a.act);
                printf("\nPRISONER'S CONVICTION IS: %s",a.punishment);
                printf("\nADDRESS OF POLICE STATION: %s",a.faddress);
                printf("\nPOLICE NUMBER IS: %s",a.fir);
                printf("\nCONVICT'S EMERGENCY CONTACT IS: %s",a.emergencyc);
                printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s",a.emergencyr);
                printf("\nARRESTED DATE: %s",a.datearr);
                printf("\n");
            }

        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
        fflush(stdin);

        scanf("%c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fp) ;

printf("\n\n\tPRESS ANY KEY TO  GO TO THE MAIN MENU...");
    getch();
    action();
}
void viewrecord()

{
    system("cls");
    FILE *fp;
    char filename[30];

    printf("\t\t\t\t '' LIST RECORDS ''");

    fp=fopen("filename","rb");
    rewind(fp);
    while((fread(&a,sizeof(a),1,fp))==1)
    {
        printf("\n\n\t\t::PRESS ENTER TO VIEW MORE RECORDS!::\n");
        printf("\nCONVICT'S NAME IS: %s",a.name);
        printf("\nCONVICT'S SEX IS: %s",a.gender);
        printf("\nCONVICT'S AGE IS: %s",a.age);
        printf("\nCONVICT'S WEIGHT IS: %s",a.weight);
        printf("\nCONVICT'S HEIGHT IS: %s",a.height);
        printf("\nCONVICT'S HAIRCOLOR IS: %s",a.haircolor);
		printf("\nCONVICT'S EYECOLOR IS: %s",a.eyecolor);
        printf("\nCONVICT'S CRIME IS: %s",a.crime);
        printf("\nFACE DETAILS: %s",a.details);
        printf("\nCOURT IS: %s",a.court);
        printf("\nACT: %s",a.act);
        printf("\nCONVICT'S CONVICTION IS: %s",a.punishment);
        printf("\nADDRESS OF POLICE STATION: %s",a.faddress);
        printf("\nPOLICE NUMBER: %s",a.fir);
        printf("\nCONVICT'S EMERGENCY CONTACT IS: %s",a.emergencyc);
        printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s",a.emergencyr);
        printf("\nARRESTED DATE: %s",a.datearr);
        getch();
    }
    fclose(fp);
	printf("\n\n\tPRESS ANY KEY TO  GO TO THE MAIN MENU...");
    getch();
    action();

}
void deleterecord( )

{

    system("cls");
    FILE *fp,*ft ;
    struct record file ;
    char filename[15],another = 'Y' ,id[16];;
    int choice,check;
    int j=0;
    char pass[8];


    printf("\t\t\t\t'' DELETE RECORDS  ''");

   while ( another == 'Y' || another == 'y' )

    {

    	printf("\n\tENTER THE NAME OF CONVICT TO BE DELETED:");
		fflush(stdin);
        gets(filename);
        fp = fopen ("filename", "rb" ) ;
        if ( fp == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
				}
				ft=fopen("temp","wb");

				if(ft==NULL)
                {
                	printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK");
                    getch();
                    return ;
                }
                printf("\n\tENTER THE ID OF RECORD TO BE DELETED:");
                fflush(stdin);
                gets(id);

        		while(fread(&file,sizeof(file),1,fp)==1)

                {

                    if(strcmp(file.id,id)!=0)

                        fwrite(&file,sizeof(file),1,ft);

                }
        fclose(ft);
        fclose(fp);
        remove("filename");
        rename("temp","filename");
        printf("\nDELETED SUCCESFULLY...");
       printf("\n\n\tPRESS ANY KEY TO  GO TO THE MAIN MENU...");
    getch();
    action();
    }
}

void login()
{
	int a=0,i=0;
    char uname[10],pword[10],c=' ';
    do
    {
        printf("\n\n\n\t\t\t\t\t'' Enter LOGIN INFORMATION:  ''\n");
        printf("\n\t\t\tENTER USERNAME: ");
        scanf("%s", &uname);
        printf("\n\t\t\tENTER PASSWORD: ");
        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];

            if(c==13)
                break;

            else printf("*");
                i++;
        }

        pword[i]='\0';
        i=0;

		if ( strcmp (uname, "admin") == 0 &&  strcmp (pword , "pass") == 0 )
        {
        printf(" \n\n\n\t\t\tYOUR LOGIN IS SUCCESSFUL .!..!!...!!!");
        printf("\n\n\n\t\t\tPress any key to continue . . . .");
        getch();
        break;
        }
        else
        {
		printf("\n\n\n\t\tYOUR LOGIN INFORMATION IS NOT CORRECT.");
		printf("\n\n\n\t\tPress any key to try again . . . . ");
		a++;

		getch();
		system("cls");
        }
    }
        while(a<=2);
        {
           if (a>2)
        {
		printf("\n\nYou have entered the wrong user name and password for four times");
        printf("\n\nPress any key to ''EXIT''");
		getchar();
        Exit ();

		}
		system("cls");

      }
}

void Exit ()
{
            system("cls");
            printf("\n\n\n\n\t\t\t\tTHANK YOU FOR USING THIS SYSTEM \n\n ");
            getch();
            exit(0);
}

