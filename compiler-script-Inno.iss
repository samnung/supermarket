; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{33991C19-1D93-45E4-B3C6-331A0F8B8544}
AppName=Supermarket
AppVersion=0.1.0
;AppVerName=Supermarket 0.1.0
AppPublisher=Roman K��
AppPublisherURL=https://code.google.com/p/supermarket-app
AppSupportURL=https://code.google.com/p/supermarket-app
AppUpdatesURL=https://code.google.com/p/supermarket-app
DefaultDirName={pf}\Supermarket
DefaultGroupName=Supermarket
AllowNoIcons=yes
OutputDir=C:\Documents and Settings\samnung\Plocha\Supermarket
OutputBaseFilename=supermarket-0.1-win-setup
SetupIconFile=\\Samnung-mb\samnung\Documents\Programing\Qt\supermarket\program\img\icon.ico
Compression=lzma
SolidCompression=yes

[Languages]
Name: "czech"; MessagesFile: "compiler:Languages\Czech.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "C:\Documents and Settings\samnung\Plocha\Supermarket\Supermarket.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\samnung\Plocha\Supermarket\libgcc_s_dw2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\samnung\Plocha\Supermarket\mingwm10.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\samnung\Plocha\Supermarket\QtCore4.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\samnung\Plocha\Supermarket\QtGui4.dll"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\Supermarket"; Filename: "{app}\Supermarket.exe"
Name: "{group}\{cm:UninstallProgram,Supermarket}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\Supermarket"; Filename: "{app}\Supermarket.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\Supermarket"; Filename: "{app}\Supermarket.exe"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\Supermarket.exe"; Description: "{cm:LaunchProgram,Supermarket}"; Flags: nowait postinstall skipifsilent

