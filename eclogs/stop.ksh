#!/bin/ksh

export ECF_PORT=1735

ecflow_client --group="halt=yes; check_pt; terminate=yes"

