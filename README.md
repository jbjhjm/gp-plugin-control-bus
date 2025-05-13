# GP Extension - Plugin Control Bus

Rackspace-level scripts are allowed to access plugins when they have a handle assigned their handles.
In most situations, plugin control via widget bindings and rackspace-level script automation is sufficient.
In complex setups with many dynamic controls, the only current alternative is to communicate via OSC to circumvent the limitations.
However, using OSC means the application sends and receives messages to itself on a port, and OSC can fail to initialize.
This extension aims to provide an alternative via a set of GPScript functions that can be used to configurate plugins without needing OSC.

## How to use

Soon...

## Building + SDK

The repository currently contains 2 separate variations of the project, because of terribly messed up Gig Performer SDK versions:

_GPCB_GithubSDK_ uses cmake to auto-fetch a SDK copy from github.
However, the most recent SDK additions have not been published, so some functions that the GPCB aims to provide were unavailable.
For that reason, we switched (maybe temporarily) to the other SDK.

_GPCB_localSDK_ is based on a "recent" SDK which was provided as a zip archive in forums.
It does include most recent functional additions, but is structured differently and is missing other aspects:
No namespacing, no extension factory function, examples still targeting VS 2019.

## Project + compiler setup

## Dependencies

Install Visual Studio Build Tools with C++ desktop development workload and Components 
If winget is set up correctly, you can install all using `winget install Microsoft.VisualStudio.2022.BuildTools --force --override "--wait --passive --add Microsoft.VisualStudio.Workload.VCTools --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 --add Microsoft.VisualStudio.Component.Windows10SDK"` 

## VS Code

vscode must be started from VS command prompt to find needed tools in env.
To do so, run "Developer Command Prompt for VS20XX". CLI should open. Execute `code x:\path\to\repo` to launch VS with C++ env.

Run vscode command "Select IntelliSense Configuration", to see if a compiler was found.

To compile, open terminal and execute ./build.cmd.

