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
