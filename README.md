# MONAN-WorkFlow-OPER
Work flow scripts for operational ECFLOW suite.



### How to install MONAN-WorkFlow-Oper for the very first time?

1. Clone the WorkFlow-Oper repository into your work directory, and ask for your tag:
~~~
git clone https://github.com/monanadmin/MONAN-WorkFlow-OPER.git
cd MONAN-WorkFlow-OPER
git checkout 0.1.0
~~~
Then you will get the follow directories and scripts struct:
~~~
|-- MONAN-WorkFlow-OPER
|   |-- LICENSE
|   |-- MONAN_PRE_OPER
|   |   `-- MONAN
|   |       |-- 00
|   |       |   |-- model.ecf
|   |       |   |-- post.ecf
|   |       |   |-- pre.ecf
|   |       |-- 12
|   |       |   |-- model.ecf -> ../00/model.ecf
|   |       |   |-- post.ecf -> ./00/post.ecf
|   |       |   |-- pre.ecf -> ../00/pre.ecf
|   |       |-- install_MONAN-MODEL-scripts.bash
|   |-- MONAN_PRE_OPER.def
|   |-- README.md
|   |-- VERSION.txt
|   |-- eclogs
|   |   |-- egeon-login.cptec.inpe.br.1735.ecf.check
|   |   |-- egeon-login.cptec.inpe.br.1735.ecf.check.b
|   |   |-- egeon-login.cptec.inpe.br.1735.ecf.log
|   |   |-- start.ksh
|   |   |-- stop.ksh
|   |   `-- template.ecf
|   `-- includes
|       |-- head.h
|       `-- tail.h
~~~

2. Put your root work-directory and host name machine in the `MONAN_PRE_OPER.def` :
~~~
cd MONAN-WorkFlow-OPER
vi MONAN_PRE_OPER.def
~~~
~~~
edit ECF_HOME "/mnt/beegfs/<your_root_work_dir>/MONAN-WorkFlow-OPER"
edit ECF_HOST "<your_host_name>.cptec.inpe.br"
edit ECF_INCLUDE "/mnt/beegfs/<your_root_work_dir>/MONAN-WorkFlow-OPER/includes"
~~~

3. Now, you must install the `scritps_CD-CT` and MONAN model repositories. The `install_MONAN-MODEL-scripts.bash` will do it in the right place automatically.
Before run it, check if the `scritps_CD-CT`, MONAN-Model and Convert_MPAS versions are the same you suppose to use:
~~~
cd MONAN-WorkFlow-OPER/MONAN_PRE_OPER/MONAN
cat install_MONAN-MODEL-scripts.bash
~~~
These vars are important to check:
~~~
SCRIPTSCDCT_VERSION=1.3.0
MONAN_VERSION=1.4.0-rc
CONVERT_MPAS_VERSION=1.1.0
~~~
Now you can run it:
~~~
cd MONAN-WorkFlow-OPER/MONAN_PRE_OPER/MONAN
./install_MONAN-MODEL-scripts.bash
~~~

4. After this step, you should get the scripts_CD-CT installed and the MONAN-Model installed and compiled:

The MONAN scripts to run manually are here: `MONAN-WorkFlow-OPER/MONAN_PRE_OPER/MONAN/scripts_CD-CT/scripts`, please check it:
~~~
2.pre_processing.bash (to run the pre-processing)
3.run_model.bash (to run the model)
4.run_post.bash (to run the post-processing)
~~~

The MONAN source are installed and compiled into the `scripts_CD-CD/sources` dir:  `MONAN-WorkFlow-OPER/MONAN_PRE_OPER/MONAN/scripts_CD-CT/scripts`:
~~~
MONAN-WorkFlow-OPER/MONAN_PRE_OPER/MONAN/scripts_CD-CT/sources/MONAN-Model_1.3.1-rc
~~~

All the executables are available in the `scripts_CD-CD/execs` :  
~~~
MONAN-WorkFlow-OPER/MONAN_PRE_OPER/MONAN/scripts_CD-CT/execs: 
build_tables
atmosphere_model     (Model main executable)
init_atmosphere_model  (pre-processing executable)
convert_mpas  (Post-processing executable)
ungrib.exe
~~~

 In this directory you can get all the repository versions that are installed:
~~~
MONAN-VERSION.txt
CONVMPAS-VERSION.txt
~~~
This vrsions are showed in the `VERSION` EcFlow label info field.

5. After all these steps, you can adjust your `ECF_PORT` and start your ECFlow suite `MONAN_PRE_OPER.def`.

### How to confiurate the MONAN forecasts profile?

1. All SLURM configuratinos are in the `setenv.bash` script for each phase of MONAN:
~~~
MONAN-WorkFlow-OPER/MONAN_PRE_OPER/MONAN/scripts_CD-CT/scripts/setenv.bash
~~~

For example, if you want to change the number of MPI tasks (cores) or cores per nodes for the MODEL phase, such as al others SLURM options, you can change on it:
~~~
# Model phase:
export MODEL_QUEUE="batch"
export MODEL_ncores=512
export MODEL_nnodes=8
export MODEL_ncpn=64
export MODEL_jobname="Model.MONAN"
export MODEL_walltime="8:00:00"
~~~



Done! 

You are ready to operate you suite MONAN. Enjoy it! 


If you have any problems with this suite operation, or suggestions/colaborations, please let us know:

gcc.dimnt@inpe.br
