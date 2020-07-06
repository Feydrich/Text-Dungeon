object ConnectionForm: TConnectionForm
  Left = 624
  Top = 382
  BorderStyle = bsDialog
  Caption = 'Multiplayer'
  ClientHeight = 77
  ClientWidth = 407
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object HostLabel: TLabel
    Left = 8
    Top = 14
    Width = 26
    Height = 13
    Caption = 'Host:'
  end
  object IP: TEdit
    Left = 8
    Top = 39
    Width = 281
    Height = 21
    TabOrder = 0
  end
  object ConnectButton: TButton
    Left = 304
    Top = 39
    Width = 85
    Height = 21
    Caption = 'Connect'
    TabOrder = 1
    OnClick = ConnectButtonClick
  end
end
