/*/////////////////////////////*
* Program by A.S.              *
* http://tetta.5u.com          *
* === Do not duplicate!!! ===  *
*//////////////////////////////*
#include "malloc.h"
#include "iostream.h"
#include "conio.h"
#include "process.h"
//===========================================================================
int *A,*B;
int *temp1,*temp2;
int *D,*E;
int m, n;
//===========================================================================
void PrintMatrix(int isreverse )
{
 int i, j,k;
 k = n / 2;
 for( i = 1; i <= m; i++ )
 {
  cprintf("\n\r");
  for( j = 1; j <= n; j++)
   if ((isreverse&&(j>k))||((!isreverse)&&(j<=k)))
	cprintf ("%8.3f ", float (A[((i-1)*n)+j]) / float(B[((i-1)*n)+j]));
 }
}
//===========================================================================
int MinRange( void )
{
 int n1 = n;
 if( m < n1 )
  return m;
 return n1;
}
//===========================================================================
void ChengeRow( int k, int t )
{
 int i;
 for( i = 1; i <= n; i++ )
 {
  temp1[i] = A[((k-1)*n)+i];
  temp2[i] = B[((k-1)*n)+i];

  A[((k-1)*n)+i] = A[((t-1)*n)+i];
  B[((k-1)*n)+i] = B[((t-1)*n)+i];

  A[((t-1)*n)+i] = temp1[i];
  B[((t-1)*n)+i] = temp2[i];
 }
}
//===========================================================================
void G_J( void )
{
 int i, j, k, t, Min;
 Min = MinRange();
 for( k = 0; k < Min; k++ )
 {
  t = k + 1;
  do
  {
   if( ( A[(k*n)+k+1] == 0 ) && ( t < m ) )
    ChengeRow( k, t++ );
   else if( A[(k*n)+k+1] == 0 )
   {
	    textcolor(12);
	    cprintf ("\n\n\rSorry, Determinan is zero!\a\a\n\r");
	    return;
   }
  }
  while( A[(k*n)+k+1] == 0 );
  for( j = n-1; j >k ; j-- )
  {
   A[(k*n)+j+1] = A[(k*n)+j+1] * B[(k*n)+k+1];
   B[(k*n)+j+1] = B[(k*n)+j+1] * A[(k*n)+k+1];
  }
  A[(k*n)+k+1] = B[(k*n)+k+1] = 1;
  for( i = 0; i < m; i++ )
  {
   if( i != k )
   {
    for( j = k + 1; j < n; j++ )
    {
     A[(i*n)+j+1] = ( A[(i*n)+j+1] * B[(k*n)+j+1] * B[(i*n)+k+1] ) - ( B[(i*n)+j+1] * A[(k*n)+j+1] * A[(i*n)+k+1] );
     B[(i*n)+j+1] =   B[(i*n)+j+1] * B[(k*n)+j+1] * B[(i*n)+k+1];
    }
   }
  }
  for( i = 0; i < m; i++ )
  {
       if( i != k )
   {
    A[(i*n)+k+1] = 0;
    B[(i*n)+k+1] = 1;
   }
  }
 }
  cout << "\n\nþ Matrix [A']:\n\n";
 PrintMatrix( 1 );
}

//===========================================================================
void ReadMatrix( void )
{
 int i, j;
 clrscr();
  cout << "Please matrix range: ";
  cin >> m;
      n = m;
     A=(int *) malloc (4*n*n);
     B=(int *) malloc (4*n*n);
 temp1=(int *) malloc (4*n*n);
 temp2=(int *) malloc (4*n*n);
   for( i = 1; i <= m; i++ )
   for( j = 1; j <= m*2; j++ ) {B[((i-1)*n*2)+j] = 1;A[((i-1)*n*2)+j]=0;}

   for( i = 1; i <= m; i++ )    A[((i-1)*n*2)+(i + 3)] = 1;
 textcolor(11);
 cprintf("\nEnter matrix [A] parameters (avval soorat, bad makhraj):\n\n\r");
 textcolor(14);
 cprintf(" i       j      Value\n\r");
 textcolor(15);
 for( i = 1; i <= m; i++ )
 {
  textcolor(9);
  cprintf ("\n\r==========================\n\r");
  textcolor(15);
  cout << "\n[" << ( i ) << "]";
  for( j = 1; j <= n; j++ )
   do
   {
    cout << "\t[" << ( j ) << "]\t";
    cin >> A[((i-1)*n*2)+j];
    cout << "\n\r\t\t /\n\t\t  ";
    cin >> B[((i-1)*n*2)+j];
    if( B[((i-1)*n*2)+j] == 0 ){
    textcolor(12);
    cprintf( "Error: Division bye zero!\n\r");}
    textcolor(15);
   }
   while( B[((i-1)*n*2)+j] == 0 );
 }
  n = 2 * m;
  clrscr();
  cout << "þ Matrix [A]:\n\n";
 PrintMatrix(0);
 getch();
 G_J();
}

//===========================================================================
void main( void )
{
 textmode(64);
 textcolor(10);
 ReadMatrix();
 getch();
}