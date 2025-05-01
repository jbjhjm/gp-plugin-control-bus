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

extern "C" void PCB_loadGPPreset(GPRuntimeEngine *vm)
{
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string presetName = buffer;

    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	LibMain::getInstance()->scriptLog("PCB_loadGPPreset " + pluginHandle + " - " + presetName, true);

}

extern "C" void PCB_setPluginParam(GPRuntimeEngine *vm)
{

	double paramValue = GP_VM_PopDouble(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string paramName = buffer;

    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	char paramValueString[20];
	gcvt(paramValue, 10, paramValueString);

	LibMain::getInstance()->scriptLog("PCB_setPluginParam " + pluginHandle + " - " + paramName + "=" + paramValueString, true);

}

extern "C" void PCB_setPluginBypass(GPRuntimeEngine *vm)
{

	double paramValue = GP_VM_PopDouble(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string pluginHandle = buffer;

	LibMain::getInstance()->scriptLog("PCB_setPluginBypass " + pluginHandle + " = " + (paramValue > 0.0 ? "true" : "false"), true);

}

extern "C" void PCB_setWidgetValue(GPRuntimeEngine *vm)
{

	double value = GP_VM_PopDouble(vm);
	
	char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string widgetHandle = buffer;

	char valueString[20];
	gcvt(value, 10, valueString);

	LibMain::getInstance()->scriptLog("PCB_setWidgetValue " + widgetHandle + " = " + valueString, true);

}

extern "C" void PCB_setWidgetCaption(GPRuntimeEngine *vm)
{
	
	char buffer[100];

	GP_VM_PopString(vm, buffer, 100);
    std::string caption = buffer;

    GP_VM_PopString(vm, buffer, 100);
    std::string widgetHandle = buffer;

	LibMain::getInstance()->scriptLog("PCB_setWidgetCaption " + widgetHandle + " = " + caption, true);

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
    {"AddTwo", "a : integer, b :integer", "Returns Integer", "Add the integers", addtwo},
    {"PCB_loadGPPreset", "handle : string, preset : string", "Returns void", "Load GPPreset for a plugin", PCB_loadGPPreset},
    {"PCB_setPluginParam", "handle : string, param : string, value : double", "Returns void", "Set param for a plugin", PCB_setPluginParam},
    {"PCB_setPluginBypass", "handle : string, value : double", "Returns void", "Set bypass for a plugin", PCB_setPluginBypass},
    {"PCB_setWidgetValue", "handle : string, value : double", "Returns void", "Set value of a Widget", PCB_setWidgetValue},
    {"PCB_setWidgetCaption", "handle : string, caption : string", "Returns void", "Set caption of a Widget", PCB_setWidgetCaption},
    // {"SubtractTwo", "a : integer,b :integer", "Returns Integer", "Subtract the integers", subtracttwo},
    // {"Increment", "a : integer", "Returns Integer", "Increment incoming value", Increment},
    // {"DupString", "a : String", "Returns String", "Return with the string twice", DupString},
};