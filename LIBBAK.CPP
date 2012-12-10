#include<iostream.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>

class MENU
{
   public :
	void main_menu(void);
	void specs(void);
	void splash(void);
   private :
	void edit_menu(void);
	void edit_book(void);
	void edit_member(void);
};

class BOOK
{
   public :
	void list(void);
	char *bookname(int);
   protected :
	void add_new_book(int, char tname[33], char tauthor[26], float, int, int);
	void update_copies(int, int, int);
	void modify(int, char[], char[], float);
	int  book_found(int);
	int  bookname_found(char []);
	int  recordno(int);
	int  available(int);
	char *authorname(int);
	float bookprice(int);
	int  no_of_copies(int);
	int  bookcodeof(char[]);
	void display(int);
	int  reccount(void);
	void delete_rec(int);
   private :
	int   bookcode, copies;
	char  name[33], author[26];
	float price;
	int   avail;

};


class MEMBER
{
public :
	void list(void);
protected :
	void add_mem(int, int, char [], char [], char[], int, int, int);
	void modify(int, char[], char[], char[]);
	int  member_found(int);
	void update_book(int, int, int, int, int);
	char *membername(int);
	char *memberphone(int);
	char *memberaddress(int);
	int  recordno(int);
	int  lastcode(void);
	int  issued(int);
	int  fine(int);
	void display(int);
	void delete_rec(int);
private :
	int  memcode, bookcode;
	char name[26], phone[10], address[33];
	int  dd, mm, yy;   // DATE OF RETURNING THE BOOK //
};

class WORKING : public BOOK, public MEMBER
{
public :
	void issuebook(void);
	void returnbook(void);
	void add_book(void);
	void add_member(void);
	void modify_book(void);
	void modify_member(void);
	void delete_book(void);
	void delete_member(void);
};

class DATE
{
public :
	void extend_date(int,int,int,int);
	int  diff(int, int, int, int, int, int);
	int  day, mon, year;
};


void DATE::extend_date(int d1, int m1, int y1, int days)
{
	static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
	for (int i=1; i<=days; i++)
	{
		d1++;
		if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
		{
			d1 = 1;
			m1++;
		}
		if (m1 > 12)
		{
			m1 = 1;
			y1++;
		}
	}
	day  = d1;
	mon  = m1;
	year = y1;
}


int DATE :: diff(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int days = 0;
	if ((y2<y1) || (y2==y1 && m2<m1) || (y2==y1 && m2==m1 && d2<d1))
		return days;
	static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
	while (d1 != d2 || m1 != m2 || y1 != y2)
	{
		days++;
		d1++;
		if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
		{
			d1 = 1;
			m1++;
		}
		if (m1 > 12)
		{
			m1 = 1;
			y1++;
		}
	}
	return days;
}


void MENU :: main_menu(void)
{
	WORKING W;
	MEMBER M;
	BOOK B;
	int i;
	while (1)
	{
		i=1;
		clrscr();
		gotoxy(5,i++);
		cprintf("               _______     ______      ______    __   ___                    ");
		gotoxy(5,i++);
		cprintf("              |   _  \"\\   /    \" \\    /    \" \\  |/\"| /  \")                   ");
		gotoxy(5,i++);
		cprintf("              (. |_)  :) // ____  \\  // ____  \\ (: |/   /                    ");
		gotoxy(5,i++);
		cprintf("              |:     \\/ /  /    ) :)/  /    ) :)|    __/                     ");
		gotoxy(5,i++);
		cprintf("              (|  _  \\\\(: (____/ //(: (____/ // (// _  \\                     ");
		gotoxy(5,i++);
		cprintf("              |: |_)  :)\\        /  \\        /  |: | \\  \\                    ");
		gotoxy(5,i++);
		cprintf("              (_______/  \\\"_____/    \\\"_____/   (__|  \\__)                   ");

		i+=2;
		gotoxy(5,i++);
		cprintf(" ___        __     _______    _______        __        _______   ___  ___  ");
		gotoxy(5,i++);
		cprintf("|\\\" |      |\" \\   |   _  \"\\  /\"      \\      /\"\"\\      /\"      \\ |\"  \\/\"  | ");
		gotoxy(5,i++);
		cprintf("||  |      ||  |  (. |_)  :)|:        |    /    \\    |:        | \\   \\  /  ");
		gotoxy(5,i++);
		cprintf("|:  |      |:  |  |:     \\/ |_____/   )   /' /\\  \\   |_____/   )  \\\\  \\/   ");
		gotoxy(5,i++);
		cprintf(" \\  |___   |.  |  (|  _  \\\\  //      /   //  __'  \\   //      /   /   /    ");
		gotoxy(5,i++);
		cprintf("( \\_|:  \\  /\\  |\\ |: |_)  :)|:  __   \\  /   /  \\\\  \\ |:  __   \\  /   /     ");
		gotoxy(5,i++);
		cprintf(" \\_______)(__\\_|_)(_______/ |__|  \\___)(___/    \\___)|__|  \\___)|___/      ");


		i+=6;

		gotoxy(15,i++);
		cprintf("  __  __       _         __  __                  ");
		gotoxy(15,i++);
		cprintf(" |  \\/  |     (_)       |  \\/  |                 ");
		gotoxy(15,i++);
		cprintf(" | \\  / | __ _ _ _ __   | \\  / | ___ _ __  _   _ ");
		gotoxy(15,i++);
		cprintf(" | |\\/| |/ _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |");
		gotoxy(15,i++);
		cprintf(" | |  | | (_| | | | | | | |  | |  __/ | | | |_| |");
		gotoxy(15,i++);
		cprintf(" |_|  |_|\\__,_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_|");



		i+=3;


		gotoxy(30,i++);
		cout <<"[1] Issue Book";
		i++;
		gotoxy(30,i++);
		cout <<"[2] Return Book";
		i++;
		gotoxy(30,i++);
		cout <<"[3] List Of Books";
		i++;
		gotoxy(30,i++);
		cout <<"[4] List Of Members";
		i++;
		gotoxy(30,i++);
		cout <<"[5] Add New Book";
		i++;
		gotoxy(30,i++);
		cout <<"[6] Add New Member";
		i++;
		gotoxy(30,i++);
		cout <<"[7] Edit Data";
		i++;
		gotoxy(30,i++);
		cout <<"[8] Specifications/Credits";
		i++;
		gotoxy(70,i+=2);
		cout <<"<0> QUIT";
		switch(getch())
		{
		case '8':
			specs();
			break;
		case '5':
			W.add_book();
			break;

		case '6':
			W.add_member();
			break;
		case '1':
			W.issuebook();
			break;
		case '2':
			W.returnbook();
			break;
		case '3':
			B.list();
			break;
		case '4':
			M.list();
			break;
		case '7':
			edit_menu();
			break;
		case '0':
			exit(1);
		}
	}
}


void MENU :: edit_menu(void)
{
	char ch;
	int i;
	while (1)
	{
		clrscr();
		i=6;
		gotoxy(30,i++);
		cout <<"ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ";
		gotoxy(30,i++);
		cout <<"Ý                  Þ";
		gotoxy(30,i++);
		cout <<"Ý E D I T  M E N U Þ";
		gotoxy(30,i++);
		cout <<"Ý                  Þ";
		gotoxy(30,i++);
		cout <<"ßßßßßßßßßßßßßßßßßßßß";
		i+=2;
		gotoxy(30,i++);
		cout <<"[1] Edit Book";
		i++;
		gotoxy(30,i++);
		cout <<"[2] Edit Member";
		i++;
		gotoxy(70,50);
		cout <<"<0> BACK";
		i++;
		gotoxy(34,i++);
		cout <<"Enter your choice : ";
		switch(getch())
		{
			case '1':
				edit_book();
				break;
			case '2':
				edit_member();
				break;
			case '0':
				ch='0';
				break;
		}
		if(ch=='0')
		break;
	}
}


void MENU :: edit_book(void)
{
	WORKING W;
	char ch;
	int i;
	while (1)
	{
		clrscr();
		i=6;
		gotoxy(30,i++);
		cout <<"ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ";
		gotoxy(30,i++);
		cout <<"Ý                  Þ";
		gotoxy(30,i++);
		cout <<"Ý E D I T  B O O K Þ";
		gotoxy(30,i++);
		cout <<"Ý                  Þ";
		gotoxy(30,i++);
		cout <<"ßßßßßßßßßßßßßßßßßßßß";
		i+=2;

		gotoxy(30,i++);
		cout <<"[1] Modify";
		i++;
		gotoxy(30,i++);
		cout <<"[2] Delete";
		i+=2;
		gotoxy(70,50);
		cout <<"<0> BACK";
		gotoxy(34,i++);
		cout <<"Enter your choice : ";
		switch(ch=getch())
		{
		case '1':
			W.modify_book();
			break;
		case '2':
			W.delete_book();
			break;
		}
		if (ch == '0')
		break;
	}
}


void MENU :: edit_member(void)
{
	WORKING W;
	char ch;
	int i;
	while (1)
	{
		clrscr();
		i=6;
		gotoxy(30,i++);
		cout <<"ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ";
		gotoxy(30,i++);
		cout <<"Ý                      Þ";
		gotoxy(30,i++);
		cout <<"Ý E D I T  M E M B E R Þ";
		gotoxy(30,i++);
		cout <<"Ý                      Þ";
		gotoxy(30,i++);
		cout <<"ßßßßßßßßßßßßßßßßßßßßßßßß";
		i+=2;
		gotoxy(30,i++);
		cout <<"[1] Modify";
		i++;
		gotoxy(30,i++);
		cout <<"[2] Delete";
		i+=2;
		gotoxy(70,50);
		cout <<"<0> BACK";
		gotoxy(34,i);
		cout <<"Enter your choice : ";
		switch(ch = getch())
		{
		case '1':
			W.modify_member();
			break;
		case '2':
			W.delete_member();
			break;
		}
		if (ch == '0')
			break;
	}
}


void MENU :: splash(void)
{
	int i,j,k,l;
	char ch='1';
	textmode(C4350);
	while(1)
	{
		i=10;
		j=5;
		clrscr();
		gotoxy(j+12,i++);
		cprintf(".____    ._____.                                                            ");
		gotoxy(j+12,i++);
		cprintf("|    |   |__\\_ |______________ _______ ___.__.                             ");
		gotoxy(j+12,i++);
		cprintf("|    |   |  || __ \\_  __ \\__  \\\\_  __ <   |  |                          ");
		gotoxy(j+12,i++);
		cprintf("|    |___|  || \\_\\ \\  | \\// __ \\|  | \\/\\___  |                       ");
		gotoxy(j+12,i++);
		cprintf("|_______ \\__||___  /__|  (____  /__|   / ____|                             ");
		gotoxy(j+12,i++);
		cprintf("        \\/       \\/           \\/       \\/                               ");
		gotoxy(j,i++);
		cprintf("   _____                                                             __     ");
		gotoxy(j,i++);
		cprintf("  /     \\ _____    ____ _____     ____   ____   _____   ____   _____/  |_   ");
		gotoxy(j,i++);
		cprintf(" /  \\ /  \\\\__  \\  /    \\\\__  \\   / ___\\_/ __ \\ /     \\_/ __ \\ /    \\   __\\  ");
		gotoxy(j,i++);
		cprintf("/    Y    \\/ __ \\|   |  \\/ __ \\_/ /_/  >  ___/|  Y Y  \\  ___/|   |  \\  |    ");
		gotoxy(j,i++);
		cprintf("\\____|__  (____  /___|  (____  /\\___  / \\___  >__|_|  /\\___  >___|  /__|    ");
		gotoxy(j,i++);
		cprintf("        \\/     \\/     \\/     \\//_____/      \\/      \\/     \\/     \\/        ");
		i++;
		gotoxy(j+8,i++);
		cprintf("	__________                                                                 ");
		gotoxy(j+8,i++);
		cprintf("\\______   \\_______  ____   ________________    _____                      ");
		gotoxy(j+8,i++);
		cprintf(" |     ___/\\_  __ \\/  _ \\ / ___\\_  __ \\__  \\  /     \\                ");
		gotoxy(j+8,i++);
		cprintf(" |    |     |  | \\(  <_> ) /_/  >  | \\// __ \\|  Y Y  \\                  ");
		gotoxy(j+8,i++);
		cprintf(" |____|     |__|   \\____/\\___  /|__|  (____  /__|_|  /                    ");
		gotoxy(j+8,i++);
		cprintf("                        /_____/            \\/      \\/                            ");
		i+=5;
		gotoxy(65,i++);
		cout<<"Initialising\n\n\n\n";
		gotoxy(5,0);
		cout<<"\tGigin C George, Chittu C Kuruvilla, Joel George Thomas, \n\n\t\tGokul R. Nair, Devasivan R";
		gotoxy(j+5,i++);
		switch(ch)
		{
			case '1':
				cout<<"Loading Databases";
				break;
			case '2':
				cout<<"Initializing Fonts";
				break;
			default:
			i=0;
			break;
		}
		if(i==0)
		break;
		for(k=0;k<10000;k++)
		for(l=0;l<1000;l++)
		if(k%1000==0&&l%1000==0)
		cout<<".";
		ch++;
	}

}
void MENU :: specs(void)
{
	clrscr();
	gotoxy(24,5);
	cout <<"C++ Project On : Library Management";
	gotoxy(16,10);
	cout <<"The Program built Strictly Using C++ Records Book and ";
	gotoxy(16,11);
	cout <<"Member Data for A Library, It also has features to ";
	gotoxy(16,12);
	cout <<"Calculate a Fine Of Rs.2/Day If the Member Doesn't";
	gotoxy(16,13);
	cout <<"Return The Book in 15 Days from The Day of Issue";
	int i=15;
	gotoxy(8,i++);
	cout<<"   _____              _ _ _       ";
	gotoxy(8,i++);
	cout<<"  / ____|            | (_| |      ";
	gotoxy(8,i++);
	cout<<" | |     _ __ ___  __| |_| |_ ___ ";
	gotoxy(8,i++);
	cout<<" | |    | '__/ _ \\/ _` | | __/ __|";
	gotoxy(8,i++);
	cout<<" | |____| | |  __| (_| | | |_\\__ \\";
	gotoxy(8,i++);
	cout<<"  \\_____|_|  \\___|\\__,_|_|\\__|___/";
	i+=5;
	gotoxy(20,i++);
	cout<<"Programming:";
	i++;
	gotoxy(25,i++);
	cout<<" Gigin C George";
	i++;
	gotoxy(25,i++);
	cout<<" Chittu C Kuruvilla";
	i++;
	gotoxy(25,i++);
	cout<<" Joel George Thomas";
	i++;
	gotoxy(25,i++);
	cout<<" Gokul R Nair";
	i++;
	gotoxy(25,i++);
	cout<<" Devasivan R";
	i+=2;
	gotoxy(20,i++);
	cout<<"Technical Support:";
	i++;
	gotoxy(20,i++);
	cout<<"(Our Most Sincere and Devoted Teachers)";
	i++;
	gotoxy(25,i++);
	cout<<"Mrs. Mini Shaji";
	i++;
	gotoxy(25,i++);
	cout<<"Mr. P. S. Jolly";
	i++;
	gotoxy(25,i++);
	cout<<"Mrs Sheela Lalu";
	gotoxy(70,50);
	cprintf("<0> BACK");
	getch();
}


int BOOK :: book_found(int tcode)
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	int found=0;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			found = 1;
			break;
		}
	}
	file.close();
	return found;
}


int BOOK :: bookname_found(char t1code[33])
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	int found=0;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (!strcmpi(name,t1code))
		{
			found = 1;
			break;
		}
	}
	file.close();
	return found;
}


int BOOK :: recordno(int tcode)
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	int count=0;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		count++;
		if (bookcode == tcode)
		break;
	}
	file.close();
	return count;
}


int BOOK :: available(int tcode)
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	int tavail=0;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			tavail = avail;
			break;
		}
	}
	file.close();
	return tavail;
}


int BOOK :: no_of_copies(int tcode)
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	int tcopies=0;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			tcopies = copies;
			break;
		}
	}
	file.close();
	return tcopies;
}


char *BOOK :: bookname(int tcode)
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	char tname[33];
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			strcpy(tname,name);
			break;
		}
	}
	file.close();
	return tname;
}


char *BOOK :: authorname(int tcode)
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	char tauthor[26];
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			strcpy(tauthor,author);
			break;
		}
	}
	file.close();
	return tauthor;
}


float BOOK :: bookprice(int tcode)
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	float tprice=0.0;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			tprice = price;
			break;
		}
	}
	file.close();
	return tprice;
}


int BOOK :: bookcodeof(char t1code[33])
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	int tcode=0;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (!strcmpi(name,t1code))
		{
			tcode = bookcode;
			break;
		}
	}
	file.close();
	return tcode;
}


int BOOK :: reccount(void)
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	int count=0;
	while (file.read((char *) this, sizeof(BOOK)))
	count++;
	file.close();
	return count;
}


void BOOK :: delete_rec(int tcode)
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	fstream temp;
	temp.open("temp.dat", ios::out);
	file.seekg(0,ios::beg);
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(BOOK));
		if ( file.eof() )
		break;
		if ( bookcode != tcode )
		temp.write((char *) this, sizeof(BOOK));
	}
	file.close();
	temp.close();
	file.open("BOOK.DAT", ios::out);
	temp.open("temp.dat", ios::in);
	temp.seekg(0,ios::beg);
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(BOOK));
		if ( temp.eof() )
		break;
		file.write((char *) this, sizeof(BOOK));
	}
	file.close();
	temp.close();
}

void BOOK :: add_new_book(int tcode,char tname[33], char tauthor[26], float tprice, int tcopies, int tavail)
{
	fstream file;
	file.open("BOOK.DAT", ios::app);
	bookcode = tcode;
	strcpy(name,tname);
	strcpy(author,tauthor);
	price = tprice;
	copies = tcopies;
	avail = tavail;
	file.write((char *) this, sizeof(BOOK));
	file.close();
}


void BOOK :: update_copies(int tcode, int tcopies, int tavail)
{
	int recno;
	recno = recordno(tcode);
	fstream file;
	file.open("BOOK.DAT", ios::out | ios::ate);
	copies = tcopies;
	avail = tavail;
	int location;
	location = (recno-1) * sizeof(BOOK);
	file.seekp(location);
	file.write((char *) this, sizeof(BOOK));
	file.close();
}


void BOOK :: modify(int tcode, char tname[33], char tauthor[26], float tprice)
{
	int recno;
	recno = recordno(tcode);
	fstream file;
	file.open("BOOK.DAT", ios::out | ios::ate);
	strcpy(name,tname);
	strcpy(author,tauthor);
	price = tprice;
	int location;
	location = (recno-1) * sizeof(BOOK);
	file.seekp(location);
	file.write((char *) this, sizeof(BOOK));
	file.close();
}


void BOOK :: display(int tcode)
{
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			gotoxy(5,5);
			cout <<"Book Code   : " <<bookcode;
			gotoxy(5,7);
			cout <<"Book Name   : " <<name;
			gotoxy(5,8);
			cout <<"Author Name : " <<author;
			gotoxy(5,9);
			cout <<"Price       : Rs." <<price;
			gotoxy(5,10);
			cout <<"Copies      : " <<price;
			gotoxy(5,11);
			cout <<"Available   : " <<avail;
			break;
		}
	}
	file.close();
}


void BOOK :: list(void)
{
	clrscr();
	int row = 6 , found=0, flag=0;
	char ch;
	gotoxy(33,2);
	cout <<"LIST OF BOOKS";
	gotoxy(32,3);
	cout <<"~~~~~~~~~~~~~~~";
	gotoxy(1,4);
	cout <<"CODE  BOOK NAME                        AUTHOR                    PRICE  COPIES";
	gotoxy(1,5);
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	fstream file;
	file.open("BOOK.DAT", ios::in);
	file.seekg(0,ios::beg);
	while (file.read((char *) this, sizeof(BOOK)))
	{
		flag = 0;
		delay(20);
		found = 1;
		gotoxy(2,row);
		cout <<bookcode;
		gotoxy(7,row);
		cout<<name;
		gotoxy(40,row);
		cout    <<author;
		gotoxy(66,row);
		cout    <<price;
		gotoxy(73,row);
		cout <<copies;
		textbackground(WHITE); textcolor(BLACK);
		gotoxy(40,row+1);
		cprintf("STATUS: ");
		textcolor(BLACK+BLINK);
		cprintf("%d copies available",avail);
		textbackground(BLACK); textcolor(LIGHTGRAY);
		if ( row == 22 )
		{
			flag = 1;
			row = 6;
			gotoxy(1,25);
			cout <<"Press any key to continue or Press <ESC> to exit";
			ch = getch();
			if (ch == 27)
			break;
			clrscr();
			gotoxy(33,2);
			cout <<"LIST OF BOOKS";
			gotoxy(32,3);
			cout <<"~~~~~~~~~~~~~~~";
			gotoxy(1,4);
			cout <<"CODE  BOOK NAME                        AUTHOR                    PRICE  COPIES";
			gotoxy(1,5);
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		}
		else
		row = row + 2;
	}
	if (!found)
	{
		gotoxy(5,10);
		cout <<"\7Records not found";
	}
	if (!flag)
	{
		gotoxy(1,25);
		cout <<"Press any key to continue:";
		getche();
	}
	file.close ();
}


int MEMBER :: member_found(int mcode)
{
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	file.seekg(0,ios::beg);
	int found=0;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			found = 1;
			break;
		}
	}
	file.close();
	return found;
}


int MEMBER :: issued(int mcode)
{
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	file.seekg(0,ios::beg);
	int missue=0;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			missue = bookcode;
			break;
		}
	}
	file.close();
	return missue;
}


int MEMBER :: fine(int mcode)
{
	DATE D;
	int d1, m1, y1;
	struct date d;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	file.seekg(0,ios::beg);
	int days, t_fine;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			days = D.diff(dd,mm,yy,d1,m1,y1);
			t_fine = days * 2;
			break;
		}
	}
	file.close();
	return t_fine;
}


int MEMBER :: lastcode(void)
{
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	file.seekg(0,ios::beg);
	int mcode=0;
	while (file.read((char *) this, sizeof(MEMBER)))
	mcode = memcode;
	file.close();
	return mcode;
}


char *MEMBER :: membername(int mcode)
{
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	file.seekg(0,ios::beg);
	char mname[26];
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			strcpy(mname,name);
			break;
		}
	}
	file.close();
	return mname;
}


char *MEMBER :: memberphone(int mcode)
{
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	file.seekg(0,ios::beg);
	char mphone[10];
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			strcpy(mphone,phone);
			break;
		}
	}
	file.close();
	return mphone;
}


char *MEMBER :: memberaddress(int mcode)
{
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	file.seekg(0,ios::beg);
	char maddress[33];
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			strcpy(maddress,address);
			break;
		}
	}
	file.close();
	return maddress;
}


int MEMBER :: recordno(int mcode)
{
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	file.seekg(0,ios::beg);
	int count=0;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		count++;
		if (memcode == mcode)
		break;
	}
	file.close();
	return count;
}


void MEMBER :: delete_rec(int mcode)
{
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	fstream temp;
	temp.open("temp.dat", ios::out);
	file.seekg(0,ios::beg);
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(MEMBER));
		if ( file.eof() )
		break;
		if ( memcode != mcode )
		temp.write((char *) this, sizeof(MEMBER));
	}
	file.close();
	temp.close();
	file.open("MEMBER.DAT", ios::out);
	temp.open("temp.dat", ios::in);
	temp.seekg(0,ios::beg);
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(MEMBER));
		if ( temp.eof() )
		break;
		file.write((char *) this, sizeof(MEMBER));
	}
	file.close();
	temp.close();
}


void MEMBER :: update_book(int mcode, int tcode, int d1, int m1, int y1)
{
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	fstream temp;
	temp.open("temp.dat", ios::out);
	file.seekg(0,ios::beg);
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(MEMBER));
		if ( file.eof() )
		break;
		if ( memcode == mcode )
		{
			bookcode = tcode;
			dd = d1;
			mm = m1;
			yy = y1;
			temp.write((char *) this, sizeof(MEMBER));
		}
		else
		temp.write((char *) this, sizeof(MEMBER));
	}
	file.close();
	temp.close();
	file.open("MEMBER.DAT", ios::out);
	temp.open("temp.dat", ios::in);
	temp.seekg(0,ios::beg);
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(MEMBER));
		if ( temp.eof() )
		break;
		file.write((char *) this, sizeof(MEMBER));
	}
	file.close();
	temp.close();
}


void MEMBER :: modify(int mcode, char mname[26], char mphone[10], char maddress[33])
{
	int recno;
	recno = recordno(mcode);
	fstream file;
	file.open("MEMBER.DAT", ios::out | ios::ate);
	strcpy(name,mname);
	strcpy(phone,mphone);
	strcpy(address,maddress);
	int location;
	location = (recno-1) * sizeof(MEMBER);
	file.seekp(location);
	file.write((char *) this, sizeof(MEMBER));
	file.close();
}


void MEMBER :: add_mem(int mcode, int bcode, char mname[26], char maddress[33], char mphone[10], int d1, int m1, int y1)
{
	fstream file;
	file.open("MEMBER.DAT", ios::app);
	memcode = mcode;
	bookcode = bcode;
	strcpy(name,mname);
	strcpy(address,maddress);
	strcpy(phone,mphone);
	dd = d1;
	mm = m1;
	yy = y1;
	file.write((char *) this, sizeof(MEMBER));
	file.close();
}


void MEMBER :: display(int mcode)
{
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	file.seekg(0,ios::beg);
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			gotoxy(5,3);
			cout <<"Member Code # " <<mcode;
			gotoxy(5,4);
			cout <<"~~~~~~~~~~~~~~~~~";
			gotoxy(5,6);
			cout <<"Name    : " <<name;
			gotoxy(5,7);
			cout <<"Phone   : " <<phone;
			gotoxy(5,8);
			cout <<"Address : " <<address;
			break;
		}
	}
	file.close();
}


void MEMBER :: list(void)
{
	clrscr();
	BOOK B;
	int row = 6 , found=0, flag=0;
	char ch;
	gotoxy(32,2);
	cout <<"LIST OF MEMBERS";
	gotoxy(31,3);
	cout <<"~~~~~~~~~~~~~~~~~";
	gotoxy(1,4);
	cout <<"CODE  BOOK CODE   NAME           PHONE        ADDRESS";
	gotoxy(1,5);
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	fstream file;
	file.open("MEMBER.DAT", ios::in);
	file.seekg(0,ios::beg);
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		flag = 0;
		delay(20);
		found = 1;
		gotoxy(2,row);
		cout <<memcode;
		gotoxy(10,row);
		cout <<bookcode;
		gotoxy(19,row);
		cout <<name;
		gotoxy(38,row);
		cout <<phone;
		gotoxy(50,row);
		cout<<address;
		textbackground(WHITE); textcolor(BLACK);
		gotoxy(7,row+1);
		if (bookcode == 0)
		cprintf("BOOK NAME: (Not Issued)");
		else
		{
			cprintf("BOOK NAME: %s",B.bookname(bookcode));
			gotoxy(42,row+1);
			cprintf("Date of return: ");
			textcolor(BLACK+BLINK);
			cprintf("%d/%d/%d",dd,mm,yy);
		}
		textbackground(BLACK); textcolor(LIGHTGRAY);
		if ( row == 22 )
		{
			flag = 1;
			row = 6;
			gotoxy(1,25);
			cout <<"Press any key to continue or Press <ESC> to exit";
			ch = getch();
			if (ch == 27)
			break;
			clrscr();
			gotoxy(32,2);
			cout <<"LIST OF MEMBERS";
			gotoxy(31,3);
			cout <<"~~~~~~~~~~~~~~~~~";
			gotoxy(1,4);
			cout <<"CODE  BOOK CODE   NAME                         PHONE";
			gotoxy(1,5);
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		}
		else
		row = row + 2;
	}
	if (!found)
	{
		gotoxy(5,10);
		cout <<"\7Records not found";
	}
	if (!flag)
	{
		gotoxy(1,25);
		cout <<"Press any key to continue:";
		getche();
	}
	file.close ();
}


void WORKING :: add_book(void)
{
	if (!reccount())  // MEMBER FUNCTION OF BOOK
	{
		add_new_book(0,"null","null",0.0,0,0);
		BOOK::delete_rec(0);
	}
	char ch;
	int tcode, tcopies, tavail;
	char tname[33], tauthor[26];
	float tprice=0.0;
	do
	{
		int found=0, valid=0;
		int tc;
		float t2=0.0;
		char t[10], t1[10];
		clrscr();
		gotoxy(29,3);
		cout <<"ADDITION OF THE BOOKS";
		gotoxy(29,4);
		cout <<"~~~~~~~~~~~~~~~~~~~~~";
		gotoxy(72,1);
		cout <<"<0>=Exit";
		gotoxy(5,25);
		cout <<"Enter code no. of the book";
		gotoxy(5,5);
		cout <<"Code no. ";
		gets(t);
		tc = atoi(t);
		tcode = tc;
		if (tcode == 0)
		return;
		if (book_found(tcode))
		{
			found = 1;
			gotoxy(19,8);
			cout <<bookname(tcode);
			gotoxy(19,9);
			cout <<authorname(tcode);
			gotoxy(22,10);
			cout <<bookprice(tcode);
		}
		gotoxy(5,8);
		cout <<"Book Name   : ";
		gotoxy(5,9);
		cout <<"Author Name : ";
		gotoxy(5,10);
		cout <<"Price       : Rs.";
		gotoxy(5,12);
		cout <<"Copies      : ";
		valid = 0;
		while (!valid && !found)
		{
			valid = 1;
			gotoxy(5,25); clreol();
			cout <<"Enter the name of the book";
			gotoxy(19,8); clreol();
			gets(tname);
			strupr(tname);
			if (tname[0] == '0')
			return;
			if (strlen(tname) < 1 || strlen(tname) > 32)
			{
				valid = 0;
				gotoxy(5,25); clreol();
				cout <<"\7Enter correctly (Range: 1..32)";
				getch();
			}
		}
		valid = 0;
		while (!valid && !found)
		{
			valid = 1;
			gotoxy(5,25); clreol();
			cout <<"Enter the author's name of the book";
			gotoxy(19,9); clreol();
			gets(tauthor);
			strupr(tauthor);
			if (tauthor[0] == '0')
			return;
			if (strlen(tauthor) < 1 || strlen(tauthor) > 25)
			{
				valid = 0;
				gotoxy(5,25); clreol();
				cout <<"\7Enter correctly (Range: 1..25)";
				getch();
			}
		}
		valid = 0;
		while (!valid && !found)
		{
			valid = 1;
			gotoxy(5,25); clreol();
			cout <<"Enter the price of the book";
			gotoxy(22,10); clreol();
			gets(t1);
			t2 = atof(t1);
			tprice = t2;
			if (t1[0] == '0')
			return;
			if (tprice < 1 || tprice > 9999)
			{
				valid = 0;
				gotoxy(5,25); clreol();
				cout <<"\7Enter correctly";
				getch();
			}
		}
		valid = 0;
		while (!valid)
		{
			valid = 1;
			gotoxy(5,25); clreol();
			cout <<"Enter no. of copies of book to be added";
			gotoxy(19,12); clreol();
			gets(t);
			tc = atoi(t);
			tcopies = tc;
			if (t[0] == '0')
			return;
			if (tcopies < 1 || tcopies > 50)
			{
				valid = 0;
				gotoxy(5,25); clreol();
				cout <<"\7Enter correctly";
				getch();
			}
		}
		tavail = available(tcode) + tcopies;
		tcopies = no_of_copies(tcode) + tcopies;
		gotoxy(5,25); clreol();
		do
		{
			gotoxy(5,15); clreol();
			cout <<"Do you want to save (y/n) : ";
			ch = getche();
			ch = toupper(ch);
		} while (ch != 'Y' && ch != 'N');

		if (ch == 'Y')
		{
			if (found)
			update_copies(tcode,tcopies,tavail);
			else
			add_new_book(tcode,tname,tauthor,tprice,tcopies,tavail);
		}
		do
		{
			gotoxy(5,17); clreol();
			cout <<"Do you want to add more (y/n) : ";
			ch = getche();
			ch = toupper(ch);
		} while (ch != 'Y' && ch != 'N');
	} while (ch == 'Y');
}


void WORKING :: add_member(void)
{
	char ch;
	int mcode, bcode;
	char mname[26], mphone[10], maddress[33];
	int d1, m1, y1;
	mcode = lastcode();
	mcode++;
	do
	{
		int valid=0;
		clrscr();
		gotoxy(28,3);
		cout <<"ADDITION OF THE MEMBERS";
		gotoxy(28,4);
		cout <<"~~~~~~~~~~~~~~~~~~~~~~~";
		gotoxy(72,1);
		cout <<"<0>=Exit";
		gotoxy(5,7);
		cout <<"Member Code # " <<mcode;
		gotoxy(5,8);
		cout <<"~~~~~~~~~~~~~~~~~";
		gotoxy(5,10);
		cout <<"Name    : ";
		gotoxy(5,12);
		cout <<"Phone   : ";
		gotoxy(5,14);
		cout <<"Address : ";
		do
		{
			valid = 1;
			gotoxy(5,25); clreol();
			cout <<"Enter the name of the New Member";
			gotoxy(15,10); clreol();
			gets(mname);
			strupr(mname);
			if (mname[0] == '0')
			return;
			if (strlen(mname) < 1 || strlen(mname) > 25)
			{
				valid = 0;
				gotoxy(5,25); clreol();
				cout <<"\7Enter correctly (Range: 1..25)";
				getch();
			}
		} while (!valid);
		do
		{
			valid = 1;
			gotoxy(5,25); clreol();
			cout <<"Enter Phone no. of the Member or Press <ENTER> for none";
			gotoxy(15,12); clreol();
			gets(mphone);
			if (mphone[0] == '0')
			return;
			if ((strlen(mphone) < 7 && strlen(mphone) > 0) || (strlen(mphone) > 9))
			{
				valid = 0;
				gotoxy(5,25); clreol();
				cout <<"\7Enter correctly";
				getch();
			}
		} while (!valid);
		if (strlen(mphone) == 0)
		strcpy(mphone,"-");
		do
		{
			valid = 1;
			gotoxy(5,25); clreol();
			cout <<"Enter the address of the New Member";
			gotoxy(15,14); clreol();
			gets(maddress);
			strupr(maddress);
			if (maddress[0] == '0')
			return;
			if (strlen(maddress) < 1 || strlen(maddress) > 32)
			{
				valid = 0;
				gotoxy(5,25); clreol();
				cout <<"\7Enter correctly (Range: 1..32)";
				getch();
			}
		} while (!valid);
		gotoxy(5,25); clreol();
		do
		{
			gotoxy(5,17); clreol();
			cout <<"Do you want to save (y/n) : ";
			ch = getche();
			ch = toupper(ch);
			if (ch == '0')
			return;
		} while (ch != 'Y' && ch != 'N');
		if (ch == 'Y')
		{
			bcode = 0;
			d1 = 0;
			m1 = 0;
			y1 = 0;
			add_mem(mcode,bcode,mname,maddress,mphone,d1,m1,y1);
			mcode++;
		}
		do
		{
			gotoxy(5,19); clreol();
			cout <<"Do you want to add more (y/n) : ";
			ch = getche();
			ch = toupper(ch);
			if (ch == '0')
			return;
		} while (ch != 'Y' && ch != 'N');
	} while (ch == 'Y');
}


void WORKING :: issuebook(void)
{
	BOOK B;
	MEMBER M;
	DATE D;
	char t1code[33], ch;
	int t2code=0, tcode=0, mcode=0;
	int valid;
	int d1, m1, y1;
	struct date d;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	do
	{
		valid =1;
		while (1)
		{
			clrscr();
			gotoxy(5,2);
			cout <<"Date : " <<d1 <<"/" <<m1 <<"/" <<y1;
			gotoxy(72,1);
			cout <<"<0>=Exit";
			gotoxy(5,5);
			cout <<"Enter Code or Name of the Book to be issued";
			gotoxy(5,6);
			cout <<"                  or                       ";
			gotoxy(5,7);
			cout <<"Press <ENTER> for help  ";
			gets(t1code);
			if (t1code[0] == '0')
			return;
			if (strlen(t1code) == 0)
			B.list();
			else
			break;
		}
		t2code = atoi(t1code);
		tcode = t2code;
		if ((tcode == 0 && !bookname_found(t1code)) || (tcode != 0 && !book_found(tcode)))
		{
			valid = 0;
			gotoxy(5,10);
			cout <<"\7Record not found";
			gotoxy(5,11);
			cout <<"Press <ESC> to exit or any other key to continue:";
			ch = getch();
			if (ch == 27)
			return;
		}
	} while (!valid);
	if (tcode == 0)
	tcode = bookcodeof(t1code);
	if (!available(tcode))
	{
		gotoxy(5,10);
		cout <<"\7Sorry! Book (" <<bookname(tcode) <<") is not available";
		gotoxy(5,11);
		cout <<"Kindly issue any other Book";
		gotoxy(5,12);
		cout <<"See List of Books";
		getch();
		return;
	}
	do
	{
		valid = 1;
		while (1)
		{
			clrscr();
			gotoxy(72,1);
			cout <<"<0>=Exit";
			gotoxy(5,2);
			cout <<"Date : " <<d1 <<"/" <<m1 <<"/" <<y1;
			gotoxy(5,5);
			cout <<"Book Name: " <<bookname(tcode);
			gotoxy(5,7);
			cout <<"Enter Code no. of the Member";
			gotoxy(5,8);
			cout <<"            or              ";
			gotoxy(5,9);
			cout <<"Press <ENTER> for help  ";
			gets(t1code);
			if (t1code[0] == '0')
			return;
			if (strlen(t1code) == 0)
			M.list();
			else
			break;
		}
		t2code = atoi(t1code);
		mcode = t2code;
		if (mcode == 0)
		{
			valid = 0;
			gotoxy(5,25);
			cout <<"\7Enter Correctly";
			getch();
		}
		if (!member_found(mcode) && valid)
		{
			valid = 0;
			gotoxy(5,13);
			cout <<"\7Record not found";
			gotoxy(5,14);
			cout <<"Press <ESC> to exit or any other key to continue:";
			ch = getch();
			if (ch == 27)
			return;
		}
	} while (!valid);
	int tcopies, tavail;
	tcopies = no_of_copies(tcode);
	tavail  = available(tcode) - 1;
	update_copies(tcode,tcopies,tavail);
	D.extend_date(d1,m1,y1,15);
	d1 = D.day;
	m1 = D.mon;
	y1 = D.year;
	update_book(mcode,tcode,d1,m1,y1);  // member function of MEMBER
	gotoxy(5,13);
	cout <<"\7Book is issued to " <<membername(mcode);
	gotoxy(5,15);
	cout <<"Date of Return : " <<d1 <<"/" <<m1 <<"/" <<y1;
	getch();
}


void WORKING :: returnbook(void)
{
	MEMBER M;
	char t1code[5], ch;
	int t2code=0, mcode=0, valid;
	int d1, m1, y1;
	struct date d;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	do
	{
		valid = 1;
		while (1)
		{
			clrscr();
			gotoxy(72,1);
			cout <<"<0>=Exit";
			gotoxy(5,2);
			cout <<"Date : " <<d1 <<"/" <<m1 <<"/" <<y1;
			gotoxy(5,7);
			cout <<"Enter Code no. of the Member who wants to return book";
			gotoxy(5,8);
			cout <<"                        or              ";
			gotoxy(5,9);
			cout <<"Press <ENTER> for help  ";
			gets(t1code);
			if (t1code[0] == '0')
			return;
			if (strlen(t1code) == 0)
			M.list();
			else
			break;
		}
		t2code = atoi(t1code);
		mcode = t2code;
		if (mcode == 0)
		{
			valid = 0;
			gotoxy(5,25);
			cout <<"\7Enter Correctly";
			getch();
		}
		if (!member_found(mcode) && valid)
		{
			valid = 0;
			gotoxy(5,13);
			cout <<"\7Record not found";
			gotoxy(5,14);
			cout <<"Press <ESC> to exit or any other key to continue:";
			ch = getch();
			if (ch == 27)
			return;
		}
		if (!issued(mcode) && valid)
		{
			valid = 0;
			gotoxy(5,13);
			cout <<"\7Member have no book to return";
			gotoxy(5,14);
			cout <<"Press <ESC> to exit or any other key to continue:";
			ch = getch();
			if (ch == 27)
			return;
		}
	} while (!valid);
	int bcode, tcopies, tavail;
	bcode = issued(mcode);
	gotoxy(5,13);
	cout <<"Book Code : " <<bcode;
	gotoxy(5,14);
	cout <<"Book Name : " <<bookname(bcode);
	tcopies = no_of_copies(bcode);
	tavail = available(bcode) + 1;
	int f;
	f = fine(mcode);
	if (f != 0)
	{
		gotoxy(5,16);
		cout <<"You have to pay a fine of Rs." <<f;
		gotoxy(5,17);
		cout <<"Please do not delay the Return of Book again";
	}
	update_copies(bcode,tcopies,tavail);
	update_book(mcode,0,0,0,0);
	gotoxy(5,19);
	cout <<"\7Book has been returned";
	getch();
}


void WORKING :: modify_book(void)
{
	BOOK B;
	char t1code[5], tname[33], tauthor[26], *t1, ch;
	int t2code=0, tcode=0;
	float t2=0.0, tprice=0.0;
	int valid;
	do
	{
		valid = 1;
		while (1)
		{
			clrscr();
			gotoxy(72,1);
			cout <<"<0>=Exit";
			gotoxy(5,5);
			cout <<"Enter Code or Name of the Book to be modified";
			gotoxy(5,6);
			cout <<"                  or                       ";
			gotoxy(5,7);
			cout <<"Press <ENTER> for help  ";
			gets(t1code);
			if (t1code[0] == '0')
			return;
			if (strlen(t1code) == 0)
			B.list();
			else
			break;
		}
		t2code = atoi(t1code);
		tcode = t2code;
		if ((tcode == 0 && !bookname_found(t1code)) || (tcode != 0 && !book_found(tcode)))
		{
			valid = 0;
			gotoxy(5,10);
			cout <<"\7Record not found";
			gotoxy(5,11);
			cout <<"Press <ESC> to exit or any other key to continue:";
			ch = getch();
			if (ch == 27)
			return;
		}
	} while (!valid);
	if (tcode == 0)
	tcode = bookcodeof(t1code);
	clrscr();
	gotoxy(72,1);
	cout <<"<0>=Exit";
	BOOK::display(tcode);
	do
	{
		gotoxy(5,13); clreol();
		cout <<"Do you want to modify this record (y/n) : ";
		ch = getche();
		ch = toupper(ch);
		if (ch == '0')
		return;
	} while (ch != 'Y' && ch != 'N');
	if (ch == 'N')
	return;
	gotoxy(5,16);
	cout <<"Book Name   : ";
	gotoxy(5,17);
	cout <<"Author Name : ";
	gotoxy(5,18);
	cout <<"Price       : Rs.";
	do
	{
		valid = 1;
		gotoxy(5,25); clreol();
		cout <<"Enter the name of the book or <ENTER> for no change";
		gotoxy(19,16); clreol();
		gets(tname);
		strupr(tname);
		if (tname[0] == '0')
		return;
		if (strlen(tname) > 32)
		{
			valid = 0;
			gotoxy(5,25); clreol();
			cout <<"\7Enter correctly (Range: 1..32)";
			getch();
		}
	} while (!valid);
	if (strlen(tname) == 0)
	strcpy(tname,bookname(tcode));
	do
	{
		valid = 1;
		gotoxy(5,25); clreol();
		cout <<"Enter the author's name or <ENTER> for no change";
		gotoxy(19,17); clreol();
		gets(tauthor);
		strupr(tauthor);
		if (tauthor[0] == '0')
		return;
		if (strlen(tauthor) > 25)
		{
			valid = 0;
			gotoxy(5,25); clreol();
			cout <<"\7Enter correctly (Range: 1..25)";
			getch();
		}
	} while (!valid);
	if (strlen(tauthor) == 0)
	strcpy(tauthor,authorname(tcode));
	do
	{
		valid = 1;
		gotoxy(5,25); clreol();
		cout <<"Enter price or <ENTER> for no change";
		gotoxy(22,18); clreol();
		gets(t1);
		t2 = atof(t1);
		tprice = t2;
		if (t1[0] == '0')
		return;
		if (strlen(t1) == 0)
		break;
		if (tprice < 1 || tprice > 9999)
		{
			valid = 0;
			gotoxy(5,25); clreol();
			cout <<"\7Enter correctly";
			getch();
		}
	} while (!valid);
	if (strlen(t1) == 0)
	tprice = bookprice(tcode);
	gotoxy(5,25); clreol();
	do
	{
		gotoxy(5,20); clreol();
		cout <<"Do you want to save changes (y/n) : ";
		ch = getche();
		ch = toupper(ch);
		if (ch == '0')
		return;
	} while (ch != 'Y' && ch != 'N');
	if (ch == 'N')
	return;
	BOOK::modify(tcode,tname,tauthor,tprice);
	gotoxy(5,23);
	cout <<"\7Record Modified";
	getch();
}


void WORKING :: modify_member(void)
{
	MEMBER M;
	char m1code[10], mname[26], mphone[10], maddress[33], ch;
	int m2code=0, mcode=0;
	int valid;
	do
	{
		valid = 1;
		while (1)
		{
			clrscr();
			gotoxy(72,1);
			cout <<"<0>=Exit";
			gotoxy(5,7);
			cout <<"Enter Code no. of the Member to be Modify";
			gotoxy(5,8);
			cout <<"                        or              ";
			gotoxy(5,9);
			cout <<"Press <ENTER> for help  ";
			gets(m1code);
			m2code = atoi(m1code);
			mcode = m2code;
			if (m1code[0] == '0')
			return;
			if (strlen(m1code) == 0)
			M.list();
			else
			break;
		}
		if (mcode == 0)
		{
			valid = 0;
			gotoxy(5,25);
			cout <<"\7Enter Correctly";
			getch();
		}
		if (valid && !member_found(mcode))
		{
			valid = 0;
			gotoxy(5,13);
			cout <<"\7Record not found";
			gotoxy(5,14);
			cout <<"Press <ESC> to exit or any other key to continue:";
			ch = getch();
			if (ch == 27)
			return;
		}
	} while (!valid);
	clrscr();
	gotoxy(72,1);
	cout <<"<0>=Exit";
	MEMBER::display(mcode);
	do
	{
		gotoxy(5,10); clreol();
		cout <<"Do you want to modify this record (y/n) : ";
		ch = getche();
		ch = toupper(ch);
		if (ch == '0')
		return;
	} while (ch != 'Y' && ch != 'N');
	if (ch == 'N')
	return;
	gotoxy(5,13);
	cout <<"Name    : ";
	gotoxy(5,14);
	cout <<"Phone   : ";
	gotoxy(5,15);
	cout <<"Address : ";
	do
	{
		valid = 1;
		gotoxy(5,25); clreol();
		cout <<"Enter the name of the member or <ENTER> for no change";
		gotoxy(19,13); clreol();
		gets(mname);
		strupr(mname);
		if (mname[0] == '0')
		return;
		if (strlen(mname) > 25)
		{
			valid = 0;
			gotoxy(5,25); clreol();
			cout <<"\7Enter correctly (Range: 1..25)";
			getch();
		}
	} while (!valid);
	if (strlen(mname) == 0)
	strcpy(mname,membername(mcode));
	do
	{
		valid = 1;
		gotoxy(5,25); clreol();
		cout <<"Enter the Phone no. of Member or <ENTER> for no change";
		gotoxy(19,14); clreol();
		gets(mphone);
		if (mphone[0] == '0')
		return;
		if ((strlen(mphone) < 7 && strlen(mphone) > 0) || (strlen(mphone) > 9))
		{
			valid = 0;
			gotoxy(5,25); clreol();
			cout <<"\7Enter correctly";
			getch();
		}
	} while (!valid);
	if (strlen(mphone) == 0)
	strcpy(mphone,memberphone(mcode));
	do
	{
		valid = 1;
		gotoxy(5,25); clreol();
		cout <<"Enter the address of the member or <ENTER> for no change";
		gotoxy(19,15); clreol();
		gets(maddress);
		strupr(maddress);
		if (maddress[0] == '0')
		return;
		if (strlen(maddress) > 32)
		{
			valid = 0;
			gotoxy(5,25); clreol();
			cout <<"\7Enter correctly (Range: 1..32)";
			getch();
		}
	} while (!valid);
	if (strlen(maddress) == 0)
	strcpy(maddress,memberaddress(mcode));
	gotoxy(5,25); clreol();
	do
	{
		gotoxy(5,18); clreol();
		cout <<"Do you want to save changes (y/n) : ";
		ch = getche();
		ch = toupper(ch);
		if (ch == '0')
		return;
	} while (ch != 'Y' && ch != 'N');
	if (ch == 'N')
	return;
	MEMBER::modify(mcode,mname,mphone,maddress);
	gotoxy(5,23);
	cout <<"\7Record Modified";
	getch();
}


void WORKING :: delete_book(void)
{
	BOOK B;
	char t1code[5], tname[33], tauthor[26], ch;
	int t2code=0, tcode=0;
	int valid;
	do
	{
		valid = 1;
		while (1)
		{
			clrscr();
			gotoxy(72,1);
			cout <<"<0>=Exit";
			gotoxy(5,5);
			cout <<"Enter Code or Name of the Book to be Deleted";
			gotoxy(5,6);
			cout <<"                  or                       ";
			gotoxy(5,7);
			cout <<"Press <ENTER> for help  ";
			gets(t1code);
			if (t1code[0] == '0')
			return;
			if (strlen(t1code) == 0)
			B.list();
			else
			break;
		}
		t2code = atoi(t1code);
		tcode = t2code;
		if ((tcode == 0 && !bookname_found(t1code)) || (tcode != 0 && !book_found(tcode)))
		{
			valid = 0;
			gotoxy(5,10);
			cout <<"\7Record not found";
			gotoxy(5,11);
			cout <<"Press <ESC> to exit or any other key to continue:";
			ch = getch();
			if (ch == 27)
			return;
		}
	} while (!valid);
	if (tcode == 0)
	tcode = bookcodeof(t1code);
	clrscr();
	gotoxy(72,1);
	cout <<"<0>=Exit";
	BOOK::display(tcode);
	do
	{
		gotoxy(5,13); clreol();
		cout <<"Do you want to delete this record (y/n) : ";
		ch = getche();
		ch = toupper(ch);
		if (ch == '0')
		return;
	} while (ch != 'Y' && ch != 'N');
	if (ch == 'N')
	return;
	int tavail, tcopies;
	tavail = available(tcode);
	tcopies = no_of_copies(tcode);
	if (tavail != tcopies)
	{
		gotoxy(5,15);
		cout <<"\7Record cannot be deleted. This book is issued.";
		getch();
		return;
	}
	BOOK::delete_rec(tcode);
	gotoxy(5,23);
	cout <<"\7Record Deleted";
	getch();
}


void WORKING :: delete_member(void)
{
	MEMBER M;
	char m1code[5], mname[26], mphone[10], maddress[33], ch;
	int m2code=0, mcode=0;
	int valid;
	do
	{
		valid = 1;
		while (1)
		{
			clrscr();
			gotoxy(72,1);
			cout <<"<0>=Exit";
			gotoxy(5,7);
			cout <<"Enter Code no. of the Member to be Deleted";
			gotoxy(5,8);
			cout <<"                        or              ";
			gotoxy(5,9);
			cout <<"Press <ENTER> for help  ";
			gets(m1code);
			m2code = atoi(m1code);
			mcode = m2code;
			if (m1code[0] == '0')
			return;
			if (strlen(m1code) == 0)
			M.list();
			else
			break;
		}
		if (mcode == 0)
		{
			valid = 0;
			gotoxy(5,25);
			cout <<"\7Enter Correctly";
			getch();
		}
		if (valid && !member_found(mcode))
		{
			valid = 0;
			gotoxy(5,13);
			cout <<"\7Record not found";
			gotoxy(5,14);
			cout <<"Press <ESC> to exit or any other key to continue:";
			ch = getch();
			if (ch == 27)
			return;
		}
	} while (!valid);
	clrscr();
	gotoxy(72,1);
	cout <<"<0>=Exit";
	MEMBER::display(mcode);
	do
	{
		gotoxy(5,10); clreol();
		cout <<"Do you want to Delete this record (y/n) : ";
		ch = getche();
		ch = toupper(ch);
		if (ch == '0')
		return;
	} while (ch != 'Y' && ch != 'N');
	if (ch == 'N')
	return;
	if (issued(mcode))
	{
		gotoxy(5,15);
		cout <<"\7Record cannot be delete. Member has a book";
		getch();
		return;
	}
	MEMBER::delete_rec(mcode);
	gotoxy(5,23);
	cout <<"\7Record Modified";
	getch();
}


void main(void)
{
	MENU menu;
	menu.splash();
	menu.main_menu();
}

