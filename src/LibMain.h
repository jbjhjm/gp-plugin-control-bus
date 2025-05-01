#pragma once

#include "gigperformer/sdk/GPMidiMessages.h"
#include "gigperformer/sdk/GPUtils.h"
#include "gigperformer/sdk/GigPerformerAPI.h"
#include "gigperformer/sdk/types.h"
#include <windows.h>

void alert(const char* text) {
    MessageBoxA(NULL, text, "Message", MB_OK | MB_ICONINFORMATION);
}

class LibMain : public gigperformer::sdk::GigPerformerAPI
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

		void setDebug(boolean state); 
		boolean assertPluginExists(std::string handle);
		boolean assertWidgetExists(std::string handle);
		
		void OnRackspaceActivated() override
		{}

		void Initialization() override;

		void ListAvailableHandles();

		int RequestGPScriptFunctionSignatureList(GPScript_AllowedLocations location,
												ExternalAPI_GPScriptFunctionDefinition **list) override;

		std::string GetProductDescription() override;
};
