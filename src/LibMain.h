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
	//   static LibMain* getInstancePointer()
	//   {
	// 	  return &getInstanceImpl();
	//   }
	//   static LibMain& getInstance()
	//   {
	// 	  return getInstanceImpl();
	//   }
	//   static void init(LibraryHandle handle) // enable moving in
	//   {
	// 	  getInstanceImpl(&handle);
	//   }
	
	  // static LibMain& getInstance(LibraryHandle handle)
	  //     {
	  //         // Instantiated on first use.
	  // 		// Guaranteed to be destroyed.
	  //         static LibMain instance {handle}; 
	  //         return instance;
	  //     }
  
	//   private:
  
		//   static LibMain* getInstanceImpl(LibraryHandle* const handle = nullptr)
		//   {
		// 	  static LibMain instance{ handle };
		// 	  return &instance;
		//   }

			static LibMain* instance;
  
			static void storeInstance(LibMain* incoming)
			{
				instance = incoming;
			}
			static LibMain* getInstance()
			{
				return (instance);
			}




  protected:
    // int GetPanelCount() override;
    // std::string GetPanelName(int index) override;
    // std::string GetPanelXML(int index) override;

    // These are for creating menu items in Gig Performer that can be used to
    // trigger external functions provided by the extension developer
    int GetMenuCount() override;
    std::string GetMenuName(int index) override;
    void InvokeMenu(int itemIndex) override;

  public:
    // These must be here but no need to do anything unless you want extra behavior
    explicit LibMain(LibraryHandle handle) : GigPerformerAPI(handle)
    {
		// if (handle == nullptr) alert( "LibMain was constructed without calling LibMain::Init!" );
		// else alert("Lib main constructed WITH handle");
    }

    ~LibMain() override
    {
    }

    // void OnStatusChanged(GPStatusType status) override
    // {
    //     consoleLog("Gig status changed to " + std::to_string(status));
    // }

    void OnRackspaceActivated() override
    {
        consoleLog("Rackspace activated");
    }

    void Initialization() override;

	void ListAvailableHandles();

    int RequestGPScriptFunctionSignatureList(GPScript_AllowedLocations location,
                                             ExternalAPI_GPScriptFunctionDefinition **list) override;

    // This MUST be defined in your class
    std::string GetProductDescription() override;
};
