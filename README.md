# MONAN-WorkFlow-OPER
Work flow scripts for operational ECFLOW suite.


### History

0.1.0 - First stable version.


Cloning this repository, you will get this files:

~~~ 
|-- MONAN-WorkFlow-OPER
|   |-- LICENSE
|   |-- MONAN-OPER
|   |   `-- MONAN
|   |       |-- install_MONAN-MODEL-scripts.bash
|   |       |-- model.ecf
|   |       |-- post.ecf
|   |       `-- pre.ecf
|   |-- MONAN-OPER.def
|   |-- README.md
|   |-- VERSION.txt
|   |-- eclogs
|   |   |-- start.ksh
|   |   |-- stop.ksh
|   |   `-- template.ecf
|   `-- includes
|       |-- head.h
|       `-- tail.h
`-- tree.txt
~~~ 



### How-to get started

- Load the ECFLow module on Egeon: `Module load ecflow/5.8.4`
- Initialize the ECFlow client-server (if it's not already up):
~~~
cd MONAN-WorkFlow-OPER/eclogs
start.ksh
~~~

- Use the `stop.ksh` script if you want to stop the ECF client-server process.
- Start your suite for the very first time:
~~~
cd MONAN-WorkFlow-OPER
ecflow_client --load=MONAN-OPER.def
ecflow_client --begin=MONAN-OPER
~~~


- Start the GUI for view and monitoring your suite:
~~~
cd MONAN-WorkFlow-OPER/eclogs
ecflow_ui >> ecflowview.${USER}.logs&
~~~

Done! 

You are ready to operate you suite MONAN. Enjoy it! 


If you have any problems with this suite operation, or suggestions/colaborations, please let us know:

gcc.dimnt@inpe.br
