#! /bin/bash
set -e
PROJECT_HOME=$( dirname "$( cd "$( dirname "$0" )" && pwd )" )
T_BD=${TRAVIS_BUILD_DIR:-}
if [[ -z $T_BD ]]; then
  T_BD=$PROJECT_HOME/build
else
  T_BD=$TRAVIS_BUILD_DIR/build
fi
L_LU=${LUA:-}
if [[ -z $L_LU ]]; then
  L_LU=5.3
fi
L_RK=${LUAROCKS:-}
if [[ -z $L_RK ]]; then
  L_RK=3.0.0
fi
echo "Decoded environment Lua $L_LU and Lua rocks $L_RK"
source $PROJECT_HOME/scripts/platform.sh
LUA_HOME_DIR=$T_BD/install/lua
LR_HOME_DIR=$T_BD/install/luarocks
echo "Ensuring build directory in $T_BD"
mkdir -p $T_BD
if [[ ! -d $T_BD ]];then
  echo "Cannot ensure build directory"
  exit 1
fi
echo "Ensuring lua local packages dir in $HOME/.lua and $HOME/.luarocks"
mkdir -p $HOME/.lua
mkdir -p $HOME/.luarocks
echo "Ensuring lua local home dir in $LUA_HOME_DIR"
mkdir -p "$LUA_HOME_DIR"
# Lua 5.x
LUASRC_BASE=5.3.5
if [ "$L_LU" == "5.1" ]; then
  LUASRC_BASE=5.1.5
elif [ "$L_LU" == "5.2" ]; then
  LUASRC_BASE=5.2.4
elif [ "$L_LU" == "5.3" ]; then
  LUASRC_BASE=5.3.5
fi
LUASRC_BAS=lua-$LUASRC_BASE.tar.gz
LUASRC_PKG="https://www.lua.org/ftp/$LUASRC_BAS"
echo "Ensuring lua $LUASRC_BASE from $LUASRC_PKG in $T_BD/$LUASRC_BAS"
cd $T_BD
if [[ ! -f $T_BD/$LUASRC_BAS ]]; then
  curl --location $LUASRC_PKG -o $T_BD/$LUASRC_BAS
  tar zxf $LUASRC_BAS
fi
cd $T_BD/lua-$LUASRC_BASE
# Build Lua without backwards compatibility for testing
perl -i -pe 's/-DLUA_COMPAT_(ALL|5_2)//' src/Makefile
make $PLATFORM clean
make $PLATFORM MYCFLAGS=-fPIC && make INSTALL_TOP="$LUA_HOME_DIR" install;
rm -f $HOME/.lua/lua
ln -sf $LUA_HOME_DIR/bin/lua $HOME/.lua/lua
rm -f $HOME/.lua/luac
ln -sf $LUA_HOME_DIR/bin/luac $HOME/.lua/luac
# Luarocks
LUARKSRC_BAS=luarocks-$L_RK.tar.gz
LUARKSRC_PKG="http://luarocks.github.io/luarocks/releases/$LUARKSRC_BAS"
echo "Ensuring lua $LUARKSRC_BAS from $LUARKSRC_PKG in $T_BD/$LUARKSRC_BAS"
cd $T_BD
if [[ ! -f $T_BD/$LUARKSRC_BAS ]]; then
  curl --location $LUARKSRC_PKG -o $T_BD/$LUARKSRC_BAS
  tar zxf $LUARKSRC_BAS
fi
cd $T_BD/luarocks-$L_RK
./configure --with-lua="$LUA_HOME_DIR" --prefix="$LR_HOME_DIR"
make build && make install
rm -f $HOME/.lua/luarocks
ln -sf $LR_HOME_DIR/bin/luarocks $HOME/.lua/luarocks
# Return
cd $T_BD
# Lua deps
PATH=$HOME/.lua:$HOME/.luarocks/bin:$PATH
echo "Path altered - checking lua and luarocks PATH=$PATH"
echo "Listing lua programs"
ls -l $HOME/.lua
echo "Listing lua rocks"
ls -l $HOME/.luarocks
echo "Checking lua interpreter version"
lua -v
echo "Checking lua rocks version"
luarocks --version
echo "Installing rock: Lua-cURL"
luarocks --local install Lua-cURL --server=https://luarocks.org/dev
echo "Installing rock: luacov-coveralls"
luarocks --local install luacov-coveralls --server=https://luarocks.org/dev
echo "Installing rock: lunitx"
luarocks --local install lunitx
echo "Dependencies are now installed"
echo "Lua installation directory: $PROJECT_HOME/build/install/lua"
ls -l $PROJECT_HOME/build/install/lua
echo "Lua rocks installation directory: $PROJECT_HOME/build/install/luarocks"
ls -l $PROJECT_HOME/build/install/luarocks
