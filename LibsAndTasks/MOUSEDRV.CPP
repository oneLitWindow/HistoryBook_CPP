
	#include <iostream.h>
	#include <dos.h>
	#include <conio.h>
	#include <stdlib.h>
//	#include "mouse.h"
		class mouse{
			//mouse();
			public:
				void install(); //  ‘õ÷ ö‘îõ ö¢¢ ö‘ª÷ ø  §ø‘õ ùõ‘÷¤“ ’¬÷
				void show (void );  // ‘õ÷ ö‘îõ ö¢¢ ö‘ª÷
				void hide (void );  // ‘õ÷ ö‘îõ  ö¢¤î üê¡õ
				int  getx (void );  //   ‘õ÷ ö‘îõ öø—¨ ñŸõ
				int  gety (void );  //   ‘õ÷ ö‘îõ ¤¯¨ ñŸõ
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
				//     ¢øª÷ ñ‘¨¤ ü¤—õ¤‘• œşû §ø‘õ ¤‘ş—¡ ¤¢
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
		regs.x.ax = 00;  /*     ùêìø ù¤‘õª */
		int86(0x33, &regs, &regs);
		show();
//		cout << "Mouse Installed ...\n"  //   §ø‘õ ù¢÷÷¢¤ğ ¢¤øõ ¤¢ ü—‘î÷
  //			 << "ax = " << regs.x.ax<<endl
	//		 << "bx = "<< regs.x.bx;
	} // install
 /*********************************************************************/
	void mouse::show( void ) {     //  ‘õ÷ ö‘îõ ö¢¢ ö‘ª÷
		regs.x.ax = 01;   /*     ùêìø ù¤‘õª */
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
		column = (regs.x.cx / 8 ) + 1 ; //  öø—¨ ù“ ñ¨îş• ñş¢“—
		return column;
	} // getx
 /*********************************************************************/
	int mouse::gety( void ) {     //  ‘õ÷ ö‘îõ ¤¯¨ ö—ê¤ğ
		int row;
		regs.x.ax = 03;  /*     ùêìø ù¤‘õª */
		int86(0x33, &regs, &regs);
		row = (regs.x.dx / 8 ) + 1 ;   //  ¤¯¨ ù“ ñ¨îş• ñş¢“—
		return row;
	} // getx
 /*********************************************************************/
	void mouse::setplace(int column, int row){
		regs.x.ax = 04;
		regs.x.cx = (8*column)+1;     //   öø—¨ ø ¤¯¨ ¥ ¢¢ä ñş¢“—
		regs.x.dx = (8*row) +1;       //   ñ¨îş• ù“
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
	// 0 ¤¢ìõ ù÷¤ğø ¢¢¤ğ üõ ¤“ 1 ¤¢ìõ ¢ª‘“ ‘ó‘“  –¨¤ ùùõî¢ ¤ğ
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
	void mouse::win ( int a = 0 , int b = 0  , int c = 80 , int d = 25 ){
		//    ü¢øõä ù¢ø¢Ÿõ ü¤“ 8  â“‘— ø üìê ù¢ø¢Ÿõ ü¤“ 7  â“‘—
		//    ¢øª÷ ñ‘¨¤ ¤—õ¤‘• öø÷ä ù“ ü¢¢ä œşû ùî ü—¤ø¬ ¤¢
		// ¢øª üõ  §ø‘õ ù¢ø¢Ÿõ ©ş‘õ÷ ùŸê¬ ñî
		a = (a*8 ) + 1;
		b = (b*8 ) + 1;
		c = (c*8 ) + 1;
		d = (d*8 ) + 1;
		regs.x.ax = 07 ; //    â“‘— ù¤‘õª
		regs.x.cx = a ; //   üìê öşş‘• ¢Ÿ
		regs.x.dx = c ; //  üìê ü‘ó‘“ ¢Ÿ
		int86 (0x33 , &regs, &regs);

		regs.x.ax = 8 ; //    â“‘— ù¤‘õª
		regs.x.cx = d ; //    ü¢øõä öşş‘• ¢Ÿ
		regs.x.dx = b ; //   ü¢øõä ü‘ó‘“ ¢Ÿ
		int86 (0x33 , &regs, &regs);
	} // win
  /*********************************************************************/
	void mouse::speed (int x = 8, int y = 16){
		regs.x.ax = 15;
		regs.x.cx = x; //   üìê üîşõ ¢¢ã—
		regs.x.dx = y; //   ü¢øõä üîşõ ¢¢ã—
		int86(0x33, &regs, &regs);
	} // speed
  /*********************************************************************/