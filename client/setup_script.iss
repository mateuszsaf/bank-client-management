[Setup]
AppName=Bank Client Managment
AppVersion=1.0
AppPublisher=Mateusz Safarzyński
DefaultDirName={autopf}\bank_client_managment
OutputDir=Output
OutputBaseFilename=setup 
Compression=lzma  
SolidCompression=yes  

[Files]
Source: "C:\Users\matsw\Documents\GitHub\bank-client-management\client\bank_client_managmentv10.exe"

[Icons]
Name: "{group}\Bank Client"; Filename: "{app}\bank_client_managmentv10.exe"; IconFilename: "C:\Users\matsw\Documents\GitHub\bank-client-management\client\SAFAR.ico"
Name: "{userdesktop}\Bank Client"; Filename: "{app}\bank_client_managmentv10.exe"; IconFilename: "C:\Users\matsw\Documents\GitHub\bank-client-management\client\SAFAR.ico"

[Run]
Filename: "{app}\bank_client_managmentv10.exe"; Description: "Uruchom Bank Client po instalacji"; Flags: nowait postinstall skipifsilent