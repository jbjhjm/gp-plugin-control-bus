#pragma once

#include "gigperformer/sdk/GPMidiMessages.h"
#include "gigperformer/sdk/GPUtils.h"
#include "gigperformer/sdk/GigPerformerAPI.h"
#include "gigperformer/sdk/types.h"

class LibMain : public gigperformer::sdk::GigPerformerAPI
{
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

    int RequestGPScriptFunctionSignatureList(GPScript_AllowedLocations location,
                                             ExternalAPI_GPScriptFunctionDefinition **list) override;

    // This MUST be defined in your class
    std::string GetProductDescription() override;
};
