# CMake + vcpkg cross-compile quick start

Here are the commands I ran to get this working. You may not need to do all of them, e.g. if you already have a vcpkg installation you should only need to make sure `VCPKG_ROOT` is set correctly.


```sh
# Clone vcpkg
git clone https://github.com/microsoft/vcpkg "$HOME/vcpkg"

# Configure env
export VCPKG_ROOT="$HOME/vcpkg"
export PATH=$VCPKG_ROOT:$PATH

# Install the vcpkg binary
cd $VCPKG_ROOT
./bootstrap-vcpkg.sh

# Clone the sample project
git clone https://github.com/bsiegel/cmake-vcpkg-ios-sampleproj.git <path to sample project>
cd <path to sample project>

# This will run vcpkg and download / compile the Azure SDK libraries
cmake --preset macos

# This will compile the sample app in main.cpp
cmake --build --preset macos

# Run the sample app
build/macos/main

# Now for cross-compile! (here we do both debug and release builds)
cmake --preset ios -G Xcode
cmake --build --preset ios
cmake --build --preset ios --config Release

# Sample app should now exist at build/ios/{Debug|Release}-iphoneos/main.app

# And the simulator
cmake --preset simulator -G Xcode
cmake --build --preset simulator
cmake --build --preset simulator --config Release

# Sample app should now exist at build/simulator/{Debug|Release}-iphonesimulator/main.app
```
