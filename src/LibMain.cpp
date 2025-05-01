#include "LibMain.h"
#include "version.h"
#include "GPScriptFunctions.h"

#include <cstdint>

using GPUtils = gigperformer::sdk::GPUtils;

/// Ignore a given value
/// \details this is a dummy function to suppress compiler warnings about unused parameters
template <typename T> void Ignore(T const &) noexcept
{
}

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

// List of panels
// std::vector<std::string> panelNames = {
//     "Red",
//     "Yellow",
//     "Blue",
// };
// std::vector<std::string> relativePanelLocations = {
//     "Red.gppanel",
//     "Yellow.gppanel",
//     "Blue.gppanel",
// };

std::string pathToMe; // This needs to be initialized from the initialization
                      // section of the LibMain class so it can be used in the
                      // standalone functions directly below

// int LibMain::GetPanelCount()
// {
//     return static_cast<int>(panelNames.size());
// }

// std::string LibMain::GetPanelName(int index)
// {
//     std::string text;
//     if (index >= 0 && static_cast<std::size_t>(index) < panelNames.size())
//     {
//         text = panelNames[index];
//     }

//     return text;
// }

// // Return panel layout in XML format
// std::string LibMain::GetPanelXML(int index)
// {
//     std::string text;
//     if (index >= 0 && static_cast<std::size_t>(index) < panelNames.size())
//     {
//         // We assume the panels are in the same folder as the library
//         GPUtils::loadTextFile(getPathToMe() + "/" + relativePanelLocations[index], text);
//     }
//     return text;
// }

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


// void LibMain::OnModeChanged(int mode)
// {
//     consoleLog(std::string("Switching to mode: ") + ((mode == GP_SetlistMode) ? "Setlist" : "FrontBack"));
// }

// void LibMain::OnSwitchToPanelView()
// {

//     consoleLog("Switching to panel view");
//     setPlayheadState(true);

//     int count = getPluginParameterCount("Legend", false);
//     consoleLog(std::to_string(count));

//     std::string p1 = getPluginParameterName("Legend", 1, false);
//     consoleLog(p1);
// }

// void LibMain::OnSwitchToWiringView()
// {
//     consoleLog("Switching to wiring view");
//     setPlayheadState(false);

//     setBPM(99);
// }

// void LibMain::OnGlobalPlayStateChanged(double playing)
// {
//     consoleLog(std::string("playing = ") + ((playing > 0.0) ? " true" : "false"));

//     // switchToSetlistView();
//     // switchToWiringView();

//     int color = RGBAToColor(1, 0, 0, 0.5);
//     setWidgetFillColor("MyShape", color);

//     double red, green, blue, alpha;
//     ColorToRGBA(color, red, green, blue, alpha);
//     consoleLog(std::to_string(alpha));
// }

// void LibMain::OnWidgetValueChanged(const std::string &widgetName, double newValue)
// {
//     Ignore(widgetName);
//     Ignore(newValue);

//     // int noteNumber = (int)GPUtils::Scale(newValue, 0.0, 1.0, 36, 96);
//     // GPMidiMessage n = GPMidiMessage::makeNoteOnMessage(noteNumber, 64, 0);
//     // const std::string device = "MIDI Monitor (Untitled)";
//     // sendMidiMessageToMidiOutDevice(device, n);

//     std::string caption = getWidgetCaption("abc");
//     consoleLog("caption: " + caption);
//     std::string value = getWidgetTextValue("abc");
//     consoleLog("value: " + value);

//     // consoleLog(newValue > 0.5 ? "Yes" : "No");
//     // if (newValue > 0.5)
//     // {
//     //     if (widgetName == "abc")
//     //     {
//     //         next();
//     //     }
//     //     else
//     //     {
//     //         previous();
//     //     }
//     // }
// }

// void LibMain::OnMidiDeviceListChanged(std::vector<std::string> &inputs, std::vector<std::string> &outputs)
// {
//     for (std::size_t i = 0; i < inputs.size(); i++)
//     {
//         std::string &name = inputs[i];
//         consoleLog("Input found: " + name);
//     }

//     Ignore(outputs);
// }

// void LibMain::OnWidgetCaptionChanged(const std::string &widgetName, const std::string &newCaption)
// {
//     Ignore(widgetName);
//     consoleLog("Widget caption changed: " + newCaption);
// }

// void LibMain::OnSongChanged(int oldIndex, int newIndex)
// {
//     Ignore(oldIndex);
//     consoleLog("Song changed from C++ example");
//     std::string name = getSongName(newIndex);
//     consoleLog("New song is called " + name);
// }

// void LibMain::OnWidgetStateChanged(const std::string &widgetName, int newState)
// {
//     consoleLog("Widget " + widgetName + ": " + ((newState == 0) ? "created" : "removed"));
// }

void LibMain::Initialization()
{
    // Do any initialization that you need

    // .... your code here

    // Finally, register all the methods that you are going to actually use,
    // i.e, the ones you declared above as override
    // registerCallback("OnSongChanged");
    // registerCallback("OnStatusChanged");
    // registerCallback("OnMidiDeviceListChanged");
    // registerCallback("OnWidgetValueChanged");
    // registerCallback("OnWidgetStateChanged");
    // registerCallback("OnWidgetCaptionChanged");
    // registerCallback("OnGlobalPlayStateChanged");
    // registerCallback("OnModeChanged");
    // registerCallback("OnSwitchToPanelView");
    // registerCallback("OnSwitchToWiringView");
    // registerCallback("OnTempoChanged");
    // registerCallback("OnSetlistChanged");
    registerCallback("OnRackspaceActivated");
    // listenForWidget("abc", true);
    // listenForWidget("def", true);

    consoleLog("path to library " + getPathToMe());
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
    Ignore(location);

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

	} // namespace sdk
} // namespace gigperformer
