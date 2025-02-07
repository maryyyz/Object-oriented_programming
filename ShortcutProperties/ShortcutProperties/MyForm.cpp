#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread] // Атрибут для использования Windows Forms
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew ShortcutProperties::MyForm()); // Запуск формы
}
