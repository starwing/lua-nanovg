#! /bin/bash
set -e
PROJECT_HOME=$( dirname "$( cd "$( dirname "$0" )" && pwd )" )
T_BD=${TRAVIS_BUILD_DIR:-}
if [[ -z $T_BD ]]; then
  T_BD=$PROJECT_HOME/build
fi

source $PROJECT_HOME/scripts/platform.sh

LUA_HOME_DIR=$T_BD/install/lua
LR_HOME_DIR=$T_BD/install/luarocks

mkdir -p $T_BD
mkdir -p $HOME/.lua
mkdir -p "$LUA_HOME_DIR"
LUASRC_BASE=5.0.0
if [ "$LUA" == "lua5.1" ]; then
  LUASRC_BASE=5.1.5
elif [ "$LUA" == "lua5.2" ]; then
  LUASRC_BASE=5.2.4
elif [ "$LUA" == "lua5.3" ]; then
  LUASRC_BASE=5.3.5
fi
LUASRC_PKG=https://www.lua.org/ftp/lua-$LUASRC_BASE.tar.gz
echo "Ensuring lua $LUASRC_BASE from $LUASRC_PKG"

if [[ ! -d $T_BD/$LUASRC_BASE ]]; then 
  curl --location $LUASRC_PKG -o $T_BD/lua-$LUASRC_BASE.tar.gz
  tar xzf lua-$LUASRC_BASE.tar.gz
  cd $T_BD/lua-$LUASRC_BASE;
  # Build Lua without backwards compatibility for testing
  perl -i -pe 's/-DLUA_COMPAT_(ALL|5_2)//' src/Makefile
  make $PLATFORM && make INSTALL_TOP="$LUA_HOME_DIR" install;
  if [[ ! -f $HOME/.lua/lua ]];then
    ln -sf $LUA_HOME_DIR/bin/lua $HOME/.lua/lua
  fi
  if [[ ! -f $HOME/.lua/luac ]];then
    ln -sf $LUA_HOME_DIR/bin/luac $HOME/.lua/luac;
  fi
fi

LUAROCKS_BASE=luarocks-$LUAROCKS
if [[ ! -d $T_BD/$LUAROCKS_BASE ]]; then
  mkdir -p $T_BD/$LUAROCKS_BASE
  cd $T_BD/$LUAROCKS_BASE
  curl --location http://luarocks.org/releases/$LUAROCKS_BASE.tar.gz -o $T_BD/$LUAROCKS_BASE.tar.gz
  tar xz $T_BD/$LUAROCKS_BASE.tar.gz
  cd $LUAROCKS_BASE
  ./configure --with-lua="$LUA_HOME_DIR" --prefix="$LR_HOME_DIR"
  make build && make install
  if [[ ! -h $HOME/.lua/luarocks ]];then
    ln -sf $LR_HOME_DIR/bin/luarocks $HOME/.lua/luarocks
  fi
  cd $T_BD
fi

luarocks install --local Lua-cURL --server=https://luarocks.org/dev
luarocks install --local luacov-coveralls --server=https://luarocks.org/dev
luarocks install --local lunitx

export PATH=$T_BD/lua/bin:$T_BD/luarocks/bin:$PATH
lua -v
luarocks --version
lunit.sh $PROJECT_HOME/test/test.lua
