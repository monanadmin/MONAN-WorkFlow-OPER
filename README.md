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
~~~ 



### How-to get started

- Load the ECFLow module on Egeon: `Module load ecflow/5.8.4`
- It is important chooseyour PORT NUMBER to install your server. We used the 1735 PORT NUMBER. If you want to use other number, please edit the `ECF_PORT` var in the files `start.ksh` and `stop.ksh`:
~~~
export ECF_PORT=<your_port_number>
~~~

- And, before you play your suite, it is very important to export the `ECF_PORT` environment variable:
~~~
export ECF_PORT=<your_port_number>
~~~
- Initialize the ECFlow client-server (if it's not already up):
~~~
cd MONAN-WorkFlow-OPER/eclogs
start.ksh
~~~

- Use the `stop.ksh` script if you want to stop the ECF client-server process.
- Before play the operational suite, some important variables need to be filled correctly. Please, do it:

Edit the `ECF_HOME` var with your main suite directory in the file `MONAN_OPER.def` :
~~~
   edit ECF_HOME "/mnt/beegfs/<your_rootdirectory>/MONAN-WorkFlow-OPER"
~~~

Edit the `ECF_HOST` var with your machine hostname in the file `MONAN_OPER.def` :
~~~
edit ECF_HOST "<your_hostname>.cptec.inpe.br"
~~~

And, edit the ECF_INCLUDE var with your `includes` directory in the file `MONAN_OPER.def` :
~~~
edit ECF_INCLUDE "/mnt/beegfs/<your_rootdirectory>/MONAN-WorkFlow-OPER/includes"
~~~


- Now, start your suite for the very first time:
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



- Install the MONAN scripts:
~~~
cd MONAN-WorkFlow-OPER/MONAN_OPER/MONAN
install_MONAN-MODEL-scripts.bash
~~~
This script will clon the `script_CD-CT` scripts and install (clone and compile) the MONAN-Model ante CONVERT-MPAS files.






Done! 

You are ready to operate you suite MONAN. Enjoy it! 


If you have any problems with this suite operation, or suggestions/colaborations, please let us know:

gcc.dimnt@inpe.br
