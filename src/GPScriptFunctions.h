#pragma once

#include "gigperformer/sdk/GPMidiMessages.h"
#include "gigperformer/sdk/GPUtils.h"
#include "gigperformer/sdk/GigPerformerAPI.h"
#include "gigperformer/sdk/types.h"
#include "LibMain.h"
#include <stdexcept>

extern "C" void addtwo(GPRuntimeEngine *vm)
{
    int b = GP_VM_PopInteger(vm);
    int a = GP_VM_PopInteger(vm);
    GP_VM_PushInteger(vm, a + b);
}

extern "C" void GPCB_loadGPPreset(GPRuntimeEngine *vm)
{
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string presetName = buffer;

    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	LibMain::getInstance()->scriptLog("GPCB_loadGPPreset " + pluginHandle + " - " + presetName, true);
	// LibMain::getInstance()->loadGPPreset(pluginHandle, presetName)

}

extern "C" void GPCB_setPluginParam(GPRuntimeEngine *vm)
{

	double paramValue = GP_VM_PopDouble(vm);
	
    int paramNumber = GP_VM_PopInteger(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	char paramValueString[20];
	gcvt(paramValue, 10, paramValueString);

	LibMain::getInstance()->scriptLog("GPCB_setPluginParam " + pluginHandle + " - " + std::to_string(paramNumber) + "=" + paramValueString, true);
	LibMain::getInstance()->setPluginParameter(pluginHandle, paramNumber, paramValue, false);

}

extern "C" void GPCB_setPluginBypass(GPRuntimeEngine *vm)
{

	double paramValue = GP_VM_PopDouble(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	LibMain::getInstance()->scriptLog("GPCB_setPluginBypass " + pluginHandle + " = " + (paramValue > 0.5 ? "true" : "false"), true);
	LibMain::getInstance()->setPluginParameter(pluginHandle, -2, paramValue, false);

}

extern "C" void GPCB_showPlugin(GPRuntimeEngine *vm)
{

	double paramValue = GP_VM_PopDouble(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	LibMain::getInstance()->scriptLog("GPCB_setPluginBypass " + pluginHandle + " = " + (paramValue > 0.5 ? "true" : "false"), true);
	LibMain::getInstance()->setPluginParameter(pluginHandle, -1, paramValue, false);

}

extern "C" void GPCB_setWidgetValue(GPRuntimeEngine *vm)
{

	double value = GP_VM_PopDouble(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string widgetHandle = buffer;

	char valueString[20];
	gcvt(value, 10, valueString);

	LibMain::getInstance()->scriptLog("GPCB_setWidgetValue " + widgetHandle + " = " + valueString, true);
	LibMain::getInstance()->setWidgetValue(widgetHandle, value);

}

extern "C" void GPCB_setWidgetCaption(GPRuntimeEngine *vm)
{
	
	char buffer[100];

	GP_VM_PopString(vm, buffer, 100);
    std::string caption = buffer;

    GP_VM_PopString(vm, buffer, 100);
    std::string widgetHandle = buffer;

	LibMain::getInstance()->scriptLog("GPCB_setWidgetCaption " + widgetHandle + " = " + caption, true);
	LibMain::getInstance()->setWidgetCaption(widgetHandle, caption);

}

ExternalAPI_GPScriptFunctionDefinition GPScriptFunctionsList[] = {
    {"AddTwo", 				"a : integer, b :integer", 							"Returns Integer", "Add the integers", addtwo},
    {"loadGPPreset", 		"handle : string, preset : string", 				"", "Load GPPreset for a plugin", GPCB_loadGPPreset},
    {"setPluginParam", 		"handle : string, paramIndex : int, value : double","", "Set param for a plugin", GPCB_setPluginParam},
    {"setPluginBypass", 	"handle : string, value : double", 					"", "Set bypass for a plugin", GPCB_setPluginBypass},
    {"showPlugin",		 	"handle : string, value : double", 					"", "Show/Hide plugin", GPCB_showPlugin},
    {"setWidgetValue", 		"handle : string, value : double", 					"", "Set value of a Widget", GPCB_setWidgetValue},
    {"setWidgetCaption", 	"handle : string, caption : string", 				"", "Set caption of a Widget", GPCB_setWidgetCaption},
};