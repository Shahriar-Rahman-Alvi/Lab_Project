#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


struct book
{
    char title[100];
    char author[50];
    char isbn[20];
    char edition[20];
    int numcopy;
}info[100];



void addbook(int count)
{
    int i=(count-1);
    FILE *fptr=fopen("book.txt","a");
    printf("Enter title of the book: ");
    gets(info[i].title);
    printf("Enter the name of author: ");
    gets(info[i].author);
    printf("Enter the isbn number: ");
    gets(info[i].isbn);
    printf("Enter edition of the book: ");
    gets(info[i].edition);
    printf("Enter number of copies: ");
    scanf("%d",&info[i].numcopy);

    fputs(info[i].title,fptr);
    fprintf(fptr,"\n");
    fputs(info[i].author,fptr);
    fprintf(fptr,"\n");
    fputs(info[i].isbn,fptr);
    fprintf(fptr,"\n");
    fputs(info[i].edition,fptr);
    fprintf(fptr,"\n");
    fprintf(fptr,"%d",info[i].numcopy);
    fprintf(fptr,"\n");

    fclose(fptr);


}

void showbook()
{
    FILE *fptr=fopen("book.txt","r");
    char str[100];

    while(fgets(str,sizeof str,fptr)!=NULL)
    {
        puts(str);
    }
    fclose(fptr);
}

void srcharray()
{

    FILE *fptr=fopen("book.txt","r");
    struct book flist[2000];
    int indx = 0;
    int track = 0;
    char sbook[100];
    while(fgets(sbook,100,fptr)!= NULL)
    {
         if(indx == 0)
        {
            strcpy(flist[track].title,sbook);
            indx++;
        }
         else  if(indx == 1)
        {
            strcpy(flist[track].author,sbook);
            indx++;
        }
         else if(indx == 2)
        {
            strcpy(flist[track].isbn,sbook);
            indx++;
        }
         else if(indx == 3)
        {
            strcpy(flist[track].edition,sbook);
            indx++;
        }
          else if(indx == 4)
          {
              int a= 0;
              int b = 0;
              for(b=0;sbook[b]!=NULL;b++)
              {

              }
              int p=0;
              for(int i= b-2;i>=0;i--)
              {
                  a +=pow(10 ,p)*(sbook[i]-'0');
                  p++;
              }
              flist[track].numcopy = a;
               indx = 0;
               track++;
          }
        }
        for (int i=0; i< track ; i++)
        {
            puts(flist[i].title);
            puts(flist[i].author);
            puts(flist[i].isbn);
            puts(flist[i].edition);
            printf("%d",flist[i].numcopy);
            printf("\n");


        }


}

void searchbook()
{
    FILE *fptr=fopen("book.txt","r");
    char title[100];
    int i,found;
    printf("Title: ");
    gets(title);
    found=0;
    char str[100];

   //for(i=0;i<count;i++)
       while(fgets(str,sizeof str,fptr)!=NULL)
       {
           //puts (str);
        if(strcmp(title,str)==0){
                puts(info[i].title);

                puts(info[i].author);

                puts(info[i].isbn);

                puts(info[i].edition);

                printf("%d",info[i].numcopy);

                found=1;
        }



        }
        fclose(fptr);
}

struct student
{
    char name[50];
    char ID[15];
}stbook[100];

void sturegister(int count2)
{
    FILE *fps=fopen("student.txt","a");
    int i=count2-1;

         printf("Enter student's name: ");
         gets(stbook[i].name);
         printf("Enter student's ID: ");
         gets(stbook[i].ID);

         printf("Student's name: ");
         fputs(stbook[i].name,fps);
         fprintf(fps,"\n");
         printf("Student's ID: ");
         fputs(stbook[i].ID,fps);
         fprintf(fps,"\n");
         printf("Your registration is successful");
         getchar();
         fclose(fps);

}

void structure(int count3)
{
     FILE *fptr=fopen("book.txt","r");
    struct book flist[2000];
    int indx = 0;
    int track = 0;
    char sbook[100];
    while(fgets(sbook,100,fptr)!= NULL)
    {
         if(indx == 0)
        {
            strcpy(flist[track].title,sbook);
            indx++;
        }
         else  if(indx == 1)
        {
            strcpy(flist[track].author,sbook);
            indx++;
        }
         else if(indx == 2)
        {
            strcpy(flist[track].isbn,sbook);
            indx++;
        }
         else if(indx == 3)
        {
            strcpy(flist[track].edition,sbook);
            indx++;
        }
          else if(indx == 4)
          {
              int a= 0;
              int b = 0;
              for(b=0;sbook[b]!=NULL;b++)
              {

              }
              int p=0;
              for(int i= b-2;i>=0;i--)
              {
                  a +=pow(10 ,p)*(sbook[i]-'0');
                  p++;
              }
              flist[track].numcopy = a;
               indx = 0;
               track++;
          }
        }
        for (int i=0; i< track ; i++)
        {
            puts(flist[i].title);
            puts(flist[i].author);
            puts(flist[i].isbn);
            puts(flist[i].edition);
            printf("%d",flist[i].numcopy);
            printf("\n");


        }


}

int main()
{

    int choice;
    char buffer[5];
    struct book booklist[2000];
    int count = 0;
    int count2=0;
    int count3=0;


    while(trunc)
    {
        printf("Press 1 for book registration.\nPress 2 for showing books.\nPress 3 for showing books in array.\nPress 4 for searching books.\nPress 5 for student registration.\nPress 6 for structure.\nPress 7 for exit.\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        gets(buffer);

        if(choice==1)
        {
            count++;
            addbook(count);
        }
        else if (choice==2)
        {
            showbook();
        }
        else if (choice==3)
        {
            srcharray();
        }
        else if(choice==4)
        {
            searchbook();
        }
         else if(choice==5)
        {
            sturegister(count2);
        }
        else if(choice==6)
        {
            structure(count3);
        }
        else if(choice==7)
        {
        return 0;
        }
    }
}
