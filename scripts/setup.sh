set -e
PROJECT_HOME=$( dirname "$( cd "$( dirname "$0" )" && pwd )" )
export PATH=$HOME/.local/bin:$PATH
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
PLATFORM=posix
L_EXT=so
E_EXT=
if [[ ! -z $MINGW_PREFIX ]]; then
    PLATFORM=mingw
    L_EXT=dll
    E_EXT=.exe
fi
if [[ $machine == "Linux" ]]; then
    PLATFORM=linux
fi
if [[ $machine == "OSX" ]]; then
    PLATFORM=macosx
fi
L_LU=${LUA:-}
if [[ -z $L_LU ]]; then
  L_LU=5.3
fi

T_BD=$PROJECT_HOME/build/$PLATFORM

echo "Setting up runtime configuration"
echo "Detected PLATFORM=$PLATFORM machine=$machine extension=$L_EXT lua=$L_LU"
echo "Building in $T_BD"
echo "Ensuring build directory in $T_BD"
mkdir -p $T_BD
if [[ ! -d $T_BD ]];then
  echo "Cannot ensure build directory"
  exit 1
fi
