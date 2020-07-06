object Form2: TForm2
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Main Menu'
  ClientHeight = 181
  ClientWidth = 354
  Color = clBlack
  Constraints.MaxHeight = 210
  Constraints.MaxWidth = 360
  Constraints.MinHeight = 210
  Constraints.MinWidth = 360
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 51
    Top = 17
    Width = 52
    Height = 13
    Caption = 'Username:'
    Color = clBlack
    ParentColor = False
  end
  object Label2: TLabel
    Left = 51
    Top = 69
    Width = 50
    Height = 13
    Caption = 'Password:'
    Color = clWhite
    ParentColor = False
  end
  object btnOK: TButton
    Left = 80
    Top = 136
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = btnOKClick
  end
  object btnCancel: TButton
    Left = 184
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object textUsername: TEdit
    Left = 51
    Top = 38
    Width = 251
    Height = 21
    TabOrder = 2
  end
  object textPassword: TEdit
    Left = 51
    Top = 88
    Width = 251
    Height = 21
    TabOrder = 3
  end
  object btnCro: TButton
    Left = 259
    Top = 3
    Width = 43
    Height = 25
    Caption = 'CRO'
    TabOrder = 4
    OnClick = btnCroClick
  end
  object btnUs: TButton
    Left = 308
    Top = 3
    Width = 43
    Height = 25
    Caption = 'ENG'
    TabOrder = 5
    OnClick = btnUsClick
  end
  object XMLDocument2: TXMLDocument
    FileName = 'podaciXML.xml'
    Left = 320
    Top = 40
  end
end
