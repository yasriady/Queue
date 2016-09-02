#!/bin/bash
export INSTALLDIR='/opt/Queue'

cd $INSTALLDIR
#cp /home/dedy/QtProjects/Queue/MyQt/MyDialog/MyDialog ./
cp /home/dedy/QtProjects/build-Queue-Desktop_Qt_5_7_0_GCC_64bit-Debug/QClient/QClient ./
cp /home/dedy/QtProjects/build-Queue-Desktop_Qt_5_7_0_GCC_64bit-Debug/QDisplay/QDisplay ./
cp /home/dedy/QtProjects/build-Queue-Desktop_Qt_5_7_0_GCC_64bit-Debug/QPrint/QPrint ./

cd $INSTALLDIR/QtLib

cp /home/dedy/QtProjects/QtLib/QtConfig/libQtConfig.so.1.0.0 ./
ln -s libQtConfig.so.1.0.0 libQtConfig.so.1 

cp /home/dedy/QtProjects/QtLib/QtDB/libQtDB.so.1.0.0 ./
ln -s libQtDB.so.1.0.0 libQtDB.so.1

cp /home/dedy/QtProjects/QtLib/QtLib/libQtLib.so.1.0.0  ./
ln -s libQtLib.so.1.0.0 libQtLib.so.1


