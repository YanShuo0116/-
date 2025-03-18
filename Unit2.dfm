object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'BST by Y.S.Chen'
  ClientHeight = 634
  ClientWidth = 1090
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1090
    Height = 634
    ActivePage = TabSheet3
    Align = alClient
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Individual'
      object Splitter1: TSplitter
        Left = 185
        Top = 0
        Height = 603
        ExplicitLeft = 200
        ExplicitTop = 200
        ExplicitHeight = 100
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 185
        Height = 603
        Align = alLeft
        TabOrder = 0
        ExplicitHeight = 602
        object GroupBox1: TGroupBox
          Left = 8
          Top = 0
          Width = 171
          Height = 153
          Caption = 'Data'
          TabOrder = 0
          object Edit1: TEdit
            Left = 24
            Top = 24
            Width = 121
            Height = 24
            TabOrder = 0
            Text = '10'
          end
          object Button1: TButton
            Left = 24
            Top = 54
            Width = 121
            Height = 25
            Caption = 'Insert BST'
            TabOrder = 1
            OnClick = Button1Click
          end
          object Button2: TButton
            Left = 24
            Top = 85
            Width = 121
            Height = 25
            Caption = 'Search BST'
            TabOrder = 2
            OnClick = Button2Click
          end
          object Button3: TButton
            Left = 24
            Top = 116
            Width = 121
            Height = 25
            Caption = 'Delete BST'
            TabOrder = 3
            OnClick = Button3Click
          end
        end
        object GroupBox2: TGroupBox
          Left = 8
          Top = 159
          Width = 171
          Height = 147
          Caption = 'Traversal'
          TabOrder = 1
          object Button4: TButton
            Left = 24
            Top = 24
            Width = 121
            Height = 25
            Caption = 'Preorder'
            TabOrder = 0
            OnClick = Button4Click
          end
          object Button5: TButton
            Left = 24
            Top = 55
            Width = 121
            Height = 25
            Caption = 'Inorder'
            TabOrder = 1
            OnClick = Button5Click
          end
          object Button6: TButton
            Left = 24
            Top = 86
            Width = 121
            Height = 25
            Caption = 'Postorder'
            TabOrder = 2
            OnClick = Button6Click
          end
          object Button9: TButton
            Left = 24
            Top = 117
            Width = 121
            Height = 25
            Caption = 'Level Order'
            TabOrder = 3
            OnClick = Button9Click
          end
        end
        object Random: TGroupBox
          Left = 8
          Top = 312
          Width = 171
          Height = 130
          Caption = 'Random'
          TabOrder = 2
          object Label1: TLabel
            Left = 24
            Top = 16
            Width = 80
            Height = 16
            Caption = 'Range 1 to'
          end
          object Label2: TLabel
            Left = 110
            Top = 16
            Width = 24
            Height = 16
            Caption = '250'
          end
          object Label3: TLabel
            Left = 92
            Top = 55
            Width = 16
            Height = 16
            Caption = '50'
          end
          object Label4: TLabel
            Left = 128
            Top = 55
            Width = 40
            Height = 16
            Caption = 'times'
          end
          object Label5: TLabel
            Left = 6
            Top = 55
            Width = 80
            Height = 16
            Caption = 'Random for'
          end
          object TrackBar1: TTrackBar
            Left = 3
            Top = 28
            Width = 168
            Height = 21
            Max = 1000
            Min = 10
            Position = 10
            TabOrder = 0
            OnChange = TrackBar1Change
          end
          object TrackBar2: TTrackBar
            Left = 3
            Top = 74
            Width = 165
            Height = 21
            Max = 200
            Min = 5
            Position = 5
            TabOrder = 1
            OnChange = TrackBar2Change
          end
          object Button7: TButton
            Left = 24
            Top = 94
            Width = 121
            Height = 25
            Caption = 'Random Insert'
            TabOrder = 2
            OnClick = Button7Click
          end
        end
        object Button8: TButton
          Left = 32
          Top = 456
          Width = 121
          Height = 25
          Caption = 'Clear'
          TabOrder = 3
          OnClick = Button8Click
        end
        object RadioButton1: TRadioButton
          Left = 8
          Top = 491
          Width = 98
          Height = 17
          Caption = 'Recursion'
          TabOrder = 4
        end
        object RadioButton2: TRadioButton
          Left = 120
          Top = 487
          Width = 59
          Height = 25
          Caption = 'Loop'
          TabOrder = 5
        end
      end
      object PageControl2: TPageControl
        Left = 188
        Top = 0
        Width = 894
        Height = 603
        ActivePage = TabSheet2
        Align = alClient
        TabOrder = 1
        ExplicitWidth = 890
        ExplicitHeight = 602
        object TabSheet2: TTabSheet
          Caption = 'Memo'
          object Memo1: TMemo
            Left = 0
            Top = 0
            Width = 886
            Height = 572
            Align = alClient
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Courier New'
            Font.Style = []
            Lines.Strings = (
              'Memo1')
            ParentFont = False
            ScrollBars = ssVertical
            TabOrder = 0
            ExplicitWidth = 882
            ExplicitHeight = 571
          end
        end
        object Draw: TTabSheet
          Caption = 'Draw'
          ImageIndex = 1
          object PaintBox1: TPaintBox
            Left = 0
            Top = 0
            Width = 886
            Height = 572
            Align = alClient
            OnPaint = PaintBox1Paint
            ExplicitLeft = -1
          end
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Build BT'
      ImageIndex = 1
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 185
        Height = 603
        Align = alLeft
        TabOrder = 0
        object Label6: TLabel
          Left = 32
          Top = 34
          Width = 40
          Height = 16
          Caption = 'infix'
        end
        object Label7: TLabel
          Left = 32
          Top = 106
          Width = 48
          Height = 16
          Caption = 'prefix'
        end
        object Label8: TLabel
          Left = 32
          Top = 168
          Width = 56
          Height = 16
          Caption = 'postfix'
        end
        object Edit2: TEdit
          Left = 32
          Top = 56
          Width = 121
          Height = 24
          TabOrder = 0
          Text = 'HBJAFDGCE'
        end
        object Edit3: TEdit
          Left = 32
          Top = 128
          Width = 121
          Height = 24
          TabOrder = 1
          Text = 'ABHJCDFGE'
        end
        object Edit4: TEdit
          Left = 32
          Top = 192
          Width = 121
          Height = 24
          TabOrder = 2
          Text = 'HJBFGDECA'
        end
        object Button10: TButton
          Left = 32
          Top = 280
          Width = 121
          Height = 25
          Caption = 'infix+prefix'
          TabOrder = 3
          OnClick = Button10Click
        end
        object Button11: TButton
          Left = 32
          Top = 336
          Width = 121
          Height = 25
          Caption = 'infix+postfix'
          TabOrder = 4
          OnClick = Button11Click
        end
      end
      object PageControl3: TPageControl
        Left = 185
        Top = 0
        Width = 897
        Height = 603
        Align = alClient
        TabOrder = 1
      end
      object Memo2: TMemo
        Left = 185
        Top = 0
        Width = 897
        Height = 603
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssBoth
        TabOrder = 2
      end
    end
  end
end
