#!/bin/ksh

export ECF_PORT=<numero_porta_server>

ecflow_client --group="halt=yes; check_pt; terminate=yes"

