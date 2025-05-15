#include "LibMain.h"
#include "version.h"
#include "GPScriptFunctions.h"
#include <cstdint>


// using GPUtils = gigperformer::sdk::GPUtils;


// define an XML string describing your product
// const std::string XMLProductDescription;

std::string pathToMe; // This needs to be initialized from the initialization
                      // section of the LibMain class so it can be used in the
                      // standalone functions directly below

LibMain* LibMain::instance = NULL;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \name    Menu support
/// \details 3 functions are used to implement menu actions: one returns number of avail items, second the labels at index, and third executes actions at index.

// List of menu items
std::vector<std::string> menuNames = {
    "Show Front Panels",
    "Show Back Wiring",
    "Show Setlists",
    "List available Handles",
};

int LibMain::GetMenuCount()
{
    return static_cast<int>(menuNames.size());
}

std::string LibMain::GetMenuName(int index)
{
    std::string text;
    if (index >= 0 && static_cast<std::size_t>(index) < menuNames.size())
    {
        text = menuNames[index];
    }

    return text;
}

void LibMain::InvokeMenu(int index)
{
    if (index >= 0 && static_cast<std::size_t>(index) < menuNames.size())
    {
        switch (index)
        {
        case 0:
            switchToPanelView();
            break;
        case 1:
            switchToWiringView();
            break;
        case 2:
            switchToSetlistView();
            break;
        case 3:
			ListAvailableHandles();
            break;

        default:
            break;
        }
    }
}
void LibMain::ListAvailableHandles()
{
	std::vector<std::string> list;

    logToWindow("ListAvailableHandles", true);

	getPluginList(list, true);
	logToWindow("Plugin Handles in global rackspace", false);
	logToWindow("===================================", false);
	for (int i = 0; i < list.size(); i++) {
		logToWindow(list[i], false);
	}

	getPluginList(list, false);
	logToWindow("Plugin Handles in current rackspace", false);
	logToWindow("===================================", false);
	for (int i = 0; i < list.size(); i++) {
		logToWindow(list[i], false);
	}

	getWidgetList(list, false);
	scriptLog("Widget Handles (current rackspace?)", false);
	scriptLog("===================================", false);
	for (int i = 0; i < list.size(); i++) {
		scriptLog(list[i], false);
	}
}

void  LibMain::logToWindow(const std::string & message, bool openLogWindow)
{
	if(openLogWindow) LogWindow::showWindow();
	LogWindow::log(message);
}

void LibMain::setDebug(boolean state) 
{
	debug = state;
}

boolean LibMain::assertPluginExists(std::string handle, bool global)
{
	boolean exists = pluginExists(handle, global);
	if(!exists) {
		scriptLog("MISSING PLUGIN HANDLE: "+handle, true);
	}
	return exists;
}

boolean LibMain::assertWidgetExists(std::string handle)
{
	boolean exists = widgetExists(handle);
	if(!exists) {
		scriptLog("MISSING WIDGET HANDLE: "+handle, true);
	}
	return exists;
}

int LibMain::RequestGPScriptFunctionSignatureList(GPScript_AllowedLocations location,
                                                  ExternalAPI_GPScriptFunctionDefinition **list)
{
    // Allow these in ANY script so no need to check the location field
    *list = GPScriptFunctionsList;
    int count = sizeof(GPScriptFunctionsList) / sizeof(ExternalAPI_GPScriptFunctionDefinition);
    return count;
}


GigPerformerAPI *CreateGPExtension(LibraryHandle handle)
{
	/**
	 * seems that the function is called TWO times:
	 * first with a nullptr handle, when GP only checks for some metadata.
	 * second, when GP sees that it should be enabled - then a handle is being passed.
	 */
	// LibMain::init(handle);
	if(handle == nullptr) {
		return new LibMain(nullptr);
	} else {
		LibMain* instance = new LibMain(handle);
		LibMain::storeInstance(instance);
		return instance;
	}
}

