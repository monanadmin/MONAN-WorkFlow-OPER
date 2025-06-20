#!/bin/bash
set -e # stop the shell on first error
set -u # fail when using an undefined variable
set -x # echo script lines as they are executed
#set +o noclobber
 
 
# Defines the variables that are needed for any communication with ECF
export ECF_PORT=%ECF_PORT%    # The server port number
export ECF_HOST=%ECF_HOST%    # The host name where the server is running
export ECF_NAME=%ECF_NAME%    # The name of this current task
export ECF_PASS=%ECF_PASS%    # A unique password
export ECF_TRYNO=%ECF_TRYNO%  # Current try number of the task
export ECF_RID=$$             # record the process id. Also used for zombie detection
export ECF_HOME=%ECF_HOME%
 
# Define the path where to find ecflow_client
# make sure client and server use the *same* version.
# Important when there are multiple versions of ecFlow
#export PATH=/usr/local/apps/ecflow/%ECF_VERSION%/bin:$PATH
 
# Tell ecFlow we have started
ecflow_client --init=$$
 
 
# Define a error handler
ERROR() {
   set +e                      # Clear -e flag, so we don't fail
   wait                        # wait for background process to stop
   ecflow_client --abort=trap  # Notify ecFlow that something went wrong, using 'trap' as the reason
   trap 0                      # Remove the trap
   exit 0                      # End the script
}
 
 
# Trap any calls to exit and errors caught by the -e flag
trap ERROR 0
 
 
# Trap any signal that may cause the script to fail
trap '{ echo "Killed by a signal"; ERROR ; }' 1 2 3 4 5 6 7 8 10 12 13 15



##########################################################################
#
#  Exports de datas/dirs importantes
#
## Output directories:-----------------------------------------------------------------------------------
export DIR_DADOS=/mnt/beegfs/monan/users/renato/issues/ecflow-PREOPER/SCRATCHOUT; mkdir -p ${DIR_DADOS}
export DIRFLUSHOUT=/mnt/beegfs/monan/users/renato/issues/trashout; mkdir -p ${DIRFLUSHOUT}
#-------------------------------------------------------------------------------

# Other vars:
export FAMILY=%FAMILY%
export FAMILY1=%FAMILY1%
export SUITE=%SUITE%
export DIRSUITE=%ECF_HOME%
export HH=$(echo "%ECF_TIME%" | cut -d: -f1)
export DIRSCRIPTSCDCT=${DIRSUITE}/${SUITE}/${FAMILY}/../scripts_CD-CT
export DIRSCRIPTDADOS=${DIR_DADOS}/scripts_CD-CT


echo ""
echo "===============  MY TASK STARTS HERE =================="
echo ""
