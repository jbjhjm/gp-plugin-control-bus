#pragma once

#include "gigperformer/sdk/GPMidiMessages.h"
#include "gigperformer/sdk/GPUtils.h"
#include "gigperformer/sdk/GigPerformerAPI.h"
#include "gigperformer/sdk/types.h"
#include "LibMain.h"
#include <stdexcept>

extern "C" void addtwo(GPRuntimeEngine *vm)
{
	LibMain::getInstance();
    int b = GP_VM_PopInteger(vm);
    int a = GP_VM_PopInteger(vm);
    GP_VM_PushInteger(vm, a + b);
}

extern "C" void subtracttwo(GPRuntimeEngine *vm)
{
    int b = GP_VM_PopInteger(vm);
    int a = GP_VM_PopInteger(vm);
    GP_VM_PushInteger(vm, a - b);
}

extern "C" void Increment(GPRuntimeEngine *vm)
{
    int a = GP_VM_PopInteger(vm);
    GP_VM_PushInteger(vm, a + 1);
}

extern "C" void DupString(GPRuntimeEngine *vm)
{
    char buffer[100];
    GP_VM_PopString(vm, buffer, 100);
    std::string s = buffer;
    s = s + s;

    GP_VM_PushString(vm, s.c_str());
}

ExternalAPI_GPScriptFunctionDefinition GPScriptFunctionsList[] = {
    {"AddTwo", "a : integer, b :integer", "Returns Integer", "Add the integers", addtwo},
    {"SubtractTwo", "a : integer,b :integer", "Returns Integer", "Subtract the integers", subtracttwo},
    {"Increment", "a : integer", "Returns Integer", "Increment incoming value", Increment},
    {"DupString", "a : String", "Returns String", "Return with the string twice", DupString},
};