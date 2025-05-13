#include "LibMain.h"


// List of panels
std::vector<std::string> panelNames = { "Red", "Yellow", "Blue"};
std::vector<std::string> relativePanelLocations = { "Red.gppanel", "Yellow.gppanel", "Blue.gppanel" };




std::string pathToMe; // This needs to be initialized from the initialization secttion of the LibMain class so it can be used in the standalone functions directly below

int LibMain::GetPanelCount()
{
   return panelNames.size();
}

 std::string  LibMain::GetPanelName(int index)
{
   std::string text; 
   if (index >= 0 && index < panelNames.size())
      then text = panelNames[index];
         
   return text;      
}

// Return panel layout in XML format
 std::string  LibMain::GetPanelXML(int index) 
{
   std::string text;
   if (index >= 0 && index < panelNames.size())
      then
         {
            // We assume the panels are in the same folder as the library
            GPUtils::loadTextFile(getPathToMe() + "/" + relativePanelLocations[index], text );
         }
   return text;
}



// List of menu items
std::vector<std::string> menuNames = { "Show Front Panels", "Show Back Wiring", "Show Setlists"};


int LibMain::GetMenuCount()
{
   return menuNames.size();
}

 std::string  LibMain::GetMenuName(int index)
{
   std::string text;
   if (index >= 0 && index < menuNames.size())
      then text =  menuNames[index];
         
   return text;      
}


void LibMain::InvokeMenu(int index)
{
   if (index >= 0 && index < menuNames.size())
      then
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
                           
                  default:
                     break;   
               }
         }

}



extern "C" void addthree(GPRuntimeEngine* vm)
{
   int c = GP_VM_PopInteger(vm);

   int b = GP_VM_PopInteger(vm);
   int a = GP_VM_PopInteger(vm);
   GP_VM_PushInteger(vm, a + b + c);
}






   
ExternaAPI_GPScriptFunctionDefinition functionList[] =
   {
      {"AddThree",         "a : integer, b :integer, c : integer",  "Returns Integer",     "Add the integers",      addthree},
   };



int LibMain::RequestGPScriptFunctionSignatureList(GPScript_AllowedLocations location,  ExternaAPI_GPScriptFunctionDefinition* *list)
{
   // Allow these in ANY script so no need to check the location field  
   *list = functionList;
   int count = sizeof(functionList) / sizeof(ExternaAPI_GPScriptFunctionDefinition);
   return count; 


}