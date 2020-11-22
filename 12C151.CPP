#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdlib.h>
#include "12c152.cpp"

struct customer
{
char name[100];
long int phno;
char address[100];
char email[50];
char password[20];
char custorev[100];
};
customer s;

struct movie
{
char mname[100];
char actors[100];
char date[100];
char desc[100];
char review[100];
double rating;
};
movie m;

struct review
{
char custname[100];
char custreview[100];
double custrat;
char movname[100];
};
review r;

struct probo
{
char prob[200];
char inname[100];
};
probo t;

struct sol
{
char response[200];
char solname[100];
};
sol q;

class movieo
{
public:
void disp();
void screen1();
void header();
void enterpass();
void login();
void signup();
void admin();
void helpdesk();
void adminmenu();
void initialize();
void cinbox();
void addmov();
void info();
void inbox();
void rent();
void resp();
void best3();
void removemov();
void displaycust();
void viewrev();
void addr();
void dispdetails();
void moviescreen();
void displaymov();
void viewmovie();
void updatemov();
};

int maxx,maxy;
void initialize(void)
{
int GraphDriver=DETECT,GraphMode;
int ErrorCode;
initgraph(&GraphDriver,&GraphMode,"c:\\turboc3\\bgi");
ErrorCode=graphresult();
if(ErrorCode!=grOk)
{
exit(1);
}
maxx=getmaxx();
maxy=getmaxy();
}

int main()
{
initialize();
movieo mo;
mo.screen1();
cleardevice();
closegraph();
return 0;
}

void movieo::info()
{
header();
int i;
for(i=0;i<15;i++)
{
delay(50);
setcolor(i);
circle(55,110,i);
circle(105,110,i);
circle(155,110,i);
circle(205,110,i);
circle(255,110,i);
circle(305,110,i);
circle(355,110,i);
circle(405,110,i);
circle(455,110,i);
circle(505,110,i);
circle(555,110,i);

circle(55,160,i);
circle(55,210,i);
circle(55,260,i);
circle(55,310,i);
circle(55,360,i);
circle(55,410,i);
circle(55,460,i);

circle(555,160,i);
circle(555,210,i);
circle(555,260,i);
circle(555,310,i);
circle(555,360,i);
circle(555,410,i);
circle(555,460,i);

circle(55,460,i);
circle(105,460,i);
circle(155,460,i);
circle(205,460,i);
circle(255,460,i);
circle(305,460,i);
circle(355,460,i);
circle(405,460,i);
circle(455,460,i);
circle(505,460,i);
circle(555,460,i);
}

setfillstyle(1,WHITE);
bar(80,130,530,440);
setcolor(BLACK);
rectangle(85,135,525,435);
delay(1000);
settextstyle(1,0,2);                                      //
outtextxy(90,140,"This portal THE CRITIC PARADISE was");
outtextxy(90,170,"designed by Manthan Tarafdar & Mahesha");
outtextxy(90,200,"Ganapath of class XII of DAV Senior");
outtextxy(90,230,"Secondary school. A lot of hardwork has");
outtextxy(90,260,"gone into the making of this portal.");
outtextxy(90,290,"Special thanks to Mrs. Uma Arthi, our");
outtextxy(90,320,"subject teacher without whom this portal");
outtextxy(90,350,"wouldnt have been complete.");
outtextxy(90,380,"Hope this portal was of paramount help");
outtextxy(90,410,"to the user.");
outtextxy(250,410,"Thankyou.");
setcolor(WHITE);
getch();
screen1();
}


void movieo::header()
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

void movieo::screen1()
{
int ch1;
header();
setfillstyle(9,BLUE);
bar(35,140,585,400);
setfillstyle(1,BLACK);
bar(350,140,585,400);
rectangle(35,140,585,400);
rectangle(350,140,585,400);

setfillstyle(1,GREEN);
bar(38,150,340,180);//textbars
setfillstyle(1,RED);
bar(38,190,340,340);

settextstyle(1,0,2);
setcolor(GREEN);
outtextxy(355,140,"THE CRITIC PARADISE");
outtextxy(355,160,"is a movie review");
outtextxy(355,180,"portal that enables");
outtextxy(355,200,"you to view, rent");
outtextxy(355,220,"and post reviews ");
outtextxy(355,240,"about movies.");
setcolor(YELLOW);
outtextxy(355,260,"Please follow the");
outtextxy(355,280,"instructions given");
outtextxy(355,300,"to start with the");
outtextxy(355,320,"portal.");
setcolor(BLACK);
outtextxy(40,150,"ENTER PRECEEDING NUMBER.");
outtextxy(40,190,"1.Login.");
outtextxy(40,220,"2.Signup");
outtextxy(40,250,"3.Administrator login.");
outtextxy(40,280,"4.Credits.");
outtextxy(40,310,"5.Exit.");
setcolor(WHITE);
outtextxy(475,376,"Enter :");
gotoxy(70,25);
setcolor(WHITE);
cin>>ch1;
if(ch1==4)
info();
if(ch1==6)
disp();
if (ch1==1)
{
outtextxy(35,405,"WAIT...");
delay(1000);
login();
}

if (ch1==2)
{
outtextxy(35,405,"WAIT...");
delay(1000);
signup();
}

if (ch1==3)
{
outtextxy(35,405,"WAIT...");
delay(1000);
admin();
}
}

void movieo::signup()
{
int ch2;
header();
bar(30,200,200,225);//info
bar(30,232,200,257);//^
bar(30,264,200,289);// ^
bar(30,297,200,322);//  ^
setcolor(WHITE);
settextstyle(1,0,2);
fstream f("customer.dat",ios::binary | ios::in | ios::out | ios::app);
outtextxy(0,143,"Please enter the following details to create a 1 time account.");
outtextxy(30,199,"Holder name :");
outtextxy(30,231,"Phone number :");
outtextxy(30,263,"Valid email id :");
outtextxy(30,296,"Address :");
gotoxy(30,14);
gets(s.name);
setfillstyle(1,GREEN);
bar(30,200,200,225);
outtextxy(30,199,"Holder name :");
gotoxy(30,16);
cin>>s.phno;
setfillstyle(1,GREEN);
bar(30,232,200,257);
outtextxy(30,231,"Phone number :");
gotoxy(30,18);
gets(s.email);
setfillstyle(1,GREEN);
bar(30,264,200,289);
outtextxy(30,263,"Valid email id :");
gotoxy(30,20);
gets(s.address);
f.close();
setfillstyle(1,GREEN);
bar(30,297,200,322);
outtextxy(30,296,"Address :");
outtextxy(0,350,"Parsing information...");
delay(1000);
enterpass();
}


void movieo::enterpass()
{
char pass[20], passagain[20];
int k;
header();
fstream f("customer.dat", ios::binary | ios::in | ios::out | ios::app);
do
{
header();
settextstyle(1,0,2);
outtextxy(0,143,"The password you are going to enter will be essential in ");
outtextxy(0,163,"future login. It is a ONE TIME password.");
outtextxy(30,215,"Enter password :");
gotoxy(30,15);
gets(pass);
outtextxy(30,247,"Reenter password :");
gotoxy(30,17);
gets(passagain);
  if(strcmp(pass,passagain)==0)
  {
  k=2;
  strcpy(s.password,pass);
  f.write((char*)&s , sizeof(s));
  f.close();
  setcolor(GREEN);
  outtextxy(30,300,"Account successfully created!");
  delay(2000);
  }
  else
  {
  k=0;
  setcolor(RED);
  outtextxy(30,300,"Password missmatch.Please try again.Wait...");
  delay(1000);
  }
  screen1();
}
while(k==0);

getch();
f.close();
setcolor(WHITE);
}

void movieo::login()
{
int k;
char namei[20], passi[20];
header();
settextstyle(1,0,2);
outtextxy(0,143,"Since you already have an existing account, enter the foll.");
fstream f("customer.dat", ios::binary | ios::in | ios::out );
outtextxy(30,215,"Enter name :");
gotoxy(30,15);
gets(namei);
outtextxy(30,247,"Enter password :");
gotoxy(30,17);
gets(passi);
while(f.read((char*)&s, sizeof(s)))
{
if(strcmpi(namei,s.name)==0 && strcmpi(passi,s.password)==0)
 {
 setcolor(GREEN);
 outtextxy(30,300,"Login successfull");
 k=1;
 setcolor(WHITE);
 outtextxy(30,330,"Press any key to continue.");
 getch();
 moviescreen();
 }
}
 if(k==0)
 {
 setcolor(RED);
 outtextxy(30,300,"Wrong.Redirecting to main screen");
 delay(1000);
 screen1();
 }
f.close();
}


void movieo::moviescreen()
{
header();
setfillstyle(1,WHITE);
bar(50,100,570,130);     //name bar
rectangle(47,97,573,133);

setfillstyle(9,BLUE);
bar(50,150,570,400);     //lower bar
setcolor(WHITE);
rectangle(47,147,573,403);

setfillstyle(1,WHITE);
bar(60,180,200,200);   //inner bars
bar(60,220,200,240);
bar(60,260,200,280);
bar(60,300,200,320);
bar(60,340,200,360);
setfillstyle(1,YELLOW);
bar(260,180,560,360);  //^^


setcolor(BLACK);
settextstyle(1,0,1);
outtextxy(60,180,"1.View/review");
outtextxy(60,220,"2.Rent/cart");
outtextxy(60,260,"3.Inbox.");
outtextxy(60,300,"4.Help desk.");
outtextxy(60,340,"5.Logout.");
fstream f("customer.dat", ios::binary | ios::in | ios::out );
outtextxy(60,100,"Name :");
outtextxy(140,100,s.name);
f.close();
best3();
setcolor(WHITE);
int ch6;
outtextxy(475,376,"Enter :");
gotoxy(70,25);
cin>>ch6;
if(ch6==4)
helpdesk();
if(ch6==2)
rent();
if(ch6==1)
viewmovie();
if(ch6==3)
cinbox();
if(ch6==5)
screen1();
}

void movieo::rent()
{
int choice;
header();
setfillstyle(9,BLUE);
bar(30,150,380,310);
setfillstyle(1,GREEN);
bar(60,180,350,200);   //inner bars
bar(60,220,350,240);
bar(60,260,350,280);
setcolor(BLACK);
settextstyle(1,0,2);	/////////////////////////////
outtextxy(60,180,"1.Search movie.");
outtextxy(60,220,"2.View purchase history.");
outtextxy(60,260,"3.Go back.");
setcolor(WHITE);
outtextxy(475,376,"Enter :");
gotoxy(70,25);
cin>>choice;
if(choice==1)
{
int x=0;
price_list p;
char movname[100];
header();
setfillstyle(1,WHITE);
bar(60,170,560,340);

rectangle(57,167,563,343);
rectangle(54,164,566,346);

setfillstyle(1,RED);
bar(70,200,205,225);
settextstyle(1,0,2);
setcolor(BLACK);
outtextxy(70,199,"Movie name :");
gotoxy(30,14);
gets(movname);
ifstream f("movie.dat" , ios::binary);
while(f.read((char *)&m, sizeof(m)))
{
  if(strcmpi(m.mname,movname)==0)
  {
  x++;
  }
}
setcolor(BLACK);
if(x==0)
{
setcolor(RED);
settextstyle(1,0,2);
outtextxy(70,300,"No such movie found.");
getch();
moviescreen();
}
  else
      {
      ph pp;
      p.input(movname);
      if(p.display(movname))
      pp.get_val(s.name,movname);
      moviescreen();
      getch();
     }
     }
 else if(choice==2)
 {
 ph pp;
 pp.disp_his(s.name);
 getch();
 moviescreen();
 }
 else if(choice==3)
 moviescreen();
}

void movieo::cinbox()
{
int j;
header();
gotoxy(0,10);
cout<<"\n\n\n\n\n\n\n\n";
fstream fo("customer.dat" , ios::binary | ios::in | ios::out);
fstream f("probo.dat" , ios::binary | ios::out | ios::in);
while(f.read((char *)&q , sizeof(q)))
{
if(strcmpi(q.solname,s.name)==0)
{
j++;
cout<<"Response from admin";
cout<<"\n\n";
puts(q.response);
cout<<"\n\n";
}
}
if(j==0)
{
cout<<"No response yet.";
}
fo.close();
f.close();
getch();
moviescreen();
}





void movieo::helpdesk()
{
header();                     /////////////////////////////
gotoxy(0,10);
cout<<"\n\n\n\n\n\n\n";
fstream f("problem.dat" , ios::binary | ios::out | ios::in | ios::app);
cout<<"Please enter any suggestion / complain / doubt so that your problem can be solved by the admin";
cout<<"\t\t";
gets(t.prob);
strcpy(t.inname,s.name);
f.write((char *)&t, sizeof(t));
f.close();
outtextxy(0,300,"Parsing information...");
delay(1000);
outtextxy(0,320,"Your problem has been successfully parsed!");
outtextxy(0,340,"Do check out for a response!");
outtextxy(0,360,"Press any key to continue.");
getch();
moviescreen();
}


void movieo::viewmovie()
{
int x=0;
char movname[100];
header();
setfillstyle(1,WHITE);
bar(60,170,560,340);

rectangle(57,167,563,343);
rectangle(54,164,566,346);

setfillstyle(1,RED);
bar(70,200,205,225);
settextstyle(1,0,2);
setcolor(BLACK);
outtextxy(70,199,"Movie name :");
gotoxy(30,14);
gets(movname);
ifstream f("movie.dat" , ios::binary);
while(f.read((char *)&m, sizeof(m)))
{
  if(strcmpi(m.mname,movname)==0)
  {
  x++;
  dispdetails();
  }
}
setcolor(BLACK);
if(x==0)
{
setcolor(RED);
settextstyle(1,0,2);
outtextxy(70,300,"No such movie found.");
getch();
}
moviescreen();
}


void movieo::dispdetails()
{
char review[100];
int ch7;
header();
setfillstyle(1,GREEN);
bar(30,200,200,225);//info
bar(30,232,200,257);//^
bar(30,264,200,289);// ^
bar(30,296,200,315);//   ^
bar(30,360,200,385);
setfillstyle(11,BLUE);
bar(30,100,585,190);//review
setcolor(WHITE);//^^
rectangle(30,100,585,190);
fstream fo("movie.dat", ios::binary | ios::in | ios::out | ios::app );
settextstyle(1,0,2);
outtextxy(30,199,"Movie name :");
outtextxy(30,231,"Actors :");
outtextxy(30,263,"Date of release :");
outtextxy(30,295,"Description :");
outtextxy(30,360,"Jury rating :");
gotoxy(30,14);
puts(m.mname);
gotoxy(30,16);
puts(m.actors);
gotoxy(30,18);
puts(m.date);
gotoxy(30,20);
puts(m.desc);
gotoxy(30,24);
cout<<m.rating;
fo.close();
settextstyle(1,0,1);
outtextxy(30,100,"Enter preceeding number.");
outtextxy(35,120,"1.View latest customer reviews");
outtextxy(35,140,"2.Add review,rating");
outtextxy(35,160,"3.Previous page.");
outtextxy(475,376,"Enter : ");
gotoxy(70,25);
cin>>ch7;
if(ch7==1)
viewrev();
if(ch7==2)
addr();
}


void movieo::viewrev()
{
int  xo=0,no=0;
header();
fstream f("review.dat",ios::binary | ios::in | ios::out);
fstream fo("movie.dat",ios::binary | ios::in | ios::out);
setcolor(WHITE);
gotoxy(0,10);
cout<<"\n\n\n\n\n\n\n";
cout<<"Movie name :  ";
cout<<m.mname;
gotoxy(0,10);
cout<<"\n\n\n";
while(f.read((char *)&r, sizeof(r)))
{
if(strcmpi(r.movname,m.mname)==0)
{
no++;
if(no==3)
{
no=1;
settextstyle(1,0,2);
outtextxy(300,405,"Press any key to go to next page.");
getch();
header();
gotoxy(0,10);
cout<<"\n\n\n\n\n\n\n";
}
xo++;
cout<<"Details";
cout<<"\n";
cout<<"Customer name :   ";
puts(r.custname);
cout<<"Review :    ";
puts(r.custreview);
cout<<"Rating :    ";
cout<<r.custrat;
cout<<"\n\n";
}
}
if(xo==0)
{
cout<<"\n\n\nNo reviews yet!";
}
fo.close();
f.close();
getch();
setcolor(WHITE);
outtextxy(17,405,"WAIT...");
delay(1000);
dispdetails();
}

void movieo::addr()
{
header();
setfillstyle(1,WHITE);
bar(60,170,560,340);

rectangle(57,167,563,343);
rectangle(54,164,566,346);

setfillstyle(1,RED);
bar(70,200,205,225);
bar(70,239,205,264);
settextstyle(1,0,2);
setcolor(BLACK);
fstream f("review.dat" , ios::binary | ios::in | ios::out | ios::app);
ifstream fo("movie.dat" , ios::binary);
ifstream fe("customer.dat" , ios::binary);
outtextxy(70,199,"Review :");
outtextxy(70,239,"Rating(10) :");
gotoxy(30,14);
gets(r.custreview);
setfillstyle(1,GREEN);
bar(70,200,205,225);
outtextxy(70,199,"Review :");
gotoxy(30,16);
cin>>r.custrat;
setfillstyle(1,GREEN);
bar(70,239,205,264);
outtextxy(70,239,"Rating(10) :");
strcpy(r.custname,s.name);
strcpy(r.movname,m.mname);
f.write((char *)&r,sizeof(r));
outtextxy(70,270,"Review and rating updated.");
f.close();
fo.close();
fe.close();
getch();
dispdetails();
}


void movieo::disp()
{
header();
gotoxy(0,10);
cout<<"\n\n\n\n";
fstream f ("review.dat" , ios::binary | ios::in | ios::out);
while(f.read((char *)&r , sizeof(r)))
{
puts(r.custname);
puts(r.custreview);
puts(r.movname);
cout<<r.custrat;
cout<<"\n\n";
}
f.close();
getch();
}


void movieo::best3()
{
char movie1[100],movie2[100],movie3[100];
double max1=0.0,max2=0.0,max3=0.0;
ifstream fo("movie.dat", ios::binary);
ifstream fe("movie.dat", ios::binary);
ifstream fi("movie.dat", ios::binary);
if(!fo)
outtextxy(270,190,"No movies.");
while(fo.read((char *)&m , sizeof(m)))
{
if(m.rating>=max1)
{
max1=m.rating;
strcpy(movie1,m.mname);
}
}
fo.close();

while(fe.read((char *)&m , sizeof(m)))
{
if(m.rating>=max2&&m.rating<max1)
{
max2=m.rating;
strcpy(movie2,m.mname);
}
}
fe.close();

while(fi.read((char *)&m , sizeof(m)))
{
if(m.rating>=max3&&m.rating<max2)
{
max3=m.rating;
strcpy(movie3,m.mname);
}
}

fi.close();
setcolor(CYAN);
outtextxy(350,190,"Hot picks today");
setcolor(GREEN);
outtextxy(270,250,"Rank 1");
outtextxy(270,290,"Rank 2");
outtextxy(270,330,"Rank 3");
setcolor(BLACK);
outtextxy(270,230,movie1);
outtextxy(270,270,movie2);
outtextxy(270,310,movie3);
}



void movieo::admin()
{
setcolor(WHITE);
delay(2000);
char passcode[20];
char ch4;
do
{
header();
setfillstyle(10,BLUE);
bar(0,145,603,398);
rectangle(0,145,605,400);
settextstyle(1,0,2);
setcolor(WHITE);
outtextxy(10,150,"Please enter the admininstrator pass code");
outtextxy(30,215,"Enter passcode :");
gotoxy(30,15);
cin>>passcode;
  if(strcmp(passcode,"teammama")==0)
  {
  setfillstyle(1,GREEN);
  bar(8,300,300,325);
  setcolor(WHITE);
  outtextxy(10,300,"Admin login successfull ! ");
  outtextxy(17,405,"WAIT...");
  delay(2000);
  adminmenu();
  }
  else
  {
  setfillstyle(1,RED);
  bar(8,300,230,325);
  setcolor(WHITE);
  outtextxy(8,300,"Passcode missmatch.");
  outtextxy(30,349,"Try agian?");
  gotoxy(20,23);
  cin>>ch4;
  if(ch4=='n')
  {
  outtextxy(17,405,"WAIT...");
  delay(1000);
  screen1();
  }
 }
}
while(ch4=='y');
}



void movieo::adminmenu()
{
int k;
header();
setfillstyle(1,BLUE);
bar(80,130,540,340);

setfillstyle(7,RED);
bar(100,150,520,320);

setfillstyle(1,YELLOW);
bar(120,170,500,300);

setcolor(BLACK);
settextstyle(1,0,2);//normal font
outtextxy(130,170,"1.To view details of all customers");
outtextxy(130,195,"2.To view details of all movies");
outtextxy(130,220,"3.To update movie/inbox");
outtextxy(130,245,"4.To respond.");
outtextxy(130,270,"5.To go back.");
setcolor(WHITE);
outtextxy(475,376,"Enter :");
gotoxy(70,25);
cin>>k;

if(k==1)
{
outtextxy(17,405,"WAIT...");
delay(2000);
displaycust();
}
if(k==3)
{
outtextxy(17,405,"WAIT...");
delay(2000);
updatemov();
}
if(k==2)
{
outtextxy(17,405,"WAIT...");
delay(2000);
displaymov();
}
if(k==4)
{
outtextxy(17,405,"WAIT...");
delay(2000);
resp();
}

if(k==5)
{
outtextxy(17,405,"WAIT...");
delay(2000);
screen1();
}
}


void movieo::inbox()
{
int n=0;
header();
fstream f("problem.dat" , ios::binary | ios::in | ios::out);
gotoxy(0,10);
cout<<"\n\n\n\n\n\n\n\t\t\t\t";
cout<<"INBOX";
cout<<"\n\n";
while(f.read((char *)&t , sizeof(t)))
{
n++;
if(n==4)
{
n=1;
outtextxy(300,405,"Press any key to go to next page.");
getch();
header();
gotoxy(0,10);
cout<<"\n\n\n\n\n\n\n";
}
cout<<"Details";
cout<<"\n\n";
cout<<"Name :    ";
puts(t.inname);
cout<<"Thoughts :    ";
puts(t.prob);
}
f.close();
getch();
setcolor(WHITE);
outtextxy(17,405,"WAIT...");
delay(1000);
updatemov();
}

void movieo::resp()
{
header();
cout<<"\n\n\n\n\n\n\n\n";
fstream f("probo.dat" , ios::binary | ios::in | ios::out |ios::app);
cout<<"Enter name of account holder :  ";
gets(q.solname);
cout<<"\n\nEnter response :  ";
gets(q.response);
f.write((char *)&q , sizeof(q));
outtextxy(0,280,"WAIT...");
delay(1000);
outtextxy(0,300,"Response sent.");
outtextxy(0,320,"Press any key to continue.");
f.close();
getch();
adminmenu();
}






void movieo::removemov()
{
int n=0, x=0;
char movname[100];
header();
setfillstyle(1,WHITE);
bar(60,170,560,340);

rectangle(57,167,563,343);
rectangle(54,164,566,346);

setfillstyle(1,RED);
bar(70,200,205,225);
settextstyle(1,0,2);
setcolor(BLACK);
outtextxy(70,199,"Movie name :");
gotoxy(30,14);
gets(movname);
outtextxy(70,199,"Movie name :");
ifstream fin("movie.dat" , ios::binary);
 if(!fin)
 {
 setcolor(BLACK);
 outtextxy(50,300,"File does not exist.");
 getch();
 }
  else
  {
  ofstream fout("temp.dat", ios::binary);
  while(fin.read((char *)&m, sizeof(m)))
  {
  n++;
  if(strcmpi(m.mname,movname)!=0)
  {
  x++;
  fout.write((char*)&m,sizeof(m));
  }
  if(strcmpi(m.mname,movname)==0)
  {
  setfillstyle(1,GREEN);
  bar(70,200,205,225);
  outtextxy(70,199,"Movie name :");
  setcolor(BLACK);
  outtextxy(70,300,"Movie details has been successfully deleted.");
  }
  }
setcolor(BLACK);
if(x==n)
{
settextstyle(1,0,2);
outtextxy(70,300,"No such movie found.");
}
fin.close();
fout.close();
remove("movie.dat");
rename("temp.dat" , "movie.dat");
}
getch();
clrscr();
updatemov();
}



void movieo::updatemov()
{
int ch5;
header();
setfillstyle(1,GREEN);
bar(80,130,540,340);

setfillstyle(7,RED);
bar(100,150,520,320);

setfillstyle(1,YELLOW);
bar(120,170,500,300);

setcolor(BLACK);
settextstyle(1,0,2);
outtextxy(130,170,"1.To add a movie.");
outtextxy(130,200,"2.To remove a movie.");
outtextxy(130,230,"3.Inbox.");
outtextxy(130,260,"4 To go back.");
setcolor(WHITE);
outtextxy(475,376,"Enter : ");
gotoxy(70,25);
cin>>ch5;
if(ch5==3)
inbox();
if(ch5==1)
{
outtextxy(17,405,"WAIT...");
delay(2000);
addmov();
}
if(ch5==2)
{
outtextxy(17,405,"WAIT...");
delay(2000);
removemov();
}
if(ch5==4)
{
outtextxy(17,405,"WAIT...");
delay(700);
adminmenu();
}
}



void movieo::addmov()
{
header();
setfillstyle(1,RED);
bar(30,200,200,225);//info
bar(30,232,200,257);//^
bar(30,264,200,289);// ^
bar(30,296,200,321);//   ^
bar(30,360,200,385);
fstream fo("movie.dat", ios::binary | ios::in | ios::out | ios::app );
settextstyle(1,0,2);
setcolor(BLACK);
outtextxy(30,199,"Movie name :");
outtextxy(30,231,"Actors :");
outtextxy(30,263,"Date of release :");
outtextxy(30,295,"Description :");
outtextxy(30,360,"Rating :");
gotoxy(30,14);
gets(m.mname);
setfillstyle(1,GREEN);
bar(30,200,200,225);
outtextxy(30,199,"Movie name :");
gotoxy(30,16);
gets(m.actors);
setfillstyle(1,GREEN);
bar(30,232,200,257);
outtextxy(30,231,"Actors :");
gotoxy(30,18);
gets(m.date);
setfillstyle(1,GREEN);
bar(30,264,200,289);
outtextxy(30,263,"Date of release :");
gotoxy(30,20);
gets(m.desc);
setfillstyle(1,GREEN);
bar(30,296,200,321);
outtextxy(30,296,"Description :");
gotoxy(30,24);
cin>>m.rating;
setfillstyle(1,GREEN);
bar(30,360,200,385);
outtextxy(30,360,"Rating :");
fo.write((char *)&m , sizeof(m));
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(400,400,"Parsing information...");
delay(2000);
fo.close();
updatemov();
}



void movieo::displaymov()
{
int n=0;
header();
fstream fo("movie.dat",ios::binary | ios::in | ios::out );
setcolor(WHITE);
gotoxy(0,10);
cout<<"\n\n\n\n\n\n\n";
while(fo.read((char *)&m , sizeof(m)))
{
n++;
if(n==3)
{
n=1;
settextstyle(1,0,2);
outtextxy(300,405,"Press any key to go to next page.");
getch();
header();
gotoxy(0,10);
cout<<"\n\n\n\n\n\n\n";
}
cout<<"Movie details";
cout<<"\n";
cout<<"Movie name :    ";
puts(m.mname);
cout<<"Actors :    ";
puts(m.actors);
cout<<"Date of release:    ";
puts(m.date);
cout<<"Description:    ";
puts(m.desc);
cout<<"Rating:    ";
cout<<m.rating;
cout<<"\n\n\n\n";
}
fo.close();
getch();
setcolor(WHITE);//
settextstyle(1,0,2);
outtextxy(500,405,"WAIT...");
delay(1000);
adminmenu();
}




void movieo::displaycust()
{
int n=0;
header();
fstream f("customer.dat",ios::binary | ios::in | ios::out );
setcolor(WHITE);
gotoxy(0,10);
cout<<"\n\n\n\n\n\n\n";
while(f.read((char *)&s , sizeof(s)))
{
n++;
if(n==4)
{
n=1;
outtextxy(300,405,"Press any key to go to next page.");
getch();
header();
gotoxy(0,10);
cout<<"\n\n\n\n\n\n\n";
}
cout<<"Customer details";
cout<<"\n\n";
cout<<"Name :    ";
cout<<s.name;
cout<<"\n";
cout<<"Address :    ";
cout<<s.address;
cout<<"\n";
cout<<"Email :    ";
cout<<s.email;
cout<<"\n\n";
}
f.close();
getch();
setcolor(WHITE);
outtextxy(17,405,"WAIT...");
delay(1000);
adminmenu();
}










