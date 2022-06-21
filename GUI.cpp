#include<fstream>
#include "GUI.h"
#include"createDB.h"

using namespace GUIProject;

[STAThreadAttribute]

int main(cli::array<System::String ^> ^args) {
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew GUI());

	return 0;
}
