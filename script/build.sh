cd "`dirname $0`//.."

if [ ! -d "build" ]; then
    mkdir build
fi
cd build

echo "Configuring & generating cmake project..."
cmake .. > cmake.log
if [ $? -ne 0 ]; then
    exit $?
fi

echo "Building targets..."
make -j8 > make.log
if [ $? -ne 0 ]; then
    exit $?
fi

echo "Rearranging binaries..."
if [ ! -d "bin" ]; then
    mkdir bin
fi
cp test/deps/sf.spv bin
cp test/deps/sv.spv bin

echo "Done."
cd ..