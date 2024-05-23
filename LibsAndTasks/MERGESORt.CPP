# include <iostream.h>
# include <fstream.h>
# include <conio.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int main(){
	   clrscr();
	   int i,j,k,l,counter,truef1,truef2,trueg1,trueg2,d,x;
	   char ch;
	   char b1[11];
	   char b2[11];
	   ofstream f("input.in",ios::in);
	   if (!f){
		     cout<<"cannot open gile.";
		     exit(0);
		  }
	   cout<<"enter numbers & separate them with ','& then press enter.\n";
	   while((ch=cin.get())!='\r'){
		     cin.get(ch);
		     f.put(ch);
		     }
	   f.close();
	   fstream f1("f1.dat",ios::in,ios::out);
	   if (!f1){
		     cout<<"cannot open file.";
		     exit(0);
		   }
	   fstream f2("f2.dat",ios::in,ios::out);
	   if (!f2){
		     cout<<"cannot open file.";
		     exit(0);
		  }
	   ifstream f3("input.in",ios::out);
	   if (!f3){
		      cout<<"cannot open file.";
		      exit(0);
		   }
	   ofstream output("output.in",ios::in);
	   while (!f3.eof()){
		      counter=0;
		      truef1=1;
		      truef2=0;
		      while ((ch=f3.get())!='\n'){
				  if (truef1){
					    while ((ch=f3.get())!=','){
						      f3.get(ch);
						      f1.put(ch);
						      }
					    counter++;
					    }
				  if (truef2){
					    while ((ch=f3.get())!=','){
						       f3.get(ch);
						       f2.put(ch);
						       }
					    counter++;
					    }
				  x=truef1;
				  truef1=truef2;
				  truef2=x;
				  }
		      i=1;
		      while((2^(i-1)<counter)){                //should change.
				  fstream g1("g1.dat",ios::in,ios::out);
				  fstream g2("g2.dat",ios::in,ios::out);
				  trueg1=1;
				  trueg2=0;
				  while (1){ //should change.
					    truef1 = 1;
					    truef2 = 0;
					    j=k=l=0;
					    while (j<=(2^i)){ //74
						      if (truef1){
								d=1;
								while((ch=f1.get())!=','){
									  f1.get(ch);
									  b1[d]=ch;
									  d++;
									  }
								}
						      if (truef2){
								d=1;
								while((ch=f2.get())!=','){
									  f2.get(ch);
									  b2[d];
									  d++;
									  }
								}
						      if((strcmp(b1,b2))>=0){
								if(trueg1)
									  g1>>b2;
								if(trueg2)
									  g2>>b2;
								k++;
								truef1=0;
								truef2=1;
								}
						      if ((strcmp(b1,b2))<0){
								if (trueg1)
									  g1>>b1;
								if(trueg2)
									  g2>>b1;
								l++;
								truef2=0;
								truef1=1;
								}
						      j++;
						      if(k=2^(i-1)){
								if(trueg1){
									  g1>>b1;
									  while((ch=f1.get())!='\n'){
										    d=1;
										    while((ch=f1.get())!=','){
											      f1.get(ch);
											      b1[d];
											      d++;
											      }
											      g1>>b1;
											      }
										    }
								if(trueg2){
									  g2>>b1;
									  while((ch=f1.get())!='\n'){
										    d=1;
										    while((ch=f1.get())!=','){
											      f1.get(ch);
											      b1[d];
											      d++;
											      }
											      g2>>b1;
											      }
										    }
								break;
								}
						      if(l=2^(i-1)){
								if(trueg1){
									   g1>>b2;
									  while((ch=f2.get())!='\n'){
										    d=1;
										    while((ch=f2.get())!=','){
											      f2.get(ch);
											      b1[d];
											      d++;
											      }
											      g2>>b2;
											      }
										    }
								if(trueg2){
									  g2>>b2;
									  while((ch=f2.get())!='\n'){
										    d=1;
										    while((ch=f2.get())!=','){
											      f2.get(ch);
											      b1[d];
											      d++;
											      }
											      g2>>b2;
											      }
										    }
								break;
								}
						      if(f2.eof()){
								while(!f1.eof()){
									  d=1;
									  while((ch=f1.get())!=','){
										    f1.get(ch);
										    b1[d]=ch;
										    d++;
										    }
									  if(trueg1)
										    g1>>b1;
									  if(trueg2)
										    g2>>b1;
									  }
								break;
								}
						      if(f1.eof()){
								while(!f2.eof()){
									  d=1;
									  while((ch=f2.get())!=','){
										    f2.get(ch);
										    b2[d]=ch;
										    d++;
										    }
									  if(trueg1)
										    g1>>b2;
									  if(trueg2)
										    g2>>b2;
									  }
								break;
								}
						      }//73
					    x=trueg1;
					    trueg1=trueg2;
					    trueg2=x;
					    }//70
				  g1.close();
				  g2.close();
				  f1.close();
				  f2.close();
				  i++;
				  remove("f1.dat");
				  remove("f2.dat");
				  rename("g1.dat","f1.dat");
				  rename("g2.dat","f2.dat");
				  }//65
		      ifstream f1("f1.dat",ios::out);
		      while(!f1.eof()){
				  f1.get(ch);
				  output.put(ch);
				  }
		      f1.close();
		      }//42

	   output.close();
	   getch();
	   return 0;
	   }
