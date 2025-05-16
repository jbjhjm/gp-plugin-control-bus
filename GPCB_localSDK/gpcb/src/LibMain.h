#pragma once
#include <version.h>
#include <interfaces/C/macros.h>
#include <interfaces/CPP/GigPerformerAPI.h>
#include <interfaces/CPP/GPUtils.h>
// #include <interfaces/CPP/GPMidiMessages.h>
// #include "interfaces/C/GPTypes.h"
#include <windows.h>
#include <LogWindow.h>
#include <MultiAsyncUpdater.h>


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

		bool hasGigFinishedLoading = false;
		MultiAsyncUpdater* actionQueue;
	
	public:
		explicit LibMain(LibraryHandle handle) : GigPerformerAPI(handle)
		{
			actionQueue = new MultiAsyncUpdater();
		}
		
		~LibMain() override
		{
		}

		void enqueueAction(std::function<void()> callback);

		void logToWindow(const std::string & message, bool openLogWindow);
		void setDebug(boolean state); 

		boolean assertPluginExists(std::string handle, bool global);
		boolean assertWidgetExists(std::string handle);
		
		void OnOpen() override {
			scriptLog("Extension: OnOpen",true);
			LogWindow::initialize();
		}
		
		// void OnVariationChanged(int oldIndex, int newIndex) override {
		// 	scriptLog("Extension: OnVariationChanged " + std::to_string(oldIndex) + " " + std::to_string(newIndex),true);
		// }
		
		void OnStatusChanged(GPStatusType status) override {
			if(status == GPStatusType::GPStatus_GigFinishedLoading) {
				if(debug) scriptLog("Extension: OnStatusChanged -> GigFinishedLoading", true);
				hasGigFinishedLoading = true;
				actionQueue->triggerAsyncUpdate(); // flush actions scheduled during loadup
			} else if(status == GPStatusType::GPStatus_GigStartedLoading) {
				if(debug) scriptLog("Extension: OnStatusChanged -> GigStartedLoading", true);
				hasGigFinishedLoading = false;
			}
		}

		void OnClose() override {
			LogWindow::finalize();
		}

		// void OnRackspaceActivated() override {
		// 	scriptLog("Extension: OnRackspaceActivated. ID: " + std::to_string(getCurrentRackspaceIndex()), true);
		// }

		void Initialization() override
		{
			// Do any initialization that you need

			// register all the methods that you are going to actually use,
			// listenForWidget("abc", true);
			// registerCallback("OnVariationChanged");
			registerCallback("OnStatusChanged");
			// registerCallback("OnRackspaceActivated");
			registerCallback("OnOpen");
			registerCallback("OnClose");
		}

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
