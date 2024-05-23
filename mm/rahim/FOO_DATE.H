char *dayname(int j){
switch (j){
case 0:return "Sunday   ";
case 1:return "Monday   ";
case 2:return "Tuesday  ";
case 3:return "Wednesday";
case 4:return "Thursday ";
case 5:return "Friday   ";
case 6:return "Saturday ";
}
return "none";
};

char *date(){
struct dosdate_t mydate;
_dos_getdate (&mydate);
int i=mydate.day;
char s[4]="",datestr[30]="",s1[10]="";
strcat (s1,dayname(mydate.dayofweek));
s1[3]='\0';
s1[2]=' ';
strcat (datestr,s1);
itoa(i           ,s,10); if (strlen (s)<2) {s[1]=s[0];s[0]='0';};strcat (datestr,s); strcat (datestr,"/");
itoa(mydate.month,s,10); if (strlen (s)<2) {s[1]=s[0];s[0]='0';};strcat (datestr,s); strcat (datestr,"/");
itoa(mydate.year ,s,10); strcat (datestr,s);
return datestr;
}
/*struct  time t;

gettime(&t);
printf("The current time is: %2d:%02d:%02d.%02d\n",
       t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
return 0;
*/
char *time(){
struct time mytime;
gettime (&mytime);
int i=mytime.ti_hour;
char s[4]="",timestr[30]="",s1[10]="";
int hour=mytime.ti_hour;
char flag=0;
if (hour>12) {hour=hour-12;flag=1;}
itoa(hour,s,10); if (strlen (s)<2) {s[1]=s[0];s[0]='0';};strcat (timestr,s); strcat (timestr,":");
itoa(mytime.ti_min,s,10);  if (strlen (s)<2) {s[1]=s[0];s[0]='0';};strcat (timestr,s); strcat (timestr,":");
itoa(mytime.ti_sec,s,10);  if (strlen (s)<2) {s[1]=s[0];s[0]='0';};strcat (timestr,s);
if (flag) strcat(timestr," PM"); else strcat(timestr," AM");
return timestr;
}
void showfulltime(){
char s[50]="";
settextjustify(2,0);
settextstyle (2,0,4);
strcat (s,time());
strcat (s," - ");
strcat (s,date());
setcolor(0);
setfillstyle (1,0);
bar (getmaxx()-(getmaxx()/32)*2-3-textwidth(s),getmaxy()-(getmaxx()/32)*2-textheight(s)-4,getmaxx()-(getmaxx()/32)*2-3,getmaxy()-(getmaxx()/32)*2-7);
setcolor(16);
outtextxy (getmaxx()-(getmaxx()/32)*2-3,getmaxy()-(getmaxx()/32)*2-7,s);
}

/*char s1[13]="";
strcpy (s1,date());
cprintf ("%s",s1);*/
