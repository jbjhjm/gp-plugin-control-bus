# GP Extension - Plugin Control Bus

Rackspace-level scripts are allowed to access plugins when they have a handle assigned their handles.
In most situations, plugin control via widget bindings and rackspace-level script automation is sufficient.
In complex setups with many dynamic controls, the only current alternative is to communicate via OSC to circumvent the limitations.
However, using OSC means the application sends and receives messages to itself on a port, and OSC can fail to initialize.
This extension aims to provide an alternative via a set of GPScript functions that can be used to configurate plugins without needing OSC.

## How to use

Soon...

## How to build...

### ... on macOS

-   Make sure you have [CMake](https://cmake.org) installed.
    You might have to add the path to the cmake executable by adding this line to your bash profile:

    ```bash
    export PATH=/Applications/CMake.app/Contents/bin:$PATH
    ```

    Alternatively, you can install CMake via [Homebrew](https://brew.sh):

    ```bash
    brew install cmake
    ```

-   Build (and install) the project via CMake.
    For your convenience we have provided a `build.sh` which contains all necessary commands:

    ```bash
    ./build.sh
    ```

### ... on Windows

-   Make sure you have [CMake](https://cmake.org), [Git](https://git-scm.com) and a C(++) compiler installed.
    You can get that for example by installing [Visual Studio](https://visualstudio.microsoft.com) with the _Desktop development with C++_ workload and the _Git for Windows_ component.
-   Build (and install) the project via CMake.
    For your convenience we have provided a `build.cmd` which contains all necessary commands:

    ```bash
    build.cmd
    ```

    **Make sure to run the script from the Visual Studio developer command prompt!**
