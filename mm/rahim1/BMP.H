typedef struct _Pixtyp {
 unsigned char red;
  unsigned char green;
   unsigned char blue;
   } Pixtyp, *PPixtyp;
   /*                  */
   typedef struct _Image {
    int lin;
     int col;
      Pixtyp *pix;
      } Image, *PImage;
      /*                  */
      typedef struct _Sequence {
       int ima;
	int lin;
	 int col;
	  PImage *img;
	  } Sequence, *PSequence;

	  //Let's read the ith image...

	      // it's up to you to allocate the sequence and ...
		   //
			CString m_sBitmap = ""/*the bitmap name*/;
			     // Load bitmap
				  HBITMAP hBitmap = (HBITMAP) ::LoadImage(AfxGetInstanceHandle(),
					m_sBitmap, IMAGE_BITMAP, 0, 0,
					      LR_LOADFROMFILE | LR_CREATEDIBSECTION);

						   if (hBitmap)
							{
							      CBitmap m_bmpBitmap;
								   // Create a CBitmap
									 m_bmpBitmap.Attach(hBitmap);

									       BITMAP bm;
										    // Get the Bitmap
											  m_bmpBitmap.GetBitmap(&bm);

												if(bm.bmBitsPixel==24)
												      // if it's 24 bits ...
													    {

														   int ligne = m_seq->lin;
															  int colonne = m_seq->col;
																 if((bm.bmWidth==colonne)&&(bm.bmHeight==ligne))
																	{

																		PPixtyp ptemp = m_seq->img[i]->pix;
																		      // a bit tricky ...
																			     // align within 32 bits
																				     int align = (4-((bm.bmWidth)%4)) & 3;
																					     int nbr_byte = bm.bmHeight * bm.bmWidth + align * bm.bmHeight/3;
																						     BYTE* pBits= (BYTE*) bm.bmBits + (ligne-1)*(3*colonne+align);

																							     for (int l=0;l<bm.bmHeight;l++)
																								     {
																									      for (int c=0;c<bm.bmWidth;c++)
																										       {
																												 ptemp->blue=*(pBits);
																													   ptemp->green=*(pBits+1);
																														     ptemp->red=*(pBits+2);
																															       ptemp++;
																																	 pBits=pBits+3;
																																		  }
																																			   pBits=pBits-align-2*3*colonne;

																																					   }
																																						  }
																																							 else
																																								{
																																									AfxMessageBox("Incompatible size !");
																																									       // do what's necessary ...
																																										      }
																																											    }
																																												  else
																																													{
																																													       AfxMessageBox("That's not 24-bits Bitmaps !");
																																														      // do what's necessary ...
																																															    }
																																																 }
																																																      else
																																																	   {
																																																		 AfxMessageBox("That's not correct Bitmaps !");
																																																		       // do what's necessary ...
																																																			    }
																																																			    Now it's raw struct so let's work on it.


																																																				Writing Raw in 24-bits BMP
																																																				All you need is a HDIB (see the next section).
																																																				The following function creates it from a PImage (see the last section).
																																																				first, you need a device context *pDC.

																																																				//////////////////////////////////////////////////////////////////////////
																																																				HDIB  ImaToDIB(CDC *pDC, PImage Ima)
																																																				{
																																																				 int ligne = Ima->lin;
																																																				  int colonne = Ima->col;

																																																				   // create bitmap
																																																				    // always the same trick, align/32 bits
																																																				     int align = (4-((colonne*3)%4)) & 3;

																																																				      // size of Bitmap
																																																				       int nbr_byte = ligne * colonne *3 + align * ligne;

																																																					// allocate Bitmap
																																																					 unsigned char *BitmapData = new (unsigned char[nbr_byte]);

																																																					  Pixtyp *ptemp = Ima->pix;
																																																					   BYTE* pBits= BitmapData;

																																																					    // let's fill it.
																																																					     for (int l=0;l<ligne;l++)
																																																					      {
																																																						for (int c=0;c<colonne;c++)
																																																						  {
																																																						     *(pBits)=ptemp->blue;
																																																							*(pBits+1)=ptemp->green;
																																																							   *(pBits+2)=ptemp->red;
																																																							      pBits=pBits+3;
																																																								 ptemp++;
																																																								   }
																																																								     pBits=pBits+align;
																																																								      }

																																																								       // Create CBitmap

																																																									CBitmap bitmap;
																																																									 bitmap.CreateCompatibleBitmap(pDC,colonne,ligne);

																																																									  PBITMAPINFO pbmi;
																																																									   WORD    cClrBits;

																																																									    // Convert the color format to a count of bits.
																																																									     cClrBits = 24;

																																																									      // Allocate memory for the BITMAPINFO structure. (This structure
																																																									       // contains a BITMAPINFOHEADER structure and an array of RGBQUAD
																																																										// data structures.)
																																																										 // There is no RGBQUAD array for the 24-bit-per-pixel format.
																																																										  pbmi = (PBITMAPINFO) LocalAlloc(LPTR,sizeof(BITMAPINFOHEADER));

																																																										    // Initialize the fields in the BITMAPINFO structure.
																																																											pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
																																																											    pbmi->bmiHeader.biWidth = colonne;
																																																												pbmi->bmiHeader.biHeight = -ligne; // tricky
																																																												    pbmi->bmiHeader.biPlanes = 1;
																																																													pbmi->bmiHeader.biBitCount = 24;

																																																													  // If the bitmap is not compressed, set the BI_RGB flag.
																																																													    pbmi->bmiHeader.biCompression = BI_RGB;

																																																													      // Compute the number of bytes in the array of color
																																																														// indices and store the result in biSizeImage.
																																																														  // Width must be DWORD aligned unless bitmap is RLE compressed.
																																																														    pbmi->bmiHeader.biSizeImage = (pbmi->bmiHeader.biWidth + 15) /16
																																																																		      * pbmi->bmiHeader.biHeight
																																																																							* cClrBits;

																																																																							 // Set biClrImportant to 0, indicating that all of the
																																																																							  // device colors are important.
																																																																							   pbmi->bmiHeader.biClrImportant = 0;

																																																																							    // insert bits
																																																																							     int s = ::SetDIBits(pDC->m_hDC,(HBITMAP)bitmap.m_hObject,0,ligne,BitmapData,pbmi,DIB_RGB_COLORS);

																																																																							      // Create HDIB

																																																																							       BITMAP bm;
																																																																								BITMAPINFOHEADER bi;
																																																																								 BITMAPINFOHEADER FAR *lpbi;
																																																																								  WORD BiBits;
																																																																								   DWORD dwLen;
																																																																								    HANDLE hdib;
																																																																								     HANDLE h;

																																																																								      bitmap.GetBitmap(&bm);

																																																																								       BiBits =  24;

																																																																									   bi.biSize               = sizeof(BITMAPINFOHEADER);
																																																																									       bi.biWidth              = bm.bmWidth;
																																																																										   bi.biHeight             = bm.bmHeight;
																																																																										       bi.biPlanes             = 1;
																																																																											   bi.biBitCount           = BiBits;
																																																																											       bi.biCompression        = BI_RGB;
																																																																												   bi.biSizeImage          = 0;
																																																																												       bi.biXPelsPerMeter      = 0;
																																																																													   bi.biYPelsPerMeter      = 0;
																																																																													       bi.biClrUsed            = 0;
																																																																														   bi.biClrImportant       = 0;

																																																																														    dwLen  = bi.biSize;

																																																																														     hdib = GlobalAlloc(GHND,dwLen);

																																																																															 lpbi = (BITMAPINFOHEADER FAR *)GlobalLock(hdib);

																																																																															     *lpbi = bi;

																																																																																 /*  call GetDIBits with a NULL lpBits param, so it will calculate the
																																																																																      *  biSizeImage field for us
																																																																																	   */
																																																																																	       GetDIBits(pDC->m_hDC,(HBITMAP)bitmap.m_hObject, 0L, (DWORD)bi.biHeight,
																																																																																		       (LPBYTE)NULL, (LPBITMAPINFO)lpbi, (DWORD)DIB_RGB_COLORS);

																																																																																			   bi = *lpbi;
																																																																																			       GlobalUnlock(hdib);

																																																																																				   /* If the driver did not fill in the biSizeImage field, make one up */
																																																																																				       if (bi.biSizeImage == 0)
																																																																																					       bi.biSizeImage = WIDTHBYTES((DWORD)bm.bmWidth * BiBits) * bm.bmHeight;

																																																																																						   /*  realloc the buffer big enough to hold all the bits */
																																																																																						       dwLen = bi.biSize + bi.biSizeImage;
																																																																																							   if (h = GlobalReAlloc(hdib,dwLen,0))
																																																																																								   hdib = h;
																																																																																								       else{
																																																																																									       GlobalFree(hdib);
																																																																																										       hdib = NULL;
																																																																																											 }

																																																																																											     /*  call GetDIBits with a NON-NULL lpBits param, and actualy get the
																																																																																												  *  bits this time
																																																																																												       */
																																																																																													   lpbi = ( BITMAPINFOHEADER *)GlobalLock(hdib);

																																																																																													       if (GetDIBits( pDC->m_hDC,
																																																																																																  (HBITMAP)bitmap.m_hObject,
																																																																																																		     0L,
																																																																																																					(DWORD)bi.biHeight,
																																																																																																							   (LPBYTE)lpbi + (WORD)lpbi->biSize,
																																																																																																									      (LPBITMAPINFO)lpbi, (DWORD)DIB_RGB_COLORS) == 0){
																																																																																																										       GlobalUnlock(hdib);
																																																																																																												hdib = NULL;}

																																																																																																												    bi = *lpbi;

																																																																																																												       return (HDIB)hdib;
																																																																																																												       }
