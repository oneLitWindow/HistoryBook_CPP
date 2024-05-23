//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TADOConnection *ADOConnection1;
        TADOQuery *ADOQuery1;
        TDataSource *DataSource1;
        TDBGrid *DBGrid1;
        TDBGrid *DBGrid2;
        TADOQuery *ADOQuery2;
        TDataSource *DataSource2;
        TPanel *Panel1;
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
