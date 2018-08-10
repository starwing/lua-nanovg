#!/bin/bash
set -e
PROJECT_HOME=$( dirname "$( cd "$( dirname "$0" )" && pwd )" )
source $PROJECT_HOME/scripts/setup.sh
cd $PROJECT_HOME

echo "Resolving dependencies"

if [[ "${machine}" == "Linux" ]]; then
    sudo apt-get install -y \
        asciidoctor \
        ruby-pygments.rb \
        libglfw3-dev \
        xvfb \
        libgl1-mesa-dev \
        libosmesa6-dev \
        libgles2-mesa-dev \
        libgles2-mesa-dev \
        libgles2-mesa-dev \
        mesa-utils \
        mesa-utils-extra \
        libreadline-dev \
        unzip \
        curl \
        libcurl3-gnutls-dev \
        lua5.3 \
        liblua5.3 \
        liblua5.3-0 \
        liblua5.3-dev \
        luarocks
    # sudo easy_install pip
fi

# Homebrew
if [[ "${machine}" == "OSX" ]]; then
    brew install glfw
fi

if [[ "${machine}" == "Windows" ]]; then
    pacman -S --noconfirm mingw-w64-x86_64-glfw \
        mingw64/mingw-w64-x86_64-glew \
        mingw64/mingw-w64-x86_64-mesa \
        mingw64/mingw-w64-x86_64-asciidoctor \
        mingw64/mingw-w64-x86_64-lua \
        mingw64/mingw-w64-x86_64-lua51-luarocks
    # mingw64/mingw-w64-x86_64-python2-pip
fi

# pip install --user hererocks urllib3[secure] cpp-coveralls
# hererocks /tmp/env --lua $L_LU -rlatest
# source /tmp/env/bin/activate
