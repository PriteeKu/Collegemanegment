#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<conio.h>
#include<iostream.h>
#include<ctype.h>
#include<stdlib.h>
class course
{
char ch;
struct entry
{
 char course_name[20],sname[20],fname[20],fo[20],add[50],dob[10],doe[10];
 int course_code,duration,roll,cnum;
 float fee;
 char qualification[30],sex;
 }p;
 fstream f;
public:
void sysdate();
int code();
void course_menu();
void add_course();
void modify_course();
void list_course();
void del_course();
};

class student:public course
{
private:
struct stu
{
char ch,sex,name[20],qualification[20],fname[20],fo[20],address[20],course[5],dob[10],doe[10];
int duration,roll,cnum;
}p;
fstream file;
public:
int code();
void student_menu();
void add_student();
void list_student();
void modify_student();
void full_student();
void del_student();
};

class fee:public student
{
private:
struct var
{
char ch,name[20],fname[20],address[20],course[5],dob[10];
int duration,roll,total_fee,paid_fee,dues_fee;
}f;
fstream file;
public:
int code();
void fee_menu();
void admission();
void received();
void modify_fee();
void list_fee();
void del_fee();
};

class exam:public fee
{
struct var
{
int duration,course_code;
char course_name[10],exam_term[10],exam_date[10];
}p;
fstream f;
public:
int code();
void examination();
void add_exam_term();
void list_exam_term();
void modify_exam_term();
void del_exam_term();
};

class emp:public exam
{
char ch;
struct entry
{
int e_no;
 char e_name[20],dob[10],city[10],dist[10],state[10],zip[5],desi[10],doj[10],dept[10],g;
double ta,da,hra,pf,tsal,bsal;
  }p;
 fstream f;
public:
int code();
void employee();
void employee_record();
void add_employee();
void modify_employee();
void list_employee();
void indi_employee();
void salary();
void salary_slip();
void change_salary();
void del_employee();
};
class library:public emp

{
char ch;
struct var
{
 int book_no,rno,price,page_no,mem_no,mem_fee;
 char class_name[20],mem_name[10],add[50],book_title[20],aname[20],pname[20];
 char bname[20],aurther[20],publisher[20],member_no[5],roll[5],clas[5];
 double bprice;
 int bno;
 }s;
 fstream file;
public:
int bcode();
int mcode();
void library_menu();
void book_record();
void book_issue_return();
void book_issue();
void book_return();
void list_issue_book();
void list_return_book();
void add_book();
void modify_book();
void list_book();
void delete_book();
void member_record();
void add_member();
void modify_member();
void list_member();
void delete_member();
int found(int);
};




//************************* course coading ********************************

  void course::sysdate()
 {
 date d;
getdate(&d);
int da=d.da_day;
int mo=d.da_mon;
int ye=d.da_year;
gotoxy(60,5);
cout<<"Date:";
cout<<da<<"/"<<mo<<"/"<<ye;
}

 void course::course_menu()
 {
 char ch;
 do
 {
clrscr();
gotoxy(16,2);
cout<<"COURSE MENU OF COLLEGE SYSTEM";
gotoxy(4,3);
cout<<"**********************************************************************";
sysdate();
gotoxy(20,6);
cout<<"1.ADD NEW COURSE";
gotoxy(20,8);
cout<<"2.LIST OF COURSE";
gotoxy(20,10);
cout<<"3.MODIFY COURSE";
gotoxy(20,12);
cout<<"4.DELETE COURSE";
gotoxy(4,16);
cout<<"**********************************************************************";
gotoxy(20,24);
cout<<"<0>FOR RETURN";
gotoxy(30,22);
cout<<"ENTER YOUR CHOICE:";
ch=getch();
switch(ch)
{
case '0':
{
break;
}
case '1':
add_course();
break;
case '2':
list_course();
break;
case '3':
modify_course();
break;
case '4':
del_course();
break;
}
}while(ch!='0');
}


int course::code()
{
int count=0;
f.open("course.dat",ios::in);
f.seekg(0L,ios::beg);
while(f.read((char *)&p,sizeof(p)))
{
count=p.course_code;
}

count++;
f.close();
return count;
}

void course::add_course()
{
do
{
clrscr();

gotoxy(16,2);
cout<<"ADD NEW COURSE";
gotoxy(4,3);
cout<<"*********************************************************************";
gotoxy(5,5);
cout<<"COURSE CODE:";
p.course_code=code();
cout<<p.course_code;
gotoxy(5,7);
cout<<"COURSE NAME:";
cin>>p.course_name;
gotoxy(5,9);
cout<<"DURATION:";
cin>>p.duration;
gotoxy(5,11);
cout<<"FEE:";
cin>>p.fee;
gotoxy(5,13);
cout<<"QUALIFICATION:";
cin>>p.qualification;
gotoxy(4,16);
cout<<"*********************************************************************";
f.open("course.dat",ios::app|ios::out);
f.seekp(0L,ios::end);
f.write((char *)&p,sizeof(p));
gotoxy(20,20);
cout<<"Add more(y/n):";
ch=getch();
f.close();
}while(ch=='y');
clrscr();
}

void course::modify_course()
{
int count=0;
int no;
long int pos;
clrscr();
f.open("course.dat",ios::in|ios::out);
f.seekg(0L,ios::beg);
gotoxy(16,2);
cout<<"MODIFY COURSE";
gotoxy(4,3);
cout<<"*********************************************************************";
gotoxy(5,5);
cout<<"COURSE CODE:";
cin>>no;
while(f.read((char *)&p,sizeof(p)))
{
if(no==p.course_code)
{
gotoxy(5,7);
cout<<"COURSE NAME:";
cin>>p.course_name;
gotoxy(5,9);
cout<<"DURATION:";
cin>>p.duration;
gotoxy(5,11);
cout<<"FEE:";
cin>>p.fee;
gotoxy(5,13);
cout<<"QUALIFICATION:";
cin>>p.qualification;
gotoxy(4,16);
cout<<"*********************************************************************";

pos=count*sizeof(p);
f.seekp(pos,ios::beg);
f.write((char*)&p,sizeof(p));
f.close();
}
count++;
}
}
void course::list_course()
{
int i=7;
clrscr();
gotoxy(16,2);
cout<<"LIST OF COURSE";
gotoxy(4,3);
cout<<"***********************************************************************";
gotoxy(5,5);
cout<<"COURSE CODE     COURSE NAME   DURATION(year)   QUALIFICATION     FEE";
gotoxy(4,6);
cout<<"***********************************************************************";
f.open("course.dat",ios::in);
f.seekg(0L,ios::beg);
while(f.read((char *)&p,sizeof(p)))
{
gotoxy(8,i);
cout<<p.course_code;
gotoxy(25,i);
cout<<p.course_name;
gotoxy(40,i);
cout<<p.duration;
gotoxy(55,i);
cout<<p.qualification;
gotoxy(70,i);
cout<<p.fee;
i++;
if(i==22)
{
i=9;
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
gotoxy(4,3);
cout<<"***********************************************************************";
gotoxy(5,5);
cout<<"COURSE CODE     COURSE NAME   DURATION(year)   QUALIFICATION     FEE";
gotoxy(4,6);
cout<<"***********************************************************************";
}
}
gotoxy(20,24);
cout<<"PRESS ANY KEY TO BACK";
f.close();
getch();
clrscr();
}

void course::del_course()
{
int no;
clrscr();
gotoxy(16,2);
cout<<"DELETE COURSE RECORD";
gotoxy(4,3);
cout<<"*********************************************************************";
fstream out;
gotoxy(5,5);
cout<<"COURSE CODE:-";
cin>>no;
gotoxy(15,24);
cout<<"DELETE(Y/N):-";
char c;
cin>>c;
if(c=='y')
{
	fstream temp;
	f.open("course.dat", ios::in);
	temp.open("TEMP.dat", ios::out);
	f.seekg(0, ios::beg);
	while (!f.eof())
	{
		f.read((char *)&p, sizeof(p));
		if (f.eof())
			break;
		if (p.course_code != no)
		{
			temp.write((char *)&p, sizeof(p));
		}
	}
	f.close();
	temp.close();
	f.open("course.dat", ios::out);
	temp.open("TEMP.dat", ios::in);
	temp.seekg(0, ios::beg);
	while (!temp.eof())
	{
		temp.read((char *)&p, sizeof(p));
		if (temp.eof())
			break;
		if (p.course_code!= no)
			f.write((char *)&p, sizeof(p));
	}
	f.close();
	temp.close();
gotoxy(15,25);
cout<<"record deleted:";
getch();
}
else
{
clrscr();
f.close();
}
clrscr();
course();
}






//*************************** student coading ***************************

 void student::student_menu()
 {
 char ch;
 do
 {
clrscr();
gotoxy(16,2);
cout<<"STUDENT MENU OF COLLEGE SYSTEM";
gotoxy(4,3);
cout<<"**********************************************************************";
sysdate();
gotoxy(20,6);
cout<<"1.ADD NEW STUDENT";
gotoxy(20,8);
cout<<"2.LIST OF STUDENT";
gotoxy(20,10);
cout<<"3.MODIFY STUDENT RECORD";
gotoxy(20,12);
cout<<"4.VIEW INDIVIDUAL STUDENT COURSE";
gotoxy(20,14);
cout<<"5.DELETE STUDENT RECORD";
gotoxy(4,18);
cout<<"**********************************************************************";
gotoxy(20,24);
cout<<"<0>FOR RETURN";
gotoxy(30,22);
cout<<"ENTER YOUR CHOICE:";

ch=getch();
switch(ch)
{
case '0':
break;
case '1':
add_student();
break;
case '2':
list_student();
break;
case '3':
modify_student();
break;
case '4':
full_student();
break;
case '5':
del_student();
break;
}
}while(ch!='0');
}

int student::code()
{
int count=0;
file.open("student.dat",ios::in);
file.seekg(0L,ios::beg);
while(file.read((char *)&p,sizeof(p)))
{
count=p.roll;
}

count++;
file.close();
return count;
}

void student::add_student()
{
clrscr();
gotoxy(16,2);
cout<<"NEW STUDENT RECORD";
gotoxy(4,3);
cout<<"***********************************************************************";
gotoxy(5,5);
cout<<"STUDENT ROLL:-";
p.roll=code();
cout<<p.roll;
gotoxy(5,7);
cout<<"STUDENT NAME:-";
gets(p.name);
gotoxy(5,9);
cout<<"FATHER NAME:-";
gets(p.fname);
gotoxy(5,11);
cout<<"FATHER OCCUPATION:-";
gets(p.fo);
gotoxy(5,13);
cout<<"DATE OF BIRTH:-";
gets(p.dob);
gotoxy(5,15);
cout<<"DATE OF ENTRY:-";
gets(p.doe);
gotoxy(5,17);
cout<<"ADDRESS:-";
gets(p.address);
gotoxy(5,19);
cout<<"COURSE NAME:-";
gets(p.course);
gotoxy(5,21);
cout<<"CONTACT NUMBER:-";
cin>>p.cnum;
gotoxy(5,23);
cout<<"PREVIOUS QUALIFICATIOPN:-";
gets(p.qualification);
gotoxy(5,25);
cout<<"SEX(M/F):-";
cin>>p.sex;
file.open("student.dat",ios::app|ios::out);
file.seekp(0L,ios::end);
file.write((char *)&p,sizeof(p));
file.close();
clrscr();
student();
}
void student::full_student()
{
int count=0;
int no;
long int pos;
clrscr();
file.open("student.dat",ios::in);
file.seekg(0L,ios::beg);

gotoxy(16,2);
cout<<"FULL STUDENT RECORD";
gotoxy(4,3);
cout<<"***********************************************************************";
gotoxy(5,5);
cout<<"STUDENT ROLL:-";
cin>>no;
while(file.read((char *)&p,sizeof(p)))
{
if(no==p.roll)
{
gotoxy(5,7);
cout<<"STUDENT NAME:-";
cout<<p.name;
gotoxy(5,9);
cout<<"FATHER NAME:-";
cout<<p.fname;
gotoxy(5,11);
cout<<"FATHER OCCUPATION:-";
cout<<p.fo;
gotoxy(5,13);
cout<<"DATE OF BIRTH:-";
cout<<p.dob;
gotoxy(5,15);
cout<<"DATE OF ENTRY:-";
cout<<p.doe;
gotoxy(5,17);
cout<<"ADDRESS:-";
cout<<p.address;
gotoxy(5,19);
cout<<"COURSE NAME:-";
cout<<p.course;
gotoxy(5,21);
cout<<"CONTACT NUMBER:-";
cout<<p.cnum;
gotoxy(5,23);
cout<<"PREVIOUS QUALIFICATIOPN:-";
cout<<p.qualification;
gotoxy(5,25);
cout<<"SEX(M/F):-";
cout<<p.sex;
}
count++;
}
gotoxy(50,25);
cout<<"PRESS ANY KEY TO BACK:";
file.close();
getch();
clrscr();
student();
}
void student::list_student()
{
int i=7;
clrscr();
gotoxy(16,2);
cout<<"LIST OF STUDENT RECORD";
gotoxy(4,3);
cout<<"**********************************************************************";
gotoxy(5,5);
cout<<"ROLL    STUDENT NAME                      COURSE NAME ";
file.open("student.dat",ios::in);
file.seekg(0L,ios::beg);
while(file.read((char *)&p,sizeof(p)))
{
gotoxy(5,i);
cout<<p.roll;
gotoxy(15,i);
cout<<p.name;
gotoxy(48,i);
cout<<p.course;
i++;
if(i==25)
{
i=7;
gotoxy(20,24);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
gotoxy(16,2);
cout<<"LIST OF STUDENT RECORD";
gotoxy(4,3);
cout<<"**********************************************************************";
gotoxy(5,5);
cout<<"ROLL    STUDENT NAME                      COURSE NAME ";
}
}

gotoxy(20,24);
cout<<"PRESS ANY KEY TO BACK";
file.close();
getch();
clrscr();
student();
}

void student::modify_student()
{
int count=0;
int no;
long int pos;
clrscr();
gotoxy(16,2);
cout<<"MODIFY STUDENT RECORD";
gotoxy(4,3);
cout<<"***********************************************************************";
gotoxy(5,5);
cout<<"STUDENT ROLL:-";
cin>>no;
file.open("student.dat",ios::in|ios::out);
file.seekg(0L,ios::beg);
while(file.read((char *)&p,sizeof(p)))
{
if(no==p.roll)
{

gotoxy(5,7);
cout<<"STUDENT NAME:-";
gets(p.name);
gotoxy(5,9);
cout<<"FATHER NAME:-";
gets(p.fname);
gotoxy(5,11);
cout<<"FATHER OCCUPATION:-";
gets(p.fo);
gotoxy(5,13);
cout<<"DATE OF BIRTH:-";
gets(p.dob);
gotoxy(5,15);
cout<<"DATE OF ENTRY:-";
gets(p.doe);
gotoxy(5,17);
cout<<"ADDRESS:-";
gets(p.address);
gotoxy(5,19);
cout<<"COURSE NAME:-";
gets(p.course);
gotoxy(5,21);
cout<<"CONTACT NUMBER:-";
cin>>p.cnum;
gotoxy(5,23);
cout<<"PREVIOUS QUALIFICATIOPN:-";
gets(p.qualification);
gotoxy(5,25);
cout<<"SEX(M/F):-";
cin>>p.sex;
pos=count*sizeof(p);
file.seekp(pos,ios::beg);
file.write((char *)&p,sizeof(p));
file.close();
}
count++;
}
file.close();
clrscr();
student();
}

void student::del_student()
{
int no;
clrscr();
gotoxy(16,2);
cout<<"DELETE STUDENT RECORD";
gotoxy(4,3);
cout<<"*********************************************************************";
fstream out;
gotoxy(5,5);
cout<<"STUDENT ROLL:-";
cin>>no;
gotoxy(15,24);
cout<<"DELETE(Y/N):-";
char c;
cin>>c;
if(c=='y')
{
	fstream temp;
	file.open("student.dat", ios::in);
	temp.open("TEMP.dat", ios::out);
	file.seekg(0, ios::beg);
	while (!file.eof())
	{
		file.read((char *)&p, sizeof(p));
		if (file.eof())
			break;
		if (p.roll != no)
		{
			temp.write((char *)&p, sizeof(p));
		}
	}
	file.close();
	temp.close();
	file.open("student.dat", ios::out);
	temp.open("TEMP.dat", ios::in);
	temp.seekg(0, ios::beg);
	while (!temp.eof())
	{
		temp.read((char *)&p, sizeof(p));
		if (temp.eof())
			break;
		if (p.roll!= no)
			file.write((char *)&p, sizeof(p));
	}
	file.close();
	temp.close();
gotoxy(15,25);
cout<<"record deleted:";
getch();
}
else
{
clrscr();
file.close();
}
clrscr();
student();
}





//********************* FEE MENU COADING *****************************

void fee::fee_menu()
 {
clrscr();
gotoxy(16,2);
cout<<"FEE RECORD MENU OF COLLEGE SYSTEM";
gotoxy(4,3);
cout<<"**********************************************************************";
sysdate();
gotoxy(20,6);
cout<<"1.ADDMISSION FEE";
gotoxy(20,8);
cout<<"2.RECEIVED FEE";
gotoxy(20,10);
cout<<"3.MODIFY FEE RECORD";
gotoxy(20,12);
cout<<"4.LIST OF FEE RECORD";
gotoxy(20,14);
cout<<"5.DELETE FEE RECORD";
gotoxy(4,18);
cout<<"**********************************************************************";
gotoxy(20,24);
cout<<"<0>FOR RETURN";
gotoxy(30,22);
cout<<"ENTER YOUR CHOICE:";
char ch;
ch=getch();
switch(ch)
{
case '0':
break;
case '1':
admission();
break;
case '2':
received();
break;
case '3':
modify_fee();
break;
case '4':
list_fee();
break;
case '5':
del_fee();
break;

}}
int fee::code()
{
int count=0;
file.open("fe.dat",ios::in);
file.seekg(0L,ios::beg);
while(file.read((char *)&f,sizeof(f)))
{
count=f.roll;
}

count++;
file.close();
return count;
}


void fee::admission()
{
clrscr();
gotoxy(16,2);
cout<<"ADMISSION FORM";
gotoxy(4,3);
cout<<"***********************************************************************";
gotoxy(8,5);
cout<<"STUDENT ROLL:-";
f.roll=code();
cout<<f.roll;
gotoxy(8,8);
cout<<"STUDENT NAME:-";
gets(f.name);
gotoxy(8,10);
cout<<"FATHER NAME:-";
gets(f.fname);
gotoxy(8,12);
cout<<"DATE OF BIRTH:-";
cin>>f.dob;
gotoxy(8,14);
cout<<"ADDRESS:-";
cin>>f.address;
gotoxy(8,16);
cout<<"COURSE NAME:-";
cin>>f.course;
gotoxy(8,18);
cout<<"DURATION:-";
cin>>f.duration;
gotoxy(8,19);
cout<<"TOTAL FEE:-";
cin>>f.total_fee;
gotoxy(8,21);
cout<<"PAID FEE:-";
cin>>f.paid_fee;
gotoxy(8,23);
cout<<"DUES FEE:-";
f.dues_fee=f.total_fee-f.paid_fee;
cout<<f.dues_fee;
getch();
file.open("fe.dat",ios::app|ios::out);
file.seekp(0l,ios::end);
file.write((char *)&f,sizeof(f));
file.close();
clrscr();
fee_menu();
}
void fee::received()
{
int count=0;
int no;
long int pos;
clrscr();
gotoxy(16,2);
cout<<"RECEIVED FEE";
gotoxy(4,3);
cout<<"************************************************************************";
file.open("fe.dat",ios::in|ios::out);
file.seekg(0L,ios::beg);
gotoxy(8,8);
cout<<"STUDENT ROLL:-";
cin>>no;
while(file.read((char *)&f,sizeof(f)))
{
if(no==f.roll)
{

gotoxy(8,10);
cout<<"STUDENT NAME:-";
cout<<f.name;
gotoxy(8,12);
cout<<"COURSE NAME:-";
cout<<f.course;
gotoxy(8,14);
cout<<"DURATION:-";
cout<<f.duration;
gotoxy(8,16);
cout<<"RECEIVED FEE:-";
cin>>f.paid_fee;
gotoxy(8,18);
cout<<"DUES FEE:-";
f.dues_fee=f.dues_fee - f.paid_fee;
cout<<f.dues_fee;
getch();
pos=count*sizeof(f);
file.seekp(pos,ios::beg);
file.write((char *)&f,sizeof(f));
file.close();
}
count++;
}
clrscr();
fee_menu();
}


void fee::list_fee()
{
int i=7;
clrscr();
gotoxy(16,2);
cout<<"LIST OF FEE RECORD";
gotoxy(2,3);
cout<<"****************************************************************************";
gotoxy(5,5);
cout<<"ROLL    STUDENT NAME                COURSE NAME    PAID FEE    DUES FEE";
gotoxy(2,6);
cout<<"****************************************************************************";

file.open("fe.dat",ios::in);
file.seekg(0L,ios::beg);

while(file.read((char *)&f,sizeof(f)))
{
gotoxy(5,i);
cout<<f.roll;
gotoxy(12,i);
cout<<f.name;
gotoxy(45,i);
cout<<f.course;
gotoxy(57,i);
cout<<f.total_fee;
gotoxy(68,i);
cout<<f.dues_fee;
i++;
if(i==25)
{
i=7;
gotoxy(20,24);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
gotoxy(16,2);
cout<<"LIST OF FEE RECORD";
gotoxy(2,3);
cout<<"***************************************************************************";
gotoxy(5,5);
cout<<"ROLL    STUDENT NAME                 COURSE NAME    PAID FEE    DUES FEE";
gotoxy(2,6);
cout<<"****************************************************************************";
}
}
gotoxy(20,24);
cout<<"PRESS ANY KEY TO BACK";
file.close();
getch();
clrscr();
fee_menu();
}

void fee::modify_fee()
{
int count=0;
int no;
long int pos;
file.open("fe.dat",ios::in|ios::out);
file.seekg(0L,ios::beg);
clrscr();
gotoxy(16,2);
cout<<"MODIFY FEE";
gotoxy(4,3);
cout<<"***********************************************************************";
gotoxy(8,5);
cout<<"STUDENT ROLL:-";
cin>>no;
while(file.read((char *)&f,sizeof(f)))
{
if(no==f.roll)
{
gotoxy(8,8);
cout<<"STUDENT NAME:-";
gets(f.name);
gotoxy(8,10);
cout<<"FATHER NAME:-";
gets(f.fname);
gotoxy(8,12);
cout<<"DATE OF BIRTH:-";
cin>>f.dob;
gotoxy(8,14);
cout<<"ADDRESS:-";
cin>>f.address;
gotoxy(8,16);
cout<<"COURSE NAME:-";
cin>>f.course;
gotoxy(8,18);
cout<<"DURATION:-";
cin>>f.duration;
gotoxy(8,19);
cout<<"TOTAL FEE:-";
cin>>f.total_fee;
gotoxy(8,21);
cout<<"PAID FEE:-";
cin>>f.paid_fee;
gotoxy(8,23);
cout<<"DUES FEE:-";
f.dues_fee=f.total_fee-f.paid_fee;
cout<<f.dues_fee;
getch();

pos=count*sizeof(f);
file.seekp(pos,ios::beg);
file.write((char *)&f,sizeof(f));
file.close();
}
count++;
}
clrscr();
fee_menu();
}



void fee::del_fee()
{
int no;
clrscr();
gotoxy(16,2);
cout<<"DELETE FEE RECORD";
gotoxy(4,3);
cout<<"*********************************************************************";
fstream out;
gotoxy(5,5);
cout<<"ROLL NUMBER:-";
cin>>no;
gotoxy(15,24);
cout<<"DELETE(Y/N):-";
char c;
cin>>c;
if(c=='y')
{
	fstream temp;
	file.open("fe.dat", ios::in);
	temp.open("TEMP.dat", ios::out);
	file.seekg(0, ios::beg);
	while (!file.eof())
	{
		file.read((char *)&f, sizeof(f));
		if (file.eof())
			break;
		if (f.roll != no)
		{
			temp.write((char *)&f, sizeof(f));
		}
	}
	file.close();
	temp.close();
	file.open("fe.dat", ios::out);
	temp.open("TEMP.dat", ios::in);
	temp.seekg(0, ios::beg);
	while (!temp.eof())
	{
		temp.read((char *)&f, sizeof(f));
		if (temp.eof())
		    break;
		if (f.roll!= no)
			file.write((char *)&f, sizeof(f));
	}
	file.close();
	temp.close();
gotoxy(15,25);
cout<<"record deleted:";
getch();
}
else
{
clrscr();
file.close();
}
clrscr();
fee_menu();
}




//********************** exam coading *****************************



void exam::examination()
 {
 char ch;
 do
 {
clrscr();
gotoxy(16,2);
cout<<"EXAMINATION MENU OF COLLEGE SYSTEM";
gotoxy(4,3);
cout<<"**********************************************************************";
sysdate();
gotoxy(20,6);
cout<<"1.ADD COURSE EXAM";
gotoxy(20,8);
cout<<"2.LIST OF COURSE EXAM & DATE";
gotoxy(20,10);
cout<<"3.MODIFY COURSE EXAM";
gotoxy(20,12);
cout<<"4.DELETE COURSE EXAM";
gotoxy(4,18);
cout<<"**********************************************************************";
gotoxy(20,24);
cout<<"<0>FOR RETURN";
gotoxy(30,22);
cout<<"ENTER YOUR CHOICE:";
ch=getch();
switch(ch)
{
case '0':
break;
case '1':
add_exam_term();
break;
case '2':
list_exam_term();
break;
case '3':
modify_exam_term();
break;
case '4':
del_exam_term();
break;
}
}while(!ch);
}

int exam::code()
{
int count=0;
f.open("exam.dat",ios::in);
f.seekg(0L,ios::beg);
while(f.read((char *)&p,sizeof(p)))
{
count=p.course_code;
}

count++;
f.close();
return count;
}

void exam::add_exam_term()
{
clrscr();
gotoxy(16,2);
cout<<"ADD EXAMINATION TERM";
gotoxy(4,3);
cout<<"***********************************************************************";
gotoxy(5,5);
cout<<"Date:-";
gotoxy(5,7);
cout<<"EXAM CODE:-";
p.course_code=code();
cout<<p.course_code;
gotoxy(5,9);
cout<<"COURSE NAME:-";
gets(p.course_name);
gotoxy(5,11);
cout<<"DURATION:-";
cin>>p.duration;
gotoxy(5,13);
cout<<"EXAM TERM:-";
gets(p.exam_term);
gotoxy(5,15);
cout<<"EXAM DATE:-";
gets(p.exam_date);
f.open("exam.dat",ios::app|ios::out);
f.seekp(0L,ios::end);
f.write((char *)&p,sizeof(p));
f.close();
clrscr();
examination();
}

void exam::modify_exam_term()
{
clrscr();
int count=0;
int no;
long int pos;
f.open("exam.dat",ios::in|ios::out);
f.seekg(0L,ios::beg);
gotoxy(16,2);
cout<<"MODIFY EXAMINATION TERM";
gotoxy(4,3);
cout<<"***********************************************************************";
gotoxy(5,7);
cout<<"EXAM CODE:-";
cin>>no;
while(f.read((char *)&p,sizeof(p)))
{
if(no==p.course_code)
{

gotoxy(5,5);
cout<<"Date:-";
gotoxy(5,9);
cout<<"COURSE NAME:-";
gets(p.course_name);
gotoxy(5,11);
cout<<"DURATION:-";
cin>>p.duration;
gotoxy(5,13);
cout<<"EXAM TERM:-";
gets(p.exam_term);
gotoxy(5,15);
cout<<"EXAM DATE:-";
gets(p.exam_date);

pos=count*sizeof(p);
f.seekp(pos,ios::beg);
f.write((char *)&p,sizeof(p));
f.close();
}
count++;
}
clrscr();
examination();
}
void exam::list_exam_term()
{
int i=7;

clrscr();
gotoxy(16,3);
cout<<"LIST OF EXAMINATION";
gotoxy(4,4);
cout<<"*************************************************************************";
gotoxy(5,5);
cout<<"EXAM CODE   COURSE NAME   DURATION   EXAM TERM    EXAM DATE   ";
f.open("exam.dat",ios::in);
f.seekg(0L,ios::beg);
while(f.read((char *)&p,sizeof(p)))
{
gotoxy(7,i);
cout<<p.course_code;
gotoxy(20,i);
cout<<p.course_name;
gotoxy(35,i);
cout<<p.duration;
gotoxy(48,i);
cout<<p.exam_term;
gotoxy(61,i);
cout<<p.exam_date;
i++;
if(i==25)
{
i=7;
gotoxy(20,24);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
gotoxy(16,3);
cout<<"LIST OF EXAMINATION";
gotoxy(4,4);
cout<<"*************************************************************************";
gotoxy(5,5);
cout<<"EXAM CODE   COURSE NAME   DURATION   EXAM TERM    EXAM DATE   ";
}
}
gotoxy(20,24);
cout<<"PRESS ANY KEY TO BACK";
f.close();
getch();
clrscr();
examination();
}



void exam::del_exam_term()
{
int no;
clrscr();
gotoxy(16,2);
cout<<"DELETE EXAMINATION TERM";
gotoxy(4,3);
cout<<"*********************************************************************";
fstream out;
gotoxy(5,5);
cout<<"EXAM CODE:-";
cin>>no;
gotoxy(15,24);
cout<<"DELETE(Y/N):-";
char c;
cin>>c;
if(c=='y')
{
	fstream temp;
	f.open("exam.dat", ios::in);
	temp.open("TEMP.dat", ios::out);
	f.seekg(0, ios::beg);
	while (!f.eof())
	{
		f.read((char *)&p, sizeof(p));
		if (f.eof())
			break;
		if (p.course_code != no)
		{
			temp.write((char *)&p, sizeof(p));
		}
	}
	f.close();
	temp.close();
	f.open("exam.dat", ios::out);
	temp.open("TEMP.dat", ios::in);
	temp.seekg(0, ios::beg);
	while (!temp.eof())
	{
		temp.read((char *)&p, sizeof(p));
		if (temp.eof())
			break;
		if (p.course_code!= no)
			f.write((char *)&p, sizeof(p));
	}
	f.close();
	temp.close();
gotoxy(15,25);
cout<<"record deleted:";
getch();
}
else
{
clrscr();
f.close();
}
clrscr();
examination();
}







//******************** EMPLOYEE MENU COADING ***************************




void emp::employee()
{
clrscr();
gotoxy(16,3);
cout<<"EMPLOYEE SYSTEMN";
gotoxy(4,4);
cout<<"**********************************************************************";
sysdate();
gotoxy(15,6);
cout<<"1.EMPLOYEE RECORD";
gotoxy(15,8);
cout<<"2.EMPLOYEE SALARY ";
gotoxy(4,10);
cout<<"*********************************************************************";
gotoxy(20,24);
cout<<"<0>FOR RETURN BACK:";
gotoxy(20,20);
cout<<"enter your choice:";
ch=getch();
clrscr();
if(ch=='0'||ch=='1'||ch=='2')
{
switch(ch)
{
case '0':
break;
case '1':
 {
employee_record();
 break;
 }
case '2':
{
salary();
break;
}

}
}
else
{
gotoxy(25,10);
cout<<"invalid option:";
sleep(2);
clrscr();
employee();
}}




void emp::employee_record()
{

gotoxy(16,3);
cout<<"EMPLOYEE SYSTEMN";
gotoxy(4,4);
cout<<"**********************************************************************";
sysdate();
gotoxy(15,6);
cout<<"1.ADD EMPLOYEE ";
gotoxy(15,8);
cout<<"2.MODIFY EMPLOYEE ";
gotoxy(15,11);
cout<<"3.LIST OF EMPLOYEE";
gotoxy(15,14);
cout<<"4.VIEW INDIVIDUAL EMPLOYEE";
gotoxy(15,17);
cout<<"5.DELETE EMPLOYEE";
gotoxy(4,19);
cout<<"*********************************************************************";
gotoxy(20,24);
cout<<"<0>for exit program:";
gotoxy(20,20);
cout<<"enter your choice:";

ch=getch();
clrscr();
switch(ch)
{
case '0':
{
employee();
break;
}
case '1':
{
add_employee();
 break;
 }
 case '2':
 {
modify_employee();
break;
}

case '3':
{
list_employee();
break;
}
case '4':
{
indi_employee();
break;
case '5':
{
del_employee();
break;
}
}
}}

int emp::code()
{
int count=0;
f.open("em.dat",ios::in);
f.seekg(0L,ios::beg);
while(f.read((char *)&p,sizeof(p)))
{
count=p.e_no;
}

count++;
f.close();
return count;
}


void emp::add_employee()
{
do
{
clrscr();
 gotoxy(16,3);
cout<<"ADD NEW EMPLOYEE";
gotoxy(4,4);
cout<<"*************************************************************************";
gotoxy(5,5);
cout<<"EMPLOYEE NUMBER:";
p.e_no=code();
cout<<p.e_no;
gotoxy(5,7);
cout<<"NAME:";
gets(p.e_name);
gotoxy(5,9);
cout<<"DOB:";
gets(p.dob);
gotoxy(5,11);
cout<<"CITY:";
gets(p.city);
gotoxy(5,13);
cout<<"DISTRICT:";
gets(p.dist);
gotoxy(5,15);
cout<<"STATE:";
gets(p.state);
gotoxy(5,17);
cout<<"ZIP:";
gets(p.zip);
gotoxy(5,19);
cout<<"DESIGNATION:";
gets(p.desi);
gotoxy(5,21);
cout<<"DATE OF JOIN:";
gets(p.doj);
gotoxy(5,23);
cout<<"DEPARTMENT:";
gets(p.dept);
gotoxy(30,21);
cout<<"SALARY:";
cin>>p.bsal;
gotoxy(30,23);
cout<<"GRADE:";
cin>>p.g;
f.open("em.dat",ios::app|ios::out);
f.seekg(0L,ios::end);
f.write((char *)&p,sizeof(p));
f.close();
gotoxy(20,25);
cout<<"more(y/n):";ch=getch();
}while(ch=='y');

clrscr();
employee_record();
}

void emp::modify_employee()
{
int count=0;
int no;
long int pos;
f.open("em.dat",ios::in|ios::out);
f.seekg(0L,ios::beg);
clrscr();
 gotoxy(16,3);
cout<<"MODIFY EMPLOYEE";
gotoxy(4,4);
cout<<"*************************************************************************";
gotoxy(5,5);
cout<<"EMPLOYEE NUMBER:";
cin>>no;

while(f.read((char *)&p,sizeof(p)))
{
if(no==p.e_no)
{

gotoxy(5,7);
cout<<"NAME:";
gets(p.e_name);
gotoxy(5,9);
cout<<"DOB:";
gets(p.dob);
gotoxy(5,11);
cout<<"CITY:";
gets(p.city);
gotoxy(5,13);
cout<<"DISTRICT:";
gets(p.dist);
gotoxy(5,15);
cout<<"STATE:";
gets(p.state);
gotoxy(5,17);
cout<<"ZIP:";
gets(p.zip);
gotoxy(5,19);
cout<<"DESIGNATION:";
gets(p.desi);
gotoxy(5,21);
cout<<"DATE OF JOIN:";
gets(p.doj);
gotoxy(5,23);
cout<<"DEPARTMENT:";
gets(p.dept);
gotoxy(30,21);
cout<<"SALARY:";
cin>>p.bsal;
gotoxy(30,23);
cout<<"GRADE:";
cin>>p.g;

pos=count*sizeof(p);
f.seekp(pos,ios::beg);
f.write((char *)&p,sizeof(p));
f.close();
}
count++;
}
clrscr();
employee_record();

}
void emp::list_employee()
{
int i=8;
clrscr();
 gotoxy(16,3);
cout<<"ADD NEW EMPLOYEE";
gotoxy(4,4);
cout<<"*************************************************************************";
gotoxy(5,5);
cout<<"EMP CODE     EMP NAME             DESIGATION       SALARY";
gotoxy(5,6);
cout<<"*************************************************************************";
f.open("em.dat",ios::in);
f.seekg(0L,ios::beg);
while(f.read((char *)&p,sizeof(p)))
{
gotoxy(8,i);
cout<<p.e_no;
gotoxy(17,i);
cout<<p.e_name;
gotoxy(40,i);
cout<<p.desi;
gotoxy(57,i);
cout<<p.bsal;
i++;
if(i==24)
{
i=8;
gotoxy(20,24);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
 gotoxy(16,3);
cout<<"ADD NEW EMPLOYEE";
gotoxy(4,4);
cout<<"*************************************************************************";
gotoxy(5,5);
cout<<"EMP CODE     EMP NAME             DESIGATION       SALARY";
gotoxy(5,6);
cout<<"*************************************************************************";

}
}
gotoxy(20,24);
cout<<"PRESS ANY KEY TO BACK";
f.close();
getch();
clrscr();
employee_record();
}
void emp::indi_employee()
{
int count=0;
int no;
long int pos;
clrscr();

f.open("em.dat",ios::in);
f.seekg(0L,ios::beg);
clrscr();
 gotoxy(16,3);
cout<<"INDIVIDUAL LIST OF EMPLOYEE";
gotoxy(4,4);
cout<<"*************************************************************************";
gotoxy(5,5);
cout<<"EMPLOYEE NUMBER:";
cin>>no;

while(f.read((char *)&p,sizeof(p)))
{
if(no==p.e_no)
{

gotoxy(5,7);
cout<<"NAME:";
cout<<p.e_name;
gotoxy(5,9);
cout<<"DOB:";
cout<<p.dob;
gotoxy(5,11);
cout<<"CITY:";
cout<<p.city;
gotoxy(5,13);
cout<<"DISTRICT:";
cout<<p.dist;
gotoxy(5,15);
cout<<"STATE:";
cout<<p.state;
gotoxy(5,17);
cout<<"ZIP:";
cout<<p.zip;
gotoxy(5,19);
cout<<"DESIGNATION:";
cout<<p.desi;
gotoxy(5,21);
cout<<"DATE OF JOIN:";
cout<<p.doj;
gotoxy(5,23);
cout<<"DEPARTMENT:";
cout<<p.dept;
gotoxy(30,21);
cout<<"SALARY:";
cout<<p.bsal;
gotoxy(30,23);
cout<<"GRADE:";
cout<<p.g;
}
count++;
}
gotoxy(20,24);
cout<<"PRESS ANY KEY TO BACK";
f.close();
getch();
clrscr();
employee_record();
}


void emp::del_employee()
{
int no;
clrscr();
gotoxy(16,2);
cout<<"DELETE COURSE RECORD";
gotoxy(4,3);
cout<<"*********************************************************************";
fstream out;
gotoxy(5,5);
cout<<"COURSE CODE:-";
cin>>no;
gotoxy(15,24);
cout<<"DELETE(Y/N):-";
char c;
cin>>c;
if(c=='y')
{
	fstream temp;
	f.open("em.dat", ios::in);
	temp.open("TEMP.dat", ios::out);
	f.seekg(0, ios::beg);
	while (!f.eof())
	{
		f.read((char *)&p, sizeof(p));
		if (f.eof())
			break;
		if (p.e_no != no)
		{
			temp.write((char *)&p, sizeof(p));
		}
	}
	f.close();
	temp.close();
	f.open("em.dat", ios::out);
	temp.open("TEMP.dat", ios::in);
	temp.seekg(0, ios::beg);
	while (!temp.eof())
	{
		temp.read((char *)&p, sizeof(p));
		if (temp.eof())
			break;
		if (p.e_no!= no)
			f.write((char *)&p, sizeof(p));
	}
	f.close();
	temp.close();
gotoxy(15,25);
cout<<"record deleted:";
getch();
}
else
{
clrscr();
f.close();
}
clrscr();
employee_record();
}



void emp::salary()
{
clrscr();
gotoxy(16,3);
cout<<"EMPLOYEE SALARY";
gotoxy(4,4);
cout<<"**********************************************************************";
sysdate();
gotoxy(15,6);
cout<<"1.SALARY SLIP";
gotoxy(15,8);
cout<<"2.CHANE SALARY ";
gotoxy(4,10);
cout<<"*********************************************************************";
gotoxy(20,24);
cout<<"<0>FOR RETURN BACK:";
gotoxy(20,20);
cout<<"enter your choice:";
ch=getch();
clrscr();
switch(ch)
{
case '0':
{
employee();
break;
}
case '1':
{
salary_slip();
break;
}
 case '2':
 {
change_salary();
break;
}
}
}

void emp::salary_slip()
{
int i=8;

clrscr();
gotoxy(16,2);
cout<<"SALARY SLIP";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(5,5);
cout<<"EMP CODE     EMP NAME             DESIGATION       SALARY";
gotoxy(4,6);
cout<<"*************************************************************************";
f.open("em.dat",ios::in);
f.seekg(0L,ios::beg);
while(f.read((char *)&p,sizeof(p)))
{
gotoxy(8,i);
cout<<p.e_no;
gotoxy(17,i);
cout<<p.e_name;
gotoxy(40,i);
cout<<p.desi;
p.ta=p.bsal*5/100;
p.da=p.bsal*10/100;
p.hra=p.bsal*12/100;
p.pf=p.bsal*5/100;
p.tsal=(p.bsal+p.ta+p.da+p.hra)-p.pf;
gotoxy(57,i);
cout<<p.tsal;
i++;
if(i==24)
{
i=8;
gotoxy(20,24);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
gotoxy(16,2);
cout<<"SALARY SLIP";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(5,5);
cout<<"EMP CODE     EMP NAME             DESIGATION       SALARY";
gotoxy(4,6);
cout<<"*************************************************************************";
}
}
gotoxy(20,24);
cout<<"PRESS ANY KEY TO BACK";
f.close();
getch();
clrscr();
salary();
}
void emp::change_salary()
{
int count=0;
int no;
long int pos;
gotoxy(16,2);
cout<<"MODIFY SALARY ";
gotoxy(4,4);
cout<<"************************************************************************";

f.open("em.dat",ios::in|ios::out);
f.seekg(0L,ios::beg);
gotoxy(8,6);
cout<<"EMPLOYEE NUMBER:";
cin>>no;
while(f.read((char *)&p,sizeof(p)))
{
if(no==p.e_no)
{
gotoxy(8,9);
cout<<"SALARY:";
cin>>p.bsal;
pos=count*sizeof(p);
f.seekp(pos,ios::beg);
f.write((char *)&p,sizeof(p));
f.close();
}
count++;
}
clrscr();
salary();

}



//*************************** MENU6 COADING *****************************



void library::library_menu()
{
clrscr();
gotoxy(16,3);
cout<<"LIBRARY SYSTEM";
gotoxy(4,4);
cout<<"***********************************************************************";
sysdate();
gotoxy(20,24);
cout<<"<0>for return";
gotoxy(15,6);
cout<<"1.BOOKS RECORD";
gotoxy(15,10);
cout<<"2.MEMBER RECORD";
gotoxy(15,14);
cout<<"3.BOOK ISSUE/RETURN";
gotoxy(4,18);
cout<<"*************************************************************************";
gotoxy(20,20);
cout<<"Enter your choice:";
ch=getch();
clrscr();
switch(ch)
{
case '0':
break;
case '1':
{
book_record();
break;
}
case '2':
{
member_record();
}
case '3':
{
book_issue_return();
}
}
}



 void library::book_record()
 {
gotoxy(16,3);
cout<<"BOOKS RECORD MENU";
gotoxy(4,4);
cout<<"**********************************************************************";
sysdate();
gotoxy(15,6);
cout<<"1.ADD NEW BOOK RECORD";
gotoxy(15,8);
cout<<"2.MODIFY BOOK RECORD";
gotoxy(15,11);
cout<<"3.LIST OF BOOK RECORD";
gotoxy(15,14);
cout<<"4.DELETE BOOK RECORD";
gotoxy(4,18);
cout<<"***********************************************************************";
gotoxy(20,24);
cout<<"<0> for return:";
gotoxy(20,20);
cout<<"Enter your choice:";
ch=getch();
clrscr();
switch(ch)
{
case '0':
{
library();
break;
}
case '1':
{
add_book();
break;
}
case '2':
{
modify_book();
break;
}
case '3':
{
list_book();
break;
}
case '4':
{
delete_book();
break;
}
 }
}

int library::bcode()
{
int count=0;
file.open("book.dat",ios::in);
file.seekg(0L,ios::beg);
while(file.read((char *)&s,sizeof(s)))
{
count=s.book_no;
}

count++;
file.close();
return count;
}


void library::add_book()
{
clrscr();
gotoxy(16,3);
cout<<"ADD BOOKS RECORD MENU";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(8,7);
cout<<"BOOK NUMBER:-";
s.book_no=bcode();
cout<<s.book_no;
gotoxy(8,9);
cout<<"BOOK TITLE:-";
gets(s.book_title);
gotoxy(8,11);
cout<<"AURTHER NAME:-";
gets(s.aname);
gotoxy(8,13);
cout<<"PUBLISHER NAME:-";
gets(s.pname);
gotoxy(8,15);
cout<<"PRICE:-";
cin>>s.price;
gotoxy(8,17);
cout<<"NUMBER OF PAGE:-";
cin>>s.page_no;
gotoxy(8,19);
cout<<"SAVE(Y/N):-";
cout<<"s";
getch();
file.open("book.dat",ios::app|ios::out);
file.seekp(0L,ios::end);
file.write((char *)&s,sizeof(s));
file.close();
clrscr();
book_record();
}
void library::modify_book()
{
int count=0;
int no;
long int pos;
file.open("book.dat",ios::in|ios::out);
file.seekg(0L,ios::beg);
clrscr();
gotoxy(16,3);
cout<<"MODIFY BOOKS RECORD MENU";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(8,7);
cout<<"BOOK NUMBER:-";
cin>>no;
while(file.read((char *)&s,sizeof(s)))
{
if(no==s.book_no)
{

gotoxy(8,5);
cout<<"Date:-";
gotoxy(8,9);
cout<<"BOOK TITLE:-";
gets(s.book_title);
gotoxy(8,11);
cout<<"AURTHER NAME:-";
gets(s.aname);
gotoxy(8,13);
cout<<"PUBLISHER NAME:-";
gets(s.pname);
gotoxy(8,15);
cout<<"PRICE:-";
cin>>s.price;
gotoxy(8,17);
cout<<"NUMBER OF PAGE:-";
cin>>s.page_no;
gotoxy(8,19);
cout<<"SAVE(Y/N):-";
cout<<"s";
getch();
pos=count*sizeof(s);
file.seekp(pos,ios::beg);
file.write((char *)&s,sizeof( s));
file.close();
}
count++;
}
clrscr();
book_record();
}
void library::list_book()
{
int i=8;
clrscr();
gotoxy(16,3);
cout<<"LIST OF BOOKS";
gotoxy(4,4);
cout<<"*************************************************************************";
gotoxy(5,5);
cout<<"BOOK NO.   BOOK NAME   AURTHER NAME   PUBLISHER NAME    PRICE   PAGES";
gotoxy(4,6);
cout<<"**************************************************************************";
file.open("book.dat",ios::in);
file.seekg(0L,ios::beg);
while(file.read((char *)&s,sizeof(s)))
{
gotoxy(7,i);
cout<<s.book_no;
gotoxy(15,i);
cout<<s.book_title;
gotoxy(30,i);
cout<<s.aname;
gotoxy(45,i);
cout<<s.pname;
gotoxy(61,i);
cout<<s.price;
gotoxy(70,i);
cout<<s.page_no;
i++;
if(i==25)
{
i=9;
gotoxy(20,24);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
gotoxy(16,3);
cout<<"LIST OF BOOKS";
gotoxy(4,4);
cout<<"*************************************************************************";
gotoxy(5,5);
cout<<"BOOK NO.   BOOK NAME   AURTHER NAME   PUBLISHER NAME    PRICE   PAGES";
gotoxy(4,6);
cout<<"**************************************************************************";

}
}
gotoxy(20,24);
cout<<"PRESS ANY KEY TO BACK";
file.close();
getch();
clrscr();
book_record();
}

void library::delete_book()
{
int no;
clrscr();
gotoxy(16,2);
cout<<"DELETE BOOK RECORD";
gotoxy(4,3);
cout<<"*********************************************************************";
fstream out;
gotoxy(5,5);
cout<<"BOOK NUMBER:-";
cin>>no;
gotoxy(15,20);
cout<<"DELETE(Y/N):-";
char c;
cin>>c;
if(c=='y')
{
	fstream temp;
	file.open("book.dat", ios::in);
	temp.open("TEMP.dat", ios::out);
	file.seekg(0, ios::beg);
	while (!file.eof())
	{
		file.read((char *)&s, sizeof(s));
		if (file.eof())
			break;
		if (s.book_no != no)
		{
			temp.write((char *)&s, sizeof(s));
		}
	}
	file.close();
	temp.close();
	file.open("book.dat", ios::out);
	temp.open("TEMP.dat", ios::in);
	temp.seekg(0, ios::beg);
	while (!temp.eof())
	{
		temp.read((char *)&s, sizeof(s));
		if (temp.eof())
			break;
		if (s.book_no!= no)
			file.write((char *)&s, sizeof(s));
	}
	file.close();
	temp.close();
gotoxy(15,22);
cout<<"Record deleted:";
getch();
}
else
{
clrscr();
file.close();
}
clrscr();
book_record();
}







void library::member_record()
{
  clrscr();
gotoxy(16,3);
cout<<"MEMBER RECORD MENU";
gotoxy(4,4);
cout<<"*************************************************************************";
sysdate();
gotoxy(15,8);
cout<<"1.ADD NEW MEMBER RECORD";
  gotoxy(15,11);
cout<<"2.MODIFY MEMBER RECORD";
 gotoxy(15,14);
cout<<"3.LIST OF MEMBER RECORD";
 gotoxy(15,17);
 cout<<"4.DELETE MEMBER RECORD";
gotoxy(4,19);
cout<<"*************************************************************************";
gotoxy(20,25);
cout<<"<0> for return:";
gotoxy(20,20);
cout<<"Enter your choice:";

ch=getch();
clrscr();
switch(ch)
{
case '0':
{
library();
break;
}
case '1':
{
add_member();
break;
}
case '2':
{
modify_member();
break;
}
case '3':
{
list_member();
break;
}
case '4':
{
delete_member();
break;
}
 }
}


int library::mcode()
{
int count=0;
file.open("mem.dat",ios::in);
file.seekg(0L,ios::beg);
while(file.read((char *)&s,sizeof(s)))
{
count=s.mem_no;
}

count++;
file.close();
return count;
}


void library::add_member()
{
clrscr();
gotoxy(16,3);
cout<<"ADD NEW MEMBER";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(8,7);
cout<<"MEMBER NUMBER:-";
s.mem_no=mcode();
cout<<s.mem_no;
gotoxy(8,9);
cout<<"MEMBER NAME:-";
gets(s.mem_name);
gotoxy(8,11);
cout<<"ROLL NUMBER:-";
cin>>s.rno;

gotoxy(8,13);
cout<<"CLASS NAME:-";
gets(s.class_name);
gotoxy(8,15);
cout<<"ADDRESS:-";
gets(s.add);
gotoxy(8,17);
cout<<"MEMBERSHIP FEE:-";
cin>>s.mem_fee;
gotoxy(8,19);
cout<<"SAVE(Y/N):-";
cout<<"s";
getch();
file.open("mem.dat",ios::app|ios::out);
file.seekp(0L,ios::end);
file.write((char *)&s,sizeof(s));
file.close();
clrscr();
member_record();
}

void library::modify_member()
{
int count=0;
int no;
long int pos;
file.open("mem.dat",ios::in|ios::out);
file.seekg(0L,ios::beg);
clrscr();
gotoxy(16,3);
cout<<"MODIFY MEMBER RECORD";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(8,7);
cout<<"MEMBER NUMBER:-";
cin>>no;
while(file.read((char *)&s,sizeof(s)))
{
if(no==s.mem_no)
{


gotoxy(8,5);
cout<<"Date:-";
gotoxy(8,9);
cout<<"MEMBER NAME:-";
gets(s.mem_name);
gotoxy(8,11);
cout<<"ROLL NUMBER:-";
cin>>s.rno;
gotoxy(8,13);
cout<<"CLASS NAME:-";
gets(s.class_name);
gotoxy(8,15);
cout<<"ADDRESS:-";
gets(s.add);
gotoxy(8,17);
cout<<"MEMBERSHIP FEE:-";
cin>>s.mem_fee;
gotoxy(8,19);
cout<<"SAVE(Y/N):-";
cout<<"s";
getch();
pos=count*sizeof(s);
file.seekp(pos,ios::beg);
file.write((char *)&s,sizeof(s));
file.close();
}
count++;
}
clrscr();
member_record();
}
void library::list_member()
{
int i=8;
clrscr();
gotoxy(16,3);
cout<<"LIST OF MEMBER";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(5,5);
cout<<"MEMBER NO.   MEMBER NAME             ROLL NO.     CLASS     FEE";
gotoxy(4,6);
cout<<"************************************************************************";
file.open("mem.dat",ios::in);
file.seekp(0l,ios::beg);
while(file.read((char *)&s,sizeof(s)))
{
gotoxy(8,i);
cout<<s.mem_no;
gotoxy(18,i);
cout<<s.mem_name;
gotoxy(42,i);
cout<<s.rno;
gotoxy(55,i);
cout<<s.class_name;
gotoxy(65,i);
cout<<s.mem_fee;
i++;
if(i==25)
{
i=8;
gotoxy(20,24);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
gotoxy(16,3);
cout<<"LIST OF MEMBER";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(5,5);
cout<<"MEMBER NO.   MEMBER NAME             ROLL NO.     CLASS     FEE";
gotoxy(4,6);
cout<<"************************************************************************";
}
}
gotoxy(20,24);
cout<<"PRESS ESC TO BACK";
file.close();
getch();
clrscr();
member_record();
}



void library::delete_member()
{
int no;
clrscr();
gotoxy(16,2);
cout<<"DELETE MEMBER RECORD";
gotoxy(4,3);
cout<<"*********************************************************************";
fstream out;
gotoxy(5,5);
cout<<"MEMBERSHIP NUMBER:-";
cin>>no;
gotoxy(15,20);
cout<<"DELETE(Y/N):-";
char c;
cin>>c;
if(c=='y')
{
	fstream temp;
	file.open("mem.dat", ios::in);
	temp.open("TEMP.dat", ios::out);
	file.seekg(0, ios::beg);
	while (!file.eof())
	{
		file.read((char *)&s, sizeof(s));
		if (file.eof())
			break;
		if (s.mem_no != no)
		{
			temp.write((char *)&s, sizeof(s));
		}
	}
	file.close();
	temp.close();
	file.open("mem.dat", ios::out);
	temp.open("TEMP.dat", ios::in);
	temp.seekg(0, ios::beg);
	while (!temp.eof())
	{
		temp.read((char *)&s, sizeof(s));
		if (temp.eof())
			break;
		if (s.mem_no!= no)
			file.write((char *)&s, sizeof(s));
	}
	file.close();
	temp.close();
gotoxy(15,25);
cout<<"record deleted:";
getch();
}
else
{
clrscr();
file.close();
}
clrscr();
member_record();
}





void library::book_issue_return()
{
clrscr();
gotoxy(16,3);
cout<<"BOOKS ISSUE RETURN";
gotoxy(4,4);
cout<<"************************************************************************";
sysdate();
gotoxy(15,8);
cout<<"1.BOOK ISSUE";
gotoxy(15,10);
cout<<"2.BOOK RETURN";
gotoxy(15,12);
cout<<"3.LIST OF ISSUED BOOK";
gotoxy(15,14);
cout<<"4.LIST OF RETURN BOOK";
gotoxy(4,18);
cout<<"************************************************************************";
gotoxy(20,24);
cout<<"<0>FOR RETURN";
gotoxy(20,20);
cout<<"Enter your choice:";
ch=getch();
clrscr();
switch(ch)
{
case '0':
library();
break;
case '1':
{
book_issue();
break;
}
case '2':
{
book_return();
break;
}
case '3':
{
list_issue_book();
break;
}
case '4':
list_return_book();
}
}


void library::book_issue()
{
a:
clrscr();
char c;
gotoxy(16,3);
cout<<"BOOK ISSUE ";
gotoxy(4,4);
cout<<"************************************************************************";
ifstream f1;
f1.open("book.dat",ios::in);
f1.seekg(0L,ios::beg);
gotoxy(8,5);
cout<<"Date:-";
gotoxy(8,7);
cout<<"BOOK NUMBER:-";
int no;
cin>>no;
int flag=found(no);
if (flag ==1)
{
	goto a;
 }


while(f1.read((char *)&s,sizeof(s)))
{
if(no==s.book_no)
{
s.book_no=no;
gotoxy(8,9);
cout<<"BOOK TITLE:-";
cout<<s.book_title;
gotoxy(8,11);
cout<<"AURTHER NAME:-";
cout<<s.aname;
gotoxy(8,13);
cout<<"PUBLISHER NAME:-";
cout<<s.pname;
gotoxy(8,15);
cout<<"PRICE:-";
cout<<s.price;
gotoxy(8,17);
cout<<"NUMBER OF PAGE:-";
cout<<s.page_no;
gotoxy(8,19);
cout<<"MEMBERSHIP NUMBER:-";
int m_no;
cin>>s.mem_no;
gotoxy(8,21);
cout<<"ROLL:-";
cin>>s.roll;
gotoxy(8,23);
cout<<"CLASS:-";
cin>>s.clas;
gotoxy(8,25);

cout<<"SAVE(Y/N):-";

cin>>c;
break;
}

}

if(c=='y')
{
file.open("is.dat",ios::app|ios::out);
file.seekp(0L,ios::end);
file.write((char *)&s,sizeof(s));
file.close();
f1.close();
}
else
{
clrscr();
file.close();
f1.close();
}
clrscr();
book_issue_return();
}
int library::found(int a)
{
fstream f1;
int flag=0;
f1.open("is.dat",ios::in);
file.seekg(0L,ios::beg);
while(f1.read((char *)&s,sizeof(s)))
{
if(a==0)
break;
if(a==s.book_no)
{
gotoxy(20,24);
flag=1;
cout<<"book are allready issued";
gotoxy(20,25);
cout<<"please enter '0' in book number to return back:";
getch();
}

}
f1.close();
return(flag);
}



void library::book_return()
{
clrscr();
int m_no;
int no;
gotoxy(16,3);
cout<<"BOOK  RETURN";
gotoxy(4,4);
cout<<"************************************************************************";
file.open("is.dat",ios::in);
file.seekg(0L,ios::beg);
gotoxy(8,5);
cout<<"Date:-";
gotoxy(8,6);
cout<<"MEMBERSHIP NUMBER:-";
cin>>m_no;
gotoxy(8,8);
cout<<"BOOK NUMBER:-";
cin>>no;
while(file.read((char *)&s,sizeof(s)))
{
if(no==s.book_no && m_no==s.mem_no)
{
gotoxy(8,9);
cout<<"BOOK TITLE:-";
cout<<s.book_title;
gotoxy(8,11);
cout<<"AURTHER NAME:-";
cout<<s.aname;
gotoxy(8,13);
cout<<"PUBLISHER NAME:-";
cout<<s.pname;
gotoxy(8,15);
cout<<"PRICE:-";
cout<<s.price;
gotoxy(8,17);
cout<<"NUMBER OF PAGE:-";
cout<<s.page_no;
gotoxy(8,21);
cout<<"ROLL:-";
cout<<s.roll;
gotoxy(8,23);
cout<<"CLASS:-";
cout<<s.clas;

}
}
file.close();
gotoxy(15,24);
cout<<"RETURN(Y/N):-";
char c;
cin>>c;
if(c=='y')
{
	fstream temp;
	file.open("is.dat", ios::in);
	temp.open("TEMP.dat", ios::out);
	file.seekg(0, ios::beg);
	while (!file.eof())
	{
		file.read((char *)&s, sizeof(s));
		if (file.eof())
			break;
		if (s.book_no != no)
		{
			temp.write((char *)&s, sizeof(s));
		}
	}
	file.close();
	temp.close();
	file.open("is.dat", ios::out);
	temp.open("TEMP.dat", ios::in);
	temp.seekg(0, ios::beg);
	while (!temp.eof())
	{
		temp.read((char *)&s, sizeof(s));
		if (temp.eof())
			break;
		if (s.book_no != no)
			file.write((char *)&s, sizeof(s));
	}
	file.close();
	temp.close();
gotoxy(15,25);
cout<<"record deleted:";
getch();
clrscr();
book_issue_return();
}
else
{
clrscr();
file.close();
}
remove("temp.dat");
}

void library::list_issue_book()
{
int i=8;
clrscr();
gotoxy(16,3);
cout<<"LIST OF ISSUED BOOK";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(5,5);
cout<<"BOOK NO.   BOOK NAME   AURTHER NAME                     MEMBERSHIP NUMBER";
gotoxy(4,6);
cout<<"*************************************************************************";
file.open("is.dat",ios::in);
file.seekg(0L,ios::beg);
while(file.read((char *)&s,sizeof(s)))
{
gotoxy(7,i);
cout<<s.book_no;
gotoxy(15,i);
cout<<s.book_title;
gotoxy(30,i);
cout<<s.aname;
gotoxy(70,i);
cout<<s.mem_no;
i++;
if(i==25)
{
i=8;
gotoxy(20,24);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
gotoxy(16,3);
cout<<"LIST OF RETURN BOOK";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(5,5);
cout<<"BOOK NO.   BOOK NAME   AURTHER NAME                     MEMBERSHIP NUMBER";
gotoxy(4,6);
cout<<"*************************************************************************";

}
}
gotoxy(20,24);
cout<<"PRESS ANY KEY TO BACK";
file.close();
getch();
clrscr();
book_issue_return();
}


void library::list_return_book()
{
int i=8;
clrscr();
gotoxy(16,3);
cout<<"BOOKS ISSUE RETURN";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(5,5);
cout<<"BOOK NO.   BOOK NAME   AURTHER NAME                     MEMBERSHIP NUMBER";
gotoxy(4,6);
cout<<"*************************************************************************";
file.open("return.dat",ios::in);
file.seekg(0L,ios::beg);
while(file.read((char *)&s,sizeof(s)))
{
gotoxy(7,i);
cout<<s.book_no;
gotoxy(15,i);
cout<<s.book_title;
gotoxy(30,i);
cout<<s.aname;
gotoxy(70,i);
cout<<s.mem_no;
i++;
if(i==25)
{
i=8;
gotoxy(20,24);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
clrscr();
gotoxy(16,3);
cout<<"BOOKS ISSUE RETURN";
gotoxy(4,4);
cout<<"************************************************************************";
gotoxy(5,5);
cout<<"BOOK NO.   BOOK NAME   AURTHER NAME                     MEMBERSHIP NUMBER";
gotoxy(4,6);
cout<<"*************************************************************************";

}
}
gotoxy(20,24);
cout<<"PRESS ANY KEY TO BACK";
file.close();
getch();
clrscr();
book_issue_return();
}

//********************** main menu ******************************

class main_menu:library
{
 public:
 main_menu()
 {
  date d;
  getdate(&d);
  int year=d.da_year;
  if(year>=2019)
  {
   cout<<"some files are missing or deleted in your software please check:";
   cout<<endl<<"press any key:";
   getch();
   exit(0);
  }
 }
 void representation();


 void list()
 {
  char ch;
  do
  {
   clrscr();
   gotoxy(16,2);
   cout<<"MAIN MENU OF COLLEGE SYSTEM";
   gotoxy(4,3);
   cout<<"**********************************************************************";
   sysdate();
   gotoxy(20,6);
   cout<<"1.COURSE LIST";
   gotoxy(20,8);
   cout<<"2.STUDENT LIST";
    gotoxy(20,10);
   cout<<"3.FEE RECORD";
   gotoxy(20,12);
   cout<<"4.EXAMINATION DEPARTMENT";
   gotoxy(20,14);
   cout<<"5.EMPLOYEE RECORD";
   gotoxy(20,16);
   cout<<"6.LIBRAARY SYSTEM";
   gotoxy(4,19);
   cout<<"**********************************************************************";
   gotoxy(20,24);
   cout<<"<0>FOR EXIT PROGRAM";
   gotoxy(30,22);
   cout<<"ENTER YOUR CHOICE:";
   ch=getch();
  switch(ch)
  {
  case '0':
    exit(0);
  case '1':
    course_menu();
    break;
  case '2':
    student_menu();
    break;
  case '3':
    fee_menu();
    break;
  case '4':
    examination();
     break;
  case '5':
    employee();
    break;
  case '6':
    library_menu();
    break;
  }
  }while(ch);
 }
};


void main_menu::representation()
{

 int gd=DETECT,gm;
 initgraph(&gd,&gm,"../bgi");
  int l=getmaxx()/2-10,t=getmaxy()/2-5,r=getmaxx()/2+10,b=getmaxy()/2+5;
	 while(l<=625 && b<=470)
	 {
	 cleardevice();	  setfillstyle(8,4);	bar(l-10,t-8,r+10,b+8);
			  setfillstyle(8,1);	bar(l,t,r,b);          		  delay(100);
		  l-=16;t-=12;r+=16;b+=12;
	 }
	 setlinestyle(2,4,1);
     //  Designing of corner
	 setcolor(3);	  setfillstyle(8,3);	pieslice(21,18,270,360,50);
			  setfillstyle(8,3);    pieslice(617,18,270,180,50);

     // outline boundry
	 setcolor(12);		 		rectangle(l+5,t+2,r-5,b-2);
	 setcolor(11);				rectangle(l+16,t+12,r-16,b-12);	  sleep(1);
     //  sepretor
			  setfillstyle(10,3);	bar(22,410,617,423);	  	  delay(200);
     //  designing of symbol
	 setcolor(11);	  setfillstyle(0,4);	rectangle(80,150,200,300);

	setcolor(11);	  setfillstyle(10,4);	line(90,100,190,100);
	setcolor(11);	  setfillstyle(10,4);	line(90,100,50,170);
	setcolor(11);	  setfillstyle(10,4);	line(190,100,230,170);
	setcolor(11);	  setfillstyle(10,4);	line(50,170,230,170);
	setcolor(11);	  setfillstyle(10,4);	line(200,250,250,250);
	setcolor(11);	  setfillstyle(10,4);	line(250,250,250,250);
	setcolor(11);	  setfillstyle(10,4);	line(50,350,250,350);
	setcolor(11);	  setfillstyle(10,4);	line(50,250,80,250);
	setcolor(11);	  setfillstyle(10,4);	line(50,250,50,350);
       setcolor(11);	  setfillstyle(10,4);	line(250,250,250,350);
	setcolor(11);	  setfillstyle(10,4);	line(160,260,160,300);
       setcolor(11);	  setfillstyle(10,4);	line(135,260,135,300);
     setcolor(11);	  setfillstyle(10,4);	line(135,260,160,260);
     setcolor(11);	  setfillstyle(10,4);	line(170,80,170,100);
	setcolor(11);	  setfillstyle(10,4);	line(160,80,160,100);
	setcolor(11);	  setfillstyle(10,4);	line(150,80,175,80);
	setcolor(11);	  setfillstyle(10,4);	line(165,60,155,80);
	setcolor(11);	  setfillstyle(10,4);	line(165,60,180,80);


     //  Title
	 char* a[4]={"WELCOME","TO", "COLLAGE MANAGEMENT","SYSTEM"};
	 int x[4]={330,390,250,330};
	 int y[4]={210,250,280,310};
	 setcolor(11);
	 for(int i=0;i<4;i++)
	 {
			  settextstyle(1,0,5);           	   		  sleep(1);
	    if(i==1||i==2)
			  settextstyle(1,0,4);
			  outtextxy(x[i],y[i],a[i]);
	 }
						rectangle(21,409,617,424);
     //  processbar
			  setfillstyle(2,4);
	 for(i=21;i<598;i++)
	 {
						bar(i,410,i+20,423);		  delay(20);
	 }
	 setcolor(11);			  	rectangle(l+5,t+2,r-5,b-2);
	 setcolor(9);		       		rectangle(l+16,t+12,r-16,b-12);
	 setcolor(4);	  	 		pieslice(21,18,270,360,50);
						pieslice(617,18,270,180,50);
     //  Status              fonr_names
	 setcolor(11);    settextstyle(1,0,1);
			  outtextxy(150,430,"<<--* PRESS ANY KEY FOR NEXT *-->>");   getch();
     //  ending of welcome page
       while(l<(getmaxx()/2-10) && b>(getmaxy()/2+5))
       {
	 cleardevice();	  setfillstyle(8,1);    bar(l,t,r,b);
			  setfillstyle(8,4);    bar(l+10,t+8,r-10,b-8);   delay(100);
			  l+=16;t+=12;r-=16;b-=12;
       }
	delay(100);
	cleardevice();
	closegraph();

     }
     void password()
 {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"../bgi");
	cleardevice();
	char uid[15],*pass;
	 setcolor(12);		 		rectangle(10,8,628,470);
	setcolor(11);				rectangle(26,18,617,460);	  sleep(1);
	settextstyle(1,0,4);
	outtextxy(40,100,"USER AUTHORIZATION CHECK SCREEN");
	settextstyle(1,0,1);
	outtextxy(50,130,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	settextstyle(1,0,3);
	outtextxy(200,210,"USER ID:");
	outtextxy(200,240,"PASSWORD:");

	x:
	gotoxy(45,15);
	cin>>uid;
	gotoxy(45,17);
	pass=getpass("   ");
	if(strcmp(uid,"priee")==0 && strcmp(pass,"BCAIII")==0)
	{
	gotoxy(35,22);
	cout<<"Authorized user";
	sleep(2);
	gotoxy(35,22);
	cout<<"                    ";
	main_menu mm;
	mm.representation();
	 mm.list();
	}
	else
	{
	gotoxy(35,22);
	cout<<"Unauthorized User";
	sleep(2);
	gotoxy(35,22);
	cout<<"                    ";
	gotoxy(45,15);
	cout<<"       ";
	gotoxy(45,17);
	cout<<"         ";
	goto x;
	}
	cleardevice();
	closegraph();
	}



 void main()
 {
     clrscr();
     password();
	clrscr();
 }

