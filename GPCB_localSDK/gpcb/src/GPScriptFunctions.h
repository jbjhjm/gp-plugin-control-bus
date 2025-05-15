#pragma once

#include <interfaces/CPP/GigPerformerAPI.h>
// #include <interfaces/CPP/GPMidiMessages.h>
#include <interfaces/CPP/GPUtils.h>
// #include "interfaces/C/GPTypes.h"
#include "LibMain.h"
#include <stdexcept>
#include <juce_core/juce_core.h>


extern "C" void GPCB_debug(GPRuntimeEngine *vm)
{
	bool state = GP_VM_PopBoolean(vm);
	LibMain::getInstance()->setDebug(state);
}

extern "C" void GPCB_loadGPPreset(GPRuntimeEngine *vm)
{
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string presetName = buffer;

    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	bool global = GP_VM_PopBoolean(vm);

	juce::MessageManager::getInstance()->callAsync([pluginHandle, presetName, global]() {
		LibMain* gpcb = LibMain::getInstance();
		if(gpcb->debug) gpcb->scriptLog("GPCB_loadGPPreset " + pluginHandle + " - " + presetName, global);
		if(gpcb->debug) gpcb->assertPluginExists(pluginHandle, global);
		bool success = gpcb->loadGPPreset(pluginHandle, presetName, global);
		std::string successInfo = (success ? "yes" : "no");
		if(gpcb->debug) gpcb->scriptLog("GPCB_loadGPPreset successful? " + successInfo, global);
    });

}

extern "C" void GPCB_setPluginParam(GPRuntimeEngine *vm)
{

	double paramValue = GP_VM_PopDouble(vm);
	
    int paramNumber = GP_VM_PopInteger(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	bool global = GP_VM_PopBoolean(vm);

	char paramValueString[20];
	gcvt(paramValue, 10, paramValueString);

	LibMain* gpcb = LibMain::getInstance();
	if(gpcb->debug) gpcb->scriptLog("GPCB_setPluginParam " + pluginHandle + " - " + std::to_string(paramNumber) + "=" + paramValueString, false);
	if(gpcb->debug) gpcb->assertPluginExists(pluginHandle, global);
	gpcb->setPluginParameter(pluginHandle, paramNumber, paramValue, global);

}

extern "C" void GPCB_setPluginBypass(GPRuntimeEngine *vm)
{

	double paramValue = GP_VM_PopDouble(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	bool global = GP_VM_PopBoolean(vm);

	LibMain* gpcb = LibMain::getInstance();
	if(gpcb->debug) gpcb->scriptLog("GPCB_setPluginBypass " + pluginHandle + " = " + (paramValue > 0.5 ? "true" : "false"), false);
	if(gpcb->debug) gpcb->assertPluginExists(pluginHandle, global);
	gpcb->setPluginParameter(pluginHandle, -2, paramValue, global);

}

extern "C" void GPCB_showPlugin(GPRuntimeEngine *vm)
{

	double paramValue = GP_VM_PopDouble(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	bool global = GP_VM_PopBoolean(vm);

	LibMain* gpcb = LibMain::getInstance();
	if(gpcb->debug) gpcb->scriptLog("GPCB_showPlugin " + pluginHandle + " = " + (paramValue > 0.5 ? "true" : "false"), false);
	if(gpcb->debug) gpcb->assertPluginExists(pluginHandle, global);
	gpcb->setPluginParameter(pluginHandle, -1, paramValue, global);

}

extern "C" void GPCB_setWidgetValue(GPRuntimeEngine *vm)
{

	double value = GP_VM_PopDouble(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string widgetHandle = buffer;

	char valueString[20];
	gcvt(value, 10, valueString);

	LibMain* gpcb = LibMain::getInstance();
	if(gpcb->debug) gpcb->scriptLog("GPCB_setWidgetValue " + widgetHandle + " = " + valueString, false);
	if(gpcb->debug) gpcb->assertWidgetExists(widgetHandle);
	gpcb->setWidgetValue(widgetHandle, value);

}

extern "C" void GPCB_setWidgetCaption(GPRuntimeEngine *vm)
{
	
	char buffer[100];

	GP_VM_PopString(vm, buffer, 100);
    std::string caption = buffer;

    GP_VM_PopString(vm, buffer, 100);
    std::string widgetHandle = buffer;

	LibMain* gpcb = LibMain::getInstance();
	if(gpcb->debug) gpcb->scriptLog("GPCB_setWidgetCaption " + widgetHandle + " = " + caption, false);
	if(gpcb->debug) gpcb->assertWidgetExists(widgetHandle);
	gpcb->setWidgetCaption(widgetHandle, caption);

}

ExternalAPI_GPScriptFunctionDefinition GPScriptFunctionsList[] = {
    {"debug", 				"enable : boolean", 													"", "Enable debug logging", GPCB_debug},
    {"loadGPPreset", 		"global : boolean, handle : string, preset : string", 					"", "Load GPPreset for a plugin", GPCB_loadGPPreset},
    {"setPluginParam", 		"global : boolean, handle : string, paramIndex : int, value : double",	"", "Set param for a plugin", GPCB_setPluginParam},
    {"setPluginBypass", 	"global : boolean, handle : string, value : double", 					"", "Set bypass for a plugin", GPCB_setPluginBypass},
    {"showPlugin",		 	"global : boolean, handle : string, value : double", 					"", "Show/Hide plugin", GPCB_showPlugin},
    {"setWidgetValue", 		"handle : string, value : double", 										"", "Set value of a Widget", GPCB_setWidgetValue},
    {"setWidgetCaption", 	"handle : string, caption : string", 									"", "Set caption of a Widget", GPCB_setWidgetCaption},
};