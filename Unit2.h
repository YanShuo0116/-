//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TSplitter *Splitter1;
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TGroupBox *GroupBox2;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TGroupBox *Random;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TTrackBar *TrackBar1;
	TTrackBar *TrackBar2;
	TButton *Button7;
	TMemo *Memo1;
	TPageControl *PageControl2;
	TTabSheet *TabSheet2;
	TTabSheet *Draw;
	TPaintBox *PaintBox1;
	TButton *Button8;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TButton *Button9;
	TTabSheet *TabSheet3;
	TPanel *Panel2;
	TPageControl *PageControl3;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TButton *Button10;
	TButton *Button11;
	TMemo *Memo2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall PaintBox1Paint(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);


private:	// User declarations

		Graphics::TBitmap *bitmap;
		void __fastcall DrawTree(struct BSTreeNode *node, int x, int y, int level, int radius, int spacing, int maxNodes);
		int maxLevel;

public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
