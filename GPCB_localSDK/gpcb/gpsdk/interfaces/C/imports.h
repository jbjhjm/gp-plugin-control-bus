#pragma once


/*
   These are functions implemented inside Gig Performer and may be called by a DLL
*/


#include "GPTypes.h"


#ifdef __cplusplus
using namespace DeskewGP;
#endif

typedef
    int (*TGP_GetPathToMe)(LibraryHandle h, char* returnBuffer, int bufferLength);


typedef
    int (*TGP_GetPluginList)(LibraryHandle h, char* returnBuffer, int bufferLength, bool useGlobalRackspace);
    
typedef
   bool (*TGP_PluginExists)(LibraryHandle h, const char*  pluginHandle, bool useGlobalRackspace);

typedef
   void (*TGP_SetPluginParameter)(LibraryHandle h, const char* pluginHandle, int parameterIndex, double value, bool useGlobalRackspace);

typedef
   double (*TGP_GetPluginParameter)(LibraryHandle h, const char* pluginHandle, int parameterIndex, bool useGlobalRackspace);

typedef
   int (*TGP_GetPluginParameterCount)(LibraryHandle h, const char* pluginHandle, bool useGlobalRackspace);

typedef
   int (*TGP_GetPluginParameterName)(LibraryHandle h, const char* pluginHandle, int parameterIndex, char* returnBuffer, int bufferLength, bool useGlobalRackspace);

typedef
   int (*TGP_GetPluginParameterText)(LibraryHandle h, const char* pluginHandle, int parameterIndex, char* returnBuffer, int bufferLength, bool useGlobalRackspace);

typedef
   int (*TGP_GetPluginCaption)(LibraryHandle h, const char* pluginHandle, char* returnBuffer, int bufferLength, bool useGlobalRackspace);

typedef
   int (*TGP_GetPluginName)(LibraryHandle h, const char* pluginHandle, char* returnBuffer, int bufferLength, bool useGlobalRackspace);

typedef
   bool (*TGP_LoadGPPreset)(LibraryHandle h, const char* pluginHandle, const char* presetName, bool useGlobalRackspace);
////////////////////

typedef
    int (*TGP_GetWidgetList)(LibraryHandle h, char* returnBuffer, int bufferLength, bool useGlobalRackspace);
    
typedef
   bool (*TGP_WidgetExists)(LibraryHandle h, const char*  widgetName);




typedef
   double (*TGP_GetWidgetValue)(LibraryHandle h, const char*  widgetName);

typedef
   double (*TGP_GetWidgetTextValue)(LibraryHandle h, const char*  widgetName, char* returnBuffer, int bufferLength);

typedef
   bool (*TGP_SetWidgetValue)(LibraryHandle h, const char*  widgetName, double newValue);

typedef
   bool (*TGP_SetWidgetCaption)(LibraryHandle h, const char*  widgetName, const char*  newCaption);

typedef
   int (*TGP_GetWidgetCaption)(LibraryHandle h, const char*  widgetName, char* returnBuffer, int bufferLength);

typedef
   void (*TGP_SetWidgetHideOnPresentation)(LibraryHandle h, const char*  widgetName, bool hide);

typedef
   bool (*TGP_GetWidgetHideState)(LibraryHandle h, const char*  widgetName);


typedef
   void (*TGP_MapWidgetToPluginParameter)(LibraryHandle h, const char* widgetName, const char* pluginHandle, int parameterNumber, bool useGlobalRackspace);

typedef
   bool (*TGP_ListenForWidget)(LibraryHandle h, const char*  widgetName, bool listen);

typedef
   bool (*TGP_ListeningForWidget)(LibraryHandle h, const char*  widgetName);


typedef
   int  (*TGP_RGBAToColor)(LibraryHandle h, double red, double green, double blue, double alpha);

typedef
   void  (*TGP_ColorToRGBA)(LibraryHandle h, int color, double* red, double* green, double* blue, double* alpha);

typedef
   void (*TGP_SetWidgetBounds)(LibraryHandle h, const char* widgetName, int left, int top, int width, int height);

typedef
   void (*TGP_GetWidgetBounds)(LibraryHandle h, const char* widgetName, int* left, int* top, int* width, int* height);

typedef
   void (*TGP_SetWidgetFillColor)(LibraryHandle h, const char* widgetName, int color);

typedef
   void (*TGP_SetWidgetOutlineColor)(LibraryHandle h, const char* widgetName, int color);
typedef
   void (*TGP_SetWidgetOutlineThickness)(LibraryHandle h, const char* widgetName, int thickness);
typedef
   void (*TGP_SetWidgetOutlineRoundness)(LibraryHandle h, const char* widgetName, int roundness);   

typedef
   int (*TGP_GetWidgetFillColor)(LibraryHandle h, const char* widgetName);
typedef
   int (*TGP_GetWidgetOutlineColor)(LibraryHandle h, const char* widgetName);
typedef
   int (*TGP_GetWidgetOutlineThickness)(LibraryHandle h, const char* widgetName);
typedef
   int (*TGP_GetWidgetOutlineRoundness)(LibraryHandle h, const char* widgetName);





typedef
   void (*TGP_SetBPM)(LibraryHandle h, double bpm);
typedef
   double (*TGP_GetBPM)(LibraryHandle h);

///////////////////////   

typedef
   void (*TGP_Panic)(LibraryHandle h);

typedef
   bool (*TGP_ListenForMidi)(LibraryHandle h, const char*  deviceName, bool listen);

typedef
   bool (*TGP_ListeningForMidi)(LibraryHandle h, const char*  deviceName);

typedef
   int (*TGP_GetMidiInDeviceCount)(LibraryHandle h);

typedef
   int (*TGP_GetMidiInDeviceName)(LibraryHandle h, int index, char* returnBuffer, int bufferLength);

typedef
   int (*TGP_GetMidiOutDeviceCount)(LibraryHandle h);

typedef
   int (*TGP_GetMidiOutDeviceName)(LibraryHandle h, int index, char* returnBuffer, int bufferLength);

typedef
   int(*TGP_TextToHexString)(LibraryHandle h, const char* text, uint8_t* returnBuffer, int bufferLength);

typedef
   void (*TGP_SendMidiMessageToMidiOutDevice)(LibraryHandle h, const char*  deviceName, const uint8_t*  midiData, int length);

typedef
   void (*TGP_InjectMidiMessageToMidiInputDevice)(LibraryHandle h, const char*  deviceName, const uint8_t*  midiData, int length);

typedef
   void (*TGP_InjectMidiMessageToMidiInputAlias)(LibraryHandle h, const char*  rigManagerAlias, const uint8_t*  midiData, int length);

typedef
   int (*TGP_GetSongCount)(LibraryHandle h);

typedef
   int (*TGP_GetSongName)(LibraryHandle h, int atSongIndex, char* returnBuffer, int bufferLength);

typedef
   int (*TGP_GetArtistName)(LibraryHandle h, int atSongIndex, char* returnBuffer, int bufferLength); 

typedef
   int (*TGP_GetSongKey)(LibraryHandle h, int atSongIndex, char* returnBuffer, int bufferLength); 

typedef
   double (*TGP_GetSongTempo)(LibraryHandle h, int atSongIndex);

typedef 
   int (*TGP_GetChordProFilenameForSong)(LibraryHandle h, int atSongIndex, char *returnBuffer, int bufferLength);

typedef
   int (*TGP_GetCurrentSongIndex)(LibraryHandle h);

typedef
   int (*TGP_GetVariationNameForSongPart)(LibraryHandle h, int atSongIndex, int atPartIndex,char* returnBuffer, int bufferLength);  

typedef
   int (*TGP_GetSongpartCount)(LibraryHandle h, int atSongIndex);

typedef
   int (*TGP_GetSongpartName)(LibraryHandle h, int atSongIndex, int atIndex, char* returnBuffer, int bufferLength);

typedef
   int (*TGP_GetCurrentSongpartIndex)(LibraryHandle h);

typedef
   bool (*TGP_InSetlistMode)(LibraryHandle h);

typedef
   bool (*TGP_SwitchToSong)(LibraryHandle h,int songIndex, int partIndex);

typedef
   bool (*TGP_SwitchToSongPart)(LibraryHandle h,int partIndex);
   
   
typedef
   int (*TGP_GetSetlistCount)(LibraryHandle h);
   
typedef
   int (*TGP_GetSetlistName)(LibraryHandle h, int atSongIndex, char* returnBuffer, int bufferLength);
   
typedef
   int (*TGP_GetCurrentSetlistIndex)(LibraryHandle h);
   
typedef
   bool (*TGP_SwitchToSetlist)(LibraryHandle h,int setlistIndex);
   
   
   

typedef
   void (*TGP_ConsoleLog)(LibraryHandle h,const char*  message);

typedef
   void (*TGP_ScriptLog)(LibraryHandle h,const char*  message, bool openLogWindow);

typedef
   int (*TGP_GetInstanceName)(LibraryHandle h, char* returnBuffer, int bufferLength);

typedef
   void(*TGP_GetCurrentTimeSignature)(LibraryHandle h, int* numerator, int* denominator);

typedef
   int (*TGP_GetRackspaceCount)(LibraryHandle h);
 
typedef
   int (*TGP_GetRackspaceName)(LibraryHandle h, int atIndex, char* returnBuffer, int bufferLength);
 
typedef
   int (*TGP_GetCurrentRackspaceIndex)(LibraryHandle h);
 
typedef
   int (*TGP_GetCurrentVariationIndex)(LibraryHandle h);
 
typedef
   int (*TGP_GetVariationCount)(LibraryHandle h, int atRackspaceIndex);
 
typedef
   int (*TGP_GetVariationName)(LibraryHandle h, int atRackspaceIndex, int atIndex, char* returnBuffer, int bufferLength);

typedef
    bool (*TGP_SwitchToRackspace)(LibraryHandle h, int rackspaceIndex, int variationIndex);

typedef
   bool (*TGP_SwitchToRackspaceName)(LibraryHandle h, const char* rackspaceName, const char* variationName);

typedef
   void (*TGP_SwitchToSetlistView)(LibraryHandle h);

typedef
   void (*TGP_SwitchToWiringView)(LibraryHandle h);

typedef
   void (*TGP_SwitchToPanelView)(LibraryHandle h);


typedef
   int (*TGP_GetRackspaceUuid)(LibraryHandle h, int atIndex, char* returnBuffer, int bufferLength);

typedef
   int (*TGP_GetSongUuid)(LibraryHandle h, int atIndex, char* returnBuffer, int bufferLength);



typedef
   void (*TGP_SetPlayheadState)(LibraryHandle h, bool play);

typedef
   bool (*TGP_GetPlayheadState)(LibraryHandle h);


typedef
   void (*TGP_ShowTuner)(LibraryHandle h, bool show);

typedef 
   bool (*TGP_TunerShowing)(LibraryHandle h);

typedef
   void (*TGP_EnableMetronome)(LibraryHandle h, bool enable);

typedef 
   bool (*TGP_MetronomeEnabled)(LibraryHandle h);

typedef
   bool (*TGP_SaveGigUnconditionally)(LibraryHandle h, bool withTimestamp);

typedef
   bool (*TGP_LoadGigByIndex)(LibraryHandle h, int indexNumber);

typedef
   bool (*TGP_Tap)(LibraryHandle h);   


typedef
   bool (*TGP_Next)(LibraryHandle h);   

typedef
   bool (*TGP_Previous)(LibraryHandle h);   

typedef
   bool (*TGP_ResetWidgetToDefault)(LibraryHandle h, const char*  widgetName, double newDefault);


typedef
    bool (*TGP_RegisterCallback)(LibraryHandle h, const char* callbackName);

typedef
    bool (*TGP_UnregisterCallback)(LibraryHandle h, const char* callbackName);


/* GP Script helper functions */
typedef
   int (*TGP_VM_PopInteger)(GPRuntimeEngine* vm); //     Pop an integer associaed with function argument
typedef
   void (*TGP_VM_PushInteger)(GPRuntimeEngine* vm, int value); //     Push an integer associaed with function argument
typedef
   double (*TGP_VM_PopDouble)(GPRuntimeEngine* vm); //     Pop a double associaed with function argument
typedef
   void (*TGP_VM_PushDouble)(GPRuntimeEngine* vm, double value); //     Push a double associaed with function argument

typedef
   int (*TGP_VM_TopStringLength)(GPRuntimeEngine* vm); //     Get the length of a string that's on the top of the stack
typedef
   void (*TGP_VM_PopString)(GPRuntimeEngine* vm, char* buffer, int bufferLength); //     Pop a string associaed with function argument

typedef
   void (*TGP_VM_PushString)(GPRuntimeEngine * vm, const char* buffer); //     Push a string associaed with function argument
typedef
   bool (*TGP_VM_PopBoolean)(GPRuntimeEngine* vm); //     Pop an boolean associaed with function argument
typedef
   void (*TGP_VM_PushBoolean)(GPRuntimeEngine* vm, bool value); //     Push a boolean associaed with function argument


// These are the extern function variables that can be used to call GP functions
// They will be initialized when GP is started by calling InitializeImportedFunctions(...)    

#ifdef __cplusplus
extern "C"
{
#endif

extern TGP_RegisterCallback                      GP_RegisterCallback;
extern TGP_UnregisterCallback                    GP_UnregisterCallback;

extern TGP_GetPathToMe                           GP_GetPathToMe;

extern TGP_ShowTuner                             GP_ShowTuner;
extern TGP_TunerShowing                          GP_TunerShowing;

extern TGP_EnableMetronome                       GP_EnableMetronome;
extern TGP_MetronomeEnabled                      GP_MetronomeEnabled;

extern TGP_SetPlayheadState                      GP_SetPlayheadState;
extern TGP_GetPlayheadState                      GP_GetPlayheadState;

extern TGP_SwitchToSetlistView                   GP_SwitchToSetlistView;
extern TGP_SwitchToWiringView                    GP_SwitchToWiringView;
extern TGP_SwitchToPanelView                     GP_SwitchToPanelView;

extern TGP_GetPluginList                         GP_GetPluginList;
extern TGP_PluginExists                          GP_PluginExists;
extern TGP_SetPluginParameter                    GP_SetPluginParameter;
extern TGP_GetPluginParameter                    GP_GetPluginParameter;
extern TGP_GetPluginParameterCount               GP_GetPluginParameterCount;
extern TGP_GetPluginParameterName                GP_GetPluginParameterName;
extern TGP_GetPluginParameterText                GP_GetPluginParameterText;
extern TGP_GetPluginCaption                      GP_GetPluginCaption;
extern TGP_GetPluginName                         GP_GetPluginName;
extern TGP_LoadGPPreset                          GP_LoadGPPreset;

extern TGP_GetWidgetList                         GP_GetWidgetList;
extern TGP_WidgetExists                          GP_WidgetExists;
extern TGP_GetWidgetValue                        GP_GetWidgetValue;
extern TGP_GetWidgetTextValue                    GP_GetWidgetTextValue;
extern TGP_SetWidgetValue                        GP_SetWidgetValue;
extern TGP_SetWidgetCaption                      GP_SetWidgetCaption;
extern TGP_GetWidgetCaption                      GP_GetWidgetCaption;

extern TGP_SetWidgetHideOnPresentation           GP_SetWidgetHideOnPresentation;
extern TGP_GetWidgetHideState                    GP_GetWidgetHideState;

extern TGP_ListenForWidget                       GP_ListenForWidget;
extern TGP_ListeningForWidget                    GP_ListeningForWidget;


extern TGP_MapWidgetToPluginParameter            GP_MapWidgetToPluginParameter;

extern TGP_RGBAToColor 			                   GP_RGBAToColor;
extern TGP_ColorToRGBA                           GP_ColorToRGBA;

extern TGP_SetWidgetFillColor 			          GP_SetWidgetFillColor;
extern TGP_SetWidgetOutlineColor 			       GP_SetWidgetOutlineColor;
extern TGP_SetWidgetOutlineThickness 			    GP_SetWidgetOutlineThickness;
extern TGP_SetWidgetOutlineRoundness 			    GP_SetWidgetOutlineRoundness;   

extern TGP_GetWidgetFillColor 			          GP_GetWidgetFillColor;
extern TGP_GetWidgetOutlineColor 			       GP_GetWidgetOutlineColor;
extern TGP_GetWidgetOutlineThickness 			    GP_GetWidgetOutlineThickness;
extern TGP_GetWidgetOutlineRoundness 			    GP_GetWidgetOutlineRoundness;   

extern TGP_GetWidgetBounds                       GP_GetWidgetBounds;
extern TGP_SetWidgetBounds                       GP_SetWidgetBounds;



extern TGP_SetBPM                                GP_SetBPM;
extern TGP_GetBPM                                GP_GetBPM;

extern TGP_Panic                                 GP_Panic;

extern TGP_ListenForMidi                         GP_ListenForMidi;
extern TGP_ListeningForMidi                      GP_ListeningForMidi;
extern TGP_GetMidiInDeviceCount                  GP_GetMidiInDeviceCount;
extern TGP_GetMidiInDeviceName                   GP_GetMidiInDeviceName;
extern TGP_GetMidiOutDeviceCount                 GP_GetMidiOutDeviceCount;
extern TGP_GetMidiOutDeviceName                  GP_GetMidiOutDeviceName;
extern TGP_SendMidiMessageToMidiOutDevice        GP_SendMidiMessageToMidiOutDevice;
extern TGP_TextToHexString                       GP_TextToHexString;
extern TGP_InjectMidiMessageToMidiInputDevice    GP_InjectMidiMessageToMidiInputDevice;
extern TGP_InjectMidiMessageToMidiInputAlias     GP_InjectMidiMessageToMidiInputAlias;
extern TGP_GetSongCount                          GP_GetSongCount;
extern TGP_GetSongName                           GP_GetSongName;
extern TGP_GetArtistName                         GP_GetArtistName;
extern TGP_GetSongKey                            GP_GetSongKey;
extern TGP_GetSongTempo                          GP_GetSongTempo;
extern TGP_GetChordProFilenameForSong            GP_GetChordProFilenameForSong;
extern TGP_GetCurrentSongIndex                   GP_GetCurrentSongIndex;
extern TGP_GetVariationNameForSongPart           GP_GetVariationNameForSongPart;
extern TGP_GetSongpartCount                      GP_GetSongpartCount;
extern TGP_GetSongpartName                       GP_GetSongpartName;
extern TGP_GetCurrentSongpartIndex               GP_GetCurrentSongpartIndex;
extern TGP_InSetlistMode                         GP_InSetlistMode;
extern TGP_SwitchToSong                          GP_SwitchToSong;
extern TGP_SwitchToSongPart                      GP_SwitchToSongPart;

extern TGP_GetSetlistCount                       GP_GetSetlistCount;
extern TGP_GetSetlistName                        GP_GetSetlistName;
extern TGP_GetCurrentSetlistIndex                GP_GetCurrentSetlistIndex;
extern TGP_SwitchToSetlist                       GP_SwitchToSetlist;

extern TGP_ConsoleLog                            GP_ConsoleLog;
extern TGP_ScriptLog                             GP_ScriptLog;
extern TGP_GetInstanceName                       GP_GetInstanceName;
extern TGP_GetCurrentTimeSignature               GP_GetCurrentTimeSignature;

extern TGP_GetRackspaceCount                     GP_GetRackspaceCount;
extern TGP_GetRackspaceName                      GP_GetRackspaceName;
extern TGP_GetCurrentRackspaceIndex              GP_GetCurrentRackspaceIndex;
extern TGP_GetCurrentVariationIndex              GP_GetCurrentVariationIndex;
extern TGP_GetVariationCount                     GP_GetVariationCount;
extern TGP_GetVariationName                      GP_GetVariationName;
extern TGP_SwitchToRackspace                     GP_SwitchToRackspace;
extern TGP_SwitchToRackspaceName                 GP_SwitchToRackspaceName;
extern TGP_SaveGigUnconditionally                GP_SaveGigUnconditionally;
extern TGP_LoadGigByIndex                        GP_LoadGigByIndex;
extern TGP_Tap                                   GP_Tap;
extern TGP_Previous                              GP_Previous;
extern TGP_Next                                  GP_Next;

extern TGP_GetRackspaceUuid                      GP_GetRackspaceUuid;
extern TGP_GetSongUuid                           GP_GetSongUuid;

extern TGP_ResetWidgetToDefault                  GP_ResetWidgetToDefault;



/*GP Script Helper Functions*/
extern TGP_VM_PopInteger                         GP_VM_PopInteger;
extern TGP_VM_PushInteger                        GP_VM_PushInteger;
extern TGP_VM_PopDouble                          GP_VM_PopDouble;
extern TGP_VM_PushDouble                         GP_VM_PushDouble;
extern TGP_VM_TopStringLength                    GP_VM_TopStringLength;
extern TGP_VM_PopString                          GP_VM_PopString;
extern TGP_VM_PushString                         GP_VM_PushString;
extern TGP_VM_PopBoolean                         GP_VM_PopBoolean;
extern TGP_VM_PushBoolean                        GP_VM_PushBoolean;




extern void InitializeImportedFunctions(LibraryHandle handle, TGetGPFunctionType getGPFunction); // Call this to initialize all the function variables defined below


#ifdef __cplusplus
}
#endif


