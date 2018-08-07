PROJECT_HOME=$( dirname "$( cd "$( dirname "$0" )" && pwd )" )
T_BD=${TRAVIS_BUILD_DIR:-}
if [[ -z $T_BD ]]; then
  T_BD=$PROJECT_HOME/build
fi

export PATH=${PATH}:$HOME/.lua:$HOME/.local/bin:${T_BD}/install/luarocks/bin
bash $PROJECT_HOME/scripts/setup_lua.sh
eval `$HOME/.lua/luarocks path`
