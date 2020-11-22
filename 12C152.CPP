//Header files
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<stdio.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdlib.h>

//Global variables
  double amount;
  int type;
  int i;

//Class / Structure definitions

  class price_list
	{
	 char mname[50];//movie name
	 double list[3];//three diff prices
	public:
	 void input(char sname[50]);
	 int display(char sname[50]);
	 void adminaccess(char sname[50]);//Allows admin to change prices
	};

void newhead()
{
clrscr();
cleardevice();
setfillstyle(7,YELLOW);
bar(35,35,585,90);
setfillstyle(7,RED);
bar(140,40,480,85);
setfillstyle(11,BLUE);
bar(145,45,475,80);
rectangle(145,45,475,80);
rectangle(140,40,480,85);
rectangle(35,35,585,90);
setcolor(WHITE);
settextstyle(1,0,3);
outtextxy(176,45,"THE CRITIC PARADISE");
setcolor(WHITE);
}

	int price_list::display(char sname[50])
	       {
		 price_list pl;
		 int k=5;

		 fstream fin ("pricelist.dat",ios::binary|ios::in|ios::out|ios::app);
		 if (!fin)
		 cout<<"\nERROR:: File pricelist.dat not found.\n";
		  else
		   {

		    while(fin.read((char *)&pl, sizeof(pl)))
		    {
		     if(strcmpi(pl.mname,sname)==0) //Checking if price list exists or not
		      {
		       newhead();
		       setfillstyle(1,BLUE);
		       bar(140,130,500,350);
		       setfillstyle(1,RED);
		       bar(140,130,500,170);
		       setfillstyle(1,GREEN);
		       bar(140,170,500,210);
		       setfillstyle(1,YELLOW);
		       bar(140,210,500,250);
		       setcolor(BLACK);
		       settextstyle(1,0,2);
		       outtextxy(200,140,"RENTING PORTAL");

		       outtextxy(150,180,"MOVIE NAME:");
		       gotoxy(40,13);
		       puts(pl.mname);
		       outtextxy(150,220,"PRICE LIST :");
		       setcolor(WHITE);

		       outtextxy(150,250,"1. Three Months--> Rs.");
		       gotoxy(55,17);
		       cout<<pl.list[0];
		       outtextxy(150,280,"2. Six Months----> Rs.");
		       gotoxy(55,19);
		       cout<<pl.list[1];
		       outtextxy(150,310,"3. Twelve Months-> Rs.");
		       gotoxy(55,21);
		       cout<<pl.list[2];
		       do
		       {
		       outtextxy(150,370,"Enter choice :") ;
		       gotoxy(55,25);
		       cin>>k;
		       }
		       while(!(k>=0&&k<4));
			 if(k!=0)
			 amount = pl.list[k-1];//To get the amount
			 type = k;

		      }
		     }
		   }
		  fin.close();
		  outtextxy(150,400,"Parsing information...");
		  delay(1000);
		  outtextxy(150,430,"Press any key to continue.");
		  getch();
		  return k;
	       } ;

	  void price_list::adminaccess(char sname[50])
	       {
	       newhead();
		 price_list pl;
		 strcpy(mname,sname);//smovie-the searched movie
		 fstream fin ("pricelist.dat",ios::binary|ios::in|ios::out);
		 gotoxy(0,10);
		 if (!fin)
		 {
		 cout<<"\nERROR:: File pricelist.dat not found.\n";
		 getch();
		 }
		  else
		   {

		    while(fin.read((char *)&pl, sizeof(pl)))
		    {
		     if(strcmpi(pl.mname,sname)==0) //Checking if price list exists or not
		      {
		       clrscr();
		       cout<<"\n\t\t";
		       puts(pl.mname);
		       cout<<"\n\tEXISTING PRICE LIST :\n";
		       cout<<"\n1. Three Months --> Rs."<<pl.list[0];
		       cout<<"\n2. Six Months --> Rs."<<pl.list[1];
		       cout<<"\n3. Twelve Months --> Rs."<<pl.list[2];
		       cout<<"\n\tNEW PRICE LIST :\n";
		       cout<<"\n1. Three Months --> Rs.";
		       cin>>pl.list[0];
		       cout<<"\n2. Six Months --> Rs." ;
		       cin>>pl.list[1];
		       cout<<"\n3. Twelve Months --> Rs.";
		       cin>>pl.list[2];
		       fin.seekp(-sizeof(pl),ios::cur);
		       fin.write((char *)&pl,sizeof(pl));
		       cout<<"\n\t\tUPDATION SUCCESSFULL";
		       getch();
		       }
		      break;
		    }
		   }
		  fin.close();
	       };

	 void price_list::input(char sname[50])
	    {
	     price_list pl;

	     fstream fin ("pricelist.dat",ios::binary|ios::in|ios::out|ios::app);
	     if (!fin)
	      cout<<"\nERROR:: File pricelist.dat not found.\n";
	     else
	       {
		int k=0;
		 while(fin.read((char *)&pl, sizeof(pl)))
		 {
		  if(strcmpi(pl.mname,sname)==0) //Checking if price list exists or not
		  {k=1;break;}
		 };
		 fin.close();
		  if(k!=1)
		  {
		    randomize();
		    strcpy(pl.mname,sname);
		    ofstream fout("pricelist.dat",ios::binary|ios::app);
		    for( i=0; i<3; i++)
		    {pl.list[i]=(i+1)*150+random(100);}
		    fout.write((char *)&pl,sizeof(pl));
		    fout.close();
		   }

	       }
	    };


 class ph
      {
	char name[50];
	char mname[50];
	int ty;
	double am;
	time_t ts;
	public:
	void get_val(char cname[50],char movname[50]);
	void disp_his(char cname[50]);
	 };


       void ph::get_val(char cname[50], char movname[50])
       {
	ph pp;
	strcpy(pp.name,cname);
	strcpy(pp.mname,movname);
	pp.ty=type;
	pp.am=amount;
	time(&pp.ts);
	ofstream fout("payment.dat",ios::binary|ios::app);
	fout.write((char*)&pp,sizeof(pp));
	fout.close();
	};

	void ph::disp_his(char cname[50])
	{
	int n=0;
	newhead();
	ifstream fin("payment.dat",ios::binary);
	cout<<"\n\n\n\n\n\n\n\n\n";
	if(!fin)
	 cout<<"Payment History not found";

	else
	  {
	    ph pp;
	     while(fin.read((char*)&pp,sizeof(pp)))
	     {
	      if(strcmp(pp.name,cname)==0)
		{
		 //Display List here
		 n++;
		 if(n==3)
		 {
		 n=1;
		 outtextxy(300,405,"Press any key to go to next page");
		 getch();
		 newhead();
		 gotoxy(0,10);
		 cout<<"\n\n\n\n\n\n";
		 }

		 cout<<"Rent details";
		 cout<<"\n\n";
		 cout<<"Name of movie : "<<pp.mname;
		 cout<<"\n";
		 cout<<"Name of customer : "<<pp.name;
		 cout<<"\n";
		 cout<<"Date of purchase : "<<ctime(&pp.ts);
		 cout<<"\n";
		 if(type==1)
		 cout<<"Purchase type : 3 months \n";
		 else if(type==2)
		 cout<<"Purchase type : 6 months\n";
		 else if(type==3)
		 cout<<"Purchase type : 12 months\n";
		 cout<<"\n\n";
		 //Do not give break
		 //Display three by three and give the next option
		 //To display the time object give: ctime(&pp.ts);
		 //For displaying type: if type is 1->three months, 2->six months, 3->twelve months
		}


	     }
	     fin.close();
	  }
	 }