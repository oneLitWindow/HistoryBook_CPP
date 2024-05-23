program DOCTOR;
uses crt,GRAPH;
type
arrays=record
n:array [1..10] of integer;
s:array [1..10] of string ;
c:array [1..03] of char   ;
end;
function per(s1:string) : string;
var
a:arrays;
per2,per1:string;
begin
per1:='';
for a.n[1]:=1 to length(s1) do
begin
a.s[1]:=copy (s1,a.n[1],1);
per2:=a.s[1];
if a.s[1]='' then per2:='1';
if a.s[1]='‚' then per2:='2';
if a.s[1]='ƒ' then per2:='3';
if a.s[1]='„' then per2:='4';
if a.s[1]='…' then per2:='5';
if a.s[1]='†' then per2:='6';
if a.s[1]='‡' then per2:='7';
if a.s[1]='ˆ' then per2:='8';
if a.s[1]='‰' then per2:='9';
if a.s[1]='€' then per2:='0';
if a.s[1]='•' then per2:='P';
if a.s[1]='”' then per2:='O';
if a.s[1]='*' then per2:='#';
if a.s[1]='Š' then per2:=',';
if a.s[1]='®' then per2:='‚';
if a.s[1]='­' then per2:='';
if a.s[1]='™' then per2:='X';
if a.s[1]='˜' then per2:='W';
if a.s[1]='ì' then per2:='š';
if a.s[1]='ë' then per2:='™';
if a.s[1]='ê' then per2:='–';
if a.s[1]='é' then per2:='•';
if a.s[1]='è' then per2:='“';
if a.s[1]='å' then per2:='';
if a.s[1]='ç' then per2:='’';
if a.s[1]='æ' then per2:='‘';
if a.s[1]='ä' then per2:='';
if a.s[1]='á' then per2:='Œ';
if a.s[1]='ã' then per2:='';
if a.s[1]='â' then per2:='';
if a.s[1]='û' then per2:='´';
if a.s[1]='ù' then per2:='²';
if a.s[1]='¡' then per2:='h';
if a.s[1]=' ' then per2:='f';
if a.s[1]='Ÿ' then per2:='d';
if a.s[1]='' then per2:='b';
if a.s[1]='›' then per2:='\';
if a.s[1]='š' then per2:='Z';
if a.s[1]='' then per2:='a';
if a.s[1]='œ' then per2:='_';
if a.s[1]='ª' then per2:='z';
if a.s[1]='©' then per2:='y';
if a.s[1]='¨' then per2:='v';
if a.s[1]='§' then per2:='u';
if a.s[1]='ş' then per2:='¼';
if a.s[1]='ü' then per2:='»';
if a.s[1]='ı' then per2:='º';
if a.s[1]='“' then per2:='L';
if a.s[1]='’' then per2:='K';
if a.s[1]='ó' then per2:='¦';
if a.s[1]='ñ' then per2:='¥';
if a.s[1]='ò' then per2:='À';
if a.s[1]='' then per2:='B';
if a.s[1]='' then per2:='D';
if a.s[1]='—' then per2:='T';
if a.s[1]='–' then per2:='S';
if a.s[1]='÷' then per2:='®';
if a.s[1]='ö' then per2:='­';
if a.s[1]='õ' then per2:='ª';
if a.s[1]='ô' then per2:='©';
if a.s[1]='à' then per2:='‰';
if a.s[1]='¯' then per2:='†';
if a.s[1]='¥' then per2:='q';
if a.s[1]='¤' then per2:='o';
if a.s[1]='£' then per2:='m';
if a.s[1]='¢' then per2:='k';
if a.s[1]='' then per2:='Ã';
if a.s[1]='' then per2:='¾';
if a.s[1]='ø' then per2:='±';
if a.s[1]='Œ' then per2:='?';
if a.s[1]='¦' then per2:='s';
per1:=per1+per2;
end;
per:=per2;
end;
VAR
N1,N2:INTEGER;
A:ARRAYS;

begin
a.n[1]:=installuserdriver('svga256',nil);
a.n[2]:=3;
initgraph (a.n[1],a.n[2],'');
n2:=installuserfont ('sinb.chr');
{n3:=installuserfont ('ctgr.chr');}
setbkcolor (10);
settextstyle (n2,0,3);
setcolor (100);
outtextxy ((getmaxx div 4)-30,gety,'! k½k«C x±i jAs¯»– ²qÄB—nTŸj K„« ³M');
a.s[1]:=per('! ¢ş¢õ ©ø¡ ¢¦÷üê¬ ù¥‘ê ¤—î¢ ’¯õ ù“');
setcolor (14);
outtextxy ((getmaxx div 4)-30,gety+50,a.s[1]);
readkey;
closegraph;
end.
