#include "LibMain.h"
#include "version.h"
#include "GPScriptFunctions.h"
#include <cstdint>

// using GPUtils = gigperformer::sdk::GPUtils;


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

    consoleLog("ListAvailableHandles");

	getPluginList(list, false);
	scriptLog("Plugin Handles in current rackspace:", true);
	for (int i = 0; i < list.size(); i++) {
		scriptLog(list[i], false);
	}

	getWidgetList(list, false);
	scriptLog("Widget Handles in current rackspace:", false);
	for (int i = 0; i < list.size(); i++) {
		scriptLog(list[i], false);
	}
}

void LibMain::Initialization()
{
    // Do any initialization that you need

    // register all the methods that you are going to actually use,
    // listenForWidget("abc", true);
    registerCallback("OnRackspaceActivated");
}

void LibMain::setDebug(boolean state) 
{
	debug = state;
}

boolean LibMain::assertPluginExists(std::string handle)
{
	boolean exists = pluginExists(handle, false);
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

std::string LibMain::GetProductDescription()
{
    // Generally don't touch this - simply define the constant
    // 'XMLProductDescription' at the top of this file with an XML description of
    // your product
    return XMLProductDescription;
}

int LibMain::RequestGPScriptFunctionSignatureList(GPScript_AllowedLocations location,
                                                  ExternalAPI_GPScriptFunctionDefinition **list)
{
    // Allow these in ANY script so no need to check the location field
    *list = GPScriptFunctionsList;
    int count = sizeof(GPScriptFunctionsList) / sizeof(ExternalAPI_GPScriptFunctionDefinition);
    return count;
}

namespace gigperformer
{
	namespace sdk
	{

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

	}
}
