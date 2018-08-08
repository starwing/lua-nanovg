#! /bin/bash
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

if [[ "${machine}" == "Linux" ]]; then
    sudo apt-get update
    sudo apt-get upgrade -y
    sudo apt-get install -y libglfw3-dev xvfb libgl1-mesa-dev libosmesa6-dev libgles2-mesa-dev libgles2-mesa-dev libgles2-mesa-dev mesa-utils mesa-utils-extra
fi

# Homebrew
if [[ "${machine}" == "OSX" ]]; then
    brew install glfw
fi

if [[ "${machine}" == "Windows" ]]; then
    pacman -S --noconfirm mingw-w64-x86_64-glfw
fi
