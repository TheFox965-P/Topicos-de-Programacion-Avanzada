#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace ProyectoFP1;

[STAThread]
int main(array<String^>^)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainForm());
    return 0;
}
