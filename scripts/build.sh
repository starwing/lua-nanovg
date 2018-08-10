#! /bin/bash
set -e
PROJECT_HOME=$( dirname "$( cd "$( dirname "$0" )" && pwd )" )
source $PROJECT_HOME/scripts/setup.sh
cd $PROJECT_HOME

eval "$(luarocks path)"
echo "Building project starting"
PROJECT_HOME=$PROJECT_HOME make clean
PROJECT_HOME=$PROJECT_HOME make install
echo "Building project finished"
