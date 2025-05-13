#!/bin/bash

SCRIPTSCDCT_VERSION=1.3.0
MONAN_VERSION=1.4.0-rc
CONVERT_MPAS_VERSION=1.1.0

if [ ! -d "scripts_CD-CT" ]; then
   echo "instalando scripts..."
   git clone https://github.com/monanadmin/scripts_CD-CT.git
   cd scripts_CD-CT
   git checkout ${SCRIPTSCDCT_VERSION}
   git status | head -n 1
   git log -1
fi

