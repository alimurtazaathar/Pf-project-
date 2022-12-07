#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct details//to hold email pass at runtime
{
   char email[30];
   char pass[10];
}s;
struct dummy//for comparison with pre-existing record 
{
	char em[30];
	char pa[10];
}d;
struct info
{
  char mail[30],name[20],father[30],cnic[16],add[40],num[12],col[20];
  int flag,c1,c2,c3;
}a;
int ch,choice,res,ent,c1,c2,c3; 
FILE *f,*p,*tf;
char temp_email[20],temp_pass[20],press,cho,col[20];
void signup(void);
void login(void);
void signup(void);
void result(void);
void chalan(struct info a);
void details(struct info a);
void banker(void);
void screen(void);
void card(struct info a);
int main(void)
{
	login();
	return 0;
}
void signup(void)
{
  FILE *p=fopen("record.txt","a+");
  printf("Enter email\n");
  scanf("%s",s.email);
  while(!feof(p))
  {
  	fread(&d,sizeof(d),1,p);
  	int j=strcmp(s.email,d.em);
  	if(j==0)
	  {
	  	printf("Email already exists\nEnter new email \n");
	  	scanf("%s",s.email);
	  	rewind(p);
      }  
  }
  printf("Create password\n");
  scanf("%s",s.pass);
  printf("Account created!\n\n");
  fwrite(&s,sizeof(s),1,p);
  fclose(p);
  printf("Press\n1.Login\n2.Mainscreen\n");
  while(1)
  {
  	scanf("%d",&ch);
  	if(ch==1)
    {
  	  login();
    }
    else if(ch==2)
    {
  	 //homepage
    }
	else printf("Enter correct choice\n");	
  }
}
void login(void)
{
  system("cls");	
  p=fopen("record.txt","r");
  printf("Enter email\n");
  scanf("%s",temp_email); 
  while(!feof(p))
  {
  	fread(&d,sizeof(d),1,p);
  	    if(strcmp(temp_email,d.em)==0)
	    {
	  	  for(int cnt=3;cnt>0;)
			{
			  printf("Enter password\n");
			  scanf("%s",temp_pass);
		      if(strcmp(temp_pass,d.pa)==0)
		       { 
			 	 printf("Login Successful!\n");
				 //calling some function but for now
				 screen();
		       }
		      else
		       {
		  	    cnt-=1;
				printf("Incorrect password.Tries left:%d",cnt);
		       }
		    }
			printf("Incorrect password!.\nPress 1 toRegister\nPress 2 to Login again\n");
			scanf("%d",&ch);  
			 while(1)
	        {	
		      if(ch==1)
		      {
			    signup();
		      } 
		      else if(ch==2)
		      {
			    login();
		      }
            }
        } 

  }
    if(feof(p))
	{
		printf("Email not found.Please\n1.register\nOR\n2.Login again\n");
		scanf("%d",&ch);
	   while(1)
	   {	
		 if(ch==1)
		 {
			signup();
		 } 
		 else if(ch==2)
		 {
			login();
		 }
       }
	}
}
void details(struct info a)
{
    printf("\t\t\t\t\tD E T A I L S\n");	
	FILE *f;
	f=fopen("Info.txt","a+");
	while(!feof(f))
	{
		fread(&a,sizeof(a),1,f);
		int i=strcmp(a.mail,s.email);
		if(i==0)
		{
			goto label;
		}
	}
	printf("Enter full name\n");
	scanf("%s",a.name);
	printf("Enter father name\n");
	scanf("%s",a.father);
	printf("Enter CNIC number\n");
	scanf("%s",a.cnic);
	printf("Enter address\n");
	scanf("%s",a.add);
	printf("Enter number\n");
	scanf("%s",a.num);
	a.flag=0;
	fwrite(&a,sizeof(a),1,f);
	fclose(f);
	printf("Enter Qualification\n1.A-levels\n2.Intermediate\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
			printf("Enter College\n");
			scanf("%s",col);
			printf("Enter equivalency(incase of awaited result press 1)\n");
			scanf("%d",&res);
			if(res==1)
			{
				char res1[]="Awaited";
			}
			break;
		}
		case 2:
		{
			printf("Enter College\n");
			scanf("%s",col);
			break;
		}
		default:
		{
			break;
		}
	}
	printf("Enter desired department\nChoose three in accordance to preference\n1.CS\t\t2.SE\t\t3.CYS\t\t4.BBA\t\t5.AI\t\t6.Robotics\n");
    scanf("%d %d %d",&c1,&c2,&c3);
    label:
    printf("Name: %s\nFather's name: %s\nCNIC: %s\nAddress: %s\nNumber: %s\nEmail: %s\nCollege: %s\nPreference: 1.");
		
    //printf("Press P to print chalan\n");
    //while(1)
	//{
	 // scanf("%c",&press);
	  //if(press=='p')
	 // {
	//	chalan(name,father,cnic,num);
	//	break;
	  //}
    //}
    printf("Press any key to proceed to mainscreen\n");
    scanf("%c",&cho);
    screen();
}
void chalan(struct info a)
{
	system("cls");
	int i;
	for(i=0;i<7;i++)
	{
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    }
    printf("\n|\n|\n|\tNAME:%s\n|\n",a.name);
    printf("|\tFather's Name:%s\n|\n",a.father);
    printf("|\tCNIC:%s\n|\n",a.cnic);
    printf("|\tNumber:%s\n|\n",a.num);
    printf("|\tRegistration Fees in words:Eight Hundred Rupees\n|\n|\tRegistration Fees in numeral:Rs.800\n|\n");
    printf("|\tAccount name:FastNuceskarachi\n|\n");
	printf("|\tIBAN: PK34ZMEJ8318654496338966\n|\n");
	printf("|\tIssue date: 01-06-22\n|\n");
	printf("|\tDue date:01-07-22");
    printf("\n|\n|\n|NOTE:Pay this fee voucher at your nearest branch of Bank Faysal before 1st of july\n|-All chalans submitted after due date may be considered void.\n|-A copy of the submitted challaan should be submitted on campus\n|on the day of admission test.-\n|-Financial aid applications should be submitted with printed fee chalan at campus.\n|\n");
    for(i=0;i<7;i++)
	{
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    }
}
void screen (void)
{
	system("cls");
	printf("\t\t\t\t\tWELCOME TO ADMISSION PORTAL\nPress\n1.Details\n2.Chalan\n3.Admit card\n4.Result");
	scanf("%d",&ent);
    while(1)
	{
		switch(ent)
		{
			case 1:
			{
				details(a);
				break;
			}
			case 2:
			{
				chalan(a);
				break;
			}
			case 3:
			{
				card(a);
				break;
			}
			case 4:
			{
				result();
				
				break;
			}
			default:
			{
				printf("Input valid choice\n");
				break;
			}
		}
	}
}
void card (struct info a)
{
	f=fopen("info.txt","r");
	fread(&a,sizeof(a),1,f);
	if(a.flag==0)
	{
		printf("You have not submitted registration fees yet!\n");
	}
	else
	{
		//card banado
	}
	printf("Enter any key to go to main screen\n");
	scanf("%c",&ch);
	screen();	
}
void result (void)
{
	;
}

