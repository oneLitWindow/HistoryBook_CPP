/*

This Program has built by Amin Safinejad
and taken from Tetta.5u.com
some of hints and comments are in farsi, to read them
you can run farsi.com or vfarsi.exe from "DOS shell" command in "File" menu.
Download vfarsi.exe from Tetta.5u.com > Downloads > Dos downloads.

*/
		class mouse{
			//mouse();
			public:
				int x,y,xo,yo;
				int ii,jj;
				char co[10][10][2];
				void updatecursor();
				void install(); //  ‘õ÷ ö‘îõ ö¢¢ ö‘ª÷ ø  §ø‘õ ùõ‘÷¤“ ’¬÷
				void show (void );  // ‘õ÷ ö‘îõ ö¢¢ ö‘ª÷
				void hide (void );  // ‘õ÷ ö‘îõ  ö¢¤î üê¡õ
				int  getx (void );  //   ‘õ÷ ö‘îõ öø—¨ ñŸõ
				int  gety (void );  //   ‘õ÷ ö‘îõ ¤¯¨ ñŸõ
				int isin(int,int,int,int);
				//  ¢¤“ üõ Row   ¤¯¨ ø Clumn öø—¨ ù“ ¤ ‘õ÷ ö‘îõ
				void setplace(int column, int row );
				int prsleft( void );  // –¨¤ ø ” ü‘û ùõî¢ ö¢ª ù¢¤ªê –¤ø¬ ¤¢
				int prsright( void );//            §ø‘õ ¯¨ø ø
				int prsmid( void ); //     ¢÷÷¢¤ğ  üõ ¤“ ¤ 1 ¤ş¢‘ìõ
	   //***************************
				// ¢¢¤ğ üõ ¤“ 0 ù÷¤ğø 1 ¤¢ìõ ¢øª ‘û¤ §ø‘õ ” ùõî¢ ¤ğ
				int upleft( void );
	   //***************************
				// ¢¢¤ğ üõ ¤“ 0 ù÷¤ğø 1 ¤¢ìõ ¢øª ‘û¤ §ø‘õ –¨¤ ùõî¢ ¤ğ
				int upright( void );
	   //***************************
				//  §ø‘õ ù¢ø¢Ÿõ öşşã—
				//     ©ş‘õ÷ ùŸê¬ ñî ö¢¢ ¤¤ì ¤‘ş—¡ ¤¢ ü¤“
				//     ¢øª÷ ñ‘¨¤ ı¤—õ¤‘• œşû §ø‘õ ¤‘ş—¡ ¤¢
				void win(int upx, int upy, int downx, int downy);
	   //***************************
				//  §ø‘õ –ä¤¨ öşşã—
				//  ¢øª üõ ñ‘õä ­¤ê ©ş• –ä¤¨ ¢øª÷ ¢¤ø ü÷‘õøğ¤ œşû ¤ğ
				void speed(int x, int y );
	   //***************************

			private:
				union REGS regs;
		}; // Class Mouse

 /*********************************************************************/
 /************************** PUBLIC FUNCTION **************************/
 /*********************************************************************/
	void mouse::install( ) {      //   ùşóø ü¥¢÷ ù¤
for (ii=0;ii<10;ii++) for (jj=0;jj<10;jj++) co[jj][ii][0]=0;
x=0;y=0;xo=1;yo=1;
co[ 0][ 0][0]=1;
co[ 0][ 1][0]=1;
co[ 0][ 2][0]=1;
co[ 0][ 3][0]=1;
co[ 0][ 4][0]=1;
co[ 0][ 5][0]=1;
co[ 0][ 6][0]=1;
co[ 1][ 0][0]=1;
co[ 1][ 1][0]=1;
co[ 1][ 2][0]=1;
co[ 1][ 3][0]=1;
co[ 1][ 4][0]=1;
co[ 1][ 5][0]=1;
co[ 1][ 6][0]=1;
co[ 2][ 0][0]=1;
co[ 2][ 1][0]=1;
co[ 2][ 2][0]=1;
co[ 2][ 3][0]=1;
co[ 2][ 4][0]=1;
co[ 3][ 0][0]=1;
co[ 3][ 1][0]=1;
co[ 3][ 2][0]=1;
co[ 3][ 3][0]=1;
co[ 3][ 4][0]=1;
co[ 4][ 0][0]=1;
co[ 4][ 1][0]=1;
co[ 4][ 2][0]=1;
co[ 4][ 3][0]=1;
co[ 4][ 4][0]=1;
co[ 4][ 5][0]=1;
co[ 5][ 0][0]=1;
co[ 5][ 1][0]=1;
co[ 5][ 4][0]=1;
co[ 5][ 5][0]=1;
co[ 5][ 6][0]=1;
co[ 6][ 0][0]=1;
co[ 6][ 1][0]=1;
co[ 6][ 5][0]=1;
co[ 6][ 6][0]=1;
co[ 6][ 7][0]=1;
co[ 7][ 6][0]=1;
co[ 7][ 7][0]=1;
co[ 7][ 8][0]=1;
co[ 8][ 7][0]=1;
co[ 8][ 8][0]=1;
//co[8][1][0]=1;
/*
co[  ][  ][0]=1;
#   0 1 2 3 4 5 6 7 8 9
  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
0 ³ 1 1 1 1 1 1 1 0 0 0
1 ³ 1 1 1 1 1 1 1 0 0 0
2 ³ 1 1 1 1 1 0 0 0 0 0
3 ³ 1 1 1 1 1 0 0 0 0 0
4 ³ 1 1 0 1 1 1 0 0 0 0
5 ³ 1 1 0 0 1 1 1 0 0 0
6 ³ 1 1 0 0 0 1 1 1 0 0
7 ³ 0 0 0 0 0 0 1 1 1 0
8 ³ 0 0 0 0 0 0 1 1 0 0
9 ³ 0 0 0 0 0 0 0 0 0 0
*/
		regs.x.ax = 00;  /*     ùêìø ù¤‘õª */
		int86(0x33, &regs, &regs);
setplace(0,0);
for (ii=0;ii<10;ii++) for (jj=0;jj<10;jj++) if (co[jj][ii][0]) co[jj][ii][1]=getpixel(xo+ii,yo+jj);

		//cprintf ("Mouse Installed!");
//		show();
//		cout << "Mouse Installed ...\n";  //   §ø‘õ ù¢÷÷¢¤ğ ¢¤øõ ¤¢ ü—‘î÷
  //			 << "ax = " << regs.x.ax<<endl
	//	   	 << "bx = "<< regs.x.bx;
	} // install
 /*********************************************************************/
	void mouse::show( void ) {     //  ‘õ÷ ö‘îõ ö¢¢ ö‘ª÷
		regs.x.ax = 03;   /*     ùêìø ù¤‘õª */
		int86(0x33, &regs, &regs);
	} // show
 /*********************************************************************/
	void mouse::hide( void ) {     //  ‘õ÷ ö‘îõ ö¢¤î üê¡õ
		regs.x.ax = 02;  /*     ùêìø ù¤‘õª */
		int86(0x33, &regs, &regs);
	} // hide
 /*********************************************************************/
	int mouse::getx( void ) {     //  ‘õ÷ ö‘îõ öø—¨  ö—ê¤ğ
		int column;
		regs.x.ax = 03;  /*     ùêìø ù¤‘õª */
		int86(0x33, &regs, &regs);
		column = (regs.x.cx );// / 8 ) + 1 ; //  öø—¨ ù“ ñ¨îş• ñş¢“—
		return column;
	} // getx
 /*********************************************************************/
	int mouse::gety( void ) {     //  ‘õ÷ ö‘îõ ¤¯¨ ö—ê¤ğ
		int row;
		regs.x.ax = 03;  /*     ùêìø ù¤‘õª */
		int86(0x33, &regs, &regs);
		row = (regs.x.dx );// / 8 ) + 1 ;   //  ¤¯¨ ù“ ñ¨îş• ñş¢“—
		return row;
	} // getx
 /*********************************************************************/
	void mouse::setplace(int column, int row){
		regs.x.ax = 04;
		regs.x.cx = column;//(8*column)+1;     //   öø—¨ ø ¤¯¨ ¥ ¢¢ä ñş¢“—
		regs.x.dx = row;//(8*row) +1;       //   ñ¨îş• ù“
	// move coursor to ( column , row )
		int86(0x33, &regs, &regs );
	} // setplace
 /*********************************************************************/
	int mouse::prsleft( void ){
	// if LeftKey Pressed Return 1 Else Return 0
		regs.x.ax = 05; //        ùêìø ù¤‘õª
		regs.x.bx = 0;  //    §ø‘õ ” ùõî¢ ù¤‘õª
		int86(0x33, &regs, &regs );
		// test cout << endl << regs.x.ax;

		 if ((regs.x.ax == 1)    // let
			|| (regs.x.ax == 3)  // left & right
			|| (regs.x.ax == 5)  // left & mid
			|| (regs.x.ax == 7)   // left & right & mid
						)
			return 1; // press left
		else return 0; //no press
	} // prsleft
  /*********************************************************************/
	int mouse::prsright( void ){
	// if RightKey Pressed Return 1 Else Return 0
		regs.x.ax = 05; //        ùêìø ù¤‘õª
		regs.x.bx = 2;  //    §ø‘õ –¨¤ ùõî¢ ù¤‘õª
		int86(0x33, &regs, &regs );
		// test cout << endl << regs.x.ax;

		 if ((regs.x.ax == 2)    // right
			|| (regs.x.ax == 3)  // left & right
			|| (regs.x.ax == 6)  // right & mid
			|| (regs.x.ax == 7)   // left & right & mid
						)
			return 1; // press right
		else return 0; //no press
	} // prsright
  /*********************************************************************/
	int mouse::prsmid ( void ){
	// if MidKey Pressed Return 1 Else Return 0
		regs.x.ax = 05; //        ùêìø ù¤‘õª
		regs.x.bx = 2;  //    §ø‘õ ¯¨ø ùõî¢ ù¤‘õª
		int86(0x33, &regs, &regs );
		 if ((regs.x.ax == 4)    // mid
			|| (regs.x.ax == 5)  // left & mid
			|| (regs.x.ax == 6)  // right & mid
			|| (regs.x.ax == 7)   // left & right & mid
						)
			return 1; // press mid
		else return 0; //no press
	} // prsmid
  /*********************************************************************/
	int mouse::upleft ( void ){
	// 0 ¤¢ìõ ù÷¤ğø ¢¢¤ğ üõ ¤“ 1 ¤¢ìõ ¢ª‘“ ‘ó‘“  ” ùõî¢ ¤ğ
		regs.x.ax = 06; //        ùêìø ù¤‘õª
		regs.x.bx = 00;  //    §ø‘õ  ” ùõî¢ ù¤‘õª
		int86(0x33, &regs, &regs );
		if ((regs.x.ax == 0) //   –¨‘ó‘“‘û ùõî¢ ô‘õ— ¤ğ
			|| (regs.x.ax == 2 )        //   ‘ó‘“ –¨¤ ùõî¢
			|| (regs.x.ax ==  4 )       //  ‘ó‘“ ¯¨ø
			|| (regs.x.ax == 6 ))           // ¯¨ø ø –¨¤
			return 1;
		else return 0;          //  –¨ öşş‘• ùõî¢
	} // upleft
  /*********************************************************************/
	int mouse::upright ( void ){
	// 0 ¤¢ìõ ù÷¤ğø ¢¢¤ğ üõ ¤“ 1 ¤¢ìõ ¢ª‘“ ‘ó‘“  –¨¤ ùõî¢ ¤ğ
		regs.x.ax = 06; //        ùêìø ù¤‘õª
		regs.x.bx = 01;  //    §ø‘õ  –¨¤ ùõî¢ ù¤‘õª
		int86(0x33, &regs, &regs );
		if ((regs.x.ax == 0) //   –¨‘ó‘“‘û ùõî¢ ô‘õ— ¤ğ
			|| (regs.x.ax == 1 )       //  ‘ó‘“ ” ùõî¢
			|| (regs.x.ax == 4 )       //  ‘ó‘“ ¯¨ø
			|| (regs.x.ax == 5 ))      //   ¯¨ø ø  ”
			return 1;
		else return 0;          //  –¨ öşş‘• ùõî¢
	} // upleft
  /*********************************************************************/
	void mouse::win ( int a = 1 , int b = 1  , int c = 80 , int d = 25 ){
		//    ı¢øõä ù¢ø¢Ÿõ ı¤“ 8  â“‘— ø üìê ù¢ø¢Ÿõ ı¤“ 7  â“‘—
		//    ¢øª÷ ñ‘¨¤ ¤—õ¤‘• öø÷ä ù“ ı¢¢ä œşû ùî ü—¤ø¬ ¤¢
		// ¢øª üõ  §ø‘õ ù¢ø¢Ÿõ ©ş‘õ÷ ùŸê¬ ñî
		a = (a*8 ) -1;//+ 1;
		b = (b*8 ) ;//+ 1;
		c = (c*8 ) -1;//+ 1;
		d = (d*8 ) -1;//+ 1;
		regs.x.ax = 07 ; //    â“‘— ù¤‘õª
		regs.x.cx = a ; //   üìê öşş‘• ¢Ÿ
		regs.x.dx = c ; //  üìê ıò‘“ ¢Ÿ
		int86 (0x33 , &regs, &regs);

		regs.x.ax = 8 ; //    â“‘— ù¤‘õª
		regs.x.cx = d ; //    ı¢øõä öşş‘• ¢Ÿ
		regs.x.dx = b ; //    ı¢øõä ıò‘“ ¢Ÿ
		int86 (0x33 , &regs, &regs);
	} // win
  /*********************************************************************/
	void mouse::speed (int x = 8, int y = 16){
		regs.x.ax = 15;
		regs.x.cx = x; //   üìê üîşõ ¢¢ã—
		regs.x.dx = y; //   ı¢øõä üîşõ ¢¢ã—
		int86(0x33, &regs, &regs);
	} // speed
  /*********************************************************************/
	void mouse::updatecursor(){
	if (getx()+2>=(getmaxx()-(2*(getmaxx()/32)))) setplace (getmaxx()-(2*getmaxx()/32)-2,gety());
	if (gety()+2>=(getmaxy()-(2*(getmaxx()/32)))) setplace (getx(),gety()-(getmaxx()/64)+8);
	x=getx();
	y=gety();
	if ((x!=xo)||(y!=yo)){
	for (ii=0;ii<10;ii++) for (jj=0;jj<10;jj++) if (co[jj][ii][0]) putpixel (xo+ii,yo+jj,co[jj][ii][1]);
	xo=x;
	yo=y;
	for (ii=0;ii<10;ii++) for (jj=0;jj<10;jj++) if (co[jj][ii][0]) co[jj][ii][1]=getpixel (xo+ii,yo+jj);
	for (ii=0;ii<10;ii++) for (jj=0;jj<10;jj++) if (co[jj][ii][0]) putpixel (xo+ii,yo+jj,98+((20)-(ii+jj)));
	   }

	}

  /*********************************************************************/
    int mouse::isin(int x1,int y1,int x2,int y2){
    if ((getx()>=x1)&&(getx()<=x2)&&(gety()>=y1)&&(gety()<=y2)) return 1;
    return 0;
}
