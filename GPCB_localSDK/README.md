## SDK setup

All files are included in the project.
After setting up dependencies as described in [Root README](../README.md), you can immediately run build.cmd.

The extension requires use of a singleton pattern which is not possible with the extension entrypoint as defined in the "local SDK" variant.
(It was calling the class ctor directly instead of using a factory function CreateGPExtension, as the Github SDK does).

Thus to make it work, the SDK had to be modified manually.

### Modifications

- CreateGPExtension added to GigPerformerAPI.h (without namespace)
- entry.cpp replaced by the version from github
  - with corrected include paths

## How to build by CLI...

### ... on Windows

-   Make sure you have [CMake](https://cmake.org), [Git](https://git-scm.com) and a C(++) compiler installed.
    You can get that for example by installing [Visual Studio](https://visualstudio.microsoft.com) with the _Desktop development with C++_ workload and the _Git for Windows_ component.
-   Build (and install) the project via CMake.
    For your convenience we have provided a `build.cmd` which contains all necessary commands:

    ```bash
    build.cmd
    ```

    **Make sure to run the script from the Visual Studio developer command prompt!**

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
