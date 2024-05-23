/* 
az satr va sotoone 1 shoroo mikonad. esme har satri ke dar arayeye s[] bashad, barresi mishavad.
aval sotoonhaye satre 1 barresi mishavad (choon 1 ra dar arayeye komaki gozashteeim).
har sotooni ke ba 1 dar ertebat bashad, agar dar arraye nabashad, dar aan neveshte mishavad.
be soraghe satre badi miravim. in satr dar sooraty barresy mishavad, ke naame aan dar araye bashad. 
vagarne be soraghe badi miravim. ta jayi ke halghe tamam shavad. haal agar tedade azaaye araye barabar ba 
v_num bashad, hamband ast , vagarna , naa hamband ast.
((check kardane ertebaat dashtane ro'ous ra be soorate 1 taabe benivisam))
*/

int hamband(){
	int p,j=0,s[v_num];
	for (int k=1;k<=v_num+1;k++){
		p=0;s[0]=1;
		if (findvertex(s[v_num],k)==1){
		for(int l=1;l<=v_num+1;l++){
			if (matrix[((k-1)*v_num)+l]==1){
			p=1;
			if (findvertex(s[v_num],k)==0) {
				s[j]=k;
				j=j+1;
			}
			if (findvertex(s[v_num],l)==0) {
				s[j]=l;
				j=j+1;
			}
			}
		}
		}
		if (p==0) return (0);
	}
	if (j==v_num-1) return (1); else return (0);

}

//.....................................................

//searche 1 char ya int dar yek arrayeye int ya char...

int findvertex(int s[],int v_num,int vert){
for (int i=0;i<=v_num;i++)
if (s[i]==vert) return (1);
return (0);
}

//.........................................................

/* 2 bakhshi va 2 bakhshie kaamel :
az satre aval barresi mikonad ke ba kodam sotoon ertebat darad. agar ba hich sotooni nadashte bashad (p=0) , dar 
yek arraye rikhte mishavad. amma agar dashte bashad, be in soorat barresi mishavad : agar naame satr dar a[] bashad, 
sotoone marboote dar b[] rikhte mishavad. agar dar b[] bashad, sotoon dar a[] rikhte mishavad, va agar naame satr, 
mojoood nabashad, be soraghe naame sotoon miravim va hamin kar ra mikonim.... va agar hich kodam dar araye nabashad,
yeki ra dar a[] va digary ra dar b[] mirizim. dar nahayat check mishavad ke ozvi az a[] dar b[] hast ya na.. ke agar bashad,
0 bar migardad , yani do bakhshi nist. vagarna 1 bar migardad , yani do bakhshi ast.
*/
int twopart(){
	int j=0,i=0,a[v_num],b[v_num];
	for (int k=1;k<=v_num+1;k++){
	p=0;
		for(int l=1;l<=v_num+1;l++){
			if (matrix[((k-1)*v_num)+l]==1){
			p=1;
			if (findvertex(a[v_num],k)==1) {
			b[j]=l;
			j=j+1;
			} else
			if (findvertex(b[v_num],k)==1) {
			a[i]=l;
			i=i+1;
			} else
			if (findvertex(a[v_num],l)==1) {
			b[j]=k;
			j=j+1;
			} else
			if (findvertex(b[v_num],l)==1) {
			a[i]=k;
			i=i+1;
			} else {
			a[i]=k;
			b[j]=l;
			i=i+1;
			j=j+1;
			}
			}
		}
		if (p==0) {
		a[i]=k;
		i=i+1;
		}			
	}
	for (i=0;i<=length(a);i++) {
		if (findvertex(b[v_num],a[i])==1) return (0);
		else return (1); 
	}
}

//..............................................................................

/* do bakhshiye kaamel :
bayad do bakhshi boode va darajeye har ras az a[] barabare lenght(b) va bar ax bashad. 
*/

int k_towpart() {
if (twopart()==0) return (0);

}

//..............................................................................