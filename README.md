# Empty Project for CRSF

## Getting Started
1. Download CRSF from http://crseed.org
2. Extract the archive to "crsf" directory.
3. Setup project using CMake
4. Build and run the project
   - You should set the project using `Set as StartUp Project`.


## Customizing
### Directory Name
You should edit the name in `CMakeLists.txt`

### Project Name (Module ID)
1. Change `CRMODULE_ID` in `empty-project/CMakeLists.txt` file.
2. Change contents in `empty-project/config.json`.
3. Change `<id>` tag value in `empty-project/config/SystemConfiguration.xml` file.
   - Without this, the application will prints error message.
4. Change tag name in `empty-project/config/DynamicModuleConfiguration.xml` file if the tag exists.
