#pragma once
#include <version.h>
#include <interfaces/C/macros.h>
#include <interfaces/CPP/GigPerformerAPI.h>
#include <interfaces/CPP/GPUtils.h>
// #include <interfaces/CPP/GPMidiMessages.h>
// #include "interfaces/C/GPTypes.h"
#include <windows.h>
#include <LogWindow.h>


// define an XML string describing your product
const std::string XMLProductDescription =
    // Replace with your information
    "<Library>"
    "  <Product"
    "    Name=\"" + PROJECT_NAME + "\""
    "    Version=\"" + PROJECT_VERSION + "\""
    "    BuildDate=\"" + PROJECT_BUILD_DATE + "\">"
    "  </Product> "
    "  <Description>Communicate with Plugins from anywhere using PluginControlBus instead of needing to use OSC</Description>"
    "  <ImagePath>/Path/To/ImageFile/foo.jpg</ImagePath>"
    "</Library>";

#define then


// void alertBox(const char* text) {
//     MessageBoxA(NULL, text, "Message", MB_OK | MB_ICONINFORMATION);
// }

class LibMain : public GigPerformerAPI
{

	public:

		static void storeInstance(LibMain* incoming)
		{
			instance = incoming;
		}
		static LibMain* getInstance()
		{
			return (instance);
		}
		
		boolean debug = true;

	private:

		static LibMain* instance;

	protected:
		int GetMenuCount() override;
		std::string GetMenuName(int index) override;
		void InvokeMenu(int itemIndex) override;
		
	public:
		explicit LibMain(LibraryHandle handle) : GigPerformerAPI(handle)
		{
		}
		
		~LibMain() override
		{
		}

		void logToWindow(const std::string & message, bool openLogWindow);
		void setDebug(boolean state); 

		boolean assertPluginExists(std::string handle, bool global);
		boolean assertWidgetExists(std::string handle);
		
		void OnRackspaceActivated() override
		{}

		void Initialization() override;

		void ListAvailableHandles();

		int RequestGPScriptFunctionSignatureList(GPScript_AllowedLocations location,
												ExternalAPI_GPScriptFunctionDefinition **list) override;

    // Generally don't touch this - simply define the constant 'XMLProductDescription' at the top of this file with
    // an XML description of your product
    std::string GetProductDescription() override // This MUST be defined in your class
        {
           return XMLProductDescription;
        }
};
