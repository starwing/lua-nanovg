PLATFORM=""
if [ -z "${PLATFORM:-}" ]; then
  T_OS=${TRAVIS_OS_NAME:-}
  if [ ! -z $T_OS ]; then
    PLATFORM=$T_OS
  fi
fi

if [[ -z $PLATFORM ]];then
  PLATFORM=posix
  if [[ ! -z ${MINGW_PREFIX:-} ]]; then
    PLATFORM=mingw
  else
    UNAME_S=`uname -s`
    if [[ $UNAME_S == "Linux" ]]; then
      PLATFORM=linux
    fi
    if [[ $UNAME_S == "Darwin" ]]; then
      PLATFORM=macosx
    fi
  fi
fi
