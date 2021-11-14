cd "`dirname $0`//.."

if [ ! -d "build" ]; then
    script/build.sh
fi
cd build

if [ ! -d "bin" ]; then
    source script/build.sh
fi

bin/s1mpleEngine

cd ..