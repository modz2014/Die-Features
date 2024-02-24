; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Die"
#define MyAppVersion "3.09"
#define MyAppPublisher "horsicq"
#define MyAppURL "https://github.com/horsicq/DIE-engine"
#define MyAppExeName "die.exe"


[Setup]
; NOTE: The value of AppId uniquely identifies this application. Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{2F69E5B8-EB45-46B7-BCD8-FC64B5DE8C39}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}
ChangesAssociations=yes
DisableProgramGroupPage=yes
; Uncomment the following line to run in non administrative install mode (install for current user only.)
;PrivilegesRequired=lowest
OutputBaseFilename=setup
SetupIconFile=logo.ico
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: checkedonce
Name: "contextmenu"; Description: "Add to context menu"; GroupDescription: "{cm:AdditionalIcons}"; Flags: checkedonce

[Files]
Source: "die\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs


[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: contextmenu
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

[Registry]
Root: HKCR; Subkey: "*\shell\Detect It Easy"; Flags: uninsdeletekey; Check: ShouldAddContextMenu
Root: HKCR; Subkey: "*\shell\Detect It Easy\command"; ValueType: string; \
    ValueName: ""; ValueData: """{app}\die.exe"" ""%1"""; Flags: uninsdeletekey; Check: ShouldAddContextMenu
Root: HKCR; Subkey: "*\shell\Detect It Easy"; ValueType: string; \
    ValueName: "Icon"; ValueData: "{app}\die.exe,0"; Flags: uninsdeletekey; Check: ShouldAddContextMenu

[Code]
function ShouldAddContextMenu(): Boolean;
begin
  Result := WizardForm.TasksList.Checked[1]; // Adjust index if necessary
end;

procedure InitializeWizard;
var
  WelcomePage: TWizardPage;
  WelcomeLabel: TNewStaticText;
begin
  // Create the welcome page
  WelcomePage := CreateCustomPage(wpWelcome, 'Welcome to Die Installation', '');
  
  // Create the welcome label with multi-line text
  WelcomeLabel := TNewStaticText.Create(WizardForm);
  WelcomeLabel.Parent := WelcomePage.Surface;
  WelcomeLabel.Left := ScaleX(16);
  WelcomeLabel.Top := ScaleY(16);
  WelcomeLabel.Width := WelcomePage.SurfaceWidth - ScaleX(32); // Adjust width to fit within page
  WelcomeLabel.Caption :=
    'Thank you for choosing to install Die, a powerful software tool for binary analysis.' + #13#10 +
    'Die (Detect It Easy) is designed to provide comprehensive analysis and identification ' + #13#10 + 
    'of binary files. It helps reverse engineers, security researchers, and software developers ' + #13#10 +
    'in understanding and examining executable files.' + #13#10#13#10+
    'Key Features:' + #13#10 +
    '� Fast and accurate identification of file types' + #13#10 +
    '� Support for various architectures and file formats' + #13#10 +
    '� Intuitive user interface for easy navigation and usage' + #13#10 +
    '� Extensible through plugins for additional functionality';

  // Adjust font size and style for better readability
  WelcomeLabel.Font.Size := 10;


  // Set the height of the label based on the text content
  WelcomeLabel.AutoSize := True;
end;