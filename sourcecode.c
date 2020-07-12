#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
union REGS i,o;
void login_window();
void password_input();
void wgeneral(int jyr,char uorg,char grp);
void wstaff();
void wstud();
void passdetect(char *);
void drawmenu(char menu[6][20],int);
void clrwin(int opt);
void getmousepos(int *buttonm,int *xm, int *ym);
void restrictmouse(int x1,int y1,int x2,int y2);
void showmouse();
int initmouse();
void setmousepos(int xpos,int ypos);
void hidemouse();

int buttonm,xm,ym,gd=9,gm=1,close=1,set=1,midx,midy;


struct faculty
{
	int year,grp;
	char co1[3],co2[3],co3[3],co4[3],co5[3],co6[3];

	char fco1[30],fco2[30],fco3[30],fco4[30],fco5[30],fco6[30];
	char c_co1[100],c_co2[100],c_co3[100],c_co4[100],c_co5[100],c_co6[100];
};

struct studentd
{
	int jyear,cyear,sem;
	char rollno[8];
	float caco1[3],caco2[3],caco3[3],caco4[3],caco5[3],caco6[3];
	float sco1[3],sco2[3],sco3[3],sco4[3],sco5[3],sco6[3];
};

struct gpass
{
	char pass[10];
	int year;
}S;

void main()
{
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"C:\\turboc3\\bgi");

	//login_window();
	//password_input();
	 initmouse();
	 showmouse();
	wgeneral(19,'u','1');
	getch();

	closegraph();

}

int initmouse(){
 i.x.ax=0;//for  initialising mouse.
 int86(0x33,&i,&o);
 return (o.x.ax);
}

void showmouse(){
 i.x.ax=1; // for displaying mouse pointer.
 int86(0x33,&i,&o);
}
void hidemouse(){
 i.x.ax=2;
 int86(0x33,&i,&o);
}

void setmousepos(int xpos,int ypos)
{
 i.x.ax=4;
 i.x.cx=xpos;
 i.x.dx=ypos;
 int86(0x33,&i,&o);
}

void restrictmouse(int x1,int y1,int x2,int y2){
 i.x.ax=7;     //to define the upper left boundry of mouse.
 i.x.cx=x1;
 i.x.dx=x2;
 int86(0x33,&i,&o);
 i.x.ax=8;   //to define the bottom right boundry of mouse.
 i.x.cx=y1;
 i.x.dx=y2;
 int86(0x33,&i,&o);
}

void getmousepos(int *buttonm,int *x, int *y){
 i.x.ax=3; //to move mouse.
 int86(0x33,&i,&o);
 *buttonm=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
}
//end mouse function


void login_window()
{
	//password input box

	setcolor(3);
	setfillstyle(1,WHITE);
	rectangle(426,288,201,259);
	rectangle(425,287,202,260);
	floodfill(419,262,3);

	//logo box
	setcolor(WHITE);
	setfillstyle(10,4);
	rectangle(402,142,224,222);
	rectangle(403,141,223,223);
	rectangle(404,140,222,224);

    //first body
    setcolor(WHITE);
    setfillstyle(1,8);
    ellipse(273, 195, 0, 360,10, 18);
    ellipse(273, 195, 0, 360,11, 19);
    floodfill(273,196,WHITE);

    /* draws and fills 2nd body  */

    setfillstyle(1,8);
    ellipse(300, 195, 0, 360,10, 18);
    ellipse(300, 195, 0, 360,9, 17);
    floodfill(301,196,WHITE);

    /* draws 3rd body */

      setfillstyle(1,8);
      ellipse(320, 200, 0, 360,8, 12);
      ellipse(320, 200, 0, 360,7, 11);
      floodfill(321,201,WHITE);



    /* draw 4th body */

    setfillstyle(1,8);
    ellipse(342, 190, 0, 360,11, 23);
    ellipse(342, 190, 0, 360,10, 22);
    floodfill(343,191,WHITE);

    /* draws head for 1st body */

    setcolor(WHITE);
    setfillstyle(1,8);
    circle(273,160,9);
    circle(273,160,8);
    floodfill(271,153,WHITE);

   /* draws head for 2nd body */

    setcolor(WHITE);
    setfillstyle(1,8);
    circle(300,160,9);
    circle(300,160,8);
    floodfill(301,161,WHITE);

   /* draws a head for 3rd body */

     setcolor(WHITE);
     setfillstyle(1,8);
     circle(320,180,5);
     circle(320,180,4);
     floodfill(321,181,WHITE);

   /* draws head for 4th body */

    setcolor(WHITE);
    setfillstyle(1,8);
    circle(342,154,9);
    circle(342,154,8);
    floodfill(343,153,WHITE);

    gotoxy(23,16);
    printf("STUDENT DATABASE MANAGEMENT SYSTEM !");

    /* following coad is to draw the circle Enter Button */

    setcolor(WHITE);
    setfillstyle(1,4);
    circle(444,272,13);
    circle(444,272,12);
    circle(444,272,11);
    floodfill(438,272,WHITE);
    outtextxy(438,269,"-");
    setcolor(WHITE);
    circle(444,272,10);

    //x section
    setbkcolor(0);
    gotoxy(15,15);
    setcolor(WHITE);
    settextstyle(1,0,1);
    outtextxy(512,98,"x");

    //outer box
     setcolor(WHITE);
     rectangle(500,120,130,300);
     rectangle(502,118,132,298);

     //outer box styling
     setcolor(WHITE);
     setfillstyle(1,3);
     rectangle(534,90,100,326);
     floodfill(533,91,WHITE);

     //window box

     setcolor(8);
     setfillstyle(7,8);
    rectangle(535,89,99,327);
    rectangle(536,88,98,328);
    rectangle(537,87,97,329);
    rectangle(538,86,96,330);
    rectangle(539,85,95,331);
    rectangle(540,84,94,332);
    rectangle(541,83,93,333);
    rectangle(542,82,92,334);
    rectangle(542,81,91,335);
    floodfill(0,0,8);
}


  void password_input()
  {
  int X=206,Y=262;
  char password[10];
  char pass[12]="minions";
  int i;
  char ch;
  for(i=0;i<12;i++)
  {
  ch=getch();
  password[i]=ch;
  if(ch==13)
  {
    password[i]='\0';

	for(i=0;i<10;i++)
    {
    sound(99*i);
    //button pressing
    setcolor(WHITE);
    setfillstyle(1,12);
    circle(444,272,12);
    circle(444,272,11);
    circle(444,272,13);
    floodfill(444,272,WHITE);
    delay(19);
    setcolor(WHITE);
    setfillstyle(1,4);
    circle(444,272,12);
    circle(444,272,11);
    circle(444,272,13);
    floodfill(444,272,WHITE);
    nosound();

    }
     sleep(1);

    //passdetect(password);
 }
   //BACKSPACE LOOP
  }
    if(ch==8)
    {
    i--;
    i--;
    X=X-15;
    fflush(stdin);

    if(X<206)
   {
    X=206;
    }

    setcolor(15);
    settextstyle(2,0,7);
    outtextxy(X,Y,"*");
    X=X-15;
    nosound();

    }

    //ESCAPE LOOP

    if(ch==27)
    exit();

    if(i>10)
    {
     sound(9999);

     }

    sound(800);
    setcolor(0);
    settextstyle(2,0,7);
    outtextxy(X,Y,"*");

    X=X+15;
    delay(100);
    nosound();

   }



/*

void passdetect(char *pass)
{
		struct gpass S;
	FILE *gp;
	gp=fopen("gpass.DAT","r");


	if(isalpha(pass[0]))
	{
		while(fread(&S,sizeof(S),1,gp)==1)
		{
			if(strcmp(pass,S.pass)==0)
			{
				wgeneral(S.year,pass[3],pass[6]);
				break;
			}
		}
	}
	else
	{
			int x,grp,flag=0,i,j,course;
		char ch[2],uni[4],u_g,filename[10];
		ch[0]=pass[0];
		ch[1]=pass[1];
		ch[2]='\n';

		sscanf(ch,"%d",&x);
		rewind(gp);
		while(fread(&S,sizeof(S),1,gp)==1)
		{
			if(x==S.year)
			{
				if(pass[2]=='u'||pass[2]=='p')
				{
					u_g=pass[2];
					if(pass[3]=='f')
					{
						struct faculty f;
						FILE *fp;
						fp=fopen("fpass.DAT","r");
						while(fread(&f,sizeof(f),1,fp)==1)
						{
							if(x==f.year)
							{
								if(pass[4]=='1' || pass[4]=='2')
								{
									if(pass[4]=='1')
									{
										grp=1;
									}
									else
									{
										grp=2;
									}
								}else{break;flag=1;}
								for(i=0,j=5;pass[j]!='\0';i++,j++)
								{
									uni[i]=pass[j];
								}
								if(strcmp(uni,f.co1)==0)
								{
									course=1;
								}
								else if(strcmp(uni,f.co2)==0)
								{
									course=2;
								}
								else if(strcmp(uni,f.co3)==0)
								{
									course=3;
								}
								else if(strcmp(uni,f.co4)==0)
								{
									course=4;
								}
								else if(strcmp(uni,f.co5)==0)
								{
									course=5;
								}
								else if(strcmp(uni,f.co6)==0)
								{
									course=6;
								}
								else{
									break;flag=1;
								}
							}else{break;flag=1;}
						}
					//call the fuction to enter faculty zone;














					}
					else if(pass[3]=='s')
					{
						struct studentd f;
						FILE *sp;

								if(pass[4]=='1' || pass[4]=='2')
								{
									for(i=0;i<5;i++)
									{
										filename[i]=pass[i];
									}
									strcat(filename,".DAT");
									sp=fopen(filename,"r");
									while(fread(&f,sizeof(f),1,sp)==1)
									{
										if(strcmp(f.rollno,pass)==0)
										{
											//call student function
										}
									}

								}
					}

				}
			}
		}
	}
}*/
void drawmenu(char menu[6][20],int select)
{

 char ch;
 char date[11];
 struct date da;
 int menu1;

 clrscr();
  _setcursortype(0);
  initgraph(&gd,&gm,"..\\BGI");

  midx=getmaxx()/2;
  midy=getmaxy()/2;
  setfillstyle(1,BLUE);
 bar(0,0,getmaxx(),getmaxy());
 setcolor(3);
 settextstyle(2,0,5);

 outtextxy(midx-130,0,"====Student Data Management System ====");

 hidemouse();
 clrwin(1);
 settextstyle(0,0,0);
 setfillstyle(1,3);
 setcolor(15);
 line(9,17,631,17);
 line(9,17,9,32);
 setcolor(0);
 line(631,18,631,32);
 bar(10,18,630,32);
 getdate(&da);
 setcolor(0);
 outtextxy(617,21,menu[0]);
 outtextxy(20,21,menu[1]);
 outtextxy(65,21,menu[2]);
 outtextxy(120,21,menu[3]);
 outtextxy(190,21,menu[4]);
 outtextxy(260,21,menu[5]);
 showmouse();
 switch(select){
   case 0: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(613,18,625,18);
    line(613,18,613,31);
    setcolor(15);
    line(625,18,625,32);
    line(613,32,625,32);
    bar(612,19,624,31);
    outtextxy(617,21,menu[0]);
    break;
   case 1: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(15,18,15,31);
    line(15,18,50,18);
    setcolor(15);
    line(50,18,50,32);
    line(15,32,50,32);
    bar(16,19,49,31);
    outtextxy(20,21,menu[1]);
    break;
   case 2: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(60,18,80,18);
    line(60,18,60,32);
    setcolor(15);
    line(80,18,80,31);
    line(60,32,80,32);
    bar(61,19,79,31);
    outtextxy(63,21,menu[2]);
    break;
   case 3: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(115,18,160,18);
    line(115,18,115,32);
    setcolor(15);
    line(160,18,160,31);
    line(115,32,160,32);
    bar(116,19,159,31);
    outtextxy(120,21,menu[3]);
    break;
   case 4: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(220,18,279,18);
    line(220,18,220,32);
    setcolor(15);
    line(221,32,279,32);
    line(280,18,280,32);
    bar(221,19,279,31);
    outtextxy(230,21,menu[4]);
    break;
	case 5: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(220,18,279,18);
    line(220,18,220,32);
    setcolor(15);
    line(221,32,279,32);
    line(280,18,280,32);
    bar(221,19,279,31);
    outtextxy(230,21,menu[4]);
    break;
  }
  sprintf(date,"%02d/%02d/%d",da.da_day,da.da_mon,da.da_year);
  setcolor(0);
  outtextxy(550,5,date);
  showmouse();
 return select;


}

void clrwin(int opt)
{


 hidemouse();
 setcolor(0);
 line(9,33,631,33);
 line(9,34,9,340);
 setcolor(15);
 line(631,34,631,339);
 line(10,340,631,340);
 setfillstyle(1,11);
 bar(10,34,630,339);
 showmouse();
}



void wgeneral(int jyr,char uorg,char grp)
{
	int menu1=-1;
	char menu[6][20]={"x","ADD","LIST","SEARCH","MODIFY","CALENDER"};
	_setcursortype(0);
 initgraph(&gd,&gm,"..\\BGI");
 

 midx=getmaxx()/2;
 midy=getmaxy()/2;
 clrscr();
 clrwin(2);
 restrictmouse(10,18,getmaxx()-10,getmaxy()-10);
 setmousepos(midx,midy);
 showmouse();
 getmousepos(&buttonm,&xm,&ym);
 drawmenu(menu,menu1);
 while(1){
  showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(buttonm==1){
   if(xm>=613&&xm<=620&&ym>=18&&ym<=32){
    menu1=0;
   }else if(xm>=15&&xm<=30&&ym>=18&&ym<=32){
     menu1=1;
   }else if(xm>=60&&xm<=80&&ym>=18&&ym<=32){
     menu1=2;
   }else if(xm>=170&&xm<=219&&ym>=18&&ym<=32){
     menu1=3;
   }else if(xm>=220&&xm<=269&&ym>=18&&ym<=32){
     menu1=4;
   }else if(xm>=220&&xm<=269&&ym>=18&&ym<=32){
     menu1=5;
   }else menu1=-1;
   clrwin(1);
   drawmenu(menu,menu1);
  /* switch(menu1){
    case 0:program();break;
    case 1:doctor();break;
    case 2:patient();break;
    case 3:rooms();break;
    case 4:about();break;
   }*/
  }
 }
  

}
