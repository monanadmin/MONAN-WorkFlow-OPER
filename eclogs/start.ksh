#!/bin/ksh

export ECF_PORT=<numero_porta_server>
export LC_ALL="en_US.utf-8"


ecflow_server --port=${ECF_PORT} &


