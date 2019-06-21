# PlayFab-CPP-SDK-Test

Temporary solution:

1. Download [PlayFab Cross-Platform C++ SDK](https://github.com/PlayFab/XPlatCppSdk) form Github, then Open this project in the VS, and compile for X86 platform.

2. Create a new C++ console project, and install package "com.playfab.xplatcppsdk.vXXX." by Nuget.

3. Right-click on a project node (not the top-level solution) and choose Properties, in the left pane of the Property Pages dialog box, select **Configuration Properties** > **VC++ Directories**. In this page, add the path to the directory where the Json cpp .lib file(**lib_json.lib** and **lib_json.pdb**) is located in **Library Directories**

   - [YourFolderPath]\XPlatCppSdk\build\Windows\[Building
   Platform]\Debug\lib_json.lib
   - [YourFolderPath]\XPlatCppSdk\build\Windows\[Building
   Platform]\Debug\lib_json.pdb

4. In the **Linker** > **Input** property page, add the name of the .lib file(**lib_json.lib**) to **Additional Dependencies**.

5. Replace the contents of main function ref https://docs.microsoft.com/en-us/gaming/playfab/sdks/xplatcpp/quickstart-windows#set-up-your-first-api-call

6. Compile and click error output, locate to PlayFabJsonHeaders.h file inside nuget package folders, change
    ```
    #include <json/json.h>

    #include <json/reader.h>

    #include <json/value.h>

    to

    #include <json.h>

    #include <reader.h>

    #include <value.h>
    ```
Reference:

- https://community.playfab.com/questions/28828/what-are-the-json-cpp-packages-needed-for-the-c-sd.html
- https://github.com/PlayFab/XPlatCppSdk