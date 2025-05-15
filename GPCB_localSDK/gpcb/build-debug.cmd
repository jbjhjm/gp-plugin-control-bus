::Create a build directory if it's not already there
mkdir build

::Change to the build directory
cd build

::Create the configuration file using cmake
cmake ..

::Now build the project in DEBUG mode.
cmake --build .

::All going well, you should now have a DLL in the Debug folder
::So now copy it to the location where GP can find it
:: Path is different due to JUCE setup!
:: https://forum.juce.com/t/cmake-generating-a-strange-postfix-entitled-artefacts/41443/2

mkdir "C:\Users\Public\Documents\Gig Performer\Extensions"
copy GPCB_artefacts\Debug\*.dll "%PUBLIC%\Documents\Gig Performer\Extensions"

::For RELEASE build please replace the "Debug" folder reference with "Release"

::Go back to the starting folder
cd ..

rem
rem ********************************************
rem Extension built and installed into "%PUBLIC%\Documents\Gig Performer\Extensions"
rem ********************************************

