#!/bin/bash
set -e
PROJECT_HOME=$( dirname "$( cd "$( dirname "$0" )" && pwd )" )
unameOut="$(uname -s)"
case "${unameOut}" in
    Linux*)     machine=Linux;;
    Darwin*)    machine=OSX;;
    CYGWIN*)    machine=Windows;;
    MINGW*)     machine=Windows;;
    *)          machine="UNKNOWN:${unameOut}"
esac
function exit_error {
    printf "%s\n" "$*" >&2;
    exit -1;
}
L_EXT=so
if [[ ! -z $MINGW_PREFIX ]]; then
    L_EXT=dll
fi
cd $PROJECT_HOME
echo "Listing project files"
ls -l $PROJECT_HOME/build
echo "Build project PROJECT_HOME=$PROJECT_HOME"
CI=true PROJECT_HOME=$PROJECT_HOME make
# resolving build tools
NVG_MAIN=$PROJECT_HOME/nvg.$L_EXT
echo "Checking if $NVG_MAIN exists"
if [[ ! -f $NVG_MAIN ]]; then
    exit_error "NanoVG build is missing from $NVG_MAIN"
fi
MOONGLFW_MAIN=$PROJECT_HOME/moonglfw.$L_EXT
echo "Checking if $MOONGLFW_MAIN exists"
if [[ ! -f $MOONGLFW_MAIN ]]; then
    exit_error "MoonGLFW build is missing from $MOONGLFW_MAIN"
fi
PATH=$HOME/.lua:$HOME/.luarocks/bin:$PATH
echo "Path altered - checking lua and luarocks PATH=$PATH"
    echo "Running tests"
if [[ "${machine}" == "Linux" ]]; then
    echo "Starting X virtual framebuffer server"
    sudo Xvfb :100 -screen 0 1600x1200x16 &
    export DISPLAY=:100
    # Wait for Xvfb
    MAX_ATTEMPTS=120
    COUNT=0
    echo -n "Waiting for Xvfb to be ready..."
    while ! xdpyinfo -display $DISPLAY >/dev/null 2>&1; do
        echo -n "."
        sleep 0.50s
        COUNT=$(( COUNT + 1 ))
        if [ "${COUNT}" -ge "${MAX_ATTEMPTS}" ]; then
            echo "  Gave up waiting for X server on $DISPLAY"
            exit 1
        fi
    done
fi
eval "$(luarocks path)"
lunit.sh -i $HOME/.lua/lua $PROJECT_HOME/test/test.lua
echo "Testing finished"
