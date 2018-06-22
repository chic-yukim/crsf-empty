# Empty Project for CRSF

## Getting Started
1. Download CRSF from http://crseed.org
2. Extract the archive to "crsf" directory.

### Visual Studio 2013
3. Setup project using CMake
4. Build and run the project
   - You should set the project using `Set as StartUp Project`.
   - You may choose Project configuration as `RelWithDebInfo` or `Release`.

### Visual Studio 2017
3. Run `bootstrap.bat` file (**This takes over 20 minutes depending on your system**)
   - This batch file will clone [vcpkg](https://github.com/Microsoft/vcpkg) project.
   - And then, vcpkg will build and install third party libraries.
4. Setup project using CMake **with vcpkg toolchain file**
   1. In CMake GUI, select proper Visual Studio generator
   2. select **Specify toolchain file for cross-compiling**
   3. Specify vcpkg toolchain file. ex) `vcpkg/scripts/buildsystems/vcpkg.cmake`
   4. Finish
5. Build and run the project
   - You should set the project using `Set as StartUp Project`.
   - You may choose Project configuration as `Debug`, `RelWithDebInfo` or `Release`.



## Customizing
### Directory Name
You should edit a value of `add_subdirectory` in `CMakeLists.txt`

### Project Name (Module ID)
1. Change a value of `CRMODULE_ID` in `empty-project/CMakeLists.txt` file.
2. Change contents in `empty-project/config.json`.
3. Change `<id>` tag value in `empty-project/config/SystemConfiguration.xml` file.
   - Without this, the application will print error message.
4. Change tag name in `empty-project/config/DynamicModuleConfiguration.xml` file if the tag exists.
