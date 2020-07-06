object sideMenu: TsideMenu
  Left = 1317
  Top = 62
  BorderStyle = bsDialog
  Caption = 'Menu'
  ClientHeight = 316
  ClientWidth = 217
  Color = clBackground
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 16
    Top = 16
    Width = 185
    Height = 41
    Caption = 'Stats and Items'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 16
    Top = 74
    Width = 185
    Height = 41
    Caption = 'Connect'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 16
    Top = 133
    Width = 185
    Height = 40
    Caption = 'Save Game'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 16
    Top = 191
    Width = 185
    Height = 42
    Caption = 'Load Game'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 16
    Top = 255
    Width = 185
    Height = 42
    Caption = 'Quit'
    TabOrder = 4
    OnClick = Button5Click
  end
  object playerSettingsXML: TXMLDocument
    FileName = 'playerSettings.xml'
    Left = 176
    Top = 56
  end
  object saveLoadXML: TXMLDocument
    FileName = 'saveLoadXML.xml'
    Left = 176
    Top = 16
  end
end
