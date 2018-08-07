#!/bin/bash
set -e
PROJECT_HOME=$( dirname "$( cd "$( dirname "$0" )" && pwd )" )
function exit_error {
    printf "%s\n" "$*" >&2;
    exit -1;
}



L_EXT=so
if [[ ! -z $MINGW_PREFIX ]]; then
    L_EXT=dll
fi

cd $PROJECT_HOME
echo "Ensuring project dependencies are installed"
if [[ ! -d $PROJECT_HOME/moonglfw ]] || [[ ! -d $PROJECT_HOME/nanovg ]] || [[ ! -d $PROJECT_HOME/nanosvg ]]; then
    git submodule init
    git submodule update
fi
cd .

# resolving build tools
LUA=lua5.3
LUAROCKS=3.0.0
source $PROJECT_HOME/scripts/setup_lua.sh

exit 0

NVG_MAIN=$PROJECT_HOME/nvg.$L_EXT
MOONGLFW_MAIN=$PROJECT_HOME/moonglfw.$L_EXT

echo "Checking if $NVG_MAIN exists"
if [[ ! -f $NVG_MAIN ]]; then
    exit_error "NanoVG build is missing from $NVG_MAIN"
fi

echo "Checking if $MOONGLFW_MAIN exists"
if [[ ! -f $MOONGLFW_MAIN ]]; then
    exit_error "MoonGLFW build is missing from $MOONGLFW_MAIN"
fi

echo "All tests passed"
