# apt-get install gcc-mingw-w64-x86-64 -y

file="DiskUtilsLinux"

mkdir build

# Linux x64
echo "Building for Linux x64..."
x86_64-linux-gnu-gcc -O2 -static-libgcc -m64 -c -fpic $file.c || exit 1
x86_64-linux-gnu-gcc -O2 -static-libgcc -m64 -shared -o build/lib$file.so $file.o || exit 1
strip --strip-debug build/lib$file.so || exit 1

rm $file.o || exit 1
echo "---FINISHED---"
