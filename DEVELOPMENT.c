#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void line_count(FILE *f2){
    rewind(f2);
    system("CLS");
    char ch;
    int line=1;
    rewind(f2);
    while(!feof(f2))
{

  ch = fgetc(f2);
  if(ch == '\n')
  {
    line++;
  }
}
system("COLOR 02");
    printf("lines %d\n\n",line);
}
void oparetor(FILE *f2){
    rewind(f2);
    system("CLS");
    char ch;
    int op=0;
    rewind(f2);
    while(!feof(f2))
{

  ch = fgetc(f2);
  if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='>'||ch=='<'||ch=='=')
  {
    op++;
  }
}
system("COLOR 02");
    printf("Oparetor :%d\n\n",op);
}

void delay(int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void comment(){
    system("CLS");
    FILE *fp,*fp1;
    char ch;
    fp=fopen("file2.txt","r");
    fp1=fopen("code2.txt","w");

    while(1)
    {
        ch=fgetc(fp);
        printf("first =%c\n",ch);
        if(ch==EOF)
                break;
        else
        {
            if(ch=='/')
            {
                ch=fgetc(fp);
                printf("Second %c",ch);
                if(ch=='/')
                {
                    while(1)
                    {
                    ch=fgetc(fp);
                    if(ch=='\n')
                    goto next;
                    }
                }
                else if(ch=='*')
                    {
                    while(1)
                        {
                        ch=fgetc(fp);
                            if(ch=='*')
                                {
                                    ch=fgetc(fp);
                                    if(ch=='/')
                                        {
                                        while(1)
                                            {
                                            ch=fgetc(fp);
                                            goto next;
                                            }
                                        }
                                        else
                                            printf("*");
                                    }
                            }
                        }
                        else
                                printf("/");
                }
        }
        next:
            fputc(ch,fp1);
    }
    system("COLOR 02");
    printf("Job Done\n\n");
}

void welcome(){
     int c;
FILE *file;
file = fopen("welcome.txt", "r");

    system("COLOR 3");
    if (file) {
    while ((c = getc(file)) != EOF)
        putchar(c);
    fclose(file);
}
    printf("\n");

}

void main_menu(){
    int i;
    FILE *f2;

    f2=fopen("file2.txt","r");

    while(i!=0){
        system("COLOR 3");
        printf("\t1:Line count.\n\t2:keyword.\n\t3:Oparetor.\n\t4:Delete Comment.\n\t0:exit\nPlease enter your choice:\n");
        scanf("%d",&i);
    switch(i){

        case 2:
        dosoft(f2);
        break;

        case 1:
        line_count(f2);
        break;

        case 3:
        oparetor(f2);
        break;
        case 4:
            comment();
            break;

    }
    }
    }

void dosoft(FILE *f2){
    rewind(f2);
    system("CLS");
    char a[100],b[100];
    int i,check=0;
    FILE *f1;
    f1=fopen("keyword.txt","r");
    while(fscanf(f2,"%s", a)!=EOF){

        for(i=0;i<35;i++){
            fscanf(f1,"%s",b);

            if(strcmp(a,b)==0)
                check++;
        }
        rewind(f1);
    }
    system("COLOR 02");
    if(check>0)
        printf("Total keyword: %d\n\n",check);
    else
        printf("There is no keyword\n\n");

}


int main()
{
    FILE *f1,*f2,*file;
    int i;
    system("COLOR 3");

    f1=fopen("keyword.txt","r");

    file = fopen("welcome.txt", "r");
    welcome();
    delay(5000);
    system("CLS");
    main_menu();

    return 0;
}


