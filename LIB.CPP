#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
struct addr
{
	int hno;
	char hnam[30];
	char strt[30];
	char city[20];
	int pin;
};
struct date
{
	int day,mnt,yr;
	char mn[10];
}tdy;
class mbr
{
	long int mid;
	char nam[20];
	addr adr;
public:
	long int msrc(long int i)
	{
		if(i==mid)
			return mid;
		else
			return 0;
	}

};
class book
{
	long int bid;
	int no;
	int avail;
	int isd;
	long int mid[20];
	char name[30];
	char author[20];
	char isbn[13];
	public:
	void issue();
	void bsrc();
};

mbr mr[100];
int j;

int main()
{
	clrscr();
	int x=1;
	cout<<"Enter Today's Date(XX/XX/XX):";
	while(x==1)
	{
		cin>>tdy.day;
	}
	clrscr();
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "c:\\TurboC3\\bgi");
	gotoxy(20,3);
	cout<<"Girideepam Bethany Central School Library";
	gotoxy(16,4);
	cout<<"Bethany Hills, Vadavathoor P.O., Kottayam-686014";
	gotoxy(26,5);
	cout<<"New Member Application Form";
	gotoxy(14,2);
	cout<<"ÎÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
	for(int i=0;i<3;i++)
	{
		gotoxy(14,3+i);
		cout<<"º";
		gotoxy(65,3+i);
		cout<<"º";
	}
	gotoxy(14,6);
	cout<<"ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
	gotoxy(2,8);
	cout<<"Name:";
	gotoxy(7,7);
	cout<<"ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
	gotoxy(7,8);
	cout<<"³";
	gotoxy(49,8);
	cout<<"³";
	gotoxy(7,9);
	cout<<"ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
	gotoxy(2,11);
	cout<<"Address:";
	gotoxy(14,10);
	cout<<"ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
	gotoxy(14,11);
	cout<<"³";
	gotoxy(51,11);
	cout<<"³";
	gotoxy(14,12);
	cout<<"³";
	gotoxy(51,12);
	cout<<"³";
	gotoxy(14,13);
	cout<<"³";
	gotoxy(51,13);
	cout<<"³";
	gotoxy(14,14);
	cout<<"³";
	gotoxy(51,14);
	cout<<"³";
	gotoxy(14,15);
	cout<<"ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
	gotoxy(2,17);
	cout<<"Phone Number : +91XXXXXXXXXX";
	gotoxy(48,20);
	cout<<"Library Seal:";
	gotoxy(48,22);
	cout<<"Date:";

	getch();
	circle(523, 327, 42);
	circle(523, 327, 30);
	gotoxy(63,21);
	cout<<"Library";
	gotoxy(53,22);
	cout<<tdy.day<<" "<<tdy.mnt<<" "<<tdy.yr;
	getch();
	closegraph();
	return 0;
}
void book::issue()
{
	long int mid;
	cout<<"Enter Member ID";
	for(long int i=10000000;i<99999999;)
	{
	    mid=mr[j].msrc(i);
	    if(mid!=0)
		break;
	}


}
