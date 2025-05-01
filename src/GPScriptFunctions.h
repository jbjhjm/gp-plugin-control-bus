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

}

extern "C" void GPCB_setPluginParam(GPRuntimeEngine *vm)
{

	double paramValue = GP_VM_PopDouble(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string paramName = buffer;

    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	char paramValueString[20];
	gcvt(paramValue, 10, paramValueString);

	LibMain::getInstance()->scriptLog("GPCB_setPluginParam " + pluginHandle + " - " + paramName + "=" + paramValueString, true);

}

extern "C" void GPCB_setPluginBypass(GPRuntimeEngine *vm)
{

	double paramValue = GP_VM_PopDouble(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	LibMain::getInstance()->scriptLog("GPCB_setPluginBypass " + pluginHandle + " = " + (paramValue > 0.5 ? "true" : "false"), true);

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

}

extern "C" void GPCB_setWidgetCaption(GPRuntimeEngine *vm)
{
	
	char buffer[100];

	GP_VM_PopString(vm, buffer, 100);
    std::string caption = buffer;

    GP_VM_PopString(vm, buffer, 100);
    std::string widgetHandle = buffer;

	LibMain::getInstance()->scriptLog("GPCB_setWidgetCaption " + widgetHandle + " = " + caption, true);

}

// extern "C" void subtracttwo(GPRuntimeEngine *vm)
// {
//     int b = GP_VM_PopInteger(vm);
//     int a = GP_VM_PopInteger(vm);
//     GP_VM_PushInteger(vm, a - b);
// }

// extern "C" void Increment(GPRuntimeEngine *vm)
// {
//     int a = GP_VM_PopInteger(vm);
//     GP_VM_PushInteger(vm, a + 1);
// }

// extern "C" void DupString(GPRuntimeEngine *vm)
// {
//     char buffer[100];
//     GP_VM_PopString(vm, buffer, 100);
//     std::string s = buffer;
//     s = s + s;

//     GP_VM_PushString(vm, s.c_str());
// }

ExternalAPI_GPScriptFunctionDefinition GPScriptFunctionsList[] = {
    {"AddTwo", 				"a : integer, b :integer", 							"Returns Integer", "Add the integers", addtwo},
    {"loadGPPreset", 		"handle : string, preset : string", 				"", "Load GPPreset for a plugin", GPCB_loadGPPreset},
    {"setPluginParam", 		"handle : string, param : string, value : double", 	"", "Set param for a plugin", GPCB_setPluginParam},
    {"setPluginBypass", 	"handle : string, value : double", 					"", "Set bypass for a plugin", GPCB_setPluginBypass},
    {"setWidgetValue", 		"handle : string, value : double", 					"", "Set value of a Widget", GPCB_setWidgetValue},
    {"setWidgetCaption", 	"handle : string, caption : string", 				"", "Set caption of a Widget", GPCB_setWidgetCaption},
    // {"SubtractTwo", "a : integer,b :integer", "Returns Integer", "Subtract the integers", subtracttwo},
    // {"Increment", "a : integer", "Returns Integer", "Increment incoming value", Increment},
    // {"DupString", "a : String", "Returns String", "Return with the string twice", DupString},
};