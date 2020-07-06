object Form3: TForm3
  Left = 760
  Top = 415
  BorderStyle = bsSingle
  Caption = 'Character Creation'
  ClientHeight = 315
  ClientWidth = 496
  Color = clBlack
  DefaultMonitor = dmMainForm
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Faster: TLabel
    Left = 16
    Top = 169
    Width = 31
    Height = 13
    Caption = 'Faster'
  end
  object Stronger: TLabel
    Left = 436
    Top = 169
    Width = 42
    Height = 13
    Caption = 'Stronger'
  end
  object Best: TLabel
    Left = 212
    Top = 169
    Width = 59
    Height = 13
    Caption = 'Best of both'
  end
  object Strength: TLabel
    Left = 8
    Top = 96
    Width = 46
    Height = 13
    Caption = 'Strength:'
  end
  object Dex: TLabel
    Left = 8
    Top = 128
    Width = 49
    Height = 13
    Caption = 'Dexterity:'
  end
  object SHolder: TLabel
    Left = 63
    Top = 96
    Width = 3
    Height = 13
  end
  object DHolder: TLabel
    Left = 63
    Top = 128
    Width = 3
    Height = 13
  end
  object Create: TLabel
    Left = 8
    Top = 24
    Width = 108
    Height = 13
    Caption = 'Enter character name:'
  end
  object SComment: TLabel
    Left = 85
    Top = 96
    Width = 339
    Height = 13
    Caption = 
      '//Strength dictates how much damage you will do to enemies on at' +
      'tack'
  end
  object DComment: TLabel
    Left = 85
    Top = 128
    Width = 337
    Height = 13
    Caption = 
      '//Dexterity dictates turn order and chance of an enemy attack mi' +
      'ssing'
  end
  object ScrollBar1: TScrollBar
    Left = 8
    Top = 200
    Width = 470
    Height = 89
    Max = 10
    PageSize = 0
    TabOrder = 0
    OnScroll = ScrollBar1Scroll
  end
  object CharacterName: TEdit
    Left = 8
    Top = 43
    Width = 193
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 212
    Top = 8
    Width = 266
    Height = 68
    Caption = 'Create this Character!'
    TabOrder = 2
    OnClick = Button1Click
  end
end
