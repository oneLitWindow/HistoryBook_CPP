/* Persian font in Graphical screen.
   This program is generated by Amin Safinejad,
   available on http://Tetta.5u.com (my Website!)
   Mailto: Amin1986@gmail.com

   Selected persian fonts: Sina Bold <<<<< only this font is available now.
			   Titr Bold
			   Bulb
	List of all available fonts (taken from Zarnegar76 (C)):
	AVLB.CHR   AVLR.CHR   BBD.CHR    BDRR.CHR   BNFI.CHR   BNKB.CHR   BOLD.CHR
	BRDB.CHR   BRDR.CHR   BRG.CHR    BRSX.CHR   BT1R.CHR   BT2R.CHR   BT3R.CHR
	C.CHR      COMB.CHR   COMR.CHR   COPB.CHR   CPTB.CHR   CPUR.CHR   CRCB.CHR
	CRCR.CHR   CRNR.CHR   CTGR.CHR   DAPR.CHR   DCLB.CHR   EURO.CHR   FUTI.CHR
	GEOR.CHR   GHRB.CHR   GOTH.CHR   HERR.CHR   HLVB.CHR   HLVX.CHR   HMMB.CHR
	HOLR.CHR   HOMB.CHR   HOUR.CHR   IRLR.CHR   JADH.CHR   KDKB.CHR   KEYR.CHR
	KLAB.CHR   KLAR.CHR   KMM.CHR    KMN.CHR    KRMB.CHR   LCOM.CHR   LITT.CHR
	LNSR.CHR   LTKB.CHR   LTKR.CHR   MHRB.CHR   MODH.CHR   MOTB.CHR   PDSR.CHR
	PHTR.CHR   PLGR.CHR   PNGB.CHR   PRSB.CHR   PRSR.CHR   RFWR.CHR   ROYB.CHR
	ROYR.CHR   SANS.CHR   SCRI.CHR   SHLR.CHR   SIMP.CHR   SINB.CHR   TAMB.CHR
	TCHR.CHR   TITB.CHR   TMPB.CHR   TMSB.CHR   TMSR.CHR   TMSX.CHR   TRFB.CHR
	TRFH.CHR   TRFR.CHR   TRIP.CHR   TSCR.CHR   TYPB.CHR   WDGR.CHR   YAGR.CHR
	YASB.CHR   YASR.CHR   YSMB.CHR   ZAKR.CHR   ZARB.CHR   ZARJ.CHR   ZURR.CHR

	titrnew = titb
	sina    = sinb  <<<<< this font is available now
	prince  = plgr

	bulb    = CTGR
	titr    = yasb
	homanew = homb
	homa    = brdb
	trafic  = trfh
	italic  = klab
	straight= motb
	tehran  = yasr
	jadid   = jadh
	fantasy = lnsr
	roya    = royr
	kids    = tchr
	arial   = avlr
	kamran  = brdr
	modern  = crnr

	clara   = klar
	titrnew = titb
	traffic2= trfr
	tehran  = yasr
	electral= pngb
	boldest = tmpb
	fantait = brsx
	jadid   = jadh
	straight= motb
	zar     = zarb

	...No rights reserved!... */

#include <iostream.h>
#include <process.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void main(void)
{
   int driver=DETECT,mode=2,myfont;
   initgraph(&driver, &mode, ""); // Where is your Graphic driver?
				  // driver is: egavga.bgi

   if (graphresult() != grOk) { //  ---> if graph was not inisialized
      printf("\n\rGraphics error! check your Bgi files!");
      printf("\n\rFile: egavga.bgi needed!");
      printf("\n\n\rPress any key to Exit...");
      getch();
      exit(1);} // ---> Exit program!

   myfont=installuserfont("sinb");
   settextstyle (myfont,0,1);
   setcolor (10);
   outtextxy (0,0,"pA �nB�");
   outtextxy (0,35,"jAs��� ���A");

getch();
closegraph();
}